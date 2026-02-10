def ft_count_harvest_recursive():
    duh = int(input("Days until harvest: "))
    helper(duh, 1)


def helper(duh, i):
    if i <= duh:
        print("Day", i)
        helper(duh, i + 1)
    else:
        print("Harvest time!")
