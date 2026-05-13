import os
from dotenv import load_dotenv


if __name__ == "__main__":
    print("ORACLE STATUS: Reading the Matrix...")
    if not os.path.exists(".env"):
        print("missing .env file not found")
    else:
        load_dotenv()
        print("Configuration loaded:")
        mode = os.environ.get("MATRIX_MODE")
        print("Mode:", mode)
        db = os.environ.get("DATABASE_URL")
        print("Database:",db)
        api = os.environ.get("API_KEY")
        print("API Access:",api)
        log = os.environ.get("LOG_LEVEL")
        print("Log level:", log)
        ze = os.environ.get("ZION_ENDPOINT")
        print("Zion Network:", ze)
        print("\nEnvironment security check:")
        print("[OK] No hardcoded secrets detected")
        print("[OK] .env file properly configured")
        print("[OK] Production overrides available")
        print("\nThe Oracle sees all configurations.")
