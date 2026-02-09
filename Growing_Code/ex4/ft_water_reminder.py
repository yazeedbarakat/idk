# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_water_reminder.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 22:48:04 by ybarakat          #+#    #+#              #
#    Updated: 2026/02/09 22:53:01 by ybarakat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_water_reminder():
    dslw = int(input("Days since last watering: "))
    if dslw > 2:
        print("Water the plants!")
    else:
        print("Plants are fine")
