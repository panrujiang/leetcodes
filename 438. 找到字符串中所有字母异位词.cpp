/*
题目来源：
https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
解答：
https://leetcode.cn/problems/find-all-anagrams-in-a-string/solutions/9749/hua-dong-chuang-kou-tong-yong-si-xiang-jie-jue-zi-/ 
https://leetcode.cn/problems/find-all-anagrams-in-a-string/solutions/1125936/gong-shui-san-xie-shuang-zhi-zhen-shi-xi-t5hc/
https://leetcode.cn/problems/find-all-anagrams-in-a-string/solutions/1123971/zhao-dao-zi-fu-chuan-zhong-suo-you-zi-mu-xzin/
*/
/*
解法都是滑动窗口法，用了两个容器来记录指定窗口的元素个数，如果两个容器相等（C++可以直接如此操作：sCount == pCount，），则返回下标
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
            int sLen = s.size(), pLen = p.size();

            if(sLen < pLen){
                return vector<int>();
            }
            vector<int> ans;
            vector<int> sCount(26);
            vector<int> pCount(26);
            for(int i =0; i < pLen; i ++){
                sCount[s[i] - 'a'] ++;
                pCount[p[i] - 'a'] ++;
            }

            if(sCount == pCount){
                ans.emplace_back(0);//追加元素 
            }

            for(int i = 0;i < sLen - pLen; i ++){
                sCount[s[i] - 'a'] --;
                sCount[s[i + pLen] - 'a'] ++;
                if(sCount == pCount){
                    ans.emplace_back(i + 1);
                }
            }
            return ans;
    }
};
/*
优化，优化成只用一个数组，同时用 differ来记录不同元素个数，只有differ == 0，才满足条件 
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(),pLen = p.size();

        if(sLen < pLen){
            return vector<int>();
        }

        vector<int> ans;
        vector<int> count(26);//count是用来记录两个字串元素个数的 
        for(int i = 0; i < pLen; i ++){
            count[s[i] - 'a'] ++;
            count[p[i] - 'a'] --;
        }
        int differ= 0;//记录不同元素个数 
        for(int j =0; j < 26; j ++){
            if(count[j] != 0){
                differ++;
            }
        } 
        if(!differ){
            ans.emplace_back(0);
        }
        for(int i =0; i < sLen - pLen; i ++){
        	//当此处的元素在字串中的个数为1时，移除该元素才会引起differ的变化，或者之前刚好与p中的字母匹配，为0，移除掉的话，会增加不同元素个数 
            if(count[s[i] - 'a'] == 1){
                differ --;
            }else if(count[s[i] - 'a'] == 0){
                differ ++;
            }
            count[s[i] - 'a'] --;
            if(count[s[i + pLen] - 'a'] == -1){
                differ --;
            }else if(count[s[i + pLen] - 'a'] == 0){
                differ ++;
            }
            count[s[i + pLen] - 'a'] ++;
            if(!differ){
                ans.emplace_back(i + 1);
            }
        }
            return ans;
    }
};
