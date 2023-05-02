from .write import writeJSON2File
from .read import readJSONFromFile

def write(filename:str, data, formatted:bool=False):
    writeJSON2File.writeJSON2File(filename, data, formatted)

def read(filename:str):
    return readJSONFromFile.readJSONFromFile(filename)
