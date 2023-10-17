/*
题目来源：
https://leetcode.cn/problems/check-if-the-sentence-is-pangram/description/ 
*/
/*
用一个数组来记录出现字母的次数，用变量differ来记录还未出现过的字母，当这个字母第一次出现的时候，differ--,最后判断differ是否等于0 
*/
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int differ = 26;
        int a[26] = {0};
        for(int i =0; i < sentence.size(); i ++){
            if(a[sentence[i] - 'a'] == 0){
                differ --;
            }
            a[sentence[i] - 'a'] ++;
        }
        if(differ == 0){
            return true;
        }
        return false;
    }
};
