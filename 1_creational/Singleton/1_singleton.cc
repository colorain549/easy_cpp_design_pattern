// C++11 的局部静态变量实现(最推荐)
// 1. 线程安全(C++11保证, 局部静态变量初始化线程安全)
// 2. 延迟初始化(第一次调用时才创建)
// 3. 自动释放内存(程序结束时自动析构)
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
    // 私有构造函数
    ShoppintCartManager() {}

public:
    static ShoppintCartManager &getInstance()
    {
        static ShoppintCartManager instance;
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

    // 删除拷贝构造函数和赋值运算符
    ShoppintCartManager(const ShoppintCartManager &) = delete;
    ShoppintCartManager &operator=(const ShoppintCartManager &) = delete;

private:
    map<string, int> _cart;
};

int main()
{
    string item;
    int quantity;
    while (cin >> item >> quantity)
    {
        ShoppintCartManager::getInstance().addItem(item, quantity);
    }
    ShoppintCartManager::getInstance().display();

    return 0;
}