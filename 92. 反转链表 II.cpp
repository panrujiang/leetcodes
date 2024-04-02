/*
题目来源：
https://leetcode.cn/problems/reverse-linked-list-ii/
解答：

*/
/*
只是将val进行更改 
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* DummyNode = new ListNode(0,head);
        ListNode* leftNode = DummyNode;
        stack<int> stk;
        while(left --){
            leftNode = leftNode -> next;
        }
        ListNode* rightNode = DummyNode;
        while(right --){
            rightNode = rightNode -> next;
        }
        ListNode* tmp = leftNode;
        while(tmp != rightNode -> next){
            stk.push(tmp -> val);
            tmp = tmp -> next;
        }
        while(leftNode != rightNode -> next){
            leftNode -> val = stk.top();
            stk.pop();
            leftNode = leftNode -> next;
        }
        return DummyNode -> next;
    }
};

/*
反转链表 
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* DummyNode = new ListNode(0,head);
        ListNode* leftNode = DummyNode;
        stack<int> stk;
        while(--left){
            leftNode = leftNode -> next;
        }
        ListNode* rightNode = DummyNode;
        while(right --){
            rightNode = rightNode -> next;
        }
        ListNode* pre = rightNode -> next, * cur = leftNode -> next;
        while(pre != rightNode){
            ListNode* tmp = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = tmp;
        }
        leftNode -> next = pre;

        return DummyNode -> next;
    }
};

