import functools

def spell_timer(func: Callable) -> Callable:
    @functools.wraps(func)
    def wrapper(*args, **kwargs) -> Callable:
        print("Casting", func.__name__)
        t1 = time.time()
        fun = func(*args, **kwargs)
        t2 = time.time()
        print(f"Spell completed in {t1 - t2} seconds")
    return wrapper


@spell_timer
def fireball() -> str:
    return "hit using fireball"


def main() -> None:
    


if __name__ == "__main__":
    main()
