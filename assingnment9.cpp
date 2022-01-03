#include<iostream>
using namespace std;
class Stack{
	int top;
	public:
		char stack[30];
		Stack(){
			top = -1;
			stack[30] = ' ';
		}
	void push(char x);
	void pop();
	char peek();
	bool isFull();
	bool isEmpty();
	void show();
};
bool Stack::isEmpty(){return (top == -1);}
bool Stack::isFull(){return (top == 29);}

char Stack::peek(){
	if(!isEmpty())return stack[top];
	else return -1;
}
void Stack::pop(){
	if(!isEmpty()){
		top--;
	}
}
void Stack::push(char data){
	if(!isFull()){
		top = top + 1;
		stack[top] = data;
	}
}
void Stack::show(){
	for(int i=0;i<=top;i++)
	{
		cout<<stack[i]<<" ";
	}
}
/***********************************************/
class Expression{
	char exps[30];
	Stack s;
	public:
		Expression(){exps[30]=' ';}
		void input();
		bool checkWellParenthesized();
};
void Expression::input(){cout<<"\nEnter Expression: ";cin>>exps;}
bool Expression::checkWellParenthesized(){
	int i=0;
	bool flag = false;
	while(exps[i]!='\0')
	{
		if(exps[i]=='('||exps[i]=='{'||exps[i]=='[')
		{
			s.push(exps[i]);
		}
		if(exps[i]==')'||exps[i]=='}'||exps[i]==']')
		{
			char temp = s.peek();
			s.pop();
			if(exps[i] == ')' && temp == '(')
			{
				flag = true;
			}
			else if(exps[i] == '}' && temp == '{')
			{
				flag = true;
			}
			else if(exps[i] == ']' && temp == '[')
			{
				flag = true;
			}
			else{return false;}
		}
		i++;
	}
	if(s.isEmpty() && flag == true)
	{
		return flag;
	}
	else return flag;
}

int main()
{
	Expression e1;
	while(1)
	{
		e1.input();
		if(e1.checkWellParenthesized() == 1)
		{
			cout <<"\nExpression is well parenthesized!";
		}
		else{
			cout <<"\nExpression is not well parenthesized!";
		}
	}
	return 0;
}
