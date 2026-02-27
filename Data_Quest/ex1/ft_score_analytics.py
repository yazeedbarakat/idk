import sys

if __name__ == "__main__":
    try:
        print("=== Player Score Analytics ===")
        argl = len(sys.argv)
        if argl == 1:
            raise ValueError("No scores provided.")
        ls = []
        for i in range(1, argl):
            ls += [int(sys.argv[i])]
        print(f"Scores processed: {ls}")
        print(f"Total players: {argl - 1}")
        print(f"Total score: {sum(ls)}")
        print(f"Average score: {sum(ls)/len(ls)}")
        print(f"High score: {max(ls)}")
        print(f"Low score: {min(ls)}")
        print(f"Score range: {max(ls) - min(ls)}")
    except Exception as e:
        print(f"{e}. Usage: python3 ft_score_analytics.py", end=" ")
        print("<score1> <score2> ...")
