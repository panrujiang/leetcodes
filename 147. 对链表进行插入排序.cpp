/*
题目来源：
https://leetcode.cn/problems/insertion-sort-list/description/
解答：
https://www.bilibili.com/video/BV1up4y1M7sQ/?p=7&spm_id_from=pageDriver
*/

/*
插入排序 + 虚拟头节点  
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head -> next){
            return head;
        }
        ListNode* dummy_node = new ListNode(0);
        dummy_node -> next = head;
        ListNode * prev = head, * cur = head -> next;
        while(cur){
            if(cur -> val >= prev -> val){
                prev = cur;
                cur = cur -> next;
            }else{
                ListNode* p = dummy_node;
                while(p->next -> val < cur -> val){
                    p = p -> next;
                }
                prev -> next = cur -> next;
                cur -> next = p -> next;
                p -> next = cur;

                cur = prev -> next;
            }
        }
        return dummy_node -> next;
    }
};

