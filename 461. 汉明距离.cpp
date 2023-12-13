/*
��Ŀ��Դ��
https://leetcode.cn/problems/hamming-distance/description/
���
https://www.bilibili.com/video/BV1da411M798?p=25&spm_id_from=pageDriver&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a

*/

/*
����˼· 
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while(x || y){
           if((x & 1) ^ (y & 1)){
               count ++;
           } 
           x >>= 1;
           y >>= 1;
        }
        return count;
    }
};

/*
�����������������֮����1�ĸ��� 
 x &= (x - 1)��·���������1 
*/
class Solution {
private:
    int getCnt(int x){
        int count = 0;
        while(x){
            x &= (x - 1);
            count ++;
        }
        return count;
    }
public:
    int hammingDistance(int x, int y) {
        return getCnt(x ^ y);
    }
};


/*
������32λ���� 
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        for(int i = 0; i < 32; i ++){
            count += ((x >> i) & 1) ^ ((y >> i) & 1);
        }
        return count;
    }
};
