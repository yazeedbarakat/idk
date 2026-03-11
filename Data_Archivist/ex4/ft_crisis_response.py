if __name__ == "__main__":
    print("=== CYBER ARCHIVES - CRISIS RESPONSE SYSTEM ===")
    print("\nCRISIS ALERT: Attempting access to ’lost_archive.txt’...")
    try:
        with open("lost_archive.txt", 'r') as f:
            f.read()
    except FileNotFoundError:
        print("RESPONSE: Archive not found in storage matrix")
        print("STATUS: Crisis handled, system stable")
    print("\nCRISIS ALERT: Attempting access to ’classified_vault.txt’...")
    try:
        with open('classified_vault.txt', 'r') as f:
            f.read()
    except PermissionError:
        print("RESPONSE: Security protocols deny access")
        print("STATUS: Crisis handled, security maintained")
    except FileNotFoundError:
        print("RESPONSE: Vault not found")
        print("STATUS: Crisis handled, system stable")
    print("\nROUTINE ACCESS: Attempting access to ’standard_archive.txt’...")
    try:
        with open("standard_archive.txt", 'r') as f:
            print('SUCCESS: Archive recovered - ',
                  '“Knowledge preserved for humanity”')
        print("STATUS: Normal operations resumed")
    except FileNotFoundError:
        print("RESPONSE: Archive not found in storage matrix")
    print("\nAll crisis scenarios handled successfully. Archives secure.")
