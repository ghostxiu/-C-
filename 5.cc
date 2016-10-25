//5.��һ��ջʵ����һ��ջ������
#include<iostream>
#include<gx/gx_stack>
#include<stdexcept>
#include<cstdlib>
#include<ctime>
using namespace std;

class OrderStack
{
private:
	Stack<int> ChStack;
	int miniValue;
public:
	OrderStack()
	{
		miniValue = 0;
	}
	void Arrange(Stack<int> stack)
	{
		int re = 0;
		while (!stack.empty())
		{
			//ÿ���ҵ�һ��Ԫ�أ����ԭջΪ��
			miniValue = stack.top();
			while (!stack.empty())
			{
				int ch;
				//����ջ
				ch = stack.top();
				ChStack.push(ch);
				stack.pop();

				if (ChStack.top() < miniValue)
				{
					//����СԪ��
					miniValue = ChStack.top();
				}
			}
			while (!ChStack.empty() && ChStack.top() != re)//re����һ�ص���СԪ��
			{   //�޳���СԪ��
				if (ChStack.top() != miniValue)
				{
					int ch = ChStack.top();
					stack.push(ch);
				}
                ChStack.pop();
			}
			ChStack.push(miniValue);//�洢���ε���СԪ����ջ
			re = miniValue;
		}
	}
	bool StackEmpty()
	{
		return ChStack.empty();
	}
	int StackPop()
	{
		int x;
		x = ChStack.top();
		ChStack.pop();
		return x;
	}
};
int main()
{
	Stack<int> stack;
	OrderStack stk;
	try {
		int x, y, z;
		x = 1; y = 1000;
		cout << "The stack is Pushing!\n...\n";
		for (int i = 0; i < 8; i++)
		{
			z = rand() % (y - x + 1) + x;
			stack.push(z);
			cout << " " << z;
		}
		cout << "\n\n\nNow Arrange the Stack!\n...\n";
		stk.Arrange(stack);
		cout << "Pop the Arrange Stack:\n";
		while (!stk.StackEmpty())
		{
			cout << " " << stk.StackPop();
		}

	}
	catch (exception &ex)
	{
		cerr << "Exception:" << ex.what() << endl;
		return -1;
	}
	return 0;
}
