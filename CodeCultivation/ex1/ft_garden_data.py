class plant:
    print("=== Garden Plant Registry ===")
    def __init__(self, name, hight, age):
        self.name = name
        self.hight = hight
        self.age = age
        self.print_plant()

    def print_plant(self):
        print(f"{self.name}: {self.hight}cm, {self.age} dayes old")


p1 = plant("Rose", 25, 30)
p2 = plant("Sunflower", 80, 45)
p3 = plant("Cactus", 15, 120)
