/*
��Ŀ��Դ��
https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/description/
���
hello�㷨 
https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/solutions/164083/mian-shi-ti-57-he-wei-s-de-liang-ge-shu-zi-shuang-/
*/

/*
��ϣ����һ����Ԫ��ֵ���ڶ��������� 
*/
class Solution{
public:
	vector<int> twoSum(vector<int>& price, int target){
		unordered_map<int, int> hash;
		for(int i = 0; i < price.size(); i ++){
			if(hash.find(price[i]) != hash.end()){
				return {target - price[i], price[i]};
			}
			hash.emplace(target - price[i], i);
		}
		return {};
	}
}; 

/*
˫ָ�� 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        int left = 0, right = price.size() - 1;
        while(left < right){
            if(price[left] + price[right] > target){
                right --;
            }else if(price[left] + price[right] < target){
                left ++;
            }else{
                return {price[left],price[right]};
            }
        }
        return {};
    }
};
