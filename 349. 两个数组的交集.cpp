/*
��Ŀ��Դ��
https://leetcode.cn/problems/intersection-of-two-arrays/description/
���
https://www.programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html#%E6%80%9D%E8%B7%AF 
https://leetcode.cn/problems/intersection-of-two-arrays-ii/solutions/327356/liang-ge-shu-zu-de-jiao-ji-ii-by-leetcode-solution/
*/

/*
�����õ���unordered_set�����Զ�ȥ�أ����ܺá��뷨�ǽ�һ��vector������nums1ת��Ϊset,Ȼ����nums2�б�������ѯ�Ƿ���ڴ�Ԫ�� 
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            unordered_set<int> result_set;
            // ��vectorת��Ϊunordered_set��nums1.end()ָ�����һ��Ԫ�ص���һ��λ�� 
            unordered_set<int> nums_set(nums1.begin(),nums1.end());
            //���ֱ���������ѧһ�£��йص��� 
            for(int num : nums2){
                if(nums_set.find(num) != nums_set.end()){
                    result_set.insert(num);
                }
            }
            //��󷵻ص���vector��������unordered_set 
            return vector<int>(result_set.begin(),result_set.end());
    }
};
