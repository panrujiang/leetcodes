'''
Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
Date: 2023-10-09 23:21:51
LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
LastEditTime: 2023-10-09 23:42:01
FilePath: \test_10_9\shellSort.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import numpy as np

def shellSort(arr):
    gap = int(len(arr)/2)
    while(gap):
        for i in range(gap,2*gap):
            for j in range(i,len(arr),gap):
                key = arr[j]
                k = j -gap
                while(k >= 0 and key < arr[k] ):
                    arr[k + gap] = arr[k]
                    k -= gap
                arr[k + gap] = key
        gap = int(gap/2)
arr = np.random.randint(100,size = 10)
shellSort(arr)
print(arr)