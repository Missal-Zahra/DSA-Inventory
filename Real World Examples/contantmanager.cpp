#include <iostream>
#include <string>
using namespace std;

struct Contact
{
    string name;
    string number;
    Contact *next;
};

Contact *head = NULL;

void addContact()
{
    Contact *newContact = new Contact;

    cout << "\nEnter Name: ";
    cin.ignore();
    getline(cin, newContact->name);

    cout << "Enter Number: ";
    getline(cin, newContact->number);

    newContact->next = NULL;

    if (head == NULL)
    {
        head = newContact;
    }
    else
    {
        Contact *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newContact;
    }

    cout << "\nContact Added Successfully!\n";
}

void displayContacts()
{
    if (head == NULL)
    {
        cout << "\nNo Contacts Found.\n";
        return;
    }

    Contact *temp = head;

    cout << "\n------ Contact List ------\n";

    while (temp != NULL)
    {
        cout << "Name   : " << temp->name << endl;
        cout << "Number : " << temp->number << endl;
        cout << "--------------------------\n";

        temp = temp->next;
    }
}

void searchContact()
{
    if (head == NULL)
    {
        cout << "\nNo Contacts Available.\n";
        return;
    }

    string searchName;

    cout << "\nEnter Name to Search: ";
    cin.ignore();
    getline(cin, searchName);

    Contact *temp = head;

    while (temp != NULL)
    {
        if (temp->name == searchName)
        {
            cout << "\nContact Found!\n";
            cout << "Name   : " << temp->name << endl;
            cout << "Number : " << temp->number << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "\nContact Not Found.\n";
}

void updateContact()
{
    string searchName;

    cout << "\nEnter Contact Name: ";
    cin.ignore();
    getline(cin, searchName);

    Contact *temp = head;

    while (temp != NULL)
    {
        if (temp->name == searchName)
        {
            cout << "Enter New Number: ";
            getline(cin, temp->number);

            cout << "\nContact Updated.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "\nContact Not Found.\n";
}

void deleteContact()
{
    if (head == NULL)
    {
        cout << "\nNo Contacts Available.\n";
        return;
    }

    string searchName;

    cout << "\nEnter Name to Delete: ";
    cin.ignore();
    getline(cin, searchName);

    if (head->name == searchName)
    {
        Contact *temp = head;
        head = head->next;

        delete temp;

        cout << "\nContact Deleted.\n";
        return;
    }

    Contact *current = head;

    while (current->next != NULL)
    {
        if (current->next->name == searchName)
        {
            Contact *temp = current->next;

            current->next = current->next->next;

            delete temp;

            cout << "\nContact Deleted.\n";
            return;
        }

        current = current->next;
    }

    cout << "\nContact Not Found.\n";
}

void countContacts()
{
    int count = 0;

    Contact *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "\nTotal Contacts: " << count << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n====== Contact Manager ======\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Update Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Count Contacts\n";
        cout << "7. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addContact();
            break;

        case 2:
            displayContacts();
            break;

        case 3:
            searchContact();
            break;

        case 4:
            updateContact();
            break;

        case 5:
            deleteContact();
            break;

        case 6:
            countContacts();
            break;

        case 7:
            cout << "\nGood Bye!\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 7);

    return 0;
}