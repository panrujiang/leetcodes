/*
问题来源：
https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/description/
解答：
https://www.programmercarl.com/0104.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%A4%A7%E6%B7%B1%E5%BA%A6.html#%E7%9B%B8%E5%85%B3%E9%A2%98%E7%9B%AE%E6%8E%A8%E8%8D%90
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
    int maxDepth(Node* root) {
        if(root == NULL)    return 0;
        int depth = 0;
        for(int i =0; i < root->children.size(); i ++){
            depth = max(depth,maxDepth(root->children[i]));
        }
        return depth + 1;
    }
};

/*
迭代 
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
    int maxDepth(Node* root) {
        if(root == NULL) return 0;
        int depth = 0;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()){
            int n = que.size();
            for(int i =0; i < n; i ++){
                Node* node = que.front();
                que.pop();
                for (int j = 0; j < node->children.size(); j++) {
                    if (node->children[j]) que.push(node->children[j]);
                }
            }
            depth ++;
        }
        return depth;
    }
};

