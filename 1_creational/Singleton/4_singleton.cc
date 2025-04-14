// 小明的购物车(懒汉式)(不推荐)
// 1. 单例/单件(Singleton)
#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

class ShoppintCartManager
{
private:
    ShoppintCartManager() {}

public:
    static ShoppintCartManager *getInstance()
    {
        if (_pInstance == nullptr)
        {
            _pInstance = new ShoppintCartManager();
        }
        return _pInstance;
    }

    void addItem(const string &item, int quantity)
    {
        _cart[item] += quantity;
    }

    void display() const
    {
        for (const auto &it : _cart)
        {
            cout << it.first << " " << it.second;
        }
        cout << endl;
    }

private:
    map<string, int> _cart;
    static ShoppintCartManager *_pInstance;
};
ShoppintCartManager *ShoppintCartManager::_pInstance = nullptr;

int main()
{
    string item;
    int quantity;
    while (cin >> item >> quantity)
    {
        ShoppintCartManager::getInstance()->addItem(item, quantity);
    }
    ShoppintCartManager::getInstance()->display();

    return 0;
}