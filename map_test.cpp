#include <iostream>
#include <map>
using namespace std;

int main(void) 
{
    map<int,int> i_map;
    map<int,double> d_map;
    map<int, string> s_map;

    cout << i_map[0] << endl;
    cout << d_map[0] << endl;
    cout << s_map[0] << endl; 

    return 0;
}