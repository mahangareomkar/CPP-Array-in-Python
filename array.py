import ctypes

MyArray = ctypes.cdll.LoadLibrary('./array.dll')

#Definitions

MyArray.createArraywithSize.argtypes = [ctypes.c_int]
#MyArray.swap = [ctypes.pointer(arr1),ctypes.c_int,ctypes.c_int]

arr1 = MyArray.createArray()

MyArray.display(arr1)

arr2 = MyArray.createArraywithSize(15)

MyArray.display(arr2)

MyArray.swap(arr1,ctypes.c_int(5),ctypes.c_int(5))

MyArray.swap(arr1,5,5)

MyArray.display(arr1)

MyArray.release(arr1)

print(arr1)
