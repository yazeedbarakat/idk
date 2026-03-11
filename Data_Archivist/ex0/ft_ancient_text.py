if __name__ == "__main__":
    print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===")
    print("\nAccessing Storage Vault: ancient_fragment.txt")
    try:
        f = open("ancient_fragment.txt")
        print("Connection established...\n")
        print("RECOVERED DATA:")
        print(f.read())
        f.close()
        print("\nData recovery complete. Storage unit disconnected.")
    except FileNotFoundError:
        print("ERROR Storage vault not found. Run data generator first.")
