/*
题目来源：
https://leetcode.cn/problems/binary-prefix-divisible-by-5/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=65&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/binary-prefix-divisible-by-5/solutions/559804/you-xian-zhuang-tai-ji-by-nonsensersunny-glkk/
*/

/*
最好将sum计算完之后取余，否则int甚至long long都放不下 
*/
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        long long sum = 0;
        for(int i = 0; i < nums.size(); i ++){
            sum = sum << 1 | nums[i];
            sum %= 5;
            ans.push_back(sum == 0);
        }
        return ans;
    }
};

/*
有限状态机可以了解一下 ，我也不知道这是什么语言 
*/
impl Solution {
    pub fn prefixes_div_by5(a: Vec<i32>) -> Vec<bool> {
        let mut state: i32 = 0;
        let mut result = vec![];
        let stateSet = [[0, 1], [2, 3], [4, 0], [1, 2], [3, 4]];
        for i in a {
            state = stateSet[state as usize][i as usize];
            result.push(state == 0);
        }
        result
    }
}

