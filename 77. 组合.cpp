/*
问题来源：
https://leetcode.cn/problems/combinations/description/
解答：
https://programmercarl.com/0077.%E7%BB%84%E5%90%88.html#%E6%80%9D%E8%B7%AF
*/

/*
回溯算法 
*/

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startIndex){
        if(path.size() == k){
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i <= n; i ++){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        path.clear();
        backtracking(n,k,1);
        return result;
    }
};

/*
进行了剪枝 
*/
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int n, int k, int startIndex){
        if(path.size() == k){
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i <= n - (k - path.size()) + 1; i ++){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        result.clear();
        path.clear();
        backtracking(n,k,1);
        return result;
    }
};
