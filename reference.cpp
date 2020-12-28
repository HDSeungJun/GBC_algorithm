#include <iostream>
using namespace std;

void print_data(int& arr);

int main(void) 
{
    int a = 5;
    int& r_a = a;   // a의 참조자로 r_a를 선언

    cout << r_a << endl; // 5 출력
    r_a = 10; // r_a의 값을 10으로 변경, r_a는 a의 별명과 같으므로 a 역시 값 변경 
    cout << a << endl; // 10 출력

    return 0;
}