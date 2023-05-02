# JFIO - Json Fast Input Output

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
[![Python Version](https://img.shields.io/badge/python-3.6%2B-blue)](https://www.python.org/downloads/)

JFIO is a high-performance Python package for reading and writing JSON files, powered by the popular C++ library [nlohmann/json](https://github.com/nlohmann/json) and [pybind11](https://github.com/pybind/pybind11). This package aims to provide simple and efficient JSON input/output operations while maintaining a user-friendly API.

## Features

- High-performance JSON serialization and deserialization
- Simple and easy-to-use API with just two main functions: `read` and `write`
- Compatible with Python 3.6 and later

## Installation

### Prerequisites

- C++ compiler with support for C++11 or later
- Python 3.6 or later
- [pybind11](https://github.com/pybind/pybind11)

### Install using pip

```bash
pip install JFIO
```

### Build from source

```bash
git clone git@github.com:PabloIbannez/JFIO.git
cd JFIO
python setup.py install 
```
Alternatively:
```bash
git clone git@github.com:PabloIbannez/JFIO.git
cd JFIO
pip install .
```

## Usage

Here is a basic example of how to use JFIO for reading and writing JSON files:

```python
import JFIO

# Writing a JSON file
data = {
    "name": "Alice",
    "age": 30,
    "city": "New York"
}

JFIO.write("output.json", data, formatted=True)

# Reading a JSON file
data_read = JFIO.read("output.json")
print(data_read)
```

## API Reference

### `JFIO.write(filename: str, data, formatted: bool = False)`

Write JSON data to a file.

**Arguments:**

- `filename` (str): The name of the file to write to.
- `data`: The data to write. This can be any data type that is serializable to JSON.
- `formatted` (bool): Write JSON file in a human-readable format. Default: `False`.

### `JFIO.read(filename: str)`

Read JSON data from a file.

**Arguments:**

- `filename` (str): The name of the file to read from.

**Returns:**

- Parsed JSON data as a Python data structure.

## License

This project is licensed under the [MIT License](LICENSE).

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue if you have any questions or suggestions.

## Acknowledgements

- [nlohmann/json](https://github.com/nlohmann/json) for providing the powerful C++ JSON library
- [pybind11](https://github.com/pybind/pybind11) for enabling seamless Python-C++ bindings
- [pybind11_json](https://github.com/pybind/pybind11_json) for simplifying the integration of nlhomann/json with pybind11
