BINDIR	:= bin
LIBDIR	:= lib
SRCDIR	:= src
OBJDIR	:= obj
INCDIR	:= include

MLXPATH := ./minilibx

FILES	:= main.c
SRCS	:= $(addprefix $(SRCDIR)/, $(FILES))
OBJS	:= $(addprefix $(OBJDIR)/, $(FILES:.c=.o))
DEPS	:= $(addprefix $(OBJDIR)/, $(FILES:.c=.d))

CC		:= cc
RM		:= rm -rf
NAME	:= fractol
FRACTOL	:= $(BINDIR)/fractol
LIBS	:= mlx Xext X11 m bsd 
CFLAGS	:= -Wall -Wextra -Werror -MMD -MP

all: $(BINDIR) $(OBJDIR) mlx $(FRACTOL)

$(NAME): all

$(FRACTOL): $(OBJS)
	$(CC) $^ $(addprefix -L, $(LIBDIR)) $(addprefix -l, $(LIBS)) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< $(addprefix -L, $(LIBDIR)) $(addprefix -l, $(LIBS)) $(addprefix -I, $(INCDIR)) -o $@

$(LIBDIR):
	mkdir -p $@

$(OBJDIR):
	mkdir -p $@

$(BINDIR):
	mkdir -p $@

mlx: $(LIBDIR)
	@if [ ! -e $(MLXPATH) ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLXPATH) ; \
		make -C $(MLXPATH) ; \
		cp $(MLXPATH)/mlx.h ./$(INCDIR)/mlx.h ; \
		cp $(MLXPATH)/libmlx.a ./$(LIBDIR)/libmlx.a ; \
	fi

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(BINDIR)
	$(RM) $(MLXPATH)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re