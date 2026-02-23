class GardenManager:
    def __init__(self):
        self.users = []
        self.gardens = {}
        self.garden_counter = 0

    def hvtest(self) -> None:
        hvt = False
        total = 0
        for u in self.users:
            plants = self.gardens[u]
            for p in plants:
                total += p.get_score()
        if total > 100:
            hvt = True
        print(f"Height validation test: {hvt}")

    def scores(self) -> None:
        print("Garden scores - ", end=" ")
        for u in self.users:
            total = 0
            plants = self.gardens[u]
            for p in plants:
                total += p.get_score()
            if u == "Alice":
                print(f"{u}: {total},", end=" ")
            else:
                print(f"{u}: {total}")

    def add_user(self, name: str) -> None:
        if name not in self.users:
            self.users += [name]
            self.gardens[name] = []
            self.garden_counter += 1

    def add_plant(self, user: str, name: str, height: int) -> None:
        plant = Plant(name, height)
        self.gardens[user] += [plant]
        print(f"Added {name} to {user}'s garden")

    def add_flowering_plant(self, user: str, name: str,
                            height: int, color: str) -> None:
        plant = FloweringPlant(name, height, color)
        self.gardens[user] += [plant]
        print(f"Added {name} to {user}'s garden")

    def add_prize_flower(self, user: str, name: str, height: int,
                         color: str, points: int) -> None:
        plant = PrizeFlower(name, height, color, points)
        self.gardens[user] += [plant]
        print(f"Added {name} to {user}'s garden")

    def grow_all(self, user: str) -> None:
        plants = self.gardens[user]
        for p in plants:
            p.grow()

    def create_garden_network(self, user: str,
                              pla: str, h1: int,
                              flo: str, h2: int, col1: str,
                              pri: str, h3: int, col2: str, poi: int
                              ) -> None:
        self.add_plant(user, pla, h1)
        self.add_flowering_plant(user, flo, h2, col1)
        self.add_prize_flower(user, pri, h3, col2, poi)

    class GardenStats:
        def __init__(self, manager: "GardenManager", user: str) -> None:
            plants = manager.gardens[user]
            self.plants_in_garden(plants)
            self.count_plants(plants)

        @staticmethod
        def plants_in_garden(plants: list) -> None:
            print("Plants in garden:")
            for i in plants:
                if i.get_type() == "prize":
                    print(f"- {i.name}: {i.height}cm, {i.color}", end=" ")
                    if i.bloom:
                        print("(blooming)", end=" ")
                    print(f", Prize points: {i.points}")
                elif i.get_type() == "flowering":
                    print(f"- {i.name}: {i.height}cm, {i.color}", end=" ")
                    if i.bloom:
                        print("(blooming)")
                elif i.get_type() == "regular":
                    print(f"- {i.name}: {i.height}cm")

        @staticmethod
        def count_plants(plants: list) -> None:
            regular = 0
            flowering = 0
            prize = 0
            for p in plants:
                if p.get_type() == "prize":
                    prize += 1
                elif p.get_type() == "flowering":
                    flowering += 1
                elif p.get_type() == "regular":
                    regular += 1
            total_plants = regular + flowering + prize
            print(f"\nPlants added: {total_plants}", end=" ")
            print(f"Total growth: {total_plants}cm")
            print(f"Plant types: {regular} regular", end=" ")
            print(f"{flowering} flowering, {prize} prize flowers\n")


class Plant:
    def __init__(self, name: str, height: int):
        self.name = name
        self.height = height

    def grow(self) -> None:
        self.height += 1
        print(f"{self.name} grew 1cm")

    def get_score(self) -> int:
        return self.height

    def get_type(self):
        return "regular"


class FloweringPlant(Plant):
    def __init__(self, name: str, height: int, color: str):
        super().__init__(name, height)
        self.color = color
        self.bloom = True

    def notblooming(self):
        self.bloom = False

    def get_type(self):
        return "flowering"


class PrizeFlower(FloweringPlant):
    def __init__(self, name: str, height: int, color: str, points: int):
        super().__init__(name, height, color)
        self.points = points

    def get_score(self):
        return self.height + self.points

    def get_type(self):
        return "prize"


if __name__ == "__main__":
    print("=== Garden Management System Demo ===\n")
    gm = GardenManager()
    gm.add_user("Alice")
    gm.create_garden_network("Alice", "Oak Tree", 100,
                             "Rose", 25, "Red flowers",
                             "Sunflower", 50, "yellow flowers", 10)
    gm.add_user("Bob")
    gm.create_garden_network("Bob", "Oak Tree", 50,
                             "Rose", 20, "blue flowers",
                             "moonflower", 22, "black flowers", 0)
    print("\nAlice is helping all plants grow...")
    gm.grow_all("Alice")
    print("\n=== Alice’s Garden Report ===")
    Alice_stats = gm.GardenStats(gm, "Alice")
    gm.hvtest()
    gm.scores()
    print(f"Total gardens managed: {gm.garden_counter}")
