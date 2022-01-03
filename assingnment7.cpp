#include<iostream>
using namespace std;
class Node{
	int bit;
	Node* previous;
	Node* next;
	public:
		Node()
		{
			bit = 0;
			previous = NULL;
			next = NULL;
		}
		Node(int data)
		{
			bit = data;
			previous = NULL;
			next = NULL;
		}
	friend class Binary;
};
class Binary{
	Node* start;
	Node* last;
	int bitlength;
	public:
		Binary(){
			start = NULL;
			last = NULL;
			bitlength = 0;
		}
		void addBegin(int data);
		void covertToBinary(int dec);
		Binary onesCompliment();
		Binary twosCompliment();
		Binary addition(Binary &b2);
		void addZeros();
		void display();
};
void Binary::addBegin(int data){
	Node* new_node = new Node(data);
	if(start == NULL && last == NULL)
	{
		start = new_node;
		last = new_node;
	}
	else
	{
		new_node->next = start;
		start->previous = new_node;
		start = new_node;
	}
	bitlength++;
}

void Binary::covertToBinary(int dec)
{
	if(dec==0)
	{
		addBegin(0);

	}
	while(dec>0)
	{
		addBegin(dec%2);
		dec = dec/2;
	}
	addZeros();
}
void Binary::addZeros(){
	while(bitlength%4 != 0)
	{
		addBegin(0);
	}
}
Binary Binary::onesCompliment(){
	Binary C1;
	Node* traveller = last;
	int i=0;
	if(bitlength == 0)
	{
		return C1;
	}
	while(i<bitlength)
	{
		if(traveller->bit==1){C1.addBegin(0);}
		else{C1.addBegin(1);}
		traveller = traveller->previous;
		i++;
	}
	return C1;
}

Binary Binary::twosCompliment(){
	Binary C2 = onesCompliment();
	Node* traveller = C2.last;
	int carry=1;
	while(traveller!= NULL)
	{
		traveller->bit+=carry;

		if(traveller->bit>1)
		{
			traveller->bit=0;
		}
		else{carry=0;}
		traveller=traveller->previous;
	}
	if(carry == 1 && traveller == NULL)
	{
		C2.addBegin(1);
	}
	C2.addZeros();
	return C2;
}
Binary Binary::addition(Binary &b2)
{
	Binary add;
	Node* first = last;
	Node* second = b2.last;
	int sum=0,carry=0;
	while(first!=NULL && second!=NULL)
	{
		sum = (first->bit)+(second->bit)+carry;
		if(sum>1){sum==2?add.addBegin(0):add.addBegin(1);carry=1;}
		else{add.addBegin(sum);carry=0;}
		first=first->previous;
		second=second->previous;
	}
	while(first==NULL && second!=NULL)
	{
		sum = (second->bit)+carry;
		if(sum>1){sum==2?add.addBegin(0):add.addBegin(1);carry=1;}
		else{add.addBegin(sum);}
		second=second->previous;
	}
	while(first!=NULL && second==NULL)
	{
		sum = (first->bit)+carry;
		if(sum>1){sum==2?add.addBegin(0):add.addBegin(1);carry=1;}
		else{add.addBegin(sum);}
		first=first->previous;
	}
	if(first == NULL && second == NULL && carry== 1 && sum == 0){add.addBegin(1);}
	else{add.addZeros();}
	return add;
}
void Binary::display()
{
	Node* traveller = start;

	while(traveller->next!=NULL)
	{
		cout<<traveller->bit<<" ";
		traveller = traveller->next;
	}
	cout<<traveller->bit<<" ";
	cout<<"\tbitlength: "<<bitlength;
}
int main()
{
	int ask,bin1,bin2;
	Binary n1,n2;
	do{
		cout<<"\nMENU:\n\n[1] Convert Decimal to Binary\t\t[3] 1's Complement\n[2] Addition of binary Numbers\t\t[4] 2's Complement\n\nEnter your Choice: ";cin>>ask;
		if(ask == 1)
		{

			cout<<"Enter first Decimal Number: ";cin>>bin1;
			n1.covertToBinary(bin1);
			cout<<"Enter second Decimal Number: ";cin>>bin2;
			n2.covertToBinary(bin2);
			cout<<"\nBinary of "<<bin1<<" : ";n1.display();cout<<"\nBinary of "<<bin2<<" : ";n2.display();
		}
		else if(ask == 2){
			cout<<"\nAddition of Binary 1 and Binary 2 is:\n";
			cout<<"\t\t\t";n1.display();
			cout<<"\n\t\t+\n\t\t\t";n2.display();
			if(bin1<15 || bin2<15){cout<<"\n\t\t\t--------\n\t\t\t";}
			else if(bin1>15 || bin2>15){cout<<"\n\t\t\t----------------\n\t\t\t";}else{}
			n1.addition(n2).display();
			cout<<endl;}
		else if(ask == 3){cout<<"\n1's compliment of Binary 1: ";n1.onesCompliment().display();cout<<"\n1's compliment of Binary 2: ";n2.onesCompliment().display();cout<<endl;}
		else if(ask == 4){cout<<"\n2's compliment of Binary 1: ";n1.twosCompliment().display();cout<<"\n2's compliment of Binary 2: ";n2.twosCompliment().display();cout<<endl;}
		else{cout<<"Wrong Input!";break;}

	}while(1);

	return 0;
}
