from abc import ABC, abstractmethod
from typing import Any
from ex0 import Creature
from ex1 import HealCapability, TransformCapability


class BattleStrategy(ABC):
    @abstractmethod
    def act(self, c: Any) -> None:
        pass

    @abstractmethod
    def is_valid(self, c: Any) -> bool:
        pass


class NormalStrategy(BattleStrategy):
    def act(self, c: Any) -> None:
        if not self.is_valid(c):
            msg = f"Invalid Creature '{c.name}' for this normal strategy"
            raise ValueError(msg)
        print(c.attack())

    def is_valid(self, c: Any) -> bool:
        return isinstance(c, Creature)


class AggressiveStrategy(BattleStrategy):
    def act(self, c: Any) -> None:
        if not self.is_valid(c):
            msg = f"Invalid Creature '{c.name}' for this aggressive strategy"
            raise ValueError(msg)
        print(c.transform())
        print(c.attack())
        print(c.revert())

    def is_valid(self, c: Any) -> bool:
        return isinstance(c, TransformCapability)


class DefensiveStrategy(BattleStrategy):
    def act(self, c: Any) -> None:
        if not self.is_valid(c):
            msg = f"Invalid Creature '{c.name}' for this defensive strategy"
            raise ValueError(msg)
        print(c.attack())
        print(c.heal("itself"))

    def is_valid(self, c: Any) -> bool:
        return isinstance(c, HealCapability)
