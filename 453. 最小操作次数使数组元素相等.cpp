/*
��Ŀ��Դ��
https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/description/
���
https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/solutions/1056443/wei-rao-li-lun-xuan-chu-n-1ge-zeng-jia-1-czj7/
*/

/*
��n-1������һ���һ������һû���� 
*/ 
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int l_min = INT_MAX, sum = 0;
        for(int i = 0; i < nums.size(); i ++){
            l_min = min(l_min, nums[i]);
            sum += nums[i];
        }
        return sum - l_min * nums.size();
    }
};

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int small = nums[0];
        int ans = 0;
        for(auto n : nums){
            small = min(small,n);
        }
        for(auto n : nums){
            ans += n - small;
        }
        return ans;
    }
};
