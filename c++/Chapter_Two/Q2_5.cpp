#include <iostream>

const int STACK_LEN = 10;

class Stack
{
public:
    Stack()
        : m_nTopPoint(-1)
    {
        // do nothing
    }
    void Pop()
    {
        if (m_nTopPoint == -1)
        {
            return;
        }
        data[m_nTopPoint] = 0;
        m_nTopPoint = m_nTopPoint - 1;
    }

    int Push(int a)
    {
        // Õ»ÒÑÂú
        if (m_nTopPoint == (STACK_LEN - 1))
        {
            return 1;
        }

        data[++m_nTopPoint] = a;
        return 0;
    }

    int Top(int &a)
    {
        if (m_nTopPoint == (STACK_LEN - 1))
        {
            return 1;
        }

        a = data[m_nTopPoint];
        return 0;
    }

    void PrintData()
    {
        for (int i = 0; i <= m_nTopPoint; ++i)
        {
            std::cout << data[i] << std::endl;
        }
    }
private:
    int m_nTopPoint;
    int data[STACK_LEN];
};

int main()
{
    Stack st;
    for (int i = 0; i < 11; ++i)
    {
        st.Push(i);
    }

    st.PrintData();

    return 0;
}