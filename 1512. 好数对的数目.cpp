/*
��Ŀ��Դ��
https://leetcode.cn/problems/number-of-good-pairs/description/ 
*/
/*
����Ϊ����j���ڣ�0��j - 1���б�������ǰ�������������п�����Ӧ�������ж��ٸ� 
record�����¼�����ֵĸ�����ans��¼�ź����Ե���Ŀ 
*/
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int record[101] = {0};
        int ans = 0;
        for(int i =0; i < nums.size(); i ++){
                ans += record[nums[i]];
                record[nums[i]] ++;
        }
        return ans;
    }
};
