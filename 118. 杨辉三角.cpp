/*
ԭ�⣺
https://leetcode.cn/problems/pascals-triangle/description/ 
���
https://leetcode.cn/problems/pascals-triangle/solutions/510638/yang-hui-san-jiao-by-leetcode-solution-lew9/ 
*/

/*
�ҵݹ鹫ʽ���ý�����漰����resize()��������Ϊ������ǵ������Ƕ��ģ������Ǳ仯�ģ���������Ҫ��resize()������ȷ���� 
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for(int i =0; i < numRows; i ++){
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for(int j = 1; j < i; j ++){
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
        }
            return ret;
    }
}; 
