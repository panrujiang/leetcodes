/*
��Ŀ��Դ��
https://leetcode.cn/problems/reverse-linked-list/description/
���
https://www.programmercarl.com/0206.%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8.html#%E6%80%9D%E8%B7%AF 
*/

/*
���˵Ľⷨ��
����ָ�룬pre,cur,Cnext,��һ��ָ��Cnext����Ϊ����ת����ʱ��cur -> next = pre,��Cnext�洢��֮ǰ��cur -> next,�Ϳ���˳����ִ��ѭ����cur = Cnext��ע�⣬��󻹵�
cur->next = pre,��Ϊѭ������ʱ���ǲ�������һ���ڵ����ϵ�  
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
�򻯰棬���˿�������վ֮�� 
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
����������˫ָ�뷨 
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp; // ����cur����һ���ڵ�
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur) {
            temp = cur->next;  // ����һ�� cur����һ���ڵ㣬��Ϊ������Ҫ�ı�cur->next
            cur->next = pre; // ��ת����
            // ����pre �� curָ��
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};
/*
�܌ŵĵݹ鷨������ʮ���ʺϵݹ� 
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

