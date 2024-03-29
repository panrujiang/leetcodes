/*
题目来源：
https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
解答：
hello 算法 
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
/*
层序遍历，可以说是个模板 
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node * > queue;
        if(root) queue.push(root);
        vector<vector<int>> ret;
        while(!queue.empty()){
            int length = queue.size();
            vector<int> vec;
            for(int i = 0; i < length; i ++){
                Node* tmp = queue.front();
                queue.pop();
                vec.push_back(tmp -> val);
                for(int j = 0; j < tmp -> children.size(); j ++){
                    if(tmp -> children[j]){
                        queue.push(tmp -> children[j]);
                    }
                }
            }
            ret.push_back(vec);
        }
        return ret;
    }
};
