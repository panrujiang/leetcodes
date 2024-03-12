/*
问题来源：
https://leetcode.cn/problems/missing-number-lcci/description/
解答：
https://blog.csdn.net/weixin_64904163/article/details/126672726?spm=1001.2014.3001.5502
https://leetcode.cn/problems/missing-number-lcci/solutions/96816/onshi-jian-fu-za-du-o1kong-jian-fu-za-du-shi-xian-/
*/

/*
把数字存在时和求出来，再依次减去数组中的值，最后得到的就是消失的数字 
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
异或法
0和任何数字异或永远等于该数字，0^4=4
利用异或的特性，res = res ^ x ^ x。
对同一个值异或两次，那么结果等于它本身，所以我们对res从0-nums.length进行异或，
同时对nums数组中的值进行异或，出现重复的会消失，所以最后res的值是只出现一次的数字，
也就是nums数组中缺失的那个数字。
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











