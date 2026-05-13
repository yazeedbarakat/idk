import functools
import operator
from typing import Any
from collections.abc import Callable


def spell_reducer(spells: list[int], operation: str) -> int:
    if not spells:
        return 0
    ops: dict[str, Callable] = {
        "add": operator.add,
        "multiply": operator.mul,
        "max": lambda a, b: a if a > b else b,
        "min": lambda a, b: a if a < b else b,
    }
    if operation not in ops:
        raise ValueError(f"Unknown operation: {operation}")
    return functools.reduce(ops[operation], spells)


def partial_enchanter(
    base_enchantment: Callable,
) -> dict[str, Callable]:
    return {
        "fire": functools.partial(base_enchantment, 50, "fire"),
        "water": functools.partial(base_enchantment, 50, "water"),
        "earth": functools.partial(base_enchantment, 50, "earth"),
    }


@functools.lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    if n <= 0:
        return 0
    if n == 1:
        return 1
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    @functools.singledispatch
    def dispatch(spell: Any) -> str:
        return "Unknown spell type"

    @dispatch.register(int)
    def _(spell: int) -> str:
        return f"{spell} damage"

    @dispatch.register(str)
    def _(spell: str) -> str:
        return spell

    @dispatch.register(list)
    def _(spell: list) -> str:
        return f"{len(spell)} spells"

    return dispatch


if __name__ == "__main__":
    spells = [10, 20, 30, 40]
    print("Testing spell reducer...")
    print(f"Sum:  {spell_reducer(spells, 'add')}")
    print(f"Product:  {spell_reducer(spells, 'multiply')}")
    print(f"Max:  {spell_reducer(spells, 'max')}")

    print("\nTesting memoized fibonacci...")
    print(f"Fib(0):  {memoized_fibonacci(0)}")
    print(f"Fib(1):  {memoized_fibonacci(1)}")
    print(f"Fib(10):  {memoized_fibonacci(10)}")
    print(f"Fib(15):  {memoized_fibonacci(15)}")

    print("\nTesting spell dispatcher...")
    dispatch = spell_dispatcher()
    print(f"Damage spell:  {dispatch(42)}")
    print(f"Enchantment:  {dispatch('fireball')}")
    print(f"Multi-cast:  {dispatch(['a', 'b', 'c'])}")
    print(dispatch(3.14))

    def base_enchant(power: int, element: str, target: str) -> str:
        return f"{element.capitalize()} enchantment ({power}) on {target}"

    print("\nTesting partial enchanter...")
    enchants = partial_enchanter(base_enchant)
    print(enchants["fire"]("Sword"))
    print(enchants["water"]("Shield"))
