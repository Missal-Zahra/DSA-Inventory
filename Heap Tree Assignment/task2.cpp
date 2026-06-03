#include <iostream>
using namespace std;

int main()
{
    int heap[] = {90,70,80,40,60,50,30};

   
    int index50 = 5;
    int parentIndex = (index50 - 1) / 2;

    cout << "Parent of 50 = "
         << heap[parentIndex] << endl;

    
    int index70 = 1;
    int leftChild = 2 * index70 + 1;

    cout << "Left Child of 70 = "
         << heap[leftChild] << endl;

    
    int rightChild = 2 * index70 + 2;

    cout << "Right Child of 70 = "
         << heap[rightChild] << endl;

    return 0;
}