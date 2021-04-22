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

NAME			= ${UTILS} ${PS} ${CH} 
UTILS			= common_utils.a
PS				= push_swap
CH				= checker
CC				= gcc
CFLAGS			= -g -Wall -Wextra -Werror
RM				= rm -f
UTILSDIR		= ./common_utils/
CHECKSRCDIR		= ./ch_srcs/
PSSRCDIR		= ./ps_srcs/
INCDIR			= ./includes/
GNLINCDIR		= ./get_next_line/
UTILSSRCNAME	= check_av.c \
					check_stacks.c \
					display_array_for_debug.c \
					display_stack_for_debug.c \
					error.c \
					pack_array.c \
					pack_check_stack.c \
					pack_sort_check_array.c \
					push.c \
					rotate.c \
					sort_array.c \
					swap.c
CHECKSRCNAME	= checker.c
PSSRCNAME		= push_swap.c
GNLSRCNAME		= get_next_line.c \
					get_next_line_utils.c
UTILSSRCS		= ${addprefix ${UTILSDIR}, ${UTILSSRCNAME}}
CHECKSRCS		= ${addprefix ${CHECKSRCDIR}, ${CHECKSRCNAME}}
PSSRCS			= ${addprefix ${PSSRCDIR}, ${PSSRCNAME}}
GNLSRCS			= ${addprefix ${GNLINCDIR}, ${GNLSRCNAME}}
UTILSOBJS		= ${UTILSSRCS:.c=.o}
CHECKOBJS		= ${CHECKSRCS:.c=.o}
PSOBJS			= ${PSSRCS:.c=.o}
GNLOBJS			= ${GNLSRCS:.c=.o}
LIBFTDIR		= ./libft
LIBFT			= ./libft.a

.c.o:
					${CC} ${CFLAGS} -I ${INCDIR} -I ${GNLINCDIR} -c $< -o ${<:.c=.o}

$(NAME):			$(CHECKOBJS) $(PSOBJS) $(UTILSOBJS) $(GNLOBJS)
					$(MAKE) -C $(LIBFTDIR)
					cp libft/libft.a ./
					${CC} ${CFLAGS} ${LIBFT} -o ${UTILS} ${UTILSOBJS} ${GNLOBJS}
					${CC} ${CFLAGS} ${LIBFT} -o ${PS} ${PSOBJS} ${GNLOBJS}
					${CC} ${CFLAGS} ${LIBFT} -o ${CH} ${CHECKOBJS} ${GNLOBJS}

all:				$(NAME)

clean:
					$(MAKE) -C $(LIBFTDIR) clean
					${RM} ${CHECKOBJS} ${PSOBJS} ${UTILSOBJS} ${GNLOBJS}

fclean:				clean
					$(MAKE) -C $(LIBFTDIR) fclean
					${RM} $(LIBFT)
					${RM} ${NAME}

re:					fclean all

.PHONY:				all clean fclean re
