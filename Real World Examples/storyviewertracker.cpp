#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<string> viewedStories;

    viewedStories.push("Sara");
    viewedStories.push("Ahmed");
    viewedStories.push("Ayesha");
    viewedStories.push("Hamza");

    cout << "Recently Viewed Stories\n\n";

    while (!viewedStories.empty())
    {
        cout << viewedStories.top() << "'s story viewed" << endl;
        viewedStories.pop();
    }

    cout << "\nNo more stories left." << endl;

    return 0;
}