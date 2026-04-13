from typing import Any
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self) -> None:
        self.queue: list[str] = []
        self.total: int = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        i = self.queue.pop(0)
        n = self.total - len(self.queue) - 1
        return (n, i)


class NumericProcessor(DataProcessor):
    def __init__(self) -> None:
        self.queue: list[str] = []
        self.total: int = 0

    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)):
            return True
        elif isinstance(data, list):
            return all(isinstance(i, (int, float)) for i in data)
        else:
            return False

    def ingest(self, data: Any) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        if isinstance(data, list):
            for i in data:
                self.queue.append(str(i))
                self.total += 1
        else:
            self.queue.append(str(data))
            self.total += 1


class TextProcessor(DataProcessor):
    def __init__(self) -> None:
        self.queue: list[str] = []
        self.total: int = 0

    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        elif isinstance(data, list):
            return all(isinstance(i, str) for i in data)
        else:
            return False

    def ingest(self, data: Any) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        if isinstance(data, list):
            for i in data:
                self.queue.append(i)
                self.total += 1
        else:
            self.queue.append(data)
            self.total += 1


class LogProcessor(DataProcessor):
    def __init__(self) -> None:
        self.queue: list[str] = []
        self.total: int = 0

    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            return all(isinstance(k, str) and isinstance(v, str)
                       for k, v in data.items())
        elif isinstance(data, list):
            return all(isinstance(d, dict) and
                       all(isinstance(k, str) and isinstance(v, str) for k, v
                           in d.items()) for d in data)
        else:
            return False

    def ingest(self, data: Any) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")
        if isinstance(data, list):
            for d in data:
                self.queue.append(f"{d['log_level']}: {d['log_message']}")
                self.total += 1
        else:
            self.queue.append(f"{data['log_level']}: {data['log_message']}")
            self.total += 1


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===")
    print("\nTesting Numeric Processor...")
    numeric = NumericProcessor()
    print(f"Trying to validate input '42': {numeric.validate(42)}")
    print(f"Trying to validate input 'Hello': {numeric.validate('Hello')}")
    try:
        print("Test invalid ingestion of string",
              "'foo' without prior validation:")
        numeric.ingest("foo")
    except ValueError as e:
        print(f"Got exception: {e}")
    numeric.ingest([1, 2, 3, 4, 5])
    print("Processing data: [1, 2, 3, 4, 5]")
    print("Extracting 3 values...")
    for i in range(3):
        rank, val = numeric.output()
        print(f"Numeric value {rank}: {val}")
    print("\nTesting Text Processor...")
    text = TextProcessor()
    print(f"Trying to validate input '42': {text.validate(42)}")
    text.ingest(['Hello', 'Nexus', 'World'])
    print("Processing data: ['Hello', 'Nexus', 'World']")
    print("Extracting 1 value...")
    rank, val = text.output()
    print(f"Text value {rank}: {val}")
    print("\nTesting Log Processor...")
    log = LogProcessor()
    print(f"Trying to validate input 'Hello': {log.validate('Hello')}")
    logs = [
        {'log_level': 'NOTICE', 'log_message': 'Connection to server'},
        {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}
    ]
    log.ingest(logs)
    print(f"Processing data: {logs}")
    print("Extracting 2 values...")
    for i in range(2):
        rank, val = log.output()
        print(f"Log entry {rank}: {val}")
