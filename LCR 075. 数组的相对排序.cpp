/*
题目来源：
https://leetcode.cn/problems/0H97ZC/description/https://leetcode.cn/problems/two-sum/
解答：

*/

/*
应该也是计数排序吧 
*/
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int hash[1001];
        vector<int> ret;
        for(int i = 0; i < arr1.size(); i ++){
            hash[arr1[i]] ++;
        }
        for(int num : arr2){
            while(hash[num] --){
                ret.push_back(num);
            }
        }
        for(int i = 0; i < 1001; i ++){
            if(hash[i] > 0){
                while(hash[i] --){
                    ret.push_back(i);
                }
            }
        }
        return ret;
    }
};

/*
自定义排序函数 
[](){}这是lambda表达式
使用[&]捕获所有外部变量的引用 
*/
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> rank;
        for(int i = 0; i < arr2.size(); i ++){
            rank[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(),[&](int x, int y){
            if(rank.count(x)){
                return rank.count(y) ? rank[x] < rank[y] : true;
            }else{
                return rank.count(y) ? false : x < y;
            }
        });
        return arr1;
    }
};
