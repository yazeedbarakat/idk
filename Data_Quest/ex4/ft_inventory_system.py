import sys

if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    dic = {}
    total = 0
    for a in sys.argv[1:]:
        arg = a.split(':')
        key = arg[0]
        value = int(arg[1])
        total += value
        dic[key] = value
    print(f"Total items in inventory: {total}")
    print(f"Unique item types: {len(dic)}")
    print(f"\n=== Current Inventory ===")
    for a in dic:
        print(f"{a}: {dic[a]} units ({(dic[a]/total*100):.1f}%)")
    print("\n=== Inventory Statistics ===")
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
    print("\n=== Item Categories ===")
    print(f"Moderate: {dic.get(
