import numpy as np

def insertionSort(arr):
    for i in range(1,len(arr)):
       key = arr[i]
       j = i -1
       while(j >= 0 and key < arr[j] ):
           arr[j + 1] = arr[j]
           j -= 1
    arr[j + 1] = key
    return 0
        

arr = np.random.randint(100,size = 10)
insertionSort(arr)
print(arr)


         
