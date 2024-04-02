/*
题目来源：
https://leetcode.cn/problems/linked-list-cycle/description/
解答：
https://leetcode.cn/problems/find-the-duplicate-number/solutions/166258/qian-duan-ling-hun-hua-shi-tu-jie-kuai-man-zhi-z-3/
*/

/*
快慢指针 
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head, * slow = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};
