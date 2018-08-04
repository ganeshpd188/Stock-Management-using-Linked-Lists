#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream.h>
#include<stdlib.h>
class p_data
{
  public:
  char pid[10],pname[50],pcat[50],pgrp[50];
  int price,qty,qty1,d1,m1,y1,d2,m2,y2,d3,m3,y3;
  char cname[50];
  p_data *next;
  void accept();
  void display();
  int check_date(int,int,int);
};

	void p_data::accept()
	 {
		  clrscr();
		  int f;
		  cout<<"enter the name of the product :";
		  cin>>pname;
		  cout<<"enter the product id :";
		  cin>>pid;
		  cout<<"enter the category of the product :";
		  cin>>pcat;
		  cout<<"enter the group of the product :";
		  cin>>pgrp;
		  cout<<"enter the name of the company of the product :";
		  cin>>cname;
		  cout<<"enter the quantity of the product :";
		  cin>>qty;
		  cout<<"enter the price of the product :";
		  cin>>price;
			do{
				  clrscr();
				  cout<<"enter the date of manufature :"<<endl;
				  cin>>d1>>m1>>y1;
				  f=check_date(d1,m1,y1);
				}while(f==1);

			do{
					clrscr();
					cout<<"enter the date of expiry :"<<endl;
					cin>>d2>>m2>>y2;
					f=check_date(d2,m2,y2);
			  }while(f==1);

	  }
	 void p_data::display()
	 {
		 cout<<pname<<"\t"<<pid<<"\t"<<pcat<<"\t"<<pgrp<<"\t"<<cname<<"\t"<<qty<<"\t"<<d1<<"/"<<m1<<"/"<<y1<<"\t\t"<<d2<<"/"<<m2<<"/"<<y2<<endl;
	  }

	 int p_data::check_date(int d,int m,int y)
	  {
			 int f1=1;
			 if(y>0)
			{
			  if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
			 {
				if(d>0 && d<32)
				{
					f1=0;
				}
			 }
			else if(m==4||m==6||m==9||m==11)
			{
			  if(d>0 && d<31)
			  {
				  f1=0;
				}
			 }
			else if(m==2)
			 {
				if(y%4==0 && y%100!=0 || y%400==0)
				 {
					if(d>0 && d<30)
					{
						f1=0;
					 }
				 }
				 else
			  {
				  if(d>0 && d<29)
					f1=0;
				}
			}
		}
		 return f1;
	 }


class product:public p_data
{
  p_data *s;
  public:
  void accept();
  void display();
  void search(char []);
  void mod(char []);
  void del(char []);
  void insert(int);
  void show_record();
  void sort_by_pname();
  void sort_by_cname();
  void sort_by_pid();
  void sort_menu();
  void save();
  void graph();
  void draw(int);
  p_data *load();
  product();
};
//constructor
	product::product()
	{
		  s=NULL;
	}

	 void product::accept()
	{
		clrscr();
		p_data *p,*t;
		char ch='y';
		while(ch=='y')
		{
			p=new p_data;
			p->accept();
			if(s==NULL)
			  s=p;
			else
			  t->next=p;
			t=p;
		  cout<<"do you wish to cont...[y/n]";
		  cin>>ch;
		 }
	}
	 void product::display()
	{
		clrscr();
		p_data *p;
		s=load();
		cout<<"name\tid\tgrp\tcat\tcname\tqty\tdom\t\tdoe"<<endl;
		for(p=s;p!=NULL;p=p->next)
	  {
		  p->display();
	  }
		getch();
	}
	void product::search(char m[])
  {
	  clrscr();
	  s=load();
	  cout<<"name\tgrp\tcat\tcname\tqty"<<endl;
	  for(p_data *p=s;p!=NULL;p=p->next)
	  {
		  if(strcmpi(p->pid,m)==0)
		 {
			 cout<<p->pname<<"\t"<<p->pgrp<<"\t"<<p->pcat<<"\t"<<p->cname<<"\t"<<p->qty<<endl;
		  }
	  }
  }
	void product::del(char m[])
  {
		p_data *t,*p;
		char ch='y';
		s=load();
		if(strcmpi(s->pid,m)==0)
		{
			p=s;
			s=s->next;
			free(p);
		}
		else
		{
			for(t=s,p=s;p!=NULL;t=p,p=p->next)
			{
				if(strcmpi(p->pid,m)==0)
			  {
				 t->next=p->next;
				 free(p);
				 p=t;
			  }
		  }
	  }
		for(p=s;p!=NULL;p=p->next)
	  {
		  cout<<p->pname<<endl;
		}
		cout<<"do you want to save [y/n]:";
		cin>>ch;
		if(ch=='y')
		save();
  }

	void product::mod(char m[])
  {
		p_data *p;
		s=load();
		char ch='y';
		for(p=s;p!=NULL;p=p->next)
		{
			if(strcmpi(p->pid,m)==0)
			{
				p->accept();
			}
		}
		cout<<"do you wish to save it..[y/n]";
		cin>>ch;
		if(ch=='y')
		 save();
	}
	void product::insert(int pos)
  {
		p_data *x;
		s=load();
		int i;
		char ch='y';
		p_data *p;
		if(pos==1)
		{
			x=new p_data;
			x->accept();
			x->next=s;
			s=x;
		}
		else
		{
			for(p=s,i=2;p->next!=NULL;p=p->next,i++)
			{
				if(i==pos)
				{
					x=new p_data;
					x->accept();
					x->next=p->next;
					p->next=x;
				}
			}
		}
		cout<<"do you wish to save it..[y/n]";
		cin>>ch;
		if(ch=='y')
	  save();
  }

//this function will show the all the records of the current products

	void product::show_record()
  {
		product pp;
		load();
		cout<<"name\tgrp\tcat\tcname\tqty"<<endl;
		ifstream fin("product",ios::in|ios::binary);
		while(fin.read((char*)&pp,sizeof(pp)))
		{
			 cout<<pp.pname<<"\t"<<pp.pgrp<<"\t"<<pp.pcat<<"\t"<<pp.cname<<"\t"<<pp.qty<<endl;
		 }
	}

//this function will save the records in the file
	 void product::save()
	{
		clrscr();
		product pp;
		char temp[8];
		p_data *p;
		ofstream fout("product",ios::out|ios::binary);
		for(p=s;p!=NULL;p=p->next)
		{
			fout.write((char *)p,sizeof(pp));
		 }
		fout.close();
		cout<<"pid"<<"\t"<<"pname"<<"\t"<<"grp"<<"\t"<<"cat"<<"\t"<<"qty"<<"\t"<<"dom"<<"\t\t"<<"doe"<<endl;
		ifstream fin("product",ios::in|ios::binary);
		while(fin.read((char *)&pp,sizeof(pp)))
		{
		  cout<<pp.pid<<"\t"<<pp.pname<<"\t"<<pp.pgrp<<"\t"<<pp.pcat<<"\t"<<pp.qty<<"\t"<<pp.d1<<"/"<<pp.m1<<"/"<<pp.y1<<"\t"<<pp.d2<<"/"<<pp.m2<<"/"<<pp.y2<<endl;
		}
		fin.close();
	}

  //this function will convert the file records into the linked list
	p_data *product::load()
	{
		clrscr();
		p_data *p,*t;
		product pp;
		ifstream fin("product",ios::in|ios::binary);
		while(fin.read((char *)&pp,sizeof(pp)))
		{
			p=new product;
			*p=pp;
			if(s==NULL)
			 s=p;
			else
			 t->next=p;
			t=p;
		}
	 /* for(p=s;p!=NULL;p=p->next)
	  {
		 cout<<p->pname<<endl;
	  }*/
			return s;
	 }

	 void product::graph()
	 {
		  clrscr();
		  product pp;
		  int x1,y1,x2,y2,i,j,l;

		  char a[10]={"quantity"};
		 for(i=7,j=0;i<=15,a[j]!=NULL;i++,j++)
		{
			gotoxy(1,i);
			cout<<a[j]<<endl;
		 }
			for(j=2;j<=20;j++)
		 {
			 gotoxy(6,j);
			 cout<<"|";
			 cout<<endl;
		 }
		 i=1;

		 for(j=2,l=9;j<=20,l>=1;j++,l--)
		{
			gotoxy(3,j+i);
			cout<<l;
			i+=1;
		 }
	  for(i=3;i<=70;i++)
	  {
		  gotoxy(i,20);
		  cout<<"-";
		}
			cout<<">"<<endl;
		int k,q;
		gotoxy(30,22);
		cout<<"product id";
		ifstream fin("product",ios::in|ios::binary);
		while(fin.read((char *)&pp,sizeof(pp)))
		{
			gotoxy(7+k,21);
			cout<<pp.pid;
			for(i=0;i<pp.qty;i++)
		  {
				}
			for(j=(i*2)-1;j>=1;j--)
			{
				gotoxy(7+k,20-j);
				cout<<char(219);
			}
			k+=10;
		}
		fin.close();
		getch();
 }
//this function will show the sort menu

	  void product::sort_menu()
	{
			clrscr();
		product pp;
		char b;
		while(1)
		{
			 clrscr();
			 gotoxy(27,8);
			 cout<<"1.sort by company name ";
			 gotoxy(27,9);
			 cout<<"2.sort by product name ";
			 gotoxy(27,10);
			 cout<<"3.sort by product id ";
			 gotoxy(27,11);
			 cout<<"0.quit";
			 fflush(stdin);
			 gotoxy(27,12);
			 cout<<"enter your choice ";
			 cin>>b;
				if(b=='0')
				  return;
				else if(b=='1')
				 {
						 clrscr();
						 sort_by_cname();
						 getch();
				  }
				  else if(b=='2')
				  {
						 clrscr();
						 sort_by_pname();
						 getch();
					 }
				else if(b=='3')
				{
						 clrscr();
						 sort_by_pid();
						 getch();
				  }
		 }
	}
 //this function will sort by the company name
	void product::sort_by_cname()
 {
	p_data *t,*x;

	 for(p_data *p=s;p!=NULL;p=p->next)
	 {
		 for(t=p->next;t!=NULL;t=t->next)
		{
			 if(strcmpi(p->cname,t->cname)>0)
		  {
				strcpy(x->pname,p->pname);
				strcpy(p->pname,t->pname);
				strcpy(t->pname,x->pname);
				strcpy(x->cname,p->cname);
				strcpy(p->cname,t->cname);
				strcpy(t->cname,x->cname);
				strcpy(x->pcat,p->pcat);
				strcpy(p->pcat,t->pcat);
				strcpy(t->pcat,x->pcat);
				strcpy(x->pid,p->pid);
				strcpy(p->pid,t->pid);
				strcpy(t->pid,x->pid);
				strcpy(x->pgrp,p->pgrp);
				strcpy(p->pgrp,t->pgrp);
				strcpy(t->pgrp,x->pgrp);
				x->qty=p->qty;
				p->qty=t->qty;
				t->qty=x->qty;
			 }
		 }
	 }
 }
 //this function will sort by product name
  void product::sort_by_pname()
 {
	p_data *p,*t,*x;
	 for(p=s;p!=NULL;p=p->next)
	 {
		 for(t=p->next;t!=NULL;t=t->next)
		{
			 if(strcmpi(p->pname,t->pname)>0)
		  {
				strcpy(x->pname,p->pname);
				strcpy(p->pname,t->pname);
				strcpy(t->pname,x->pname);
				strcpy(x->cname,p->cname);
				strcpy(p->cname,t->cname);
				strcpy(t->cname,x->cname);
				strcpy(x->pcat,p->pcat);
				strcpy(p->pcat,t->pcat);
				strcpy(t->pcat,x->pcat);
				strcpy(x->pid,p->pid);
				strcpy(p->pid,t->pid);
				strcpy(t->pid,x->pid);
				strcpy(x->pgrp,p->pgrp);
				strcpy(p->pgrp,t->pgrp);
				strcpy(t->pgrp,x->pgrp);
				x->qty=p->qty;
				p->qty=t->qty;
				t->qty=x->qty;
			 }
		 }
	}
 }
 //this function will sort by product id
  void product::sort_by_pid()
 {
	 p_data *p,*t,*x;
	 for(p=s;p!=NULL;p=p->next)
	 {
		 for(t=p->next;t!=NULL;t=t->next)
		{
			 if(strcmpi(p->pid,t->pid)>0)
		  {
				strcpy(x->pname,p->pname);
				strcpy(p->pname,t->pname);
				strcpy(t->pname,x->pname);
				strcpy(x->cname,p->cname);
				strcpy(p->cname,t->cname);
				strcpy(t->cname,x->cname);
				strcpy(x->pcat,p->pcat);
				strcpy(p->pcat,t->pcat);
				strcpy(t->pcat,x->pcat);
				strcpy(x->pid,p->pid);
				strcpy(p->pid,t->pid);
				strcpy(t->pid,x->pid);
				strcpy(x->pgrp,p->pgrp);
				strcpy(p->pgrp,t->pgrp);
				strcpy(t->pgrp,x->pgrp);
				x->qty=p->qty;
				p->qty=t->qty;
				t->qty=x->qty;
			 }
		 }
	 }
 }

 class v_data
{
  public:
  char vid[20],vname[20],vadd[20],vcno[10],vmail[20],vtin[20],vproq[20],vpro[20][20],vproi[20][20],vprop[20][20];
  v_data *next;
  int i,rate;//,vprop[20][20];
  char z;
  void accept();
  void display();
  void display2();
};
  void v_data::accept()
  { clrscr();
	// purchase rr;
	 i=0;
	 cout<<"enter the id of the vendor :";
	 cin>>vid;
	 cout<<"enter the name of the vendor :";
	 cin>>vname;
	 cout<<"enter the address of the vendor :";
	 cin>>vadd;
	 cout<<"enter the contact number of the vendor :";
	 cin>>vcno;
	 cout<<"enter the email id of the vendor :";
	 cin>>vmail;
	 cout<<"enter the transiction number :";
	 cin>>vtin;
	 cout<<"how many stars you want to give to this vendor :";
	 cin>>rate;
	 cout<<"do you want to add the product list to the vendor :[y/n]";
	 cin>>z;
	 while(z=='y')
	 {
		  cout<<"enter the name of the product :";
		  cin>>vpro[i];
		  cout<<"enter the id of the product :";
		  cin>>vproi[i];
		  cout<<"enter the quantity of the product :";
		  cin>>vproq[i];
		  cout<<"enter the price :";
		  cin>>vprop[i];
		  i++;
		  cout<<"do you wish to continue[y/n] ";
		  cin>>z;
	  }
 }
  void v_data::display()
  {
	  cout<<vid<<"\t"<<vname<<"\t"<<vadd<<"\t"<<vcno<<"\t"<<vmail<<"\t"<<vtin<<endl;
	}
	  void v_data::display2()
  {
	  clrscr();
	  cout<<"id------>"<<vid<<endl;
	  cout<<"name---->"<<vname<<endl;
	  cout<<"address->"<<vadd<<endl;
	  cout<<"contact->"<<vcno<<endl;
	  cout<<"mail---->"<<vmail<<endl;
	  cout<<"tin----->"<<vtin<<endl;
	  cout<<"rate---->"<<rate<<endl;
	  cout<<"products list "<<endl;
	  cout<<"**************"<<endl;
	  cout<<"name\tid\tqty\tprice"<<endl;
	  for(int j=0;j<i;j++)
	  {
		  cout<<vpro[j]<<"\t"<<vproi[j]<<"\t"<<vproq[j]<<"\t"<<vprop[j]<<endl;
	  }
	}

class vendor:public v_data
{
  v_data *s;
  public:
  void accept();
  void display();
  void search(char []);
  void mod(char []);
  void del(char []);
  void insert(int);
  void show_record();
  void sort_by_vname();
  void sort_by_vtin();
  void sort_by_vid();
  void sort_menu2();
  void save();
  v_data *load();
  vendor();
};
vendor::vendor()
{
	s=NULL;
}
void vendor::accept()
{
	clrscr();
	v_data *p,*t;
	char ch='y';
	while(ch=='y')
	{
		p=new v_data;
		p->accept();
		if(s==NULL)
			s=p;
		else
				t->next=p;
		 t=p;
		cout<<"do you wish to cont...[y/n]";
		cin>>ch;
	}
}
void vendor::display()
{
	 v_data *p;
	 s=load();
	  cout<<"vid"<<"\t"<<"vname"<<"\t"<<"vadd"<<"\t"<<"vcno"<<"\t"<<"vmail"<<"\t"<<"vtin"<<endl;
	for(p=s;p!=NULL;p=p->next)
	{
		p->display();
	}
}
//this function will search any particular vendor

void vendor::search(char m[])
{
	clrscr();
	s=load();
	cout<<"id\tname\tadd\tc.no.\tmail\ttin"<<endl;
	for(v_data *p=s;p!=NULL;p=p->next)
	{
	  if(strcmpi(p->vid,m)==0)
	  {
		 cout<<p->vid<<"\t"<<p->vname<<"\t"<<p->vadd<<"\t"<<p->vcno<<"\t"<<p->vmail<<"\t"<<p->vtin<<endl;
	  }
	}
}

//this function will delete the record of the vendor
void vendor::del(char m[])
{
	v_data *p,*t;
	s=load();
	char ch='y';
	if(strcmpi(s->vid,m)==0)
	{
		p=s;
		s=s->next;
		free(p);
	}
	else
	{
		for(t=s,p=s;p!=NULL;t=p,p=p->next)
		{
		  if(strcmpi(p->vid,m)==0)
		  {
			  t->next=p->next;
			  free(p);
			  p=t;
			}
		}
	}
	cout<<"do you wish to save..[y/n]";
	cin>>ch;
	if(ch=='y')
	 save();
}

//this function will modify the vendor's record
void vendor::mod(char m[])
{
	v_data *p;
	s=load();
	char ch='y';
	for(p=s;p!=NULL;p=p->next)
	{
		if(strcmpi(p->vid,m)==0)
		{
			p->accept();
		}
	}
	cout<<"do you wish to save..[y/n]";
	cin>>ch;
	if(ch=='y')
	 save();
}
//this function will insert record
void vendor::insert(int c)
{
	v_data *x;
	int i;
	char ch='y';
	v_data *p;
	s=load();
	if(c==1)
	{
		x=new v_data;
		x->accept();
		x->next=s;
		s=x;
	}
	else
	{
		for(p=s,i=2;p->next!=NULL;p=p->next,i++)
		{
			if(i==c)
			{
				x=new v_data;
				x->accept();
				x->next=p->next;
				p->next=x;
			}
		}
	}
	cout<<"do you wish to save it..[y/n]";
	cin>>ch;
	if(ch=='y')
	save();
}
//this function will show the details of the vendor along with it's product list

void vendor::show_record()
{
	 vendor vv;
	load();
	cout<<"id\tname\tadd\tcno\tvmail\tvtin"<<endl;
	ifstream fin("vendor",ios::in|ios::binary);
	while(fin.read((char*)&vv,sizeof(vv)))
	{
			 cout<<vv.vid<<"\t"<<vv.vname<<"\t"<<vv.vadd<<"\t"<<vv.vcno<<"\t"<<vv.vmail<<"\t"<<vv.vtin<<endl;
	}

}
//this function will save the linked list into the file
void vendor::save()
{
	clrscr();
	vendor vv;
	char temp[8];
	v_data *p;
	ofstream fout("vendor",ios::out|ios::binary);
		for(p=s;p!=NULL;p=p->next)
	{
		fout.write((char *)p,sizeof(vv));
	 }
	fout.close();
	cout<<"vid"<<"\t"<<"vname"<<"\t"<<"vadd"<<"\t"<<"vcno"<<"\t"<<"vmail"<<"\t"<<"vtin"<<endl;

	ifstream fin("vendor",ios::in|ios::binary);
	while(fin.read((char *)&vv,sizeof(vv)))
	{
	  cout<<vv.vid<<"\t"<<vv.vname<<"\t"<<vv.vadd<<"\t"<<vv.vcno<<"\t"<<vv.vmail<<"\t"<<vv.vtin<<endl;
	}
	fin.close();
 }

 //this function will convert the file records into the linked list
 v_data *vendor::load()
 {
	  clrscr();
	  v_data *p,*t;
	  vendor vv;
	  ifstream fin("vendor",ios::in|ios::binary);
	  while(fin.read((char *)&vv,sizeof(vv)))
	  {
		 p=new vendor;
		 *p=vv;
		 if(s==NULL)
			s=p;
		 else
			t->next=p;
		 t=p;
	  }
	 /* for(p=s;p!=NULL;p=p->next)
	  {
		 cout<<p->pname<<endl;
	  }*/
	  return s;
  }


//this function will show the sort menu
void vendor::sort_menu2()
 {
	clrscr();
	char b;
	while(1)
	{ clrscr();
	  gotoxy(27,8);
	  cout<<"1.sort by company name ";
	  gotoxy(27,9);
	  cout<<"2.sort by product name ";
	  gotoxy(27,10);
	  cout<<"3.sort by product id ";
	  gotoxy(27,11);
	  cout<<"0.quit";
	  fflush(stdin);
	  gotoxy(27,12);
	  cout<<"enter your choice ";
	  cin>>b;
	  if(b=='0')
	  return;
	  else if(b=='1')
	  {
		 clrscr();
		 sort_by_vname();
		 getch();
	  }
	  else if(b=='2')
	  {
		 clrscr();
		 sort_by_vid();
		 getch();
	  }
		else if(b=='3')
	  {
		 clrscr();
		 sort_by_vtin();
		 getch();
	  }
  }
}



//this functoion will sort by vendor's name
	void vendor::sort_by_vname()
 {
	v_data *t,*x;

	 for(v_data *p=s;p!=NULL;p=p->next)
	 {
		 for(t=p->next;t!=NULL;t=t->next)
		{
			 if(strcmpi(p->vname,t->vname)>0)
			 {
				strcpy(x->vname,p->vname);
				strcpy(p->vname,t->vname);
				strcpy(t->vname,x->vname);
				strcpy(x->vid,p->vid);
				strcpy(p->vid,t->vid);
				strcpy(t->vid,x->vid);
				strcpy(x->vadd,p->vadd);
				strcpy(p->vadd,t->vadd);
				strcpy(t->vadd,x->vadd);
				strcpy(x->vcno,p->vcno);
				strcpy(p->vcno,t->vcno);
				strcpy(t->vcno,x->vcno);
				strcpy(x->vmail,p->vmail);
				strcpy(p->vmail,t->vmail);
				strcpy(t->vmail,x->vmail);
				strcpy(x->vtin,p->vtin);
				strcpy(p->vtin,t->vtin);
				strcpy(t->vtin,x->vtin);
			 }
		 }
	 }
 }
 //this function will sort by vendor's id
	void vendor::sort_by_vid()
 {
	v_data *t,*x;

	 for(v_data *p=s;p!=NULL;p=p->next)
	 {
		 for(t=p->next;t!=NULL;t=t->next)
		{
			 if(strcmpi(p->vid,t->vid)>0)
			{
				strcpy(x->vname,p->vname);
				strcpy(p->vname,t->vname);
				strcpy(t->vname,x->vname);
				strcpy(x->vid,p->vid);
				strcpy(p->vid,t->vid);
				strcpy(t->vid,x->vid);
				strcpy(x->vadd,p->vadd);
				strcpy(p->vadd,t->vadd);
				strcpy(t->vadd,x->vadd);
				strcpy(x->vcno,p->vcno);
				strcpy(p->vcno,t->vcno);
				strcpy(t->vcno,x->vcno);
				strcpy(x->vmail,p->vmail);
				strcpy(p->vmail,t->vmail);
				strcpy(t->vmail,x->vmail);
				strcpy(x->vtin,p->vtin);
				strcpy(p->vtin,t->vtin);
				strcpy(t->vtin,x->vtin);
			 }
		 }
	 }
 }
//this function will sort by vendor's TIN
	void vendor::sort_by_vtin()
 {
	v_data *t,*x;

	 for(v_data *p=s;p!=NULL;p=p->next)
	 {
		 for(t=p->next;t!=NULL;t=t->next)
		{
			 if(strcmpi(p->vtin,t->vtin)>0)
			 {
				strcpy(x->vname,p->vname);
				strcpy(p->vname,t->vname);
				strcpy(t->vname,x->vname);
				strcpy(x->vid,p->vid);
				strcpy(p->vid,t->vid);
				strcpy(t->vid,x->vid);
				strcpy(x->vadd,p->vadd);
				strcpy(p->vadd,t->vadd);
				strcpy(t->vadd,x->vadd);
				strcpy(x->vcno,p->vcno);
				strcpy(p->vcno,t->vcno);
				strcpy(t->vcno,x->vcno);
				strcpy(x->vmail,p->vmail);
				strcpy(p->vmail,t->vmail);
				strcpy(t->vmail,x->vmail);
				strcpy(x->vtin,p->vtin);
				strcpy(p->vtin,t->vtin);
				strcpy(t->vtin,x->vtin);
			 }
		 }
	 }
 }

 class u_data
{
  public:
  char uid[20],uname[20],uadd[20],ucno[10],umail[20],utin[20],upro[20][20];
  u_data *next;
  char z;
  int i,rate;
  void accept();
  void display();
  void display2();
};
  void u_data::accept()
  { clrscr();
	 i=0;
	 cout<<"enter the id of the customer :";
	 cin>>uid;
	 cout<<"enter the name of the customer :";
	 cin>>uname;
	 cout<<"enter the address of the customer :";
	 cin>>uadd;
	 cout<<"enter the contact number of the customer :";
	 cin>>ucno;
	 cout<<"enter the email id of the customer :";
	 cin>>umail;
	 cout<<"enter the transiction number :	";
	 cin>>utin;
	  cout<<"how many stars do you give to this vendor ";
	 cin>>rate;
	 do{
		  cout<<"enter the list of the products " ;
		  cin>>upro[i];
		  i++;
		  cout<<"do you wish to continue :[y/n]";
		  cin>>z;
		 }while(z=='y');
  }
  void u_data::display()
  {
	  cout<<uid<<"\t"<<uname<<"\t"<<uadd<<"\t"<<ucno<<"\t"<<umail<<"\t"<<utin<<endl;
	}
	  void u_data::display2()
  {
	  clrscr();
	  cout<<"id------>"<<uid<<endl;
	  cout<<"name---->"<<uname<<endl;
	  cout<<"address->"<<uadd<<endl;
	  cout<<"contact->"<<ucno<<endl;
	  cout<<"mail---->"<<umail<<endl;
	  cout<<"tin----->"<<utin<<endl;
	  cout<<"rate---->"<<rate<<endl;
	  cout<<"products list "<<endl;
	  cout<<"**************"<<endl;
	  for(int j=0;j<i;j++)
	  {
		  cout<<upro[j]<<endl;
	  }
	}

class customer:public u_data
{
  u_data *s;
  public:
  void accept();
  void display();
  void search(char []);
  void mod(char []);
  void del(char []);
  void insert(int);
  void show_record();
  void sort_by_uname();
  void sort_by_utin();
  void sort_by_uid();
  void sort_menu3();
  void save();
  u_data *load();
  customer();
};
customer::customer()
{
	s=NULL;
}
void customer::accept()
{
	clrscr();
	u_data *p,*t;
	char ch='y';
	while(ch=='y')
	{
		p=new u_data;
		p->accept();
		if(s==NULL)
			s=p;
		else
				t->next=p;
		 t=p;
		cout<<"do you wish to cont...[y/n]";
		cin>>ch;
	}
}
void customer::display()
{
	  s=load();
	  cout<<"uid"<<"\t"<<"uname"<<"\t"<<"uadd"<<"\t"<<"ucno"<<"\t"<<"umail"<<"\t"<<"utin"<<endl;
	for(u_data *p=s;p!=NULL;p=p->next)
	{
		p->display();
	}
}
void customer::search(char m[])
{
	clrscr();
	s=load();
	cout<<"id\tname\tadd\tc.no.\tmail\ttin"<<endl;
	for(u_data *p=s;p!=NULL;p=p->next)
	{
	  if(strcmpi(p->uid,m)==0)
	  {
		 cout<<p->uid<<"\t"<<p->uname<<"\t"<<p->uadd<<"\t"<<p->ucno<<"\t"<<p->umail<<"\t"<<p->utin<<endl;
	  }
	}
}
void customer::del(char m[])
{
	u_data *p,*t;
	s=load();
	char ch='y';
	if(strcmpi(s->uid,m)==0)
	{
		p=s;
		s=s->next;
		free(p);
	}
	else
	{
		for(t=s,p=s;p!=NULL;t=p,p=p->next)
		{
		  if(strcmpi(p->uid,m)==0)
		  {
			  t->next=p->next;
			  free(p);
			  p=t;
			}
		}
	}
	cout<<"do you wish to save it..[y/n]";
	cin>>ch;
	if(ch=='y')
	save();
}
void customer::mod(char m[])
{
	u_data *p;
	char ch='y';
	for(p=s;p!=NULL;p=p->next)
	{
		if(strcmpi(p->uid,m)==0)
		{
			p->accept();
		}
	}
	cout<<"do you wish to save it..[y/n]";
	cin>>ch;
	if(ch=='y')
	save();
}

void customer::insert(int c)
{
	u_data *x;
	int i;
	char ch='y';
	u_data *p;
	if(c==1)
	{
		x=new u_data;
		x->accept();
		x->next=s;
		s=x;
	}
	else
	{
		for(p=s,i=2;p->next!=NULL;p=p->next,i++)
		{
			if(i==c)
			{
				x=new u_data;
				x->accept();
				x->next=p->next;
				p->next=x;
			}
		}
	}
	cout<<"do you wish to save it...[y/n]";
	cin>>ch;
	if(ch=='y')
	save();
}
void customer::show_record()
{
  clrscr();
  customer uu;
  cout<<"id\tname\tadd\tcno\tmail\ttin"<<endl;
  ifstream fin("customer",ios::in|ios::binary);
  while(fin.read((char *)&uu,sizeof(uu)))
  {
		cout<<uu.uid<<"\t"<<uu.uname<<"\t"<<uu.uadd<<"\t"<<uu.ucno<<"\t"<<uu.umail<<"\t"<<uu.utin<<endl;
	}
}


//this function will save the linked list into the file
void customer::save()
{
	clrscr();
	customer uu;
	char temp[8];
	u_data *p;
	ofstream fout("customer",ios::out|ios::binary);
		for(p=s;p!=NULL;p=p->next)
	{
		fout.write((char *)p,sizeof(uu));
	 }
	fout.close();
	cout<<"uid"<<"\t"<<"uname"<<"\t"<<"uadd"<<"\t"<<"ucno"<<"\t"<<"umail"<<"\t"<<"utin"<<endl;

	ifstream fin("customer",ios::in|ios::binary);
	while(fin.read((char *)&uu,sizeof(uu)))
	{
	  cout<<uu.uid<<"\t"<<uu.uname<<"\t"<<uu.uadd<<"\t"<<uu.ucno<<"\t"<<uu.umail<<"\t"<<uu.utin<<endl;
	}
	fin.close();
 }

 //this function will convert the file records into the linked list
 u_data *customer::load()
 {
	  clrscr();
	  u_data *p,*t;
	  customer uu;
	  ifstream fin("customer",ios::in|ios::binary);
	  while(fin.read((char *)&uu,sizeof(uu)))
	  {
		 p=new customer;
		 *p=uu;
		 if(s==NULL)
			s=p;
		 else
			t->next=p;
		 t=p;
	  }
	 /* for(p=s;p!=NULL;p=p->next)
	  {
		 cout<<p->pname<<endl;
	  }*/
	  return s;
  }


//this function will show the sort menu
void customer::sort_menu3()
 {
	clrscr();
	char b;
	while(1)
	{ clrscr();
	  gotoxy(27,8);
	  cout<<"1.sort by company name ";
	  gotoxy(27,9);
	  cout<<"2.sort by product name ";
	  gotoxy(27,10);
	  cout<<"3.sort by product id ";
	  gotoxy(27,11);
	  cout<<"0.quit";
	  fflush(stdin);
	  gotoxy(27,12);
	  cout<<"enter your choice ";
	  cin>>b;
	  if(b=='0')
	  return;
	  else if(b=='1')
	  {
		 clrscr();
		 sort_by_uname();
		 getch();
	  }
	  else if(b=='2')
	  {
		 clrscr();
		 sort_by_uid();
		 getch();
	  }
		else if(b=='3')
	  {
		 clrscr();
		 sort_by_utin();
		 getch();
	  }
  }
}
	void customer::sort_by_uname()
 {
	u_data *t,*x;

	 for(u_data *p=s;p!=NULL;p=p->next)
	 {
		 for(t=p->next;t!=NULL;t=t->next)
		{
			 if(strcmpi(p->uname,t->uname)>0)
			 {
				strcpy(x->uname,p->uname);
				strcpy(p->uname,t->uname);
				strcpy(t->uname,x->uname);
				strcpy(x->uid,p->uid);
				strcpy(p->uid,t->uid);
				strcpy(t->uid,x->uid);
				strcpy(x->uadd,p->uadd);
				strcpy(p->uadd,t->uadd);
				strcpy(t->uadd,x->uadd);
				strcpy(x->ucno,p->ucno);
				strcpy(p->ucno,t->ucno);
				strcpy(t->ucno,x->ucno);
				strcpy(x->umail,p->umail);
				strcpy(p->umail,t->umail);
				strcpy(t->umail,x->umail);
				strcpy(x->utin,p->utin);
				strcpy(p->utin,t->utin);
				strcpy(t->utin,x->utin);
			 }
		 }
	 }
 }
	void customer::sort_by_uid()
 {
	u_data *t,*x;

	 for(u_data *p=s;p!=NULL;p=p->next)
	 {
		 for(t=p->next;t!=NULL;t=t->next)
		{
			 if(strcmpi(p->uid,t->uid)>0)
			{
				strcpy(x->uname,p->uname);
				strcpy(p->uname,t->uname);
				strcpy(t->uname,x->uname);
				strcpy(x->uid,p->uid);
				strcpy(p->uid,t->uid);
				strcpy(t->uid,x->uid);
				strcpy(x->uadd,p->uadd);
				strcpy(p->uadd,t->uadd);
				strcpy(t->uadd,x->uadd);
				strcpy(x->ucno,p->ucno);
				strcpy(p->ucno,t->ucno);
				strcpy(t->ucno,x->ucno);
				strcpy(x->umail,p->umail);
				strcpy(p->umail,t->umail);
				strcpy(t->umail,x->umail);
				strcpy(x->utin,p->utin);
				strcpy(p->utin,t->utin);
				strcpy(t->utin,x->utin);
			 }
		 }
	 }
 }
	void customer::sort_by_utin()
 {
	u_data *t,*x;

	 for(u_data *p=s;p!=NULL;p=p->next)
	 {
		 for(t=p->next;t!=NULL;t=t->next)
		{
			 if(strcmpi(p->utin,t->utin)>0)
			 {
				strcpy(x->uname,p->uname);
				strcpy(p->uname,t->uname);
				strcpy(t->uname,x->uname);
				strcpy(x->uid,p->uid);
				strcpy(p->uid,t->uid);
				strcpy(t->uid,x->uid);
				strcpy(x->uadd,p->uadd);
				strcpy(p->uadd,t->uadd);
				strcpy(t->uadd,x->uadd);
				strcpy(x->ucno,p->ucno);
				strcpy(p->ucno,t->ucno);
				strcpy(t->ucno,x->ucno);
				strcpy(x->umail,p->umail);
				strcpy(p->umail,t->umail);
				strcpy(t->umail,x->umail);
				strcpy(x->utin,p->utin);
				strcpy(p->utin,t->utin);
				strcpy(t->utin,x->utin);
			 }
		 }
	 }
 }



class purchase
{
	friend class p_data;
	public:
	void acceptv();
	void acceptp();
	void bill();
};
 void purchase::acceptv()
{
  clrscr();
  vendor vv;
  char m[20];
  int i;
  cout<<"enter the id of the vendor from which you want to purchase :";
  cin>>m;
	v_data *s1=NULL,*p1,*t1,x1;
	ifstream fin("vendor",ios::in|ios::binary);
	while(fin.read((char *)&vv,sizeof(vv)))
	{
		p1=new vendor;
		*p1=vv;
		p1->next=NULL;
		if(s1==NULL)
			s1=p1;
		else
		{
			 t1->next=p1;
		 }
	  t1=p1;
	}
	for(p1=s1;p1!=NULL;p1=p1->next)
	{
		if(strcmpi(p1->vid,m)==0)
		{
		  clrscr();
		  p1->display2();
		 /* cout<<"id        :"<<p1->vid<<endl;
		  cout<<"name      :"<<p1->vname<<endl;
		  cout<<"mail      :"<<p1->vmail<<endl;
		  cout<<"rating    :"<<p1->rate<<endl;
		  cout<<"contact   :"<<p1->vcno<<endl;*/
		}
  }
	fin.close();
 }

  void purchase::acceptp()
 {
	clrscr();
	product pp;
	char q[20];
	cout<<"enter the id of the product  you want to purchase :";
	cin>>q;
	p_data *s=NULL,*p,*t;
	ifstream fin("product",ios::in|ios::binary);
	while(fin.read((char *)&pp,sizeof(pp)))
	{
		p=new product;
		*p=pp;
		p->next=NULL;
		if(s==NULL)
			s=p;
		else
		{
			 t->next=p;
		 }
	  t=p;
	}
	fin.close();
	 struct date d;
	 getdate(&d);
	 pp.d3=d.da_day;
	 pp.m3=d.da_mon;
	 pp.y3=d.da_year;
	for(p=s;p!=NULL;p=p->next)
	{
		if(strcmpi(p->pid,q)==0)
		{
		  clrscr();
		  cout<<"id           :"<<p->pid<<endl;
		  cout<<"name         :"<<p->pname<<endl;
		  cout<<"qty          :"<<p->qty<<endl ;
		  cout<<"purchase date:"<<pp.d3<<"/"<<pp.m3<<"/"<<pp.y3<<endl;
		  ofstream fout("product",ios::in|ios::binary);
		  fout.write((char *)&pp,sizeof(pp));
		  cout<<"enter the quantity you want to purchase :";
		  cin>>p->qty1;
		  p->qty+=p->qty1;
		}
  }
		clrscr();
		ifstream fin1("product",ios::in|ios::binary);
		ofstream fout("product",ios::out|ios::binary);
		for(p=s;p!=NULL;p=p->next)
	{
		fout.write((char *)p,sizeof(pp));
	 }
	fout.close();
	clrscr();
	cout<<"pname\tpid\tcat\tgrp\tcname\tqty"<<endl;
	while(fin1.read((char *)&pp,sizeof(pp)))
	{
		 cout<<pp.pname<<"\t"<<pp.pid<<"\t"<<pp.pcat<<"\t"<<pp.pgrp<<"\t"<<pp.cname<<"\t"<<pp.qty<<"\t"<<endl;
	}
	fin1.close();
}


class sales:public product
{
  public:
  void acceptp();
  void acceptc();
  void budget();
  void bill();
};

//this function will accept the customer details to which products are sold
	void sales::acceptc()
  {
	  clrscr();
	  customer uu;
	  char m[20];
	  cout<<"enter the id of the customer to which you want to sale :";
	  cin>>m;
	  u_data *s1=NULL,*p1,*t1,x1;
	  ifstream fin("customer",ios::in|ios::binary);
	  ofstream fout2("bill",ios::out|ios::binary|ios::trunc);
		while(fin.read((char *)&uu,sizeof(uu)))
		{
			p1=new customer;
			*p1=uu;
			p1->next=NULL;
			if(s1==NULL)
			 s1=p1;
			else
			{
			  t1->next=p1;
			}
		  t1=p1;
		}
		for(p1=s1;p1!=NULL;p1=p1->next)
	  {
			 if(strcmpi(p1->uid,m)==0)
			{
				clrscr();
				p1->display2();
				fout2.write((char *)p1,sizeof(uu));
				/* cout<<"id        :"<<p1->vid<<endl;
				cout<<"name      :"<<p1->vname<<endl;
				cout<<"mail      :"<<p1->vmail<<endl;
				cout<<"rating    :"<<p1->rate<<endl;
				cout<<"contact   :"<<p1->vcno<<endl;*/
			  }
	  }
		fout2.close();
		fin.close();
}

//this function will show the list of products in the budget of the customer
	void sales::budget()
	{
		 clrscr();
		 char m[20];
		 int pr,f=0;
		 product pp;
		 cout<<"enter the name of the product you want to sale :";
		 cin>>m;
		 cout<<"enter the budget of the customer :";
		 cin>>pr;
		 ifstream fin("product",ios::in|ios::binary);
		 while(fin.read((char*)&pp,sizeof(pp)))
		 {
			 if(strcmpi(pp.pname,m)==0)
			 {
				 if(pp.price-pr>=0 && (pp.price-pr)<=(10*pp.price)/100 || pr-pp.price>=0 && (pr-pp.price)<=(10*pp.price)/100)
				 {
					 f=1;
					 cout<<"name--->"<<pp.pname<<endl;
					 cout<<"id----->"<<pp.pid<<endl;
					 cout<<"price-->"<<pp.price<<endl;
					 cout<<"qty---->"<<pp.qty<<endl;
					 cout<<"actual price-->"<<pp.price<<endl;
					 cout<<"dom---->"<<pp.d1<<"/"<<pp.m1<<"/"<<pp.y1<<endl;
					 cout<<"doe---->"<<pp.d2<<"/"<<pp.m2<<"/"<<pp.y2<<endl;
					 cout<<"**********"<<endl;
				  }
			  }
		  }
		  if(f==0)
		  cout<<"please increase your budget ";
	}

//this function will accept and show the details of the product which are to be sold

	void sales::acceptp()
 {
		clrscr();
		product pp;
		sales ss;
		char q[20];
		p_data *s=NULL,*p,*t;
		ifstream fin("product",ios::in|ios::binary);
		while(fin.read((char *)&pp,sizeof(pp)))
		 {
				p=new product;
				*p=pp;
				p->next=NULL;
				if(s==NULL)
				 s=p;
				else
				{
					t->next=p;
				}
			  t=p;
		  }
		fin.close();
		struct date d;
		getdate(&d);
		pp.d3=d.da_day;
		pp.m3=d.da_mon;
		pp.y3=d.da_year;
		ofstream fout2("bill",ios::in|ios::binary|ios::trunc);
		char ch='y';
		while(ch=='y')
		{
			clrscr();
			cout<<"enter the id of the product  you want to sale :";
			cin>>q;
			for(p=s;p!=NULL;p=p->next)
			 {
				if(strcmpi(p->pid,q)==0)
				 {
					clrscr();
					cout<<"id           :"<<p->pid<<endl;
					cout<<"name         :"<<p->pname<<endl;
					cout<<"qty          :"<<p->qty<<endl ;
					cout<<"sales date   :"<<pp.d3<<"/"<<pp.m3<<"/"<<pp.y3<<endl;
					cout<<"enter the quantity you want to purchase :";
					cin>>p->qty1;
					p->qty-=p->qty1;
					fout2.write((char *)p,sizeof(pp));
				 }
			}
			cout<<"do you wish to sale more...[y/n]";
			cin>>ch;
		}
		fout2.close();
		clrscr();
		ifstream fin1("product",ios::in|ios::binary);
		ofstream fout("product",ios::out|ios::binary);
		for(p=s;p!=NULL;p=p->next)
	 {
		fout.write((char *)p,sizeof(pp));
	 }
	  fout.close();
	  clrscr();
	  cout<<"pname\tpid\tcat\tgrp\tcname\tqty"<<endl;
	  while(fin1.read((char *)&pp,sizeof(pp)))
	  {
		  cout<<pp.pname<<"\t"<<pp.pid<<"\t"<<pp.pcat<<"\t"<<pp.pgrp<<"\t"<<pp.cname<<"\t"<<pp.qty<<"\t"<<endl;
		}
	fin1.close();
	cout<<"press any key to get the bill";
	cin>>q;
	ss.bill();
}

  void sales::bill()
  {
		 clrscr();
		 int total=0;
		 product pp;
		 struct date d;
		 getdate(&d);
		 pp.d3=d.da_day;
		 pp.m3=d.da_mon;
		 pp.y3=d.da_year;
		 gotoxy(30,7);
	  {
		 cout<<"sales date :->"<<pp.d3<<"/"<<pp.m3<<"/"<<pp.y3<<endl;
	  }
		 gotoxy(30,9);
		 int i=11,sum;
		 cout<<"name\tqty\tprice\tsum"<<endl;
		 ifstream fin("bill",ios::in|ios::binary);
		 while(fin.read((char *)&pp,sizeof(pp)))
	 {
		 gotoxy(30,i);
		 sum=pp.qty1*pp.price;
		 cout<<pp.pname<<"\t\t"<<pp.qty1<<"\t"<<pp.price<<"\t"<<sum<<endl;
		 total+=sum;
		 i++;
	  }
	  gotoxy(30,i+2);
	  cout<<"total--------------------->"<<total;
	  gotoxy(30,i+4);
	  char ch=2;
	  cout<<"THANK YOU FOR SHOPPING"<<" "<<ch;
	  fin.close();
  }

 class menu
{
	 public:
	 void show_menu();
	 void pmenu();
	 void vmenu();
	 void cmenu();
	 void rmenu();
	 void smenu();
	 void current_stock();
};
void menu::show_menu()
{
  clrscr();
  char q;
  menu m;
  while(1)
  {
	 clrscr();
	 struct date d;
	 getdate(&d);
	 gotoxy(3,3);
	 printf("date:%d/%d/%d",d.da_day,d.da_mon,d.da_year);
	 gotoxy(3,4);
	 struct  time t;
	 gettime(&t);
	 printf("time: %2d:%02d:%02d\n", t.ti_hour, t.ti_min, t.ti_sec);
	 gotoxy(28,10);
	 cout<<"STOCK MANAGEMENT SOFTWARE	";
	 gotoxy(28,11);	 cout<<"a.product";
	 gotoxy(28,12);	 cout<<"b.vendor";
	 gotoxy(28,13);	 cout<<"c.customer";
	 gotoxy(28,14);	 cout<<"d.purchase";
	 gotoxy(28,15);	 cout<<"e.sales";
	 gotoxy(28,16);	 cout<<"f.current stock";
	 gotoxy(28,17);    cout<<"z.exit";
	 gotoxy(28,19);
	 fflush(stdin);
	 cout<<"enter your choice :";
	 cin>>q;
	 if(q=='a')
	 {
		clrscr();
		m.pmenu();
		getch();
	 }
	 else if(q=='b')
	 {
		clrscr();
		m.vmenu();
		getch();
	 }
	 else if(q=='c')
	 {
		 clrscr();
		 m.cmenu();
		 getch();
	 }
	 else if(q=='d')
	 {
		 clrscr();
		 m.rmenu();
		 getch();
	 }
	 else if(q=='e')
	 {
		 clrscr();
		 m.smenu();
		 getch();
	  }
	else if(q=='f')
	{
	  clrscr();
	  m.current_stock();
	  getch();
	}
	 else if(q=='z')
	 {
		exit(0);
		getch();
	  }
	}
}
void menu::current_stock()
{
	  clrscr();
	  product pp;
	  p_data *p;
	  ifstream fin("product",ios::in|ios::binary);
	  cout<<"pid\tpname\tcat\tgrp\tqty"<<endl;
	  while(fin.read((char *)&pp,sizeof(pp)))
	  {
		 cout<<pp.pid<<"\t"<<pp.pname<<"\t"<<pp.pcat<<"\t"<<pp.pgrp<<"\t"<<pp.qty<<endl;
	  }
 }

void menu::rmenu()
{clrscr();
 purchase rr;
 char c;
 while(1)
 {
	clrscr();
	gotoxy(27,8);      cout<<"stock management project ";
	gotoxy(27,11);     cout<<"a.vendor details";
	gotoxy(27,12);     cout<<"b.product details";
	gotoxy(27,13);     cout<<"c.show";
	gotoxy(27,14);     cout<<"z.exit";
	fflush(stdin);
	gotoxy(27,15);
	cout<<"enter your choice :";
	cin>>c;
	if(c=='a')
	{
		clrscr();
		rr.acceptv();
		getch();
	 }
	else if(c=='b')
	{
		clrscr();
		rr.acceptp();
		getch();
	 }
	 else if(c=='c')
	 {
		// rr.show();
		 getch();
	 }
	else if(c=='z')
	return;
 }
}
void menu::smenu()
{
  clrscr();
  sales ss;
  char c;
  while(1)
  {
	  clrscr();
	  gotoxy(27,8);      cout<<"stock management project ";
	  gotoxy(27,11);     cout<<"a.customer details";
	  gotoxy(27,12);     cout<<"b.product details";
	  gotoxy(27,13);     cout<<"c.budget";
	  gotoxy(27,14);     cout<<"z.exit";
	  fflush(stdin);
	  gotoxy(27,15);
	  cout<<"enter your choice :";
	  cin>>c;
	  if(c=='a')
	  {
		 clrscr();
		 ss.acceptc();
		 getch();
	  }
	  else if(c=='b')
	  {
		  clrscr();
		  ss.acceptp();
		  getch();
	  }
	  else if(c=='c')
	  {
		  clrscr();
		  ss.budget();
		  getch();
		}
	  else if(c=='z')
	  return;
  }
}


void menu::cmenu()
{  clrscr();
	char c,b,s[10],m[10];
	customer uu;
	int pos;
	while(1)
	{
		clrscr();
		gotoxy(27,8);	  cprintf("stock management software");
		gotoxy(27,11);   cout<<"a.add";
		gotoxy(27,12);   cout<<"b.display";
		gotoxy(27,13);   cout<<"c.search";
		gotoxy(27,14);   cout<<"d.modify";
		gotoxy(27,15);   cout<<"e.delete";
		gotoxy(27,16);   cout<<"f.insert";
		gotoxy(27,17);   cout<<"g.sort";
		gotoxy(27,18);   cout<<"h.details of the costumer";
		gotoxy(27,19);   cout<<"i.save";
		gotoxy(27,20);   cout<<"j.load";
		gotoxy(27,21);   cout<<"z.quit";
		gotoxy(27,22);   cout<<"enter your choice ";
		fflush(stdin);
		cin>>c;
		if(c=='a')
		uu.accept();
		else if(c=='b')
		{
			clrscr();
			uu.display();
			getch();
		}
		else if(c=='c')
		{
			clrscr();
			cout<<"enter the id of the product to be searched :";
			cin>>s;
			uu.search(s);
			getch();
		}
		else if(c=='d')
		{
		  clrscr();
		  cout<<"enter the id of the product to be modified :";
		  cin>>m;
		  uu.mod(m);
		  getch();
		}
		else if(c=='e')
		{
			clrscr();
			char m[10];
			cout<<"enter the id of the product to be deleted :";
			cin>>m;
			uu.del(m);
			getch();
		 }
		else if(c=='f')
		{
			clrscr();
			cout<<"enter the position into which data to be inserted :";
			cin>>pos;
			uu.insert(pos);
			getch();
		}
		else if(c=='g')
		{
			clrscr();
			uu.sort_menu3();
			getch();
		 }
		 else if(c=='h')
		 {clrscr();
		  uu.show_record();
		  getch();
		 }
	  else if(c=='i')
		{
			clrscr();
			uu.save();
			getch();
		 }
		 else if(c=='j')
		{
			clrscr();
			uu.load();
			getch();
		 }

		else if(c=='z')
	  {
		 return;
	  }
	}
}

void menu::vmenu()
{  clrscr();
	char c,b,s[10],m[10];
	vendor vv;
	int pos;
	while(1)
	{
		clrscr();
		gotoxy(27,8);	  cprintf("stock management project");
		gotoxy(27,11);   cout<<"a.add";
		gotoxy(27,12);   cout<<"b.display";
		gotoxy(27,13);   cout<<"c.search";
		gotoxy(27,14);   cout<<"d.modify";
		gotoxy(27,15);   cout<<"e.delete";
		gotoxy(27,16);   cout<<"f.insert";
		gotoxy(27,17);   cout<<"g.sort";
		gotoxy(27,18);   cout<<"h.details of the vendor";
		gotoxy(27,19);   cout<<"i.save";
		gotoxy(27,20);   cout<<"j.load";
		gotoxy(27,21);   cout<<"z.quit";
		gotoxy(27,22);   cout<<"enter your choice ";
		fflush(stdin);
		cin>>c;
		if(c=='a')
		vv.accept();
		else if(c=='b')
		{
			clrscr();
			vv.display();
			getch();
		}
		else if(c=='c')
		{
			clrscr();
			cout<<"enter the id of the product to be searched :";
			cin>>s;
			vv.search(s);
			getch();
		}
		else if(c=='d')
		{
		  clrscr();
		  cout<<"enter the id of the product to be modified :";
		  cin>>m;
		  vv.mod(m);
		  getch();
		}
		else if(c=='e')
		{
			clrscr();
			char m[10];
			cout<<"enter the id of the product to be deleted :";
			cin>>m;
			vv.del(m);
			getch();
		 }
		else if(c=='f')
		{
			 clrscr();
			 cout<<"enter the position into which data to be inserted :";
			 cin>>pos;
			 vv.insert(pos);
			 getch();
		}
		else if(c=='g')
		{
			 clrscr();
			 vv.sort_menu2();
			 getch();
		 }
		 else if(c=='h')
		 {
			 clrscr();
			 vv.show_record();
			 getch();
		 }
	  else if(c=='i')
		{
			 clrscr();
			 vv.save();
			 getch();
		 }
		else if(c=='j')
		{
			clrscr();
			vv.load();
			getch();
		}
		else if(c=='z')
		{
			return;
		}
	}
}

void menu::pmenu()
{  clrscr();
	char c,b,s[10],m[10];
	product pp;
	int pos;
	while(1)
	{
		clrscr();
		gotoxy(27,8);	  cprintf("stock management software");
		gotoxy(27,11);   cout<<"a.add";
		gotoxy(27,12);   cout<<"b.display";
		gotoxy(27,13);   cout<<"c.search";
		gotoxy(27,14);   cout<<"d.modify";
		gotoxy(27,15);   cout<<"e.delete";
		gotoxy(27,16);   cout<<"f.insert";
		gotoxy(27,17);   cout<<"g.sort";
		gotoxy(27,18);   cout<<"h.show";
		gotoxy(27,19);   cout<<"i.save";
		gotoxy(27,20);   cout<<"j.current";
		gotoxy(27,21);   cout<<"k.graph";
		gotoxy(27,22);   cout<<"z.quit";
		gotoxy(27,23);   cout<<"enter your choice ";
		fflush(stdin);
		cin>>c;
		if(c=='a')
		pp.accept();
		else if(c=='b')
		{
			clrscr();
			pp.display();
			getch();
		}
		else if(c=='c')
		{
			cout<<"enter the id of the product to be searched :";
			cin>>s;
			pp.search(s);
		}
		else if(c=='d')
		{
		  clrscr();
		  cout<<"enter the id of the product to be modified :";
		  cin>>m;
		  pp.mod(m);
		  getch();
		}
		else if(c=='e')
		{
			clrscr();
			char m[10];
			cout<<"enter the id of the product to be deleted :";
			cin>>m;
			pp.del(m);
			getch();
		 }
		else if(c=='f')
		{
			clrscr();
			cout<<"enter the position into which data to be inserted :";
			cin>>pos;
			pp.insert(pos);
			getch();
		}
		else if(c=='g')
		{
			clrscr();
			pp.sort_menu();
			getch();
		 }
		 else if(c=='h')
		 {clrscr();
		  pp.show_record();
		  getch();
		}
	  else if(c=='i')
		{
			clrscr();
			pp.save();
			getch();
		 }
		else if(c=='k')
		{
		  clrscr();
		  pp.graph();
		  getch();
		}
		else if(c=='z')
	  {
		  return;
		}
	}
}

  void main()
  {
		clrscr();
		menu m;
		m.show_menu();
		getch();
	}
