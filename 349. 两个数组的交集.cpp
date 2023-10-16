/*
题目来源：
https://leetcode.cn/problems/intersection-of-two-arrays/description/
解答：
https://www.programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html#%E6%80%9D%E8%B7%AF 
https://leetcode.cn/problems/intersection-of-two-arrays-ii/solutions/327356/liang-ge-shu-zu-de-jiao-ji-ii-by-leetcode-solution/
*/

/*
这里用到了unordered_set，会自动去重，这点很好。想法是将一个vector容器的nums1转换为set,然后在nums2中遍历，查询是否存在此元素 
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> result_set;
            // 将vector转化为unordered_set，nums1.end()指向最后一个元素的下一个位置 
            unordered_set<int> nums_set(nums1.begin(),nums1.end());
            //这种遍历语句可以学一下，有关迭代 
            for(int num : nums2){
                if(nums_set.find(num) != nums_set.end()){
                    result_set.insert(num);
                }
            }
            //最后返回的是vector，而不是unordered_set 
            return vector<int>(result_set.begin(),result_set.end());
    }
};
