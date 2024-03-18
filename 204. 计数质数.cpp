/*
题目来源：
https://leetcode.cn/problems/count-primes/description/
解答：
https://leetcode.cn/problems/count-primes/solutions/507445/kuai-lai-miao-dong-shai-zhi-shu-by-sweetiee/
*/

/*
埃氏筛
*/
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrim(n, true);
        int count = 0;
        for(int i = 2; i * i < n; i ++){
            if(isPrim[i]){
                for(int j = i * i; j < n; j +=i){
                    isPrim[j] = false;
                }
            }
        } 
        for(int i = 2; i < n ; i ++){
            if(isPrim[i]){
                count ++;
            }
        }
        return count;
    }
};
