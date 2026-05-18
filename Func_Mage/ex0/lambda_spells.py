def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    return sorted(artifacts, key=lambda x: x['power'], reverse=True)


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    return list(filter(lambda x: x['power'] >= min_power, mages))


def spell_transformer(spells: list[str]) -> list[str]:
    return list(map(lambda x: '* ' + x + ' *', spells))


def mage_stats(mages: list[dict]) -> dict:
    avg = round(sum(map(lambda x: x['power'], mages))/len(mages), 2)
    most = max(mages, key=lambda x: x['power'])['power']
    least = min(mages, key=lambda x: x['power'])['power']
    return {'max_power': most, 'min_power': least, 'avg_power': avg}


def main() -> None:
    print("Testing artifact sorter...")
    ex = [
            {'name': 'ahmad', 'power': 10, 'type': 'a'},
            {'name': 'ali', 'power': 30, 'type': 'b'},
            {'name': 'yazeed', 'power': 20, 'type': 'c'},
            {'name': 'omar', 'power': 5, 'type': 'd'}
            ]
    print(*list(map(lambda x: x['power'], artifact_sorter(ex))),
          sep=" comes before ")
    print()
    print("Testing power filter...")
    ex = [
            {'name': 'ahmad', 'power': 10, 'element': 'a'},
            {'name': 'ali', 'power': 30, 'element': 'b'},
            {'name': 'yazeed', 'power': 20, 'element': 'c'},
            {'name': 'omar', 'power': 5, 'element': 'd'}
            ]
    print(*list(map(lambda x: x['power'], power_filter(ex, 20))), sep=" :: ")
    print()
    print("Testing spell transformer...")
    s = ['what', 'is', 'that']
    print(*spell_transformer(s))
    print()
    print("Testing mage stats...")
    print(mage_stats(ex))


if __name__ == "__main__":
    main()
