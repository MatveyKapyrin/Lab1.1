#include <iostream>
#include <string>
#include <vector>
#include <ctime>

enum class BookTyp
{
    art,
    technical
};
class Book
{
public:
    Book(const std::string& _autor, const std::string& _NameBook, BookTyp _booktyp) :
        autor(_autor),
        NameBook(_NameBook),
        booktyp(_booktyp) {}

    BookTyp GetBookType()const {
        return booktyp;
    }
private:
    const std::string autor;
    const std::string NameBook;
    const BookTyp booktyp;
};
class LibraryB {
public:

    ~LibraryB() {
        for (int i = 0; i < size(lib); ++i) {
            delete lib[i];
        }
    }
    void addB(const std::string& autor, const std::string& NameBook, BookTyp booktyp)
    {
        if ((autor != " ") || (NameBook!= ""))
        {
            lib.push_back(new Book(autor, NameBook, booktyp));
        }
    }
    void CounterTypeWithSwitch() {
        int artbook = 0;
        int techbook = 0;

    for (const Book* book : lib) {
        switch (book->GetBookType()) {
        case BookTyp::art:
            ++artbook;
            break;
        case BookTyp::technical:
            ++techbook;
            break;
        }
    }
    std::cout << "art book: " << artbook << '\n';
    std::cout << "technical book: " << techbook << '\n';
}

void CounterTypeNoneSwitch() {
    int artbook = 0;
    int techbook = 0;
    for (const Book* book : lib) {
        if (book->GetBookType() == BookTyp::art) {
            ++artbook;
        }
        else {
            ++techbook;
        }

    }

    std::cout << "art book: " << artbook << '\n';
    std::cout << "technical book: " << techbook << '\n';
}

private:
    std::vector<Book*> lib;
};

int main()
{
    LibraryB libBook;

    libBook.addB("Tolstoy", "War and peace", BookTyp::art);
    libBook.addB("Vlasov M.D.", "Physics", BookTyp::technical);

    std::cout << "with switch\n";
    libBook.CounterTypeWithSwitch();
    std::cout <<"\n";

    std::cout << "no switch\n";
    libBook.CounterTypeNoneSwitch();
}