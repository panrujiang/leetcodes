/*
��Ŀ��Դ��
 https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 ���
https://programmercarl.com/0028.%E5%AE%9E%E7%8E%B0strStr.html#%E6%80%9D%E8%B7%AF
https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/2335848/javapython3wei-shi-yao-shi-kmptu-jie-by-p2d4b/
*/

/*
����ö�� 
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
KMP�㷨������ĵ�������������ַ��������ִ���ͦ�ѵġ��ѵ�����ǰ׺��
ǰ׺����ƥ�䵽��Ԫ�ز�ͬʱ����ĸ�ִ���ָ���һ���ٱ���������ʱ�临�Ӷ�̫����
��������ǰ׺��ʹ�þ���ƥ�䵽��ͬԪ�صĵط���ʼ����ƥ�� 
*/
class Solution {
public:
    void getNext(int* next, const string& s) {
    	//j ָ���ǰ׺����һλ�ã�Ҳ�����ǰ׺�ĳ��� 
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
