/*
������Դ��
https://leetcode.cn/problems/count-number-of-pairs-with-absolute-difference-k/description/
���
https://leetcode.cn/problems/count-number-of-pairs-with-absolute-difference-k/solutions/1039580/fei-chang-qiao-miao-de-ji-shu-si-xiang-0-uhh6/
*/

/*
�ù�ϣ���¼֮ǰ���ֹ������ִ�����Ȼ��������ж�Ҫ���ҵ������Ƿ񲻺Ϲ棬���ֵĴ��� 
*/
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int record[101] ={0};
        int ans = 0;
        for(int i =0; i < nums.size(); i ++){
            int x = nums[i] + k;
            if(x > 0 && x < 101){
                ans += record[x];
            }
            x = nums[i] - k;
            if(x > 0 && x < 101){
                ans += record[x];
            }
            record[nums[i]] ++;
        }
        return ans;
    }
};

/*
�����ⷨ 
*/
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i ++){
            for(int j = i; j < nums.size(); j ++){
                if(abs(nums[i]-nums[j]) == k){
                    ans ++;
                }
            }
        }
        return ans;
    }
};

/*
��������� 
*/
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int harsh[101] = {0};
        int count = 0;
        for(int i = 0; i < nums.size(); i ++){
            harsh[nums[i]]  ++;
        }
        for(int i = 0; i + k < 101; i ++){
                count += harsh[i] * harsh[ i + k];
        }
        return count;
    }
};
