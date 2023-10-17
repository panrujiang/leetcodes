/*
������Դ��
https://leetcode.cn/problems/4sum/description/
���
https://www.programmercarl.com/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E6%80%9D%E8%B7%AF 
*/

/*
��������֮�ͣ�ֻ��������������ѭ��������ָ�� 
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int left, right;
        for(int i =0; i < nums.size(); i ++){
        	//���target�Ǹ�����������ǰ��ֹ����target=-9��nums[0] = -8,nums[1] = -3,nums[2] = 0,nums[3] = 2,��ʹnums[0] > -9,�����Ǵ��ڵ� 
            if(nums[i] > target && nums[i] > 0){
                return ans;
            }
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            //����ֻ����break����������return 
            for(int j = i + 1; j < nums.size(); j ++){
                if(nums[j] + nums[i] > target && nums[j] + nums[i] >= 0){
                    break;
                }
                if((j - 1) > i &&nums[j] == nums[j - 1]){
                    continue;
                }
                left = j + 1;
                right = nums.size() - 1;
            while(left < right){
            	//����long������� 
                if((long)nums[i] + nums[j] + nums[left] + nums[right] > target){
                    right --;
                }else if((long)nums[i] + nums[j] + nums[left] + nums[right] < target){
                    left ++;
                }else{
                    ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                    //����ȥ�ز��ǼӼ�2����Ϊ�����ز��أ�left��Ҫ++,right��Ҫ-- ��ֻҪ�������Ƶ����һ���ص�λ�ü��� 
                    while(left < right && nums[left] == nums[left + 1]) left ++;
                    while(left < right && nums[right] == nums[right - 1]) right --;
                    left ++;
                    right --;
                }
            }

            }
        }
        return ans;
    }
};
