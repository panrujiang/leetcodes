/*
题目来源：https://www.nowcoder.com/questionTerminal/4060ac7e3e404ad1a894ef3e17650423
解答：https://blog.csdn.net/weixin_64904163/article/details/125920964?spm=1001.2014.3001.5502 
*/
class Solution{
public:
	void replaceSpace(char * str, int length){
		int cnt = 0;
		char * start = str;
		while(*start){
			if(*start == ''){
				cnt ++;
			}
			start ++;
		}
		int end1 = length - 1;
		int end2 = length + 2 * cnt - 1;
		while(end1 != end2){
			if(str[end1] != ' '){
				str[end2--] = str[end1 --];
			}else{
				str[end2--] = '0';
				str[end2--] = '2';
				str[end2--] = '%';
				end1 --;
			}
		}
	}
}; 

