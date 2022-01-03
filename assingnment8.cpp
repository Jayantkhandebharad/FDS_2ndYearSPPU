#include<iostream>
#include<string>
using namespace std;

class Node
{
	int rollNo;
	Node *next;
	public:
		Node()
		{
			rollNo = 0;
			next=NULL;
		}
		Node(int val)
		{
			rollNo = val;
			next = NULL;
		}
		friend class Icecream;

};

class Icecream
{
	Node *start;
	int length;
	public:
	Icecream()
		{
			start = NULL;
			length = 0;
		}
		/**************************1.insertion********************************/
		void insertEnd(int x)
		{
			Node *n = new Node(x);		// created new node
			/*n->rollNo = x;				// copying values
			n->next = NULL;				// copying values*/
			if(length>0)
			{
				Node*travel = start;
				while(travel!=NULL)
				{
					if(travel->rollNo==x)
					{
						return;
					}
					travel=travel->next;
				}
			}

			if (start == NULL)
			{
				start = n;
			}
			else
			{
				Node *next = start;			//created another pointer variable
				while(next->next != NULL)
				{
					next = next->next;		//Traversing over the link
				}
				next->next = n;
			}

			length++;
		}
		/**************************8.Delete ********************************/
		void deletion(int data)
		{
			Node* check = start;
			Node* pre = check->next;
			if (check->rollNo == data)
			{
				start = check->next;
				delete check;
			}
			else{
				while(pre->rollNo != data)
				{
					if (pre->next == NULL)
					{
						check->next = NULL;
					}
					pre = pre->next;
					check = check->next;
				}
				check->next = pre->next;
				delete pre;
			}
			length--;
		}
		/**************************8.Display********************************/
		void display()
		{
			Node *shw = start;
			while(shw != NULL)
			{
				cout <<" " << shw->rollNo;
				shw = shw->next;
			}
			cout << "\nTotal length is: " << length <<endl;
		}
		Icecream unionSet(Icecream&);
		Icecream intersect(Icecream&);
		Icecream symDiff(Icecream&);
		bool isExist(int rn);
};

Icecream Icecream::unionSet(Icecream& oth)
{
	Icecream uni;
	Node*v = start;
	Node* o = oth.start;
	for(int i=0;i<length;i++)
	{
		uni.insertEnd(v->rollNo);
		v=v->next;
	}
	for(int i=0;i<oth.length;i++)
	{
		uni.insertEnd(o->rollNo);
		o=o->next;
	}
	return uni;

}
Icecream Icecream::intersect(Icecream& fav){
	Icecream both;
	Node* travel1 = start;
	//Node* travel2 = fav.start;

	while(travel1!=NULL)
	{
		Node* travel2 = fav.start;
		while(travel2!=NULL)
		{
			if(travel1->rollNo == travel2->rollNo){
			both.insertEnd(travel1->rollNo);
			}
			travel2=travel2->next;
		}
		travel1=travel1->next;
	}
	return both;
}

Icecream Icecream::symDiff(Icecream& oth){
	Icecream symdiff;
	int i=0,j=0;
	Node *travel1 = start;
	Node *travel2 = oth.start;
	while(i<length && j< oth.length)
	{
		if(travel1->rollNo<travel2->rollNo)
		{
			symdiff.insertEnd(travel1->rollNo);
			travel1 = travel1->next;i++;
		}
		else if(travel1->rollNo>travel2->rollNo)
		{
			symdiff.insertEnd(travel2->rollNo);
			travel2 = travel2->next;j++;
		}
		else{					//if elements same then increament

			travel1 = travel1->next;
			travel2 = travel2->next;
			i++;j++;
		}
	}
	while(i<length){
		symdiff.insertEnd(travel1->rollNo);
		travel1 = travel1->next;i++;
	}
	while(j<oth.length)
	{
		symdiff.insertEnd(travel2->rollNo);
		travel2 = travel2->next;j++;
	}
	return symdiff;
}
bool Icecream::isExist(int rn){
	Node *traveller = start;
	if(length>0)
	{
		while(traveller!=NULL){
			if(traveller->rollNo==rn){return true;}
			else {traveller = traveller->next;}
		}
		if(traveller->rollNo==rn){return true;}
		else return false;
	}
	else {return false;}

}

int main()
{
	Icecream vanilla;
	Icecream butterscoch,both,Nboth;
	string ask;
	char ch;
	int a,flavour,rn;
	while(1)
	{
		cout<<"\n1] Ask students for icecream\n2] Show student status\n3] Exit\n\nEnter choice: ";cin>>a;
		if(a == 1)
		{
			int v=0,b=0;
			cout<<"Enter Roll Number\n>>";cin>>rn;
			do{
				cout<<"\n1] Vanilla\t\t2] ButterScoch\n3] Not from above\n\nChoose flavour:";cin>>flavour;
				if(flavour == 1){vanilla.insertEnd(rn);v++;}
				else if(flavour == 2){butterscoch.insertEnd(rn);b++;}
				else if(flavour == 3){if(vanilla.isExist(rn) || butterscoch.isExist(rn)){cout<<"You Have already taken enough!";break;}else{Nboth.insertEnd(rn);}}
				else{cout<<"Wrong input!";}
				if((v==0 && b==1)||(v==1&&b==0)){cout<<"Do you want another flavour?? (Y/N) ";cin>>ch;}
				if(v==1&&b==1){both = vanilla.intersect(butterscoch);}
				if(ch=='N'||ch=='n')break;
			}while((ch=='Y' || ch=='y') && (v<1 || b<1));

		}
		else if(a == 2)
		{
			cout<<"Total students who took Icecream: ";vanilla.unionSet(butterscoch).display();
			cout<<"Students who took vanilla flavoured icecream: ";vanilla.display();
			cout<<"Students who took butterscoch flavoured icecream: ";butterscoch.display();
			cout<<"Students who took both vanilla and butterscoch flavoured icecream: ";vanilla.intersect(butterscoch).display();
			cout<<"Students who took either vanilla or butterscoch flavoured icecream or not both: ";vanilla.symDiff(butterscoch).unionSet(Nboth).display();
			cout<<"Students who took neither vanilla nor butterscoch flavoured icecream: ";Nboth.display();
		}
		else{
			cout <<"\nThank You!";
			break;
		}
	}
	return 0;
}
