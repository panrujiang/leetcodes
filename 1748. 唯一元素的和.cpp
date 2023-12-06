/*
������Դ��
https://leetcode.cn/problems/sum-of-unique-elements/description/
���
https://www.bilibili.com/video/BV1Ra41177RB/?spm_id_from=333.788&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a

*/


/*
�����ⷨ 
*/
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans[101] = {0};
        int count = 0;
        for(int i =0; i < nums.size(); i ++){
            ans[nums[i]] ++;
        }
        for(int i =0; i <101; i ++){
            if(ans[i] == 1)
                count += i;
        }
        return count;
    }
};

/*
˫ָ�뻹��������for��䲻ȷ��i�Ĳ���ʱ�����ȿ��� 
*/
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), sum = 0;
        for(int i = 0; i < n; ){
            int j = i;
            while(j < n && nums[j] == nums[i]) j ++;
            if(j - i == 1) sum += nums[i];
            i = j;
        }
        return sum;
    }
};
