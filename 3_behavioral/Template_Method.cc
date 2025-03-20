// 咖啡店(美式咖啡(American Coffee)和拿铁(Latte))
// 1. 抽象类
// 2. 具体类
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 1. 抽象类
class Coffee
{
public:
    // 注意构造函数
    Coffee(const string &coffeeName) : _coffeeName(coffeeName) {}

    virtual void coffeeTemplate()
    {
        cout << "Making " << _coffeeName << ":" << endl;
        grind();
        brew();
        addCondiments();
        cout << endl;
    }

    virtual void grind() = 0;
    virtual void brew() = 0;

    virtual void addCondiments()
    {
        cout << "Adding condiments" << endl;
    }

private:
    string _coffeeName;
};

// 2. 具体类
class AmericanCoffee : public Coffee
{
public:
    // 注意构造函数
    AmericanCoffee(const string &coffeeName) : Coffee(coffeeName) {}
    void grind() override
    {
        cout << "Grinding coffee beans" << endl;
    }
    void brew() override
    {
        cout << "Brewing coffee" << endl;
    }
};

class Latte : public Coffee
{
public:
    Latte(const string &coffeeName) : Coffee(coffeeName) {}
    void grind() override
    {
        cout << "Grinding coffee beans" << endl;
    }
    void brew() override
    {
        cout << "Brewing coffee" << endl;
    }
    void addCondiments() override
    {
        cout << "Adding milk" << endl;
        cout << "Adding condiments" << endl;
    }
};

int main()
{
    int choice;
    while (cin >> choice)
    {
        if (choice == 1)
        {
            Coffee *americanCoffee = new AmericanCoffee("American Coffee");
            americanCoffee->coffeeTemplate();
            delete americanCoffee;
        }
        else if (choice == 2)
        {
            Coffee *latte = new Latte("Latte");
            latte->coffeeTemplate();
            delete latte;
        }
    }

    return 0;
}