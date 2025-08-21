# 设计模式（最简单, 最常用的模式）

## 三种模式（据目的准则分类）
1. 创建型（与对象的创建有关）
2. 结构型（处理, 类或对象的组合）
3. 行为型（对类或对象, 怎样交互, 和怎样分配职责, 进行描述）

## 创建型模式（1将对象的部分创建工作, 延迟到子类）（2将它延迟到另一个对象中）
1. Abstract Factory（抽象工厂）（对象创建型模式）（1）
2. Factory Method（工厂方法）（对象创建型模式）（2）
3. Singleton（单例/单件）（对象创建型模式）（1）

## 结构型模式（1使用继承机制来组合类）（2描述了对象的组装方式）
1. Adapter（适配器）（类对象结构型模式）（1、2）
2. Composite（组合）（对象结构型模式）（2）
3. Decorate（装饰）（对象结构型模式）（2）

## 行为型模式（1使用继承, 描述算法和控制流）（2描述了一组对象, 怎样协调完成, 单个对象所无法完成的任务）
1. Observer（观察者）（对象行为型模式）（2）
2. Strategy（策略）（对象行为型模式）（2）
3. Template Method（模板方法）（类行为型模式）（1）

## 实例目录
1. 家具工厂（5）（1抽象产品2具体产品3抽象工厂4具体工厂5客户端）
2. 积木工厂（4）（1产品2具体产品3创建者4具体创建者）
3. 小明的购物车
4. 拓展坞（4）（1目标2被适配者3适配器4客户端）
5. *公司组织架构（4）（1组件2叶3组合4客户端）
6. 咖啡加糖（4）（1组件2具体组件3装饰4具体装饰）
7. *时间观察者（4）（1目标2观察者3具体目标4具体观察者）
8. 超市打折（3）（1策略2具体策略3上下文）
9. 咖啡馆（2）（1抽象类2具体类）

## 家具工厂(3.1)
1. 抽象工厂（Abstract Factory）(类Factory)
2. 具体工厂（Concrete Factory）(类ClassicalFactory, 类ModernFactory)
3. 抽象产品（Abstract Product）(类Chair, 类Sofa)
4. 具体产品（Concrete Product）(类ClassicalChair, 类ModernChair, 类ClassicalSofa, 类ModernSofa)
5. 客户端(Client)(main)
### 目的
* 提供接口
```
// 纯虚函数chairFactory()和, 纯虚函数SofaFactory()
class Factory{
public:
    virtual Chair *chairFactory() = 0;
    virtual Sofa *sofaFactory() = 0;
};
```
* 以创建一系列相关或相互依赖的对象
```
// 堆分配 
// 对象classicalChair, 对象classicalSofa
// 对象modernChair, 对象modernSofa
class ClassicalFactory: public Factory{
public:
    Chair *chairFactory() override {
        Chair *classicalChair = new ClassicalChair();
        return classicalChair;
    }
    Sofa *sofaFactory() override {
        Chair *classicalChair = new ClassicalChair();
        return classicalChair;
    }
    ...
};
```

## 积木工厂(3.3)
1. 产品（Product）(类Block)
2. 具体产品（Concrete Product）(类CircleBlock, 类SquareBlock)
3. 创建者（Creator）(类Factory)
4. 具体创建者（Concrete Creator）(类CircleFactory, 类SquareFactory)
### 目的
* 定义一个用于创建对象的接口
```
class Block{
public:
    virtual void produceBlock() = 0;
};
```
* 让子类决定实例化哪一个类
* 使一个类的实例化延迟到其子类
```
class CircleBlock: public Block {
    ...
};

class SquareBlock: public Block {
    ...
};

// 让子类决定实例化, 类的实例化延迟到其子类
class Factory{
public:
    virtual Block *blockFactory() = 0;
};

class CircleFactory: public Factory {
public:
    Block *blockFactory() override {
        Block *circleBlock = new CircleBlock();
        return circleBlock;
    }
};

class SquareFactory: public Factory {
public:
    Block *squareFactory() override {
        Block *squareBlock = new CircleBlock();
        return squareBlock;
    }
};
```

## 小明的购物车(3.5)
1. 单例/单件（Singleton）
### 目的
* 保证一个类仅有一个实例
* 并提供访问它的一个全局访问点(一个成员静态函数)
```
// 定义一个, 静态成员函数(getInstance())
// 允许客户服务访问它的唯一实例
static ShoppingCartManager *getInstance() {...}
```

## 扩展坞(4.1)
1. 目标（Target）(类USB)
2. 客户端（Client）(main)
3. 被适应者（Adaptee）(类TypeC, 类TypeCComputer)
4. 适配器（Adapter）(类TypeCToUSBAdapter)
### 目的
* 一个类的接口, 转换成客户希望的, 另一个接口
* 使得接口不兼容而不能一起工作的类, 可以一起工作
```
// 适配器(继承自USB 原有USB接口)

class Adapter: public USB {
private:
    // 将USB接口转为TypeC接口
    TypeC *_typeC;
public:
    // 初始化TypeC接口
    Adapter(TypeC *typeC):_typeC(typeC){}
    // 用USB接口实现TypeC接口 输出TypeC
    void chargeWithUSB() override {
        _typeC->chargeWithTypeC();
    }
};
```

## 公司组织架构(4.3)
1. 组件（Component）(类Component)
2. 叶结点（Leaf）(类Employee)
3. 组合（Composite）(类Department)
4. 客户端（Client）(类Company)
### 目的
* 将对象组合成树形结构, 以表示"部份-整体"的层次结构
```
class Department: public Component {
public:
    Department(const string &departmentName):_departmentName(departmentName){}

    void add(Component* component) override {
        _children.push_back(component);
    }

    void display(int depth) override {
        string indent(depth * 2, ' ');
        cout << indent << _departmentName << endl;
        for(Component *component: _children){
            component->display(depth + 1);
        }
    }

private:
    string _departmentName;
    vector<Component*> _children;
};
```
* 使得用户, 对单个对象和组合对象的使用, 具有一致性
### ⚠️注意
```
class Component {...};

class Department: public Component{
public:
    ...
private:
    // ⚠️注意
    vector<Component*> _children;
}

class Company {
public:
    // ⚠️注意, 初始化root
    Company(cpnName):_cpnName(cpnName), _root(new Department(_cpuName)){}

    // ⚠️注意
    void display(){
        cout << "Company Structure:" << endl;
        _root->display(0);
    }

private:
    // ⚠️注意
    Department *_root;
};
```

## 咖啡加糖(4.4)
1. 组件（Component）(类Coffee)
2. 具体组件（Concrete Component）(类AmericanCoffee, 类Latte)
3. 装饰者（Decorator）(类Decorate)
4. 具体装饰者（Concrete Decorator）(类MilkDecorate, 类SugarDecorate)
### 目的
* 动态地给一个对象, 添加一些额外的职责
```
class Coffee {
public:
    virtual void brew() = 0;
};

class Latte: public Coffee {
public:
    void brew() override {...}
};

// ⚠️注意这里, 以公有方式, 继承自Coffee
class Decorate: public Coffee{
public:
    Decorate(Coffee *coffee):_coffee(coffee){}
    void brew() override {
        _coffee->brew();
    }
private:
    Coffee *_coffee;
};

// 动态地给一个对象, 添加一些额外的职责
class MilkDecorate: public Decorate {
public:
    MilkDecorate(Coffee *coffee): Decorate(coffee) {}
    void brew() override { ... }
};

class SugarDecorate: public Decorate {
public:
    SugarDecorate(Coffee *coffee): Decorate(coffee) {}
    void brew() override { ... }
};

int main(){
    // 在堆空间创建一个 Latte 对象，并用基类指针指向它
    Coffee *latte = new Latte();
    // 指针指向 SugarDecorate 对象
    latte = new SugarDecorate(latte);
    // 调用 SugarDecorate 的 brew 方法
    latte->brew(latte);
    delete latte;
}
```
* 就增加功能来说, 比生成子类更为灵活

## 时间观察者(5.7)
1. 目标（Subject）(类Subject, 接口register, 接口remove, 接口notify)
2. 观察者（Observer）(类Observer, 接口update)
3. 具体目标（Concrete Subject）(类Clock, 成员函数getObservers(), 成员函数tick())
4. 具体观察者（Concrete Observer）(类Student, 接口update)
### 目的
1. 定义对象间的一种, 一对多的依赖关系
2. 当一个对象的状态发生改变时
3. 所有依赖于它的对象, 都得到通知并被自动更新
```
// 前向声明
class Observer;

// 目标
class Subject {
public:
    virtual void register(Observer* obsderver) = 0;
    virtual void remove(Observer* obsderver) = 0;
    virtual void notify() = 0;
    ...
};

// 观察者
class Observer {
public:
    virtual void update(int hour) = 0;
    ...
};

// 具体目标
class Clock: public Subject {
public:
    ...
    const vector<Observer*> &getObservers const {...}
    void tick(){...}
};

// 具体观察者
class Student: public Observer {
public:
    ...
    void update(int hour) override {...}
};
```
### ⚠️注意
```
// 具体目标
class Clock: public Subject {
public:
    ...
    const vector<Observer*> &getObservers const {...}
    void tick(){...}
};

// 具体观察者
class Student: public Observer {
public:
    ...
    void update(int hour) override {...}
};
```

## 超市打折(5.9)
1. 策略（Strategy）(类Strategy)
2. 具体策略（Concrete Strategy）(类NinetyPercentStrategy, 类ReduceStrategy)
3. 上下文（Context）(类Context)
### 目的
* 定义一系列的算法, 把它们一个个封装起来, 使它们可相互替换
* 使得算法, 可独立于, 使用它的客户, 而变化
```
class Strategy {
public:
    // 算法
    virtual int applyStrategy(int originalPrice) = 0;
};

// 封装
class NinetyPercentStrategy: public Strategy {
public:
    int applyStrategy(int originalPrice) override {...}
}

class ReduceStrategy: public Strategy {
public:
    int applyStrategy(int originalPrice) override {...}
}
```

## 咖啡店(5.10)
1. 抽象类（Abstract Class）(类Coffee)
2. 具体类（Concrete Class）(类BlackCoffee, 类Latte)
### 目的
* 定义一个操作/函数中算法的骨架
```
class Coffee{
public:
    ...
    // 操作/函数中算法的骨架
    virtual void coffeeTemplate() {
        cout<<_coffeeName;
        grind();
        brew();
        addCondiments();
    }
    virtual void grind() = 0;
    virtual void brew() = 0;
    virtual void addCondiments() {...}
    ...
};
```
* 而将一些步骤延迟到子类中
```
// 步骤延迟到子类中
class AmericanCoffee: public Coffee {
public:
    void grind() override {...}
    void brew() override {...}
}
class Latte: public Coffee {
public:
    void grind() override {...}
    void brew() override {...}
    void addCondiments() override {...}
}
```


