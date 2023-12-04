/*
问题来源：
https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/
解答：
https://programmercarl.com/0501.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E4%B8%AD%E7%9A%84%E4%BC%97%E6%95%B0.html#%E6%80%9D%E8%B7%AF
*/

/*
没用使用搜索树的特点 
*/
class Solution {
private:
    void searchBST(TreeNode* cur, unordered_map<int, int>& map){
        if(cur == NULL) return;
        map[cur -> val] ++;
        searchBST(cur -> left,map);
        searchBST(cur -> right,map);
        return;
    }
    bool static cmp(const pair<int,int>& a, const pair<int, int>& b){
        return a.second > b.second;
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map;
        vector<int> result;
        if(root == NULL) return result;
        searchBST(root,map);
        vector<pair<int, int>> vec(map.begin(),map.end());
        sort(vec.begin(),vec.end(),cmp);
        result.push_back(vec[0].first);
        for(int i = 1; i < vec.size(); i++){
            if(vec[i].second == vec[0].second) result.push_back(vec[i].first);
            else break;
        }
        return result;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int maxCount = 0;
    int count =0;
    TreeNode* pre = NULL;
    vector<int> result;
    void searchBTS(TreeNode* cur){
        if(cur== NULL) return;

        searchBTS(cur -> left);

        if(pre == NULL){
            count = 1;
        }else if(pre -> val == cur -> val){
            count ++;
        }else{
            count = 1;
        }
        pre = cur;

        if(count == maxCount){
            result.push_back(cur -> val);
        }
        if(count > maxCount){
            maxCount =count;
            result.clear();
            result.push_back(cur -> val);
        }
        searchBTS(cur -> right);
        return;
    }
public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        pre = NULL;
        result.clear();

        searchBTS(root);
        return result;
    }
};
