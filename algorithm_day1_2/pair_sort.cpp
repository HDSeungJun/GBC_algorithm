#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <random>
using namespace std;

int main(void) 
{
    vector <pair<int, int> > p;
    vector <pair<int, int> >::iterator iter;

    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution<int> dis(0, 99);

    for(int i=0; i<10; i++)
        p.push_back(make_pair(dis(gen), dis(gen)));

    for(iter = p.begin(); iter != p.end(); iter++)
        cout << iter->first  << " " << iter->second << endl;

    sort(p.begin(), p.end());

    cout << endl;
    cout << "Sort:" << endl;
    for(iter = p.begin(); iter != p.end(); iter++)
        cout << iter->first  << " " << iter->second << endl;
    

    return 0;
}