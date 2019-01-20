#include<iostream>
using namespace std;

class node 
{
	//type
	public:

	//pointer to the next node
	node *next;

	//pointer to the previous node
	node *prev;

	//data
	int data;
	
	//construct
	node()
	{
		next=NULL;
		prev=NULL;
	}
};

class dlinklist
{
	//head-> node type pointer
	node *head;

	//tail->node type pointer
	node *tail;

	//type
	public:
	
	//construct
	dlinklist()
	{
		head=NULL;
		tail=NULL;
	}
	
//insert
void insert(int value)
{		
	//addition of the first node
	node *p=new node;

	p->data=value;
	
	//for first node
	if (head==NULL)
	{head=p;}

	//for other nodes
	else
	{p->prev=tail;
	 tail->next=p;}
	tail=p;
}

//insertat
void insertat(int pos,int value)
{
	//condition if given input has more element than the linklist
	if( pos>this->count() )
	cout<<"Linklist doesnot have this many elements"<<endl;

	else
	{
	
	//create a node
	node *temp=new node;

	//ponters moving
	temp->data=value;
	if (pos==1)
	{
		head->prev=temp;
		temp->next=head;
		temp->prev=NULL;
		head=temp;
	}
	else
	{	
		int i=1;
		node *p=head;
		while(i<pos-1)
		{p=p->next;i++;}
		temp->prev=p;
		temp->next=p->next;
		p->next=temp;
		if(temp->next!=NULL)
		temp->next->prev=temp;
	}
	}
}

//del
void del()
{
	//before tail has to point to  null
	node *p=head;
	while(p->next!=tail)
	{p=p->next;}

	//update tail
	tail=p;
	p=p->next;
	tail->next=NULL;
	p->prev=NULL;

	//del p
	delete p;
}

//delat
void delat(int pos)
{
	if( pos>this->count() )
	cout<<"Linklist Doesnt have that many elements"<<endl;
	else
	{

		//reach the place before the pos
		node *p=head;
		int i=1;
		while(i<pos)
		{p=p->next;i++;}
		
		if (p!=head)
		{p->prev->next=p->next;}
		
		if (p!=tail)
		{p->next->prev=p->prev;}
		
		p->next=NULL;
		p->prev=NULL;
		delete p;
		
	}
	
	
}
//cout
int count()
{
	node *p=head;int i=0;
	while(p!=NULL)
	{
		i+=1;
		p=p->next;
	}
	return i;
}

//display
void display()
{
	node *p=head;
	while(p!=NULL)
	{
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<"NULL"<<endl;
}
};

int main()
{
	dlinklist dl;
					            dl.insert(1);dl.insert(2);dl.insert(3);dl.insert(4);dl.insert(5);dl.insert(6);dl.insert(7);dl.insert(8);dl.insert(9);dl.insert(10);
	dl.display();

	dl.insertat(2,5);
	dl.display();

	dl.insertat(12,9);

	dl.del();
	dl.display();

	dl.delat(5);
	dl.display();
	
	//terminating
	return 0;
}
