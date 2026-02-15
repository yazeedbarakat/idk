class Plant:
    def __init__(self, name: str, height: int, age: int) -> None:
        self.name = name
        self.height = height
        self.age = age

    def print_plant(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days old")

    def grow(self):
        self.height += 1

    def iage(self):
        self.age += 1

    def get_info(self, day: int) -> None:
        doh = self.height
        for i in range(1, day):
            self.grow()
            self.iage()
        self.print_plant()
        if self.height - doh > 0:
            print(f"Growth this week: +{self.height - doh}cm")


if __name__ == "__main__":
    p1 = Plant("Rose", 25, 30)
    print("=== Day 1 ===")
    p1.get_info(1)
    print("=== Day 7 ===")
    p1.get_info(7)
