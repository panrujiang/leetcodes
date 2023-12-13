/*
题目来源：
https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-to-zero/description/
解答：
https://www.bilibili.com/video/BV1oR4y1W79x/?spm_id_from=333.999.0.0&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a 
https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-to-zero/solutions/1240668/gong-shui-san-xie-note-bie-pian-yi-ti-sh-85fb/
*/

/*
我的方法 
*/
int numberOfSteps(int num){
    int count = 0;
    while(num){
        if(!(num%2)) num/=2;
        else num-=1;
        count ++;
    }
    return count;
}
/*
屌的做法，有点找规律了 
*/
int f[1000001];
int numberOfSteps(int num){
    int i;
    f[0] = 0;
    for(i = 1; i <= num;i ++){
        if(i % 2){
            f[i] = f[i - 1] + 1;
        }else{
            f[i] = f[i/2] + 1;
        }
    }
    return f[num];
}
/*
三叶的做法 
*/
class Solution {
public:
    int numberOfSteps(int num) {
        int ans = 0;
        while(num != 0 &&  ans ++ >= 0 ){
            num = num % 2 == 0 ? num /2 : num - 1;
        }
        return ans;
    }
};

/*
变为0：末尾是1，减去，末尾是0，右移1位 
*/
class Solution {
public:
    int numberOfSteps(int num) {
        long  count = 0;
        while(num > 0){
            if((num & 1 ) == 1){
                num -= 1;
            }else{
                num /= 2;
            }
            count ++;
        }
        return count;
    }
};

/*
统计1的个数和最高位1所在位置即可 
*/
class Solution {
private:
    int count = 0;
    int getCnt(int num){
        while(num){
            num &= (num - 1);
            count ++;
        }
        return count;
    }
    int position = 0;
    int getPos(int num){
        while(num > 1){
            num >>= 1;
            position ++;
        }
        return position;
    }
public:
    int numberOfSteps(int num) {
        if(num == 0){
            return 0;
        }
        return getCnt(num) + getPos(num) ;
    }
};
