/*
������Դ��
https://leetcode.cn/problems/implement-stack-using-queues/description/
���
https://programmercarl.com/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.html#%E6%80%9D%E8%B7%AF 
*/

/*
����������que1��que2ʵ�ֶ��еĹ��ܣ�que2��ʵ��ȫ����һ�����ݵ����ã���que1������Ԫ�������Ԫ�ض����ݵ�que2��Ȼ�󵯳�������Ԫ�أ��ٰ�����Ԫ�ش�que2����que1��
*/

class MyStack {
public:
    queue<int> que1;
    queue<int> que2;

    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size = que1.size();
        size --;
        while(size --){
            que2.push(que1.front());
            que1.pop();
        }
        int result = que1.front();
        que1.pop();
        que1 = que2;
        while(!que2.empty()){
            que2.pop();
        }
        return result;
    }
    
    int top() {
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
    }
};
/*
һ��������ģ��ջ����Ԫ�ص�ʱ��ֻҪ������ͷ����Ԫ�أ��������һ��Ԫ���⣩ ������ӵ�����β������ʱ��ȥ����Ԫ�ؾ���ջ��˳���ˡ�
*/
class MyStack {
public:
    queue<int> que;
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int size = que.size();
        size --;
        while(size --){
            que.push(que.front());
            que.pop();
        }
        int result = que.front();
        que.pop();
        return result;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
