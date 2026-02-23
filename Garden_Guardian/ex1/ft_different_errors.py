def garden_operations(ntype: str, num: int, file: bool,
                      file_name: str, key: str) -> None:
    try:
        if ntype == "string":
            raise ValueError
        dic = {"Plant": "Tree", "Flowering": "Rose"}
        num = 10 / num
        if file:
            f = open(file_name)
            f.close()
        p = dic[key]
        print(p)

    except ValueError:
        print("Caught ValueError: invalid literal for int()")
    except ZeroDivisionError:
        print("Caught ZeroDivisionError: division by zero")
    except FileNotFoundError:
        print(f"Caught FileNotFoundError: No such file ’{file_name}’")
    except KeyError:
        print(f"Caught KeyError: ’{key}’")
    except (ValueError, ZeroDivisionError, FileNotFoundError,
            KeyError, IndexError, AttributeError, TypeError):
        print("Caught an error, but program continues!")


def test_error_types() -> None:
    print("=== Garden Error Types Demo ===")
    print("\nTesting ValueError...")
    garden_operations('string', 0, False, "m", "Plant")
    print("\nTesting ZeroDivisionError...")
    garden_operations('num', 0, False, "m", "Plant")
    print("\nTesting FileNotFoundError...")
    garden_operations('num', 10, True, "missing.txt", "Plant")
    print("\nTesting KeyError...")
    garden_operations('num', 10, False, "m",  "missing_plant")
    print("\nTesting multiple errors together...")
    garden_operations('num', 'non', True, "missing.txt", "missing_plant")
    print("\nAll error types tested successfully!")


if __name__ == "__main__":
    test_error_types()
