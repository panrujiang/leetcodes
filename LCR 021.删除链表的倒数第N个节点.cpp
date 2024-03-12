/*
��Ŀ��Դ��
https://leetcode.cn/problems/SLwz0R/description/
���
https://leetcode.cn/problems/SLwz0R/solutions/1417848/shan-chu-lian-biao-de-dao-shu-di-n-ge-ji-ydte/
*/

/*
�ҵ��뷨��Ҫɾ��һ���ڵ㣬�����ҵ��ýڵ��ǰ��һ���ڵ� 
*/

/*
˫ָ�� ����Ŀ������ҵ�����n+1���ڵ� 
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(0,head);//����д��ѧһѧ 
        ListNode * slow = dummyNode, *fast = dummyNode;
        n += 1;
        while(n --){
            fast = fast -> next;
        }
        while(fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        slow -> next = slow -> next -> next;
        ListNode* ans = dummyNode -> next;
        delete(dummyNode);
        return ans;
    }
};

/*
��ջ������Ҳ���� 
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(0, head);
        stack<ListNode*> stk;
        ListNode* cur = dummyNode;
        while(cur){
            stk.push(cur);
            cur = cur -> next;
        }
        for(int i = 0 ; i < n; i ++){
            stk.pop();
        }
        ListNode* prev = stk.top();
        prev -> next = prev -> next -> next;
        ListNode* ans = dummyNode -> next;
        delete dummyNode;
        return ans;
    }
};
