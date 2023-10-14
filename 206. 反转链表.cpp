/*
题目来源：
https://leetcode.cn/problems/reverse-linked-list/description/
解答：
https://www.programmercarl.com/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.html#%E6%80%9D%E8%B7%AF 
*/

/*
本人的解法：
三个指针，pre,cur,Cnext,多一个指针Cnext是因为当反转链表时，cur -> next = pre,用Cnext存储了之前的cur -> next,就可以顺利地执行循环，cur = Cnext，注意，最后还得
cur->next = pre,因为循环结束时，是不会把最后一个节点连上的  
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        if (head->next == NULL) return head;

        ListNode *pre = head;
        ListNode *cur = head -> next;
        ListNode *Cnext = cur -> next;
        while(cur -> next != NULL){

            cur -> next = pre;
            pre = cur;
            cur = Cnext;
            Cnext = Cnext -> next;
        }
        cur -> next = pre;
        head -> next = NULL;
        return cur;
    }
};
/*
简化版，看了卡尔的网站之后 
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        if (head->next == NULL) return head;

        ListNode *pre = head;
        ListNode *cur = head -> next;
        ListNode *Cnext;
        while(cur != NULL){
            Cnext = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = Cnext;
        }
        //cur -> next = pre;
        head -> next = NULL;
        return pre;
    }
};
/*
卡尔给出的双指针法 
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // 保存cur的下一个节点
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur) {
            temp = cur->next;  // 保存一下 cur的下一个节点，因为接下来要改变cur->next
            cur->next = pre; // 翻转操作
            // 更新pre 和 cur指针
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
/*
很屌的递归法，链表十分适合递归 
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
    ListNode* reverse(ListNode* pre, ListNode* cur){
        if(cur == NULL) return pre;
        ListNode* tmp = cur -> next;
        cur -> next = pre;
        return reverse(cur,tmp);
    }
    ListNode* reverseList(ListNode* head) {
            return reverse(NULL,head);
    }
};

