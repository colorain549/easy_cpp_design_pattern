// 小明的购物车(饿汉式/直接初始化)
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
        // 饿汉式/直接初始化
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
// 初始化, 私有的保存实例的静态变量(饿汉式/直接初始化)
ShoppingCartManager *ShoppingCartManager::_pInstance = new ShoppingCartManager();

int main()
{
    string item;
    int quantity;
    ShoppingCartManager *shopCar = ShoppingCartManager::getInstance();
    while (cin >> item >> quantity)
    {
        shopCar->addItem(item, quantity);
    }
    shopCar->display();
    ShoppingCartManager::destroy();

    return 0;
}