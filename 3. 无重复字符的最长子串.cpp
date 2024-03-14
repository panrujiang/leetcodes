/*
问题来源：
https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
解答：
https://blog.csdn.net/qq_75270497/article/details/136607537
*/

/*
暴力解法 
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, length = s.size();
        for(int i = 0; i < length; i ++){
            int hash[128] = {0};
            for(int j = i; j < length; j ++){
                hash[s[j]] ++;
                if(hash[s[j]] > 1){
                    break;
                }
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

/*
双指针 
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128] = {0};
        int ans = 0;
        int left = 0, right = 0;
        while(right < s.size()){
            hash[s[right]] ++;
                while(hash[s[right]] > 1){
                    hash[s[left ++]] --;
                }
            ans = max(ans, right - left + 1);
            right ++;
        }
        return ans;
    }
};
