/*
问题来源：
https://leetcode.cn/problems/binary-tree-paths/description/
解答：
https://programmercarl.com/0257.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%89%80%E6%9C%89%E8%B7%AF%E5%BE%84.html#%E6%80%9D%E8%B7%AF 
https://leetcode.cn/problems/binary-tree-paths/solutions/400434/257-er-cha-shu-de-suo-you-lu-jing-tu-wen-jie-xi-by/
*/

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
        void traversal(TreeNode* cur,vector<int>& path,vector<string>& result){
            path.push_back(cur->val);
            if(cur->left == NULL && cur->right == NULL){
                string sPath;
                for(int i = 0;i < path.size() - 1;i ++){
                    sPath += to_string(path[i]);
                    sPath += "->";
                }
                sPath += to_string(path[path.size() - 1]);
                result.push_back(sPath);
                return;
            }
            if(cur -> left){
                traversal(cur->left,path,result);
                path.pop_back();
            }
            if(cur -> right){
                traversal(cur->right,path,result);
                path.pop_back();
            }
        }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if(root == NULL) return result;
        traversal(root,path,result);
        return result;
    }
};


/*
一眼回溯算法 
*/
class Solution {
private:
    vector<string> ans;
    void dfs(TreeNode* node, string path){
        if(!node){
            return;
        }
        if(!node -> left && !node -> right){
            path += to_string(node -> val);
             ans.push_back(path);
        }
        dfs(node -> left, path + to_string(node -> val) + "->");
        dfs(node -> right, path + to_string(node -> val) + "->");
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "");
        return ans;
    }
};
/*
Java递归的方法 
*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new LinkedList<>();
        if(root == null){
            return res;
        }
        if(root.left == null && root.right == null){
            res.add(root.val + "");
            return res;
        }
        for(String path : binaryTreePaths(root.left)){
            res.add(root.val + "->" + path);
        }
        for(String path : binaryTreePaths(root.right)){
            res.add(root.val + "->" + path);
        }
        return res;
    }
}


