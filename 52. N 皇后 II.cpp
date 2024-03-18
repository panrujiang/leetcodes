/*
题目来源：
https://leetcode.cn/problems/n-queens-ii/description/
*/

/*
计算个数，hello 算法 
*/
class Solution {
private:
    int count = 0;
    void backtrack(int row, int n,vector<bool>& cols,vector<bool>& diags1, vector<bool>& diags2){
        if(row == n){
            count ++;
            return;
        }
        for(int col = 0; col < n; col ++){
            int diag1 = row - col + (n - 1);
            int diag2 = row + col;
            if(!cols[col] && !diags1[diag1] && !diags2[diag2]){
                cols[col] = diags1[diag1] = diags2[diag2] = true;
                backtrack(row + 1, n, cols, diags1, diags2);
                cols[col] = diags1[diag1] = diags2[diag2] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<bool> cols(n,false);
        vector<bool> diags1(2 * n - 1, false);
        vector<bool> diags2(2 * n - 1, false);
        backtrack(0, n,cols, diags1, diags2);
        return count;
    }
};
