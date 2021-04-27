NAME			= checker
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f
SRCDIR			= ./
INCDIR			= ../includes/
GNLINCDIR		= ../get_next_line/
SRCNAME			= $(shell echo *.c)
GNLSRCNAME		= get_next_line.c \
					get_next_line_utils.c
SRCS			= ${addprefix ${SRCDIR}, ${SRCNAME}}
GNLSRCS			= ${addprefix ${GNLINCDIR}, ${GNLSRCNAME}}
OBJS			= ${SRCS:.c=.o}
GNLOBJS			= ${GNLSRCS:.c=.o}
LIBFTDIR		= ../libft
LIBFT			= ../libft.a

.c.o:
					${CC} ${CFLAGS} -I ${INCDIR} -I ${GNLINCDIR} -c $< -o ${<:.c=.o}

$(NAME):			$(OBJS) $(GNLOBJS)
					$(MAKE) -C $(LIBFTDIR)
					cp ../libft/libft.a ../
					${CC} ${CFLAGS} ${LIBFT} -o ${NAME} ${OBJS} ${GNLOBJS}

all:				$(NAME)

clean:
					$(MAKE) -C $(LIBFTDIR) clean
					${RM} ${OBJS} ${GNLOBJS}

fclean:				clean
					$(MAKE) -C $(LIBFTDIR) fclean
					${RM} $(LIBFT)
					${RM} ${NAME}

re:					fclean all

.PHONY:				all clean fclean re
