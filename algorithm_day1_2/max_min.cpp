#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main(void) 
{
    vector<int> vec;
    vector<int>::iterator iter;

    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution<int> dis(0, 99);
    for(int i=0; i<10; i++)
        vec.push_back(dis(gen));

    for(iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    cout << "Max: " << *max_element(vec.begin(), vec.end()) << endl;
    cout << "Min: " << *min_element(vec.begin(), vec.end()) << endl;

    return 0;
}