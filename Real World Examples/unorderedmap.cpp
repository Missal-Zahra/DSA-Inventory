#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

unordered_map<string, string> urlDatabase;

string generateCode()
{
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string code = "";

    for (int i = 0; i < 6; i++)
    {
        code += chars[rand() % chars.length()];
    }

    return code;
}

void shortenURL()
{
    string longURL;

    cout << "\nEnter Long URL: ";
    cin.ignore();
    getline(cin, longURL);

    string shortCode = generateCode();

    while (urlDatabase.find(shortCode) != urlDatabase.end())
    {
        shortCode = generateCode();
    }

    urlDatabase[shortCode] = longURL;

    cout << "\nShort URL: https://mini.ly/" << shortCode << endl;
}

void openURL()
{
    string code;

    cout << "\nEnter Short Code: ";
    cin >> code;

    if (urlDatabase.find(code) != urlDatabase.end())
    {
        cout << "\nOriginal URL:\n";
        cout << urlDatabase[code] << endl;
    }
    else
    {
        cout << "\nURL not found.\n";
    }
}

void showAll()
{
    if (urlDatabase.empty())
    {
        cout << "\nNo URLs stored.\n";
        return;
    }

    cout << "\nStored URLs\n\n";

    for (auto item : urlDatabase)
    {
        cout << "https://mini.ly/" << item.first << endl;
        cout << item.second << endl;
        cout << "-----------------------------\n";
    }
}

int main()
{
    srand(time(0));

    int choice;

    do
    {
        cout << "\n===== Mini URL Shortener =====\n";
        cout << "1. Shorten URL\n";
        cout << "2. Open URL\n";
        cout << "3. Show All URLs\n";
        cout << "4. Exit\n";

        cout << "\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            shortenURL();
            break;

        case 2:
            openURL();
            break;

        case 3:
            showAll();
            break;

        case 4:
            cout << "\nGoodbye!\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 4);

    return 0;
}