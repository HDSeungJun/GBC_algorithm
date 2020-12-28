#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

void print_data(vector<int> my_vector, list<int> my_list, set<int> my_set, map<int, int> my_map);

int main(void) 
{
    // 변수 선언
    vector<int> my_vector;
    list<int> my_list;
    set<int> my_set;
    map<int, int> my_map;

    // 값 삽입
    for(int i=0; i<10; i++)
    {
        my_vector.push_back(i);
        my_list.push_back(i);
        my_set.insert(i);
        my_map.insert(make_pair(i, i));
    }

    // 삽입 출력
    cout << "Insert: " << endl;
    print_data(my_vector, my_list, my_set, my_map);

    // 값 수정
    // vector 수정
    my_vector[5] = 100;

    // list 수정
    list<int>::iterator l_iter;
    for(l_iter=my_list.begin(); l_iter!=my_list.end(); l_iter++)
    {
        if(*l_iter == 5)
            *l_iter =100;
    } 

    // set 수정
    my_set.erase(5);
    my_set.insert(100);

    // map 수정
    my_map.erase(5);
    my_map.insert(make_pair(100,100));

    // 수정 출력
    cout << "Modify: " << endl;
    print_data(my_vector, my_list, my_set, my_map); 

    // 값 삭제 
    // vector 삭제
    vector<int>::iterator v_iter;
    v_iter = my_vector.begin() + 5;
    my_vector.erase(v_iter);

    // list 삭제
    my_list.remove(100);

    // set 삭제
    my_set.erase(100);

    // map 삭제
    my_map.erase(100);

    // 삭제 출력
    cout << "Delete:" << endl;
    print_data(my_vector, my_list, my_set, my_map);

    return 0; 
}

// 값 출력 
void print_data(vector<int> my_vector, list<int> my_list, set<int> my_set, map<int, int> my_map)
{
    // vector 출력
    cout << "Vector:\t";
    for(int i=0; i<10; i++)
        cout << my_vector[i] << " ";
    cout << endl;

    // list 출력
    list<int>::iterator l_iter;
    cout << "List:\t";
    for(l_iter=my_list.begin(); l_iter!=my_list.end(); l_iter++)
        cout << *l_iter << " ";
    cout << endl;

    // set 출력
   set<int>::iterator s_iter;
   cout << "Set:\t";
   for(s_iter=my_set.begin(); s_iter!=my_set.end(); s_iter++)
        cout << *s_iter << " ";
    cout << endl;

    // map 출력
    map<int, int>::iterator m_iter;
    cout << "Map:\t";
    for(m_iter=my_map.begin(); m_iter!=my_map.end(); m_iter++)
        cout << m_iter->second << " ";
    cout << endl;

    cout << endl;
}

