/*
��Ŀ��Դ��
https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/
������
https://www.programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html#%E6%80%9D%E8%B7%AF 
https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/solutions/1395092/lian-biao-xiang-jiao-by-leetcode-solutio-2kne/
*/

/*

˼·������������ĳ��ȼ��������Ȼ���������ָ��ͣ���ھ�������ĩβmin(len(A),len(B))�ĵط���Ȼ��һ��ʼ���� 
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
        
        //����ָ���ٴγ�ʼ������Ϊ֮ǰ���������ȵ�ʱ�򣬷����˱仯 
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
��ѧ�����õ��ĳ��ŵĽⷨ��Ҳ��˫ָ�� 
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
��ϣ�� 
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
