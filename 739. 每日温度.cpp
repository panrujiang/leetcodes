/*
��Ŀ��Դ��
https://leetcode.cn/problems/daily-temperatures/
���
https://www.bilibili.com/video/BV1sN4y1a7yz/?spm_id_from=333.999.0.0&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/daily-temperatures/solutions/71433/leetcode-tu-jie-739mei-ri-wen-du-by-misterbooo/
*/

/*
�����ⷨ ������ʱ������ 
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ans(size);
        for(int i = 0; i < size; i ++){
            for(int j = i; j < size; j ++){
                if(temperatures[j] > temperatures[i]){
                    ans[i] = j - i;
                    break;
                }
            }
        }
        return ans;
    }
};

/*
�����ⷨ��ֻ�����Ӻ���ǰ������������ʱ�򾭳��ôӺ���ǰ�ķ����������ʱ�����Ƶ����� 
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ans(size);
        for(int i = size - 1; i > 0; i --){
            for(int j = i - 1; j >= 0; j --){
                if(temperatures[i] <= temperatures[j]){
                    break;
                }else {
                    ans[j] = i - j;
                }
            }
        }
        return ans;
    }
};

/*
����ջ 
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        stack<int> st;
        for(int i = 0; i < n; i ++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                auto t = st.top(); st.pop();
                res[t] = i - t;
            }
            st.push(i);
        }
        return res;
    }
};
