#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int id;
    int mark;
    Student(string name, int id, int mark)
    {
        this->name = name;
        this->mark = mark;
        this->id = id;
    }
};

class compare
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.mark > b.mark)
        {
            return true;
        }
        else if (a.mark < b.mark)
        {
            return false;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<Student, vector<Student>, compare> pq;
    for (int i = 0; i < n; i++)
    {
        string name;
        int id, mark;
        cin >> name >> id >> mark;
        Student obj(name, id, mark);
        pq.push(obj);
    }
    while (!pq.empty())
    {
        cout << pq.top().name << " " << pq.top().id << " " << pq.top().mark << endl;
        pq.pop();
    }

    return 0;
}
