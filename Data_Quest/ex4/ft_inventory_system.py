import sys

if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    dic = {}
    for a in sys.argv[1:]:
        arg = a.split(':')
        key = arg[0]
        value = int(arg[1])
        dic[key] = value
        total = 0
        for a in dic:
            total += dic[a]
    print(f"Total items in inventory: {total}")
    print(f"Unique item types: {len(dic)}")
    print(f"\n=== Current Inventory ===")
    for a in dic:
        print(f"{a}: {dic[a]} units ({(dic[a]/total*100):.1f}%)")
    print("\n=== Inventory Statistics ===")
