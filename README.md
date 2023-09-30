# C++ Array in Python
C++ Array in Python is a program which executes Array Operations developed in C++ in Python

## Packages installation
```
pip install -r requirements.txt
```

## Conversion of CPP file to DLL (Dynamic Link Library)
```
cd build
c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --include) source_filename.cpp -o output_filename$(python3-config --extension-suffix)
```