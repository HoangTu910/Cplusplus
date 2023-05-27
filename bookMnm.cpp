#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <fstream>
//#include <map>
using namespace std;


//Variables
vector<int> bookIDData;
vector<string> bookNameData;
vector<string> bookAuthorData;
vector<int> bookNumberData;
//map<int, int> bookIDMap;

int numberAddings = 0;

class myBook {
    private: 
        int bookID;
        string bookName;
        string bookAuthor;
        int bookNumber = 3;
    
    public:
        //Setter
        void setBookID(int setbookID) { bookID = setbookID; }
        void setBookName(string setBookName) { bookName = setBookName; }
        void setBookAuthor(string setBookAuthor) { bookAuthor = setBookAuthor; }
        void setBookNumber(int setBookNumber) { bookNumber = setBookNumber; }

        //Getter
        int getBookID() { return bookID; }
        string getBookName() { return bookName; }
        string getBookAuthor() { return bookAuthor; }
        int getBookNumber() { return bookNumber; }

        void inputBook(){
            cout << "ID of Book: ";
            cin >> bookID;
            bookIDData.push_back(bookID);
            cout << "Book Name: ";
            cin >> bookName;
            bookNameData.push_back(bookName);
            cout << "Book Author: ";
            cin >> bookAuthor;
            bookAuthorData.push_back(bookAuthor);
            cout << "Book Number: ";
            cin >> bookNumber;
            bookNumberData.push_back(bookNumber);
            numberAddings++;
        }
};


class GUIUser {
    private:
        myBook book;
        string userName;
        int quantity = book.getBookNumber();
        int option = 0;
        int displayBookID;
        string displayBookName;
        string displayBookAuthor;
        int displayBookNumber;

    
    public:
        //Setter
        void setUserName(string setuserName) { userName = setuserName;}
        string getUserName() { return userName; }

        void controlPanel(){
            cout << "CONTROL PANEL" << endl;
            cout << "1. ADD BOOK"   << endl;
            cout << "2. DISPLAY BOOK" << endl;
            cout << "3. CHECK PARTICULAR BOOK" << endl;
            cout << "4. UPDATE BOOK" << endl;
            cout << "5. DELETE BOOK" << endl;
            cout << "6. EXIT" << endl;
            cout << "Choose your options: ";
            cin >> option;
        }

        void checkFile(){
            ofstream ofs("bookInformation.txt");
            if(!ofs){
                cerr << "Error reading book information" << endl;
            }
        }

        void optionSelect(){
            while(option != 6){
                controlPanel();
                switch(option){
                    case 1: system("cls"); book.inputBook(); system("cls"); break;
                    case 2: system("cls"); displayInfo(); break;
                    case 3: system("cls"); checkParticularBook(); break;
                    case 4: system("cls"); updateBook(); break;
                    case 5: system("cls"); deleteBook(); break;
                    default:
                    {
                        cout <<"Unknown Information ! Please choose again" << endl;
                        controlPanel(); 
                        break;
                    }
                }
            }
        }

        void displayInfo(){
            system("cls");

            ofstream ofs("bookInformation.txt");
            if(!ofs){
                cerr << "Error reading book information" << endl;
            }

            ofs << "Your books information:"<< endl;
            for(int i=0; i<numberAddings; i++){
                // cout << "Book ID: " << bookIDData.at(i) << endl;
                // cout << "Book Name: " << bookNameData.at(i) << endl;
                // cout << "Book Author: " << bookAuthorData.at(i) << endl;
                // cout << "Number of books: " << bookNumberData.at(i) << endl;
                // cout << "----------------------------------------" << endl;
                ofs << "Book ID: " << bookIDData.at(i) << endl;
                ofs << "Book Name: " << bookNameData.at(i) << endl;
                ofs << "Book Author: " << bookAuthorData.at(i) << endl;
                ofs << "Number of books: " << bookNumberData.at(i) << endl;
                ofs << "----------------------------------------" << endl;
                cout <<"Update success ! Please check your file !" << endl;
            }
        }

        int getBookIDs(){
            int id;
            cout << "ID of book: ";
            cin >> id;

            return id;
        }

        void displayParticular(int id){
            system("cls");
            ofstream ofs("bookParticular.txt");
            if(!ofs){
                cerr << "Error reading book information" << endl;
            }

            ofs << "Your books information:"<< endl;
            for(int i=0; i<numberAddings; i++){
                if(id == bookIDData.at(i)){
                    ofs << "Book ID: " << bookIDData.at(i) << endl;
                    ofs << "Book Name: " << bookNameData.at(i) << endl;
                    ofs << "Book Author: " << bookAuthorData.at(i) << endl;
                    ofs << "Number of books: " << bookNumberData.at(i) << endl;
                    ofs << "----------------------------------------" << endl;
                    cout <<"Update success ! Please check your file !" << endl;
                }
            }


        }

        void checkParticularBook(){
            int IDcheck = getBookIDs();
            for(int i = 0; i<numberAddings; i++){
                if(IDcheck == bookIDData.at(i)){
                    displayParticular(IDcheck);
                }
            }
        }


        void updateBook(){
            int id = getBookIDs();
            for(int i = 0; i<numberAddings; i++){
                if(id == bookIDData.at(i)){
                    cout <<"Update your book. . ."<<endl;
                    cout << "ID of Book: ";
                    cin >> bookIDData.at(i);
                    cout << "Book Name: ";
                    cin >> bookNameData.at(i);
                    cout << "Book Author: ";
                    cin >> bookAuthorData.at(i);
                    cout << "Book Number: ";
                    cin >> bookNumberData.at(i);
                    cout <<"Update Success !" <<endl;
                }
            }
        }



        void deleteBook(){
            int id = getBookIDs();
            //cout << numberAddings << endl;
            for(int i = 0; i < numberAddings; i++){
                if(id == bookIDData.at(i)){
                    for(int j = i; j < numberAddings-1; j++){
                        bookIDData[j] = bookIDData[j+1];
                        bookNameData[j] = bookNameData[j+1];
                        bookAuthorData[j] = bookAuthorData[j+1];
                        bookNumberData[j] = bookNumberData[j+1];
                    }
                    numberAddings--;
                    bookIDData.pop_back();
                    bookNameData.pop_back();
                    bookAuthorData.pop_back();
                    bookNumberData.pop_back();

                }
                
            }
            
        }
};


int main(){
    GUIUser gui;
    gui.optionSelect();
}