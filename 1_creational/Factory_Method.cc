// 积木工厂
// 1. 产品
// 2. 具体产品
// 3. 创建者
// 4. 具体创建者
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 1. 产品
class Block
{
public:
    virtual void produceBlock() = 0;
};

// 2. 具体产品
class CircleBlock : public Block
{
public:
    void produceBlock() override
    {
        cout << "Circle Block" << endl;
    }
};

class SquareBlock : public Block
{
public:
    void produceBlock() override
    {
        cout << "Square Block" << endl;
    }
};

// 3. 创建者
class Factory
{
public:
    virtual Block *blockFactory() = 0;
};

// 4. 具体创建者
class CircleFactory : public Factory
{
public:
    Block *blockFactory() override
    {
        Block *produceCircleBlock = new CircleBlock();
        return produceCircleBlock;
    }
};

class SquareFactory : public Factory
{
public:
    Block *blockFactory() override
    {
        Block *produceSquareBlock = new SquareBlock();
        return produceSquareBlock;
    }
};

int main()
{
    int N, times;
    string type;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> type >> times;
        for (int i = 0; i < times; i++)
        {
            if (type == "Circle")
            {
                Factory *circleFactory = new CircleFactory();
                Block *circleBlock = circleFactory->blockFactory();
                circleBlock->produceBlock();
            }
            else if (type == "Square")
            {
                Factory *squareFactory = new SquareFactory();
                Block *squareBlock = squareFactory->blockFactory();
                squareBlock->produceBlock();
            }
        }
    }

    return 0;
}