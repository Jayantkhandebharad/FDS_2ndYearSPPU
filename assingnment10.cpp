#include<iostream>
using namespace std;
#define MAX 30

template<class T>
class Stack{
	int top;
	T stack[MAX];
	public:

		Stack(){
			top = -1;
			stack[MAX] = ' ';
		}
	void push(char x);
	void pop();
	char peek();
	bool isFull();
	bool isEmpty();
	void show();
};
template<class T>
bool Stack<T>::isEmpty(){return (top == -1);}
template<class T>
bool Stack<T>::isFull(){return (top == MAX-1);}
template<class T>
char Stack<T>::peek(){
	if(!isEmpty())return stack[top];
	else return -1;
}
template<class T>
void Stack<T>::pop(){
	if(top == -1){cout << "Stack underflow!";}
	else
	{
		if(!isEmpty()){top--;}
	}
}
template<class T>
void Stack<T>::push(char data){
	if(top == MAX-1){cout << "Stack overflow!";}
	else
	{
			if(!isFull()){
			top = top + 1;
			stack[top] = data;
		}
	}
}
template<class T>
void Stack<T>::show(){
	for(int i=0;i<=top;i++)
	{
		cout<<stack[i]<<" ";
	}
}
/***********************************************/
template<class T>
class Expression{
	char exps[30];
	char postfixExps[30];
	public:
		Expression(){exps[30]=' ';}
		void input();
		int precedence(char x);
		int evaluate(char opr,int op1,int op2);
		void infixToPostfix();
		void evaluateExpression();
		void output();
};
template<class T>
void Expression<T>::input(){cout<<"Enter Expression: ";cin>>exps;}
template<class T>
void Expression<T>::output(){
	cout<<"\nPostfix expression is: ";
	int j=0;
	while(postfixExps[j]!='\0')
	{
		cout<<postfixExps[j];
		j++;
	}
}
template<class T>
int Expression<T>::precedence(char x){
	switch(x)
	{
	case '+':return 1;
	case '-':return 1;
	case '*':return 2;
	case '/':return 2;
	default:return -1;
	}
}
template<class T>
void Expression<T>::infixToPostfix()
{

	char ch;
	int i=0,k=0;
	Stack <char> s;
	while(exps[i]!='\0')
	{
			ch = exps[i];
			if(isalnum(ch)){postfixExps[k++] = ch;}
			else if (ch == '('){s.push(ch);}
			else if(ch == ')')
			{
				while(s.peek()!='(')
					{
						postfixExps[k++] = s.peek();
						s.pop();
					}
				s.pop();
			}
			else
			{
				while(!s.isEmpty()&& s.peek()!='('&& (precedence(ch)<= precedence(s.peek())))
					{
						postfixExps[k++] = s.peek();
						s.pop();
					}
				s.push(ch);
			}
		i++;
	}
	while(!s.isEmpty())
	{
		postfixExps[k++] =s.peek();
		s.pop();
	}
	postfixExps[k] = '\0';
}
template<class T>
int Expression<T>::evaluate(char opr,int op1,int op2)
{
	if(opr == '+'){return (op2+op1);}
	if(opr == '-'){return (op2-op1);}
	if(opr == '*'){return (op2*op1);}
	if(opr == '/'){return (op2/op1);}
	else{return -10;}
}
template<class T>
void Expression<T>::evaluateExpression()
{
	Stack <int> s1;
	int i=0,operand1,operand2,result;
	while(postfixExps[i] !='\0')
	{
		if(isalpha(postfixExps[i])){cout<<"\nValues required for evaluation! ";return;}
		if(isdigit(postfixExps[i])){s1.push(postfixExps[i]);}
		else
		{
			if(postfixExps[i] == '+' || postfixExps[i] == '-' || postfixExps[i] == '*' || postfixExps[i] == '/')
			{
				operand1 = (s1.peek()-'0');
				s1.pop();
				operand2 = (s1.peek()-'0');
				s1.pop();
				result = evaluate(postfixExps[i],operand1,operand2);
				char temp = '0' + result;
				s1.push(temp);
			}
		}
		i++;
	}
	cout << "\nResult: "<<s1.peek()-'0';
	cout << (isdigit(s1.peek())?"(int)":"");
	s1.pop();
}
int main()
{
	Expression<char> e1;
	int i=0;
	while(1)
	{
		cout<<"\nTest Case "<<i+1<<" :\n";
		e1.input();
		e1.infixToPostfix();
		e1.output();
		e1.evaluateExpression();
		i++;
		cout<<endl;
	}
	return 0;
}
