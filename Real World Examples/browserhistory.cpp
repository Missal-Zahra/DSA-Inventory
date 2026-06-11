#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string website;
    Node* next;
    Node* prev;

    Node(string site)
    {
        website = site;
        next = NULL;
        prev = NULL;
    }
};

class BrowserHistory
{
private:
    Node* current;

public:
    BrowserHistory(string homepage)
    {
        current = new Node(homepage);
    }

    void visit(string site)
    {
        Node* newPage = new Node(site);

        current->next = NULL;

        newPage->prev = current;
        current->next = newPage;
        current = newPage;

        cout << "Visited: " << site << endl;
    }

    void back()
    {
        if (current->prev == NULL)
        {
            cout << "No previous page." << endl;
            return;
        }

        current = current->prev;
        cout << "Current Page: " << current->website << endl;
    }

    void forward()
    {
        if (current->next == NULL)
        {
            cout << "No next page." << endl;
            return;
        }

        current = current->next;
        cout << "Current Page: " << current->website << endl;
    }

    void showCurrent()
    {
        cout << "Current Page: " << current->website << endl;
    }
};

int main()
{
    BrowserHistory browser("google.com");

    browser.showCurrent();

    browser.visit("github.com");
    browser.visit("stackoverflow.com");
    browser.visit("youtube.com");

    cout << "\nGoing Back...\n";
    browser.back();
    browser.back();

    cout << "\nGoing Forward...\n";
    browser.forward();

    cout << "\nCurrent Status:\n";
    browser.showCurrent();

    return 0;
}