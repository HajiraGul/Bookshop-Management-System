#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Book {
    string title, author, genre;
    int stock, price, year;
};

// Sample collection of books
vector<Book> books = {
    {"The Great Gatsby", "F. Scott Fitzgerald", "Classic", 10, 15, 1925},
    {"To Kill a Mockingbird", "Harper Lee", "Classic", 5, 12, 1960},
    {"1984", "George Orwell", "Dystopian", 8, 10, 1949},
    {"Pride and Prejudice", "Jane Austen", "Classic", 7, 8, 1813}, 
    {"The Catcher in the Rye", "J.D. Salinger", "Coming-of-age", 3, 9, 1951}
};

// Utility function to print a divider
void printDivider(char symbol = '=', int length = 50) {
    for (int i = 0; i < length; ++i) {
        cout << symbol;
    }
    cout << "\n";
}

// Function to add a new book
void addBook() {
    Book book;
    cout << "\n";
    printDivider('-', 40);
    cout << "\t--- ADD A NEW BOOK ---\n";
    printDivider('-', 40);
    cout << "○ Enter book title: ";
    getline(cin, book.title);
    cout << "○ Enter author name: ";
    getline(cin, book.author);
    cout << "○ Enter publication year: ";
    cin >> book.year;
    cout << "○ Enter price: $";
    cin >> book.price;
    cout << "○ Enter stock: ";
    cin >> book.stock;
    cin.ignore();
    cout << "○ Enter genre: ";
    getline(cin, book.genre);
    books.push_back(book);
    printDivider('-', 40);
    cout << "\t** BOOK ADDED SUCCESSFULLY! **\n";
    printDivider('-', 40);
    cout << "\n";
}

// Function to display all books
void displayBooks() {
    if (books.empty()) {
        printDivider('-', 40);
        cout << "\t** NO BOOKS FOUND **\n";
        printDivider('-', 40);
        return;
    }
    
    cout << "\n";
    printDivider('=', 60);
    cout << "\t--- BOOKS AVAILABLE ---\n";
    printDivider('=', 60);
    for (const auto& book : books) {
        cout << "Title: " << book.title << "\n";
        cout << "Author: " << book.author << "\n";
        cout << "Publication Year: " << book.year << "\n";
        cout << "Price: $" << book.price << "\n";
        cout << "Stock: " << book.stock << "\n";
        cout << "Genre: " << book.genre << "\n";
        printDivider('-', 50);
    }
    cout << "\n";
}

// Function to find books by author
void findBooksByAuthor(const string& author) {
    if (books.empty()) {
        printDivider('-', 40);
        cout << "** NO BOOKS FOUND **\n";
        printDivider('-', 40);
        return;
    }

    bool found = false;
    printDivider('=', 50);
    cout << "\t--- SEARCH RESULTS FOR AUTHOR: " << author << " ---\n";
    printDivider('=', 50);
    for (const auto& book : books) {
        if (book.author == author) {
            cout << "Title: " << book.title << "\n";
            cout << "Publication Year: " << book.year << "\n";
            cout << "Price: $" << book.price << "\n";
            cout << "Stock: " << book.stock << "\n";
            cout << "Genre: " << book.genre << "\n";
            printDivider('-', 50);
            found = true;
        }
    }
    
    if (!found) {
        printDivider('-', 50);
        cout << "\t** No books found by author " << author << ". **\n";
        printDivider('-', 50);
    }
    cout << "\n";
}

// Function to find books by author and year
void findBooksByAuthorAndYear(const string& author, int year) {
    if (books.empty()) {
        printDivider('-', 40);
        cout << "** NO BOOKS FOUND **\n";
        printDivider('-', 40);
        return;
    }

    bool found = false;
    printDivider('=', 60);
    cout << "\t--- SEARCH RESULTS FOR AUTHOR: " << author << " AND YEAR: " << year << " ---\n";
    printDivider('=', 60);
    for (const auto& book : books) {
        if (book.author == author && book.year == year) {
            cout << "Title: " << book.title << "\n";
            cout << "Publication Year: " << book.year << "\n";
            cout << "Price: $" << book.price << "\n";
            cout << "Stock: " << book.stock << "\n";
            cout << "Genre: " << book.genre << "\n";
            printDivider('-', 50);
            found = true;
        }
    }

    if (!found) {
        printDivider('-', 50);
        cout << "\t** No books found by author " << author << " and year " << year << ". **\n";
        printDivider('-', 50);
    }
    cout << "\n";
}

// Function to remove a book
void removeBook() {
    string title;
    printDivider('-', 40);
    cout << "\t--- REMOVE A BOOK ---\n";
    printDivider('-', 40);
    cout << "○ Enter book title to remove: ";
    getline(cin, title);
    
    bool found = false;
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->title == title) {
            books.erase(it);
            printDivider('-', 40);
            cout << "\t** BOOK REMOVED SUCCESSFULLY! **\n";
            printDivider('-', 40);
            found = true;
            break;
        }
    }

    if (!found) {
        printDivider('-', 40);
        cout << "\t** No book found with title " << title << ". **\n";
        printDivider('-', 40);
    }
    cout << "\n";
}

// Function to search by genre
void findBooksByGenre(const string& genre) {
    if (books.empty()) {
        printDivider('-', 40);
        cout << "** NO BOOKS FOUND **\n";
        printDivider('-', 40);
        return;
    }

    bool found = false;
    printDivider('=', 50);
    cout << "\t--- SEARCH RESULTS FOR GENRE: " << genre << " ---\n";
    printDivider('=', 50);
    for (const auto& book : books) {
        if (book.genre == genre) {
            cout << "Title: " << book.title << "\n";
            cout << "Author: " << book.author << "\n";
            cout << "Publication Year: " << book.year << "\n";
            cout << "Price: $" << book.price << "\n";
            cout << "Stock: " << book.stock << "\n";
            cout << "Genre: " << book.genre << "\n";
            printDivider('-', 50);
            found = true;
        }
    }

    if (!found) {
        printDivider('-', 50);
        cout << "\t** No books found in genre " << genre << ". **\n";
        printDivider('-', 50);
    }
    cout << "\n";
}

int main() {
    int choice;
    do {
        printDivider('=', 50);
        cout << "\t===== BOOKSHOP MANAGEMENT SYSTEM =====\n";
        printDivider('=', 50);
        cout << "1. Add a book\n";
        cout << "2. Display all books\n";
        cout << "3. Find books by author\n";
        cout << "4. Find books by author and year\n";
        cout << "5. Find books by genre\n";
        cout << "6. Remove a book\n";
        cout << "7. Exit\n";
        printDivider('=', 50);
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3: {
                string author;
                cout << "○ Enter author name to search for: ";
                getline(cin, author);
                findBooksByAuthor(author);
                break;
            }

            case 4: {
                string author;
                int year;
                cout << "○ Enter author name to search for: ";
                getline(cin, author);
                cout << "○ Enter publication year to search for: ";
                cin >> year;
                findBooksByAuthorAndYear(author, year);
                cin.ignore();
                break;
            }

            case 5: {
                string genre;
                cout << "○ Enter genre to search for: ";
                getline(cin, genre);
                findBooksByGenre(genre);
                break;
            }

            case 6:
                removeBook();
                break;

            case 7:
                printDivider('=', 50);
                cout << "\t** EXITING BOOKSHOP SYSTEM **\n";
                printDivider('=', 50);
                break;

            default:
                printDivider('=', 50);
                cout << "\t** INVALID CHOICE. TRY AGAIN. **\n";
                printDivider('=', 50);
                break;
        }

    } while (choice != 7);

    return 0;
}
