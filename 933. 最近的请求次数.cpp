/*
��Ŀ��Դ��
https://leetcode.cn/problems/number-of-recent-calls/description/
���
https://www.bilibili.com/video/BV1da411M798?p=53&spm_id_from=pageDriver&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

/*
Ӣ����������Ķ����㷨����󷵻ض��еĳ��� 
*/
class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {

    }
    
    int ping(int t) {
        while(!q.empty()){
            if(t - q.front() > 3000){
                q.pop();
            }else{
                break;
            }
        }
        q.push(t);
        return q.size();
    }
};

