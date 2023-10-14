/*
��Ŀ��Դ��
https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
���
https://www.programmercarl.com/0019.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
 
*/

/*
˫ָ��ľ���Ӧ�ã����Ҫɾ��������n���ڵ㣬��fast�ƶ�n����Ȼ����fast��slowͬʱ�ƶ���ֱ��fastָ������ĩβ��ɾ��slow��ָ��Ľڵ�Ϳ����ˡ�
slowӦ��ָ��ɾ���ڵ��ǰһλ�� 
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummyNode = new ListNode(0);
        dummyNode -> next = head;
        ListNode* fast = dummyNode;
        ListNode* slow = dummyNode;
        int loop = n;
        while(loop --){
            fast = fast -> next;
        }
        while(fast -> next){
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode* tmp = slow -> next;
        slow -> next = slow -> next -> next;
        delete tmp;
        return dummyNode -> next;
    }
};
