'''
Author: panrujiang 3144571429@qq.com
Date: 2023-10-18 20:29:44
LastEditors: panrujiang 3144571429@qq.com
LastEditTime: 2023-10-18 20:33:40
FilePath: \leetcodes\541. 反转字符串 II.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
'''
题目来源：
https://leetcode.cn/problems/reverse-string-ii/description/
解答：
https://www.programmercarl.com/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.html#%E5%85%B6%E4%BB%96%E8%AF%AD%E8%A8%80%E7%89%88%E6%9C%AC
'''
'''
这里不用像C++一样考虑下标的问题，python的切片是可以允许超出范围的
当p2超出范围的时候，s[p2 : ]返回"",s[p : p2]会到最后一个
'''
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        p = 0
        while p < len(s):
            p2 = p + k
            s = s[:p] + s[p : p2][: : -1] + s[p2 : ]
            p = p + 2 * k
        return s