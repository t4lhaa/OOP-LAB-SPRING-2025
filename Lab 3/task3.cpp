
#include <iostream>
#include <string>

using namespace std;

class Library{
private:
    string books[50];
    string borrowed[50];
    int bookCount;
    int borrowedCount;

public:
    Library()
    {
        bookCount = 0;
        borrowedCount = 0;
    }

    void adding(string book)
    {
        if (bookCount < 50)
        {
            books[bookCount] = book;
            bookCount++;
            cout << "Book added: " << book << endl;
        }
        else
        {
            cout << "Library is full!\n";
        }
    }

    void borrowing(string book)
    {
        for (int i = 0; i < bookCount; i++)
        {
            if (books[i] == book)
            {
                borrowed[borrowedCount] = book;
                borrowedCount++;
                for (int j = i; j < bookCount - 1; j++)
                {
                    books[j] = books[j + 1];
                }
                bookCount--;
                cout << "Book borrowed: " << book << "\n";
                return;
            }
        }
        cout << "Book not available.\n";
    }

    void returning(string book)
    {
        for (int i = 0; i < borrowedCount; i++)
        {
            if (borrowed[i] == book)
            {
                books[bookCount++] = book;
                for (int j = i; j < borrowedCount - 1; j++)
                {
                    borrowed[j] = borrowed[j + 1];
                }
                borrowedCount--;
                cout << "Book returned: " << book << "\n";
                return;
            }
        }
        cout << "Book not in borrowed list.\n";
    }

    void display()
    {
        cout << "Books Available:\n";
        for (int i = 0; i < bookCount; i++)
        {
            cout << "-> " << books[i] << endl;
        }
        cout << "Books Borrowed:\n";
        for (int i = 0; i < borrowedCount; i++)
        {
            cout << "-> " << borrowed[i] << endl;
        }
    }
};

int main()
{
    Library library;
    int choice;
    string book;

    do
    {
        cout << "\n1. Add Book"<<endl;
        cout<<"2.Borrow Book"<<endl;
        cout<<"3.Return Book"<<endl;
        cout<<"4.View Books"<<endl;
        cout<<"5.Exit"<<endl;
        cout<<"Enter Your Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter book name: ";
            getline(cin, book);
            library.adding(book);
            break;
        case 2:
            cout << "Enter book to borrow: ";
            getline(cin, book);
            library.borrowing(book);
            break;
        case 3:
            cout << "Enter book to return: ";
            getline(cin, book);
            library.returning(book);
            break;
        case 4:
            library.display();
            break;
        case 5:
            cout << "Thank You!!!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
