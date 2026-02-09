# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_seed_inventory.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybarakat <ybarakat@learner.42.tech>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/10 00:01:02 by ybarakat          #+#    #+#              #
#    Updated: 2026/02/10 00:23:45 by ybarakat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    if unit == "packets":
        print(seed_type.capitalize(), "seeds:  ",quantity, "packets available")
    elif unit == "grams":
        print(seed_type.capitalize(), "seeds:  ",quantity, "grams total")
    elif unit == "area":
        print(seed_type.capitalize(), "seeds:  ","covers", quantity, "square meters")
    else:
        print(seed_type.capitalize(), "seeds:  ","Unknown unit type")
