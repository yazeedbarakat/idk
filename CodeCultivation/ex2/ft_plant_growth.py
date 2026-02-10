class plant:
    def __init__(self, name, hight, page):
        self.name = name
        self.hight = hight
        self.page = page
        self.get_info()
    def print_plant(self):
        print(f"{self.name}: {self.hight}cm, {self.page} dayes old")
    def grow(self):
        self.hight += 1
    def age(self):
        self.page += 1
    def get_info(self):
        print("=== Day 1 ===")
        self.print_plant()
        doh = self.hight
        for i in range (1, 7):
            self.grow()
            self.age()
            i += 1
        print("=== Day 7 ===")
        self.print_plant()
        print(f"Growth this week: +{self.hight - doh}cm")
p1 = plant("Rose", 25, 30)
