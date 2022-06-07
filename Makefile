BINDIR	:= bin
LIBDIR	:= lib
SRCDIR	:= src
OBJDIR	:= obj
INCDIR	:= include

INCPATH	:= /usr/local/include
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

all: $(LIBFT) $(BINDIR) $(OBJDIR) mlx $(FRACTOL)

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

mlx:
	@if [ ! -e $(MLXPATH) ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLXPATH) ; \
		make -C $(MLXPATH) ; \
		cp $(wildcard $(MLXPATH)/*.h) $(INCPATH) ; \
		cp $(wildcard $(MLXPATH)/*.a) $(LIBDIR) ; \
	fi

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(BINDIR)
	$(RM) $(MLXPATH)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re