# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_count_harvest_recursive.py                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 23:11:57 by ybarakat          #+#    #+#              #
#    Updated: 2026/02/10 00:28:55 by ybarakat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_count_harvest_recursive():
    duh = int(input("Days until harvest: "))
    helper(duh, 1)

def helper(duh, i):
    if i <= duh:
        print("Day", i)
        helper(duh, i + 1)
    else:
        print("Harvest time!")
