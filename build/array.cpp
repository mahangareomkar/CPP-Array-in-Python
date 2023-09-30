#include <iostream>
#include <pybind11/pybind11.h>

namespace py = pybind11;

using namespace std;

class Array
{
    int size;
    int *arr;

public:
    Array()
    {
        cout << "Array default constructor" << endl;
        size = 10;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    Array(int s)
    {
        cout << "Array Parameterized constructor" << endl;
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    void insert(int index, int num)
    {
        arr[index] = num;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << i + 1 << "] " << arr[i] << endl;
    }

    void bubbleSort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void binarySearch(int num)
    {
        int l = 0, r = size - 1;
        int mid;
        bool found = false;
        while (l <= r)
        {
            mid = (l + r) / 2;

            if (num == arr[mid])
            {
                cout << num << " is at Index " << mid << endl;
                found = true;
                break;
            }
            else if (num < arr[mid])
            {
                r = mid - 1;
            }
            else if (num > arr[mid])
            {
                l = mid + 1;
            }
        }

        if (!found)
        {
            cout << num << " is not in the Array" << endl;
        }
    }
};

PYBIND11_MODULE(array, m)
{
    py::class_<Array>(m, "Array")
        .def(py::init<>())
        .def(py::init<int>())
        .def("insert", &Array::insert)
        .def("display", &Array::display)
        .def("binarySearch", &Array::binarySearch)
        .def("bubbleSort", &Array::bubbleSort);
}