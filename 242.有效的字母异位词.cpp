/*
������Դ��
https://leetcode.cn/problems/valid-anagram/description/
���
https://www.programmercarl.com/0242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
 
*/

/*
���ݿ�����˼·�Ľⷨ����һ�������¼������ĸ�Ĵ�������++,��--����������и���Ԫ�ض���0���򷵻�true 
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        vector<int> ans(26,0);
        for(int i =0; i < s.size();i ++){
            ans[s[i] - 'a'] ++;
            ans[t[i] - 'a'] --;
        }
        for(int i =0; i < 26; i ++){
            if(ans[i]){
                return false;
            }
        }
        return true;
    }
};

