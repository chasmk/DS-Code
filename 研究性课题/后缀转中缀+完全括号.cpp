//#include<iostream>
//#include<string>
//#include<stack>
//#include"except.h"
//using namespace std;
//
//class postfixEval
//{
//public:
//	postfixEval();
//	string getPostfixExp() const;
//	void setPostfixExp(const string& postfixExp);
//	int evaluate();
//private:
//	string postfixExpression;
//	stack<int> operandStack;
//	void getOperands(int& left, int& right);//获取顶部两个元素并弹出
//	int compute(int left, int right, char op) const;//计算
//	bool isOperator(char ch) const;//判断是否是运算符
//	// is ch one of '+','-','*','/','%','^'
//};
//
//void postfixEval::getOperands(int& left, int& right)//获取顶部两个元素并弹出
//{
//	if (operandStack.empty())
//		throw  expressionError("postfixEval: Too many 		operators");
//	right = operandStack.top();
//	operandStack.pop();
//	if (operandStack.empty())
//		throw  expressionError("postfixEval: Too many 		operators");
//	left = operandStack.top();
//	operandStack.pop();
//}
//int postfixEval::compute(int left, int right, char op) const
//{
//	int value;
//	switch (op)
//	{
//	case '+':	value = left + right;	break;
//	case '-':	value = left - right;	break;
//	case '*':	value = left * right;	break;
//	case '%':	if (right == 0)	throw expressionError("postfixEval: divide by 0");
//		value = left % right;		break;
//	case '/':	if (right == 0)throw	expressionError("postfixEval: divide by 0");
//		value = left / right;		break;
//	case '^':	if (left == 0 && right == 0)throw	expressionError("postfixEval: 0^0 undefined");
//		value = 1;
//		while (right > 0) { value *= left;  right--; }	break;
//	}
//	return value;
//}
//bool postfixEval::isOperator(char ch) const
//{
//	return ch == '+' || ch == '-' || ch == '*' ||
//		ch == '%' || ch == '/' || ch == '^';
//}
//
//postfixEval::postfixEval()
//{}
//
//string postfixEval::getPostfixExp() const
//{
//	return postfixExpression;
//}
//
//void postfixEval::setPostfixExp(const string& postfixExp)
//{
//	postfixExpression = postfixExp;
//}
//int postfixEval::evaluate()
//{
//	int left, right, expValue;	char ch;		int i;
//	for (i = 0; i < postfixExpression.length(); i++)
//	{
//		ch = postfixExpression[i];
//		if (isdigit(ch))//如果是数字 入栈
//			operandStack.push(ch - '0');
//		else if (isOperator(ch))//如果是操作数
//		{
//			getOperands(left, right);//获取栈顶两个值
//			operandStack.push(compute(left, right, ch));//计算后再压入栈中
//		}
//		else if (!isspace(ch))
//			throw expressionError("postfixEval: Improper char");
//	}
//	expValue = operandStack.top();
//	operandStack.pop();
//	if (!operandStack.empty())
//		throw expressionError("postfixEval: Too many operands");
//	return expValue;
//}
//
//int main()
//{
//	string s;
//	while (cin >> s)
//	{
//		postfixEval p;
//		p.setPostfixExp(s);
//
//		cout << p.evaluate() << endl;
//	}
//
//	return 0;
//}