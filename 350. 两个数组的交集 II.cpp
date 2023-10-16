/*
题目来源：
https://leetcode.cn/problems/intersection-of-two-arrays-ii/description/
解答：
https://leetcode.cn/problems/intersection-of-two-arrays-ii/solutions/683821/ha-xi-biao-liang-ge-shu-zu-de-jiao-ji-ii-fkwo/ 
*/
/*
先排序，双指针，将满足条件的放入到vector中 
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    	//对两个数组排序 
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int> ans;
        int index1 = 0, index2 = 0;
        while(index1 < len1 && index2 < len2){
            if(nums1[index1] == nums2[index2]){
                ans.push_back(nums1[index1]);
                index1 ++;
                index2 ++;
            }else if(nums1[index1] < nums2[index2]){
                index1 ++;
            }else{
                index2 ++;
            }
        }
        return ans;
    }
};
/*
哈希表，map 
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            if(nums1.size() > nums2.size()){
                return intersect(nums2,nums1);
            }
            unordered_map <int, int> m;
            for(int num : nums1){
                m[num] ++;
            }
            vector<int> ans;
            for(int num : nums2){
                if(m.count(num)){
                    ans.push_back(num);
                    m[num] --;
                    //擦除map中的元素 
                    if(!m[num]){
                        m.erase(num);
                    }
                }
            }
            return ans;
    }
};
