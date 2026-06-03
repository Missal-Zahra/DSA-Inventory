#include<iostream>
using namespace std;

class MaxHeap
{
    int heap[100];
    int size;

public:

    MaxHeap()
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

            if(heap[parent] < heap[i])
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
        cout<<"Heap: ";

        for(int i=0;i<size;i++)
        {
            cout<<heap[i]<<" ";
        }

        cout<<endl;
    }
};

int main()
{
    MaxHeap h;

    h.insert(10);
    h.insert(50);
    h.insert(30);
    h.insert(80);
    h.insert(60);
    h.insert(20);

    return 0;
}