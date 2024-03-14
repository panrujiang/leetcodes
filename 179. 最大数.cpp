/*
������Դ��
https://leetcode.cn/problems/largest-number/description/
���
https://blog.csdn.net/m0_67403773/article/details/135656198?spm=1001.2014.3001.5502
*/

/*
�Զ����˱ȽϺ��� 
*/
class Solution {
private:
   static bool cmp(int a, int b){
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
    }
public:
    string largestNumber(vector<int>& nums) {
        string ans;

        sort(nums.begin(), nums.end(), cmp);

        for(int& i : nums){
            ans += to_string(i);
        }
        if(ans[0] == '0'){
            return "0";
        }
        return ans;
    }
};
