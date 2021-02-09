#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

void addSubSet(map<string, int> &m, string &s, int idx, string subStr)
{
    if (idx == s.size())
        return;

    string cur = subStr + s[idx];
    if (m.count(cur) == 0)
    {
        m[cur] = 1;
    }
    else
    {
        m[cur]++;
    }

    for (int i = idx + 1; i < s.size(); i++)
    {
        addSubSet(m, s, i, cur);
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    map<string, int> m;

    for (int i = 0; i < orders.size(); i++)
    {
        sort(orders[i].begin(), orders[i].end());
        for (int j = 0; j < orders[i].size(); j++)
        {
            addSubSet(m, orders[i], j, "");
        }
    }

    for(int i = 0 ; i < course.size(); i++){
        int maxCount = 0;
        for(map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++)
        {
            if(iter->first.size() == course[i])
            {
                maxCount = max(maxCount, iter->second);
            }
        }

        if(maxCount < 2) continue;

        for(map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++)
        {
            if(iter->first.size() == course[i] && iter->second == maxCount)
            {
                answer.push_back(iter->first);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    vector<string> orders = {
        "ABCFG",
        "AC",
        "CDE",
        "ACDE",
        "BCFG",
        "ACDEH"};

    vector<int> course = {2, 3, 4};

    vector<string> answer = solution(orders, course);

    cout << "===answer===" << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}