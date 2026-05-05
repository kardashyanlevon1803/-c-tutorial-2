#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    int year;

    Book(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }

    void print() {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year << endl;
    }
};

void addBook(vector<Book>& books, string title, string author, int year) {
    books.push_back(Book(title, author, year));
    cout << "Book added!" << endl;
}

void removeByTitle(vector<Book>& books, string title) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i].title == title) {
            books.erase(books.begin() + i);
            cout << "Book removed!" << endl;
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void removeByAuthor(vector<Book>& books, string author) {
    int count = 0;
    for (int i = 0; i < books.size(); i++) {
        if (books[i].author == author) {
            books.erase(books.begin() + i);
            i--;
            count++;
        }
    }
    if (count > 0) {
        cout << "Removed " << count << " book(s)!" << endl;
    } else {
        cout << "Books not found!" << endl;
    }
}

void printAll(vector<Book>& books) {
    if (books.size() == 0) {
        cout << "No books!" << endl;
        return;
    }
    for (int i = 0; i < books.size(); i++) {
        books[i].print();
    }
}

int main() {
    vector<Book> books;

    addBook(books, "The C++ Programming Language", "Bjarne Stroustrup", 1985);
    addBook(books, "Clean Code", "Robert Martin", 2008);
    addBook(books, "Design Patterns", "Gang of Four", 1994);
    addBook(books, "Effective C++", "Scott Meyers", 1992);

    cout << endl << "=== All books ===" << endl;
    printAll(books);

    cout << endl << "=== Remove by title: Clean Code ===" << endl;
    removeByTitle(books, "Clean Code");
    printAll(books);

    cout << endl << "=== Remove by author: Scott Meyers ===" << endl;
    removeByAuthor(books, "Scott Meyers");
    printAll(books);

    return 0;
}