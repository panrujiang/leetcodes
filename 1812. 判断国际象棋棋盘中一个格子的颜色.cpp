/*
题目来源：
https://leetcode.cn/problems/determine-color-of-a-chessboard-square/description/
解答：
https://www.bilibili.com/video/BV1da411M798?p=16&vd_source=bb4b48d8c0acdd7bc58973f8e38ef55a
*/

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = coordinates[0] - 'a', y = coordinates[1] - '1';
        return (x + y) % 2 == 1;
    }
};


/*
异或也可以 
*/
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = coordinates[0] - 'a', y = coordinates[1] - '1';
        return (x % 2) ^ (y % 2) == 1;
    }
};
