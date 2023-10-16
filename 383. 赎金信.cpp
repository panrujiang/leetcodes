/*
问题来源：
https://leetcode.cn/problems/ransom-note/description/
解法：
https://programmercarl.com/0383.%E8%B5%8E%E9%87%91%E4%BF%A1.html#%E6%80%9D%E8%B7%AF
 
*/

/*
解法基本都是哈希表，而且是数组的方式，我这里用need数组记录ransomNote所需的字母个数 
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
            int need[26] = {0};
            for(int i =0; i < ransomNote.size(); i ++){
                need[ransomNote[i] - 'a'] ++;
            }
            for(int i = 0; i < magazine.size(); i ++){
                need[magazine[i] - 'a'] --;
            }
            for(int i =0; i < 26; i ++){
                if(need[i] > 0){
                    return false;
                }
            }
            return true;
    }
};
/*
卡尔解法，用record数组记录magazine所能提供的字母个数 
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        //add
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        for (int i = 0; i < magazine.length(); i++) {
            // 通过record数据记录 magazine里各个字符出现次数
            record[magazine[i]-'a'] ++;
        }
        for (int j = 0; j < ransomNote.length(); j++) {
            // 遍历ransomNote，在record里对应的字符个数做--操作
            record[ransomNote[j]-'a']--;
            // 如果小于零说明ransomNote里出现的字符，magazine没有
            if(record[ransomNote[j]-'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
