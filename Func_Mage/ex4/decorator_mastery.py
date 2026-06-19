import functools
import time
from collections.abc import Callable
from typing import Any


def spell_timer(func: Callable[..., Any]) -> Callable[..., Any]:
    @functools.wraps(func)
    def wrapper(*args: Any, **kwargs: Any) -> Any:
        print(f"Casting {func.__name__}...")
        t1 = time.time()
        fun = func(*args, **kwargs)
        t2 = time.time()
        print(f"Spell completed in {t2 - t1:.3f} seconds")
        return fun
    return wrapper


def power_validator(min_power: int) -> Callable[..., Any]:
    def decorator(func: Callable[..., Any]) -> Callable[..., Any]:
        @functools.wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            if args[2] >= min_power:
                return func(*args, **kwargs)
            return "Insufficient power for this spell"
        return wrapper
    return decorator


def retry_spell(max_attempts: int) -> Callable[..., Any]:
    def decorator(func: Callable[..., Any]) -> Callable[..., Any]:
        @functools.wraps(func)
        def wrapper(*args: Any, **kwargs: Any) -> Any:
            for i in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    if i != max_attempts:
                        print("Spell failed, retrying...",
                              f"(attempt {i}/{max_attempts})")
            return f"Spell casting failed after {max_attempts} attempts"
        return wrapper
    return decorator


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        if len(name) >= 3 and all(x.isalpha() or x == ' ' for x in name):
            return True
        return False

    @power_validator(10)
    def cast_spell(self, spell_name: str, power: int) -> str:
        return f"Successfully cast {spell_name} with {power} power"


@spell_timer
def fireball() -> str:
    time.sleep(0.1)
    return "Fireball cast!"


def lightning(power: int) -> str:
    return f"Successfully cast Lightning with {power} power"


def main() -> None:
    print("Testing spell timer...")
    print("Result:", fireball())
    print("\nTesting retrying spell...")

    @retry_spell(3)
    def test1() -> None:
        raise ValueError("testing error")

    @retry_spell(3)
    def test2() -> str:
        return "spelled !"
    print(test1())
    print(test2())
    print("\nTesting MageGuild...")
    mg = MageGuild()
    print(mg.validate_mage_name('yazeed'))
    print(mg.validate_mage_name('rrr2'))
    print(mg.cast_spell('lightning', 15))
    print(mg.cast_spell('fireball', 9))


if __name__ == "__main__":
    main()
