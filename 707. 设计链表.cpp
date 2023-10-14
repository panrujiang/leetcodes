/*
题目来源：
https://leetcode.cn/problems/design-linked-list/description/
解答：
https://www.programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html#%E6%80%9D%E8%B7%AF 
https://leetcode.cn/problems/design-linked-list/solutions/1840997/she-ji-lian-biao-by-leetcode-solution-abix/
*/
/*
涉及链表的查询，在指定位置增加或者删除元素，本题中还有一个_size来保存链表中元素个数，查询是用while(index --) 
*/
class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val),next(nullptr){}
    };
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index > _size - 1){
            return -1;
        }
        LinkedNode *cur = _dummyHead -> next;
        while(index --){
            cur = cur ->next;
        }
        return cur ->val;
    }
    
    void addAtHead(int val) { 
        LinkedNode *newNode = new LinkedNode(val);
        newNode -> next = _dummyHead -> next;
        _dummyHead -> next = newNode;
        _size ++;
    }
    
    void addAtTail(int val) {
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = _dummyHead;
        while(cur->next != NULL){
            cur = cur -> next;
        }
        /*
        int loop = _size;
        while(loop--){
            cur = cur -> next;
        }
        这样也可以，只不过不能用_size -- 
        */
        cur -> next = newNode;
        _size ++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size){
            return ;
        }
        if (index < 0){
            index = 0;
        }
        LinkedNode *newNode = new LinkedNode(val);
        LinkedNode *cur = _dummyHead;
        while(index --){
            cur = cur ->next;
        }
        newNode -> next = cur -> next;
        cur -> next = newNode; 
        _size ++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index > _size -1){
            return ;
        }
        LinkedNode *cur = _dummyHead;
        while(index --){
            cur = cur ->next;
        }
        LinkedNode *tmp = cur -> next;
        cur -> next = cur ->next -> next;
        delete tmp;
        tmp = NULL;
        _size --;
    }
    void printLinkedList(){
        LinkedNode *cur = _dummyHead;
        while(cur -> next != NULL){
            cout << cur ->next -> val << " ";
            cur = cur ->next;
        }
        cout << endl;
    }

private:
    int _size;
    LinkedNode* _dummyHead;
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
