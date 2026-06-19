import functools
import operator
from typing import Any
from collections.abc import Callable


def base_enchantment(power: int, element: str, target: str) -> str:
    return f"{target} attacked using {element} element with {power} power"


def spell_reducer(spells: list[int], operation: str) -> int:
    operations: dict[str, Callable[..., int]] = {
            'add': operator.add,
            'multiply': operator.mul,
            'max': max,
            'min': min
            }
    if not spells:
        return 0
    try:
        return functools.reduce(operations[operation], spells)
    except KeyError:
        print(f"{operation} isnt one of the known operations")
        return 0


def partial_enchanter(base_enchantment: Callable[..., str]
                      ) -> dict[str, Callable[..., str]]:
    fire_enchant = functools.partial(base_enchantment, 50, 'fire')
    water_enchant = functools.partial(base_enchantment, 50, 'water')
    air_enchant = functools.partial(base_enchantment, 50, 'air')
    return {'fire': fire_enchant, 'water': water_enchant, 'air': air_enchant}


@functools.lru_cache
def memoized_fibonacci(n: int) -> int:
    if n <= 1:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    @functools.singledispatch
    def dispatcher(spell: Any) -> str:
        return "Unknown spell type"

    @dispatcher.register(int)
    def _(spell: int) -> str:
        return f"{spell} damage"

    @dispatcher.register(str)
    def _(spell: str) -> str:
        return spell

    @dispatcher.register(list)
    def _(spell: list[Any]) -> str:
        return f"{len(spell)} spells"
    return dispatcher


def main() -> None:
    print("Testing spell reducer...")
    spells = [10, 20, 40, 30]
    print('Sum:', spell_reducer(spells, 'add'))
    print('Product:', spell_reducer(spells, 'multiply'))
    print('Max:', spell_reducer(spells, 'max'))
    print("\nTesting partial enchanter...")
    enchanter = partial_enchanter(base_enchantment)
    print(enchanter['fire']('dragon'),
          enchanter['water']('dragon'),
          enchanter['air']('dragon'), sep='\n')
    print("\nTesting memoized fibonacci...")
    print("Fib(0):", memoized_fibonacci(0))
    print("Fib(1):", memoized_fibonacci(1))
    print("Fib(10):", memoized_fibonacci(10))
    print("Fib(15):", memoized_fibonacci(15))
    print("\nTesting spell dispatcher...")
    dis = spell_dispatcher()
    print("Damage spell:", dis(42))
    print("Enchantment:", dis('fireball'))
    print("Multi-cast:", dis(['fire', 'water', 'air']))
    print(dis(3.14))


if __name__ == "__main__":
    main()
