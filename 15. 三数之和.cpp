/*
������Դ��
https://leetcode.cn/problems/3sum/description/
���
https://programmercarl.com/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E6%80%9D%E8%B7%AF 
*/

/*
˫ָ�뷨����һ��i������������� ��Ȼ��left��right���м俿£ 
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        //���������� 
        sort(nums.begin(),nums.end());
        for(int i =0; i < nums.size(); i ++){
            if(nums[i] > 0){
                return result;
            }
    		//��aȥ�� 
            if(i > 0 &&nums[i] == nums[i - 1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[i] + nums[left] + nums[right] > 0){
                    right --;
                }else if(nums[i] + nums[left] + nums[right] < 0){
                    left ++;
                }else{
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    //ֻ���ҵ��˷�����ĿҪ������֣����б�Ҫ��b,cȥ�� 
                    while(left < right && nums[left] == nums[left + 1]) left ++;
                    while(left < right && nums[right] == nums[right - 1]) right --;

                    right --;
                    left ++;
                }
            }
        }
        return result;
    }
};
