#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) 
{
    vector<int> vec;
    vector<int>::iterator iter;

    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(5);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(1);
    vec.push_back(8);
    vec.push_back(4);
    vec.push_back(3);

    for(iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for(iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    return 0;
}