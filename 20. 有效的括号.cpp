/*
������Դ��
https://leetcode.cn/problems/valid-parentheses/description/
���
https://programmercarl.com/0020.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
*/

/*
����ƥ����ʹ��ջ����ľ������⡣�����ſ�����˼·д�� 
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
            //���ж��Ƿ��ǿ�ջ�����ж��Ƿ�ƥ�� 
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
�����Ĵ��� 
*/
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false; // ���s�ĳ���Ϊ������һ��������Ҫ��
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // ����������������ַ���ƥ��Ĺ����У�ջ�Ѿ�Ϊ���ˣ�û��ƥ����ַ��ˣ�˵��������û���ҵ���Ӧ�������� return false
            // �ڶ�������������ַ���ƥ��Ĺ����У�����ջ��û������Ҫƥ����ַ�������return false
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); // st.top() �� s[i]��ȣ�ջ����Ԫ��
        }
        // ��һ���������ʱ�����Ѿ����������ַ���������ջ��Ϊ�գ�˵������Ӧ��������û����������ƥ�䣬����return false�������return true
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
python,�õ����ֵ� 
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
            

