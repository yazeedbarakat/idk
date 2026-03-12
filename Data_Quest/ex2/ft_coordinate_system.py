import math


def distance(pos1: tuple, pos2: tuple) -> float:
    return (math.sqrt((pos2[0] - pos1[0]) ** 2 +
                      (pos2[1] - pos1[1]) ** 2 + (pos2[2] - pos1[2]) ** 2))


if __name__ == "__main__":
    print("=== Game Coordinate System ===\n")
    position = (10, 20, 5)
    print(f"Position created: {position}")
    print(f"Distance between (0, 0, 0) and {position}: {distance((0, 0, 0),
          position):.2f}")
    coordinates = "3,4,0"
    print(f"\nParsing coordinates: \"{coordinates}\"")
    args = coordinates.split(',')
    x = int(args[0])
    y = int(args[1])
    z = int(args[2])
    coordinates = (x, y, z)
    print(f"Parsed position: {coordinates}")
    print(f"Distance between (0, 0, 0) and {coordinates}: {distance((0, 0, 0),
          coordinates):.1f}")
    try:
        coordinates = "abc,def,ghi"
        print(f"\nParsing invalid coordinates: \"{coordinates}\"")
        args = coordinates.split(',')
        x = int(args[0])
        y = int(args[1])
        z = int(args[2])
        coordinates = (x, y, z)
        print(f"Parsed position: {coordinates}")
        print(f"Distance between (0, 0, 0) and {coordinates}:",
              f"{distance((0, 0, 0), coordinates):.1f}")
    except ValueError as e:
        print(f"Error parsing coordinates: {e}")
        print(f"Error details - Type: ValueError, Args: (\"{e}\",)")
    print("\nUnpacking demonstration:")
    print(f"Player at x={x}, y={y}, z={z}")
    print(f"Coordinates: X={x}, Y={y}, z={z}")
