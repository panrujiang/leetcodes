/*
问题来源：
https://leetcode.cn/problems/combination-sum-iii/description/
解答：
https://programmercarl.com/0216.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CIII.html#%E6%80%9D%E8%B7%AF
*/

/*
我的解法：回溯算法 + 剪枝 
*/
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    int sum = 0;
    void backtracking(int k, int n,int startIndex){
        if(sum == n && path.size() == k){
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i <= min(n,9); i ++){
            path.push_back(i);
            sum += i;
            backtracking(k,n,i + 1);
            path.pop_back();
            sum -= i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        path.clear();
        result.clear();
        backtracking(k,n,1);
        return result;
    }
};
