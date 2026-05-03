#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    bool isAvailable;

public:
    Book(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
        isAvailable = true;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    int getYear() {
        return year;
    }

    bool getIsAvailable() {
        return isAvailable;
    }

    void setAvailable(bool val) {
        isAvailable = val;
    }
};

class Reader {
private:
    string name;
    int cardNumber;
    vector<Book*> borrowedBooks;

public:
    Reader(string n, int card) {
        name = n;
        cardNumber = card;
    }

    string getName() {
        return name;
    }

    int getCardNumber() {
        return cardNumber;
    }

    void addBook(Book* b) {
        borrowedBooks.push_back(b);
    }

    void removeBook(int index) {
        borrowedBooks.erase(borrowedBooks.begin() + index);
    }

    void showBooks() {
        cout << "Books of reader " << name << ":" << endl;
        for (int i = 0; i < (int)borrowedBooks.size(); i++) {
            cout << "  - " << borrowedBooks[i]->getTitle() << endl;
        }
    }
};

class Library {
private:
    string name;
    vector<Book*> books;
    vector<Reader*> readers;

public:
    Library(string n) {
        name = n;
    }

    void addBook(Book* b) {
        books.push_back(b);
    }

    void registerReader(Reader* r) {
        readers.push_back(r);
    }

    void borrowBook(int bookIndex, int readerIndex) {
        if (books[bookIndex]->getIsAvailable()) {
            books[bookIndex]->setAvailable(false);
            readers[readerIndex]->addBook(books[bookIndex]);
            cout << readers[readerIndex]->getName() << " borrowed: ";
            cout << books[bookIndex]->getTitle() << endl;
        } else {
            cout << "Book is not available!" << endl;
        }
    }

    void showAllBooks() {
        cout << "All books in library " << name << ":" << endl;
        for (int i = 0; i < (int)books.size(); i++) {
            cout << i << ". " << books[i]->getTitle();
            if (books[i]->getIsAvailable()) {
                cout << " [available]" << endl;
            } else {
                cout << " [borrowed]" << endl;
            }
        }
    }
};

int main() {
    Library lib("City Library");

    Book* b1 = new Book("Kobzar", "Shevchenko", 1840);
    Book* b2 = new Book("Shadows of Forgotten Ancestors", "Kotsiubynsky", 1911);

    Reader* r1 = new Reader("Ivan Petrenko", 1001);
    Reader* r2 = new Reader("Maria Koval", 1002);

    lib.addBook(b1);
    lib.addBook(b2);
    lib.registerReader(r1);
    lib.registerReader(r2);

    lib.showAllBooks();
    lib.borrowBook(0, 0);
    lib.showAllBooks();
    r1->showBooks();

    delete b1;
    delete b2;
    delete r1;
    delete r2;

    return 0;
}