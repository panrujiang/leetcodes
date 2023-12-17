/*
题目来源：
https://leetcode.cn/problems/delete-node-in-a-linked-list/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=86&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/


/*
由于头节点未知，不可能找到当前节点的前一节点，但是当前节点之后的连接关系十分清楚
所以把当前节点的值改成下一节点的值，把下一节点删除了 
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
         ListNode * pre = node, * cur = node -> next;
        pre -> val = cur -> val;
        pre -> next = cur -> next;
    }
};
