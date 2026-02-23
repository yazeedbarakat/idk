class GardenManager:
    plants = []
    def add_plant(self, name: str, water_level: int, sunlight_hours: int) -> None:
        try:
            if plant == "":
                raise ValueError
            self.plants += [plant]
            self.{name}
            print(f"Added {plant} successfully")
        except ValueError:
            print("Error adding plant: Plant name cannot be empty!")

    def water_plants(self):
        print("Opening watering system")
        try:
            for p in self.plants:
                if p is None:
                    raise ValueError
                print(f"Watering {p} - success")
        except ValueError:
            print("Error: Cannot water None - invalid plant!")
        finally:
            print("Closing watering system (cleanup)")


    def check_plant_health(self):
        try:
            for p in plants:
                if plant_name == "":
                    raise ValueError("Plant name cannot be empty!")
                if water_level < 1:
                     raise ValueError(f"Water level {water_level} is too low (min 1)")
                if water_level > 10:
                    raise ValueError(f"Water level {water_level} is too high (max 10)")
                if sunlight_hours < 2:
                    raise ValueError(f"Sunlight hours {sunlight_hours} is too low (min 2)")
                if sunlight_hours > 12:
                    raise ValueError(
                            f"Sunlight hours {sunlight_hours} is too high (max 12)"
                            )
        except ValueError as e:
            print(f"Error checking {plant}")

class Plant:
    def __init__(self, n: str, wl: int, sh: int):
        self.name = n
        self.water_level = wl
        self.sunlight_hours = sh


if __name__ == "__main__":
    print("=== Garden Management System ===")
    print("\nAdding plants to garden...")
    gm = GardenManager()
    gm.add_plant("tomato", 5, 8)
    gm.add_plant("lettuce", 15, 7)
    gm.add_plant("")
    print("\nWatering plants...")
    gm.water_plants()
    print("\nChecking plant health...")

