/*
��Ŀ��Դ��
https://leetcode.cn/problems/sqrtx/description/
���
https://www.bilibili.com/video/BV1da411M798?p=57&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

/*
Ӣ�۲��ʳ����Ľⷨ ����mid * midС��x,�Ѹ�ֵ��¼��������Ϊһ����Чֵ 
*/
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        int ans;
        while(left <= right){
            int mid = (left + right) >> 1;
            if((long long) mid * mid <= x){
                ans = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return ans;
    }
};
/*
��Щ����һ��ȫ����ȫƽ�������������ȫƽ������ֱ����while()�з����� 
����ѭ����ʱ��˵�������������ȫƽ����������right���� ��right���Ǵ� 
*/
class Solution {
public:
    int mySqrt(int x) {
        int  left = 0, right = x;

        while(left <= right){
            int mid = left + (right - left)/2;
            if((long long)mid * mid < x )
                left = mid + 1;
            else if((long long)mid * mid > x)
                right = mid - 1;
            else
                return mid;
        }
        return right;
    }
};
