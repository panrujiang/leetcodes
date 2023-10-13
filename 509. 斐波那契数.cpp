/*
ԭ�⣺https://leetcode.cn/problems/fibonacci-number/description/
һЩ�ȽϺõĽ��
https://blog.csdn.net/weixin_57544072/article/details/121969045?app_version=6.1.7&csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22121969045%22%2C%22source%22%3A%22m0_53573725%22%7D&utm_source=app
https://leetcode.cn/problems/fibonacci-number/solutions/545049/fei-bo-na-qi-shu-by-leetcode-solution-o4ze/
https://leetcode.cn/problems/fibonacci-number/solutions/2361746/509-fei-bo-na-qi-shu-dong-tai-gui-hua-qi-so8h/ 
*/
/*
�������ƣ��������ڸ��� 
*/
class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        if(n == 2)
            return 1;
        return fib(n-1) + fib(n - 2);

    }
};
/*
��̬�滮������ʽ������
��Ȼ��Ч��ԭ�����ظ����㣬��ô���ǿ�����һ��������¼����ÿ�����ĳ��������Ĵ𰸺���ŷ��أ��ȼǵ�������¼�����ٷ��أ�ÿ������һ����������ȥ������¼�����һ�飬�������֮ǰ�Ѿ��������������ˣ�ֱ�ӰѴ��ó����ã���Ҫ�ٺ�ʱȥ�����ˡ�
һ��ʹ��һ������䵱���������¼������Ȼ��Ҳ����ʹ�ù�ϣ���ֵ䣩��˼�붼��һ���ġ�
*/
class Solution {
public:
	int fib(int n){
		if(n <= 1){
			return n;
		}
		vector<int> ans(n + 1,0);
		ans[0] = 0;
		ans[1] = 1;
		for(int i =2; i <= n; i++){
			ans[i] = ans[i-1] + ans[i - 2];
		}
		return ans[n];
	}
}; 
/*
Ҳ�Ƕ�̬�滮����ͬ��չʾ��ʽ 
*/
class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        int p = 0, q = 1, r = 1;
        int loop = n - 2;
        while(loop -- > 0){
            p = q;
            q = r;
            r = p + q;
        } 
        return r;
    }
};
