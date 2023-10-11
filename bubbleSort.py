'''
Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
Date: 2023-10-09 17:53:58
LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
LastEditTime: 2023-10-09 19:20:08
FilePath: \test_10_9\test_01.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import numpy as np
import time
import math

def bubbleSort(arr):
    n = len(arr)
    for i in range(n -1):
        flag = 0  #如果在一次遍历中，数组元素无交换，冒泡排序就完成了
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j],arr[j + 1] = arr[j + 1],arr[j]
                flag = 1
        if flag == 0:
            break
arr = np.random.randint(100,size = 10)
bubbleSort(arr)
print("完成冒泡排序 ")
print(arr)
        