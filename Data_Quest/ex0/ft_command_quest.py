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
    for i in range(1, argl):
        print(f"Argument {i}: {sys.argv[i]}")
    print(f"Total arguments: {argl}")    
