#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main(void) 
{
    vector<int> vec;
    vector<int>::iterator iter;
    int arr[10];

    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution<int> dis(0, 99);
    for(int i=0; i<10; i++)
    {
        arr[i] = dis(gen);
        vec.push_back(dis(gen));
    }

    cout << "Arr:\t";
    for(int i=0; i<10; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Vecot:\t";
    for(iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    reverse(arr, arr+10);
    reverse(vec.begin(), vec.end());

    cout << "\nReverse:" << endl;
    cout << "Arr:\t";
    for(int i=0; i<10; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Vecot:\t";
    for(iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;
    
    return 0;
}