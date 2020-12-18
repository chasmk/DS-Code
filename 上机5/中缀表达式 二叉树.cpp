#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include"except.h"
using namespace std;

class tnodeShadow//影子结点类，用于正向打印二叉树
{
public:
	string nodeValueStr;	// formatted node value
	int level, column;
	tnodeShadow* left, * right;
	tnodeShadow()
	{}
};

template<class T>
class tnode {//二叉树结点模板类
public:
	T nodeValue;
	tnode<T>* left, * right;

	tnode() {};
	tnode(const T& item, tnode<T>* lptr = nullptr, tnode<T>* rptr = nullptr) :
		nodeValue(item), left(lptr), right(rptr) {}
};

class expressionSymbol//运算符类 栈内栈外优先级
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
class infix2Postfix //中缀转后缀 类
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
	void outputHigherOrEqual(const expressionSymbol& op);//输出栈内不小于op优先级的元素
	bool isOperator(char ch) const;//判断是否为运算符
	//  ch is one of '+','-','*','/','%','^'
};

//转换的核心是：所有运算符都必须先进入栈（完成优先级排序），才能出栈。唯一例外的是右括号，右括号不入栈。

void infix2Postfix::outputHigherOrEqual(const expressionSymbol& op)
{
	expressionSymbol op2;
	while (!operatorStack.empty() &&
		(op2 = operatorStack.top()) >= op)//把优先级大于等于op的元素都出栈，加到后缀表达式末尾
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
		if (isalnum(ch))//如果是字母或数字
		{
			string num = "";
			int numlen = 0;
			int numi = i;
			while (isalnum(infixExpression[numi]) || infixExpression[numi] == '.')//获取数字长度和位置
			{
				numi++;
				numlen++;
			}
			postfixExpression += infixExpression.substr(i, numlen);//把数字放到后缀表达式尾部
			postfixExpression += ' ';
			i = numi - 1;//重新设置i
			rank++;//运算数就+1
			if (rank > 1)
				throw expressionError("infix2Postfix: Operator expected");
		}
		else if (isOperator(ch) || ch == '(')//如果是操作符或左括号
		{
			if (ch != '(')	rank--;//运算符就-1
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
/****************************************************************************************************************/
class postfixEval //后缀表达式生成表达式二叉树
{
public:
	postfixEval();
	string getPostfixExp() const;
	void setPostfixExp(const string& postfixExp);
	tnode<string>* evaluate();
private:
	string postfixExpression;//后缀表达式
	stack<tnode<string>*> operandStack; //存放表达式的栈
	void getOperands(tnode<string>*& left, tnode<string>*& right);//获取顶部两个元素并弹出
	tnode<string>* compute(tnode<string>* left, tnode<string>* right, string op) const;//计算
	bool isOperator(char ch) const;//判断是否是运算符
	// is ch one of '+','-','*','/','%','^'
};
void postfixEval::getOperands(tnode<string>*& left, tnode<string>*& right)//获取顶部两个元素并弹出
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
	tnode<string>* root = new tnode<string>(op, left, right);//将左右运算数作为op的儿子结点
	return root; //返回根节点 op
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
tnode<string>* postfixEval::evaluate() // 生成最终的运算符二叉树
{
	tnode<string>* left, *right, *expValue;	char ch;
	int i;
	for (i = 0; i < postfixExpression.length(); i++)
	{
		ch = postfixExpression[i];
		if (isalnum(ch))//如果是字母或数字 入栈
		{
			int len = 0;
			while (ch != ' ')//取出运算数
			{
				len++;
				ch = postfixExpression[i + len];
			}
			operandStack.push(new tnode<string>(postfixExpression.substr(i,len), nullptr, nullptr));//生成结点后压入栈中
			i += len;//更新i的值
		}
		else if (isOperator(ch))//如果是运算符
		{
			getOperands(left, right);//获取栈顶两个元素的指针
			string str_ch(1,ch);
			operandStack.push(compute(left, right, str_ch));//生成新树后再将根节点压入栈中
			i++;//跳过空格
		}
		else if (!isspace(ch))
			throw expressionError("postfixEval: Improper char");
	}
	expValue = operandStack.top();//获取最终的根节点
	operandStack.pop();
	if (!operandStack.empty())
		throw expressionError("postfixEval: Too many operands");
	return expValue;
}


//正向打印
//从左到右展开，通过步进逐次展开
template <typename T>
tnodeShadow* buildShadowTree(tnode<T>* t, int level, int& column)//创建一个影子树
{						//level初值为0, column初值为10
	tnodeShadow* newNode = NULL;
	if (t != NULL) {//按左中右的顺序遍历
		newNode = new tnodeShadow;//新建结点
		tnodeShadow* newLeft = buildShadowTree(t->left, level + 1, column);//新建左子树
		//赋值
		newNode->left = newLeft;
		newNode->nodeValueStr = t->nodeValue;
		newNode->level = level;
		newNode->column = column;//给该结点的偏移量赋值
		/*
			左子树赋值完，column+1，再构造自己，+1，再构造右子树，保证一人一列
		*/
		column+=t->nodeValue.length();	//赋值完后再加上t的宽度，保证每列一个值
		
		tnodeShadow* newRight = buildShadowTree(t->right, level + 1, column);//新建右子树
		newNode->right = newRight;
	}
	return newNode;
}
template<class T>
void displayTree(tnode<T>* root)//由影子树正向打印二叉树
{
	int column = 10;
	tnodeShadow* s = buildShadowTree<T>(root, 0, column);
	queue<tnodeShadow* > q;
	tnodeShadow* p = nullptr, * pre = nullptr;
	q.push(s);
	int level;//上次结点层级
	int curlevel;//当前结点层级
	bool flag = true;
	column = 0;//上个结点偏移量
	int curcolumn = 0;//本次结点偏移量
	while (!q.empty())//每次输出队头结点，再把它的左右儿子入队
	{
		pre = p;//pre记录上一个输出的结点，用于输出空格数的判断。
		p = q.front();
		if (flag)//赋初值
		{
			level = p->level;
			curlevel = p->level;
			column = p->column;
			curcolumn = p->column;
			flag = false;
		}
		//赋当前值
		curlevel = p->level;
		curcolumn = p->column;
		if (curlevel != level)//一行输出完后换行
		{
			level = curlevel;
			column = curcolumn;
			cout << endl;
		}
		int len = column;//len是此次输出空格的数量，初值是上次column的值
		if (curcolumn > column)
		{
			len = curcolumn - column - pre->nodeValueStr.length();//计算需输出的空格数
			column = curcolumn;//更新column值
		}
		
		q.pop();
		for (int i = 0; i < len; i++)cout << " ";//输出空格
		cout << p->nodeValueStr; //输出结点值
		if (p->left != NULL)	q.push(p->left);
		if (p->right != NULL)	q.push(p->right);
	}
	cout << endl;
}
int main()
{
	infix2Postfix p;
	string s;
	while (cout<<"请输入一个中缀表达式: " && cin >> s)
	{
		p.setInfixExp(s);
		string post = p.postfix();
		cout << "后缀表达式: " << post << endl;
		postfixEval p1;
		p1.setPostfixExp(post);
		tnode<string>* res = p1.evaluate();
		cout << "正向打印：" << endl;
		displayTree(res);
	}
	return 0;
}