/*
��Ŀ��Դ��
https://leetcode.cn/problems/subarray-sum-equals-k/description/
���
https://leetcode.cn/problems/binary-subarrays-with-sum/solutions/562198/de-liao-yi-wen-ba-qian-zhui-he-miao-sha-mqngx/
https://leetcode.cn/problems/subarray-sum-equals-k/solutions/247577/bao-li-jie-fa-qian-zhui-he-qian-zhui-he-you-hua-ja/
https://leetcode.cn/problems/subarray-sum-equals-k/solutions/247991/dai-ni-da-tong-qian-zhui-he-cong-zui-ben-fang-fa-y/
*/

/*
ǰ׺�ͣ������Ӵ����ֵģ���Ӧ���뵽ǰ׺�� �����������ʱ������ 
*/
class Solution {
    int count = 0;
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> presum((nums.size() + 1), 0);
        for(int i = 0; i < nums.size(); i ++){
            presum[i + 1] = presum[i] + nums[i]; 
        }
        for(int i = 0; i < nums.size(); i ++){
            for(int j = i; j < nums.size(); j ++){
                if(presum[j + 1] - presum[i] == k){
                    count ++;
                }
            }
        }
        return count;
    }
};

/*
ǰ׺����Ϲ�ϣ�� 
map[0] = 1;��Ե�һ�����͵���K 
for(auto num : nums)���ֱ���һ��Ҫ�ᣬ���Ҫ�޸�nums�е�Ԫ�أ����ԼӸ����� auto & num 
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        int sum =0;
        for(auto num : nums){
            sum += num;
            res += map[sum - k];
            map[sum] ++;
        }
        return res;
    }
};
