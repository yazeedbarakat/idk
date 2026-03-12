import sys


def inventory_statistics(dic: dict) -> None:
    most_key = ""
    most_val = 0
    for a in dic:
        if most_val < dic[a]:
            most_key = a
            most_val = dic[a]
    least_key = ""
    least_val = most_val
    for a in dic:
        if least_val > dic[a]:
            least_key = a
            least_val = dic[a]
    print(f"Most abundant: {most_key} ({most_val} units)")
    print(f"Least abundant: {least_key} ({least_val} unit)")


def get_int(v: str) -> int:
    digits = "0123456789"
    num = 0
    for c in v:
        digit = -1
        i = 0
        for d in digits:
            if c == d:
                digit = i
                break
            i += 1
        if digit == -1:
            raise Exception(f"Invalid number ({v}) the value must be an int")
        num = num * 10 + digit
    return num


def create_dic() -> dict:
    dic = {}
    for arg in sys.argv[1:]:
        key = ""
        val = 0
        i = 0
        for a in arg:
            if a == ':':
                break
            key += a
            i += 1
        for a in arg[i+1:]:
            val = get_int(a)
        dic[key] = val
    return dic


if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    try:
        if len(sys.argv) == 1:
            raise Exception("\nNo values provided. Example usage sword:1"
                            "potion:5 shield:2 armor:3 helmet:1")
        elif ':' not in sys.argv[1]:
            raise Exception("\nNo value for the key")
        inventory = create_dic()
        total = 0
        moderate = {}
        scarce = {}
        restock = []
        keys = []
        values = []
        for a in inventory:
            total += inventory[a]
            keys += [a]
            values += [inventory[a]]
            if a == "sword" or a == "shield" or a == "armor" or a == "helmet":
                scarce[a] = inventory[a]
            else:
                moderate[a] = inventory[a]
            if inventory[a] == 1:
                restock += [a]
        print("Total items in inventory:", total)
        print("Unique item types:", len(inventory))
        print("\n=== Current Inventory ===")
        for a in inventory:
            print(f"{a}: {inventory[a]} units"
                  f"({(inventory[a] / total * 100):.1f}%)")
        print("\n=== Inventory Statistics ===")
        inventory_statistics(inventory)
        print("\n=== Item Categories ===")
        print(f"Moderate: {moderate}")
        print(f"Scarce: {scarce}")
        print("\n=== Management Suggestions ===")
        print(f"• Restock needed: {restock}")
        print("\n=== Dictionary Properties Demo ===")
        print(f"Dictionary keys: {keys}")
        print(f"Dictionary values: {values}")
        print(f"Sample lookup - ’sword’ in inventory: {'sword' in inventory}")
    except Exception as e:
        print(e)
