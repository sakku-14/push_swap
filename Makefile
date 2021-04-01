# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysakuma <ysakuma@student.42tokyo.j>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/09 12:55:15 by ysakuma           #+#    #+#              #
#    Updated: 2021/04/01 13:23:42 by ysakuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ${PS} ${CH}
PS				= push_swap
CH				= checker
CC				= gcc
CFLAGS			= -g -Wall -Wextra -Werror
RM				= rm -f
CHECKSRCDIR		= ./ch_srcs/
PSSRCDIR		= ./ps_srcs/
INCDIR			= ./includes/
GNLINCDIR		= ./get_next_line/
CHECKSRCNAME	= checker.c
PSSRCNAME		= push_swap.c
GNLSRCNAME		= get_next_line.c \
					get_next_line_utils.c
CHECKSRCS		= ${addprefix ${CHECKSRCDIR}, ${CHECKSRCNAME}}
PSSRCS			= ${addprefix ${PSSRCDIR}, ${PSSRCNAME}}
GNLSRCS			= ${addprefix ${GNLINCDIR}, ${GNLSRCNAME}}
CHECKOBJS		= ${CHECKSRCS:.c=.o}
PSOBJS			= ${PSSRCS:.c=.o}
GNLOBJS			= ${GNLSRCS:.c=.o}
LIBFTDIR		= ./libft
LIBFT			= ./libft.a

.c.o:
					${CC} ${CFLAGS} -I ${INCDIR} -I ${GNLINCDIR} -c $< -o ${<:.c=.o}

$(NAME):			$(CHECKOBJS) $(PSOBJS) $(GNLOBJS)
					$(MAKE) -C $(LIBFTDIR)
					cp libft/libft.a ./
					${CC} ${CFLAGS} ${LIBFT} -o ${PS} ${PSOBJS} ${GNLOBJS}
					${CC} ${CFLAGS} ${LIBFT} -o ${CH} ${CHECKOBJS} ${GNLOBJS}

all:				$(NAME)

clean:
					$(MAKE) -C $(LIBFTDIR) clean
					${RM} ${CHECKOBJS} ${PSOBJS} ${GNLOBJS}

fclean:				clean
					$(MAKE) -C $(LIBFTDIR) fclean
					${RM} $(LIBFT)
					${RM} ${NAME}

re:					fclean all

.PHONY:				all clean fclean re
