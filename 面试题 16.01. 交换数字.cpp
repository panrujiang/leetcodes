/*
��Ŀ��Դ��
https://leetcode.cn/problems/swap-numbers-lcci/description/
���
https://www.bilibili.com/video/BV1da411M798?p=11&spm_id_from=pageDriver&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/swap-numbers-lcci/solutions/280374/cjian-jie-dai-ma-si-chong-fang-fa-qie-shuang-bai-b/
*/

/*
ջ 
*/
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        stack<int> s;
        for(int i = 0; i < numbers.size(); i ++){
            s.push(numbers[i]);
        }
        for(int i = 0; i < numbers.size(); i ++){
            numbers[i] = s.top();
            s.pop();
        }
        return numbers;
    }
};
/*
ȡ���� 
*/
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        return {numbers[1],numbers[0]};
    }
};

/*
���ķ��� 
*/
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] ^= numbers[1];
        numbers[1] ^= numbers[0];
        numbers[0] ^= numbers[1];
        return numbers;
    }
};
