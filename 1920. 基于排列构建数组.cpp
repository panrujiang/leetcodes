/*
��Ŀ��Դ��
https://leetcode.cn/problems/build-array-from-permutation/description/
���
https://leetcode.cn/problems/build-array-from-permutation/solutions/858017/ji-yu-pai-lie-gou-jian-shu-zu-by-leetcod-gjcn/
*/

/*
�򵥽ⷨ,����һ�����飬������������ 
*/
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans;
        for(int i = 0; i < size; i ++){
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};

/*
���۹ٷ�������ֱ����ԭ�������ϸģ���Ԫ�ظ��躬�� 
Ϊ��ʹ�ù������̿����������У�������Ҫ�� nums �е�ÿ��Ԫ��
nums[i] �ܹ�ͬʱ�洢����ǰֵ������ nums[i])�͡�����ֵ������ nums[nums[i]])
�̷�Ŀ��ֵ�������ŵ�ǰֵ 
*/
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i ++){
            nums[i] += 1000 * (nums[nums[i]]%1000);
        }
        for(int i = 0 ; i < nums.size(); i ++){
            nums[i] /= 1000;
        }
        return nums;
    }
};

