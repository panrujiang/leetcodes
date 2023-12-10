/*
题目来源：
https://leetcode.cn/problems/palindrome-partitioning/description/
解答：
https://programmercarl.com/0131.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2.html#%E6%80%9D%E8%B7%AF
*/

/*
回溯法 
*/
class Solution {
private:
    vector<string> path;
    vector<vector<string>> result;
    void backtracking(string s, int startIndex){
        if(startIndex == s.size()){
            result.push_back(path);
            return ;
        }
        for(int i = startIndex; i < s.size(); i ++){
            if(isPalindrome(s, startIndex, i)){
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }else{
                continue;
            }
            backtracking(s,i + 1);
            path.pop_back();
        }
    }
    bool isPalindrome(const string& s, int start, int end){
        int left = start, right = end;
        while(left <= right){
            if(s[left] != s[right]){
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        path.clear();
        result.clear();
        backtracking(s,0);
        return result;
    }
};


/*
用查询的方法判断是否是回文 
*/
class Solution {
private:
    vector<string> path;
    vector<vector<string>> result;
    vector<vector<bool>> isPalindrome;
    void backtracking(string s, int startIndex){
        if(startIndex == s.size()){
            result.push_back(path);
            return ;
        }
        for(int i = startIndex; i < s.size(); i ++){
            if(isPalindrome[startIndex][i]){
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }else{
                continue;
            }
            backtracking(s,i + 1);
            path.pop_back();
        }
    }
    void computePalindrome(const string& s){
        isPalindrome.resize(s.size(), vector<bool>(s.size(), false));
        for(int i = s.size() - 1; i >=0; i --){
            for(int j = i; j < s.size(); j ++){
                if(j == i) {
                    isPalindrome[i][j] = true;
                }else if(j - i == 1){
                    isPalindrome[i][j] = (s[j] == s[i]);
                }else{
                    isPalindrome[i][j] = (s[j] == s[i] && isPalindrome[i + 1][ j - 1]);
                }
            }
        }
        
    }
public:
    vector<vector<string>> partition(string s) {
        path.clear();
        result.clear();
        computePalindrome(s);
        backtracking(s,0);
        return result;
    }
};
