#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
class Product
{
public:
    Product() {}
    string name;
    float price;
};
class Store
{
public:
    void DisplayAvailableProducts()
    {
        // To Display Products Available in the Store
        cout << "Here is a list of all Products available in the Store!" << endl;
        ifstream proFile;
        proFile.open("Product.txt");
        string names;
        string prices;
        while (proFile >> names >> prices)
        {
            cout << "Product Name : " << names << endl;
            cout << "Product Price : " << prices << endl
                 << endl;
        }
    }

    void addProduct()
    {
        // To add Products in the Store
        bool flag = true;
        string pro_name;
        string checkName;
        string checkPrice;
        string pro_price;
        DisplayAvailableProducts();
        do
        {
            cout << "Enter Name of the Product you want to add : " << endl;
            cin >> pro_name;
            cout << "Enter Price : " << endl;
            cin >> pro_price;

            fstream File;
            File.open("Product.txt", ios::app);
            while (File >> checkName >> checkPrice)
            {
                if (checkName == pro_name)
                {
                    cout << "Product already Exist!" << endl;
                    flag = false;
                    break;
                }
                else
                {
                    flag = true;
                }
            }
            File.close();
        } while (flag == false);

        if (flag)
        {
            fstream File;
            cout << "Product Added Successfully!" << endl;
            File.open("Product.txt", ios::app);
            File << pro_name << " " << pro_price << endl;
            File.close();
        }
    }
    void removeProduct()
    {
        // To Remove Prduct from Store
        DisplayAvailableProducts();
        string product;
        string price;
        bool flag = false;
        string product_file;
        string price_file;
        string newAccounts = "";
        cout << "Enter the name of the product you want to remove from Store : " << endl;
        cin >> product;
        ifstream file;
        file.open("Product.txt");
        do
        {
            if (!(product == product_file))
            {
                newAccounts = newAccounts + product_file + " " + price_file + "\n";
                flag = true;
            }
        } while (file >> product_file >> price_file);
        ofstream newfile;
        newfile.open("Product.txt", ios::out);
        newfile << newAccounts;
        newfile.close();
        file.close();
        if (flag)
        {
            cout << "Product deleted Successfully" << endl;
        }
        else
        {
            cout << "Product not deleted" << endl;
        }
    }
};
class Manager : public Store
{
protected:
    string username;
    string password;

public:
    void RemoveUser()
    {
        // To Remove User
        string del_user;
        string newAccounts = "";
        string user_file;
        string password_file;
        string del_pass;
        ifstream file;
        file.open("userData.txt");
        cout << "Enter Name of the User you want to delete" << endl;
        cin >> del_user;
        cout << "Enter Password of the User you want to delete" << endl;
        cin >> del_pass;
        do
        {
            if (!(del_user == user_file))
            {
                newAccounts = newAccounts + user_file + " " + password_file + "\n";
            }
        } while (file >> user_file >> password_file);
        ofstream newfile;
        newfile.open("userData.txt", ios::out);
        newfile << newAccounts;
        newfile.close();
        cout << "Account deleted Successfully" << endl;
        file.close();
    }
    void seeUsers()
    {
        // To see all Users
        cout << "Here is a list of all Users!";
        ifstream userfile;
        userfile.open("userData.txt");
        string user_name;
        string password_1;
        do
        {
            cout << user_name << endl;
        } while (userfile >> user_name >> password_1);
    }
    void login()
    {
        // To Login
        bool isloggedin = false;
        {
            string checkUsername, checkPassword;
            cout << "For Login" << endl;
            cout << "Enter User Name : " << endl;
            cin >> checkUsername;
            cout << "Enter Password : " << endl;
            cin >> checkPassword;
            fstream File;
            File.open("managerData.txt", ios::in);
            ifstream f("managerData.txt");
            while (f >> username >> password)
            {
                if (checkUsername == username && checkPassword == password)
                {
                    isloggedin = true;
                    break;
                }
                else
                {
                    isloggedin = false;
                }
            }
            if (isloggedin == true)
            {
                cout << "Login succeed!" << endl;
                cout << "Redirecting to Main Menu Please Wait" << endl;
            }
            else if (isloggedin == false)
            {
                cout << "Wrong Credentials" << endl;
                system("pause");
                exit(1);
            }
            File.close();
        }
    }

    void registerUser()
    {
        // To Register New User
        bool flag = true;
        cout << "To Register Enter given Details : " << endl;
        do
        {
            cout << "Enter User Name : ";
            cin >> this->username;
            cout << "Enter Password : ";
            cin >> this->password;

            fstream File;
            File.open("userData.txt", ios::app);
            while (!File.eof())
            {
                string checkName;
                string checkPassword;
                File >> checkName >> checkPassword;
                if (checkName == username)
                {
                    cout << "Username is already taken!" << endl;
                    cout << "Enter Details again" << endl;
                    flag = false;
                    break;
                }
                else
                {
                    flag = true;
                }
            }
            File.close();
        } while (flag == false);

        if (flag)
        {
            fstream File;
            cout << "User"
                 << "\"" << username << "\""
                 << "registered successfully!" << endl;
            File.open("userData.txt", ios::app);
            File << username << " " << password << endl;
            File.close();
        }
    }
};
class User : public Manager
{
private:
    string username;
    string password;

public:
    void RemoveFromCart()
    {
        // To Remove Prduct from Cart
        string product;
        string price;
        bool flag = false;
        string product_file;
        string price_file;
        string newAccounts = "";
        cout << "Enter the name of the product you want to remove from your Cart" << endl;
        cin >> product;
        ifstream file;
        file.open("Cart.txt");
        do
        {
            if (!(product == product_file))
            {
                newAccounts = newAccounts + product_file + " " + price_file + "\n";
                flag = true;
            }
        } while (file >> product_file >> price_file);
        ofstream newfile;
        newfile.open("Cart.txt", ios::out);
        newfile << newAccounts;
        newfile.close();
        file.close();
        if (flag)
        {
            cout << "Product deleted Successfully" << endl;
        }
        else
        {
            cout << "Product not deleted" << endl;
        }
    }
    void Buy()
    {
        // To Buy Products
        string buy;
        string price;
        string file_pro;
        string file_pri;
        bool flag = false;
        bool flag1 = false;
        cout << "Enter the name of the product you want to Buy : " << endl;
        cin >> buy;
        ofstream cart;
        ifstream file;
        file.open("Product.txt");
        cart.open("Cart.txt", ios::app);
        while (file >> file_pro >> file_pri)
        {
            if (buy == file_pro)
            {
                flag = true;
                buy = file_pro;
                price = file_pri;
                break;
            }
        }
        if (!flag)
        {
            cout << "Prduct does not Exist" << endl;
        }
        if (flag)
        {
            cout << "Product Exists" << endl;
            flag1 = true;
            cart << buy << " " << price << endl;
        }
        if (flag1)
        {
            cout << "Product Added to your Cart Successfully" << endl;
        }
        file.close();
        cart.close();
    }
    void seeCart()
    {
        // To see Products in your cart
        cout << "Here is your Cart" << endl;
        ifstream cartFile;
        cartFile.open("Cart.txt");
        string Cart_pro;
        string Cart_prices;
        while (cartFile >> Cart_pro >> Cart_prices)
        {
            cout << "Product Name : " << Cart_pro << endl;
            cout << "Product Price : " << Cart_prices << endl
                 << endl;
        }
    }
    void logout()
    {
        cout << "Successfully Logged Out" << endl;
        // To Log Out
    }
    void login()
    {
        // To Login
        bool isloggedin = false;
        {
            string checkUsername, checkPassword;
            cout << "For Login" << endl;
            cout << "Enter User Name : " << endl;
            cin >> checkUsername;
            cout << "Enter Password : " << endl;
            cin >> checkPassword;
            fstream File;
            File.open("userData.txt", ios::in);
            ifstream f("userData.txt");
            while (f >> username >> password)
            {
                if (checkUsername == username && checkPassword == password)
                {
                    isloggedin = true;
                    break;
                }
                else
                {
                    isloggedin = false;
                }
            }
            File.close();
            if (isloggedin)
            {
                cout << "Login succeed!" << endl;
                cout << "Redirecting to the Main Menu" << endl;
                system("pause");
            }
            else
            {
                cout << "Wrong Credentials" << endl;
                system("pause");
                exit(1);
            }
        }
        while (!isloggedin)
            ;
    }
};
void GroupMembers()
{
    cout << "Chief Executive Officer : Hifza" << endl;
    cout << "Roll No. : 2022-CS-602" << endl
         << endl;
    cout << "Chief Operating Officer : Muhmmad Zaid Latif" << endl;
    cout << "Roll No. : 2022-CS-617" << endl
         << endl;
    cout << "Head Of Sweepers : Faiq Ahmad" << endl;
    cout << "Roll No. : 2022-CS-618" << endl
         << endl;
}
void DisplayLogo()
{
    cout << "--------------------WEILCOME TO E-COMMERCE MANAGEMENT SYSTEM--------------------" << endl;
    cout << "-------------------------A PLACE TO FULFILL YOUR NEEDS--------------------------" << endl
         << endl;
}
void selfservice()
{
    cout << "------------------------Welcome to Self-Service Area----------------------------" << endl;
}
void callAll()
{
    system("cls");
    DisplayLogo();
    GroupMembers();
    selfservice();
}
int main()
{
    Manager manager1;
    User user;
    string option1;
    string after_login;
    callAll();
    string choice;
    string signin;
    cout << "Press 1 if you are a Manager" << endl;
    cout << "Press 2 if you are a Customer" << endl;
    cin >> choice;
    if (choice == "1")
    {
        manager1.login();
        system("pause");
        callAll();
        cout << "Press 1 to see all Products" << endl;
        cout << "Press 2 to see all Users" << endl;
        cout << "Press 3 to delete User" << endl;
        cout << "Press 4 to add a User" << endl;
        cout << "Press 5 to add a Product" << endl;
        cout << "Press 6 to remove a Product" << endl;
        cin >> after_login;
        if (after_login == "1")
        {
            manager1.DisplayAvailableProducts();
        }
        else if (after_login == "2")
        {
            callAll();
            manager1.seeUsers();
        }
        else if (after_login == "3")
        {
            manager1.RemoveUser();
        }
        else if (after_login == "4")
        {
            callAll();
            user.registerUser();
        }
        else if (after_login == "5")
        {
            manager1.addProduct();
        }
        else if (after_login == "6")
        {
            manager1.removeProduct();
        }
        else
        {
            cout << "Wrong Option Selected!" << endl;
        }
    }
    else if (choice == "2")
    {
        // User Module
        cout << "Press 1 for SignUP" << endl;
        cout << "Press 2 for Login" << endl;
        cin >> signin;
        if (signin == "1")
        {
            system("pause");
            callAll();
            user.registerUser();
            user.login();
        }
        else if (signin == "2")
        {
            User user;
            user.login();
        }
        else
        {
            cout << "Wrong Option Selected!" << endl;
            system("pause");
            exit(1);
        }
        callAll();
        cout << "Press 1 to see all Products" << endl;
        cout << "Press 2 to Buy Prducts" << endl;
        cout << "Press 3 to see your Cart" << endl;
        cout << "Press 4 to remove product from your cart" << endl;
        cout << "Press 5 to Log Out" << endl;
        cin >> option1;
        if (option1 == "1")
        {
            manager1.DisplayAvailableProducts();
        }
        else if (option1 == "2")
        {
            manager1.DisplayAvailableProducts();
            user.Buy();
        }
        else if (option1 == "3")
        {
            user.seeCart();
        }
        else if (option1 == "4")
        {
            user.seeCart();
            user.RemoveFromCart();
        }
        else if (option1 == "5")
        {
            user.logout();
        }
        else
        {
            cout << "Wrong Choice" << endl;
        }
    }
    else
    {
        cout << "Wrong Choice" << endl;
        system("pause");
        exit(1);
    }
    system("pause");
    return 0;
}
