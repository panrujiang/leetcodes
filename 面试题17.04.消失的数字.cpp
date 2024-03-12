/*
������Դ��
https://leetcode.cn/problems/missing-number-lcci/description/
���
https://blog.csdn.net/weixin_64904163/article/details/126672726?spm=1001.2014.3001.5502
https://leetcode.cn/problems/missing-number-lcci/solutions/96816/onshi-jian-fu-za-du-o1kong-jian-fu-za-du-shi-xian-/
*/

/*
�����ִ���ʱ��������������μ�ȥ�����е�ֵ�����õ��ľ�����ʧ������ 
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int length = nums.size();
        int sum = length * (length + 1)/2;
        for(int i = 0; i < length; i ++){
            sum -= nums[i];
        }
        return sum;
    }
};

/*
���
0���κ����������Զ���ڸ����֣�0^4=4
�����������ԣ�res = res ^ x ^ x��
��ͬһ��ֵ������Σ���ô��������������������Ƕ�res��0-nums.length�������
ͬʱ��nums�����е�ֵ������򣬳����ظ��Ļ���ʧ���������res��ֵ��ֻ����һ�ε����֣�
Ҳ����nums������ȱʧ���Ǹ����֡�
*/
class Solution{
public:
	int missingNumber(vector<int>& nums){
		int ans = 0;
		int length = nums.size();
		for(int i = 0; i < length; i ++){
			ans ^= i;
			ans ^= nums[i];
		}
		ans ^= length;
		return ans;
	} 
};











