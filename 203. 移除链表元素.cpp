/*
ԭ�⣺
https://leetcode.cn/problems/remove-linked-list-elements/description/
���
https://programmercarl.com/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.html#%E6%80%9D%E8%B7%AF 
https://leetcode.cn/problems/remove-linked-list-elements/solutions/813358/yi-chu-lian-biao-yuan-su-by-leetcode-sol-654m/
*/

/*
ֱ��ʹ��ԭ���������������Ƴ��ڵ����
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
    ListNode* removeElements(ListNode* head, int val) {

        while(head != NULL && head ->val == val){
            ListNode *tmp = head;
            head = head -> next;
            delete tmp;
        }

        ListNode * cur = head;
        while(cur != NULL && cur->next != NULL){
            if(cur->next->val == val){
                ListNode * tmp = cur -> next;
                cur -> next = cur -> next -> next;
                delete tmp;
            }else{
                cur = cur -> next;
            }
        }
        return head;
    }
};

/*
����һ������ͷ����ڽ����Ƴ��ڵ������ʹ�ö�ͷ�ڵ�Ĵ��������⴦�� 
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * dummyNode = new ListNode(0);
        dummyNode -> next = head;
        ListNode * pre = dummyNode;
        while(pre != NULL && pre -> next != NULL){
            if(pre -> next -> val == val){
                ListNode * tmp = pre ->next;
                pre -> next = pre -> next ->next;
                delete tmp;
            }else{
                pre = pre -> next;
            }
        }
        head = dummyNode -> next;
        delete dummyNode;
        return head;
    }
};
/*
�ݹ鷽�����ȶ�ͷ�ڵ�head����Ľڵ����ɾ�����������ж�head�Ƿ���Ҫɾ���� 
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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL){
            return head;
        }
        head -> next = removeElements(head -> next, val);
        return head -> val == val ? head -> next : head;

    }
};

