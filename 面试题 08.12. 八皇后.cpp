/*
��Ŀ��Դ��
https://leetcode.cn/problems/eight-queens-lcci/description/
���
https://leetcode.cn/problems/eight-queens-lcci/solutions/487917/ba-huang-hou-hui-su-suan-fa-jing-dian-ti-mu-xiang-/
*/

/*
������Դ��Hello�㷨�����ϴ�������¼ 
*/
class Solution {
private:
    void backtrack(int row, int n, vector<string> &state, vector<vector<string>>& res,
    vector<bool> &cols, vector<bool>& diags1, vector<bool>& diags2){
        if(row == n){
            res.push_back(state);
            return;
        }
    for(int col = 0; col < n; col ++){
        int diag1 = row - col + (n - 1);
        int diag2 = row + col;
        if(!cols[col] && !diags1[diag1] && !diags2[diag2]){
            state[row][col] = 'Q';
            cols[col] = diags1[diag1] = diags2[diag2] = true;
            backtrack(row + 1, n, state, res, cols, diags1, diags2);
            state[row][col] = '.';
            cols[col] = diags1[diag1] = diags2[diag2] = false;
        }
    }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
    	//����ĳ�ʼ��û��ô������ 
        std::vector<std::string> state(n, std::string(n, '.'));
        //vector<string> state(n, string(n, '.'));
        vector<vector<string>> res;
        vector<bool> cols(n, false);
        vector<bool> diags1(2 * n - 1, false);
        vector<bool> diags2(2 * n - 1, false);
        backtrack(0, n, state, res, cols, diags1, diags2);
        return res;

    }
};
