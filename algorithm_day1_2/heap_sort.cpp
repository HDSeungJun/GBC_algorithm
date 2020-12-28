#include <iostream>
#include <queue>
#include <random>
#include <list>
using namespace std;

int main(void)
{
    priority_queue<int> pq;
    list<int> li;
    list<int>::iterator iter;

    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution<int> dis(0, 99);

    for(int i=0; i<10; i++)
        pq.push(dis(gen));

    while(!pq.empty())
    {
        cout << pq.top() << " ";
        li.push_front(pq.top());
        pq.pop();
    }
    cout << "\n" << endl;

    for(iter=li.begin(); iter!=li.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    return 0;
}