/*
问题来源：
https://leetcode.cn/problems/combination-sum/description/
解答：
https://programmercarl.com/0039.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C.html#%E6%80%9D%E8%B7%AF
*/

/*
回溯算法 
*/

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& candidates, int target, int index , int sum){
        if(sum > target){
            return;
        }
        if(sum == target){
            result.push_back(path);
            return;
        }
        for(int i = index; i < candidates.size(); i ++){
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i, sum);
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        backtracking(candidates, target, 0, 0);
        return result;
    }
};


/*
sum写在外面也可以，毕竟回溯都是要减去 
*/
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    int sum = 0;
    void backtracking(vector<int>& candidates, int target, int index){
        if(sum > target){
            return;
        }
        if(sum == target){
            result.push_back(path);
            return;
        }
        for(int i = index; i < candidates.size(); i ++){
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        backtracking(candidates, target, 0);
        return result;
    }
};
/*
直接用target等不等于0 
*/
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& candidates, int target, int index){
        if(target < 0){
            return;
        }
        if(target == 0){
            result.push_back(path);
            return;
        }
        for(int i = index; i < candidates.size(); i ++){
            target -= candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);
            target += candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        backtracking(candidates, target, 0);
        return result;
    }
};


/*
剪枝，要先对数组排序 
*/
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    void backtracking(vector<int>& candidates, int target, int index){
        if(target == 0){
            result.push_back(path);
            return;
        }
        for(int i = index; i < candidates.size() && target - candidates[i] >= 0; i ++){
            target -= candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);
            target += candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        path.clear();
        result.clear();
        sort(candidates.begin(),candidates.end());
        backtracking(candidates, target, 0);
        return result;
    }
};
