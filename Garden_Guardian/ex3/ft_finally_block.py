def Watering_System(plants: list) -> None:
    print("Opening watering system")
    try:
        for p in plants:
            if p is None:
                raise ValueError
            print(f"Watering {p}")
    except ValueError:
        print("Error: Cannot water None - invalid plant!")
    finally:
        print("Closing watering system (cleanup)")


def Test_System():
    print("=== Garden Watering System ===")
    print("\nTesting normal watering...")
    Watering_System(['tomato', 'lettuce', 'carrots'])
    print("Watering completed successfully!")
    print("\nTesting with error...")
    Watering_System(['tomato', None])
    print("\nCleanup always happens, even with errors!")


if __name__ == "__main__":
    Test_System()
