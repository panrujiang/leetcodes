/*
��Ŀ��Դ��
https://leetcode.cn/problems/merge-sorted-array/description/
���
https://blog.csdn.net/weixin_64904163/article/details/126756323?spm=1001.2014.3001.5502
https://leetcode.cn/problems/merge-sorted-array/solutions/666608/he-bing-liang-ge-you-xu-shu-zu-by-leetco-rrb0/ 
*/
/*
����˫ָ��
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1,p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while(p1 >= 0 || p2 >= 0){
            if(p1 == -1){
                cur = nums2[p2 --];
            }else if(p2 == -1){
                cur = nums1[p1 --];
            }else if(nums1[p1] > nums2[p2]){
                cur = nums1[p1 --];
            }else{
                cur = nums2[p2 --];
            }
            nums1[tail --] = cur;
        }
    }
};

/*
�ҵĽⷨ 
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tail = m + n -1;
        int right1 = m - 1, right2 = n - 1;
        for(;tail >= 0; tail --){
            if(right1 >=0 && right2 >= 0){
                if(nums1[right1] > nums2[right2]){
                    nums1[tail] = nums1[right1 --];
                }else {
                    nums1[tail] = nums2[right2 --];
                }
                }else if(right1 == -1){
                        nums1[tail] = nums2[right2 --];
                    }else{
                        nums1[tail] = nums1[right1 --];
                    }
            }
    }
};

/*
һ�ֺ÷��� 
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int old1 = m-1;//������1���±�old1
    int old2 = n-1;//������2���±�old2
    int new = nums1Size-1;//������1���±�
    //�鲢����˼�룬�����ܴ�ǰ����ʼ���򣬶�Ҫ�������Ӻ���ǰ������Ϊ�Ḳ��δ����Ԫ�ء�
    //����һ��������±�С��0��˵��ĳһ��������Ԫ���Ѿ�ȫ���ƶ����������ˣ�����ѭ��
    while(old1 >= 0 && old2 >= 0){
        if(nums1[old1] > nums2[old2]){
            nums1[new] = nums1[old1];
            --old1;
            --new;
        }
        else{
            nums1[new] = nums2[old2];
            --old2;
            --new;
        }
    }
    //��Ϊ��������Ǿ�����1��ֻ�������2��ȫ��Ԫ���ƶ��������������ˣ���ֻ����old2
    while(old2 >= 0){
        nums1[new] = nums2[old2];
        --new;
        --old2;
    }
}
/*
˫ָ��򻯰� 
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int up1 = m - 1, up2 = nums1.size() - 1, below = n -1;
        while(up1 >= 0 && below >= 0){
           nums1[up2 --] = (nums1[up1] > nums2[below] ? nums1[up1 --] : nums2[below --]);
        }
        while(below >= 0){
            nums1[up2 --] = nums2[below --];
        }
    }
};

