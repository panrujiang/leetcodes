/*
��Ŀ��Դ��
https://leetcode.cn/problems/duplicate-zeros/description/
���

*/

/*
�ҵı����ⷨ��ϸ�������������±겻��Խ�磬��Ϊ0ʱ��iҪ�����1 
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
˫ָ�� ��java 
*/
class Solution {
    public void duplicateZeros(int[] arr) {
        //����˼·�� 1.��ȡ�������ȡλ�õ����� 2.��β��ͷ����˫ָ�븳ֵ
        //1.��ȡ�������ȡλ�õ����� i
        int n = arr.length, i = 0, j = 0;
        while (j < n) {
            if (arr[i] == 0) j++;
            i++; j++;
        }
        //��ʱ������iָ����ǽ�ȡ��һλ����Ҫ-1������jͬ��
        i--; j--;
        //2.��β��ͷ����˫ָ�븳ֵ i : i->0   j : n->0
        while (i >= 0) {
            //j���һ������ִ����+2����,�ڴ�ȷ��j������С��n
            if (j < n) arr[j] = arr[i];
            //j���ƶ������ڴ�ȷ��j�����겻С��0
            if (arr[i] == 0 && j >= 0){
                j--;
                arr[j] = 0;
            }
            //i��jָ����ǰ�ƶ�
            i--; j--;
        }
    }
}
