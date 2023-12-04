/*
问题来源：
https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
解答：
https://programmercarl.com/0017.%E7%94%B5%E8%AF%9D%E5%8F%B7%E7%A0%81%E7%9A%84%E5%AD%97%E6%AF%8D%E7%BB%84%E5%90%88.html#%E6%80%9D%E8%B7%AF
*/

class Solution {
private:
    const string letterMap[10] = {
        "",//0
        "",//1
        "abc",//2
        "def",//3
        "ghi",//4
        "jkl",//5
        "mno",//6
        "pqrs",//7
        "tuv",//8
        "wxyz",//9
    };
public:
    vector<string> result;
    string s;
    void backtracking(const string& digits, int index){
        if(index == digits.size()){
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for(int i =0; i < letters.size(); i ++){
            s.push_back(letters[i]);
            backtracking(digits,index + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if(digits.size() == 0){
            return result;
        }
        backtracking(digits,0);
        return result;
    }
};



/*
把回溯放在递归函数中 
*/
class Solution {
private:
    const string letterMap[10] = {
        "",//0
        "",//1
        "abc",//2
        "def",//3
        "ghi",//4
        "jkl",//5
        "mno",//6
        "pqrs",//7
        "tuv",//8
        "wxyz",//9
    };
public:
    vector<string> result;
    string s;
    void backtracking(const string& digits, int index, const string& s){
        if(index == digits.size()){
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for(int i =0; i < letters.size(); i ++){
            backtracking(digits,index + 1,s + letters[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if(digits.size() == 0){
            return result;
        }
        backtracking(digits,0,"");
        return result;
    }
};
