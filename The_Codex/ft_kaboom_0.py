import alchemy.grimoire

if __name__ == "__main__":
    print("=== Kaboom 0 ===")
    print("Using grimoire module directly")
    record = alchemy.grimoire.light_spell_record
    print("Testing record light spell:",
          record("Fantasy", "Earth, wind and fire"))
