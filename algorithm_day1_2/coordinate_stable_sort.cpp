#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

typedef struct _cdnt 
{
    int x;
    int y;
} cdnt;

bool compare(cdnt i, cdnt j);

int main(void) 
{
    cdnt m_cdnt[10];

    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution<int> dis(0, 99);

    for(int i=0; i<10; i++)
    {
        m_cdnt[i].x = dis(gen);
        m_cdnt[i].y = dis(gen); 
    }

    for(int i=0; i<10; i++)
        cout << "x: " << m_cdnt[i].x << ", " << "y: " << m_cdnt[i].y << endl;
    cout  << endl;

    cout << "Sort:" << endl;
    stable_sort(m_cdnt, m_cdnt+10, compare);

    for(int i=0; i<10; i++)
        cout << "x: " << m_cdnt[i].x << ", " << "y: " << m_cdnt[i].y << endl;
        cout << endl;

    return 0;
}

bool compare(cdnt i, cdnt j)
{
    return i.y > j.y;
}