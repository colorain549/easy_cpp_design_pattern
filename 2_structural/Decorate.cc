// 咖啡加糖()
// 1. 组件
// 2. 具体组件
// 3. 装饰
// 4. 具体装饰
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 1. 组件
class Coffee
{
public:
    virtual void brew() = 0;
    virtual ~Coffee() {}
};

// 2. 具体组件
class AmericanCoffee : public Coffee
{
public:
    void brew() override
    {
        cout << "Brewing Black Coffee" << endl;
    }
};

class Latte : public Coffee
{
public:
    void brew() override
    {
        cout << "Brewing Latte" << endl;
    }
};

// 3. 装饰
class Decorate : public Coffee
{
public:
    Decorate(Coffee *coffee) : _coffee(coffee) {}

    void brew() override
    {
        _coffee->brew();
    }

private:
    Coffee *_coffee;
};

// 4. 具体装饰
class MilkDecorate : public Decorate
{
public:
    MilkDecorate(Coffee *coffee) : Decorate(coffee) {}

    void brew() override
    {
        Decorate::brew();
        cout << "Adding Milk" << endl;
    }
};

class SugarDecorate : public Decorate
{
public:
    SugarDecorate(Coffee *coffee) : Decorate(coffee) {}

    void brew() override
    {
        Decorate::brew();
        cout << "Adding Sugar" << endl;
    }
};

int main()
{
    int coffeeType, condimentType;
    while (cin >> coffeeType >> condimentType)
    {
        Coffee *coffee;
        if (coffeeType == 1)
        {
            coffee = new AmericanCoffee();
        }
        else if (coffeeType == 2)
        {
            coffee = new Latte();
        }
        if (condimentType == 1)
        {
            coffee = new MilkDecorate(coffee);
        }
        else if (condimentType == 2)
        {
            coffee = new SugarDecorate(coffee);
        }
        if (coffee)
        {
            coffee->brew();
        }
        delete coffee;
    }

    return 0;
}