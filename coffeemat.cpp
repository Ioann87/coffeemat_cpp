#include "coffeemat.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <unistd.h>

Coffeemat::Coffeemat()
{
    code.reserve(9);
    names.reserve(9);
    price.reserve(9);
    count.reserve(9);
    sales.reserve(9);
    counter = 0;
    balance = 10000;
}
void Coffeemat::init_coffeemat()
{
    std::ifstream coffee_list;
    coffee_list.open(PATH);
    std::string name;
    char ch = 'A';
    while (getline(coffee_list, name)) {
        code.push_back(ch++);
        names.push_back(name);
        price.push_back((rand() % 30 + 15) * 0.1);
        count.push_back(10);
        sales.push_back(0);
    }
    coffee_list.close();
    return;
}

void Coffeemat::start()
{
    std::cout << "Welcom!" << std::endl;
    for (size_t i = 0; i < names.size(); i++) {
        std::cout << code[i] << " " << names[i] << " "
                  << std::fixed << std::setprecision(2)
                  << price[i] << '\n';
    }

    std::cout << "Throw the money into mashine(blr): " << std::endl;
    std::cout << "Coins - 5, 10, 20, 50(kop); 1 , 2(rub)" << std::endl;
    std::cout << "Paiper - 5, 10, 20" << std::endl;
    double money = 0.0;
    std::cin >> money;
    if (money == 200) {
        std::cout << "Administrator mode" << std::endl;
        std::cout << "Choose actions: " << std::endl;
        std::cout << "1 - show statistic; 2 - add coffee: " << std::endl;
        int choice = 0;
        std::cin >> choice;
        switch (choice) {
        case 1:
            show_statistic();
            start();
            break;
        case 2:
            add_coffee();
        default:
            start();
        }
    }
    for (size_t i = 0; i < names.size(); i++) {
        if (money >= price[i]) {
            std::cout << code[i] << " " << names[i] << " "
                      << std::fixed << std::setprecision(2)
                      << price[i] << '\n';
        }
    }
    choose_coffee(money);
    return;
}
bool Coffeemat::check_coffee(char& choice, double& money)
{
    for (size_t i = 0; i < code.size(); i++) {
        if (choice == code[i] && count[i] != 0 && money >= price[i])
            return true;
    }
    return false;
}

void Coffeemat::choose_coffee(double& money)
{
    std::cout << "Choose a coffee: ";
    char choice = '\0';
    std::cin >> choice;
    std::cin.ignore();
    if (check_coffee(choice, money)) {
        std::cout << "Waiting..." << std::endl;
        sleep(10);
        std::cout << "Take you coffee" << std::endl;
        double money_back = 0.0;
        money_back = calculate(money, choice);
        std::cout << "Money back: " << money_back << std::endl;
        start();
    } else {
        std::cout << "Sorry, coffee isn't" << std::endl;
        std::cout << "Take your money back" << std::endl;
        start();
    }
    return;
}

double Coffeemat::calculate(double& money, char& choice)
{
    count[(int)choice - 65] -= 1;
    sales[(int)choice - 65] += 1;
    counter += 1;

    double money_back = 0.0;
    money_back = money - price[(int)choice - 65];
    balance += price[(int)choice - 65] * 100;
    return money_back;
}

void Coffeemat::show_statistic()
{
    for (size_t i = 0; i < names.size(); i++) {
        std::cout << names[i] << " count saled - " << count[i]
                  << " profit: " << (10 - count[i]) * price[i] << std::endl;
    }
    std::cout << "Ballance: " << std::fixed
              << std::setprecision(2) << balance / 100
              << std::endl;
    std::cout << "Total saled: " << counter << std::endl;
    return;
}
void Coffeemat::add_coffee()
{
    std::cout << "Enter code:";
    char code = '\0';
    std::cin >> code;
    this->code.push_back(code);

    std::cout << "Enter name:";
    std::string name;
    std::cin >> name;
    this->names.push_back(name);

    std::cout << "Enter price:";
    double price = 0.0;
    std::cin >> price;
    this->price.push_back(price);

    std::cout << "Enter count:";
    int count = 0;
    std::cin >> count;
    this->count.push_back(count);
    this->sales.push_back(0);

    std::fstream coffee_list;
    coffee_list.open(PATH, std::ios::app);
    coffee_list << name;
    coffee_list.close();

    return;
}

void Coffeemat::set_code(char code)
{
    this->code.push_back(code);
    return;
}
std::vector<char> Coffeemat::get_code() const
{
    return code;
}
void Coffeemat::set_names(std::string name)
{
    this->names.push_back(name);
    return;
}
std::vector<std::string> Coffeemat::get_names() const
{
    return names;
}

void Coffeemat::set_price(double price)
{
    this->price.push_back(price);
    return;
}
std::vector<double> Coffeemat::get_price() const
{
    return price;
}
void Coffeemat::set_count(int count)
{
    this->count.push_back(count);
    return;
}
std::vector<int> Coffeemat::get_count() const
{
    return count;
}
void Coffeemat::set_sales(int sale)
{
    this->sales.push_back(sale);
    return;
}
std::vector<int> Coffeemat::get_sales() const
{
    return sales;
}
void Coffeemat::set_counter(int counter)
{
    this->counter = counter;
    return;
}
int Coffeemat::get_counter() const
{
    return counter;
}
void Coffeemat::set_balance(int balance)
{
    this->balance = balance;
    return;
}
double Coffeemat::get_balance() const
{
    return balance;
}
