/*
问题来源：
https://leetcode.cn/problems/how-many-numbers-are-smaller-than-the-current-number/description/
解答：
https://programmercarl.com/1365.%E6%9C%89%E5%A4%9A%E5%B0%91%E5%B0%8F%E4%BA%8E%E5%BD%93%E5%89%8D%E6%95%B0%E5%AD%97%E7%9A%84%E6%95%B0%E5%AD%97.html#%E6%80%9D%E8%B7%AF
*/

/*
暴力解法 
*/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i ++){
            int count = 0;
            for(int j = 0; j < nums.size(); j ++){
                if(nums[j] < nums[i]){
                    count ++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

/*
哈希优化 ,trick：建立哈希表时从后向前遍历 
*/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      vector<int> num = nums;
      sort(num.begin(), num.end());
      int hash[101];
      vector<int> result;
      for(int i = nums.size() - 1; i >= 0;i --){
          hash[num[i]] = i;
      }
      for(int i = 0; i < nums.size(); i ++){
          result.push_back(hash[nums[i]]);
      }
      return result;
    }
};

