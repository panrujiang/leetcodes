/*
问题来源：
https://leetcode.cn/problems/7WHec2/description/
解答：
https://leetcode.cn/problems/7WHec2/solutions/974489/jian-zhi-offer-2-mian-shi-ti-77-shu-zhon-7vy3/ 
*/

/*
直接将这些数据放到数组中进行排序 
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* cur = head;
        int i = 0;
        vector<int> ans;
        while(cur){
            ans.push_back(cur -> val);
            cur = cur -> next;
        }
        sort(ans.begin(), ans.end());
        cur = head;
        while(cur){
            cur -> val = ans[i];
            cur = cur -> next;
            i ++;
        }
        return head;
    }
};
/*
归并排序，但有些没有通过 
*/
class Solution {
private:
    ListNode* split(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next;
        }
        ListNode* second = slow -> next;
        slow -> next = NULL;
        return second;
    }
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while(head1 && head2){
            if(head1 -> val < head2 -> val){
                cur -> next = head1;
                head1 = head1 -> next;
            }else{
                cur -> next = head2;
                head2 = head2 -> next;
            }
            cur = cur -> next;
        }
        cur -> next = (head1 == NULL)? head2 : head1;
        ListNode* ret = dummy -> next;
        delete dummy;
        dummy = NULL;
        return ret;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* head1 = head;
        ListNode* head2 = split(head);

        head1 = sortList(head1);
        head2 = sortList(head2);
        return merge(head1, head2);
    }
};
