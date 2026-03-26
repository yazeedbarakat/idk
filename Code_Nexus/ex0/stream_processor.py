from abc import ABC, abstractmethod
from typing import Any, List, Dict, Union, Optional

class DataProcessor(ABC):
    @abstractmethod
    def process(self, data: Any) -> str:
        pass
    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass
    def format_output(self, result: str) -> str:
        return result

class NumericProcessor(DataProcessor):
    def __init__(self):
        self.total: int = 0
        self.nov: int = 0
        self.avg: int = 0
        self.act: bool = True
    def process(self, data: Any) -> str:
        if self.act:
            print(f"Processing data: {data}")
        if self.validate(data):
            self.avg = self.total / self.nov
            return (self.format_output(f"Validation: Numeric data verified"))
        else:
            return ("Validation: [ERROR] - Numeric data not verified")
    def validate(self, data: Any) -> bool:
        try:
            for i in data:
                self.total += i
                self.nov += 1
            return (True)
        except TypeError:
            return (False)
    def format_output(self, result: str) -> str:
        if self.act:
            print(result)
        return (f"Processed {self.nov} numeric values, sum={self.total}, avg={self.avg}")

class TextProcessor(DataProcessor):
    def __init__(self):
        self.chars: int = 0
        self.words: int = 0
        self.act: bool = True

    def process(self, data: Any) -> str:
        if self.act:
            print(f"Processing data: \"{data}\"")
        if self.validate(data):
            spaces = 0
            for i in data:
                self.chars += 1
                if i == ' ':
                    spaces += 1
            self.words = spaces + 1
            return(self.format_output("Validation: Text data verified"))
        else:
            return("Validation: [ERROR] - Text data not verified")
    def validate(self, data: Any) -> bool:
        try:
            st = ""
            st += data
            return True
        except Exception as e:
            return (False)
    

    def format_output(self, result: str) -> str:
        if self.act:
            print (result)
        return (f"Processed text: {self.chars} characters, {self.words} words")


class LogProcessor(DataProcessor):
    def __init__(self):
        self.logtype : str = ""
        self.message : str = ""
        self.act: bool = True

    def process(self, data: Any) -> str:
        if self.act:
            print(f"Processing data: \"{data}\"")
        if self.validate(data):
            switch = False
            w = False
            for a in data:
                if w:
                    w = False
                    continue
                if a == ':':
                    switch = True
                    w = True
                else:
                    if not switch:
                        self.logtype += a
                    else:
                        self.message += a
            return(self.format_output("Validation: Log entry verified"))
        else:
            return("Validation: [ERROR] - Log entry not verified")

    def validate(self, data: Any) -> bool:
        for a in data:
            if a == ':':
                return (True)
        return (False)

    def format_output(self, result: str) -> str:
        if self.act:
            print(result)
        if self.logtype == 'ERROR':
            return(f"[ALERT] {self.logtype} level detected: {self.message}")
        else:
            return(f"[INFO] {self.logtype} level detected: {self.message}")
        
def Polymorphic_Demo(data : Any):
    for processor in [NumericProcessor(), LogProcessor(), TextProcessor()]:
        ob = processor
        ob.act = False
        result: str = ob.process(data)
        if "ERROR" not in result:
            return result
    return "No suitable processor found"

if __name__ == "__main__":
    print("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===")
    print("\nInitializing Numeric Processor...")
    numeric = NumericProcessor()
    print(f"Output: {numeric.process([1, 2, 3, 4, 5])}")
    print("\nInitializing Text Processor...")
    text = TextProcessor()
    print(f"Output: {text.process("Hello Nexus World")}")
    print("\nInitializing Log Processor...")
    log = LogProcessor()
    print(f"Output: {log.process("ERROR: Connection timeout")}")
    print("\n=== Polymorphic Processing Demo ===")
    print("Processing multiple data types through same interface...")
    print(f"Result 1: {Polymorphic_Demo([1, 2, 3])}")
    print(f"Result 2: {Polymorphic_Demo("Hello world!")}")
    print(f"Result 3: {Polymorphic_Demo("INFO: System ready")}")
    print("\nFoundation systems online. Nexus ready for advanced streams.")
