def ft_water_reminder():
    dslw = int(input("Days since last watering: "))
    if dslw > 2:
        print("Water the plants!")
    else:
        print("Plants are fine")
