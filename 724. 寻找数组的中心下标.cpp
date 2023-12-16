/*
��Ŀ��Դ��
https://leetcode.cn/problems/find-pivot-index/description/
���
https://leetcode.cn/problems/find-pivot-index/solutions/1645928/by-jyd-9265/
*/

/*
�ҵĽⷨ��ǰ׺�� 
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> presum((nums.size() + 1), 0);
        for(int i = 0; i < nums.size(); i ++){
            presum[i + 1] = presum[i] + nums[i];
        }
        for(int i = 1; i < presum.size(); i ++){
            if(presum[i - 1] == presum[presum.size() - 1] - presum[i]){
                return i - 1;
            }
        }
        return -1;
    }
};
/*
ģ�ⷨ 
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0,presum = 0;
        for(int i = 0; i < nums.size(); i ++){
            sum += nums[i];
        }
        for(int i = 0; i < nums.size(); i ++){
           presum = i == 0 ? presum : presum + nums[i - 1];
           if(presum == sum - nums[i]- presum){
               return i;
           }
        }
        return -1;
    }
};
/*
K��Ľⷨ��accumulate()������leftsum ��	rightsum 
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum = 0;
        int rightsum = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < nums.size(); i ++){
            rightsum -= nums[i];
            if(leftsum == rightsum){
                return i;
            }
            leftsum += nums[i];
        }
        return -1;
    }
};
