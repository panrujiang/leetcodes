/*
题目来源：
https://leetcode.cn/problems/hanota-lcci/description/
*/

/*
Hello算法的分治法 
*/
class Solution {
private:
    void move(vector<int> &src, vector<int> &tar){
        int pan = src.back();
        src.pop_back();
        tar.push_back(pan);
    }
    void dfs(int i, vector<int>& src, vector<int>& buf, vector<int>& tar){
        if(i == 1){
            move(src, tar);
            return;
        }
        dfs(i -1, src, tar, buf);
        move(src, tar);
        dfs(i - 1, buf, src, tar);
        return;
    }
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int i = A.size();
        dfs(i, A, B, C);
    }
};
