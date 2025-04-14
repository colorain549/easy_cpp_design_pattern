// 小明的购物车(饿汉式)
// 1. 线程安全
// 2. 实现简单
// 3. 程序启动时就创建，可能浪费资源
// 4. 需手动管理内存（除非使用智能指针）
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
        return instance;
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
    static ShoppintCartManager *instance;
};
ShoppintCartManager *ShoppintCartManager::instance = new ShoppintCartManager();

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