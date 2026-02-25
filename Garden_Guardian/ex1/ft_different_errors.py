def garden_operations() -> None:
    print("Testing ValueError...")
    try:
        for c in 'abc':
            if c > '9' or c < '0':
                raise ValueError('invalid literal for int()')
    except ValueError as e:
        print(f"Caught ValueError: {e}")
    print("\nTesting ZeroDivisionError...")
    try:
        result = 1
        result *= 10 / 0
    except ZeroDivisionError as e:
        print(f"Caught ZeroDivisionError: {e}")
    print("\nTesting FileNotFoundError...")
    try:
        f = open("missing.txt")
        f.close()
    except FileNotFoundError:
        print("Caught FileNotFoundError: No such file 'missing.txt'")
    print("\nTesting KeyError...")
    try:
        plants = {"tomato": 5, "lettuce": 3}
        p = plants["missing_plant"]
        p += p
    except KeyError as e:
        print(f"Caught KeyError: {e}")
    print("\nTesting multiple errors together...")
    try:
        x = 0
        x += 10 / 'y'
    except (ValueError, TypeError):
        print("Caught an error, but program continues!")


def test_error_types() -> None:
    """Run all error type demonstrations."""
    print("=== Garden Error Types Demo ===\n")
    garden_operations()
    print("\nAll error types tested successfully!")


if __name__ == '__main__':
    test_error_types()
