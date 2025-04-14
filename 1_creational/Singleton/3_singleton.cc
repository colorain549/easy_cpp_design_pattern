// 小明的购物车(双重检查锁定的懒汉式)
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
        ShoppintCartManager *tmp = instance.load(std::memory_order_relaxed);
        if (tmp == nullptr)
        {
            std::lock_guard<std::mutex> lock(mtx);
            tmp = instance.load(std::memory_order_relaxed);
            if (tmp == nullptr)
            {
                tmp = new ShoppintCartManager();
                instance.store(tmp, std::memory_order_release);
            }
        }
        return tmp;
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
    static std::atomic<ShoppintCartManager *> instance;
    static std::mutex mtx;
};

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