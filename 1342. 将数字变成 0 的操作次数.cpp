/*
��Ŀ��Դ��
https://leetcode.cn/problems/number-of-steps-to-reduce-a-number-to-zero/description/
���
https://www.bilibili.com/video/BV1oR4y1W79x/?spm_id_from=333.999.0.0&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a 
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
