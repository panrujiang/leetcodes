/*
问题来源：
https://leetcode.cn/problems/valid-parentheses/description/
解答：
https://programmercarl.com/0020.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
*/

/*
括号匹配是使用栈解决的经典问题。我照着卡尔的思路写的 
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.size() % 2){
            return false;
        }
        for(int i =0; i < s.size(); i ++){
            if(s[i] == '(') st.push(')');
            else if(s[i] == '{') st.push('}');
            else if(s[i] == '[') st.push(']');
            //先判断是否是空栈，再判断是否匹配 
            else if(st.empty() || s[i] != st.top()){
                return false;
            }
            else if (s[i] == st.top())
                st.pop();
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};
/*
卡尔的代码 
*/
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false; // 如果s的长度为奇数，一定不符合要求
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
            // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); // st.top() 与 s[i]相等，栈弹出元素
        }
        // 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
        return st.empty();
    }
};


/*
python
*/
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        for item in s:
            if item == '(':
                stack.append(')')
            elif item == '[':
                stack.append(']')
            elif item == '{':
                stack.append('}')
            elif not stack or stack[-1] != item:
                return False
            else: 
                stack.pop()
        return True if not stack else False
            
/*
python,用到了字典 
*/
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {
            '(':')',
            '[':']',
            '{':'}'
        }

        for item in s:
            if item in mapping.keys():
                stack.append(mapping[item])
            elif not stack or stack[-1] != item:
                return False
            else: 
                stack.pop()
        return True if not stack else False
            

