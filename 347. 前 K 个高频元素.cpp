/*
������Դ��
https://leetcode.cn/problems/top-k-frequent-elements/description/
���
https://programmercarl.com/0347.%E5%89%8DK%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0.html#%E6%80%9D%E8%B7%AF
*/

/*
ѧ���˴󶥶Ѻ�С���� 
*/

class Solution {
public:

    class mycomparison{
        public:
            bool operator()(const pair<int ,int>& lhs,const pair<int,int> rhs){
                return lhs.second > rhs.second;
            }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i = 0;i < nums.size(); i++){
            map[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomparison> pri_que;

        for(unordered_map<int,int> :: iterator it = map.begin();it != map.end();it ++){
            pri_que.push(*it);
            if(pri_que.size() > k){
                pri_que.pop();
            }
        }
        vector<int> result(k);
        for(int i = k - 1;i >= 0 ; i --){
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};

/*
python
*/
import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        map_ = {}
        for i in range(len(nums)):
            map_[nums[i]] = map_.get(nums[i],0) + 1//get()������ȡ��Ԫ�ص�value�����û�д�Ԫ�أ�Ĭ��ֵΪ0 

        pri_que = []

        for key,freq in map_.items():
            heapq.heappush(pri_que,(freq,key))
            if len(pri_que) > k:
                heapq.heappop(pri_que)
        
        result = [0] * k
        for i in range(k - 1, -1,-1):
            result[i] = heapq.heappop(pri_que)[1]
        return result
