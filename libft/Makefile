
NAME		= libft.a
CC		= cc
FLAGS  = -Wall -Wextra -Werror

RM		=	rm -f

AR		=	ar -rcs

HEADERS		:= -I ../mandatory/inc

SOURCES	=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
            ft_isalpha.c \
            ft_isascii.c \
            ft_isdigit.c \
            ft_isprint.c \
            ft_itoa.c \
            ft_memchr.c \
            ft_memcmp.c \
            ft_memcpy.c \
            ft_memmove.c \
            ft_memset.c \
            ft_putchar_fd.c \
            ft_putendl_fd.c \
            ft_putnbr_fd.c \
            ft_putstr_fd.c \
            ft_split.c \
            ft_strchr.c \
            ft_strdup.c \
            ft_striteri.c \
            ft_strjoin.c \
            ft_strlcat.c \
            ft_strlcpy.c \
            ft_strlen.c \
            ft_strmapi.c \
            ft_strncmp.c \
            ft_strnstr.c \
            ft_strrchr.c \
            ft_strtrim.c \
            ft_substr.c \
            ft_tolower.c \
            ft_toupper.c \
            ft_lstadd_back_bonus.c \
            ft_lstadd_front_bonus.c \
            ft_lstclear_bonus.c \
            ft_lstdelone_bonus.c \
            ft_lstiter_bonus.c \
            ft_lstlast_bonus.c \
            ft_lstnew_bonus.c \
            ft_lstsize_bonus.c \
            get_next_line.c \

OBJECTS	=	$(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) $(HEADERS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re`
