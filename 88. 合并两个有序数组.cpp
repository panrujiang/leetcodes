/*
题目来源：
https://leetcode.cn/problems/merge-sorted-array/description/
解答：
https://leetcode.cn/problems/merge-sorted-array/solutions/666608/he-bing-liang-ge-you-xu-shu-zu-by-leetco-rrb0/ 
*/
/*
逆向双指针
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1,p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while(p1 >= 0 || p2 >= 0){
            if(p1 == -1){
                cur = nums2[p2 --];
            }else if(p2 == -1){
                cur = nums1[p1 --];
            }else if(nums1[p1] > nums2[p2]){
                cur = nums1[p1 --];
            }else{
                cur = nums2[p2 --];
            }
            nums1[tail --] = cur;
        }
    }
};

/*
我的解法 
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = m + n -1;
        int right1 = m - 1, right2 = n - 1;
        for(;tail >= 0; tail --){
            if(right1 >=0 && right2 >= 0){
                if(nums1[right1] > nums2[right2]){
                    nums1[tail] = nums1[right1 --];
                }else {
                    nums1[tail] = nums2[right2 --];
                }
                }else if(right1 == -1){
                        nums1[tail] = nums2[right2 --];
                    }else{
                        nums1[tail] = nums1[right1 --];
                    }
            }
    }
};
