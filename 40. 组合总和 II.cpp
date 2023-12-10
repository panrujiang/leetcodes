/*
题目来源：
https://leetcode.cn/problems/combination-sum-ii/description/
解答：
https://programmercarl.com/0040.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CII.html#%E6%80%9D%E8%B7%AF
*/

/*
回溯算法，要去重，这里用数组来去重 
*/
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& candidates, int target, int startIndex, vector<bool> used){
        if(target == 0){
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i ++){
            if(i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false){
                continue;
            }
            target -= candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, i + 1, used);
            used[i] = false;
            target += candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        path.clear();
        result.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used);
        return result;
    }
};

/*
直接用startIndex来去重 
*/
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& candidates, int target, int startIndex){
        if(target == 0){
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i ++){
            if(i > startIndex && candidates[i] == candidates[ i - 1]){
                continue;
            }
            target -= candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i + 1);
            target += candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return result;
    }
};
