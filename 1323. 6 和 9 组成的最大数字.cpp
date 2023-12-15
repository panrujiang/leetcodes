/*
��Ŀ��Դ��
https://leetcode.cn/problems/maximum-69-number/description/
���
https://leetcode.cn/problems/maximum-69-number/solutions/79090/c-zhao-chu-di-yi-ge-6zai-na-li-ji-ke-by-logan-31/
*/

/*
�ҵ�������ת�����ַ��� 
stoi(s)���ַ���ת��Ϊ���� 
*/
class Solution {
public:
    int maximum69Number (int num) {
        string s  = "";
        while(num){
            s = (char)(num % 10 + '0') + s;
            num /= 10;
        }
        for(char& ch : s){
            if(ch == '6'){
                ch = '9';
                break;
            }
        }
        return stoi(s);
    }
};

/*
�ҵ����λ��6 ������ 3 * pow(10,th - 1)���� 
*/
class Solution {
public:
    int maximum69Number (int num) {
        int count = 0, th = 0;
        int re = num;
        while(re){
            count ++;
            if(re % 10 == 6){
                th = count;
            }
            re /= 10;
        }
        return th == 0 ? num : num + 3 * pow(10,th - 1);
    }
};

/*
ԭ�����ߵ�˼· ������Ҳ�����th = 0, 3 * pow(10,th - 1) = 3 * 10 ^(-1) �Ǹ�С��������ֵ���Ǹ�int�ͣ����Զ�ȥβ 
*/
class Solution {
public:
    int maximum69Number (int num) {
        int count = 0, th = 0;
        int re = num;
        while(re){
            count ++;
            if(re % 10 == 6){
                th = count;
            }
            re /= 10;
        }
        return  num + 3 * pow(10,th - 1);
    }
};
