#include<iostream>
#include<string.h>
using namespace std;
class vertex;

class edge
{
	edge* next;
	int comm;
	vertex* ptr;

public:
	friend class vertex;
	friend class social;
};
class vertex
{
	char name[20];
	vertex* down;
	edge* start;
public:
	friend class social;
};

class social
{
	vertex* head;
	int size;
	public:
	void create();	
	vertex* getv();
	edge* gete();
	void displayUser();
	vertex* search(char[]);
	void add();
	void displayf();
};

vertex*  social::getv()
{
	vertex* temp=new vertex;
	cout<<endl<<"Enter NAme :";
	cin>>temp->name;
	temp->down=NULL;
	temp->start=NULL;
	return temp;
	
}
void  social ::create()
{
	cout<<"Enter No. Of Vertex :";
	cin>>size;
	head=getv();
	vertex* temp=head;

	for(int i=1;i<size;i++)
	{
		temp->down=getv();
		temp=temp->down;
	}
}
void  social::displayUser()
{
	vertex* temp=head;
	while(temp!=NULL)
	{
		cout<<endl<<temp->name;
		temp=temp->down;
	}
}
vertex* social:: search(char key[10])
{
		vertex* temp=head;
	while(temp!=NULL)
	{
		if(strcmp(temp->name,key)==0)
		{
			cout<<"Found";
			return temp;
		}
		temp=temp->down;
	}
	return 0;
}
void social:: add()
{
	char key1[10],key2[10];
	vertex*a1,*a2;
	cout<<"\n Enter User 1 :";
	cin>>key1;
	a1=search(key1);
	cout<<"\n Enter User 2 :";
	cin>>key2;
	a2=search(key2);
	if(a1->start==NULL)
	{
		edge* temp=new edge;
		a1->start=temp;
		temp->ptr=a2;
		cout<<"Enter Comment :" ;
		cin>>temp->comm;
		temp->next=NULL;
		cout<<"\nYour the first Friend ";
	}
	else
	{
	/*	edge* temp=new edge;
		
		edge* a3=a1->start;
	
				
		temp->ptr=a2;
		cout<<"Enter Comment :" ;
		cin>>temp->comm;
		temp->next=NULL;
		a3->next=temp;
	*/	
	    edge* temp=new edge;
		//Please Help on these
		edge* a3=a1->start;
		while(a3!=NULL)
		{
			a3=a3->next;
		}
	
				
		temp->ptr=a2;
		cout<<"Enter Comment :" ;
		cin>>temp->comm;
		temp->next=NULL;
		a3->next=temp;
	}
}
void social::displayf()
{
	vertex*a1=head;
	
	cout<<"\n"<<a1->start->ptr->name;
	edge* a2=a1->start->next;
	cout<<"\n"<<a2->ptr->name;
}

int main()
{
	class social s;
	int f;
	s.create();
	s.displayUser();
	cout<<"\nEnter No. Of Friend you have to add :";
	cin>>f;
	while(f)
	{
		s.add();
		f--;
	}
	s.displayf();
	return 0;
}
