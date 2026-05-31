from collections.abc import Callable


def mage_counter() -> Callable:
    count: int = 0
    def counter() -> int:
        nonlocal count
        count += 1
        return count
    return counter

def spell_accumulator(initial_power: int) -> Callable:
    def power_adder(amount: int) -> int:
        nonlocal initial_power
        initial_power += amount
        return initial_power
    return power_adder


def enchantment_factory(enchantment_type: str) -> Callable:
    return lambda item: f"{enchantment_type} {item}"

def memory_vault() -> dict[str, Callable]:
    d = {}
    def store(key: str, value: int) -> None:
        d[key] = value
    def recall(key: str) -> int | str:
        try:
            return d[key]
        except KeyError:
            return "Memory not found"
    return {'store': store, 'recall': recall}


def main() -> None:
    print("Testing mage counter...")
    counter_a = mage_counter()
    counter_b = mage_counter()
    print("counter_a call 1:", counter_a())
    print("counter_a call 2:", counter_a())
    print("counter_b call 1:", counter_b())
    print("\nTesting spell accumulator...")
    accumulator = spell_accumulator(100)
    print("Base 100, add 20:", accumulator(20))
    print("Base 100, add 30:", accumulator(30))
    print("\nTesting enchantment factory...")
    Flaming = enchantment_factory("Flaming")
    Frozen = enchantment_factory("Frozen")
    print(Flaming("Sword"))
    print(Frozen("Shield"))
    print("\nTesting memory vault...")
    vault = memory_vault()
    store = vault['store']
    recall = vault['recall']
    print("Store 'secret' = 42")
    store('secret', 42)
    print("Recall 'secret':", recall('secret'))
    print("Recall 'unknown':", recall('unknown'))

if __name__ == "__main__":
    main()
