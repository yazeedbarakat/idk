class Plant:
    def __init__(self, name, height, age):
        self.name = name
        self.height = height
        self.age = age

    def display(self, plant_type, feature):
        print(f"\n{self.name} ({plant_type}): {self.height}cm", end=" ")
        print(f"{self.age} days, {feature}")


class Flower(Plant):
    def __init__(self, name, height, age, color):
        super().__init__(name, height, age)
        self.color = color

    def bloom(self):
        print(f"{self.name} is blooming beautifully!")

    def display(self):
        super().display("Flower", self.color + " color")


class Tree(Plant):
    def __init__(self, name, height, age, trunk_diameter):
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self):
        shade = self.height * self.trunk_diameter * 0.00312
        print(f"{self.name} provides {shade:.0f} square meters of shade")

    def display(self):
        super().display("Tree", f"{self.trunk_diameter}cm diameter")


class Vegetable(Plant):
    def __init__(self, name, height, age, harvest_season, nutritional_value):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def info(self):
        print(f"{self.name} is rich in {self.nutritional_value}")

    def display(self):
        super().display("Vegetable", self.harvest_season + " harvest")


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    f1 = Flower("Rose", 25, 30, "red")
    f2 = Flower("Black Iris", 20, 10, "black")
    f1.display()
    f1.bloom()
    t1 = Tree("Oak", 500, 1825, 50)
    t2 = Tree("Pine", 700, 500, 30)
    t1.display()
    t1.produce_shade()
    v1 = Vegetable("Tomato", 80, 90, "summer", "vitamin C")
    v2 = Vegetable("Carrot", 30, 40, "spring", "vitamin A")
    v1.display()
    v1.info()
