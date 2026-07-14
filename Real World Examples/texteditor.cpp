#include <iostream>
#include <stack>
#include <string>

using namespace std;
stack<string> undoStack;
stack<string> redoStack;
string currentText = "";

void typeText()
{
    string text;

    cout << "\nEnter text:";
    cin.ignore();
    getline(cin, text);

    undoStack.push(currentText);
    currentText += text;

    while (!redoStack.empty())
        redoStack.pop();

    cout << "\nText Added Successfully.\n";
}

void undo()
{
    if (undoStack.empty())
    {
        cout << "\nNothing to undo.\n";
        return;
    }

    redoStack.push(currentText);
    currentText = undoStack.top();
    undoStack.pop();

    cout << "\nUndo Successful.\n";
}

void redo()
{
    if (redoStack.empty())
    {
        cout << "\nNothing to redo.\n";
        return;
    }

    undoStack.push(currentText);
    currentText = redoStack.top();
    redoStack.pop();

    cout << "\nRedo Successful.\n";
}

void showText()
{
    cout << "\nCurrent Text:\n";
    cout << "\"" << currentText << "\"" << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n====== Mini Text Editor ======\n";
        cout << "1. Type Text\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "4. Show Text\n";
        cout << "5. Exit\n";

        cout << "\nChoice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            typeText();
            break;

        case 2:
            undo();
            break;

        case 3:
            redo();
            break;

        case 4:
            showText();
            break;

        case 5:
            cout << "\nGoodbye!\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 5);

    return 0;
}