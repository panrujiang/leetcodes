'''
Author: panrujiang 3144571429@qq.com
Date: 2023-10-18 21:24:00
LastEditors: panrujiang 3144571429@qq.com
LastEditTime: 2023-10-18 21:31:48
FilePath: \leetcodes\LCR 122. 路径加密.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
'''
题目来源：
https://leetcode.cn/problems/ti-huan-kong-ge-lcof/description/
解答：
https://leetcode.cn/problems/ti-huan-kong-ge-lcof/solutions/94608/mian-shi-ti-05-ti-huan-kong-ge-ji-jian-qing-xi-tu-/
'''
'''
在 Python 和 Java 等语言中，字符串都被设计成「不可变」的类型，即无法直接修改字符串的某一位字符，需要新建一个字符串实现。
'''
class Solution:
    def pathEncryption(self,path:str) -> str:
        res = []
        for c in path:
            if c == '.':res.append(' ')
            else: res.append(c)
        #以''的形式将res中的元素连接起来
        return ''.join(res)
    
'''
直接替换
'''
class Solution:
    def pathEncryption(self, path: str) -> str:
        #将path中的'.'替换成' '
        return path.replace('.',' ')