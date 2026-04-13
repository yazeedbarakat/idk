from typing import Protocol , Any
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self) -> None:
        self.queue: list[str] = []
        self.total: int = 0
        self.name: str = ""

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
        self.name: str = "Numeric Processor"

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
        self.name: str = "Text Processor"

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
        self.name: str = "Log Processor"

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


class ExportPlugin(Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


class DataStream():
    def __init__(self) -> None:
        self.processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self.processors += [proc]

    def process_stream(self, stream: list[Any]) -> None:
        for i in stream:
            h = False
            for j in self.processors:
                if j.validate(i):
                    j.ingest(i)
                    h = True
                    break
            if not h:
                print(f"DataStream error - Can't process element in stream: {i}")

    def print_processors_stats(self) -> None:
        if not self.processors:
            print("No processor found, no data")
            return
        for proc in self.processors:
            name = proc.name
            remaining = len(proc.queue)
            print(f"{name}: total {proc.total} items processed, "
                  f"remaining {remaining} on processor")

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for i in self.processors:
            l: list[tuple[int, str]] = []
            for j in range(min(nb, len(i.queue))):
                l.append(i.output())
            if l:
                plugin.process_output(l)


class CSVExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("CSV Output:")
        print(",".join(val for i, val in data))


class JSONExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        print("JSON Output:")
        print("{" + ", ".join(f'"item_{i}": "{v}"' for i, v in data) + "}")


if __name__ == "__main__":
    print("=== Code Nexus - Data Pipeline ===\n")
    stream = DataStream()
    print("Initialize Data Stream...")
    print("== DataStream statistics ==")
    stream.print_processors_stats()
    print("\nRegistering Processors")
    stream.register_processor(NumericProcessor())
    stream.register_processor(TextProcessor())
    stream.register_processor(LogProcessor())
    batch1 = ['Hello world', [3.14, -1, 2.71],
              [{'log_level': 'WARNING', 'log_message': 'Telnet access! Use ssh instead'},
               {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
              42, ['Hi', 'five']]
    print(f"\nSend first batch of data on stream: {batch1}")
    stream.process_stream(batch1)
    print("== DataStream statistics ==")
    stream.print_processors_stats()
    print("\nSend 3 processed data from each processor to a CSV plugin:")
    stream.output_pipeline(3, CSVExportPlugin())
    print("== DataStream statistics ==")
    stream.print_processors_stats()
    batch2 = [21, ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
              [{'log_level': 'ERROR', 'log_message': '500 server crash'},
               {'log_level': 'NOTICE', 'log_message': 'Certificate expires in 10 days'}],
              [32, 42, 64, 84, 128, 168], 'World hello']
    print(f"\nSend another batch of data: {batch2}")
    stream.process_stream(batch2)
    print("== DataStream statistics ==")
    stream.print_processors_stats()
    print("\nSend 5 processed data from each processor to a JSON plugin:")
    stream.output_pipeline(5, JSONExportPlugin())
    print("== DataStream statistics ==")
    stream.print_processors_stats()
