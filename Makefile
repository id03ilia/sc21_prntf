# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dflorenc <dflorenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 14:04:19 by dflorenc          #+#    #+#              #
#    Updated: 2021/05/22 10:50:38 by dflorenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_strlen.c ft_atoi.c ft_itoa_u.c ft_itoa_di.c print_flag_c.c print_flag_s.c\
			print_flag_u.c putchar_fd.c print_flag_d.c print_flag_x.c print_flag_p.c parser.c print_flag_1.c\
			print_flag_d_plus_fmin0.c print_flag_d_plus_fminus1.c print_flag_d_otrizat_fmin0.c\
			print_flag_d_otrizat_fmin1.c parser_initial_list.c print_flag_p_fmin0.c print_flag_p_fmin1.c

OBJS	= ${patsubst %.c,%.o,$(SRCS)}

HEADER	= ft_printf.h

NAME 	= libftprintf.a

RM		= rm -f
GCCFLAG	= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	${OBJS} ${HEADER}
			ar rcs ${NAME} $?

%.o	:	%.c	
			gcc ${GCCFLAG} -c $< -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
