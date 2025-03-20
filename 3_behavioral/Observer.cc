// 时间观察者(5.7)
// 1. 目标(Subject)(类Subject, 接口register, 接口remove, 接口notify)
// 2. 观察者(Observer)(类Observer, 接口update)
// 3. 具体目标(Concrete Subject)(类Clock, 成员函数getObservers(), 成员函数tick())
// 4. 具体观察者(Concrete Observer)(类Student, 接口update)
#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::find;
using std::string;
using std::vector;

class Observer;
// 1. 目标(Subject)
class Subject
{
public:
    // 注册
    virtual void registerObserver(Observer *observer) = 0;
    // 移除
    virtual void removeObserver(Observer *observer) = 0;
    // 通知
    virtual void notifyObservers() = 0;
    virtual ~Subject() {}
};

// 2. 观察者(Observer)
class Observer
{
public:
    virtual void update(int hour) = 0;
    virtual ~Observer() {}
};

// 3. 具体目标(Concrete Subject)
class Clock : public Subject
{
public:
    Clock() : _hour(0) {}

    void registerObserver(Observer *observer) override
    {
        _observers.push_back(observer);
    }
    // 移除
    void removeObserver(Observer *observer) override
    {
        auto it = find(_observers.begin(), _observers.end(), observer);
        if (it != _observers.end())
        {
            _observers.erase(it);
        }
    }
    // 通知
    void notifyObservers() override
    {
        for (Observer *observer : _observers)
        {
            observer->update(_hour);
        }
    }

    // 添加获取观察者的函数
    const vector<Observer *> &getObservers() const
    {
        return _observers;
    }

    void tick()
    {
        _hour = (_hour + 1) % 24;
        notifyObservers();
    }

private:
    int _hour;
    vector<Observer *> _observers;
};

// 4. 具体观察者(Concrete Observer)
class Student : public Observer
{
public:
    Student(const string &name) : _name(name) {}

    void update(int hour) override
    {
        cout << _name << " " << hour << endl;
    }

private:
    string _name;
};

int main()
{
    // 读取学生数量
    int N;
    std::cin >> N;

    // 创建时钟
    Clock clock;

    // 注册学生观察者
    for (int i = 0; i < N; i++)
    {
        std::string studentName;
        std::cin >> studentName;
        clock.registerObserver(new Student(studentName));
    }

    // 读取时钟更新次数
    int updates;
    std::cin >> updates;

    // 模拟时钟每隔一个小时更新一次
    for (int i = 0; i < updates; i++)
    {
        clock.tick();
    }

    // 释放动态分配的观察者对象
    for (Observer *observer : clock.getObservers())
    {
        delete observer;
    }

    return 0;
}