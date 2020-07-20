//deletestudent   //deletebook
#include<bits/stdc++.h>
using namespace std;

class Book
{
	char book_number[6];
	char book_name[50];
	char book_author[20];
	public:
		void createBook()
		{
			cout<<"\n\n\n\t\t\t\t\t\tNEW BOOK ENTRY !!";
			cout<<"\n\n\n\tEnter Book Number  ";
			cin>>book_number;
			cout<<"\n\n\n\tEnter Book Name    ";
			cin>>book_name;
			cout<<"\n\n\n\tEnter the Author's Name      ";
			cin>>book_author;
				cout<<"\n\n\n\t\t\t\t\t\tENTRY FEEDED SUCCESSFULY !!\n\n\n";
		}
		
		void showbook()
		{
			cout<<"\n\n\n\t\t\t\t\t\tBOOK DETAILS !!";
			cout<<"\n\n\n\tBook Number :- ";
			puts(book_number);
			cout<<"\n\n\n\tBook Name :- ";
			puts(book_name);
			cout<<"\n\n\n\tAuthor's Name :- ";
			puts(book_author);
			
			cout<<"\n\n\n\t\t\t\t\t\tENTRY SHOWN SUCCESSFULY !!\n\n\n";
		}
		
		
		void modifyBook()
		{
			cout<<"Modifying details for Book Number:- "<<book_number<<endl;
			cout<<"Enter the new Book Name\n";
			cin>>book_name;
			cout<<"Enter the new Author's Name\n";
			cin>>book_author;
		}
		
		char* retbno()
		{
			return book_number;
			// char retbno-> returns single character
			// char* retbno-> returns array of string
		}
		
		void report()
		{
			cout<<book_number<<setw(30)<<book_name<<setw(30)<<book_author<<endl;
		}
};




class student
{
	char admno[6];
	char name[20];
	char stdbno[6];// student book number
	int token;  //total no of books issued by a student
	public:
		
		void createstudent()
		{
			system("CLS");
			cout<<"\n\n\n\t\t\t\t\t\tNEW STUDENT ENTRY !!";
			cout<<"\n\n\n\tEnter Admission Number";
			cin>>admno;
			cout<<"\n\n\n\tEnter Studnet's Name";
			cin>>name;
			token=0;
			stdbno[0]='\0';
			cout<<"\n\n\n\t\t\t\t\t\tENTRY FEEDED SUCCESSFULY !!\n\n\n";
		}
		
		void showstudent()
		{
			cout<<"\n\n\n\t\t\t\t\t\tSTUDENT DETAILS !!";
			cout<<"\n\n\n\tStudent's Admission number' :- ";
			puts(admno);
			cout<<"\n\n\n\tStudnet's' Name :- ";
			puts(name);
			cout<<"\n\n\n\tNo of Books Issued :- "<<token;
			if(token==1)
			{
				cout<<"\nBook Number:- "<<stdbno;
			}
			
			cout<<"\n\n\n\t\t\t\t\t\tENTRY SHOWN SUCCESSFULY !!\n\n\n";	
		}
		
		
		void modifystudent()
		{
			cout<<"Modifying details for Admission Number:- "<<admno<<endl;
			cout<<"Enter the new Students Name\n";
			cin>>name;

		}
		
		char* retadmno()
		{
			return admno;
		}
		
		char* retstdbno()
		{
			return stdbno;
		}
		
		int rettoken()
		{
			return token;
		}
		
		void addtoken()
		{
			token=1;
		}
		
		void restetoken()
		{
			token=0;
		}
		
		void getstdbno(char t[])
		{
			strcpy(stdbno,t); 
		}
		void report()
		{
			cout<<"\t"<<admno<<setw(30)<<name<<setw(10)<<token<<endl;
			
		}
		
	
	
};

fstream fp,fp1;
Book bk;
student st;

void writebook()
{
	char ch;
	fp.open("book.dat",ios::out|ios::app);//i/o specification->write+append
	do
	{
		system("CLS");
		bk.createBook();
		fp.write((char*)&bk,sizeof(Book));//write obj of book class
		cout<<"\n\nDo You Want to Add More Record....(y/n)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
		cout<<"\n\nPress 1 to go back ";
	int x;
	cin>>x;
	if(x==1)
	return;
}

void writestudent()
{
	char ch;
	fp.open("student.dat",ios::out|ios::app);//i/o specification->write+append
	do
	{
		system("CLS");
		st.createstudent();
		fp.write((char*)&st,sizeof(student));//write obj of book class
		cout<<"\n\nDo You Want to Add More Record....(y/n)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
		cout<<"\n\nPress 1 to go back ";
	int x;
	cin>>x;
	if(x==1)
	return;
}

void DisplaySpeceficBook() //book no
{
	char n[6];
	cout<<"\n\n\tEnter Book Number\n";
	cin>>n;
	cout<<"\nBook Details Are As:- \n";
	int flag=0;
	fp.open("book.dat",ios::in); //read type
	while(fp.read((char *)&bk,sizeof(Book)))
	{
		if(strcmpi(bk.retbno(),n)==0) //function is not case sensitive...strcmp is case sensitive
		{
			bk.showbook();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	{
		cout<<"\n Such Book is Not Available\n";
	}
		cout<<"\n\nPress 1 to go back ";
	int x;
	cin>>x;
	if(x==1)
	return;
}

void displayspeceficStudent()
{
	char n[6];
	cout<<"\n\n\tEnter Student Admission Number\n";
	cin>>n;
	cout<<"\nStudent Details Are As:- \n";
	int flag=0;
	fp.open("student.dat",ios::in); //read type
	while(fp.read((char *)&st,sizeof(student)))
	{
		if(strcmpi(st.retadmno(),n)==0) //function is not case sensitive...strcmp is case sensitive
		{
			st.showstudent();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
	{
		cout<<"\n Such Student is Not Available\n";
	}
		cout<<"\n\nPress 1 to go back ";
	int x;
	cin>>x;
	if(x==1)
	return;
} 

void modifybook()
{
	char n[6];
	int found=0;
	system("CLS");
	cout<<"\nMODIFY BOOK RECORD ";
	cout<<"\n\n Enter The Book Number";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&bk,sizeof(Book)) && found==0)//there should be data in the file AND should be present in the file
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.showbook();//displays the data of the required book
			cout<<endl;
			cout<<"Enter The New Details of Boook \n";
			bk.modifyBook();
			//now we need to rewrite it
			//now pointer will point to the next entry henc we need to come back to the starting 
			int pos=(-1*sizeof(bk)); // to shift back to the data read
			fp.seekp(pos,ios::cur); //gets back from current to the given position
			fp.write((char*)&bk,sizeof(Book));
			cout<<" \n\n\tRecord Updated !!!";
			found=1;
		}
		fp.close();
		if(found==0)
		{
			cout<<"\n\n Record Not found !!!\n";
		}
			
	}
		cout<<"\n\nPress 1 to go back ";
	int x;
	cin>>x;
	if(x==1)
	return;
	
}



void modifyStudent()
{
	char n[6];
	int found=0;
	system("CLS");
	cout<<"\nMODIFY STUDENT RECORD ";
	cout<<"\n\n Enter The Admission Number";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)) && found==0)//there should be data in the file AND should be present in the file
	{
		if(strcmpi(st.retadmno(),n)==0)
		{
			st.showstudent();//displays the data of the required book
			cout<<endl;
			cout<<"Enter The New Details of Student ";
			st.modifystudent();
			//now we need to rewrite it
			//now pointer will point to the next entry henc we need to come back to the starting 
			int pos=-1*sizeof(st); // to shift back to the data read
			fp.seekp(pos,ios::cur); //gets back from current to the given position
			fp.write((char*)&st,sizeof(student));
			cout<<" \n\n\tRecord Updated !!!";
			found=1;
		}
		fp.close();
		if(found==0)
		{
			cout<<"\n\n Record Not found !!!\n";
		}
			
	}
		cout<<"\n\nPress 1 to go back ";
	int x;
	cin>>x;
	if(x==1)
	return;
	
}


void DeleteStudent()
{
	char n[6];
	int flag=0;
	system("CLS");
	cout<<"\n\n\nDELETE STUDENT";
	cout<<"\n\nEnter the Admission Number:- ";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	fstream fp2; //local to this function
	fp2.open("temp.dat",ios::out);
	fp.seekg(0,ios::beg); //from its current position it should move to 0 ie starting 
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(st.retadmno(),n!=0) //student not found
		{
			fp2.write((char*)&st,sizeof(student));
		}
		else   //student found
		{
			flag=1;
		}
	}
	fp2.close();
	fp.close(); 
	//req data is written in temp file
	remove("student.dat"); //file deleted
	rename("temp.dat","student.dat");// file renamed
	if(flag==1)
	{
		cout<<"\n\n\tRecord Deleted Successfuly !!";
	}
	else
	{
		cout<<"\n\n\tRecord not found !!";
	}
		cout<<"\n\nPress 1 to go back ";
	int x;
	cin>>x;
	if(x==1)
	return;
}


void deleteBook()
{
	char n[6];
	int flag=0;
	system("CLS");
	cout<<"\n\n\nDELETE BOOK";
	cout<<"\n\nEnter the Book Number Number:- ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2; //local to this function
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg); //from its current position it should move to 0 ie starting 
	while(fp.read((char*)&bk,sizeof(Book)))
	{
		if(bk.retbno(),n!=0) //student not found
		{
			fp2.write((char*)&bk,sizeof(Book));
		}
		else   //student found
		{
			flag=1;
		}
	}
	fp2.close();
	fp.close(); 
	//req data is written in temp file
	remove("book.dat"); //file deleted
	rename("temp.dat","book.dat");// file renamed
	if(flag==1)
	{
		cout<<"\n\n\tRecord Deleted Successfuly !!";
	}
	else
	{
		cout<<"\n\n\tRecord not found !!";
	}
		cout<<"\n\nPress 1 to go back ";
	int x;
	cin>>x;
	if(x==1)
	return;
}


void displayAllStudent()
{
	system("CLS");
	fp.open("student.dat",ios::in);
	if(!fp) //file not present
	{
		cout<<"\n\n\tFile Couldn't be Opened !!";
		cout<<"\n\n\tPress 1 to go back";
		int n;
		cin>>n;
		if(n==1)
			return;
		
	}
	cout<<"\n\n\tStudents Record:- ";
	cout<<"\n\n";
	cout<<"\tAdmission No. "<<setw(20)<<"Name "<<setw(15)<<"Book issued\n";
	cout<<"==========================================================================================================\n";
	while(fp.read((char*)&st,sizeof(student)))
	{
		st.report();
	}
	fp.close();
	cout<<"\n\nPress 1 to go back ";
	int x;
	cin>>x;
	if(x==1)
	return;
}

void displayAllBooks()
{
	system("CLS");
	fp.open("book.dat",ios::in);
	if(!fp)
	{
		cout<<"\n\n\tFile Couldn't be Opened !!";
		cout<<"\n\n\tPress 1 to go back";
		int n;
		cin>>n;
		if(n==1)
			return;
	}
	cout<<"\n\n\tBooks Record:- ";
	cout<<"\n\n";
	cout<<"\tbook Number "<<setw(20)<<" Book Name "<<setw(25)<<"Author's Name\n";
	cout<<"==========================================================================================================\n";
	while(fp.read((char*)&bk,sizeof(Book)))
	{
		bk.report();
	}
	fp.close();
		cout<<"\n\nPress 1 to go back ";
	int x;
	cin>>x;
	if(x==1)
	return;
}


void Issue_Book()
{
	char sn[6],bn[6];//student/book no
	int found=0,flag=0;
      //student  //book
	system("CLS");
	cout<<"\n\n\tBOOK ISSUE...";
	cout<<"\n\n\tEnter You Admission Number ";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student))&&found==0)//find student untill not found
	{
		if(strcmpi(st.retadmno(),sn)==0)
		{
		found=1;
		if(st.rettoken()==0)
		{
			cout<<"\n\tEnter the Book Number";
			cin>>bn;
			while(fp1.read((char*)&bk,sizeof(Book))&&flag==0)
			{
					if(strcmpi(bk.retbno(),bn)==0)
					{
						flag=1;
						st.addtoken();//sets token as 1 as book is issued
						st.getstdbno(bk.retbno()); //copies book number 
						int pos=-1*sizeof(st);
						fp.seekg(pos,ios::cur);
						fp.write((char*)&bk,sizeof(Book));
						cout<<"\n\n\t Book issued Successfuly !!\n\n\t Please Write The Book issue date in backSide of your Book and return within 15 days";
						
						
					}
			}
			if(flag==0)
			{
				cout<<"\n\n\tSuch Book Number Doesn't Exist";
			}
		}
		else
		{
			cout<<"\n\n\tYou Have Not Returned the Last Book";	
		}
		}
		}
		if(found==0)
		{
				cout<<"\n\n\tSuch Admission Number Doesn't Exist";
		}
		fp.close();
		fp1.close();
			cout<<"\n\nPress 1 to go back ";
	int x;
	cin>>x;
	if(x==1)
	return;
		
	}
	
	
void Deposit_Book()
{
	char sn[6],bn[6];//student/book no
	int found=0,flag=0;
	int day,fine;
      //student  //book
	system("CLS");
	cout<<"\n\n\tBOOK DEPOSIT...";
	cout<<"\n\n\tEnter You Admission Number  ";
	cin>>sn;
	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student))&&found==0)//find student untill not found
	{
		if(strcmpi(st.retadmno(),sn)==0)
		{
		found=1;
		if(st.rettoken()==1)
		{
		
			while(fp1.read((char*)&bk,sizeof(Book))&&flag==0)
			{
					if(strcmpi(bk.retbno(),st.retstdbno())==0)
					{
						flag=1;
						bk.showbook();
						cout<<"\n\n\tBook Deposited after days..?\n";
						cin>>day;
						if(day>15)
						{
							fine=(day-15)*1;
							cout<<"\n\n\t Fine to be Paid :- "<<fine<<endl;
						}
						st.restetoken(); //sets token as 0
						int pos=-1*sizeof(st);
						fp.seekg(pos,ios::cur);
						fp.write((char*)&st,sizeof(student));
						cout<<"\n\n\t Book Deposited Successfuly !!";
						
						
					}
			}
			if(flag==0)
			{
				cout<<"\n\n\tSuch Book Number Doesn't Exist";
			}
		}
		else
		{
			cout<<"\n\n\tNo Book is Issued";	
		}
		}
		}
		if(found==0)
		{
				cout<<"\n\n\tSuch Admission Number Doesn't Exist";
		}
		fp.close();
		fp1.close();
			cout<<"\n\nPress 1 to go back ";
	int x;
	cin>>x;
	if(x==1)
	return;
}
	




void start()
{

	cout<<"\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t************************\n";
	cout<<"\t\t\t\t\t\t\tLIBRARY\n";
	cout<<"\t\t\t\t\t\t\tMANAGEMENT\n";
	cout<<"\t\t\t\t\t\t\tSYSTEM\n";
	cout<<"\t\t\t\t\t\t************************\n";
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\tDeveloped By:- Ashish Chaubey";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\tDate:- 17.07.2020";
	cout<<"\n\n\n";cout<<"\n\n\n";cout<<"\n\n\n";
}

void Administrator()
{
		system("CLS");
		int var;
		cout<<"\n\n\n\t\t\t\t\t\tADMINISTRATOR MENU";
		cout<<"\n\n\n\t\t\t\t\t\t1. Create Student Record";
		cout<<"\n\t\t\t\t\t\t2. Display All Student Record";
		cout<<"\n\t\t\t\t\t\t3. Display Specefic Student Record";
		cout<<"\n\t\t\t\t\t\t4. Modify Student Record";
		cout<<"\n\t\t\t\t\t\t5. Delete Student Record";
		cout<<"\n\t\t\t\t\t\t6. Create Book Record";
		cout<<"\n\t\t\t\t\t\t7. Display All Books Record";
		cout<<"\n\t\t\t\t\t\t8. Display Specefic Book Record";
		cout<<"\n\t\t\t\t\t\t9. Modify Book Record";
		cout<<"\n\t\t\t\t\t\t10. Delete Book Record";
		cout<<"\n\t\t\t\t\t\t11. Back To Main Menu\n\n";
		cout<<" Choose Your Option\n";
		cin>>var;
		switch(var)
		{
			case 1:
				writestudent();
				break;
			case 2:
				displayAllStudent();
				break;
			case 3:
				displayspeceficStudent();
				break;
			case 4:
				modifyStudent();
				break;
			case 5:
				DeleteStudent();
				break;
			case 6:
				writebook();
				break;
			case 7:
				displayAllBooks();
				break;
			case 8:
			DisplaySpeceficBook();
				break;
			case 9:
				modifybook();
				break;
			case 10:
				deleteBook();
				break;
			case 11:
				return;
				break;
			default:
				cout<<"Select Your Option Wisely\n";
		}
		Administrator();
		
}
int main()
{
	start();
	char ch;
	char ch1;
	cout<<"\nPRESS 1 TO CONTINUE\n";
	cin>>ch1;
	if (ch1=='1')
	{
	do
	{
		system("CLS");
		cout<<"\n\n\n\t\t\t\t\t\tMAIN MENU";
		cout<<"\n\n\n\t\t\t\t\t\t1. Issue Book";
		cout<<"\n\n\n\t\t\t\t\t\t2. Submit Book";
		cout<<"\n\n\n\t\t\t\t\t\t3. Administrator Menu";
		cout<<"\n\n\n\t\t\t\t\t\t4. Exit\n\n";
		cin>>ch;
		switch(ch)
		{
			case '1':
				Issue_Book();
				break;
			case '2':
				Deposit_Book();
				break;
			case '3':
				Administrator();
				break;
			case '4':
				int i;
				for(i=0;i<=3;i++)
				{
					if(i==0)
					cout<<"\nSending Request !!";
					if(i==1)
					cout<<"\nRequest Approved !!";
					if(i==2)
					cout<<"\nClosing Application !!";
					if(i==3)
					{
						cout<<"\n\t\t\t\t\t\t\t\t\t\tApplication Terminated Successfuly\n";
						exit(0);					}
					
				}
				exit(0);
				break;
			default:
				cout<<"Select Your Option Wisely\n";
		}		
	
	}while(ch!='4');
	}
}
