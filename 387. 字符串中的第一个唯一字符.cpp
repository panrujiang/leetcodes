/*
��Ŀ��Դ��
https://leetcode.cn/problems/first-unique-character-in-a-string/description/?envType=study-plan-v2&envId=selected-coding-interview
���
https://leetcode.cn/problems/first-unique-character-in-a-string/solutions/531740/zi-fu-chuan-zhong-de-di-yi-ge-wei-yi-zi-x9rok/?envType=study-plan-v2&envId=selected-coding-interview
*/

/*
�����ⷨ 
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
��ϣ��
count�����������ӳ�������д��ڴ��м�K��Ԫ�أ���ú�������1����������в����ڼ�ΪK��Ԫ�أ��򷵻�0��
map�ı�����ʽ 
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
��϶��У��Ƚ��ȳ� 
���е�һЩ�����ü�һ���Լ���ζ�����У����еĳ�Ա 
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
