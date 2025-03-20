// 公司组织架构
// 1. 组件
// 2. 叶子
// 3. 组合
// 4. 客户端
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// 1. 组件
class Component
{
public:
    virtual void display(int depth) = 0;
};

// 2. 叶子
class Employee : public Component
{
public:
    Employee(const string &employeeName) : _employeeName(employeeName) {}

    void display(int depth) override
    {
        string indent((depth + 1) * 2, ' ');
        cout << indent << _employeeName << endl;
    }

private:
    string _employeeName;
};

// 3. 组合
class Department : public Component
{
public:
    Department(const string &departName) : _departName(departName) {}

    void add(Component *component)
    {
        _children.push_back(component);
    }

    void display(int depth) override
    {
        string indent(depth * 2, ' ');
        cout << indent << _departName << endl;
        for (Component *component : _children)
        {
            component->display(depth + 1);
        }
    }

private:
    string _departName;
    vector<Component *> _children;
};

// 4. 客户端
class Company
{
public:
    Company(const string &companyName) : _companyName(companyName), _root(new Department(companyName)) {}

    void add(Component *component)
    {
        _root->add(component);
    }

    void display()
    {
        cout << "Company Structure:" << endl;
        _root->display(0);
    }

private:
    string _companyName;
    Department *_root;
};

int main()
{
    string companyName;
    getline(cin, companyName);

    Company company(companyName);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string type, info;
        cin >> type >> info;
        if (type == "D")
        {
            Department *department = new Department(info);
            company.add(department);
        }
        else if (type == "E")
        {
            Employee *employee = new Employee(info);
            company.add(employee);
        }
    }
    company.display();

    return 0;
}