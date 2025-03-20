// 小明的购物车(懒汉式/惰性初始化)
// 使用map或vector
// 1. 单例/单件(一个静态成员函数)
#include <iostream>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

class ShoppingCartManager
{
    // 构造函数私有化/保护型构造器
private:
    ShoppingCartManager() = default;

public:
    // 公有的静态方法
    static ShoppingCartManager *getInstance()
    {
        // 懒汉式/惰性初始化
        if (_pInstance == nullptr)
        {
            _pInstance = new ShoppingCartManager();
        }
        return _pInstance;
    }

    // 商品添加到购物车(增加const &)
    void addItem(const string &item, int quantity)
    {
        _cart[item] += quantity;
    }

    // 打印商品清单
    void display() const
    {
        for (const auto &it : _cart)
        {
            cout << it.first << " " << it.second << endl;
        }
    }

    // 公有的静态方法
    static void destroy()
    {
        if (_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }

private:
    map<string, int> _cart;
    // 私有的保存实例的静态变量
    static ShoppingCartManager *_pInstance;
};
// 初始化, 私有的保存实例的静态变量(懒汉式/惰性初始化)
ShoppingCartManager *ShoppingCartManager::_pInstance = nullptr;

int main()
{
    string item;
    int quantity;
    while (cin >> item >> quantity)
    {
        ShoppingCartManager *shopCar = ShoppingCartManager::getInstance();
        shopCar->addItem(item, quantity);
        shopCar->display();
        ShoppingCartManager::destroy();
    }

    return 0;
}