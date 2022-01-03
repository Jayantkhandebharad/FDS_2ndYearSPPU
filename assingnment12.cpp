#include<iomanip>
#include<iostream>
using namespace std;
#define MAX 10

template<class T>
class item{
private:
	T dataItem;
	int priority;
public:
	item()
	{
		priority = 0;
		dataItem = 0;
	}
	item(int p,T itm)
	{
		priority = p;
		dataItem = itm;
	}
	bool operator<=(const item &oth);
	template <class> friend class Pqueue;
};
/******************************************************************/
template <class T>
bool item<T>::operator <=(const item<T> &oth)
{
	if(priority <= oth.priority)return true;
	else return false;
}
/******************************************************************/
/******************************************************************/
template <class T>
class Pqueue
{
private:
	item<T> queue[MAX];
	int front,rear;
public:
	Pqueue()
	{
		queue[MAX] = {};
		front = -1;
		rear = -1;
	}
bool isFull();
bool isEmpty();
void insertData(item<T> &data);
void deleteData();
void display();
};
/******************************************************************/
template<class T>
bool Pqueue<T>::isEmpty()
{
if(front == -1)
	return true;else return false;
}
template<class T>
bool Pqueue<T>::isFull()
{
	if(rear == MAX-1)return true;
	else return false;
}
template<class T>
void Pqueue<T>::insertData(item<T> &data)
{
	if(isFull()){cout<<"Overflow!";}
	if(isEmpty())
	{
		front=0;rear=0;
		queue[rear] = data;
	}
	else
	{
		int j;
		rear++;
		j = rear-1;
		while(queue[j] <= data && j>=0)
		{
			queue[j+1] = queue[j];
			j--;
		}
		queue[j+1] = data;
	}
}
/****************************/
template<class T>
void Pqueue<T>::deleteData()
{
item<T> data;
if(front == -1 || front == rear+1)
{
cout <<"\nQueue Empty"<<endl;
}
else{
data = queue[front];
front++;
}
cout<<"\nRecently processed job: "<<data.dataItem;
}
/*****************************/
template<class T>
void Pqueue<T>::display(){
int i=front;
cout<<endl<<"QUEUE STATUS: ";
if(isEmpty()){cout<<"Queue is empty!";}
else{
while(i<=rear)
{
cout <<queue[i].dataItem<<"("<<queue[i].priority<<")"<< " ";
i++;
}
}
}
/*****************************/
template<class type>
void menu(Pqueue<type>&q1)
{
int ask,prior,total;
type element;
while(1)
{
cout <<"\n\nOperations\n"
"1] Enter Elements\n"
"2] Delete Elements\n"
"3] Display Elements\n"
"4] Back to Menu\n"
"\nEnter choice: ";cin>>ask;
switch(ask)
{
case 1:
	cout<<"\nHow much data??\n>>";cin>>total;
	for(int i=0;i<total;i++)
	{
		cout<<"Enter data item: ";cin>>element;
		cout<<"Enter Priority: ";cin>>prior;
		item <type>data(prior,element);
		q1.insertData(data);
	}break;
case 2:q1.deleteData();cout<<"\nDeleted!"<<endl;break;
case 3:q1.display();break;
case 4:break;
}
if(ask == 4){break;}
}
}
int main()
{
int ask;
Pqueue <int> q1;
Pqueue <double> q2;
Pqueue <float> q3;
while(1)
{
cout<<endl;
cout <<setfill('*')<< setw(20);cout << " MENU ";
cout <<setfill('*')<< setw(14);cout<<"*"<<endl;
cout<<"\nChoose Data type:\n1] Integer\n2] Double\n3] Float\n4] Exit\n\nEnter choice: ";cin>>ask;
switch(ask)
{
case 1:menu(q1);break;
case 2:menu(q2);break;
case 3:menu(q3);break;
case 4:cout<<"\nThank You!";break;
}
if(ask==4){break;}
}
return 0;
}
