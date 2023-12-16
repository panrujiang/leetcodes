/*
��Ŀ��Դ��
https://leetcode.cn/problems/binary-prefix-divisible-by-5/description/
���
https://www.bilibili.com/video/BV1da411M798?p=65&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/binary-prefix-divisible-by-5/solutions/559804/you-xian-zhuang-tai-ji-by-nonsensersunny-glkk/
*/

/*
��ý�sum������֮��ȡ�࣬����int����long long���Ų��� 
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
����״̬�������˽�һ�� ����Ҳ��֪������ʲô���� 
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

