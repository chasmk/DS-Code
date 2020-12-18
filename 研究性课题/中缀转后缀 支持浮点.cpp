#include<iostream>
#include<string>
#include<stack>
#include"except.h"
using namespace std;

class expressionSymbol//运算符类 栈内 栈外优先级
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
expressionSymbol::expressionSymbol(char ch)//构造函数，为运算符赋优先级
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

char expressionSymbol::getOp() const//获取运算符
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
	//构造函数
	infix2Postfix();
	infix2Postfix(const string& infixExp);
	void setInfixExp(const string& infixExp);//输入中缀表达式
	string postfix();//获取后缀表达式
private:
	string infixExpression;//中缀表达式
	string postfixExpression;//后缀表达式
	stack<expressionSymbol> operatorStack;//栈
	void outputHigherOrEqual(const expressionSymbol& op);
	bool isOperator(char ch) const;//判断是否为运算符
	//  ch is one of '+','-','*','/','%','^'
};

//转换的核心是：所有运算符都必须先进入栈（完成优先级排序），才能出栈。唯一例外的是右括号，右括号不入栈。

void infix2Postfix::outputHigherOrEqual(const expressionSymbol& op)
{
	expressionSymbol op2;
	while (!operatorStack.empty() &&
		(op2 = operatorStack.top()) >= op)//把优先级高于op的元素都出栈，加到后缀表达式末尾
	{
		operatorStack.pop();
		postfixExpression += op2.getOp();
		postfixExpression += ' ';
	}
}

bool infix2Postfix::isOperator(char ch) const//判断是否是运算符
{
	return ch == '+' || ch == '-' || ch == '*' ||
		ch == '%' || ch == '/' || ch == '^';
}
infix2Postfix::infix2Postfix()
{}

infix2Postfix::infix2Postfix(const string& infixExp) ://构造函数
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
		if (isdigit(ch))			//若是操作数
		{
			string num="";
			int numlen = 0;
			int numi = i;
			while (isdigit(infixExpression[numi]) || infixExpression[numi] == '.')//获取数字长度和位置
			{
				numi++;
				numlen++;
			}
			postfixExpression += infixExpression.substr(i,numlen);//把数字放到后缀表达式尾部
			postfixExpression += ' ';
			i = numi - 1;//重新设置i
			rank++;
			if (rank > 1)
				throw expressionError("infix2Postfix: Operator expected");
		}
		else if (isOperator(ch) || ch == '(')//是操作符或左括号
		{
			if (ch != '(')	rank--;
				if (rank < 0)
					throw expressionError("infix2Postfix: Operand expected");
				else
				{
					op = expressionSymbol(ch);
						outputHigherOrEqual(op);//先把栈内优先级高于op的都输出
						operatorStack.push(op);//再把op入栈
				}
		}
		else if (ch == ')')		//是操作符但为右括号
		{
			op = expressionSymbol(ch);
			outputHigherOrEqual(op);//先把栈内优先级高于op的都输出
			if (operatorStack.empty())	//缺失配对的左括号
				throw expressionError("infix2Postfix: Missing '('");
			else
				operatorStack.pop();//弹出左括号
		}
		else if (!isspace(ch))		//无效输入符号
			throw expressionError("infix2Postfix: Invalid input");
	}					//中缀转后缀处理完毕
	if (rank != 1)			//中缀表达式有误
		throw expressionError("infix2Postfix: Operand expected");
	else			//表达式正确且转换完成，将运算符依次出栈
	{
		while (!operatorStack.empty())//将剩余元素出栈并加在后缀表达式尾部
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