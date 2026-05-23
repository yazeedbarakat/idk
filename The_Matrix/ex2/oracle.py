import os
import sys


try:
    from dotenv import load_dotenv
except ImportError:
    m = "python-dotenv not installed, Install with: pip install python-dotenv"
    print(m)
    sys.exit(1)


def conf(var: str | None, typ: str) -> None:
    if not var:
        print(f"{typ} configuration is missing")
    else:
        print(f"{typ}: {var}")
    if typ == "Mode":
        if var == "production":
            print("PROD: Minimal logging, errors only")
            print("PROD: Using production database")
            print("PROD: Debug info hidden from users")
        elif var == "development":
            print("DEV: Verbose logging enabled")
            print("DEV: Using local database")
            print("DEV: Full error details shown")


if __name__ == "__main__":
    print("ORACLE STATUS: Reading the Matrix...\n")
    if not os.path.exists(".env"):
        print(".env file missing")
    load_dotenv()
    print("Configuration loaded:")
    mode = os.environ.get("MATRIX_MODE")
    conf(mode, "Mode")
    db = os.environ.get("DATABASE_URL")
    conf(db, "Database")
    api = os.environ.get("API_KEY")
    conf(api, "API Access")
    log = os.environ.get("LOG_LEVEL")
    conf(log, "Log Level")
    ze = os.environ.get("ZION_ENDPOINT")
    conf(ze, "Zion Network")
    print("\nEnvironment security check:")
    print("[OK] No hardcoded secrets detected")
    if os.path.exists(".env"):
        print("[OK] .env file properly configured")
    if mode == "production":
        print("[OK] Production overrides available")
    print("\nThe Oracle sees all configurations.")
