// 适配器
// 1. 目标
// 2. 被适配者
// 3. 适配器
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// 1. 目标
class USB
{
public:
    virtual void chargeWithUSB() = 0;
};

// 2. 被适配者
class TypeC
{
public:
    virtual void chargeWithTypeC() = 0;
};

class TypeCComputer : public TypeC
{
public:
    void chargeWithTypeC() override
    {
        cout << "TypeC" << endl;
    }
};

// 3. 适配器(原有USB接口)
class Adapter : public USB
{
    // 将USB接口转为TypeC接口
private:
    TypeC *_typeC;

public:
    // 初始化TypeC接口
    Adapter(TypeC *typeC) : _typeC(typeC) {}
    // 用USB接口实现TypeC接口 输出TypeC
    void chargeWithUSB() override
    {
        _typeC->chargeWithTypeC();
    }
};

// 其他
class USBAdapter : public USB
{
public:
    void chargeWithUSB() override
    {
        cout << "USB Adapter" << endl;
    }
};

int main()
{
    int N;
    int choice;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> choice;
        if (choice == 1)
        {
            TypeC *typeCComputer = new TypeCComputer();
            typeCComputer->chargeWithTypeC();
        }
        else if (choice == 2)
        {
            USB *usbCharge = new USBAdapter();
            // 这里的 chargeWithUSB 输出 USB Adapter
            usbCharge->chargeWithUSB();
        }
        else if (choice == 3)
        {
            // 电脑的TypeC口
            TypeC *typeCComputer = new TypeCComputer();
            // 使用USB接口的适配器 将适配器的TypeC端与电脑连接
            USB *adapter = new Adapter(typeCComputer);
            // 使用USB接口的适配器 实现TypeC的功能
            // 使用USB接口的适配器 改输出为TypeC(原输出为USB)
            adapter->chargeWithUSB();
        }
    }

    return 0;
}