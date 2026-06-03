#include<iostream>
using namespace std;

int main()
{
    int heap[]={90,70,80,40,60,50,30};

    cout<<"Parent of index 5 = "
        <<heap[(5-1)/2]<<endl;

    cout<<"Left child of index 2 = "
        <<heap[2*2+1]<<endl;

    cout<<"Right child of index 2 = "
        <<heap[2*2+2]<<endl;

    return 0;
}