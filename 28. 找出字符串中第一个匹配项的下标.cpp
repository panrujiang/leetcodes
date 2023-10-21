/*
题目来源：
 https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 解答：
https://programmercarl.com/0028.%E5%AE%9E%E7%8E%B0strStr.html#%E6%80%9D%E8%B7%AF
https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/2335848/javapython3wei-shi-yao-shi-kmptu-jie-by-p2d4b/
*/

/*
暴力枚举 
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
            int n = haystack.size(), m = needle.size();
            for(int i = 0; i <= n - m; i ++ ){
                int j =i, k =0;
                while(k < m && haystack[j] == needle[k]){
                    j ++;
                    k ++;
                }
                if(k == m){
                    return i;
                }

            }
            return -1;
    }
};
/*
KMP算法，这个的典型例题就是在字符串中找字串，挺难的。难点在于前缀表
前缀表：当匹配到的元素不同时，在母字串的指针加一，再遍历，这样时间复杂度太大了
可以利用前缀表使得就在匹配到不同元素的地方开始重新匹配 
*/
class Solution {
public:
    void getNext(int* next, const string& s) {
    	//j 指向最长前缀的下一位置，也就是最长前缀的长度 
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
