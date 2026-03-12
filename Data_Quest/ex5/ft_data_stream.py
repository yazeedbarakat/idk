def game_events(n):
    names = ["alice", "bob", "charlie"]
    actions = ["killed monster", "found treasure", "leveled up"]
    for i in range(n):
        name = names[i % 3]
        level = (i % 15) + 1
        action = actions[i % 3]
        yield i + 1, name, level, action


def fibonacci():
    a = 0
    b = 1
    while True:
        yield a
        a = b
        b = a + b


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
    total = 0
    high = 0
    treasure = 0
    levelup = 0
    for e, name, level, action in game_events(1000):
        total += 1
        if level >= 10:
            high += 1
        if action == "found treasure":
            treasure += 1
        if action == "leveled up":
            levelup += 1
    print("Total events:", total)
    print("High level:", high)
    print("Treasure:", treasure)
    print("Level up:", levelup)
    f = fibonacci()
    print("Fibonacci:", end=" ")
    for i in range(10):
        print(next(f), end=" ")
    print()
    p = primes()
    print("Primes:", end=" ")
    for i in range(5):
        print(next(p), end=" ")
