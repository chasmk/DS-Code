#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include"except.h"
using namespace std;

class tnodeShadow//Ӱ�ӽ���࣬���������ӡ������
{
public:
	string nodeValueStr;	// formatted node value
	int level, column;
	tnodeShadow* left, * right;
	tnodeShadow()
	{}
};

template<class T>
class tnode {//���������ģ����
public:
	T nodeValue;
	tnode<T>* left, * right;

	tnode() {};
	tnode(const T& item, tnode<T>* lptr = nullptr, tnode<T>* rptr = nullptr) :
		nodeValue(item), left(lptr), right(rptr) {}
};

class expressionSymbol//������� ջ��ջ�����ȼ�
{
public:
	expressionSymbol();
	expressionSymbol(char ch);
	friend bool operator>= (const expressionSymbol& left,const expressionSymbol& right);
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
class infix2Postfix //��׺ת��׺ ��
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
	void outputHigherOrEqual(const expressionSymbol& op);//���ջ�ڲ�С��op���ȼ���Ԫ��
	bool isOperator(char ch) const;//�ж��Ƿ�Ϊ�����
	//  ch is one of '+','-','*','/','%','^'
};

//ת���ĺ����ǣ�����������������Ƚ���ջ��������ȼ����򣩣����ܳ�ջ��Ψһ������������ţ������Ų���ջ��

void infix2Postfix::outputHigherOrEqual(const expressionSymbol& op)
{
	expressionSymbol op2;
	while (!operatorStack.empty() &&
		(op2 = operatorStack.top()) >= op)//�����ȼ����ڵ���op��Ԫ�ض���ջ���ӵ���׺���ʽĩβ
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
		if (isalnum(ch))//�������ĸ������
		{
			string num = "";
			int numlen = 0;
			int numi = i;
			while (isalnum(infixExpression[numi]) || infixExpression[numi] == '.')//��ȡ���ֳ��Ⱥ�λ��
			{
				numi++;
				numlen++;
			}
			postfixExpression += infixExpression.substr(i, numlen);//�����ַŵ���׺���ʽβ��
			postfixExpression += ' ';
			i = numi - 1;//��������i
			rank++;//��������+1
			if (rank > 1)
				throw expressionError("infix2Postfix: Operator expected");
		}
		else if (isOperator(ch) || ch == '(')//����ǲ�������������
		{
			if (ch != '(')	rank--;//�������-1
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
/****************************************************************************************************************/
class postfixEval //��׺���ʽ���ɱ��ʽ������
{
public:
	postfixEval();
	string getPostfixExp() const;
	void setPostfixExp(const string& postfixExp);
	tnode<string>* evaluate();
private:
	string postfixExpression;//��׺���ʽ
	stack<tnode<string>*> operandStack; //��ű��ʽ��ջ
	void getOperands(tnode<string>*& left, tnode<string>*& right);//��ȡ��������Ԫ�ز�����
	tnode<string>* compute(tnode<string>* left, tnode<string>* right, string op) const;//����
	bool isOperator(char ch) const;//�ж��Ƿ��������
	// is ch one of '+','-','*','/','%','^'
};
void postfixEval::getOperands(tnode<string>*& left, tnode<string>*& right)//��ȡ��������Ԫ�ز�����
{
	if (operandStack.empty())
		throw  expressionError("postfixEval: Too many operators");
	right = operandStack.top();
	operandStack.pop();
	if (operandStack.empty())
		throw  expressionError("postfixEval: Too many operators");
	left = operandStack.top();
	operandStack.pop();
}
tnode<string>* postfixEval::compute(tnode<string>* left, tnode<string>* right, string op) const
{
	tnode<string>* root = new tnode<string>(op, left, right);//��������������Ϊop�Ķ��ӽ��
	return root; //���ظ��ڵ� op
}
bool postfixEval::isOperator(char ch) const
{
	return ch == '+' || ch == '-' || ch == '*' ||
		ch == '%' || ch == '/' || ch == '^';
}
postfixEval::postfixEval()
{}
string postfixEval::getPostfixExp() const
{
	return postfixExpression;
}
void postfixEval::setPostfixExp(const string& postfixExp)
{
	postfixExpression = postfixExp;
}
tnode<string>* postfixEval::evaluate() // �������յ������������
{
	tnode<string>* left, *right, *expValue;	char ch;
	int i;
	for (i = 0; i < postfixExpression.length(); i++)
	{
		ch = postfixExpression[i];
		if (isalnum(ch))//�������ĸ������ ��ջ
		{
			int len = 0;
			while (ch != ' ')//ȡ��������
			{
				len++;
				ch = postfixExpression[i + len];
			}
			operandStack.push(new tnode<string>(postfixExpression.substr(i,len), nullptr, nullptr));//���ɽ���ѹ��ջ��
			i += len;//����i��ֵ
		}
		else if (isOperator(ch))//����������
		{
			getOperands(left, right);//��ȡջ������Ԫ�ص�ָ��
			string str_ch(1,ch);
			operandStack.push(compute(left, right, str_ch));//�����������ٽ����ڵ�ѹ��ջ��
			i++;//�����ո�
		}
		else if (!isspace(ch))
			throw expressionError("postfixEval: Improper char");
	}
	expValue = operandStack.top();//��ȡ���յĸ��ڵ�
	operandStack.pop();
	if (!operandStack.empty())
		throw expressionError("postfixEval: Too many operands");
	return expValue;
}


//�����ӡ
//������չ����ͨ���������չ��
template <typename T>
tnodeShadow* buildShadowTree(tnode<T>* t, int level, int& column)//����һ��Ӱ����
{						//level��ֵΪ0, column��ֵΪ10
	tnodeShadow* newNode = NULL;
	if (t != NULL) {//�������ҵ�˳�����
		newNode = new tnodeShadow;//�½����
		tnodeShadow* newLeft = buildShadowTree(t->left, level + 1, column);//�½�������
		//��ֵ
		newNode->left = newLeft;
		newNode->nodeValueStr = t->nodeValue;
		newNode->level = level;
		newNode->column = column;//���ý���ƫ������ֵ
		/*
			��������ֵ�꣬column+1���ٹ����Լ���+1���ٹ�������������֤һ��һ��
		*/
		column+=t->nodeValue.length();	//��ֵ����ټ���t�Ŀ�ȣ���֤ÿ��һ��ֵ
		
		tnodeShadow* newRight = buildShadowTree(t->right, level + 1, column);//�½�������
		newNode->right = newRight;
	}
	return newNode;
}
template<class T>
void displayTree(tnode<T>* root)//��Ӱ���������ӡ������
{
	int column = 10;
	tnodeShadow* s = buildShadowTree<T>(root, 0, column);
	queue<tnodeShadow* > q;
	tnodeShadow* p = nullptr, * pre = nullptr;
	q.push(s);
	int level;//�ϴν��㼶
	int curlevel;//��ǰ���㼶
	bool flag = true;
	column = 0;//�ϸ����ƫ����
	int curcolumn = 0;//���ν��ƫ����
	while (!q.empty())//ÿ�������ͷ��㣬�ٰ��������Ҷ������
	{
		pre = p;//pre��¼��һ������Ľ�㣬��������ո������жϡ�
		p = q.front();
		if (flag)//����ֵ
		{
			level = p->level;
			curlevel = p->level;
			column = p->column;
			curcolumn = p->column;
			flag = false;
		}
		//����ǰֵ
		curlevel = p->level;
		curcolumn = p->column;
		if (curlevel != level)//һ����������
		{
			level = curlevel;
			column = curcolumn;
			cout << endl;
		}
		int len = column;//len�Ǵ˴�����ո����������ֵ���ϴ�column��ֵ
		if (curcolumn > column)
		{
			len = curcolumn - column - pre->nodeValueStr.length();//����������Ŀո���
			column = curcolumn;//����columnֵ
		}
		
		q.pop();
		for (int i = 0; i < len; i++)cout << " ";//����ո�
		cout << p->nodeValueStr; //������ֵ
		if (p->left != NULL)	q.push(p->left);
		if (p->right != NULL)	q.push(p->right);
	}
	cout << endl;
}
int main()
{
	infix2Postfix p;
	string s;
	while (cout<<"������һ����׺���ʽ: " && cin >> s)
	{
		p.setInfixExp(s);
		string post = p.postfix();
		cout << "��׺���ʽ: " << post << endl;
		postfixEval p1;
		p1.setPostfixExp(post);
		tnode<string>* res = p1.evaluate();
		cout << "�����ӡ��" << endl;
		displayTree(res);
	}
	return 0;
}