import sys

if __name__ == "__main__":
    print("=== Command Quest ===")
    argl = len(sys.argv)
    if argl == 1:
        print("No arguments provided!")
        print(f"Program name: {sys.argv[0]}")
    else:
        print(f"Program name: {sys.argv[0]}")
        print(f"Arguments received: {argl - 1}")
    i = 1
    for a in sys.argv[1:]:
        print(f"Argument {i}: {a}")
        i += 1
    print(f"Total arguments: {argl}")
