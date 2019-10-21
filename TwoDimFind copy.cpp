#include <iostream>
#include <vector>
using namespace std;
//题目描述
//在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int max_len = array[0].size();
        for(int i=0; i < array.size(); i++){
            vector<int> temp = array[i];
            for (int j=0; j < max_len; j++){
                if (array[i][j] == target)
                    return true;
                else if (array[i][j] > target){
                    max_len = j;
                    break;
                }
            }
        }
        return false;
    }
    bool Find2(int target, vector<vector<int> > array) {
        int i = 0;
        int j = array[0].size() - 1;
        while(i < array.size() && j >= 0 ){
            if(array[i][j] == target){
                return true;
            }
            else if (array[i][j] > target)
                j--;
            else if (array[i][j] < target)
                i++;
        }
        return false;
    }
};

int main(){
    Solution *so = new Solution();
    int value[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    vector<vector<int> > array;
    vector<int> temp;
    for(int i=0; i < 4; i ++){
        for (int j=0; j < 4; j ++){
            temp.push_back(value[i][j]);
        }
        array.push_back(temp);
        temp.clear();
    }
    so->Find2(7, array);
    return 0;
}
