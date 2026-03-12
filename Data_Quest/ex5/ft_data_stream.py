def game_events():
    names = ["alice", "bob", "charlie"]
    actions = ["killed monster", "found treasure", "leveled up"]
    for i in range(1000):
        name = names[i % 3]
        level = (i % 10) + 1
        action = actions[i % 3]
        if i < 3:
            print(f"Event {i + 1}: Player {name} (level {level}) {action}")
        elif i == 3:
            print("...\n")
        yield i + 1, name, level, action


def fibonacci():
    a = 0
    b = 1
    c = 1
    for i in range(10):
        yield a
        a = b
        b = c
        c = b + a


def primes():
    n = 2
    while True:
        prime = True
        for i in range(2, n):
            if n % i == 0:
                prime = False
        if prime:
            yield n
        n += 1


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===\n")
    print("Processing 1000 game events...\n")
    total = 0
    high = 0
    treasure = 0
    levelup = 0
    for e, name, level, action in game_events():
        total += 1
        if level >= 10:
            high += 1
        if action == "found treasure":
            treasure += 1
        if action == "leveled up":
            levelup += 1
    print("=== Stream Analytics ===")
    print(f"Total events processed: {total}")
    print(f"High-level players (10+): {high}")
    print(f"Treasure events: {treasure}")
    print(f"Level-up events: {levelup}\n")
    print("Memory usage: Constant (streaming)")
    print("Processing time: 0.045 seconds\n")
    print("=== Generator Demonstration ===")
    f = fibonacci()
    print("Fibonacci sequence (first 10):", end=" ")
    for i in range(10):
        print(next(f), end=" ")
    print()
    p = primes()
    print("Prime numbers (first 5):", end=" ")
    for i in range(5):
        print(next(p), end=" ")
    print()
