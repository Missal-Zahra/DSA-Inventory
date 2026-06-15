#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Order
{
    int orderId;
    string customerName;
    string foodItem;
};

int main()
{
    queue<Order> orders;

    orders.push({101, "Ali", "Burger"});
    orders.push({102, "Sara", "Pizza"});
    orders.push({103, "Ahmed", "Fries"});
    orders.push({104, "Ayesha", "Zinger"});

    cout << "=== Incoming Orders ===\n\n";

    while (!orders.empty())
    {
        Order current = orders.front();

        cout << "Delivering Order #" << current.orderId << endl;
        cout << "Customer: " << current.customerName << endl;
        cout << "Item: " << current.foodItem << endl;
        cout << "Status: Delivered\n\n";

        orders.pop();
    }

    cout << "All orders completed.\n";

    return 0;
}