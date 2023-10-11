'''
Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
Date: 2023-10-09 21:09:00
LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
LastEditTime: 2023-10-09 21:18:45
FilePath: \test_10_9\test_02.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import numpy as np
def selectSort(arr):
    for i in range(len(arr) - 1):
        min = i
        for j in range(i+1,len(arr)):
            if(arr[min] > arr[j]):
                min = j
        arr[i],arr[min] = arr[min],arr[i]
arr = np.random.randint(100,size = 6)
selectSort(arr)
print(arr)
