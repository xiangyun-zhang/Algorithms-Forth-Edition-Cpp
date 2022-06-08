#include <iostream>
#include <vector>

template <typename T>
class MyStack
{
private:
    int m_size;
    std::vector<T> m_data{};

public:

    MyStack()
    {
        m_size = 0;
    }

    int size()
    {
        return m_size;
    }

    void push(T val)
    {
        m_data.push_back(val);
        m_size++;
    }

    void pop()
    {
        if (m_size > 0)
        {
            m_data.pop_back();
            m_size--;
        }
    }

    T top()
    {
        return m_data[m_size - 1];
    }

    void printMyStack()
    {
        for (int i = 0; i < m_size; i++) {
            std::cout << m_data[i] << ' ';
        }
        std::cout << std::endl;
    }
};

int main()
{
    MyStack<int> test1;
    test1.printMyStack();
    test1.push(12);
    test1.printMyStack();
    test1.push(15);
    test1.printMyStack();
    test1.push(13);
    test1.printMyStack();
    int temp = test1.top();
    test1.pop();
    test1.printMyStack();
    test1.push(temp + 100);
    test1.printMyStack();
    test1.push(25);
    test1.printMyStack();
    std::cout << temp;

    return 0;
}