import sys

if __name__ == "__main__":
    sys.stdout.write("=== CYBER ARCHIVES - COMMUNICATION SYSTEM ===\n")
    sys.stdout.write("\nInput Stream active. Enter archivist ID: ")
    sys.stdout.flush()
    archivist_ID = input()
    sys.stdout.write("Input Stream active. Enter status report: ")
    sys.stdout.flush()
    status_report = input()
    sys.stdout.write("\n[STANDARD] Archive status ")
    sys.stdout.write(f"from {archivist_ID}: {status_report}")
    sys.stdout.flush()
    sys.stderr.write("\n[ALERT] System diagnostic: ")
    sys.stderr.write("Communication channels verified")
    sys.stderr.flush()
    sys.stdout.write("\n[STANDARD] Data transmission complete")
    sys.stdout.write("\n\nThree-channel communication test successful.\n")
