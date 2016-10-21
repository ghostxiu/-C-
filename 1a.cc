//10.21������
//����һ����getmin���ܵ�ջ
#include<iostream>
#include<vector>
#include<stdexcept>
#include<gx/gx_stack>
using namespace std;

template <class T>
class GetMinStack{
    private:
        Stack<int> DataStack;//DataStack������ջ
        Stack<int> MinStack;//MinStack����������СԪ��
    public:
        //��ջ
        void Push( T const &elem )
        {
            DataStack.push(elem);
            //����СջΪ�ջ���С�ڵ���ջ��Ԫ��ʱ��Push
            if(MinStack.empty() || elem <= MinStack.top())
            {
                MinStack.push(elem);
            }
        }
        //��ջ
        void Pop()
        {
            if(Empty())
            {
                throw out_of_range("Stack<>::Empty!");
            }
            int x;
            x = DataStack.top();
            DataStack.pop();
            //��ǰԪ��ʱ������СԪ�أ���ջ
            if(x == MinStack.top())
            {
                MinStack.pop();
            }
        }
        //ȡ��Сֵ
        int GetMin()
        {
            return MinStack.top();
        }
        bool Empty()
        {
            return DataStack.empty();
        }

    };

int main()
{
    GetMinStack<int> G;
    int x = 5 ,num;

    try{
        cout <<"Please Enter a Num push in Stack:\n";
        while(x--)
        {
            cin >> num ;
            G.Push(num);
            cout <<"Please Enter a Num push in Stack:\n";
        }
        cout << "\n\n\nNow pull them out!\n\n";
        while(!G.Empty())
        {
            G.Pop();
            cout << "The Min Num in stack now is :" << G.GetMin() << endl;
        }
    }
    catch (exception const& ex)
    {
        cerr << "Exception :" << ex.what() << endl;
		return -1;
    }
    return 0 ;
}
