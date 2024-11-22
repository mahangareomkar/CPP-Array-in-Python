#include <iostream>
#include <pybind11/pybind11.h>

namespace py = pybind11;

using namespace std;

class Array
{
    int size;
    int last=0;
    int *arr;

public:
    Array()
    {
        size = 10;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    Array(int s)
    {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    void display()
    {
        cout<<"[";
        for (int i=0;i<last; i++){
            if(i==last-1){
                cout<<arr[i]<<"]"<<endl;
            }else{
                cout <<arr[i]<<",";;
            }
        }
        if(last==0){
            cout<<"]"<<endl;
        }
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

    int binarySearch(int num)
    {
        int l = 0, r = size - 1;
        int mid;
        while (l <= r)
        {
            mid = (l + r) / 2;

            if (num == arr[mid])
            {
                return mid;
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

        return -1;
    }

    void increaseSize(){
        int* newArr = new int[size*2];

        for(int i=0;i<size;i++){
            newArr[i] = arr[i];
        }

        for(int i=size;i<size*2;i++){
            newArr[i] = INT_MAX;
        }

        arr = newArr;
        size *= 2;
    }


    void push(int num){
        if(last==size){
            this->increaseSize();
        }

        arr[last] = num;
        last++;
    }
};

PYBIND11_MODULE(array, m)
{
    py::class_<Array>(m, "Array")
        .def(py::init<>())
        .def(py::init<int>())
        .def("display", &Array::display)
        .def("binarySearch", &Array::binarySearch)
        .def("bubbleSort", &Array::bubbleSort)
        .def("push", &Array::push);
}