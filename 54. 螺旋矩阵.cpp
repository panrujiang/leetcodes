/*
��ϸ������
https://leetcode.cn/problems/spiral-matrix/solutions/275393/luo-xuan-ju-zhen-by-leetcode-solution/ 
*/

/*
����һ��ģ��
һЩϸ�ڣ�
�˶���˳����ȷ���ģ���->��->��->��->�ҡ�����
���Է��������˳��Ҳ����һ�£����統�������в�ͨ�ˣ�������һ������Ԫ�أ������� 
*/
class Solution {
private:
    static constexpr int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix.size() == 0){
            return {};
        }
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(columns));
        int total = rows * columns;
        vector<int> order(total);

        int row = 0, column = 0;
        int directionIndex = 0;

        for(int i =0; i < total; i ++){
            order[i] = matrix[row][column];
            visited[row][column] = true;
            int nextRow = row + directions[directionIndex][0],nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
                directionIndex = (directionIndex + 1) % 4;
            }
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
        }
        return order;
    }
};

/*
������������ģ��
ϸ�ڣ�
��������������ϱ�����ʱ�򣬶��˸�if�ж���䣬������Ϊ������ֻʣ��һ�л���һ�е�ʱ��ֻ��Ҫ���ұ����������±������ɣ����û�����������䣬��ֻʣһ�л���һ�е�ʱ������ĸ�ֵ����������ҵ�
�ĸ�ֵ�����ͬ������Ҳ������µĳ���� 
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
};
/*
 һ�ֳ��ŵĽⷨ����ϸ����
 https://leetcode.cn/problems/spiral-matrix/solutions/7155/cxiang-xi-ti-jie-by-youlookdeliciousc-3/ 
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int left = 0;
        int right = matrix[0].size() - 1;
        int top = 0;
        int bottom = matrix.size() - 1;

        while(true){
            for(int i = left; i <= right; i ++){
                ans.push_back(matrix[top][i]);
            }
            if(++ top > bottom){
                break;
            }
            for(int i = top; i <= bottom; i ++){
                ans.push_back(matrix[i][right]);
            }
            if(--right < left){
                break;
            }
            for(int i = right; i >= left; i --){
                ans.push_back(matrix[bottom][i]);
            }
            if(-- bottom < top){
                break;
            }
            for(int i = bottom; i >= top; i --){
                ans.push_back(matrix[i][left]);
            }
            if(++left > right){
                break;
            }
        }
            return ans;
    }
};
