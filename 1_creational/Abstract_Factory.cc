// 家具工厂
// 1. 抽象产品
// 2. 具体产品
// 3. 抽象工厂
// 4. 具体工厂
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 1. 抽象产品
class Chair
{
public:
    virtual void produceChair() = 0;
};

class Sofa
{
public:
    virtual void produceSofa() = 0;
};

// 2. 具体产品
class ClassicalChair : public Chair
{
public:
    void produceChair() override
    {
        cout << "classical chair" << endl;
    }
};

class ModernChair : public Chair
{
public:
    void produceChair() override
    {
        cout << "modern chair" << endl;
    }
};

class ClassicalSofa : public Sofa
{
public:
    void produceSofa() override
    {
        cout << "classical sofa" << endl;
    }
};

class ModernSofa : public Sofa
{
public:
    void produceSofa() override
    {
        cout << "modern sofa" << endl;
    }
};

// 3. 抽象工厂
class Factory
{
public:
    virtual Chair *chairFactory() = 0;
    virtual Sofa *sofaFactory() = 0;
};

// 4. 具体工厂
class ClassicalFactory : public Factory
{
public:
    Chair *chairFactory() override
    {
        Chair *classicalChair = new ClassicalChair();
        return classicalChair;
    }
    Sofa *sofaFactory() override
    {
        Sofa *classicalSofa = new ClassicalSofa();
        return classicalSofa;
    }
};

class ModernFactory : public Factory
{
public:
    Chair *chairFactory() override
    {
        Chair *modernChair = new ModernChair();
        return modernChair;
    }
    Sofa *sofaFactory() override
    {
        Sofa *modernSofa = new ModernSofa();
        return modernSofa;
    }
};

int main()
{
    int N;
    string style;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> style;
        if (style == "modern")
        {
            Factory *factory = new ModernFactory();
            Chair *chairFactory = factory->chairFactory();
            Sofa *sofaFactory = factory->sofaFactory();
            chairFactory->produceChair();
            sofaFactory->produceSofa();
        }
        else if (style == "classical")
        {
            Factory *factory = new ClassicalFactory();
            Chair *chairFactory = factory->chairFactory();
            Sofa *sofaFactory = factory->sofaFactory();
            chairFactory->produceChair();
            sofaFactory->produceSofa();
        }
    }

    return 0;
}