/*
������Դ��
https://leetcode.cn/problems/sort-the-people/
���
˼·������Hello�㷨 
*/
/*
�Զ������� 
*/
class Item{
    public:
    int index;
    int height;
    Item(int index, int height): index(index), height(height){}
};
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<Item> res;
        for(int i = 0; i < heights.size(); i ++){
            res.push_back(Item(i, heights[i]));
        }
        sort(res.begin(), res.end(),[](Item &a, Item &b){return a.height > b.height;});
        vector<string> ans;
        for(auto &item : res){
            ans.push_back(names[item.index]);
        }
        return ans;
    }
};


/*
��΢�Ż���һ��� 
*/
class Item{
    public:
    string name;
    int height;
    Item(string name, int height): name(name), height(height){}
};
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<Item> items;
        for(int i = 0; i < heights.size(); i ++){
            items.push_back(Item(names[i], heights[i]));
        }
        sort(items.begin(), items.end(),[](Item &a, Item &b){return a.height > b.height;});
        vector<string> res;
        for(auto &item : items){
            res.push_back(item.name);
        }
        return res;
    }
};
