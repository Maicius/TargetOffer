#include<iostream>
#include<queue>
using namespace std;
class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        cnt[ch - '\0']++;
        if (cnt[ch - '\0'] == 1) {
            data.push(ch);
        }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while (!data.empty() && cnt[data.front()] > 1) data.pop();
        if (data.empty()) return '#';
        return data.front();
    }
    Solution() {
        memset(cnt, 0, sizeof(cnt));
    }
private:
    queue<char> data;
    unsigned cnt[256];
};

int main() {
    Solution *so = new Solution();
    so->Insert('g');
    so->Insert('o');
    so->Insert('o');
    so->Insert('g');
    so->Insert('l');
    so->Insert('e');
    cout << so->FirstAppearingOnce() << endl;
}