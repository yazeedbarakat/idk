import functools
import time
from collections.abc import Callable


def spell_timer(func: Callable) -> Callable:
    @functools.wraps(func)
    def wrapper(*args: object, **kwargs: object) -> object:
        print(f"Casting {func.__name__}...")
        start = time.time()
        result = func(*args, **kwargs)
        elapsed = time.time() - start
        print(f"Spell completed in {elapsed:.3f} seconds")
        return result
    return wrapper


def power_validator(min_power: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args: object, **kwargs: object) -> object:
            power = args[0]
            if isinstance(power, int) and power >= min_power:
                return func(*args, **kwargs)
            return "Insufficient power for this spell"
        return wrapper
    return decorator


def retry_spell(max_attempts: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @functools.wraps(func)
        def wrapper(*args: object, **kwargs: object) -> object:
            for attempt in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    if attempt < max_attempts:
                        print(
                            f"Spell failed, retrying..."
                            f"  (attempt {attempt}/{max_attempts})"
                        )
                    else:
                        return (
                            f"Spell casting failed after {max_attempts} attempts"
                        )
        return wrapper
    return decorator


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        return len(name) >= 3 and all(c.isalpha() or c == ' ' for c in name)

    def cast_spell(self, spell_name: str, power: int) -> str:
        @power_validator(10)
        def _cast(p: int) -> str:
            return f"Successfully cast {spell_name} with {p} power"
        return str(_cast(power))


if __name__ == "__main__":
    @spell_timer
    def fireball() -> str:
        time.sleep(0.1)
        return "Fireball cast!"

    print("Testing spell timer...")
    result = fireball()
    print(f"Result:  {result}")

    print("\nTesting retrying spell...")

    @retry_spell(3)
    def failing_spell() -> str:
        raise RuntimeError("Spell failed!")

    print(failing_spell())

    @retry_spell(3)
    def waaaagh() -> str:
        return "Waaaaaaagh spelled !"

    print(waaaagh())

    print("\nTesting MageGuild...")
    guild = MageGuild()
    print(MageGuild.validate_mage_name("Gandalf"))
    print(MageGuild.validate_mage_name("X"))
    print(guild.cast_spell("Lightning", 15))
    print(guild.cast_spell("Lightning", 5))
