/*
��Ŀ��Դ��
https://leetcode.cn/problems/majority-element/description/?envType=study-plan-v2&envId=top-100-liked
*/


/*
��һ������Ϊ nums.size()/2 + 1�Ļ������飬�����򣬼�����ĩ���˵�Ԫ���Ƿ���ͬ 
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result;
        int size = nums.size()/2 + 1;
        int slow = 0, fast = slow + size - 1;
        sort(nums.begin(), nums.end());
        while(fast < nums.size()){
            if(nums[slow] == nums[fast]){
                result = nums[slow];
                break;
             }
             slow ++;
             fast ++;
        }
        return result;
    }
};

