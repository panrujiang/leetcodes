/*
��Ŀ��Դ��
https://leetcode.cn/problems/maximum-product-of-three-numbers/description/
���
https://www.bilibili.com/video/BV1dY4y1m7YB/?p=9&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/maximum-product-of-three-numbers/solutions/339839/pai-xu-fa-he-bu-pai-xu-de-fang-fa-du-zai-zhe-li-li/
*/

/*
�ҵ���С�����������Լ�������������(����еĻ�) 
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max1 = nums[0] * nums[1] * nums[nums.size() - 1];
        int max2 = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        return max1 > max2 ? max1 : max2;

    }
};


/*
����ɨ�� 
�ҵ�5�������洢���ֵ�������ֵ�Լ��δ����ֵ����Сֵ������Сֵ 
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for(int num : nums){
            if(num > max1){
                max3 = max2;
                max2 = max1; 
                max1 = num;
            }else if(num > max2){
                max3 = max2;
                max2 = num;
            }else if(num > max3){
                max3 = num;
            } 
            if(num < min1){
                min2 = min1;
                min1 = num;
            }else if( num < min2){
                min2 = num;
            }
        }

        return (min1 * min2 * max1) >(max1 * max2 * max3) ? min1 * min2 * max1 : max1 * max2 * max3;

    }
};
