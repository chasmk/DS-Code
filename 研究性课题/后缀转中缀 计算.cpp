//#include<iostream>
//#include<string>
//#include<stack>
//#include"except.h"
//using namespace std;
//
//
//class postfixEval //�����׺���ʽ
//{
//public:
//	postfixEval();
//	string getPostfixExp() const;
//	void setPostfixExp(const string& postfixExp);
//	int evaluate();
//private:
//	string postfixExpression;//��׺���ʽ
//	stack<int> operandStack; //��ű��ʽ��ջ
//	void getOperands(int& left, int& right);//��ȡ��������Ԫ�ز�����
//	int compute(int left, int right, char op) const;//����
//	bool isOperator(char ch) const;//�ж��Ƿ��������
//	// is ch one of '+','-','*','/','%','^'
//};
//
//void postfixEval::getOperands(int& left, int& right)//��ȡ��������Ԫ�ز�����
//{
//	if (operandStack.empty())
//		throw  expressionError("postfixEval: Too many operators");
//	right = operandStack.top();
//	operandStack.pop();
//	if (operandStack.empty())
//		throw  expressionError("postfixEval: Too many operators");
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
//				value = left % right;		break;
//	case '/':	if (right == 0)throw	expressionError("postfixEval: divide by 0");
//				value = left / right;		break;
//	case '^':	if (left == 0 && right == 0)throw	expressionError("postfixEval: 0^0 undefined");
//				value = 1;
//				while (right > 0) { value *= left;  right--; }	break;
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
//	int left, right, expValue;	char ch;		
//	int i;
//	for (i = 0; i < postfixExpression.length(); i++)
//	{
//		ch = postfixExpression[i];
//		if (isdigit(ch))//��������� ��ջ
//			operandStack.push(ch - '0');
//		else if (isOperator(ch))//����ǲ�����
//		{
//			getOperands(left, right);//��ȡջ������ֵ
//			operandStack.push(compute(left, right, ch));//�������ѹ��ջ��
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