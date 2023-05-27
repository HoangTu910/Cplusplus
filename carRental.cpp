#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

//Login account
//choosing type of car
    //color
    //price
//choosing day to return

string getPassword(){
    string password;
    cout << "Enter your password: ";
    cin >> password;

    return password;
}



string getUsername(){
    string username;
    cout << "Enter your username: ";
    cin >> username;

    //cout << &username << endl;///DIA CHI CUA DONG NAY
    return username;
}


void checkLogin(string* userName, string* password){
    string getUser = getUsername();
    string getPass = getPassword(); 
    //cout << getUsername() << endl;
    //cout << (&getUser);//DIA CHI CUA DONG NAY
    while((*userName != getUser) && (*password != getPass)){
        cout << "Login failed" << endl;
        getUser = getUsername();
        getPass = getPassword();
    }
    cout << "Login successful" << endl;
    system("cls");
}

int selectCar(string* carBrand){
    int selectCar;
    cout << "Choose brand of car..." << endl;
    cout << "1. Ferarri" << endl;
    cout << "2. Toyota" << endl;
    cout << "3. Tesla" << endl;
    cout << "Choosing: ";
    cin >> selectCar; 
    system("cls");

    int getCar;

    switch(selectCar){
        case 1: 
        getCar = 1;
        *carBrand = "Ferrari";
        break;
        case 2:
        getCar = 2;
        *carBrand = "Toyota";
        break;
        case 3:
        getCar = 3 ;
        *carBrand = "Tesla";
        break;
    }


    return getCar;
}

void getInformation(string* name, int* age, string* home, string* dateRent, string* dateBack){
    cout << "Name: ";
    cin >> *name; 
    cout << endl;
    cout <<"Age: ";
    cin >> *age;
    cout << endl;
    cout <<"Your home address: ";
    cin >> *home;
    cout << endl;
    cout <<"Date of Rent: ";
    cin >> *dateRent;
    cout << endl;
    cout <<"Date of turn back: ";
    cin >>* dateBack;
    cout << endl;
    system("cls");
}

void printInfo(string* name, int* age, string* home, string* dateRent, string* dateBack, string* carBrand, string* carType){
    cout << "---------------Your rental information--------------" << endl;
    cout << "Name of Renter: " << *name << endl;
    cout <<"Age: " << *age << endl;
    cout <<"Car Brand: " << *carBrand << endl;
    cout <<"Car Type: " << *carType << endl;
    cout <<"Date of Rent: " << *dateRent << endl;
    cout <<"Date of turn back: " << *dateBack << endl;
}

/*-------------------Car Function-----------------------*/
void carInformation(string* carType, string* carBrand){ 
    int carCheck = selectCar(carBrand);
    int carTypenum;
    cout << "--------" << *carBrand << "---------" << endl;
    cout << "Choose your type of car..." << endl;

        
    switch(carCheck){
        case 1:
            cout <<"1. Aventador" << endl;
            cout <<"2. Lightnight" << endl;
            cout <<"3. FastHum " << endl;
            cout <<"Choosing: ";
            cin >> carTypenum;
            switch(carTypenum){
                case 1:
                    *carType = "Aventador";
                    break;
                case 2:
                    *carType = "Lightnight";
                    break;
                case 3:
                    *carType = "FastHum";
                    break;      
            }
            break;

        case 2:
            cout <<"1. Innova"  << endl;
            cout <<"2. Hecbano" << endl;
            cout << "3. Guffal  " << endl;
            cout <<"Choosing: ";
            cin >> carTypenum;
            switch(carTypenum){
                case 1:
                    *carType = "Innova";
                    break;
                case 2:
                    *carType = "Hecbano";
                    break;
                case 3:
                    *carType = "Guffal";
                    break;
            }
            break;

        case 3:
            cout <<"1. Burst"  << endl;
            cout << "2. Charge" << endl;
            cout <<"Choosing: ";
            cin >> carTypenum;
            switch(carTypenum){
                case 1:
                    *carType = "Burst";
                    break;
                case 2:
                    *carType = "Charge";
                    break;
            }
            break;
        
    }
    system("cls");
}

void sumInfo(string* userName, string* password, string* carBrand, string* carType){
    cout <<"--------Your rental information--------" << endl;
    cout <<"Username: " << *userName << endl;
    cout <<"Password: " << *password << endl;
    cout <<"Brand of car: " << *carBrand << endl;
    cout <<"Type of car: " << *carType << endl;
}

int main(){
    string userName = "Tuhoang";
    string password = "12345";
    bool isCorrect = false;
    string carBrand;
    string carType;
    string name;
    int age;
    string home;
    string dateRent;
    string dateBack;

    checkLogin(&userName, &password);
    carInformation(&carType, &carBrand);
    //sumInfo(&userName, &password, &carBrand, &carType);
    getInformation(&name, &age, &home, &dateRent, &dateBack);
    printInfo(&name, &age, &home, &dateRent, &dateBack, &carBrand, &carType);

}