if __name__ == "__main__":
    print("=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===\n")
    print("Initiating secure vault access...")
    try:
        with open("classified_data.txt", 'r') as f:
            print("Vault connection established with failsafe protocols\n")
            print(f"SECURE EXTRACTION:\n{f.read()}")
        with open("security_protocols.txt", 'w') as f:
            print(f"SECURE PRESERVATION:\n[CLASSIFIED] New security protocols archived")
            f.write("[CLASSIFIED] New security protocols archived")
        print("Vault automatically sealed upon completion\n")
        print("All vault operations completed with maximum security.")
    except FileNotFoundError:
        print("ERROR: Vault not found. Run data generator first.")
