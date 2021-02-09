#include <string>
#include <vector>
#include <iostream>
using namespace std;

void lower(string &id)
{
    for (int i = 0; i < id.size(); i++)
    {
        if ('A' <= id[i] && id[i] <= 'Z')
        {
            id[i] += 32;
        }
    }
}

string removeSpecialCharacter(string &id)
{
    string s = "";
    for (int i = 0; i < id.size(); i++)
    {
        if (('a' <= id[i] && id[i] <= 'z') ||
            ('0' <= id[i] && id[i] <= '9') ||
            (id[i] == '-' || id[i] == '_' || id[i] == '.'))
        {
            s.push_back(id[i]);
        }
    }
    return s;
}

string removeContinuosDot(string &id)
{
    string s = "";
    bool dotFlag = false;
    for (int i = 0; i < id.size(); i++)
    {
        if (id[i] == '.'){
            if(!dotFlag){
                dotFlag = true;
                s.push_back(id[i]);
            } else {
                continue;
            }
        } else {
            s.push_back(id[i]);
            dotFlag = false;
        }
    }
    return s;
}

string removeStartEndDot(string &id)
{
    string s = "";
    int start = (id[0] == '.') ? 1 : 0;
    int end = (id[id.size() - 1] == '.') ? id.size() - 1 : id.size();
    for (; start < end; start++)
    {
        s.push_back(id[start]);
    }
    return s;
}

string solution(string new_id)
{
    //1
    lower(new_id);
    //2
    new_id = removeSpecialCharacter(new_id);
    //3
    new_id = removeContinuosDot(new_id);
    //4
    new_id = removeStartEndDot(new_id);
    //5
    if (new_id.size() == 0)
    {
        new_id = 'a';
    }
    //6
    if (new_id.size() >= 16)
        new_id = new_id.substr(0, 15);
    if (new_id[new_id.size() - 1] == '.')
        new_id = new_id.substr(0, 14);
    //7
    if (new_id.size() <= 2)
    {
        char last = new_id[new_id.size() - 1];
        while (new_id.size() != 3)
        {
            new_id.push_back(last);
        }
    }
    return new_id;
}

int main()
{
    string s = "...!@BaT#*..y.abcdefghijklm";
    cout << s << endl;
    cout << solution(s) << endl;
    //cout << (int)'B' << endl;
    //cout << (int)'b' << endl;
    return 0;
}