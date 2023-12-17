/*
题目来源：
https://leetcode.cn/problems/sum-multiples/description/
解答：
https://leetcode.cn/problems/sum-multiples/solutions/2485869/python3javacgorust-yi-ti-shuang-jie-mei-b3o2s/
*/

/*
题目简单，暴力遍历就行了，但涉及到了数学的容斥原理 
普通的遍历 
*/
class Solution {
public:
    int sumOfMultiples(int n) {
        int count = 0;
        for(int i = 1 ; i <= n; i ++){
            if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0){
               count += i;
            }
        }
        return count;
    }
};

/*
容斥原理 , 学到匿名函数的用法
https://blog.csdn.net/gongdiwudu/article/details/125797173 
*/
class Solution {
public:
    int sumOfMultiples(int n) {
        auto f = [&](int x){
            int m = n / x;
            return (x + m * x) * m / 2;
        };
        return f(3) + f(5) + f(7) - f(3 * 5) - f(3 * 7) - f(5 * 7) + f(3 * 5 * 7);
    }
};

