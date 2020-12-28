#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
using namespace std;

void print_data(int* arr, vector<int> vec);

int main(void)
{
    //변수 선언
    int arr[10];
    vector<int> vec;

    //무작위 값 삽입
    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution<int> dis(0, 99);
    for(int i=0; i<10; i++)
    {
        arr[i] = dis(gen);
        vec.push_back(dis(gen));
    }
    cout << "Insert: " << endl;
    print_data(arr, vec);
    cout << endl;

    // sort
    sort(arr, arr+10);
    sort(vec.begin(), vec.end());
    cout << "Sort:" << endl;
    print_data(arr, vec);
    cout << endl;

    // binary search (두번째 값 검색)
    int temp_1 = arr[1];
    int temp_2 = vec[1];
    cout << "Binary search: " << endl;
    if(binary_search(arr, arr+10, temp_1))
       cout << temp_1 << "이(가) 존재함." << endl;
    else
       cout << temp_1 << "이(가) 존재하지 않음." << endl;  

    if(binary_search(vec.begin(), vec.end(), temp_2))
       cout << temp_2 << "이(가) 존재함." << endl;
    else
       cout << temp_2 << "이(가) 존재하지 않음." << endl;  
    cout << endl;

    // lower_bound 
    vector<int>::iterator up, low;
    cout << "Lower bound: " << endl;
    cout << "arr lower_bound: " << arr[lower_bound(arr, arr+10, temp_1)-arr] << endl;
    low = lower_bound(vec.begin(), vec.end(), temp_2);
    cout << "vector lower_bound: " << vec[low-vec.begin()]  << endl;
    cout << endl;

    // upper_bound  
    cout << "Upper bound: " << endl;
    cout << "arr upper_bound: " << arr[upper_bound(arr, arr+10, temp_1)-arr] << endl;
    low = upper_bound(vec.begin(), vec.end(), temp_2);
    cout << "vector upper_bound: " << vec[low-vec.begin()]  << endl;
    cout << endl; 


    return 0;
}

void print_data(int* arr, vector<int> vec) 
{
    for(int i=0; i<10; i++)
        cout << arr[i] << " ";

    cout << endl;

    vector<int>::iterator v_iter;
    for(v_iter=vec.begin(); v_iter!=vec.end(); v_iter++)
        cout << *v_iter << " ";

    cout << endl;
}