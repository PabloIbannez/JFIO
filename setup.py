from setuptools import setup, find_packages, Extension
from setuptools.command.build_ext import build_ext
import pybind11

###########################

ext_modules = [
    Extension(
        'JFIO.write.writeJSON2File',
        sources=['JFIO/write/writeJSON2File.cpp'],
        include_dirs=[pybind11.get_include()],
        extra_compile_args=['-std=c++11','-O3'],
        language='c++'
    ),
    Extension(
        'JFIO.read.readJSONFromFile',
        sources=['JFIO/read/readJSONFromFile.cpp'],
        include_dirs=[pybind11.get_include()],
        extra_compile_args=['-std=c++11','-O3'],
        language='c++'
    ),
]

setup(
    packages=find_packages(),
    ext_modules=ext_modules,
    cmdclass={'build_ext': build_ext},
    url="https://github.com/PabloIbannez/JFIO",
)
