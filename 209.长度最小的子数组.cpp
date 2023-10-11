class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
            int length = nums.size();
            int result = INT32_MAX;
            int subLength;
            int sum = 0;
            int i =0;
            for(int j = 0; j < length; j ++){
                sum += nums[j];
                while(sum >= target){
                    subLength = j - i + 1;
                    result = result < subLength ? result : subLength ;
                    sum -= nums[i];
                    i += 1;
                }
            }
        return result == INT32_MAX ? 0 : result;
    }
};
