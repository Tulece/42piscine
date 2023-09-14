# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmalbeck <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 17:26:36 by tmalbeck          #+#    #+#              #
#    Updated: 2023/09/10 20:43:50 by tmalbeck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c check.c display.c convert.c ft_split.c ft_utilities.c 

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

CC	= cc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
