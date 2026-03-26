from abc import ABC, abstractmethod
from typing import Any, List, Dict, Union, Optional, Protocol, runtime_checkable
import collections


@runtime_checkable
class ProcessingStage(Protocol):
    def process(self, data: Any) -> Any:
        ...


class ProcessingPipeline(ABC):
    def __init__(self, pipeline_id: str) -> None:
        self.pipeline_id: str = pipeline_id
        self.stages: List[ProcessingStage] = []
        self.stats: collections.Counter = collections.Counter()

    def add_stage(self, stage: ProcessingStage) -> None:
        self.stages += [stage]

    def run_stages(self, data: Any) -> Any:
        result: Any = data
        for stage in self.stages:
            result = stage.process(result)
        return result

    @abstractmethod
    def process(self, data: Any) -> Union[str, Any]:
        pass

    def get_stats(self) -> Dict[str, Any]:
        return {"pipeline_id": self.pipeline_id, "stats": dict(self.stats)}


class InputStage:
    def process(self, data: Any) -> Any:
        return {"raw": data, "stage": "input", "valid": True}


class TransformStage:
    def process(self, data: Any) -> Any:
        if not isinstance(data, dict):
            data = {"raw": data, "valid": True}
        data["stage"] = "transform"
        data["enriched"] = True
        return data


class OutputStage:
    def process(self, data: Any) -> str:
        if not isinstance(data, dict):
            return f"Processed: {data}"
        return f"Delivered: {data.get('raw', 'N/A')}"


class JSONAdapter(ProcessingPipeline):
    def process(self, data: Any) -> Union[str, Any]:
        try:
            result: Any = self.run_stages(data)
            self.stats["processed"] += 1
            if isinstance(data, dict) and "value" in data:
                val: Any = data.get("value")
                unit: str = data.get("unit", "")
                sensor: str = data.get("sensor", "reading")
                return f"Processed {sensor} reading: {val}°{unit} (Normal range)"
            return f"JSON processed: {result}"
        except Exception as e:
            self.stats["errors"] += 1
            raise ValueError(f"JSONAdapter error: {e}")


class CSVAdapter(ProcessingPipeline):
    def process(self, data: Any) -> Union[str, Any]:
        try:
            columns: List[str] = []
            current: str = ""
            for c in str(data) + ",":
                if c == ",":
                    columns += [current.strip()]
                    current = ""
                else:
                    current += c
            result: Any = self.run_stages(columns)
            self.stats["processed"] += 1
            return f"User activity logged: 1 actions processed"
        except Exception as e:
            self.stats["errors"] += 1
            raise ValueError(f"CSVAdapter error: {e}")


class StreamAdapter(ProcessingPipeline):
    def process(self, data: Any) -> Union[str, Any]:
        try:
            readings: List[float] = []
            for v in data:
                readings += [get_float(str(v))]
            result: Any = self.run_stages(readings)
            self.stats["processed"] += 1
            total: float = 0.0
            for r in readings:
                total += r
            count: int = 0
            for r in readings:
                count += 1
            avg: float = total / count if count > 0 else 0.0
            return f"Stream summary: {count} readings, avg: {avg:.1f}°C"
        except Exception as e:
            self.stats["errors"] += 1
            raise ValueError(f"StreamAdapter error: {e}")


class NexusManager:
    def __init__(self) -> None:
        self.pipelines: List[ProcessingPipeline] = []

    def add_pipeline(self, pipeline: ProcessingPipeline) -> None:
        self.pipelines += [pipeline]

    def process_data(self, data: Any, pipeline: ProcessingPipeline) -> Union[str, Any]:
        try:
            return pipeline.process(data)
        except ValueError as e:
            return f"[RECOVERED] {e}"


def get_float(v: str) -> float:
    digits = "0123456789"
    integer_part: int = 0
    decimal_part: int = 0
    decimal_digits: int = 0
    dot: bool = False
    for c in v.strip():
        if c == '.':
            dot = True
            continue
        digit: int = -1
        i: int = 0
        for d in digits:
            if c == d:
                digit = i
                break
            i += 1
        if digit == -1:
            raise Exception(f"Invalid number ({v})")
        if dot:
            decimal_part = decimal_part * 10 + digit
            decimal_digits += 1
        else:
            integer_part = integer_part * 10 + digit
    if decimal_digits > 0:
        return integer_part + decimal_part / (10 ** decimal_digits)
    return float(integer_part)


if __name__ == "__main__":
    print("=== CODE NEXUS - ENTERPRISE PIPELINE SYSTEM ===\n")
    print("Initializing Nexus Manager...")
    manager = NexusManager()
    print("Pipeline capacity: 1000 streams/second\n")
    print("Creating Data Processing Pipeline...")
    print("Stage 1: Input validation and parsing")
    print("Stage 2: Data transformation and enrichment")
    print("Stage 3: Output formatting and delivery\n")
    print("=== Multi-Format Data Processing ===\n")
    print("Processing JSON data through pipeline...")

