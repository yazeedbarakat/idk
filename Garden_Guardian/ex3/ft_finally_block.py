def water_plants(plant_list: list) -> None:
    print("Opening watering system")
    try:
        for p in plant_list:
            if p is None:
                raise ValueError("Cannot water None - invalid plant!")
            print(f"Watering {p}")
    except ValueError as e:
        print(f"Error: {e}")
    finally:
        print("Closing watering system (cleanup)")


def test_watering_system() -> None:
    print("=== Garden Watering System ===")
    print("\nTesting normal watering...")
    water_plants(['tomato', 'lettuce', 'carrots'])
    print("Watering completed successfully!")
    print("\nTesting with error...")
    water_plants(['tomato', None])
    print("\nCleanup always happens, even with errors!")


if __name__ == "__main__":
    test_watering_system()
