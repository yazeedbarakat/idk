from ex0 import FlameFactory, AquaFactory, CreatureFactory


def test_factory(factory: CreatureFactory) -> None:
    print("Testing factory")
    base = factory.create_base()
    print(base.describe())
    print(base.attack())
    evolved = factory.create_evolved()
    print(evolved.describe())
    print(evolved.attack())


def test_battle(factory_a: CreatureFactory,
                factory_b: CreatureFactory) -> None:
    print("\nTesting battle")
    creature_a = factory_a.create_base()
    creature_b = factory_b.create_base()
    print(creature_a.describe())
    print("vs.")
    print(creature_b.describe())
    print("fight!")
    print(creature_a.attack())
    print(creature_b.attack())


if __name__ == "__main__":
    flamefact = FlameFactory()
    waterfact = AquaFactory()
    test_factory(flamefact)
    print()
    test_factory(waterfact)
    test_battle(flamefact, waterfact)
