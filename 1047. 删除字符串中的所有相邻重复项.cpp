/*
问题来源：
https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
解答：
https://programmercarl.com/1047.%E5%88%A0%E9%99%A4%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%89%80%E6%9C%89%E7%9B%B8%E9%82%BB%E9%87%8D%E5%A4%8D%E9%A1%B9.html#%E6%80%9D%E8%B7%AF
*/

/*
匹配问题都是栈的强项，最后涉及到了如何将栈中的元素转化输出为字符串 
*/
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        //遍历，迭代对象 
        for(char c : s){
            if(st.empty() || c != st.top()){
                st.push(c);
            }else{
                st.pop();
            }
        }
        //栈-->>字符串 
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
/*
可以拿字符串直接作为栈，这样省去了栈还要转为字符串的操作。
*/
class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for(char c : s){
            if(result.empty() || result.back() != c){//字符串的末尾元素:result.back() 
                result.push_back(c);//字符串末尾添加元素 
            }else{
                result.pop_back();//字符串末尾删减元素 
            }
        }
        return result;
    }
};

/*
python 
*/
class Solution:
    def removeDuplicates(self, s: str) -> str:
        res = list()
        for item in s:
            if res and res[-1] == item:
                res.pop()
            else:
                res.append(item)
        return "".join(res)
