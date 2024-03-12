/*
������Դ��
https://leetcode.cn/problems/reverse-words-in-a-string-iii/description/
���
https://blog.csdn.net/weixin_64904163/article/details/134115458?spm=1001.2014.3001.5502
*/

/*
�ҵĽⷨ��˫ָ�� + �ҿո� 
*/
class Solution {
private:
    void swap(char& a, char& b){
        int temp = a;
            a = b;
            b = temp;
    }
public:
    string reverseWords(string s) {
        vector<int> ans;
        int length = s.size();
        for(int i = 0 ; i < length; i ++){
            if(s[i] == ' '){
                ans.push_back(i);
            }
        }
        ans.push_back(length);
        for(int i = 0 ; i < ans.size(); i ++){
            int l = (i == 0) ? 0 : ans[i -1] + 1, r = ans[i] - 1;
            while(l < r){
                swap(s[l], s[r]);
                l ++;
                r --;
            }
        }
        return s;
    }
};

/*
����� 
*/
class Solution {
public:
    string reverseWords(string s) {
        size_t start = 0;
        size_t pos = s.find(' ');
        while(pos != string::npos){
            reverse(s.begin() + start, s.begin() + pos);
            start = pos + 1;
            pos = s.find(' ', start);
        }
        reverse(s.begin() + start, s.end());
        return s;

    }
};
