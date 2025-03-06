#include <iostream>
using namespace std;

class Level
{
private:
    string level;

public:
    Level(string level) : level(level) {}

    string getlevel()
    {
        return level;
    }
};

class Game
{
private:
    string title;
    string genre;
    Level levels[3];

public:
    Game(string title, string genre, string level1, string level2, string level3) : title(title), genre(genre), levels{Level(level1), Level(level2), Level(level3)} {}

    void display()
    {
        cout << "Game Title: " << title << endl;
        cout << "Game Genre: " << genre << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Level " << (i + 1) << " : " << levels[i].getlevel() << endl;
        }
    }
};

int main()
{
    Game G1("GTA-V", "Story Mode", "Easy", "Medium", "Hard");
    G1.display();

    return 0;
}
