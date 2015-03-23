// Describe how you could use a single array to implement three stacks.
// 思路：可以将数据均分为3段，每段作为一个栈，但是这样有些浪费，所以尝试
// 加入一种数据结构，即每个节点都指向上个节点，这样就可以由底到上填充栈，
// 从而充分利用数组的空间
#include <iostream>

const int STACK_LEN = 200;

struct Node
{
    int data;
    int pre;
    Node()
        : data(0)
        , pre(0)
    {
        // do nothing
    }
};
class Stack
{
public:
    Stack()
        : curr_(0)
    {
        data_ = new Node[STACK_LEN];
        stack_top_[0] = stack_top_[1] = stack_top_[2] = -1;
        curr_ = 0;
    }

	~Stack()
	{
		delete[] data_;
	}
    void Pop(int stack_no)
    {
        if (stack_top_[stack_no] == -1)
        {
            return;
        }

        curr_ = stack_top_[stack_no];
        data_[stack_top_[stack_no]].data = 0;
        stack_top_[stack_no] = data_[stack_top_[stack_no]].pre;
    }

    int Push(const int stack_no, const int a)
    {
        int ret = 0;
        if (stack_no < 0 || stack_no > 2)
        {
            ret = -1;
            return ret;
        }

        if (curr_ >= STACK_LEN)
        {
            std::cout << "栈满了" << std::endl;
            return -1;
        }

        data_[curr_].data = a;
        data_[curr_].pre = stack_top_[stack_no];
        int temp = stack_top_[stack_no];
        // 如果当前位置在数据后，进行数据的扫描，来确定下个位置
        if (temp > curr_)
        {
			stack_top_[stack_no] = curr_;
            while (data_[curr_].data && curr_ < STACK_LEN)
            {
                curr_++;
            }
        }
        else
        {
            stack_top_[stack_no] = curr_;
            curr_++;
        }

            return ret;
    }
	
    int top(const int stack_no, int &top_data)
    {
        int ret = 0;
        if (stack_no < 0 || stack_no > 2)
        {
            ret = -1;
            return ret;
        }
        int stack_curr = stack_top_[stack_no];
        if (stack_curr == -1)
        {
            ret = -1;
            return ret;
        }

        top_data = data_[stack_curr].data;
        return ret;
    }

    void print(const int stack_no)
    {
         if (stack_no < 0 || stack_no > 2)
         {
             return ;
         }
         int temp = stack_top_[stack_no];
         while(data_[temp].pre != -1)
         {
             std::cout << data_[temp].data << std::endl;
             temp = data_[temp].pre;
         }
     }
private:
    int stack_top_[3];                   // 存储三个栈的栈顶
    int curr_;                           // 存储下个数据的位置
    Node* data_;
};

int main()
{
    Stack st;
    for (int i = 0; i < 4; ++i)
    {
        st.Push(0, i);
    }
    st.print(0);
    std::cout << "----------------------" << std::endl;
    for (int i = 10; i < 14; ++i)
    {
        st.Push(1, i);
    }
    st.print(1);
    std::cout << "----------------------" << std::endl;
    for (int i = 20; i < 24; ++i)
    {
        st.Push(2, i);
    } 
    st.print(2);
    std::cout << "----------------------" << std::endl;
    st.Pop(1);
    st.print(1);
    std::cout << "----------------------" << std::endl;
    st.Push(2, 14);
    st.print(2);
    std::cout << "----------------------" << std::endl;
    st.Pop(2);
    st.Push(2, 15);
    st.print(2);
    return 0;
}
