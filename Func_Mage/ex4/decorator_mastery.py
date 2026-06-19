import functools
import time
from collections.abc import Callable


def spell_timer(func: Callable) -> Callable:
    @functools.wraps(func)
    def wrapper(*args, **kwargs) -> Callable:
        print(f"Casting {func.__name__}...")
        t1 = time.time()
        fun = func(*args, **kwargs)
        t2 = time.time()
        print(f"Spell completed in {t2 - t1:.3f} seconds")
        return fun
    return wrapper


def power_validator(min_power: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args, **kwargs) -> Callable | str:
            if args[0] >= min_power:
                return func(*args, **kwargs)
            return "Insufficient power for this spell"
        return wrapper
    return decorator


def retry_spell(max_attempts: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        def wrapper(*args, **kwargs) -> str:
            for i in range(1, max_attempts):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    print(f"Spell failed, retrying... ({i}/{max_attempts})")
            return f"Spell casting failed after {max_attempts} attempts"
        return wrapper
    return decorator

class MageGuild:
    @staticmethod
    def validate_mage_name(name) -> str:
        if len(name) >= 3 and x not in 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ' for x in name:
            return 'name is invalid'
        return 'name is valid'
    @power_validator(10)
    def cast_spell(self, spell_name, power):
        return f"Successfully cast {spell_name} with {power} power"
        

@spell_timer
def fireball() -> str:
    return "Fireball cast!"


def lightning(power: int) -> str:
    return f"Successfully cast Lightning with {power} power"


def main() -> None:
    print("Testing retrying spell...")
    print("Result:", fireball())


if __name__ == "__main__":
    main()
