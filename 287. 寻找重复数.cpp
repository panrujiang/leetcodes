/*
��Ŀ��Դ��
https://leetcode.cn/problems/find-the-duplicate-number/description/
���
https://www.bilibili.com/video/BV1HG411C7ZM/?spm_id_from=333.788.recommend_more_video.4&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a

*/

/*
����+��ϣ�� 
*/
class Solution {
    int hash[100001] = {0};
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i ++){
            if(hash[nums[i]]){
                return nums[i];
            }
            hash[nums[i]] = 1;
        }
        return -1;
    }
};

/*
Ӣ����������Ļ��ķ��� 
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0,fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
