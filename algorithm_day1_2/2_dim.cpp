#include <cstdio>
#include <vector>
#include <random>
using namespace std;

int main(void) 
{
    vector<vector<int> > vec;

    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution<int> dis(0, 99);

    for(int i=0; i<5; i++)
    {
        vector<int> temp;
        for(int j=0; j<5; j++)
            temp.push_back(dis(gen));
        vec.push_back(temp);
    }

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
            printf("%2d ", vec[i][j]);
        printf("\n");
    }
}