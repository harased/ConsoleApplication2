#include <iostream> 
#include "library.h" 
#include <string> 
#include <fstream> 
using namespace std;

int main()
{
    const int SIZE2 = 50;

    int bookSize = 0;
    Book* library = nullptr;

    //int bookSize = 5;
    //Book* library = new Book[bookSize]{
    //    {"Whispers of the Forest", "Emily Green", "Nature Press", "Fantasy"},
    //    {"The Digital Frontier", "Mark Thompson", "Tech World Publications", "Technology"},
    //    {"Secrets of the Deep", "Anna Rivers", "Oceanic Publishing", "Adventure"},
    //    {"Secrets of the Space", "Anna Rivers", "Space Publishing", "Adventure"},
    //    {"Secrets of the World", "Anna Rivers", "World Publishing", "Adventure"},
    //};

    int magazineSize = 0;
    Magazine* magazines = nullptr;

    //int magazineSize = 5;
    //Magazine* magazines = new Magazine[magazineSize]{
    //    {"Style Insider", "Olivia Hart", "Fashion Forward"},
    //    {"Future Tech", "Jason Lee", "Tech Insights"},
    //    {"Wellness Today", "Anna White", "Healthy Life Press"},
    //    {"Wellness Tomorrow", "Anna White", "Healthy Life Press"},
    //    {"Wellness Yesterday", "Anna White", "Healthy Life Press"},
    //};

    int newspaperSize = 0;
    NewsPaper* newspapers = nullptr;

    //int newspaperSize = 5;
    //NewsPaper* newspapers = new NewsPaper[newspaperSize]{
    //    {"City Gazette", "Urban News", "1978"},
    //    {"World Observer", "International Media Group", "1988"},
    //    {"Sunset Bulletin", "Evening Press", "1978"},
    //    {"Todays news", "Evening Press", "1978"},
    //    {"Last week news", "Evening Press", "1988"},
    //};

    //loadBooks(library, bookSize);
    //printBooks(library, bookSize);
    //printMagazines(magazines, magazineSize);
    //printNewsPapers(newspapers, newspaperSize);
    //addNewBook(library, bookSize);
    //addNewMagazine(magazines, magazineSize);
    //addNewNewsPaper(newspapers, newspaperSize);
    //deleteBook(library, bookSize);
    //printBooks(library, bookSize);
    //deleteMagazine(magazines, magazineSize);
    //deleteNewsPaper(newspapers, newspaperSize);
    //deleteNewsPaperYear(newspapers, newspaperSize);
    //cout << countBooks(library, bookSize) << endl;
    //cout << boolalpha << findBook(library, bookSize) << endl;
    //cout << boolalpha << findMagazine(magazines, magazineSize) << endl;
    //sortBooks(library, bookSize);
    //sortMagazine(magazines, magazineSize);
    //sortNewsPapers(newspapers, newspaperSize);
    //printBooks(library, bookSize);
    //printMagazines(magazines, magazineSize);
    //printNewsPapers(newspapers, newspaperSize);
    //viewBookAuthor(library, bookSize);
    //viewBookGenre(library, bookSize);
    //viewNewsPaperYear(newspapers, newspaperSize);
    //loadBooks(library, bookSize);
    //printBooks(library, bookSize);
    //addNewBook(library, bookSize);
    //printBooks(library, bookSize);
    //saveBooks(library, bookSize);
    //saveMagazines(magazines, magazineSize);
    //saveNewPapers(newspapers, newspaperSize);
    //loadBooks(library, bookSize);
    //loadMagazines(magazines, magazineSize);
    //loadNewPapers(newspapers, newspaperSize);
    //printBooks(library, bookSize);
    //printMagazines(magazines, magazineSize);
    //printNewsPapers(newspapers, newspaperSize);

    loadBooks(library, bookSize);
    //loadMagazines(magazines, magazineSize);
    //loadNewPapers(newspapers, newspaperSize);

    int choose;
    do {

        cout << R"(Menu ::
1. View all books
2. Add new book
3. Delete book
4. Sort books as name
5. Sort books as author
6. Sort books as publisher
7. Find book as author and name
8. Check author books
9. Check genre books
10. Count books as genre
0. Exit
)";

        cin >> choose;
        cin.ignore();
        switch (choose)
        {
        case 1:
            printBooks(library, bookSize);
            break;
        case 2:
            addNewBook(library, bookSize);
            break;
        case 3:
            deleteBook(library, bookSize);
            break;
        case 4:
            sortBooks(library, bookSize);
            break;        
        case 5:
            sortBooksAuthor(library, bookSize);
            break;        
        case 6:
            sortBooksPublisher(library, bookSize);
            break;
        case 7:
            cout << boolalpha << findBook(library, bookSize) << endl;
            break;
        case 8:
            viewBookAuthor(library, bookSize);
            break;
        case 9:
            viewBookGenre(library, bookSize);
            break;
        case 10:
            cout << countBooks(library, bookSize) << endl;
            break;
        case 0:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Choice error," << endl;
            break;
        }
    } while (choose != 0);

    saveBooks(library, bookSize);
    //saveMagazines(magazines, magazineSize);
    //saveNewPapers(newspapers, newspaperSize);

    delete[] library;
    //delete[] magazines;
    //delete[] newspapers;

}