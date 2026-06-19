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


def spell_combiner(spell1: Callable[[str, int], str],
                   spell2: Callable[[str, int], str]
                   ) -> Callable[[str, int], tuple[str, str]]:
    def combiner(target: str, power: int) -> tuple[str, str]:
        s1 = spell1(target, power)
        s2 = spell2(target, power)
        return (s1, s2)
    return combiner


def power_amplifier(base_spell: Callable[[str, int], str],
                    multiplier: int
                    ) -> Callable[[str, int], str]:
    def amplifier(target: str, power: int) -> str:
        return base_spell(target, multiplier * power)
    return amplifier


def conditional_caster(condition: Callable[[str, int], bool],
                       spell: Callable[[str, int], str]
                       ) -> Callable[[str, int], str]:
    def cast(target: str, power: int) -> str:
        if condition(target, power):
            return spell(target, power)
        return "Spell fizzled"
    return cast


def spell_sequence(spells: list[Callable[[str, int], str]]
                   ) -> Callable[[str, int], list[str]]:
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
    print(f"Original: {fireball('Dragon', 10)}, Amplified:",
          f"{mega_fireball('Dragon', 10)}")
    print("\nTesting conditional caster...")
    caster = conditional_caster(power_check, freeze)
    print(f"Casting: {caster("Dragon", 15)}, {caster("Dragon", 5)}")
    print("\nTesting spell sequence...")
    sequence = spell_sequence([heal, fireball, freeze, poison])
    print("sequence:", *sequence('Dragon', 20), sep="\n")


if __name__ == "__main__":
    main()
