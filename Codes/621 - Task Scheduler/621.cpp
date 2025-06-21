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
    priority_queue<int> pq;
    for (auto [c, ct] : mp)
        pq.push(ct);

    int time = 0;
    while (!pq.empty())
    {
        int cycle = n + 1;
        vector<int> temp;
        int ct = 0;
        while (cycle-- && !pq.empty())
        {
            if (pq.top() > 1)
                temp.push_back(pq.top() - 1);
            pq.pop();
            ct++;
        }
        for (auto &x : temp)
            pq.push(x);
        time += (pq.empty() ? ct : n + 1);
    }
    return time;
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