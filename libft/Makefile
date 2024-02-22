NAME = libft.a

VPATH = .

SRCS = ft_split.c ft_substr.c ft_atoi.c ft_strlcpy.c \
		ft_strlen.c ft_isdigit.c

OBJC = $(SRCS:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS = $(BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJC)
	ar -r $(NAME) $?

clean : 
	rm -f $(OBJC) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all 

.PHONY : all clean fclean re 

                            