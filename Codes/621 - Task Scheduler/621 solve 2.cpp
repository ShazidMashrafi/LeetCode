#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int leastInterval(vector<char> &tasks, int n)
{
    map<char, int> mp;
    for (auto &x : tasks)
        mp[x]++;
    int mx = 0;
    for (auto [c, ct] : mp)
        mx = max(mx, ct);
    int time = (mx - 1) * (n + 1);
    for (auto [x, ct] : mp)
        if (ct == mx)
            time++;
    return max((int)tasks.size(), time);
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<char> tasks(m);
    for (int i = 0; i < m; i++)
        cin >> tasks[i];

    cout << leastInterval(tasks, n) << endl;

    return 0;
}