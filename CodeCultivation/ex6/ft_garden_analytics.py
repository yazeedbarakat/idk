class GardenManager:
    users = []
    def __init__(self, user_name: str):
        users += [user_name]
    class GardenStats:
        def print_report(self):
             

class Plant:
    def __init__(self, name: str, height: int):
        self.name = name
        self.height = height

    def grow(self, plant_type: str, growth: int) -> None:
        self.height += growth
        print(f"{self.name} {plant_type} grew {growth}cm")

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
    def __init__(self, name: str, height: int, color: str, points: int)
        super().__init__(name, height, color)
        self.points = points


if __name__ = "__main__":
    print("=== Garden Management System Demo ===")

    print("
