/*
��Ŀ��Դ��
https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/description/
���
https://zhuanlan.zhihu.com/p/510570301
*/

/*
ֱ�ӱ������ҵ���һ��С����Ԫ�ص�Ԫ�ؼ������� 
*/
class Solution {
public:
    int stockManagement(vector<int>& stock) {
        int min = stock[0];
        for(auto i : stock){
            if(i < min){
                min =  i;
                break;
            }
        }
        return min;
    }
};
