from collections.abc import Callable


def heal(target: str, power: int) -> str:
    return f"Heal restores {target} for {power} HP"

def fireball(target: str, power: int) -> str:
    return f"Fireball hits {target} with {power}"

def freeze(target: str, power: int) -> str:
    return f"{target} is frozen with {power} ice power"

def poison(target: str, power: int) -> str:
    return f"{target} is poisoned for {power} damage over time"

def power_check(target: str, power: int) -> bool:
    if power > 10:
        return True
    return False

def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    def combiner(target: str, power: int) -> tuple:
        s1 = spell1(target, power)
        s2 = spell2(target, power)
        return (s1, s2)
    return combiner

def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    def amplifier(target: str, power: int) -> str:
        return base_spell(target, multiplier * power)
    return amplifier


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def cast(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        return "Spell fizzled"
    return cast

def spell_sequence(spells: list[Callable]) -> Callable:
    def helper(target: str, power: int) -> list[str]:
        return [x(target, power) for x in spells]
    return helper

def main() -> None:
    print("\nTesting spell combiner...")
    combined = spell_combiner(fireball, heal)
    x, y = combined('Dragon', 23)
    print(f"Combined spell result: {x}, {y}")
    print("\nTesting power amplifier...")
    mega_fireball = power_amplifier(fireball, 3)
    print(f"Original: {fireball('Dragon', 10)}, Amplified: {mega_fireball('Dragon', 10)}")
    print("\nTesting conditional caster...")
    caster = conditional_caster(power_check, freeze)
    print(f"Casting: {caster("Dragon", 15)}, {caster("Dragon", 5)}")
    print("\nTesting spell sequence...")
    sequence = spell_sequence([heal, fireball, freeze, poison])
    print("sequence:" ,*sequence('Dragon', 20), sep="\n")
if __name__ == "__main__":
    main()
