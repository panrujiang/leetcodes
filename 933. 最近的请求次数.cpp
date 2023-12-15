/*
题目来源：
https://leetcode.cn/problems/number-of-recent-calls/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=53&spm_id_from=pageDriver&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

/*
英雄哪里出来的队列算法，最后返回队列的长度 
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

