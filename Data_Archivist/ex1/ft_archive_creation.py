if __name__ == "__main__":
    print("=== CYBER ARCHIVES - PRESERVATION SYSTEM ===")
    print("\nInitializing new storage unit: new_discovery.txt")
    f = open('new_discovery.txt', 'w')
    print("Storage unit created successfully...")
    print("\nInscribing preservation data...")
    f.write("[ENTRY 001] New quantum algorithm discovered\n" \
            "[ENTRY 002] Efficiency increased by 347%\n" \
            "[ENTRY 003] Archived by Data Archivist trainee")
    print("[ENTRY 001] New quantum algorithm discovered\n" \
            "[ENTRY 002] Efficiency increased by 347%\n" \
            "[ENTRY 003] Archived by Data Archivist trainee")
    f.close()
    print("\nData inscription complete. Storage unit sealed.")
    print("Archive ’new_discovery.txt’ ready for long-term preservation.")
