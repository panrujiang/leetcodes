/*
��Ŀ��Դ��
https://leetcode.cn/problems/missing-number/description/
���
https://www.bilibili.com/video/BV1da411M798?p=18&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/missing-number/solutions/1086545/gong-shui-san-xie-yi-ti-wu-jie-pai-xu-ji-te3s/
*/

/*
���������ּ������������μ�ȥ 
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) /2;
        for(int i = 0; i < n; i ++){
            sum -= nums[i];
        }
        return sum;
    }
};


/*
���������򣬱��±� ���Ҳ����������ֵ 
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i ++){
            if(i != nums[i]){
               return i;
            }
        }
        return n;
    }
};

/*
��ϣ�� 
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> result(n + 1, false);
        for(int i = 0; i < n; i ++){
            result[nums[i]] = true;
        }
        for(int i = 0; i < n; i ++){
            if(!result[i]){
                return i;
            }
        }
        return n;
    }
};

/*
���������������е��� 
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n + 1);
        for(int i = 0; i < n + 1; i ++){
            result[i] = i;
        }
        int ans = 0;
        for(int i = 0; i < n; i ++){
            ans ^= nums[i];
        }
        for(int i = 0; i < n + 1; i ++){
            ans^=result[i];
        }
        return ans;
    }
};

/*
��ˮ��Ҷ����� 
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 1; i <= nums.size(); i ++){
            ans ^= i;
        }
        for(int i = 0; i < nums.size(); i ++){
            ans ^= nums[i];
        }
        return ans;
    }
};
