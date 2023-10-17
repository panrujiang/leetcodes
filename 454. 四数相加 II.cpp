/*
������Դ��
https://leetcode.cn/problems/4sum-ii/description/
���
https://programmercarl.com/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE 
*/

/*
��������֮�ͣ�ֻ�����������ĸ����飬�ǾͿ��������ϲ�������������飬Ȼ�����ù�ϣ���ѯ 
*/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    	//�����map 
        unordered_map<int ,int> umap;
        //���ֱ���Ҫ���ö���Ҫ��д 
        for(int num1 : nums1){
            for(int num2 : nums2){
                umap[num1 + num2] ++;
            }
        }
        int count = 0;
        for(int num3 : nums3){
            for(int num4 : nums4){
                auto iter = umap.find(0 - (num3 + num4));
                if( iter!= umap.end()){
                    count += iter ->second;
                }
            }
        }
        return count;
    }
};
