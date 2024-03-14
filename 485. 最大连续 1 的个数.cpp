/*
������Դ��
https://leetcode.cn/problems/max-consecutive-ones/description/
���
https://leetcode.cn/problems/max-consecutive-ones/solutions/603700/zui-da-lian-xu-1de-ge-shu-by-leetcode-so-252a/
*/

/*
�ҵĵͶ˽ⷨ 
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, length = nums.size();
        for(int i = 0; i < length; i ++){
            for(int j = i; j < length; j ++){
                if(nums[j] == 0){
                    break;
                }
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

/*
�ٷ�ֻ��һ�α������� 
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount =0, count = 0;
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] == 1){
                count ++;
            }else{
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        maxCount = max(maxCount, count);
        return maxCount;
    }
};
