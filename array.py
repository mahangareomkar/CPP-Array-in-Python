from build.array import Array

print(dir(Array))

arr = Array(5)
print(arr)

print("\n\n\nBefore Insertion")
arr.display()

arr.push(10)
arr.push(20)
arr.push(30)
arr.push(40)
arr.push(50)
arr.push(60)
arr.push(70)

print("\n\n\nAfter Push Operations")
arr.display()

print("\n\n\nSorting")
arr.bubbleSort()
arr.display()

print("\n\n\nSearching")
print(arr.binarySearch(30))
print(arr.binarySearch(18))
