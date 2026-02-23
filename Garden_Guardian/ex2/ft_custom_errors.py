class GardenError(Exception):
    pass


class PlantError(GardenError):
    pass


class WaterError(GardenError):
    pass


def test_errors(error: str) -> None:
    try:
        if error == 'Garden':
            raise GardenError
        elif error == 'Plant':
            raise PlantError
        elif error == 'Water':
            raise WaterError
    except PlantError:
        print("Caught PlantError: The tomato plant is wilting!")
    except WaterError:
        print("Caught WaterError: Not enough water in the tank!")
    except GardenError:
        print("Caught a garden error: The tomato plant is wilting!")
        print("Caught a garden error: Not enough water in the tank!")


if __name__ == '__main__':
    print("=== Custom Garden Errors Demo ===")
    print("\nTesting PlantError...")
    test_errors('Plant')
    print("\nTesting WaterError...")
    test_errors('Water')
    print('\nTesting catching all garden errors...')
    test_errors('Garden')
    print('\nAll custom error types work correctly!')
