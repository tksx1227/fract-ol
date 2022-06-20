UNAME	:= $(shell uname)

BINDIR	:= bin
LIBDIR	:= lib
SRCDIR	:= src
OBJDIR	:= obj
INCDIR	:= include

LIBDIRS	:= $(LIBDIR)
INCDIRS	:= $(INCDIR)

MLXDIR := minilibx

FILES	:= main.c \
		   canvas_utils.c \
		   color_utils.c \
		   comp_utils.c \
		   mlx_draw.c \
		   mlx_hooks.c \
		   mlx_hooks_sub.c \
		   utils.c
SRCS	:= $(addprefix $(SRCDIR)/, $(FILES))
OBJS	:= $(addprefix $(OBJDIR)/, $(FILES:.c=.o))
DEPS	:= $(addprefix $(OBJDIR)/, $(FILES:.c=.d))

CC		:= cc
RM		:= rm -rf
NAME	:= fractol
FRACTOL	:= $(BINDIR)/fractol
CFLAGS	:= -Wall -Wextra -Werror -MMD -MP

# OS別で分岐
ifeq ($(UNAME), Darwin)
	LIBDIRS += /usr/X11R6/lib
	INCDIRS += /opt/X11/include
	LIBS := mlx X11 Xext
	FW := $(addprefix -framework , OpenGL AppKit)
else
	LIBS := mlx Xext X11 m bsd 
endif

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< $(addprefix -L, $(LIBDIRS)) $(addprefix -l, $(LIBS)) $(addprefix -I, $(INCDIRS)) $(FW) -o $@

.PHONY: $(NAME)
$(NAME): all

.PHONY: all
all: $(BINDIR) $(OBJDIR) $(MLXDIR) $(FRACTOL)

$(FRACTOL): $(OBJS)
	@echo "\033[32mGenerating binary file...\033[0m"
	$(CC) $^ $(addprefix -L, $(LIBDIRS)) $(addprefix -l, $(LIBS)) -o $@

$(LIBDIR):
	@echo "\033[32mGenerating $(LIBDIR) directory...\033[0m"
	mkdir -p $@

$(OBJDIR):
	@echo "\033[32mGenerating $(OBJDIR) directory...\033[0m"
	mkdir -p $@

$(BINDIR):
	@echo "\033[32mGenerating $(BINDIR) directory...\033[0m"
	mkdir -p $@

$(MLXDIR): $(LIBDIR)
	@if [ ! -e $(MLXDIR) ]; then \
		echo "\033[32mDownloading minilibx from GitHub...\033[0m" ; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLXDIR) ; \
		make -C $(MLXDIR) ; \
		cp $(MLXDIR)/mlx.h $(INCDIR)/mlx.h ; \
		cp $(MLXDIR)/libmlx.a $(LIBDIR)/libmlx.a ; \
	fi

.PHONY: clean
clean:
	@echo "\033[31mRemoving $(OBJDIR) directory...\033[0m"
	$(RM) $(OBJDIR)

.PHONY: fclean
fclean: clean
	@echo "\033[31mRemoving $(BINDIR) and $(MLXDIR) directory...\033[0m"
	$(RM) $(BINDIR)
	$(RM) $(MLXDIR)

.PHONY: re
re: fclean all

-include $(DEPS)
