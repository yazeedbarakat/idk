class GardenError(Exception):
    pass


class PlantError(GardenError):
    pass


class WaterError(GardenError):
    pass


class GardenManager:
    plants = []

    def add_plant(self, name: str) -> None:
        try:
            if name == "":
                raise ValueError("Plant name cannot be empty!")
            self.plants += [name]
            print(f"Added {name} successfully")
        except ValueError as e:
            print(f"Error adding plant: {e}")

    def water_plants(self) -> None:
        print("Opening watering system")
        try:
            for p in self.plants:
                print(f"Watering {p} - success")
        except Exception as e:
            print(f"Error: {e}")
        finally:
            print("Closing watering system (cleanup)")

    def check_plant_health(self, name: str, water: int, sun: int) -> None:
        try:
            if water < 1:
                raise ValueError(f"Water level {water} is too low (min 1)")
            if water > 10:
                raise ValueError(f"Water level {water} is too high (max 10)")
            if sun < 2:
                raise ValueError(f"Sunlight hours {sun} is too low (min 2)")
            if sun > 12:
                raise ValueError(
                       f"Sunlight hours {sun} is too high (max 12)"
                       )
            print(f"{name}: healthy (water: {water}, sun: {sun})")
        except ValueError as e:
            print(f"Error checking {name}: {e}")


def test_garden_management() -> None:
    print("=== Garden Management System ===")
    print("\nAdding plants to garden...")
    gm = GardenManager()
    gm.add_plant("tomato")
    gm.add_plant("lettuce")
    gm.add_plant("")
    print("\nWatering plants...")
    gm.water_plants()
    print("\nChecking plant health...")
    gm.check_plant_health("tomato", 5, 8)
    gm.check_plant_health("lettuce", 15, 7)
    print("\nTesting error recovery...")
    try:
        raise WaterError("Not enough water in tank")
    except GardenError as e:
        print(f"Caught GardenError: {e}")
        print("System recovered and continuing...")
    print("\nGarden management system test complete!")


if __name__ == '__main__':
    test_garden_management()
