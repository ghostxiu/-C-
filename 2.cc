//������ջģ��һ������
#include<iostream>
#include<vector>
#include<stdexcept>
#include<gx/gx_stack>
//gx_stack��һ����ghostxiu��д��ͷ�ļ���vector����һ��stack
using namespace std;

template <class T>
class TwoStackQueue
{
public:
	Stack <int> InStack;//��ջ�����Ԫ���Ƚ����ջ
	Stack <int> OutStack;//��ջ������Ԫ�شӴ˶����߳�

	int x;
	//���
	void InQueue(T const& elem)
	{
		InStack.push(elem);
	}

	int o;
	void out()
	{
		//��ջ
		while (!InStack.empty())
		{//ֻҪ��ջ��Ϊ�����Ԫ�شӶ�ջ�Ƶ���ջ
			o = InStack.top();
			InStack.pop();//xxx�����˶�ջ�ĳ�ջ����������ѭ��
			OutStack.push(o);
		}
	}

	//����
	int OutQueue()
	{

		if (EmptyQ())//�������Ԫ��Ϊ�գ��������׳��쳣
		{
			throw out_of_range("Queue<>::Out ::emptyQueue\n");
		}

		//�����ջ�ǿն���ջΪ�գ����Ԫ��ȫ�������ջ
		if (OutStack.empty() && !InStack.empty())
		{
			out();
		}
        //�����ջ��Ϊ��
		if (!OutStack.empty())
		{
			x = OutStack.top();
		}
		OutStack.pop();//��ջ��Ԫ�س���--xxx����λ�ã�������д����
		return x;
	}


	//����Ԫ��

	int top()//ջ��ָ��
	{
		if (InStack.empty() && OutStack.empty())
		{//��ջΪ�����Ϊ�ն�
			throw out_of_range("Stack<>::pop : empty stack");
		}
		else if (OutStack.empty() && !InStack.empty())
		{
		    //����ջ�գ���ջ�ǿգ��򽫶�ջԪ��ѹ���ջ
			out();
		}
		//����Ԫ��ʼ���ǳ�ջ��ջ��Ԫ��
		return OutStack.top();
	}

	bool EmptyQ()
	{
	    //��ջ��ͬʱΪ����ǿ�
		return (InStack.empty() && OutStack.empty());
	}

};

int main()
{
	int x;
	TwoStackQueue<int> Stk;
	try {
		for (int i = 1; i<6; i++)
		{
			Stk.InQueue(i);
		}

		while (!Stk.EmptyQ())
		{
			cout << "Now The Queue head is :" << Stk.top() << endl;
			Stk.OutQueue();
		}
	}
	catch (exception const &ex)
	{
		cerr << "Exception :" << ex.what() << endl;
		return -1;
	}
	return 0;
}
/*���ӹ���
���ݶ����Ƚ��ȳ��Ĺ��򣬳���ʱ��
1.����ջ�ǿգ���ջ�գ����Ԫ�شӶ�ջȫ��ת���ջ�����Ƴ���ջԪ�أ���ִ�еڶ�������
2.����ջ�գ���ջ�ǿգ����Ƴ���ջԪ�أ�
3.����ջ��ջ�Էǿգ������Ƴ���ջԪ������ջԪ��Ϊ��ʱ����ִ�е�1����
4.����ջ��Ϊ�գ���ӿա�
*/
