#include<iostream>
using namespace std;
#define MAX 20
class Queue
{
	private:
		int elements[MAX];
		int front;
		int rear;
	public:
		Queue()
		{
			elements[MAX] = {0};
			front = -1;
			rear = -1;
		}
		bool isEmpty(){if(front == -1)return true;else return false;}
		bool isFull(){if(rear == MAX-1)return true;else return false;}
		void insertData(int data);
		void deleteData();
		void display();
};
void Queue::insertData(int data)
{
	if(isFull())
	{
		cout <<"\nOVERFLOW!"<<endl;
	}
	else{
		if(isEmpty())
		{
			front = 0;
		}
		rear++;
		elements[rear] = data;
	}
}


void Queue::deleteData()
{
	int data;
	if(isEmpty()|| front == rear+1)
	{
		cout <<"\nQueue Empty"<<endl;
	}
	else{
		data = elements[front];
		front++;
	}
	cout<<"\nRecently processed job: "<<data;
}
void Queue::display(){
	int i=front;
	cout<<endl;
	if(i == -1){cout<<"Queue is Empty!";}
	else{
		while(i<=rear)
		{
			cout << elements[i] << " ";
			i++;
		}
	}
}
int main()
{
	Queue q;
	int ask,size,id;
	while(1)
	{
		cout<<"\nMenu:\n\n1) Add Job into Queue\n2) Delete Job from Queue\n3) Display Queue\n4) Exit\n\nEnter choice:\n>>";cin>>ask;
		if(ask == 1)
		{
			cout<<"\nHow many jobs to add?\n>>";cin>>size;
			for(int i=0;i<size;i++)
			{
				cout<<"\nEnter job ID: ";cin>>id;
				q.insertData(id);
			}
			cout<<"\nJob added!\n";
		}
		else if(ask == 2){q.deleteData();cout<<"\nJob deleted!\n";}
		else if(ask == 3){q.display();}
		else if(ask == 4){cout << "Thank You!";break;}
		else{cout<<"\nWrong input!";}
	}
	return 0;
}
