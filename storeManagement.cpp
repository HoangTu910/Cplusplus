#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<string> brandProduct;
vector<string> modelProduct;
vector<int> priceProduct;
vector<string> nameProduct;
vector<int> quantityProduct;

class Technology
{
private:
    int price;
    string brand;
    int quantity;
    string model;

public:
    // Contructor
    Technology()
    {
        this->price = price;
        this->brand = brand;
        this->quantity = quantity;
        this->model = model;
    }
    // setter
    void setPrice(int p)
    {
        price = p;
    }

    void setBrand(string br)
    {
        brand = br;
    }

    void setQuantity(int q)
    {
        quantity = q;
    }

    void setModel(string mod)
    {
        model = mod;
    }

    // getter

    int getPrice() { return price; }
    string getBrand() { return brand; }
    int getQuantity() { return quantity; }
    string getModel() { return model; }

    // method
    void buyThing()
    {
        cout << "          Buying...          " << endl;
        cout << "Brand: ";
        cin >> brand;
        brandProduct.push_back(brand);
        cout << "Model: ";
        cin >> model;
        nameProduct.push_back(model);
        cout << "Quantity: ";
        cin >> quantity;
        quantityProduct.push_back(quantity);
        cout << "Price: ";
        cin >> price;
        priceProduct.push_back(price);
        system("cls");
    }
};

class Fruit
{
private:
    int price;
    string name;
    int quantity;

public:
    // Contructor
    Fruit()
    {
        this->price = price;
        this->name = name;
        this->quantity = quantity;
    }

    // setter
    void setPrice(int p)
    {
        price = p;
    }

    void setName(string n)
    {
        name = n;
    }

    void setQuantity(int q)
    {
        quantity = q;
    }

    // getter

    int getPrice() { return price; }
    string getName() { return name; }
    int getQuantity() { return quantity; }

    // method
    void buyThing()
    {
        cout << "             Buying...        " << endl;
        cout << "Name: ";
        cin >> name;
        nameProduct.push_back(name);
        cout << "Quantity: ";
        cin >> quantity;
        quantityProduct.push_back(quantity);
        cout << "Price: ";
        cin >> price;
        priceProduct.push_back(price);
        system("cls");
    }
};

class Hometools : public Fruit
{
};

class Customer
{
private:
    string name;
    int id;
    int budget;
    string gender;
    int age;

public:
    // setter
    void setName(string n)
    {
        name = n;
    }
    void setId()
    {
        this->id = id;
    }
    void setBudget(int bud)
    {
        budget = bud;
    }
    void setGender(string gen)
    {
        gender = gen;
    }
    void setAge(int a)
    {
        age = a;
    }

    // getter
    string getName() { return name; }
    int getId() { return id; }
    int getBudget() { return budget; }
    string getGender() { return gender; }
    int getAge() { return age; }

    void getInfo()
    {
        cout << "            Getting your information...           " << endl;
        cout << "Name: ";
        cin >> name;
        cout << "ID: ";
        cin >> id;
        cout << "Age: ";
        cin >> age;
        cout << "Gender: ";
        cin >> gender;
        system("cls");
    }

    void printInfo()
    {
        cout << "--------------Your Information ! Check Carefully Before Print !--------------" << endl;
        cout << "Customer Name: " << name << endl;
        cout << "ID's Customer: " << id << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

class Security
{
private:
    string userName;
    string password;
    string loginUser;
    string loginPassword;
    string confirmPassword;

public:
    Security()
    {
        this->userName = userName;
        this->password = password;
        this->confirmPassword = confirmPassword;
    }

    Security(string userName, string password, string confirmPassword)
    {
        this->userName = userName;
        this->password = password;
        this->confirmPassword = confirmPassword;
    }

    void signUp()
    {
        cout << "----------------Sign Up-------------------" << endl;
        cout << "Enter User Name: ";
        cin >> userName;
        cout << "Enter Password: ";
        cin >> password;
        cout << "Confirm Password: ";
        cin >> confirmPassword;
        while (confirmPassword != password)
        {
            cout << "Incorrect Confirm Password" << endl;
            cout << "Confirm Password: ";
            cin >> confirmPassword;
        }
        system("cls");
    }

    bool Login()
    {
        bool checkLogin = false;
        cout << "-------------Login to Enter Store----------------" << endl;
        cout << "User Name: ";
        cin >> loginUser;
        cout << "Password: ";
        cin >> loginPassword;

        if ((loginUser == userName) && (loginPassword == password))
        {
            return true;
        }
        else
        {
            cout << "Access Denied !" << endl;
            return false;
        }
    }
};

// bien toan cuc
Customer customer;
int budget = customer.getBudget();

class TopUp
{
private:
    int moneyTopUp;

public:
    TopUp()
    {
        this->moneyTopUp = moneyTopUp;
    }

    void topUp()
    {
        Customer customer;
        // int budget = customer.getBudget();
        cout << "Enter Money You Want To TopUp: ";
        cin >> moneyTopUp;
        budget = budget + moneyTopUp;
        system("cls");
        cout << "You have been TopUp " << budget << " successfully !" << endl;
        // customer.setBudget(budget);
    }
};

class Management
{
private:
    Customer customer;
    Technology technology;
    Fruit fruit;
    Hometools hometools;
    TopUp topUp;

public:
    Management()
    {
        this->customer = customer;
        this->technology = technology;
        this->fruit = fruit;
        this->hometools = hometools;
        this->topUp = topUp;
    }

    void customerBudget()
    {
        customer.setBudget(0);
    }

    void buyThings()
    {
        int choose;
        int loop;
        string type;
        while (loop != 0)
        {
            cout << "So tien cua ban: " << budget << endl;
            cout << "Danh sach cac mat hang: " << endl;
            cout << "1. Technology" << endl;
            cout << "2. Fruit" << endl;
            cout << "3. Hometools" << endl;
            cout << "9. Menu" << endl;
            cout << "Press 0 if you finish !" << endl;
            cout << "Chon mat hang ban muon mua: ";
            cin >> choose;
            system("cls");
            switch (choose)
            {
            case 1:
                type = "technology";
                break;
            case 2:
                type = "fruit";
                break;
            case 3:
                type = "hometools";
                break;
            case 9:
                chooseOption();
                break;
            case 0:
                cout << "Cam on ban da mua hang !" << endl;
                loop = 0;
                break;
            }
            if (loop == 0)
            {
                break;
            }

            if ((type == "technology"))
            {
                technology.buyThing();
                if (budget < technology.getPrice())
                {
                    cout << "Your budget is not enough to buy this !" << endl;
                    nameProduct.pop_back();
                    quantityProduct.pop_back();
                    priceProduct.pop_back();
                }
                else
                    budget = budget - technology.getPrice();
            }
            else if ((type == "fruit"))
            {
                fruit.buyThing();
                if (budget < fruit.getPrice())
                {
                    cout << "Your budget is not enough to buy this !" << endl;
                    nameProduct.pop_back();
                    quantityProduct.pop_back();
                    priceProduct.pop_back();
                }
                else
                    budget = budget - fruit.getPrice();
            }
            else if ((type == "hometools"))
            {
                hometools.buyThing();
                if (budget < hometools.getPrice())
                {
                    cout << "Your budget is not enough to buy this !" << endl;
                    nameProduct.pop_back();
                    quantityProduct.pop_back();
                    priceProduct.pop_back();
                }
                else
                    budget = budget - hometools.getPrice();
            }
        }
    }

    void printProduct()
    {
        char choose;
        cout << "Press P to print the bill !" << endl;
        cin >> choose;
        if (choose == 'p')
        {
            system("cls");
            cout << "This is all the thing you have bought ! Please check carefully." << endl;
            for (int i = 0; i < nameProduct.size(); i++)
            {
                cout << "Product Name: " << nameProduct[i] << endl;
                cout << "Quantity: " << quantityProduct[i] << endl;
                cout << "Price: " << priceProduct[i] << endl;
                cout << "----------------------------------" << endl;
            }
        }
    }

    void chooseOption()
    {
        int choose;
        int loop;

        while (loop != 0)
        {
            cout << "Welcome To Online Store !" << endl;
            cout << "1. Access To The Store !" << endl;
            cout << "2. TopUp !" << endl;
            cout << "Press 0 to exit..." << endl;
            cout << "Choose Your Option: ";
            cin >> choose;
            system("cls");
            switch (choose)
            {
            case 1:
                customerBudget();
                // getCustomerInfo();
                buyThings();
                printCustomerInfo();
                printProduct();
                break;
            case 2:
                topUp.topUp();
                break;
            case 0:
                loop = 0;
                break;
            }

            if (loop == 0)
            {
                break;
            }
        }
    }

    void getCustomerInfo()
    {
        customer.getInfo();
    }

    void printCustomerInfo()
    {
        customer.printInfo();
    }
};

int main()
{
    Management manage;
    TopUp topup;
    Security security;
    security.signUp();
    if (security.Login() == true)
    {
        manage.getCustomerInfo();
        manage.chooseOption();
    }

    // Tu Hoang FETEL HCMUS
}