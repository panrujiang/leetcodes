/*
题目来源：
https://leetcode.cn/problems/percentage-of-letter-in-string/description/
解答：
https://www.bilibili.com/video/BV1nt4y1b7pw/?spm_id_from=333.999.0.0&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int count = 0;
        for(int i = 0; i < s.size(); i ++ ){
            if(s[i] == letter){
                count ++;
            }
        }
        return 100 * count/s.size();
    }
};
