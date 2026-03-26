from abc import ABC, abstractmethod
from typing import Any, List, Dict, Union, Optional

class DataStream(ABC):
    def __init__(self, stream_id: str):
        self.stream_id: str = stream_id
        self.processed_count: int = 0

    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str:
        pass

    def filter_data(self, data_batch: List[Any],
                    criteria: Optional[str] = None) -> List[Any]:
        if criteria is None:
            return data_batch
        result = []
        for item in data_batch:
            if isinstance(item, str):
                if criteria in item:
                    result += [item]
        return result

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        return {
                "stream_id": self.stream_id,
                "processed_count": self.processed_count
                }



class SensorStream(DataStream):
    def __init__(self, stream_id: str):
        super().__init__(stream_id)
        self.tempsum : float = 0
        self.tempc : int = 0
        self.readingc : int = 0

    def process_batch(self, data_batch: List[Any]) -> str:
        filtered: List[Any] = self.filter_data(data_batch, 'temp')
        for i in data_batch:
            self.readingc += 1
        for item in filtered:
            val: str = ""
            past_colon: bool = False
            for a in item:
                if a == ':':
                    past_colon = True
                    continue
                if past_colon:
                    val += a
            self.tempsum += get_float(val)
            self.tempc += 1
        avg: float = self.tempsum / self.tempc if self.tempc > 0 else 0.0
        return f"Sensor analysis: {self.readingc} readings processed, avg temp: {avg:.1f}°C"

    def filter_data(self, data_batch: List[Any], criteria: Optional[str] = None) -> List[Any]:
        if criteria is None:
            return data_batch
        result: List[Any] = []
        for item in data_batch:
            if isinstance(item, str) and ':' in item:
                key: str = ""
                for a in item:
                    if a == ':':
                        break
                    key += a
                if key == criteria:
                    result +=[item]
        return result

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        base: Dict[str, Union[str, int, float]] = super().get_stats()
        avg: float = self.tempsum / self.tempc if self.tempc > 0 else 0.0
        base["readingc"] = self.readingc
        base["tempc"] = self.tempc
        return base

                        

class TransactionStream(DataStream):
    def __init__(self, stream_id: str):
        super().__init__(stream_id)
        self.opc : int = 0
        self.netflow : int = 0

    def process_batch(self, data_batch: List[Any]) -> str:
        buy : List[Any] = self.filter_data(data_batch, 'buy')
        sell : List[Any] = self.filter_data(data_batch, 'sell')
        for i in buy + sell:
            self.opc += 1
        for item in buy:
            val: str = ""
            past_colon: bool = False
            for a in item:
                if a == ':':
                    past_colon = True
                    continue
                if past_colon:
                    val += a
            self.netflow += get_float(val)
        for item in sell:
            val: str = ""
            past_colon: bool = False
            for a in item:
                if a == ':':
                    past_colon = True
                    continue
                if past_colon:
                    val += a
            self.netflow -= get_float(val)
        sign = "+" if self.netflow >= 0 else ""
        return f"Transaction analysis: {self.opc} operations, net flow: {sign}{self.netflow} units"

    def filter_data(self, data_batch: List[Any], criteria: Optional[str] = None) -> List[Any]:
        if criteria is None:
            return data_batch
        result : List[Any] = []
        for item in data_batch:
            if isinstance(item, str) and ':' in item:
                key: str = ""
                for a in item:
                    if a == ':':
                        break
                    key += a
                if key == criteria:
                    result += [item]
        return result

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        base: Dict[str, Union[str, int, float]] = super().get_stats()
        base["net_flow"] = self.netflow
        return base

class EventStream(DataStream):
    def __init__(self, stream_id):
        super().__init__(stream_id)
        self.eventc : int = 0
        self.errorc : int = 0

    def process_batch(self, data_batch: List[Any]) -> str:
        filtered : List[Any] = self.filter_data(data_batch, 'error')
        for i in filtered:
            self.errorc += 1
        for i in data_batch:
            self.eventc += 1
        return f"Event analysis: {self.eventc} events, {self.errorc} error detected"


    def filter_data(self, data_batch: List[Any], criteria: Optional[str] = None) -> List[Any]:
        if criteria is None:
            return data_batch
        result : List[Any] = []
        for item in data_batch:
            if isinstance(item, str) and item == criteria:
                result += [item]
        return result

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        base: Dict[str, Union[str, int, float]] = super().get_stats()
        base["eventc"] = self.eventc
        base["errorc"] = self.errorc
        return base


def get_float(v: str) -> float:
    digits = "0123456789"
    integer_part: int = 0
    decimal_part: int = 0
    decimal_digits: int = 0
    dot: bool = False
    for c in v:
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
    return integer_part


class StreamProcessor:
    def __init__(self) -> None:
        self.streams: List[DataStream] = []
    
    def add_stream(self, stream: DataStream) -> None:
        self.streams += [stream]

    def process_all(self, batches: List[List[Any]]) -> List[str]:
        results: List[str] = []
        i: int = 0
        for stream in self.streams:
            results += [stream.process_batch(batches[i])]
            i += 1
        return results

if __name__ == "__main__":
    print("=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM ===")
    print("\nInitializing Sensor Stream...")
    print("Stream ID: SENSOR_001, Type: Environmental Data")
    sensor = SensorStream("SENSOR_001")
    print("Processing sensor batch: [temp:22.5, humidity:65, pressure:1013]")
    print(sensor.process_batch(["temp:22.5", "humidity:65", "pressure:1013"]))
    print("\nInitializing Transaction Stream...")
    print("Stream ID: TRANS_001, Type: Financial Data")
    trans = TransactionStream("TRANS_001")
    print("Processing transaction batch: [buy:100, sell:150, buy:75]")
    print(trans.process_batch(["buy:100", "sell:150", "buy:75"]))
    print("\nInitializing Event Stream...")
    print("Stream ID: EVENT_001, Type: System Events")
    event = EventStream("EVENT_001")
    print("Processing event batch: [login, error, logout]")
    print(event.process_batch(["login", "error", "logout"]))
    print("\n=== Polymorphic Stream Processing ===")
    print("Processing mixed stream types through unified interface...")
    s2 = SensorStream("SENSOR_002")
    t2 = TransactionStream("TRANS_002")
    e2 = EventStream("EVENT_002")
    sp: StreamProcessor = StreamProcessor()
    sp.add_stream(s2)
    sp.add_stream(t2)
    sp.add_stream(e2)
    batches: List[List[Any]] = [
        ["temp:35.1", "humidity:80"],
        ["buy:200", "sell:50", "buy:120", "sell:80"],
        ["login", "warning", "error"],
    ]
    results = sp.process_all(batches)
    print("Batch 1 Results:")
    print(f"- Sensor data: {s2.readingc} readings processed")
    print(f"- Transaction data: {t2.opc} operations processed")
    print(f"- Event data: {e2.eventc} events processed")
    print("\nStream filtering active: High-priority data only")
    critical = s2.filter_data(["temp:35.1", "temp:40.2"], 'temp')
    c: int = 0
    for i in critical:
        c += 1
    large = t2.filter_data(["buy:200", "sell:50", "buy:120"], 'buy')
    l : int = 0
    for i in large:
        l += 1
    print(f"Filtered results: {c} critical sensor alerts, {l} large transaction")
    print("\nAll streams processed successfully. Nexus throughput optimal.")
