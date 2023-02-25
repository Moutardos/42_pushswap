CC = cc
ODIR = obj
BDIR = bin
IDIR = include
NAME = $(BDIR)/push_swap
LIBFT = $(IDIR)/libft/libft.a
RM = rm -f
CFLAGS = -Wall -Wextra -I$(IDIR) 
LFLAGS = -L$(IDIR)/libft -lft
_OBJS =  main.o pushswap.o stack.o operation.o utils.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

all: lib | $(NAME)

lib : $(LIBFT)

$(ODIR):
	mkdir -p $(ODIR)

$(BDIR):
	mkdir -p $(BDIR)

$(LIBFT):
	$(MAKE) -C $(IDIR)/libft

$(ODIR)/%.o : src/%.c | $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) | $(BDIR)
	$(CC) $(CFLAGS)  -o  $@ $(OBJS) $(LFLAGS)

clean:
	$(RM) -R $(ODIR)
	$(MAKE) -C $(IDIR)/libft $@

fclean: clean
	$(MAKE) -C $(IDIR)/libft $@
	$(RM) -R $(BDIR)

re: fclean all

.PHONY: all clean fclean re