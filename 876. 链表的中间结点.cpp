/*
题目来源：
https://leetcode.cn/problems/middle-of-the-linked-list/description/
解答：
https://leetcode.cn/problems/middle-of-the-linked-list/solutions/165152/kuai-man-zhi-zhen-zhu-yao-zai-yu-diao-shi-by-liwei/
*/

/*
返回第二个节点，一开始将slow和fast都定义在第一个节点 
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
};
