// 超市打折
// 1. 策略
// 2. 具体策略
// 3. 上下文
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::round;

// 1. 策略
class Strategy
{
public:
    virtual int applyStrategy(int originalPrice) = 0;
    virtual ~Strategy() {}
};

// 2. 具体策略
class NinetyPercentStrategy : public Strategy
{
public:
    int applyStrategy(int originalPrice) override
    {
        return static_cast<int>(round(originalPrice * 0.9));
    }
};

class ReduceStrategy : public Strategy
{
private:
    int thresholds[4] = {100, 150, 200, 300};
    int discounts[4] = {5, 15, 25, 40};

public:
    int applyStrategy(int originalPrice) override
    {
        for (int i = sizeof(thresholds) / sizeof(thresholds[0]) - 1; i >= 0; i--)
        {
            // 注意这里是 >=
            if (originalPrice >= thresholds[i])
            {
                return originalPrice - discounts[i];
            }
        }
        return originalPrice;
    }
};

// 3. 上下文
class Context
{
private:
    Strategy *_strategy;

public:
    void setStrategy(Strategy *strategy)
    {
        this->_strategy = strategy;
    }

    int applyStrategy(int originalPrice)
    {
        return _strategy->applyStrategy(originalPrice);
    }
};

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int M, strategyType;
        cin >> M >> strategyType;

        Strategy *strategy;
        if (strategyType == 1)
        {
            strategy = new NinetyPercentStrategy();
        }
        else if (strategyType == 2)
        {
            strategy = new ReduceStrategy();
        }

        Context *context = new Context;
        context->setStrategy(strategy);
        int discountPrice = context->applyStrategy(M);
        cout << discountPrice << endl;

        delete strategy;
        delete context;
    }

    return 0;
}