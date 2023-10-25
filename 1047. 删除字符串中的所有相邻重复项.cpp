/*
������Դ��
https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
���
https://programmercarl.com/1047.%E5%88%A0%E9%99%A4%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%89%80%E6%9C%89%E7%9B%B8%E9%82%BB%E9%87%8D%E5%A4%8D%E9%A1%B9.html#%E6%80%9D%E8%B7%AF
*/

/*
ƥ�����ⶼ��ջ��ǿ�����漰������ν�ջ�е�Ԫ��ת�����Ϊ�ַ��� 
*/
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        //�������������� 
        for(char c : s){
            if(st.empty() || c != st.top()){
                st.push(c);
            }else{
                st.pop();
            }
        }
        //ջ-->>�ַ��� 
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
�������ַ���ֱ����Ϊջ������ʡȥ��ջ��ҪתΪ�ַ����Ĳ�����
*/
class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for(char c : s){
            if(result.empty() || result.back() != c){//�ַ�����ĩβԪ��:result.back() 
                result.push_back(c);//�ַ���ĩβ���Ԫ�� 
            }else{
                result.pop_back();//�ַ���ĩβɾ��Ԫ�� 
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
