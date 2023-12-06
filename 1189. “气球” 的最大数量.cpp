/*
题目来源：
https://leetcode.cn/problems/maximum-number-of-balloons/description/
解答：
https://leetcode.cn/problems/maximum-number-of-balloons/solutions/1261928/gong-shui-san-xie-jian-dan-mo-ni-ti-by-a-9px4/
*/

/*
switch语句要会用，break一定不要忘了 
*/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans[5] = {0};
        for(int i = 0; i < text.size(); i ++){
            switch (text[i]){
                case 'a': ans[0] ++;break;
                case 'b': ans[1] ++;break;
                case 'l': ans[2] ++;break;
                case 'o': ans[3] ++;break;
                case 'n': ans[4] ++;break;
            }
        }

                ans[2] /= 2;
                ans[3] /= 2;
        int min = ans[0];
        for(int i = 1; i < 5; i ++){
            min = min < ans[i] ? min : ans[i];
        }
        return min;
        }
};

/*
我的办法 
*/
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int nums[26] = {0};
        int count = INT_MAX;
        for(int i =0; i < text.size(); i ++){
            nums[text[i] - 'a'] ++;
        }
        for(int i = 0; i < 26; i ++){
            if(i == 'b' - 'a' || i == 0 ||i == 'l' - 'a' || i == 'o' - 'a' || i == 'n' - 'a'){
                if(i == 'l' - 'a' || i == 'o' - 'a'){
                    count = count < nums[i] /2 ? count : nums[i]/2;
                }else{
                    count = count < nums[i] ? count : nums[i];
                }
            }
        }
    return count;
    }
};
