class Plant:
    def __init__(self, name: str, height: int = 0, age: int = 0) -> None:
        self.name = name
        self.__height = 0
        self.__age = 0
        if height < 0 or height > 11600:
            print("\nInvalid operation attempted:", end=" ")
            print(f"height {height}cm [REJECTED]")
            if height < 0:
                print("Security: Negative height rejected, height set to 0")
            if height > 11600:
                print("Security: Impossible height rejected, height set to 0")
        else:
            self.__height = height
        if age < 0 or age > 100000:
            print(f"\nInvalid operation attempted: age {age} days [REJECTED]")
            if age < 0:
                print("Security: Negative age rejected, age set to 0")
            if age > 100000:
                print("Security: Impossible age rejected, age set to 0")
        else:
            self.__age = age

    def set_height(self, new_height: int) -> None:
        if new_height < 0 or new_height > 11600:
            print("\nInvalid operation attempted:", end=" ")
            print(f"height {new_height}cm [REJECTED]")
            if new_height < 0:
                print("Security: Negative height rejected")
            if new_height > 11600:
                print("Security: Impossible height rejected")
            return
        self.__height = new_height
        print(f"Height updated: {self.__height}cm [OK]")

    def set_age(self, new_age: int) -> None:
        if new_age < 0 or new_age > 100000:
            print("\nInvalid operation attempted:", end=" ")
            print(f"age {new_age} days [REJECTED]")
            if new_age < 0:
                print("Security: Negative age rejected")
            if new_age > 100000:
                print("Security: Impossible age rejected")
            return
        self.__age = new_age
        print(f"Age updated: {self.__age} days [OK]")

    def get_height(self) -> int:
        return self.__height

    def get_age(self) -> int:
        return self.__age


if __name__ == "__main__":
    print("=== Garden Security System ===")
    p1 = Plant("Rose")
    print("Plant created: ", p1.name)
    p1.set_height(25)
    p1.set_age(30)
    p1.set_height(-5)
    print(f"\nCurrent plant:  {p1.name} ({p1.get_height()}cm,", end=" ")
    print(f"{p1.get_age()} days)")
