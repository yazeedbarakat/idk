# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_iterative.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 22:55:54 by ybarakat          #+#    #+#              #
#    Updated: 2026/02/09 23:09:42 by ybarakat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_count_harvest_iterative():
    duh = int(input("Days until harvest: "))
    i = 1
    while i <= duh:
        print("Day", i)
        i += 1
    print("Harvest time!")
