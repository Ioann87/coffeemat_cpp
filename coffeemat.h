#ifndef COFFEEMAT_H
#define COFFEEMAT_H
#include <string>
#include <vector>

inline std::string PATH = "/home/shastiva/c_projects/homework28/coffee_list";

class Coffeemat {
    std::vector<char> code;
    std::vector<std::string> names;
    std::vector<double> price;
    std::vector<int> count;
    std::vector<int> sales;
    int counter;
    double balance;

public:
    Coffeemat();
    ~Coffeemat() {};
    void set_code(char);
    std::vector<char> get_code() const;
    void set_names(std::string);
    std::vector<std::string> get_names() const;
    void set_price(double);
    std::vector<double> get_price() const;
    void set_count(int);
    std::vector<int> get_count() const;
    void set_sales(int);
    std::vector<int> get_sales() const;
    void set_counter(int);
    int get_counter() const;
    void set_balance(int);
    double get_balance() const;

    void init_coffeemat();
    void start();
    bool check_coffee(char&, double&);
    void choose_coffee(double&);
    double calculate(double&, char&);
    void show_statistic();
    void add_coffee();
};

#endif // COFFEEMAT_H
