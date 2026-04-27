import sys
import importlib

try:
    import pandas as pd
    import numpy as np
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
except ImportError:
    pass


def import_check(name: str) -> tuple[bool, str | None]:
    try:
        module = importlib.import_module(name)
        return True, getattr(module, "__version__", "unknown")
    except ImportError:
        return False, None


def print_install_instructions() -> None:
    print("\nSome dependencies are missing. Install them with:")
    print("  pip:    pip install -r requirements.txt")
    print("  Poetry: poetry install")


def analyze() -> None:
    print("Processing 1000 data points...")
    np.random.seed(42)
    data = np.random.randn(1000)
    df = pd.DataFrame({"value": data})
    df["cumulative"] = df["value"].cumsum()
    print(f"Mean: {df['value'].mean():.4f}")
    print(f"Std:  {df['value'].std():.4f}")
    print("Generating visualization...")
    fig, ax = plt.subplots(figsize=(10, 6))
    ax.plot(df.index, df["value"], alpha=0.5, label="Raw data")
    ax.plot(df.index, df["cumulative"], color="green", label="Cumulative")
    ax.set_title("Matrix Data Analysis")
    ax.set_xlabel("Sample")
    ax.set_ylabel("Value")
    ax.legend()
    ax.grid(True, alpha=0.3)
    fig.savefig("matrix_analysis.png", dpi=100, bbox_inches="tight")
    plt.close(fig)
    print("\nAnalysis complete!")
    print("Results saved to: matrix_analysis.png")


def main() -> None:
    print("LOADING STATUS: Loading programs...\n")
    print("Checking dependencies:")
    modules = [
        ("pandas", "Data manipulation"),
        ("numpy", "Numerical computation"),
        ("requests", "Network access"),
        ("matplotlib", "Visualization")
    ]

    all_ok = True
    for name, desc in modules:
        ok, version = import_check(name)
        if ok:
            print(f"[OK] {name} ({version}) - {desc} ready")
        else:
            print(f"[MISSING] {name} - {desc} unavailable")
            all_ok = False

    if not all_ok:
        print_install_instructions()
        sys.exit(1)

    print("\nAnalyzing Matrix data...")
    analyze()


if __name__ == "__main__":
    main()
