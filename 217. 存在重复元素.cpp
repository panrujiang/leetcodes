/*
��Ŀ��Դ��
https://leetcode.cn/problems/contains-duplicate/description/
���
https://www.bilibili.com/video/BV1da411M798?p=47&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/contains-duplicate/solutions/683879/ha-xi-biao-cun-zai-zhong-fu-yuan-su-by-d-bbzm/
*/

/*
���� + ѭ�� 
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i + 1 < nums.size(); i ++){
            if(nums[i] == nums[i + 1]){
                return true;
            }
        }
        return false;
    }
};
/*
������û�е����⣬�����뵽��ϣ�� 
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto x : nums){
            if(s.find(x) != s.end()){
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};
