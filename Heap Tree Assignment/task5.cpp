#include<iostream>
using namespace std;

class MinHeap
{
    int heap[100];
    int size;

public:

    MinHeap()
    {
        size = 0;
    }

    void insert(int value)
    {
        int i = size;

        heap[size] = value;
        size++;

        while(i > 0)
        {
            int parent = (i - 1) / 2;

            if(heap[parent] > heap[i])
            {
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else
            {
                break;
            }
        }

        display();
    }

    void display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<heap[i]<<" ";
        }

        cout<<endl;
    }
};

int main()
{
    MinHeap h;

    h.insert(45);
    h.insert(20);
    h.insert(35);
    h.insert(10);
    h.insert(25);
    h.insert(15);

    return 0;
}