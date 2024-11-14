#pragma once
#include <iostream> 
#include <string> 
#include <fstream> 

using std::to_string;
using std::swap;
using std::endl;
using std::cin;
using std::cout;
using std::string;
using std::getline;
using std::ofstream;
using std::ifstream;

const int SIZE1 = 50;

struct Book
{
    char name[SIZE1]{};
    char author[SIZE1]{};
    char publisher[SIZE1]{};
    char genre[SIZE1]{};
};

struct Magazine
{
    char name[SIZE1]{};
    char author[SIZE1]{};
    char publisher[SIZE1]{};
};

struct NewsPaper
{
    char name[SIZE1]{};
    char publisher[SIZE1]{};
    char year[SIZE1]{};
};

void printBook(const Book& book, const string& title);
void printBooks(const Book* library, const int& size);
void printMagazine(const Magazine& magazine, const string& title);
void printMagazines(const Magazine* magazine, const int& size);
void printNewsPaper(const NewsPaper& newspaper, const string& title);
void printNewsPapers(const NewsPaper* newspaper, const int& size);
void addNewBook(Book*& books, int& size);
void addNewMagazine(Magazine*& magazines, int& size);
void addNewNewsPaper(NewsPaper*& newspapers, int& size);
void deleteBook(Book*& books, int& size);
void deleteMagazine(Magazine*& magazines, int& size);
void deleteNewsPaper(NewsPaper*& newspapers, int& size);
void deleteNewsPaperYear(NewsPaper*& newspapers, int& size);
int countBooks(Book*& library, const int& size);
bool findBook(Book*& library, const int& size);
bool findMagazine(Magazine*& magazines, const int& size);
void sortBooks(Book*& library, int& size);
void sortBooksAuthor(Book*& library, int& size);
void sortBooksPublisher(Book*& library, int& size);
void sortMagazine(Magazine*& magazines, int& size);
void sortNewsPapers(NewsPaper*& newspapers, int& size);
void viewBookAuthor(Book*& library, const int& size);
void viewBookGenre(Book*& library, const int& size);
void viewNewsPaperYear(NewsPaper*& newspapers, const int& size);
void saveBooks(const Book* library, int& size);
void saveMagazines(const Magazine* magazines, int& size);
void saveNewPapers(const NewsPaper* newspapers, int& size);
void loadBooks(Book*& library, int& size);
void loadMagazines(Magazine*& magazines, int& size);
void loadNewPapers(NewsPaper*& newspapers, int& size);
