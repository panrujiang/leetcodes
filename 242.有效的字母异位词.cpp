/*
问题来源：
https://leetcode.cn/problems/valid-anagram/description/
解答：
https://www.programmercarl.com/0242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
 
*/

/*
根据卡尔的思路的解法，用一个数组记录出现字母的次数，先++,再--，如果数组中各个元素都是0，则返回true 
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

