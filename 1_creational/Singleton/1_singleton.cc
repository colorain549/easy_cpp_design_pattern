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
    // (1)私有构造函数
    ShoppintCartManager() {}

public:
    // (2)公有有静态函数
    static ShoppintCartManager &getInstance()
    {
        static ShoppintCartManager instance;
        return instance;
    }

    // (3)添加项目
    void addItem(const string &item, int quantity)
    {
        _cart[item] += quantity;
    }

    // (4)打印项目清单
    void display() const
    {
        for (const auto &it : _cart)
        {
            cout << it.first << " " << it.second;
        }
        cout << endl;
    }

    // (5)使用=delete阻止拷贝类对象
    // 将拷贝构造函数和拷贝赋值运算符 定义为删除的函数 阻止拷贝
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