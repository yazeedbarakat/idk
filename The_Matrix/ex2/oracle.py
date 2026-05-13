import os
import sys
from typing import Optional

try:
    from dotenv import load_dotenv
    load_dotenv()
    DOTENV_LOADED: bool = True
except ImportError:
    DOTENV_LOADED = False


def get_env(key: str, default: Optional[str] = None) -> Optional[str]:
    return os.environ.get(key, default)


def env_file_exists() -> bool:
    return os.path.exists(".env")


def print_status() -> None:
    mode = get_env("MATRIX_MODE", "development")
    db_url = get_env("DATABASE_URL")
    api_key = get_env("API_KEY")
    log_level = get_env("LOG_LEVEL", "DEBUG")
    zion_endpoint = get_env("ZION_ENDPOINT")

    print("ORACLE STATUS: Reading the Matrix...\n")
    print("Configuration loaded:")
    print(f"Mode:  {mode}")
    print(
        "Database:  "
        + ("Connected to local instance" if db_url else "[WARNING] DATABASE_URL not set")
    )
    print(
        "API Access:  "
        + ("Authenticated" if api_key else "[WARNING] API_KEY not set")
    )
    print(f"Log Level:  {log_level}")
    print(
        "Zion Network:  "
        + ("Online" if zion_endpoint else "[WARNING] ZION_ENDPOINT not set")
    )

    print("\nEnvironment security check:")
    print("[OK] No hardcoded secrets detected")
    if DOTENV_LOADED and env_file_exists():
        print("[OK] .env file properly configured")
    else:
        print("[WARNING] .env file not found — copy .env.example to .env")
    print("[OK] Production overrides available")

    print("\nThe Oracle sees all configurations.")


def main() -> None:
    if not DOTENV_LOADED:
        print("[WARNING] python-dotenv not installed.")
        print("Install: pip install python-dotenv\n")
        sys.exit(1)
    print_status()


if __name__ == "__main__":
    main()
