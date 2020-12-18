#include<iostream>
#include<string>
#include<stack>
#include"except.h"
using namespace std;

class expressionSymbol//������� ջ�� ջ�����ȼ�
{
public:
	expressionSymbol();
	expressionSymbol(char ch);
	friend bool operator>= (const expressionSymbol& left,
		const expressionSymbol& right);
	char getOp() const;
private:
	char op;
	int inputPrecedence;
	int stackPrecedence;
};

expressionSymbol::expressionSymbol()
{}
expressionSymbol::expressionSymbol(char ch)//���캯����Ϊ����������ȼ�
{
	op = ch;
	switch (op)
	{
	case '+':
	case '-':  inputPrecedence = 1;//
				stackPrecedence = 1;	  break;
	case '*':
	case '%':
	case '/':  inputPrecedence = 2;
				stackPrecedence = 2;	  break;
	case '^':  inputPrecedence = 4;
				stackPrecedence = 3;	  break;
	case '(':  inputPrecedence = 5;
				stackPrecedence = -1;	  break;
	case ')':  inputPrecedence = 0;
				stackPrecedence = 0;	  break;
	}
}

char expressionSymbol::getOp() const//��ȡ�����
{
	return op;
}

bool operator>= (const expressionSymbol& left, const 	expressionSymbol& right)
{
	return left.stackPrecedence >= right.inputPrecedence;
}
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
class infix2Postfix
{
public:
	//���캯��
	infix2Postfix();
	infix2Postfix(const string& infixExp);
	void setInfixExp(const string& infixExp);//������׺���ʽ
	string postfix();//��ȡ��׺���ʽ
private:
	string infixExpression;//��׺���ʽ
	string postfixExpression;//��׺���ʽ
	stack<expressionSymbol> operatorStack;//ջ
	void outputHigherOrEqual(const expressionSymbol& op);
	bool isOperator(char ch) const;//�ж��Ƿ�Ϊ�����
	//  ch is one of '+','-','*','/','%','^'
};

//ת���ĺ����ǣ�����������������Ƚ���ջ��������ȼ����򣩣����ܳ�ջ��Ψһ������������ţ������Ų���ջ��

void infix2Postfix::outputHigherOrEqual(const expressionSymbol& op)
{
	expressionSymbol op2;
	while (!operatorStack.empty() &&
		(op2 = operatorStack.top()) >= op)//�����ȼ�����op��Ԫ�ض���ջ���ӵ���׺���ʽĩβ
	{
		operatorStack.pop();
		postfixExpression += op2.getOp();
		postfixExpression += ' ';
	}
}

bool infix2Postfix::isOperator(char ch) const//�ж��Ƿ��������
{
	return ch == '+' || ch == '-' || ch == '*' ||
		ch == '%' || ch == '/' || ch == '^';
}
infix2Postfix::infix2Postfix()
{}

infix2Postfix::infix2Postfix(const string& infixExp) ://���캯��
	infixExpression(infixExp)
{}

void infix2Postfix::setInfixExp(const string& infixExp)
{
	infixExpression = infixExp;
	postfixExpression = "";
}
string infix2Postfix::postfix()
{
	expressionSymbol op;
	int rank = 0, i;
	char ch;
	for (i = 0; i < infixExpression.length(); i++)
	{
		ch = infixExpression[i];
		if (isdigit(ch))			//���ǲ�����
		{
			string num="";
			int numlen = 0;
			int numi = i;
			while (isdigit(infixExpression[numi]) || infixExpression[numi] == '.')//��ȡ���ֳ��Ⱥ�λ��
			{
				numi++;
				numlen++;
			}
			postfixExpression += infixExpression.substr(i,numlen);//�����ַŵ���׺���ʽβ��
			postfixExpression += ' ';
			i = numi - 1;//��������i
			rank++;
			if (rank > 1)
				throw expressionError("infix2Postfix: Operator expected");
		}
		else if (isOperator(ch) || ch == '(')//�ǲ�������������
		{
			if (ch != '(')	rank--;
				if (rank < 0)
					throw expressionError("infix2Postfix: Operand expected");
				else
				{
					op = expressionSymbol(ch);
						outputHigherOrEqual(op);//�Ȱ�ջ�����ȼ�����op�Ķ����
						operatorStack.push(op);//�ٰ�op��ջ
				}
		}
		else if (ch == ')')		//�ǲ�������Ϊ������
		{
			op = expressionSymbol(ch);
			outputHigherOrEqual(op);//�Ȱ�ջ�����ȼ�����op�Ķ����
			if (operatorStack.empty())	//ȱʧ��Ե�������
				throw expressionError("infix2Postfix: Missing '('");
			else
				operatorStack.pop();//����������
		}
		else if (!isspace(ch))		//��Ч�������
			throw expressionError("infix2Postfix: Invalid input");
	}					//��׺ת��׺�������
	if (rank != 1)			//��׺���ʽ����
		throw expressionError("infix2Postfix: Operand expected");
	else			//���ʽ��ȷ��ת����ɣ�����������γ�ջ
	{
		while (!operatorStack.empty())//��ʣ��Ԫ�س�ջ�����ں�׺���ʽβ��
		{
			op = operatorStack.top();
			operatorStack.pop();
			if (op.getOp() == '(')
				throw expressionError("infix2Postfix:Missing ')'");
			else
			{
				postfixExpression += op.getOp();
				postfixExpression += ' ';
			}
		}
	}
	return postfixExpression;
}
int main()
{
	infix2Postfix p;
	string s;
	while (cin >> s)
	{
		p.setInfixExp(s);
		cout <<"post: "<< p.postfix() << endl;
	}
	return 0;
}