class GardenManager:
    def __init__(self):
        self.users = []
        self.gardens = {}
        self.garden_counter = 0

    def add_user(self, name: str) -> None:
        if name not in self.users:
            self.users.append(name)
            self.gardens[name] = []
            self.garden_counter += 1
            
    def add_plant(self, user: str, name: str, height: int) -> None:
        plant = Plant(name, height)
        self.gardens[user].append(plant)
        print(f"Added {name} to {user}'s garden")
    
    def add_flowering_plant(self, user: str, name: str, height: int, color: str) -> None:
        plant = FloweringPlant(name, height, color)
        self.gardens[user].append(plant)
        print(f"Added {name} to {user}'s garden")

    def add_prize_flower(self, user: str, name: str, height: int, color: str, points: int) -> None:
        plant = PrizeFlower(name, height, color, points)
        self.gardens[user].append(plant)
        print(f"Added {name} to {user}'s garden")

    @classmethod
    def create_garden_network(cls, user: str,
                              pla: str, h1: int,
                              flo :str, h2: int, col1: str,
                              pri: str, h3: int, col2: str, poi: int
                              ) -> None:
        cls.add_plant(user, pla, h1)
        cls.add_flowering_plant(user, flo, h2, col1)
        cls.add_prize_flower(user, pri, h3, col2, poi)


    class GardneStats:
        @staticmethod
        def count_plants(plants: list) -> dict:
            regular = 0
            flowering = 0
            prize = 0
            for p in plants:
                    if type(p) == PrizeFlower:
                        regular += 1
                    elif type(p) == FloweringPlant:
                        flowering += 1
                    elif type(p) == Plant:
                        prize += 1
            return {"regular": regular, "flowering": flowering, "prize": prize}


class Plant:
    def __init__(self, name: str, height: int):
        self.name = name
        self.height = height

    def grow(self) -> None:
        self.height += 1
        print(f"{self.name} grew 1cm")

    def get_score(self) -> int:
        return self.height
    

class FloweringPlant(Plant):
    def __init__(self, name: str, height: int, color: str):
        super().__init__(name, height)
        self.color = color
        self.bloom = False

    def blooming(self):
        self.bloom = True


class PrizeFlower(FloweringPlant):
    def __init__(self, name: str, height: int, color: str, points: int):
        super().__init__(name, height, color)
        self.points = points


if __name__ == "__main__":
    print("=== Garden Management System Demo ===")

    gm = GardenManager()
    gm.add_user("Alice")
    gm.create_garden_network("Alice", "Oak Tree", 100,
                             "Rose", 25, "Red flowers",
                             "Sunflower", 50, "yellow flowers", 50)
