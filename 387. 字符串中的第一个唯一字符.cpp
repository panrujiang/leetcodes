/*
题目来源：
https://leetcode.cn/problems/first-unique-character-in-a-string/description/?envType=study-plan-v2&envId=selected-coding-interview
解答：
https://leetcode.cn/problems/first-unique-character-in-a-string/solutions/531740/zi-fu-chuan-zhong-de-di-yi-ge-wei-yi-zi-x9rok/?envType=study-plan-v2&envId=selected-coding-interview
*/

/*
暴力解法 
*/
class Solution {
public:
    int firstUniqChar(string s) {
        int a[26] = {0};
        for(int i = 0; i < s.size(); i ++){
            a[s[i] - 'a']++;
        }
        for(int i = 0; i < s.size(); i ++){
            if(a[s[i] - 'a'] == 1){
                return i;
            }
        }
        return -1;
    }
};


/*
哈希表，
count函数：如果在映射容器中存在带有键K的元素，则该函数返回1。如果容器中不存在键为K的元素，则返回0。
map的遍历方式 
*/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> position;
        int n = s.size();
        for(int i = 0; i < n ; i ++){
            if(position.count(s[i])){
                position[s[i]] = -1;
            }else{
                position[s[i]] = i;
            }
        }
        int first = n;
        for(auto [_,pos] : position){
            if(pos != -1 && pos < first){
                first = pos;
            }
        }
        if(first == n){
            first = -1;
        }
        return first;
    }
};

/*
配合队列，先进先出 
队列的一些函数得记一记以及如何定义队列，队列的成员 
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> position;
        queue<pair<char,int>> q;
        int n = s.size();
        for(int i = 0; i < n; i ++){
            if(!position.count(s[i])){
                position[s[i]] = i;
                q.emplace(s[i],i);
            }else{
                position[s[i]] = - 1;
                while(!q.empty() && position[q.front().first] == -1){
                    q.pop();
                }
            }
        }
        return q.empty() ? - 1 : q.front().second;
    }
};
