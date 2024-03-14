/*
题目来源：
https://leetcode.cn/problems/merge-intervals/description/
解答：
https://leetcode.cn/problems/merge-intervals/solutions/203562/he-bing-qu-jian-by-leetcode-solution/
https://leetcode.cn/problems/merge-intervals/
*/


/*
官方解答 
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0){
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for(int i = 0 ; i < intervals.size(); i ++){
            int L = intervals[i][0], R = intervals[i][1];
            if(!merged.size() || merged.back()[1] < L){
                merged.push_back({L,R});
            }else{
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};

/*
稍微简化版本 
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        for(auto intr : intervals){
            if(res.empty() || res.back()[1] < intr[0])
                res.push_back(intr);
            else{
            res.back()[1] = max(res.back()[1], intr[1]);
            }
        }
        return res;
    }
};

/*
双指针 
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for(int i = 0 ; i < intervals.size();){
            int t = intervals[i][1];
            int j = i + 1;
            while(j < intervals.size() && intervals[j][0] <= t){
                t = max(t, intervals[j][1]);
                j ++;
            }
            ans.push_back({intervals[i][0], t});
            i = j;
        }
        return ans;
    }
};
