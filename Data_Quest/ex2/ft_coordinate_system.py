import sys
import math

if __name__ == "__main__":
    print("=== Game Coordinate System ===\n")

    try:
        args = sys.argv[1].split(',')
        x = int(args[0])
        y = int(args[1])
        z = int(args[2])
        print(f"Parsing coordinates: {sys.argv[1]}")
        coordinates = (x, y, z)
        print(f"Parsed position: {coordinates}")
        distance = math.sqrt((x-0)**2 + (y-0)**2 + (z-0)**2) 
        print(f"Distance between (0, 0, 0) and {coordinates}: {distance:.2f}")
        print("\nUnpacking demonstration:")
        print(f"Player at x={x}, y={y}, z={z}")
        print(f"Coordinates: X={x}, Y={y}, z={z}")
    except Exception as e:
        print(f"Parsing invalid coordinates: \"{sys.argv[1]}\"")
        print(f"Error parsing coordinates: {e}")
