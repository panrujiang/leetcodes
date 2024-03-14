/*
题目来源：
https://leetcode.cn/problems/jewels-and-stones/description/
解答：
https://leetcode.cn/problems/jewels-and-stones/solutions/2356253/ben-ti-zui-you-jie-xian-xing-shi-jian-ch-ddw3/
*/

/*
我的做法 
*/
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for(char& ch : stones){
            size_t pos = jewels.find(ch);
            if(pos != std::string::npos){
                ans ++;
            }
        }
        return ans;
    }
};
/*
灵神的解法 
*/
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        long long mask = 0;
        for(char c : jewels){
            mask |= 1LL << (c & 63);
        }
        int ans = 0;
        for(char c : stones){
        	//&1是将其他位置零，保留最低位 
            ans += mask >> (c & 63) & 1;
        }
        return ans;
    }
};

// 全部英文字母大小写一共 52 个
// 可以利用 64 位 long long 的二进制位作哈希
// 如何将 52 个字母唯一的映射到每个二进制位？
// (c & 63) 只取字符c(ASCII 码)二进制的后六位，好比取余操作，相当于 (c % 64)
// 如此 'A' ~ 'Z' 被映射到 1 ~ 26，'a' ~ 'z' 被映射到 33 ~ 58
// 该映射能保证每个字母都有唯一值，不会哈希冲突
// 且 (c & 63) 假设最大值为 63，移位操作也不会溢出 long long 范围
// 而实际上 (c & 63) 最大也就是 58，即 ('z' % 64)，所以移位不会溢出
// 总结：(c & 63) 解决了唯一映射的问题，同时移位不会溢出 64 位
// 这里应该是因为字符 ‘A’ 的 ASCII 码为 65 > 64，65 % 64 = 1，且最大的 'z' % 64 = 58 < 64
// 也就是 (c % 64) 能够映射到 0 ~ 63 的范围且保证唯一映射
// 可以把 (c & 63) 换成 (c - 64) 或 (c - 'A') 等也是可以的，但是位运算的效率更高点
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        long long mask = 0;
        for (char c : jewels) mask |= 1LL << (c & 63);
        int ans = 0;
        for (char c : stones) ans += mask >> (c & 63) & 1;
        return ans;
    }
};
