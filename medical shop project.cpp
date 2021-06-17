#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<windows.h>
using namespace std;
class fun
{
	int lap_id;
	char laptop_name[30];
	float price;
	char date;
	public:
		void getdata()
		{
			cout<<"enter laptop id"<<endl;
			cin>>lap_id;
			cout<<"enter laptop brand name"<<endl;
			cin>>laptop_name;
			cout<<"enter the price for laptoprepair"<<endl;
			cin>>price;
			cout<<"enter the last date when you need back"<<endl;
			cin>>date;	
		}	
		void putdata()
		{
			cout<<"laptop id"<<setw(20)<<"laptop brand name"<<setw(20)<<"price"<<setw(20)<<"last date"<<endl;
			cout<<lap_id<<setw(20)<<laptop_name<<setw(30)<<price<<setw(20)<<date<<setw(20)<<endl;
		}
		void add_data();
		void view_data();
		void search_data();
		void delete_data();
		void update_data();
		void choice();
		void menu()
		{
			cout<<"press 1 to add new data"<<endl;
			cout<<"press 2 to view all the data"<<endl; 
			cout<<"press 3 to search the data"<<endl;
			cout<<"press 4 to delete the data"<<endl;
			cout<<"press 5 to update the data"<<endl;
		}
	int laptop_id()
	{
		return lap_id;
	}
};
fun m;
fstream f;
fstream f1;
/*------------------------------------view data in file------------------------------------------*/
void fun::view_data()
{
    system("cls");	
	ifstream fin("project.txt",ios::binary);
	while(fin.read((char*)&m,sizeof(m)))
	{
		m.putdata();
	}
	fin.close();
	getch();
	choice(); 
	
}
/*------------------------add data in file------------------------------*/
void fun::add_data()
{
	system("cls");
	char opt1='y';
	f.open("project.txt",ios::out|ios::app|ios::binary);
	while(opt1=='y'||opt1=='Y')
	{
		m.getdata();
		f.write((char*)&m,sizeof(m));
		cout<<"enter the option to add more data"<<endl;
		fflush(stdin);
		cin>>opt1;
	}
	f.close();
	getch();
	choice();
}
/*---------------------------search data in file----------------------------------*/
void fun::search_data()
{
	system("cls");
	fstream f("project.txt",ios::binary|ios::in);
	int me_id, found=0;
	cout<<"enter the id"<<endl;
	cin>>me_id;
		while(f.read((char*)&m,sizeof(m)))
		{
			if(m.lap_id==me_id)
			{
				m.putdata();
				found=1;
			}
		}
	if(found==0)
		{
			
			cout<<"enterd id could not searched"<<endl;
		}
	f.close();
	getch();
	choice();
}
/*---------------------------delete data in file-----------------------------*/
void fun::delete_data()
{
	system("cls");
	f.open("project.txt",ios::in|ios::binary);
	f1.open("project1.txt",ios::out|ios::binary);
	char opt3='y';
	int mee_id;
	cout<<"enter the laptoprepair id to be deleted"<<endl;
	cin>>mee_id;
		while(f.read((char*)&m,sizeof(m)))
		{
			if(m.lap_id!=mee_id)
			{
				f1.write((char*)&m,sizeof(m));
				m.putdata();
			}
		}
	f.close();
	f1.close();
	remove("project.txt");
	rename("project1.txt","project.txt");
	f1.open("project1.txt",ios::in|ios::binary);
	f1.close();
	getch();
	choice();
}
/*******************************data to update***************************************/
void fun::update_data()
{
	system("cls");
	int pos,found;
	int met_id;
	cout<<"enter the laptoprepair id to be updated"<<endl;
	cin>>met_id;
	f.open("project.txt",ios::in|ios::out|ios::binary);
	while(f.read((char*)&m,sizeof(m)))
	{
		if(m.lap_id==met_id)
	{
		pos=f.tellg()- sizeof(m);
		f.seekp(pos,ios::beg);
		m.getdata();
		f.write((char*)&m,sizeof(m));
		found=1;
		break;
	}
	}
	if(found==1)
	{
		cout<<"record is updated"<<endl;
	}
	else
	{
		cout<<"record is not updated"<<endl;
	}
	f.close();
	choice();
	getch();
}
/***************************function for choice**********************************/
void fun::choice()
{
	system("cls");
	menu();
	int choice;
	cout<<"enter the choice\n";
	cin>>choice;
	switch(choice)
	{
		case 1:{
				cout<<"enter data to add"<<endl;
				m.add_data();
		}
		break;
		case 2:{
				cout<<"view data"<<endl;
				m.view_data();
		}	
		break;
		case 3:{
				cout<<"enter data to searched"<<endl;
				m.search_data();
		}
		break;
		case 4:{
			cout<<"enter data to delete"<<endl;
			m.delete_data();
		}
		break;
		case 5:{
			cout<<"enter the data to update"<<endl;
			m.update_data();
		}
		break;
	}
	f.close();
}
main()
{
   fun m1;
   m1.choice();
}
