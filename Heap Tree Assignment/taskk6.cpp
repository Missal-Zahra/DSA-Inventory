#include<iostream>
using namespace std;

class MaxHeap
{
    int heap[100];
    int size;

public:

    MaxHeap()
    {
        size=5;

        heap[0]=80;
        heap[1]=60;
        heap[2]=30;
        heap[3]=10;
        heap[4]=50;
    }

    void deleteRoot()
    {
        cout<<"Deleting Root = "<<heap[0]<<endl;

        heap[0]=heap[size-1];
        size--;

        int i=0;

        while(true)
        {
            int left=2*i+1;
            int right=2*i+2;
            int largest=i;

            if(left<size && heap[left]>heap[largest])
                largest=left;

            if(right<size && heap[right]>heap[largest])
                largest=right;

            if(largest!=i)
            {
                cout<<"Swap "
                    <<heap[i]
                    <<" and "
                    <<heap[largest]
                    <<endl;

                swap(heap[i],heap[largest]);

                i=largest;
            }
            else
                break;
        }
    }

    void display()
    {
        for(int i=0;i<size;i++)
            cout<<heap[i]<<" ";

        cout<<endl;
    }
};

int main()
{
    MaxHeap h;

    h.deleteRoot();

    h.display();
}