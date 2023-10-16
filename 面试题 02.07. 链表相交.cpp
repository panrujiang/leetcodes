/*
题目来源：
https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/
问题解答：
https://www.programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html#%E6%80%9D%E8%B7%AF 
https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/solutions/1395092/lian-biao-xiang-jiao-by-leetcode-solutio-2kne/
*/

/*

思路；把两个链表的长度计算出来，然后操作遍历指针停靠在距离链表末尾min(len(A),len(B))的地方，然后一起开始遍历 
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A_cur = headA;
        ListNode* B_cur = headB;
        int A_len = 0, B_len = 0;
        while(A_cur){
            A_len ++;
            A_cur = A_cur -> next;
        }
        while(B_cur){
            B_len ++;
            B_cur = B_cur -> next;
        }
        
        //两个指针再次初始化，因为之前计算链表长度的时候，发生了变化 
        A_cur = headA;
        B_cur = headB;
        
        if(B_len > A_len){
            swap (A_cur,B_cur);
            swap (A_len,B_len);
        }
        int gap = A_len - B_len;
        while(gap --){
            A_cur = A_cur -> next;
        }
        while(A_cur && B_cur){
            if(A_cur == B_cur ){
                return (A_cur);
            }
            A_cur = A_cur ->next;
            B_cur = B_cur -> next;
        }
        return NULL;
    }
};

/*
数学方法得到的超屌的解法，也是双指针 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        ListNode* A_cur = headA, *B_cur = headB;
        while(A_cur != B_cur){
            A_cur = A_cur == NULL ? headB : A_cur ->next;
            B_cur = B_cur == NULL ? headA : B_cur ->next;
        }
        return A_cur;
    }
};
/*
哈希表 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> visited;
        ListNode* temp = headA;
        while(temp){
            visited.insert(temp);
            temp = temp -> next;
        }
        temp = headB;
        while(temp){
            if(visited.count(temp)){
                    return temp;
            }
            temp = temp -> next;
        }
            return NULL;
    }
};
