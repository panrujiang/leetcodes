'''
Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
Date: 2023-10-09 21:55:47
LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
LastEditTime: 2023-10-09 22:47:13
FilePath: \test_10_9\1.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import numpy as np

def insertionSort(arr):
    for i in range(1,len(arr)):
        for j in range(i,0,-1):
            if arr[j -1] > arr[j]:
                arr[j],arr[j -1] = arr[j - 1],arr[j]
    return 0

arr = np.random.randint(100,size = 10)
insertionSort(arr)
print(arr)
