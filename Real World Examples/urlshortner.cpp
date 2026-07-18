#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

unordered_map<string, string> urlMap;

string generateShortCode()
{
    const string chars =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

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

    string shortCode;

    do
    {
        shortCode = generateShortCode();
    }
    while (urlMap.find(shortCode) != urlMap.end());

    urlMap[shortCode] = longURL;

    cout << "\nShort URL Created Successfully!\n";
    cout << "https://tiny.local/" << shortCode << endl;
}

void openURL()
{
    string code;

    cout << "\nEnter Short Code: ";
    cin >> code;

    if (urlMap.find(code) == urlMap.end())
    {
        cout << "\nURL not found.\n";
        return;
    }

    cout << "\nOriginal URL:\n";
    cout << urlMap[code] << endl;
}

void showDatabase()
{
    if (urlMap.empty())
    {
        cout << "\nNo URLs available.\n";
        return;
    }

    cout << "\nStored URLs\n";
    cout << "----------------------------\n";

    for (auto &item : urlMap)
    {
        cout << item.first << " -> " << item.second << endl;
    }
}

int main()
{
    srand(time(0));

    int choice;

    do
    {
        cout << "\n====== Mini URL Shortener ======\n";
        cout << "1. Shorten URL\n";
        cout << "2. Open URL\n";
        cout << "3. Show Database\n";
        cout << "4. Exit\n";

        cout << "\nEnter Choice: ";
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
            showDatabase();
            break;

        case 4:
            cout << "\nGoodbye!\n";
            break;

        default:
            cout << "\nInvalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}