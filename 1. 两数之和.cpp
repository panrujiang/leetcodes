/*
��Ŀ��Դ��
https://leetcode.cn/problems/two-sum/
���
https://www.programmercarl.com/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
https://leetcode.cn/problems/two-sum/solutions/434597/liang-shu-zhi-he-by-leetcode-solution/
*/
/*
�ù�ϣ���map�����map key��value.key�洢����Ԫ�أ�value�洢�±ꡣ 
map��find�������β�Ϊkey,����ֵ��һ����������first��key,second��value
map׷��Ԫ���� map.insert(pair<int, int>(nums[i], i)); 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            // ������ǰԪ�أ�����map��Ѱ���Ƿ���ƥ���key
            auto iter = map.find(target - nums[i]); 
            if(iter != map.end()) {
                return {iter->second, i};
            }
            // ���û�ҵ�ƥ��ԣ��Ͱѷ��ʹ���Ԫ�غ��±���뵽map��
            map.insert(pair<int, int>(nums[i], i)); 
        }
        return {};
    }
};
