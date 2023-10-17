/*
������Դ��
https://leetcode.cn/problems/count-number-of-pairs-with-absolute-difference-k/description/
*/
/*
�ù�ϣ���¼֮ǰ���ֹ������ִ�����Ȼ��������ж�Ҫ���ҵ������Ƿ񲻺Ϲ棬���ֵĴ��� 
*/
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int record[101] ={0};
        int ans = 0;
        for(int i =0; i < nums.size(); i ++){
            int x = nums[i] + k;
            if(x > 0 && x < 101){
                ans += record[x];
            }
            x = nums[i] - k;
            if(x > 0 && x < 101){
                ans += record[x];
            }
            record[nums[i]] ++;
        }
        return ans;
    }
};
