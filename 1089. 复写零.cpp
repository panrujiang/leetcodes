/*
题目来源：
https://leetcode.cn/problems/duplicate-zeros/description/
解答：

*/

/*
我的暴力解法，细节满满，数组下标不得越界，当为0时候，i要额外加1 
*/
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int size = arr.size();
        if(size == 1) return;
        for(int i = 0; i < size; i ++){
             if(arr[i] == 0){
                 for(int j = size -1; j > i; j --){
                     arr[j] = arr[j - 1];
                 }
                 i +=1;
             }
        }
    }
};

/*
双指针 ，java 
*/
class Solution {
    public void duplicateZeros(int[] arr) {
        //整体思路是 1.获取到数组截取位置的坐标 2.从尾到头进行双指针赋值
        //1.获取到数组截取位置的坐标 i
        int n = arr.length, i = 0, j = 0;
        while (j < n) {
            if (arr[i] == 0) j++;
            i++; j++;
        }
        //这时候坐标i指向的是截取后一位，需要-1操作，j同理
        i--; j--;
        //2.从尾到头进行双指针赋值 i : i->0   j : n->0
        while (i >= 0) {
            //j最后一步可能执行了+2操作,在此确保j的坐标小于n
            if (j < n) arr[j] = arr[i];
            //j的移动规则，在此确保j的坐标不小于0
            if (arr[i] == 0 && j >= 0){
                j--;
                arr[j] = 0;
            }
            //i，j指针往前移动
            i--; j--;
        }
    }
}
