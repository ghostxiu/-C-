//�㷨1�����һ����getmin���ܵ�ջ
//����1���ռ���ʤ
#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<stdexcept>
#include<cstring>

using namespace std ;

template <class S>
class Stack{
    protected:
        vector<S> elems ;
    public:
        S top() const //ջ��ָ��
        {
            if(elems.empty())
            {
                throw out_of_range("Stack<>::pop : empty stack");
            }
            return elems.back();

        }
        //�麯����Ҫ��������
        virtual void push(S const& elem)
        {
            //����Ԫ��
            elems.push_back(elem);
        }
        virtual void pop( )
        {
            if(elems.empty())
            {
                throw out_of_range("Stack<>::pop : empty stack");
            }
            elems.pop_back();
            //A reference to the last element in the vector
        }
        bool empty () const
        {
            return elems.empty();
        }
};

//������Сֵ��ջ���ǻ���stack���������
template <class S1>
class MinStack:public Stack<S1>{
    protected:
        vector<S1> elems ;
    public:
        S1 top() const //ջ��ָ��
        {
            if(elems.empty())
            {
                throw out_of_range("Stack<>::pop : empty stack");
            }
            return elems.back();

        }
        //���ػ����push����,������Ԫ��С�ڻ����ջ��Ԫ��ʱ����push
        void push(S1 const& elem)
        {
            //minstackΪ�գ�����Ԫ��
            if(elems.empty())
            {
                elems.push_back(elem);
            }
            //������Ԫ��С�ڻ����ջ��Ԫ��ʱ
            if(elem <= elems.back())
            {
                elems.push_back(elem);
            }

        }

        //���ػ����pop��������ջ��Ԫ�ص���stack��ջԪ��ʱ��minstack��ջ
        void pop( S1 const& elem )
        {
            if(elems.empty())
            {
                throw out_of_range("Stack<>::pop : empty stack");
            }
            if(elem == elems.back())
            {
                elems.pop_back();
            }
            cout << "The mini value in stack is :" << elems.back()
                 << endl ;

        }
        bool empty () const
        {
            return elems.empty();
        }
};

int main()
{
    Stack<int> stackData;     // stackData�洢����
    MinStack<int> stackMin; // stackMin�洢������Сֵ
    int x,v;//x���ڼ�¼��ջԪ�أ�v���ڼ�¼��ջԪ��

    try{


        //��ջ
        cout << "Push a New num :" ;
        cin >> x;
        stackData.push(x);
        stackMin.push(x);

        cout << "Now the mini Data is :"
             << stackMin.top() << endl;

        cout << "Push a New num :" ;
        cin >> x;
        stackData.push(x);
        stackMin.push(x);
        cout << "Now the mini Data is :"
             << stackMin.top() << endl;

        cout << "Push a New num :" ;
        cin >> x;
        stackData.push(x);
        stackMin.push(x);
        cout << "Now the mini Data is :"
             << stackMin.top() << endl;

        cout << "Push a New num :" ;
        cin >> x;
        stackData.push(x);
        stackMin.push(x);
        cout << "Now the mini Data is :"
             << stackMin.top()<< endl<<endl<<endl<<endl;




        //��ջ

        v = stackData.top();stackData.pop();
        cout << v << " is out of the stack\n";
        stackMin.pop(v);
        v = stackData.top();stackData.pop();
        cout << v << " is out of the stack\n";
        stackMin.pop(v);
                v = stackData.top();stackData.pop();
        cout << v << " is out of the stack\n";
        stackMin.pop(v);
        v = stackData.top();stackData.pop();
        cout << v << " is out of the stack\n";
        stackMin.pop(v);

    }
    catch (exception const &ex)
    {
        cerr << "Exception :" << ex.what() << endl ;
        return -1;
    }
    return 0;
}
//xxx��ģ�������
