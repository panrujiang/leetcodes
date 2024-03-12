/*
题目来源：
https://leetcode.cn/problems/validate-stack-sequences/description/
解答：
https://www.bilibili.com/video/BV1tu4y1N77i/?spm_id_from=333.788&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
https://leetcode.cn/problems/validate-stack-sequences/solutions/1787960/by-ac_oier-84qd/
*/

/*
模拟即可 
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        for(int i = 0, j = 0; i < n; i ++){
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[j]){
                st.pop();
                j ++;
            }
        }
        return st.empty();
    }
};

/*
原地修改 
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), idx = 0;
        for(int i = 0, j = 0; i < n; i ++){
            pushed[idx ++] = pushed[i];
            while(idx > 0 && pushed[idx - 1] == popped[j] && ++j >= 0){
                idx --;
            }
        }
        return idx == 0;
    }
};

