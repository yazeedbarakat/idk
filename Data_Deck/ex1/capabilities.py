from abc import ABC, abstractmethod
from ex0.creatures import Creature


class HealCapability(ABC):
    @abstractmethod
    def heal(self, target: str = "") -> str:
        pass


class TransformCapability(ABC):
    def __init__(self) -> None:
        self._transformed = False

    @abstractmethod
    def transform(self) -> str:
        pass

    @abstractmethod
    def revert(self) -> str:
        pass


class Sproutling(Creature, HealCapability):
    def attack(self) -> str:
        return "Sproutling uses Vine Whip!"

    def heal(self, target: str = "") -> str:
        return f"Sproutling heals {target} for a small amount"


class Bloomelle(Creature, HealCapability):
    def attack(self) -> str:
        return "Bloomelle uses Petal Dance!"

    def heal(self, target: str = "") -> str:
        return f"Bloomelle heals {target} for a large amount"


class Shiftling(Creature, TransformCapability):
    def __init__(self, cname: str, ctype: str) -> None:
        Creature.__init__(self, cname, ctype)
        TransformCapability.__init__(self)

    def attack(self) -> str:
        if self._transformed:
            return "Shiftling performs a boosted strike!"
        return "Shiftling attacks normally."

    def transform(self) -> str:
        self._transformed = True
        return "Shiftling shifts into a sharper form!"

    def revert(self) -> str:
        self._transformed = False
        return "Shiftling returns to normal."


class Morphagon(Creature, TransformCapability):
    def __init__(self, cname: str, ctype: str) -> None:
        Creature.__init__(self, cname, ctype)
        TransformCapability.__init__(self)

    def attack(self) -> str:
        if self._transformed:
            return "Morphagon unleashes a devastating morph strike!"
        return "Morphagon attacks normally."

    def transform(self) -> str:
        self._transformed = True
        return "Morphagon morphs into a dragonic battle form!"

    def revert(self) -> str:
        self._transformed = False
        return "Morphagon stabilizes its form."
