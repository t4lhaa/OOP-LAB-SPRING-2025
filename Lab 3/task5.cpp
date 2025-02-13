#include <iostream>
#include <string>

using namespace std;

class MusicPlayer{
private:
    string playlist[50];
    string currentPlayingSong;
    int count;

public:
    MusicPlayer()
    {
        count = 0;
        currentPlayingSong = "None";
    }

    void add(string song)
    {
        if (count < 50){
            playlist[count] = song;
            count++;
            cout << song << " added.\n";
        }
        else
        {
            cout << "Playlist is full!!!!!!\n";
        }
    }

    void remove(string song)
    {
        int found = 0;
        for (int i = 0; i < count; i++)
        {
            if (playlist[i] == song)
            {
                for (int j = i; j < count - 1; j++)
                {
                    playlist[j] = playlist[j + 1];
                }
                count--;
                found = 1;
                cout << song << " removed from the playlist.\n";
                break;
            }
        }
        if (found==0)
        {
            cout << "Song not found!\n";
        }
    }

    void play(string song)
    {
        int found = 0;
        for (int i = 0; i < count; i++)
        {
            if (playlist[i] == song)
            {
                currentPlayingSong = song;
                found = 1;
                cout << "Now playing: " << song << "\n";
                break;
            }
        }
        if (found==0)
        {
            cout << "Song not found!\n";
        }
    }

    void Playlist()
    {
        cout << "\nPlaylist:\n";
        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << ". " << playlist[i] << "\n";
        }
    }
};

int main()
{
    MusicPlayer player;
    int choice;
    string song;

    do
    {
        cout << "\n1. Add Song\n";
        cout<<"2. Remove Song\n";
        cout<<"3. Play Song\n";
        cout<<"4. Show Playlist\n";
        cout<<"5. Exit\n";
        cout<<"Enter Your Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter song name: ";
            getline(cin, song);
            player.add(song);
            break;
        case 2:
            cout << "Enter song name: ";
            getline(cin, song);
            player.remove(song);
            break;
        case 3:
            cout << "Enter song name: ";
            getline(cin, song);
            player.play(song);
            break;
        case 4:
            player.Playlist();
            break;
        case 5:
            cout << "Thank You for Listening.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
