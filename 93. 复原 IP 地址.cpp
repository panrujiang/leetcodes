/*
题目来源：
https://leetcode.cn/problems/restore-ip-addresses/description/
解答：
https://programmercarl.com/0093.%E5%A4%8D%E5%8E%9FIP%E5%9C%B0%E5%9D%80.html#%E6%80%9D%E8%B7%AF
*/

/*
回溯算法 
*/

class Solution {
private:
    vector<string> result;
    void backtracking(string& s, int startIndex , int pointNum){
        if(pointNum == 3){
            if(isValid(s, startIndex, s.size() - 1)){
                result.push_back(s);
            }
            return ;
        }
        for(int i = startIndex; i < s.size(); i ++){
            if(isValid(s, startIndex, i)){
                s.insert(s.begin() + i + 1,'.');
                pointNum ++;
                backtracking(s, i + 2, pointNum);
                pointNum --;
                s.erase(s.begin() + i + 1);
            }else break;
        }
    }
    bool isValid(const string &s, int start, int end){
        if(start > end){
            return false;
        }
        if(s[start] == '0' && start != end){
            return false;
        }
        int num = 0;
        for(int i = start; i <= end; i ++){
            if(s[i] > '9' || s[i] < '0'){
                return false;
            }
            num = num * 10 + (s[i] - '0');
            {
                if(num > 255){
                    return false;
                }
            }
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if(s.size() < 4 || s.size() >12) return result;
        backtracking(s,0,0);
        return result;
    }
};
