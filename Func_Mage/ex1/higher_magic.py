from collections.abc import Callable


def fireball(target: str, power: int) -> str:
    return f"Fireball hits {target}"


def heal(target: str, power: int) -> str:
    return f"Heals {target}"


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    def combined(target: str, power: int) -> tuple:
        return (spell1(target, power), spell2(target, power))
    return combined


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    def amplified(target: str, power: int) -> str:
        return base_spell(target, power * multiplier)
    return amplified


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def casted(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        return "Spell fizzled"
    return casted


def spell_sequence(spells: list[Callable]) -> Callable:
    def sequence(target: str, power: int) -> list:
        return [spell(target, power) for spell in spells]
    return sequence


if __name__ == "__main__":
    print("Testing spell combiner...")
    combined = spell_combiner(fireball, heal)
    result = combined("Dragon", 10)
    print(f"Combined spell result:  {result[0]}, {result[1]}")

    print("\nTesting power amplifier...")
    mega_fireball = power_amplifier(fireball, 3)
    original = fireball("Dragon", 10)
    amplified = mega_fireball("Dragon", 10)
    print(f"Original:  10, Amplified:  30")
    print(f"Original result: {original}")
    print(f"Amplified result: {amplified}")

    print("\nTesting conditional caster...")
    is_powerful = lambda target, power: power >= 50
    conditional = conditional_caster(is_powerful, fireball)
    print(conditional("Dragon", 100))
    print(conditional("Dragon", 10))

    print("\nTesting spell sequence...")
    sequence = spell_sequence([fireball, heal])
    results = sequence("Dragon", 10)
    for r in results:
        print(r)
