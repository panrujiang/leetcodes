/*
��Ŀ��Դ��
https://leetcode.cn/problems/repeated-substring-pattern/description/
���
https://programmercarl.com/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.html#%E6%80%9D%E8%B7%AF
*/
/*
�ƶ�ƥ�� 
*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string  t = s + s;
        t.erase(t.begin());
        t.erase(t.end() - 1);
        if(t.find(s) != std::string::npos){
            return true;
        }
        return false;
    }
};
/*
��һ�����в����Ƿ���ֹ���һ����������KMP�Ŀ��ұ��졣
*/
class Solution {
public:
    void getNext(int* next,const string& s){
        next[0] = 0;
        int j = 0;
        for(int i = 1; i < s.size(); i ++){
            while(j > 0 && s[i] != s[j]){
                j = next[j - 1];
            }
            if(s[j] == s[i]){
                j ++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 0){
            return false;
        }
        int next[s.size()];
        getNext(next,s);
        int len = s.size();
        if(next[len - 1] != 0 && len % (len - (next[len - 1])) == 0){
            return true;
        }
            return false;
    }
};
