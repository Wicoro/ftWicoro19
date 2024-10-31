# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: norban <norban@student.S19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 17:59:20 by norban            #+#    #+#              #
#    Updated: 2024/07/18 22:24:57 by norban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -Wall -Wextra -Werror -c ft_swap.c ft_putchar.c ft_putstr.c ft_strlen.c ft_strcmp.c
ar rc libft.a *.o
