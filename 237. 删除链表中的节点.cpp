/*
��Ŀ��Դ��
https://leetcode.cn/problems/delete-node-in-a-linked-list/description/
���
https://www.bilibili.com/video/BV1da411M798?p=86&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/


/*
����ͷ�ڵ�δ֪���������ҵ���ǰ�ڵ��ǰһ�ڵ㣬���ǵ�ǰ�ڵ�֮������ӹ�ϵʮ�����
���԰ѵ�ǰ�ڵ��ֵ�ĳ���һ�ڵ��ֵ������һ�ڵ�ɾ���� 
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
         ListNode * pre = node, * cur = node -> next;
        pre -> val = cur -> val;
        pre -> next = cur -> next;
    }
};
