# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_plant_age.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 22:14:36 by ybarakat          #+#    #+#              #
#    Updated: 2026/02/09 22:43:59 by ybarakat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_plant_age():
    age = int(input("Enter plant age in days: "))
    if age >= 60:
        print("Plant is ready to harvest!")
    else:
        print("Plant needs more time to grow.")
