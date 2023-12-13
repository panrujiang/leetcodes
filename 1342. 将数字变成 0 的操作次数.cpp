/*
��Ŀ��Դ��
https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-to-zero/description/
���
https://www.bilibili.com/video/BV1oR4y1W79x/?spm_id_from=333.999.0.0&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a 
https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-to-zero/solutions/1240668/gong-shui-san-xie-note-bie-pian-yi-ti-sh-85fb/
*/

/*
�ҵķ��� 
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
�ŵ��������е��ҹ����� 
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
��Ҷ������ 
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
��Ϊ0��ĩβ��1����ȥ��ĩβ��0������1λ 
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
ͳ��1�ĸ��������λ1����λ�ü��� 
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
