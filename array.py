from build.array import Array

print(dir(Array))

arr = Array(5)
print(arr)

print("\n\n\nBefore Insertion")
arr.display()
arr.insert(1, 2)
arr.insert(0, 5)
arr.insert(2, 10)
arr.insert(3, 1)
arr.insert(4, 3)

print("\n\n\nAfter Insertion")
arr.display()

print("\n\n\nSorting")
arr.bubbleSort()
arr.display()

print("\n\n\nSearching")
arr.binarySearch(5)
arr.binarySearch(18)
