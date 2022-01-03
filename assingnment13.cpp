#include<iostream>
using namespace std;
#define MAX 30
class Deque
{
    private:
    int elements[MAX];
    int front;
    int rear;
    public:
    Deque()
    {
        elements[MAX] = {0};
        front = -1;
        rear = -1;
    }
    bool isEmpty();
    bool isFull();
    void insertRear(int data);
    void insertFront(int data);
    void deleteFront();
    void deleteRear();
    void display();
};


bool Deque::isEmpty()
{
if(front == -1)return true;
else return false;
}

bool Deque::isFull()
{
if(rear == MAX-1)return true;
else return false;
}

void Deque::insertRear(int data)
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

void Deque::insertFront(int data)
{
	if(isEmpty()){front = 0;rear = 0;}
	else
	{
		int i=rear;
		while(i>=front)
		{
			elements[i+1]= elements[i];
			i--;
		}
		front = i+1;
		rear++;
	}
	elements[front] = data;
}
void Deque::deleteRear()
{
	int data;
	if(isEmpty()){cout << "\nCan't delete from empty Deque! ";}
	else
	{
		data = elements[rear];
		rear--;
	}
	cout<<"\nRecently processed job: "<<data;
}

void Deque::deleteFront()
{
    int data;
    if(isEmpty()|| front == rear+1)
    {
        cout <<"\nQueue Empty"<<endl;
    }
    else
    {
        data = elements[front];
        front++;
    }
    cout<<"\nRecently processed job: "<<data;
}
void Deque::display(){
    int i=front;
    cout<<endl;
    if(i == -1){cout<<"Queue is Empty!";}
    else
    {
        while(i<=rear)
        {
            cout << elements[i] << " ";
            i++;
        }
    }
}
void format()
{
    cout<<endl;
    for(int i=0;i<30;i++)
    {
        cout<<"-";
    }
}
int main()
{
    Deque q;
    int id,ask,ask1,ask2,ask22;
    while(1)
    {
    format();
    cout<<"\nMENU:\n1] Create dequeue\n2] Add elements to dequeue\n"
    "3] Delete elements from dequeue\n4] Display dequeue\n5] Exit\n";format();
    cout<<"\nEnter choice:\n>>";cin>>ask;
    if(ask == 1)
    {
        cout<<"\nQueue is now ready!\nEnter some minimum elements in Queue! How many minimum??\n>>";cin>>ask1;
        for(int i=0;i<ask1;i++)
        {
            cout<<"Enter Element "<<i+1<<" : ";cin>>id;
            q.insertRear(id);
        }
        format();
    }
    else if(ask == 2)
    {
        cout<<"\nWhere to add??\n1] At front\t2] At rear\nEnter choice: ";cin>>ask22;
        if(ask22 == 1)
        {
            cout<<"\nHow many to add at front??\n>>";cin>>ask2;
            for(int i=0;i<ask2;i++)
            {
                cout<<"Enter Element "<<i+1<<" : ";cin>>id;
                q.insertFront(id);
            }
            cout<<"Elements added! ";
        }
        else if(ask22 == 2){
        cout<<"\nHow many to add at rear??\n>>";cin>>ask2;
        for(int i=0;i<ask2;i++)
        {
        cout<<"Enter Element "<<i+1<<" : ";cin>>id;
        q.insertRear(id);
        }
        cout<<"Elements added! ";
        }
        else{break;}
        format();
    }
    else if(ask == 3)
    {
        int ask33;
        cout<<"\nFrom where to delete??\n1] At front\t2] At rear\nEnter choice: ";cin>>ask33;
        if(ask33 == 1){q.deleteFront();cout<<"\nElement deleted!\n";}
        else{q.deleteRear();cout<<"\nElement deleted!\n";}
        format();
    }
    else if(ask == 4){q.display();format();}
    else if(ask == 5){cout<<"\nThank You! ";break;}
    else{break;}
    }
    return 0;
}
