#include <iostream>
using namespace std;

int main(void) 
{
    cout << "int의 범위: " << numeric_limits<int>::min() << " ~ " << numeric_limits<int>::max() << endl;
    cout << "long long의 범위: " <<  numeric_limits<long long>::min() << " ~ " << numeric_limits<long long>::max() << endl;

    return 0;
}