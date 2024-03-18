/*
题目来源：
https://leetcode.cn/problems/7p8L0Z/description/
*/

/*
Hello算法的回溯法 
和无重复的比，多了一个哈希表，用来裁剪重复的出现 
*/
class Solution {
private:
    void backtrack(vector<int>& state, const vector<int> &choices, vector<bool> &selected, vector<vector<int>> &res){
        if(state.size() == choices.size()){
            res.push_back(state);
            return;
        }
        unordered_set<int>  duplicated;
        for(int i = 0; i < choices.size(); i ++){
            int choice = choices[i];
            if(!selected[i] && duplicated.find(choice) == duplicated.end()){
                duplicated.emplace(choice);
                selected[i] = true;
                state.push_back(choice);
                backtrack(state, choices, selected, res);
                selected[i] = false;
                state.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> state;
        vector<bool> selected(nums.size(), false);
        vector<vector<int>> res;
        backtrack(state, nums, selected, res);
        return res;
    }
};
