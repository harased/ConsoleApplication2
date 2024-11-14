#include "library.h"

void printBook(const Book& book, const string& title) {
    cout << title << endl;
    cout << "Name     \t:: \t" << book.name << endl;
    cout << "Author   \t:: \t" << book.author << endl;
    cout << "Publisher  \t:: \t" << book.publisher << endl;
    cout << "Genre   \t:: \t" << book.genre << endl;
}

void printBooks(const Book* library, const int& size) {
    for (size_t i = 0; i < size; i++)
    {
        printBook(library[i], "\t\tBook #" + to_string(i + 1));
    }
}

void printMagazine(const Magazine& magazine, const string& title)
{
    cout << title << endl;
    cout << "Name    \t:: \t " << magazine.name << endl;
    cout << "Author  \t:: \t " << magazine.author << endl;
    cout << "Publisher  \t:: \t " << magazine.publisher << endl;
}

void printMagazines(const Magazine* magazines, const int& size)
{
    for (size_t i = 0; i < size; i++)
    {
        printMagazine(magazines[i], "\t\tMagazine #" + to_string(i + 1));
    }
}

void printNewsPaper(const NewsPaper& newspaper, const string& title)
{
    cout << title << endl;
    cout << "Name    \t:: \t " << newspaper.name << endl;
    cout << "Publisher   \t:: \t " << newspaper.publisher << endl;
    cout << "Year   \t\t:: \t " << newspaper.year << endl;
}

void printNewsPapers(const NewsPaper* newspapers, const int& size)
{
    for (size_t i = 0; i < size; i++)
    {
        printNewsPaper(newspapers[i], "\t\tNewspaper #" + to_string(i + 1));
    }
}

template <typename T>
void tempAddNew(T*& library, int& size)
{
    T* newlibrary = new T[size + 10];
    for (int i = 0; i < size; i++)
    {
        newlibrary[i] = library[i];
    }
    delete[] library;
    library = newlibrary;
}

void addNewBook(Book*& books, int& size)
{
    if (size % 5 == 0)
    {
        tempAddNew(books, size);
    }
    Book newBook;
    cout << "Enter new books name :: ";
    cin.clear();
    cin.getline(newBook.name, SIZE1);
    cout << "Enter new books author :: ";
    cin.getline(newBook.author, SIZE1);
    cout << "Enter new books publisher :: ";
    cin.getline(newBook.publisher, SIZE1);
    cout << "Enter new books genre :: ";
    cin.getline(newBook.genre, SIZE1);
    books[size++] = newBook;
}

void addNewMagazine(Magazine*& magazines, int& size)
{
    if (size % 5 == 0)
    {
        tempAddNew(magazines, size);
    }
    Magazine newMagazine;
    cout << "Enter new magazines name :: ";
    cin.clear();
    cin.getline(newMagazine.name, SIZE1);
    cout << "Enter new magazines author :: ";
    cin.getline(newMagazine.author, SIZE1);
    cout << "Enter new magazines publisher :: ";
    cin.getline(newMagazine.publisher, SIZE1);
    magazines[size++] = newMagazine;
}

void addNewNewsPaper(NewsPaper*& newspapers, int& size)
{
    if (size % 5 == 0)
    {
        tempAddNew(newspapers, size);
    }
    NewsPaper newNewsPaper;
    cout << "Enter new newspapers name :: ";
    cin.clear();
    cin.getline(newNewsPaper.name, SIZE1);
    cout << "Enter new newspapers publisher :: ";
    cin.getline(newNewsPaper.publisher, SIZE1);
    cout << "Enter new newspapers year :: ";
    cin.getline(newNewsPaper.year, SIZE1);
    newspapers[size++] = newNewsPaper;
}

template <typename T>
void tempDelete(T*& library, int& size)
{
    char line[SIZE1];
    cout << "Enter name which u want to delete :: ";
    cin.clear();
    cin.getline(line, SIZE1);
    for (int i = 0; i < size; i++)
    {
        if (strcmp(library[i].name, line) == 0)
        {
            for (int j = i; j < size - 1; j++)
            {
                library[j] = library[j + 1];
            }
            size--;
            cout << "Successful deleted!" << endl;
            return;
        }
    }
    cout << "Unsuccessful deleted, may-be ur request not found!" << endl;
}

void deleteBook(Book*& library, int& size)
{
    tempDelete(library, size);
}

void deleteMagazine(Magazine*& magazines, int& size)
{
    tempDelete(magazines, size);
}

void deleteNewsPaper(NewsPaper*& newspapers, int& size)
{
    tempDelete(newspapers, size);
}

void deleteNewsPaperYear(NewsPaper*& newspapers, int& size)
{
    char yeardelete[SIZE1];
    cout << "Enter year of newspaper which u want to delete :: ";
    cin.clear();
    cin.getline(yeardelete, SIZE1);
    for (int i = 0; i < size; i++)
    {
        if (strcmp(newspapers[i].year, yeardelete) == 0)
        {
            for (int j = i; j < size - 1; j++)
            {
                newspapers[j] = newspapers[j + 1];
            }
            size--;
            cout << "Successful deleted!" << endl;
            return;
        }
    }
    cout << "Unsuccessful deleted, may-be ur request not found!" << endl;
}

int countBooks(Book*& library, const int& size)
{
    char genrefind[SIZE1];
    cout << "Enter genre what u find in books :: ";
    cin.clear();
    cin.getline(genrefind, SIZE1);
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(library[i].genre, genrefind) == 0)
        {
            count++;
        }
    }
    return count;
}

bool findBook(Book*& library, const int& size)
{
    char bookName[SIZE1];
    cout << "Enter book name what u find :: ";
    cin.getline(bookName, SIZE1);
    char authorName[SIZE1];
    cout << "Enter author name what u find :: ";
    cin.getline(authorName, SIZE1);
    for (int i = 0; i < size; i++)
    {
        if (strcmp(library[i].name, bookName) == 0 and strcmp(library[i].author, authorName) == 0)
        {
            return true;
        }
    }
    return false;
}

bool findMagazine(Magazine*& magazines, const int& size)
{
    char magazineName[SIZE1];
    cout << "Enter magazine name what u find :: ";
    cin.getline(magazineName, SIZE1);
    for (int i = 0; i < size; i++)
    {
        if (strcmp(magazines[i].name, magazineName) == 0)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
void sortLibrary(T*& library, int& size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (strcmp(library[j].name, library[j + 1].name) > 0)
            {
                T temp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = temp;
            }
        }
    }
}

void sortBooks(Book*& library, int& size)
{
    sortLibrary(library, size);
}

void sortBooksAuthor(Book*& library, int& size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (strcmp(library[j].author, library[j + 1].author) > 0)
            {
                Book temp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = temp;
            }
        }
    }
}

void sortBooksPublisher(Book*& library, int& size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (strcmp(library[j].publisher, library[j + 1].publisher) > 0)
            {
                Book temp = library[j];
                library[j] = library[j + 1];
                library[j + 1] = temp;
            }
        }
    }
}

void sortMagazine(Magazine*& magazines, int& size)
{
    sortLibrary(magazines, size);
}

void sortNewsPapers(NewsPaper*& newspapers, int& size)
{
    sortLibrary(newspapers, size);
}

void viewBookAuthor(Book*& library, const int& size)
{
    bool flag = false;
    char bookview[SIZE1];
    cout << "Enter name author what books u want to see :: ";
    cin.getline(bookview, SIZE1);
    cout << "Author books :: " << endl;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(library[i].author, bookview) == 0)
        {
            cout << library[i].name << endl;
            flag = true;
        }
    }
    if (!flag)
    {
        cout << "No books with ur author" << endl;
    }
}
void viewBookGenre(Book*& library, const int& size)
{
    bool flag = false;
    char genreview[SIZE1];
    cout << "Enter genre what books u want to see :: ";
    cin.getline(genreview, SIZE1);
    cout << "Genre books :: " << endl;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(library[i].genre, genreview) == 0)
        {
            cout << library[i].name << endl;
            flag = true;
        }

    }
    if (!flag)
    {
        cout << "No books with ur genre" << endl;
    }
}
void viewNewsPaperYear(NewsPaper*& newspapers, const int& size)
{
    bool flag = false;
    char year[SIZE1];
    cout << "Enter year what newspapers u want to see :: ";
    cin.getline(year, SIZE1);
    cout << "Newspapers :: " << endl;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(newspapers[i].year, year) == 0)
        {
            cout << newspapers[i].name << endl;
            flag = true;
        }

    }
    if (!flag)
    {
        cout << "No newspapers in this year" << endl;
    }
}

void saveBooks(const Book* library, int& size)
{
    ofstream booksOut("books.txt");
    if (!booksOut)
    {
        cout << "Not found a file" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        booksOut << library[i].name << "," << library[i].author << "," << library[i].publisher << "," << library[i].genre << endl;
    }
    booksOut.close();
    cout << "Succsessfully saved!" << endl;
}

void saveMagazines(const Magazine* magazines, int& size)
{
    ofstream magazinesOut("magazines.txt");
    if (!magazinesOut)
    {
        cout << "Not found a file" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        magazinesOut << magazines[i].name << "," << magazines[i].author << "," << magazines[i].publisher << endl;
    }
    magazinesOut.close();
    cout << "Succsessfully saved!" << endl;
}

void saveNewPapers(const NewsPaper* newspapers, int& size)
{
    ofstream newspapersOut("newspapers.txt");
    if (!newspapersOut)
    {
        cout << "Not found a file" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        newspapersOut << newspapers[i].name << "," << newspapers[i].publisher << "," << newspapers[i].year << endl;
    }
    newspapersOut.close();
    cout << "Succsessfully saved!" << endl;
}

void loadBooks(Book*& library, int& size)
{
    ifstream booksLoad("books.txt");
    if (!booksLoad)
    {
        cout << "File not found!" << endl;
        return;
    }

    size = 0;
    string line;
    while (getline(booksLoad, line))
    {
        size++;
    }

    booksLoad.clear();
    booksLoad.seekg(0);

    library = new Book[size];

    for (int i = 0; i < size; i++)
    {
        booksLoad.getline(library[i].name, SIZE1, ',');
        booksLoad.getline(library[i].author, SIZE1, ',');
        booksLoad.getline(library[i].publisher, SIZE1, ',');
        booksLoad.getline(library[i].genre, SIZE1);
    }

    booksLoad.close();
    cout << "Succsessfully loaded books!" << endl;
}

void loadMagazines(Magazine*& magazines, int& size)
{
    ifstream magazinesLoad("magazines.txt");
    if (!magazinesLoad)
    {
        cout << "File not found!" << endl;
        return;
    }

    size = 0;
    string line;
    while (getline(magazinesLoad, line))
    {
        size++;
    }

    magazinesLoad.clear();
    magazinesLoad.seekg(0);

    magazines = new Magazine[size];

    for (int i = 0; i < size; i++)
    {
        magazinesLoad.getline(magazines[i].name, SIZE1, ',');
        magazinesLoad.getline(magazines[i].author, SIZE1, ',');
        magazinesLoad.getline(magazines[i].publisher, SIZE1);
    }

    magazinesLoad.close();
    cout << "Succsessfully loaded magazines!" << endl;
}


void loadNewPapers(NewsPaper*& newspapers, int& size)
{
    ifstream newspapersLoad("newspapers.txt");
    if (!newspapersLoad)
    {
        cout << "File not found!" << endl;
        return;
    }

    size = 0;
    string line;
    while (getline(newspapersLoad, line))
    {
        size++;
    }

    newspapersLoad.clear();
    newspapersLoad.seekg(0);

    newspapers = new NewsPaper[size];

    for (int i = 0; i < size; i++)
    {
        newspapersLoad.getline(newspapers[i].name, SIZE1, ',');
        newspapersLoad.getline(newspapers[i].publisher, SIZE1, ',');
        newspapersLoad.getline(newspapers[i].year, SIZE1);
    }

    newspapersLoad.close();
    cout << "Succsessfully loaded newspapers!" << endl;
}

//void printMenu(int choose)
//{
//    printBooks(library, bookSize);
//    printMagazines(magazines, magazineSize);
//    printNewsPapers(newspapers, newspaperSize);
//        case 2:
//            printBooks(library, bookSize);
//        case 3:
//            printMagazines(magazines, magazineSize);
//        case 4:
//            printNewsPapers(newspapers, newspaperSize);
//        case 5:
//            addNewBook(library, bookSize);
//        case 6:
//            addNewMagazine(magazines, magazineSize);
//        case 7:
//            addNewNewsPaper(newspapers, newspaperSize);
//        case 8:
//            deleteBook(library, bookSize);
//        case 9:
//            deleteMagazine(magazines, magazineSize);
//        case 10:
//            deleteNewsPaper(newspapers, newspaperSize);
//        case 11:
//            sortBooks(library, bookSize);
//        case 12:
//            sortMagazine(magazines, magazineSize);
//        case 13:
//            sortNewsPapers(newspapers, newspaperSize);
//        case 14:
//            findBook(library, bookSize);
//        case 15:
//            findMagazine(magazines, magazineSize);
//        case 16:
//            viewBookAuthor(library, bookSize);
//        case 17:
//            viewBookGenre(library, bookSize);
//        case 18:
//            viewNewsPaperYear(newspapers, newspaperSize);
//        case 19:
//            countBooks(library, bookSize);
//        case 20:
//            deleteNewsPaperYear(newspapers, newspaperSize);
//}