def checkdep() -> bool:
    imported = True
    try:
        import pandas as pd
        print(f"[OK] pandas {pd.__version__} - Data manipulation ready")
    except ImportError as e:
        print(e)
        imported = False
    try:
        import numpy as np
        print(f"[OK] numpy {np.__version__} - Numerical computation ready")
    except ImportError as e:
        print(e)
        imported = False
    try:
        import matplotlib as plt
        print(f"[OK] matplotlib {plt.__version__} - Visualization ready")
    except ImportError as e:
        print(e)
        imported = False
    if not imported:
        print("you should use pip install -r requirements.txt or poetry install")
        return False
    return True

if __name__ == "__main__":
    if(checkdep()):
        import pandas as pd
        import numpy as np
        import matplotlib.pyplot as plt
        print("Analyzing Matrix data...")
        print("Processing 1000 data points...")
        data = np.random.normal(0, 1, 1000)
        print("Generating visualization...")
        df = pd.DataFrame(data, columns=["signal"])
        df.plot()
        plt.savefig("matrix_analysis.png")
