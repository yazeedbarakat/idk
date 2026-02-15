class Plant:
    def __init__(self, name: str, hight: int, age: int) -> None:
        self.name = name
        self.hight = hight
        self.age = age

    def print_plant(self):
        print(f"{self.name}: {self.hight}cm, {self.age} days old")


if __name__ == "__main__":
    print("=== Garden Plant Registry ===")
    p1 = Plant("Rose", 25, 30)
    p2 = Plant("Sunflower", 80, 45)
    p3 = Plant("Cactus", 15, 120)
    p1.print_plant()
    p2.print_plant()
    p3.print_plant()
