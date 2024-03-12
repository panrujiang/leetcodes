/*
������Դ��
https://leetcode.cn/problems/rotate-array/description/
���
https://blog.csdn.net/weixin_64904163/article/details/126672726?spm=1001.2014.3001.5502
*/
/*
ÿ������һ�Σ��ظ�k�Σ������۳�����ʱ������ 
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         k %= nums.size();
        for(int j = 0; j < k; j ++ ){
             int temp = nums[nums.size() - 1];
        for(int i = nums.size() - 1 ; i - 1 >= 0; i --){
            nums[i] = nums[i - 1];
        }
            nums[0] = temp;
        }
       
    }
};
/*
ʱ�任�ռ�
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        k %= length;
        int *arr = (int*)malloc(sizeof(int)*length);
        for(int i = length - k - 1, j = length - 1; i >=0;){
            arr[j--] = nums[i --]; 
        }
        for(int i = length - k, j = 0; i < length; ){
            arr[j ++] = nums[i ++];
        }
        for(int i = 0; i < length; i ++){
            nums[i] = arr[i];
        }
        free(arr);
        arr = NULL;
    }
};

/*
һ�ֺ�����ķ��� 
*/
class Solution {
private:
	//���� 
    void swap(int& a, int& b){
        int temp = a;
            a = b;
            b = temp;
    }
public:
    void rotate(vector<int>& nums, int k) {
        int length = nums.size();
        k %= length;//�������Ҫ 
        int l = 0, r = length - k - 1;
        while(l < r){
            swap(nums[l++], nums[r--]);
        }
        l = length -k;
        r = length - 1;
        while(l < r){
            swap(nums[l++], nums[r--]);
        }
        l = 0;
        r = length - 1;
        while(l < r){
            swap(nums[l++], nums[r--]);
        }
    }
};

/*
��Ϊ�򵥵�д�� 
*/
class Solution {
private:
    void reverse(vector<int>& nums, int left, int right){
        while(left < right){
            int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            ++ left;
            -- right;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int numsSize = nums.size();
        k %= numsSize;
        reverse(nums, 0, numsSize - k - 1);
        reverse(nums, numsSize - k, numsSize - 1);
        reverse(nums, 0, numsSize - 1);
    }
};


