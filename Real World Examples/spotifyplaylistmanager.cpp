#include <iostream>
#include <string>
using namespace std;

struct Song
{
    string title;
    Song* next;

    Song(string name)
    {
        title = name;
        next = NULL;
    }
};

class Playlist
{
private:
    Song* head;

public:
    Playlist()
    {
        head = NULL;
    }

    void addSong(string name)
    {
        Song* newSong = new Song(name);

        if (head == NULL)
        {
            head = newSong;
            return;
        }

        Song* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newSong;
    }

    void removeSong(string name)
    {
        if (head == NULL)
        {
            return;
        }

        if (head->title == name)
        {
            Song* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Song* current = head;

        while (current->next != NULL)
        {
            if (current->next->title == name)
            {
                Song* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }

            current = current->next;
        }
    }

    void displayPlaylist()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        Song* temp = head;

        cout << "\nPlaylist:\n";

        while (temp != NULL)
        {
            cout << "🎵 " << temp->title << endl;
            temp = temp->next;
        }
    }

    int totalSongs()
    {
        int count = 0;

        Song* temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
};

int main()
{
    Playlist myPlaylist;

    myPlaylist.addSong("Blinding Lights");
    myPlaylist.addSong("Starboy");
    myPlaylist.addSong("Perfect");
    myPlaylist.addSong("Heat Waves");

    myPlaylist.displayPlaylist();

    cout << "\nTotal Songs: "
         << myPlaylist.totalSongs() << endl;

    cout << "\nRemoving Perfect...\n";

    myPlaylist.removeSong("Perfect");

    myPlaylist.displayPlaylist();

    cout << "\nTotal Songs: "
         << myPlaylist.totalSongs() << endl;

    return 0;
}