/*
题目来源： 
https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/description/
https://leetcode.cn/problems/binary-tree-right-side-view/description/
https://leetcode.cn/problems/average-of-levels-in-binary-tree/description/
https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/
https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/
https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/description/
https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/description/
https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
解答：
https://programmercarl.com/0102.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E5%B1%82%E5%BA%8F%E9%81%8D%E5%8E%86.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE 
*/

/*
111. 二叉树的最小深度
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
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        int depth = 0;
        while(!que.empty()){
            int size = que.size();
            depth ++;
            for(int i =0; i < size; i ++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node ->right) que.push(node->right);
                if(!node->left && !node->right){
                    return depth;
                }
            }
        }
        return depth;
    }
};

/*
104. 二叉树的最大深度
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
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        int depth = 0;
        if(root != NULL) que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i =0; i < size; i ++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node ->right) que.push(node->right);
            }
            depth ++;
        }
        return depth;
    }
};

/*
117. 填充每个节点的下一个右侧节点指针 II
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root) que.push(root);
        while(!que.empty()){
            int size = que.size();
            Node* nodePre;
            Node* node;
            for(int i =0; i < size;i ++){
                if(i == 0){
                    nodePre = que.front();
                    que.pop();
                    node = nodePre;
                }else{
                    node = que.front();
                    que.pop();
                    nodePre->next = node;
                    nodePre = nodePre ->next;
                }
                if(node->left) que.push(node->left);
                if(node ->right) que.push(node->right);
            }
            nodePre ->next = NULL;
        }
        return root;
    }
};

/*
116. 填充每个节点的下一个右侧节点指针
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que;
        if(root) que.push(root);
        while(!que.empty()){
            int size = que.size();
            Node* nodePre;
            Node* node;
            for(int i =0; i < size;i ++){
                if(i == 0){
                    nodePre = que.front();
                    que.pop();
                    node = nodePre;
                }else{
                    node = que.front();
                    que.pop();
                    nodePre->next = node;
                    nodePre = nodePre ->next;
                }
                if(node->left) que.push(node->left);
                if(node ->right) que.push(node->right);
            }
            nodePre ->next = NULL;
        }
        return root;
    }
};
/*
515. 在每个树行中找最大值
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
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);
        vector<int> result;
        while(!que.empty()){ 
            int size = que.size();
            int max = INT_MIN;
            while(size --){
                TreeNode* node = que.front();
                que.pop();
                if(node->val > max){
                    max = node->val;
                }
                if(node->left) que.push(node -> left);
                if(node->right) que.push(node -> right);
            }
            result.push_back(max);
        }
         return result;
    }
};
/*
429. N 叉树的层序遍历
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        if(root) que.push(root);
        vector<vector<int>> result;
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            for(int i =0; i < size; i ++){
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);
                for(int j = 0;j < node->children.size();j ++){
                    if(node ->children[j]) que.push(node->children[j]);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};
/*
637. 二叉树的层平均值
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
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        vector<double> result;
        while(!que.empty()){
            int size = que.size();
            double sum = 0;
            for(int i =0; i < size; i ++){
                TreeNode* node = que.front();
                que.pop();
                sum += node -> val;
                if(node->left) que.push(node->left);
                if(node ->right) que.push(node->right);
            }
            result.push_back(sum/size);
        }
        return result;
    }
};

/*
199. 二叉树的右视图
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
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);
        vector<int> result;
        while(!que.empty()){
            int size = que.size();
            while(size --){
                TreeNode* node = que.front();
                que.pop();
                if(size == 0){
                    result.push_back(node->val);
                }
                if(node->left) que.push(node -> left);
                if(node->right) que.push(node -> right);
            }

        }
         return result;
    }
};
/*
107. 二叉树的层序遍历 II
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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);
        vector<vector<int>> result;
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            while(size --){
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node -> val);
                if(node->left) que.push(node -> left);
                if(node->right) que.push(node -> right);
            }
            result.push_back(vec);
        }
         reverse(result.begin(),result.end());
         return result;
    }
};
/*
102. 二叉树的层序遍历
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != NULL) que.push(root);
        vector<vector<int>> result;
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            for(int i =0; i < size; i ++){
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node ->right) que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};
