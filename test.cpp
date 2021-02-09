#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int compare(const pair<float, int> p1, const pair<float, int> p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<pair<float, int>> failRates(N + 1);
    vector<int> count(N + 2);

    for (int i = 0; i < stages.size(); i++)
    {
        count[stages[i]]++;
    }

    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        failRates[i] = pair<float, int>((float)count[i] / (float)(stages.size() - sum), i);
        sum += count[i];
    }

    sort(failRates.begin() + 1, failRates.end(), compare);

    for(int i = 1 ; i < failRates.size(); i++){
        printf("%.1f %d\n", failRates[i].first, failRates[i].second);
    }

    for (int i = 1; i <= N; i++)
    {
        answer.push_back(failRates[i].second);
    }

    return answer;
}

int main()
{
    int n = 4;
    vector<int> stages = {4,4,4,4,4};
    vector<int> v = solution(n, stages);

    for (int i = 0; i < v.size(); i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}