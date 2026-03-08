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
            val = val * 10 + ord(a) - ord('0')
        dic[key] = val
    return dic

if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
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
    print("Total items in inventory:",total)
    print("Unique item types:", len(inventory))
    print("\n=== Current Inventory ===")
    for a in inventory:
        print(f"{a}: {inventory[a]} units ({(inventory[a] / total * 100):.1f}%)")
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
