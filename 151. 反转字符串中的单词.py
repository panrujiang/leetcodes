'''
Author: panrujiang 3144571429@qq.com
Date: 2023-10-19 17:09:08
LastEditors: panrujiang 3144571429@qq.com
LastEditTime: 2023-10-19 17:16:53
FilePath: \leetcodes\151. 反转字符串中的单词.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
'''
题目来源：
https://leetcode.cn/problems/reverse-words-in-a-string/description/
解答：
https://programmercarl.com/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.html#%E6%80%9D%E8%B7%AF
https://leetcode.cn/problems/reverse-words-in-a-string/solutions/194450/fan-zhuan-zi-fu-chuan-li-de-dan-ci-by-leetcode-sol/
'''
'''
先将单词分割出来，再将多个单词的顺序反转（单词本身不反转），然后再将这些元素以“ ”的形式连接起来
'''
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(reversed(s.split()))

'''
'''
class Solution:
    def reverseWords(self, s: str) -> str:
        # 删除前后空白
        s = s.strip()
        # 反转整个字符串
        s = s[::-1]
        # 将字符串拆分为单词，并反转每个单词
        s = ' '.join(word[::-1] for word in s.split())
        return s

class Solution:
    def reverseWords(self, s: str) -> str:
        # 将字符串拆分为单词，即转换成列表类型
        words = s.split()

        # 反转单词
        left, right = 0, len(words) - 1
        while left < right:
            words[left], words[right] = words[right], words[left]
            left += 1
            right -= 1

        # 将列表转换成字符串
        return " ".join(words)


