#include<iostream>
using namespace std;
#include<windows.h>
#include"antheader.h"
#include<string.h>
#include<conio.h>
int i=0,x=0,y=0,w=0,h=0,count=0,k=0;
int c=0;
char ch;
string staff[100][7];
string product[100][7];
string remainder[100][7];
string payment[100][7];
string pay[100][8];
string pass, password,cha1,mail;
FILE *fp_staff;
FILE *fp_staff1;
FILE *fp_product;
FILE *fp_product1;
FILE *fp_payment;
FILE *fp_payment1;
FILE *fp_remainder;
FILE *fp_remainder1;
string mainMenus[]={" Main "," Staff "," Product "," Payment "," About "," Exit "};
void boxbox(int );
void boxbox1(int );
void boxbox2(int );
void boxfunction(int ,int , int ,int );
void boxfunction1(int ,int , int ,int);
void Interface(int );
void stock();

class Staff {
private:
	char id[10],
		name[30],
		gender[7],
		position[30],
		phoneNumber[15],
		validateEmail[30],
		startWork[20],
		dateOfbirth[20],
		placeOfBirth[20],
		nationality[20],
		idCard[20],
		religion[20];
		float age, salary;
		
		public:
			void addStaff();
			void showStaff();
			void editStaff();
			void deleteStaff();
			void searchStaff();	
};
Staff St;
string addStaffLeftLabels[] = {
	" ID      :",
	" Name    :",
	" Gender  :",
	" Age     :",
	" Position:",
	" Phone   :",
	" validateEmail   :"
};

string addStaffRightLabels[] = { 
	" Hire Date    :",
	" Salary       :",
	" Date of Birth:",
	" Place of Birth:",
	" Nationality  :",
	" Identity Card:",
	" Religion     :"
};
					
void showMenu(int col)
{
	for(int i=3;i<(22+col);i++)
	{
		gotoxy(13,i);foreColor(0);cout<<"                                 ";
		gotoxy(45,i);foreColor(0);cout<<"                                 ";
	}
	gotoxy(16,4);foreColor(2);cout<<"ID";
	gotoxy(25,4);foreColor(2);cout<<"Name";
	gotoxy(38,4);foreColor(2);cout<<"Gender";
	gotoxy(47,4);foreColor(2);cout<<"Age";
	gotoxy(55,4);foreColor(2);cout<<"Position";
	gotoxy(70,4);foreColor(2);cout<<"Phone";
}

void staffMenus()
{
	gotoxy(30,4);foreColor(180);cout<<"    Staff Information    ";
	for(int i=0;i<7;i++)
	{
		gotoxy(14,6+i*2);foreColor(180);cout<<addStaffLeftLabels[i];
		gotoxy(24,6+i*2);foreColor(150);cout<<"                  ";
		gotoxy(44,6+i*2);foreColor(180);cout<<addStaffRightLabels[i];
		gotoxy(59,6+i*2);foreColor(150);cout<<"                  ";
	}
}
class Product {
public: 
	char id[10],
		name[30],
		date[15],
		User[12],
		Pass[12];
	float total, quantity, unitPrice, productOf;
};
Product Pro;
Product Create;
	void addProduct();
	void showProduct();
	void editProduct();
	void deleteProduct();
	void searchProduct();
	void showRemainderProduct();
	void createAccount();

string Put[] = {
	" Pro_ID  :",
	" Pro_Name:",
	" Quantity:",
	" Price($):",
	" Date    :",
	" Product :",
	" Total   :",
};
void productMenus(int col)
{
	for(int i=3;i<22+col;i++)
	{
		gotoxy(13,i);foreColor(0);cout<<"                                 ";
		gotoxy(45,i);foreColor(0);cout<<"                                 ";
	}
	gotoxy(16,4);foreColor(2);cout<<"ID";
	gotoxy(22,4);foreColor(2);cout<<"Pro_Name";
	gotoxy(34,4);foreColor(2);cout<<"Count";
	gotoxy(40,4);foreColor(2);cout<<"Price";
	gotoxy(50,4);foreColor(2);cout<<"Date";	
	gotoxy(59,4);foreColor(2);cout<<"Product";
	gotoxy(70,4);foreColor(2);cout<<"Total";
}	
void productHeader()
{
	gotoxy(29,4);foreColor(180);cout<<"     Product Information    ";
	for(int i=0;i<7;i++)
	{
		gotoxy(29,6+i*2);foreColor(180);cout<<Put[i];
		gotoxy(39,6+i*2);foreColor(150);cout<<"                  ";
	}
}//product information
class Payment{
private:
	char Ex_customer[30],
		 Ex_phone[15],
		 Ex_date[15],
		 Ex_Proid[10],
		 Ex_product[15];
	float Ex_qty,Ex_price,Ex_discount,Ex_amount,AmountTotal,Ex_product_of;
	public:
		void saleProduct();
		void showExport();
		void deleteExport();
		void searchExport();
};
Payment Pay;

string saleLeftLabels[] = { 
	" Cus_Name  :",
	" Telephone :",
	" Date      :",
	" Product ID:",
	" Pro_Name  :",
	" Product of:"
};
string saleRightLabels[] = {
	" Quantity   :",
	" Price($)   :",
	" Discount %?:",
	" Amount     :",
	" Amount dis :",
	" Your bill is : "
};
void paymentMenus(int col){
	
	for(int i=3;i<22+col;i++)
	{
		gotoxy(13,i);foreColor(0);cout<<"                                 ";
		gotoxy(45,i);foreColor(0);cout<<"                                 ";
	}
	gotoxy(16,4);foreColor(2);cout<<"Customer";
	gotoxy(29,4);foreColor(2);cout<<"Product";
	gotoxy(39,4);foreColor(2);cout<<"Dis%";
	gotoxy(44,4);foreColor(2);cout<<"Count";
	gotoxy(50,4);foreColor(2);cout<<"Price";
	gotoxy(60,4);foreColor(2);cout<<"Date";	
	gotoxy(71,4);foreColor(2);cout<<"Amount";
}		
void saleMenus()
{
	gotoxy(29,4);foreColor(180);cout<<"     Export Information    ";
	for(int i=0;i<6;i++)
	{
		gotoxy(14,6+i*2);foreColor(180);cout<<saleLeftLabels[i];
		gotoxy(26,6+i*2);foreColor(150);cout<<"                ";
		gotoxy(45,6+i*2);foreColor(180);cout<<saleRightLabels[i];
		gotoxy(58,6+i*2);foreColor(150);cout<<"                 ";
	}
}
void bang()
{
	for(int i=0;i<54;i++)
	{
		gotoxy(17+i,18);foreColor(130);cout<<(char)0;
		gotoxy(17+i,20);foreColor(130);cout<<(char)0;
	}
}//payment information
void validateNumbers(int x,int y)
{
	int ix,n=0;
	ix=x;
	int k=pass.length();
	pass.erase(pass.length()-k,k);
	gotoxy(x,y);
	char ch=getch();
	while(ch !=13)
	{		
		if(ch>='0' && ch<='9'||ch=='/'||ch==32)
		{
			ix++;
			cout<<ch;
			pass+=ch;			
		}
		r1:				
		ch=getch();		
		if(ch==8)
		{	
			ix--;				
			gotoxy(ix, y);cout<<" \b";
			if(ix==x)
			{			
				gotoxy(ix, y);
				ix=x+1;
				n=1;				
				goto r1;
			}
			pass.erase(pass.length()-1,1);
			goto r1;
		}		
		else if(ch !=8 && n==1)	
		{			
			n=0;
			pass ="";
		}	
	}
}//validateNumbers
void validateCharacters(int x,int y)
{
	int ix,n=0;
	ix=x;
	int k=cha1.length();
	cha1.erase(cha1.length()-k,k);
	gotoxy(x,y);
	char ch=getch();
	while(ch !=13)
	{			
		if(ch>='a' && ch<='z'||ch>='A' && ch<='Z'||ch==32)
		{
			ix++;
			cout<<ch;
			cha1+=ch;
		}
		r1:				
		ch=getch();		
		if(ch==8)
		{	
			ix--;				
			gotoxy(ix, y);cout<<" \b";
			if(ix==x)
			{			
				gotoxy(ix, y);
				ix=x+1;
				n=1;				
				goto r1;
			}
			cha1.erase(cha1.length()-1,1);
			goto r1;
		}		
		else if(ch !=8 && n==1)	
		{			
			n=0;
			cha1 ="";
		}	
	}
}//validateCharacters
void validateEmail(int x,int y)
{
	int ix,n=0;
	ix=x;
	int k=mail.length();
	mail.erase(mail.length()-k,k);
	gotoxy(x,y);
	char ch=getch();
	while(ch !=13)
	{			
		if(ch>='a' && ch<='z'||ch>='0' && ch<='9'||ch=='_'||ch=='@'||ch=='.')
		{
			ix++;
			cout<<ch;
			mail+=ch;
		}
		r1:				
		ch=getch();		
		if(ch==8)
		{	
			ix--;				
			gotoxy(ix, y);cout<<" \b";
			if(ix==x)
			{			
				gotoxy(ix, y);
				ix=x+1;
				n=1;				
				goto r1;
			}
			mail.erase(mail.length()-1,1);
			goto r1;
		}		
		else if(ch !=8 && n==1)	
		{			
			n=0;
			mail ="";
		}	
	}
}//validateEmail
void Password(int x,int y)
{
	int ix,n=0;
	ix=x;
	int k=password.length();
	password.erase(password.length()-k,k);
	gotoxy(x,y);
	char ch=getch();
	while(ch !=13)
	{		
		if(ch>='0' && ch<='9'||ch=='/')
		{
			ix++;
			cout<<"*";
			password+=ch;			
		}
		r1:				
		ch=getch();		
		if(ch==8)
		{	
			ix--;				
			gotoxy(ix, y);cout<<" \b";
			if(ix==x)
			{			
				gotoxy(ix, y);
				ix=x+1;
				n=1;				
				goto r1;
			}
			password.erase(password.length()-1,1);
			goto r1;
		}		
		else if(ch !=8 && n==1)	
		{			
			n=0;
			password ="";
		}	
	}
}//password
void information(){
//cls();
string show="WELCOME TO MY APPLICATION";
	int n=show.length();
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(show[i]==' ')
			{
				continue;
			}
			gotoxy(32+i,6);foreColor(130);
			cout<<(char)(97+j);
			delay(3);
		}
		gotoxy(32+i,6);//system("COLOR 3B");
		foreColor(130);cout<<show[i];
		delay(3);
	}
}
void login(){
int i,b,end=0,end1=0;
       char user[]="admin",pa[]="1234";   
	setcursor(0,0);
	stock();
	getch();
    do{
		setcursor(1,0);
       	cls();
       	system("color 1B");
       	for(int i=0;i<29;i++)
       	{
       		for(int j=0;j<5;j++)	
       		{
       			gotoxy(25+i,9);foreColor(150);cout<<(char)0;
       			gotoxy(27+i,11+j);foreColor(0);cout<<(char)0;
       			gotoxy(25+i,10+j);foreColor(180);cout<<(char)0;
       		}
		}			
		gotoxy(25,9);foreColor(150);cout<<" LOGIN ";		
	    gotoxy(27,11);foreColor(110);cout<<" Username :";
	    gotoxy(27,13);foreColor(110);cout<<" Password :";
	    gotoxy(38,11);foreColor(110);cout<<"              ";
	    gotoxy(38,13);foreColor(110);cout<<"              ";
		t:
	    validateCharacters(39,11); int a = cha1.length();char x[a]; cha1.copy(x, a); x[a] = '\0';	  		
		if(strcmp(x,"")==0){ goto t;}
		t1:
	    Password(39,13);int c=password.length(); char t9[c]; password.copy(t9, c); t9[c] = '\0';
		if(strcmp(t9,"")==0){ goto t1;}
	    b=0;
		setcursor(0,0);
		if(strcmp(x,user)==0 && strcmp(pa,t9)==0)
	    {
			b=1;    		
	    }		
		else
		{
		   	fp_product=fopen("Login.txt","rb");
			rewind(fp_product);	
		   	while(fread(&Create,sizeof(Product),1,fp_product))
			{
				if(strcmp(x,Create.User)==0 && strcmp(t9,Create.Pass)==0 )         
				{
					b=1; 					
				}
			}
			fclose(fp_product);			
		}			
		if(b==1)
		{
			boxfunction(18,17,40,1);
			for(int i=0;i<40;i++)
			{
				gotoxy(20,17);foreColor(150);cout<<"Loading";		
				gotoxy(19+i,18);foreColor(180);cout<<(char)0;
				gotoxy(20,19);foreColor(150);cout<<61+i<<" %";		
				delay(15);
			}
		}
		else if(b==0)
		{
			gotoxy(28,20);foreColor(90);cout<<"Password is incorrect...!" ;
			gotoxy(25,22);foreColor(90);cout<<"Press < Enter > to input again";
				getch();
				end++;
				if(end>2)
				{
					exit(0);
				}
		}
	}while(b!=1);
}//login
void Staff::addStaff()
{
	setcursor(1,0);
	again:
	//Interface(0);
	fp_staff=fopen("Staff.txt","rb");
	rewind(fp_staff);
	staffMenus();
	s:
	validateNumbers(25,6); int c=pass.length(); char get9[c]; pass.copy(get9, c); get9[c] = '\0';
	if(strcmp(get9,"")==0){ goto s;}
	while(fread(&St,sizeof(Staff),1,fp_staff))
	{
		if(strcmp(St.id ,get9)==0)
		{
			gotoxy(25,20);foreColor(4);cout<<"Already Exist...! Please Input new ID";
			getch();
			goto again;
		}
	}
	fclose(fp_staff);
	fp_staff=fopen("Staff.txt","a+b");
	rewind(fp_staff);
	staffMenus();
	strcpy(St.id,get9);
	gotoxy(25,6);cout<<St.id;
	s1:
	validateCharacters(25,8); c=cha1.length(); char get[c]; cha1.copy(get, c); get[c] = '\0';
	if(strcmp(get,"")==0){ goto s1;}
	strcpy(St.name,get);
	gotoxy(25,8);cout<<St.name;
	char ch;
	int k=0;
	char gender[2][7];
	strcpy(gender[0],"Male");
	strcpy(gender[1],"Female");
	do{
		switch(ch)
		{
			case 77:k++;if(k>1)k=0;break;
			case 75:k--;if(k<0)k=1;break;
		}
		gotoxy(25,10);foreColor(150);cout<<"<<";
		gotoxy(36,10);foreColor(150);cout<<">>";	
		gotoxy(28,10);foreColor(150);cout<<"       ";
		gotoxy(28,10);foreColor(150);cout<<gender[k];
		ch=getch();
		if(ch==13)
		{
			strcpy(St.gender,gender[k]);
		}
	}while(ch!=13);
	gotoxy(28,10);cout<<St.gender;
	s2:
	validateNumbers(25,12);	St.age=atoi(pass.c_str());
	if(St.age==0){ goto s2;}
	gotoxy(25,12);cout<<St.age;
	ch;
	k=0;
	char position[7][15];
	strcpy(position[0],"Manager");
	strcpy(position[1],"Accountant");
	strcpy(position[2],"Receptionist");
	strcpy(position[3],"Technician");	
	strcpy(position[4],"Salsperson");
	strcpy(position[5],"Labour");
	strcpy(position[6],"Cleaner");
	do{
		switch(ch)
		{
			case 77:k++;if(k>6) k=0;break;
			case 75:k--;if(k<0) k=6;break;
		}
		gotoxy(24,14);foreColor(150);cout<<"<<";
		gotoxy(40,14);foreColor(150);cout<<">>";	
		gotoxy(27,14);foreColor(150);cout<<"            ";
		gotoxy(27,14);foreColor(150);cout<<position[k];
		ch=getch();
		if(ch==13)
		{
			strcpy(St.position,position[k]);
		}
	}while(ch!=13);
	gotoxy(27,14);cout<<St.position;
	s3:
	validateNumbers(25,16); c=pass.length(); char get8[c]; pass.copy(get8, c); get8[c] = '\0';
	if(strcmp(get8,"")==0){ goto s3;}
	strcpy(St.phoneNumber,get8);
	gotoxy(25,16);cout<<St.phoneNumber;
	s4:
	validateEmail(25,18); c=mail.length(); char get3[c]; mail.copy(get3, c); get3[c] = '\0';
	if(strcmp(get3,"")==0){ goto s4;}
	strcpy(St.validateEmail,get3);
	gotoxy(25,18);cout<<St.validateEmail;
	s5:
	gotoxy(60,6);cout<<"dd/mm/yyyy";
	validateNumbers(60,6); c=pass.length(); char get7[c]; pass.copy(get7, c); get7[c] = '\0';
	if(strcmp(get7,"")==0){ goto s5;}
	strcpy(St.startWork,get7);
	gotoxy(60,6);cout<<St.startWork;
	s6:
	validateNumbers(60,8);	St.salary=atoi(pass.c_str());
	if(St.salary==0){goto s6;}
	gotoxy(60,8);cout<<St.salary;
	s7:
	gotoxy(60,10);cout<<"dd/mm/yyyy";
	validateNumbers(60,10); c=pass.length(); char get6[c]; pass.copy(get6, c); get6[c] = '\0';
	if(strcmp(get6,"")==0){ goto s7;}
	strcpy(St.dateOfbirth,get6);
	gotoxy(60,10);cout<<St.dateOfbirth;
	s8:
	validateCharacters(60,12); c=cha1.length(); char get4[c]; cha1.copy(get4, c); get4[c] = '\0';
	if(strcmp(get4,"")==0){ goto s8;}
	strcpy(St.placeOfBirth,get4);
	gotoxy(60,12);cout<<St.placeOfBirth;
	s9:
	validateCharacters(60,14); 	c=cha1.length(); char get5[c]; cha1.copy(get5, c); get5[c] = '\0';
	if(strcmp(get5,"")==0){ goto s9;}
	strcpy(St.nationality,get5);
	gotoxy(60,14);cout<<St.nationality;
	s10:
	validateNumbers(60,16); c=pass.length(); char ge[c]; pass.copy(ge, c); ge[c] = '\0';
	if(strcmp(ge,"")==0){ goto s10;}
	strcpy(St.idCard,ge);
	gotoxy(60,16);cout<<St.idCard;
	ch;
	k=0;
	char religion[5][15];
	strcpy(religion[0],"Buddhism");
	strcpy(religion[1],"Christ");
	strcpy(religion[2],"Islam");
	strcpy(religion[3],"Brahmanism");
	strcpy(religion[4],"Hinduism");
	do{
		switch(ch)
		{
			case 77:k++;if(k>4) k=0;break;
			case 75:k--;if(k<0) k=4;break;
		}
		gotoxy(61,18);foreColor(150);cout<<"<<";
		gotoxy(75,18);foreColor(150);cout<<">>";	
		gotoxy(63,18);foreColor(150);cout<<"            ";
		gotoxy(64,18);foreColor(150);cout<<religion[k];
		ch=getch();
		if(ch==13)
		{
			strcpy(St.religion,religion[k]);
		}
	}while(ch!=13);
	gotoxy(64,18);cout<<St.religion;
	fwrite(&St,sizeof(Staff),1,fp_staff);
	fclose(fp_staff);		
	gotoxy(20,20);foreColor(135);cout<<"Press <Enter> to add more or < Arrow key > to finish";
		if(getch()==13)
		{
			Interface(0);
			addStaff();
		}
setcursor(0,0);
}
void Staff::showStaff(){
setcursor(0,0);
char st;
int count,col=0;	
fp_staff=fopen("Staff.txt","rb");
rewind(fp_staff);
int ix=0;
count=0;
while(fread(&St,sizeof(Staff),1,fp_staff))
{
	stringstream s[100][6];
	
		s[ix][0]<<St.id;
		s[ix][1]<<St.name;
		s[ix][2]<<St.gender;
		s[ix][3]<<St.age;
		s[ix][4]<<St.position;
		s[ix][5]<<St.phoneNumber;
		
		staff[ix][0]=s[ix][0].str();
		staff[ix][1]=s[ix][1].str();
		staff[ix][2]=s[ix][2].str();
		staff[ix][3]=s[ix][3].str();
		staff[ix][4]=s[ix][4].str();
		staff[ix][5]=s[ix][5].str();
		ix++;
		if(ix>13)
		{
			col++;
		}
		if(strcmp(St.gender,"Female")==0 || strcmp(St.gender,"female")==0 ||strcmp(St.gender,"F")==0||strcmp(St.gender,"f")==0)
		{
			count++;
		}
}	
	fclose(fp_staff);	
	Interface(col);
	showMenu(col);
	boxbox(col);	
	string temp="";	
	for(int i=0; i<ix; i++)
	{
		for(int j=i+1; j<ix; j++)
		{
			if(staff[j][0] < staff[i][0])
			{
				for(int l=0;l<6;l++)
				{
					temp=staff[i][l];
					staff[i][l]=staff[j][l];
					staff[j][l]=temp;
				}						
			}
		}			
	}	
	do{
		for(int i=0;i<ix;i++)
		{
			gotoxy(14,6+i); foreColor(7);cout<<staff[i][0];		
			gotoxy(21,6+i); foreColor(7);cout<<staff[i][1];		
			gotoxy(38,6+i); foreColor(7);cout<<staff[i][2];		
			gotoxy(47,6+i); foreColor(7);cout<<staff[i][3];		
			gotoxy(54,6+i); foreColor(7);cout<<staff[i][4];		
			gotoxy(67,6+i); foreColor(7);cout<<staff[i][5];		
		}	
		gotoxy(37,20+col);cout<<"Female= ";foreColor(4);cout<<count;
		if(ix==0)
     	{
     		 gotoxy(15,20+col); foreColor(2);cout<<"No Staff";	
		}
		else if(ix==1)
     	{
     		 gotoxy(15,20+col); foreColor(2);cout<<"There is a Staff";	
		}
		else
     	{
     		 gotoxy(15,20+col); foreColor(2);cout<<"There are ";foreColor(4);cout<<ix;foreColor(2);cout<<" Staves";	
		}	
	}while(getch()!=27);
  Interface(0);
}//show();..........................
void Staff::editStaff(){
char id[10];
int b;
Interface(0);
gotoxy(14,4);foreColor(130);cout<<"1.Update Name  2.Update Position  3.Update Phone  4.Update validateEmail";
switch(getch()){
case '1': //edit name..................   
	setcursor(1,0);
		back1:
		Interface(0);
		fp_staff=fopen("Staff.txt","rb+");
		rewind(fp_staff);
		gotoxy(31,4);cout<<"Input ID to Update :  ";gotoxy(51,4);cin>>id;
		b=0;
		while(fread(&St,sizeof(Staff),1,fp_staff))
		{
			if(strcmp(St.id , id)==0)
			{
				b=1;
				fseek(fp_staff, -sizeof(St), SEEK_CUR);
				staffMenus();
				gotoxy(25,6);cout<<id;
				gotoxy(25,10);cout<<St.gender;
				gotoxy(25,12);cout<<St.age;
				gotoxy(25,14);cout<<St.position;
				gotoxy(25,16);cout<<St.phoneNumber;
				gotoxy(25,18);cout<<St.validateEmail;
		
				gotoxy(60,6);cout<<St.startWork;
				gotoxy(60,8);cout<<St.salary;
				gotoxy(60,10);cout<<St.dateOfbirth;
				gotoxy(60,12);cout<<St.placeOfBirth;
				gotoxy(60,14);cout<<St.nationality;
				gotoxy(60,16);cout<<St.idCard;
				gotoxy(60,18);cout<<St.religion;
				gotoxy(25,8);fflush(stdin);gets(St.name);
		
				fwrite(&St,sizeof(Staff),1,fp_staff);
				gotoxy(26,20);foreColor(135);cout<<"Press Arrow key up/down to finish";			
				break;
		}	
	}
	if(b==0)
	{
		gotoxy(34,18);foreColor(135);cout<<"This ID is not found..!";
		gotoxy(17,20);foreColor(135);cout<<"Press Enter to search again or Arrow key up/down to finish";
		if(getch()==13)
		{
			goto back1;
		} 	
	}	
  	fclose(fp_staff);
	setcursor(0,0);
  	break;
case '2':  //edit position.................
	setcursor(1,0);
	back2: 
  	Interface(0);
  	fp_staff=fopen("Staff.txt","rb+");
  	rewind(fp_staff);
	gotoxy(31,4);cout<<"Input ID to Update :  ";gotoxy(51,4);cin>>id;	
	b=0;
	while(fread(&St,sizeof(Staff),1,fp_staff))
	{
		if(strcmp(St.id , id)==0)
		{
			b=1;
			fseek(fp_staff, -sizeof(St), SEEK_CUR);
			staffMenus();
			gotoxy(25,6);cout<<id;
			gotoxy(25,8);cout<<St.name;
			gotoxy(25,10);cout<<St.gender;
			gotoxy(25,12);cout<<St.age;
			gotoxy(25,16);cout<<St.phoneNumber;
			gotoxy(25,18);cout<<St.validateEmail;
				
			gotoxy(60,6);cout<<St.startWork;
			gotoxy(60,8);cout<<St.salary;
			gotoxy(60,10);cout<<St.dateOfbirth;
			gotoxy(60,12);cout<<St.placeOfBirth;
			gotoxy(60,14);cout<<St.nationality;
			gotoxy(60,16);cout<<St.idCard;
			gotoxy(60,18);cout<<St.religion;
			gotoxy(25,14);fflush(stdin);gets(St.position);
			fwrite(&St,sizeof(Staff),1,fp_staff);
			gotoxy(26,20);foreColor(135);cout<<"Press Arrow key up/down to finish";			
			break;
		}	
	}
	if(b==0)
	{
		gotoxy(34,18);foreColor(135);cout<<"This ID is not found..!";
		gotoxy(17,20);foreColor(135);cout<<"Press Enter to search again or Arrow key up/down to finish";
		if(getch()==13)
		{
			goto back2;
		} 	
	}	
   fclose(fp_staff);
	setcursor(0,0); 
  break;
case '3':   //edit phone...............
	setcursor(1,0);
  	back3:
  	Interface(0);
  	fp_staff=fopen("Staff.txt","rb+");
  	rewind(fp_staff);
	gotoxy(31,4);cout<<"Input ID to Update :  ";gotoxy(51,4);cin>>id;	
	b=0;
	while(fread(&St,sizeof(Staff),1,fp_staff))
	{
		if(strcmp(St.id , id)==0)
		{
			b=1;
			fseek(fp_staff, -sizeof(St), SEEK_CUR);
			staffMenus();
			gotoxy(25,6);cout<<id;
			gotoxy(25,8);cout<<St.name;
			gotoxy(25,10);cout<<St.gender;
			gotoxy(25,12);cout<<St.age;
			gotoxy(25,14);cout<<St.position;
			gotoxy(25,18);cout<<St.validateEmail;	
			
			gotoxy(60,6);cout<<St.startWork;
			gotoxy(60,8);cout<<St.salary;
			gotoxy(60,10);cout<<St.dateOfbirth;
			gotoxy(60,12);cout<<St.placeOfBirth;
			gotoxy(60,14);cout<<St.nationality;
			gotoxy(60,16);cout<<St.idCard;
			gotoxy(60,18);cout<<St.religion;
			gotoxy(25,16);fflush(stdin);gets(St.phoneNumber);

			fwrite(&St,sizeof(Staff),1,fp_staff);
			gotoxy(26,20);foreColor(135);cout<<"Press Arrow key up/down to finish";			
			break;
		}	
	}
	if(b==0)
	{
		gotoxy(34,18);foreColor(135);cout<<"This ID is not found..!";
		gotoxy(17,20);foreColor(135);cout<<"Press Enter to search again or Arrow key up/down to finish";
		if(getch()==13)
		{
			goto back3;
		} 	
	}	
	fclose(fp_staff);
	setcursor(0,0);	
  break;
case '4':   //edit validateEmail............... 
	setcursor(1,0);
	back4:
  	Interface(0);
  	fp_staff=fopen("Staff.txt","rb+");
  	rewind(fp_staff);
	gotoxy(31,4);cout<<"Input ID to Update :  ";gotoxy(51,4);cin>>id;
	
	b=0;
	while(fread(&St,sizeof(Staff),1,fp_staff))
	{
		if(strcmp(St.id , id)==0)
		{
			b=1;
			fseek(fp_staff, -sizeof(St), SEEK_CUR);
			staffMenus();
			gotoxy(25,6);cout<<id;
			gotoxy(25,8);cout<<St.name;
			gotoxy(25,10);cout<<St.gender;
			gotoxy(25,12);cout<<St.age;
			gotoxy(25,14);cout<<St.position;
			gotoxy(25,16);cout<<St.phoneNumber;	
			
			gotoxy(60,6);cout<<St.startWork;
			gotoxy(60,8);cout<<St.salary;
			gotoxy(60,10);cout<<St.dateOfbirth;
			gotoxy(60,12);cout<<St.placeOfBirth;
			gotoxy(60,14);cout<<St.nationality;
			gotoxy(60,16);cout<<St.idCard;
			gotoxy(60,18);cout<<St.religion;
			gotoxy(25,18);fflush(stdin);gets(St.validateEmail);
	
			fwrite(&St,sizeof(Staff),1,fp_staff);
			gotoxy(26,20);foreColor(135);cout<<"Press Arrow key up/down to finish";	
			break;
		}	
	}
	if(b==0)
	{
		gotoxy(34,18);foreColor(135);cout<<"This ID is not found..!";
		gotoxy(17,20);foreColor(135);cout<<"Press Enter to search again or Arrow key up/down to finish";
		if(getch()==13)
		{
			goto back4;
		} 	
	}	
   	fclose(fp_staff);
	setcursor(0,0);	
	break;
 }//switch();
}//edit();

void Staff::deleteStaff()
{
	int b;
	begin:
	Interface(0);
	char id[10];
	gotoxy(14,4);foreColor(130);cout<<"1.Delete by ID    2.Delete All";
	switch(getch())
	{
	case '1':
		setcursor(1,0);
		fp_staff=fopen("Staff.txt","rb");
		fp_staff1=fopen("Staff1.txt","wb");
		rewind(fp_staff);
		gotoxy(14,6);cout<<"Input ID to Delete : ";cin>>id;
		b=0;
		while(fread(&St,sizeof(Staff),1,fp_staff))
		{
			if(strcmp(St.id , id)!=0)
			{
				fwrite(&St,sizeof(Staff),1,fp_staff1);
			}
			if(strcmp(St.id,id)==0)
			{
				b=1;
				gotoxy(30,20);foreColor(135);cout<<"Deleted Successfully...!";	
				getch();
			}
		}	
		if(b==0)
		{
			gotoxy(34,18);foreColor(135);cout<<"This ID is not found..!";
			gotoxy(17,20);foreColor(135);cout<<"Press Enter to search again or Arrow key up/down to finish";
			if(getch()==13)
			{
				goto begin;
			} 	
		}	
		fclose(fp_staff);
		fclose(fp_staff1);
		remove("Staff.txt");
		rename("Staff1.txt","Staff.txt");
	setcursor(0,0);	
	break;
	case '2':		
   		boxfunction1(27,6,31,3);
		gotoxy(30,7);foreColor(135);cout<<"Are you Sure to Delete All ?";	
		gotoxy(30,9);foreColor(135);cout<<"ENTER =>YES     Up/Down =>NO";	
   		if(getch()==13)
	   	{
			fp_staff=fopen("Staff.txt","rb");
			rewind(fp_staff);
			while(fread(&St,sizeof(Staff),1,fp_staff))	
			fclose(fp_staff);
			remove("Staff.txt");
			gotoxy(33,20);foreColor(135);cout<<"Deleted successfully..!";
			getch();
		}		
	break;
	}//switch
}//delete();

void Staff::searchStaff()
{
	setcursor(1,0);
	int b;
	begin1:
	Interface(0);
	char find[10];
	fp_staff=fopen("Staff.txt","rb");
	rewind(fp_staff);
	gotoxy(30,4);cout<<"Input ID to Search :  ";gotoxy(51,4);cin>>find;
	b=0;
	while(fread(&St,sizeof(Staff),1,fp_staff))
	{
		if(strcmp(St.id,find)==0)
		{
			b=1;		
			staffMenus();
			gotoxy(25,6);cout<<St.id;
			gotoxy(25,8);cout<<St.name;
			gotoxy(25,10);cout<<St.gender;
			gotoxy(25,12);cout<<St.age;
			gotoxy(25,14);cout<<St.position;
			gotoxy(25,16);cout<<St.phoneNumber;
			gotoxy(25,18);cout<<St.validateEmail;
			
			gotoxy(60,6);cout<<St.startWork;
			gotoxy(60,8);cout<<"$ "<<St.salary;
			gotoxy(60,10);cout<<St.dateOfbirth;
			gotoxy(60,12);cout<<St.placeOfBirth;
			gotoxy(60,14);cout<<St.nationality;
			gotoxy(60,16);cout<<St.idCard;
			gotoxy(60,18);cout<<St.religion;
			gotoxy(26,20);foreColor(135);cout<<"Press Arrow key up/down to finish";	
		}
	}
		if(b==0)
		{
			gotoxy(34,18);foreColor(135);cout<<"This ID is not found..!";
			gotoxy(17,20);foreColor(135);cout<<"Press Enter to search again or Arrow key up/down to finish";
			if(getch()==13)
			{
				goto begin1;
			} 	
		}	
	fclose(fp_staff);
setcursor(0,0);
}//search();
void addProduct(){
setcursor(1,0);
char id[10];
back:
again:
Interface(0);
fp_remainder=fopen("Remainder.txt","rb");
rewind(fp_remainder);
fp_product=fopen("Product.txt","rb");
rewind(fp_product);
w:
	productHeader();
gotoxy(40,6);cin>>id;

if(strcmp(id,"")==0){ goto w;}
while(fread(&Pro,sizeof(Product),1,fp_product))
{
	if(strcmp(Pro.id ,id)==0)
	{
		gotoxy(23,20);foreColor(135);cout<<" Already Exist...! Please Input new ID ";
		getch();
		goto again;
	}
}
fclose(fp_product);
fclose(fp_remainder);

fp_remainder=fopen("Remainder.txt","a+b");
rewind(fp_remainder);
fp_product=fopen("Product.txt","a+b");
rewind(fp_product);
		productHeader();
		strcpy(Pro.id, id);
		gotoxy(40,6);cout<<Pro.id;
		w1:
		validateCharacters(40,8); c=cha1.length(); char g2[c]; cha1.copy(g2, c); g2[c] = '\0';
		if(strcmp(g2,"")==0){ goto w1;}
		strcpy(Pro.name,g2);
		gotoxy(40,8);cout<<Pro.name;
		w2:
		validateNumbers(40,10); Pro.quantity=atoi(pass.c_str());
		if(Pro.quantity==0){goto w2;}
		gotoxy(40,10);cout<<Pro.quantity;
		w3:
		validateNumbers(40,12); Pro.unitPrice=atoi(pass.c_str());
		if(Pro.unitPrice==0){goto w3;}
		gotoxy(40,12);cout<<Pro.unitPrice;
		w4:		
		gotoxy(40,14); cout<<"dd/mm/yyyy";
		validateNumbers(40,14); c=pass.length(); char g3[c]; pass.copy(g3, c); g3[c] = '\0';
		if(strcmp(g3,"")==0){ goto w4;}
		strcpy(Pro.date,g3);
		gotoxy(40,14); cout<<Pro.date;
		w5:
		gotoxy(50,16);cout<<"Ex: 855";
		validateNumbers(40,16); Pro.productOf=atoi(pass.c_str());
		if(Pro.productOf==0){ goto w5; }
		gotoxy(40,16);cout<<Pro.productOf;
		Pro.total=Pro.unitPrice*Pro.quantity;
		gotoxy(40,18);cout<<Pro.total<<" $";		
		
		fwrite(&Pro,sizeof(Product),1,fp_product);
		fwrite(&Pro,sizeof(Product),1,fp_remainder);
		
		fclose(fp_product);	
		fclose(fp_remainder);	
		gotoxy(19,20);foreColor(135);cout<<"Press Enter to add more or Arrow key Up/Down to finish";
		if(getch()==13)
		{
			goto back;
		}		
setcursor(0,0);	
}
void showProduct()
{
setcursor(0,0);
int col=0,ix=0;
float total=0;
fp_product=fopen("Product.txt","rb");
rewind(fp_product);
while(fread(&Pro,sizeof(Product),1,fp_product))
{
	stringstream p[100][7];
	
		p[ix][0]<<Pro.id;
		p[ix][1]<<Pro.name;
		p[ix][2]<<Pro.quantity;
		p[ix][3]<<Pro.unitPrice;
		p[ix][4]<<Pro.date;		
		p[ix][5]<<Pro.productOf;
		p[ix][6]<<Pro.total;
		total+=Pro.total;
		
		product[ix][0]=p[ix][0].str();
		product[ix][1]=p[ix][1].str();
		product[ix][2]=p[ix][2].str();
		product[ix][3]=p[ix][3].str();
		product[ix][4]=p[ix][4].str();
		product[ix][5]=p[ix][5].str();
		product[ix][6]=p[ix][6].str();
		ix++;
		if(ix>13){	col++;	}
}		
fclose(fp_product);	
	Interface(col);
	productMenus(col);
	boxbox1(col);
	do{
		string temp="";
		for(int i=0; i<ix; i++)
		{	
			for(int j=i+1; j<ix; j++)
			{
				if(product[j][0] < product[i][0])
				{
					for(int l=0;l<7;l++)
					{
						temp=product[i][l];
						product[i][l]=product[j][l];
						product[j][l]=temp;
					}
				}
			}			
		}	
		float Total=0;
		for(int i=0; i<ix; i++)
		{
			gotoxy(14,6+i); foreColor(7);cout<<product[i][0];		
			gotoxy(21,6+i); foreColor(7);cout<<product[i][1];		
			gotoxy(34,6+i); foreColor(7);cout<<product[i][2];			
			gotoxy(40,6+i); foreColor(7);cout<<"$ "<<product[i][3];		
			gotoxy(48,6+i); foreColor(7);cout<<product[i][4];		
			gotoxy(61,6+i); foreColor(7);cout<<product[i][5];							
			gotoxy(67,6+i);foreColor(6);cout<<"$ "<<product[i][6];		
		}
			gotoxy(46,20+col); foreColor(6);cout<<"Total of product : ";foreColor(6);cout<<"$ ";foreColor(4);cout<<total;	
			if(ix==0)
	     	{
	     		 gotoxy(15,20+col); foreColor(2);cout<<"No Product";	
			}
			else if(ix==1)
	     	{
	     		 gotoxy(15,20+col); foreColor(2);cout<<"There is a type of product";	
			}
			else
	     	{
	     		 gotoxy(15,20+col); foreColor(2);cout<<"There are ";foreColor(4);cout<<ix;foreColor(2);cout<<" types of product";	
			}
	}while(getch()!=27);
	Interface(0);
}//showProduct();

void showRemainderProduct()
{
	setcursor(0,0);
	int col=0, ix=0;
	float to=0,Amount=0;
	fp_remainder=fopen("Remainder.txt","rb");
	rewind(fp_remainder);
	while(fread(&Pro,sizeof(Product),1,fp_remainder))
	{
		stringstream p1[100][6];
		
			p1[ix][0]<<Pro.id;
			p1[ix][1]<<Pro.name;
			p1[ix][2]<<Pro.quantity;
			p1[ix][3]<<Pro.unitPrice;
			p1[ix][4]<<Pro.date;		
			p1[ix][5]<<Pro.productOf;
			to=Pro.quantity*Pro.unitPrice;
			p1[ix][6]<<to;
			Amount+=to;
			
			remainder[ix][0]=p1[ix][0].str();
			remainder[ix][1]=p1[ix][1].str();
			remainder[ix][2]=p1[ix][2].str();
			remainder[ix][3]=p1[ix][3].str();
			remainder[ix][4]=p1[ix][4].str();
			remainder[ix][5]=p1[ix][5].str();
			remainder[ix][6]=p1[ix][6].str();
			ix++;
			if(ix>13){	col++;	}
	}			
	fclose(fp_remainder);
	Interface(col);	
	productMenus(col);
	boxbox1(col);
	do{
	string temp="";
	for(int i=0; i<ix; i++)
	{
		for(int j=i; j<ix; j++)
		{
			if(remainder[j][0] < remainder[i][0])
			{
				for(int l=0;l<7;l++)
				{
					temp=remainder[i][l];
					remainder[i][l]=remainder[j][l];
					remainder[j][l]=temp;
				}
			}
		}			
	}	
	float Total=0;
	for(int i=0; i<ix; i++)
	{
		gotoxy(14,6+i); foreColor(7);cout<<remainder[i][0];		
		gotoxy(21,6+i); foreColor(7);cout<<remainder[i][1];		
		gotoxy(34,6+i); foreColor(7);cout<<remainder[i][2];		
		gotoxy(40,6+i); foreColor(7);cout<<"$ "<<remainder[i][3];		
		gotoxy(48,6+i); foreColor(7);cout<<remainder[i][4];		
		gotoxy(61,6+i); foreColor(7);cout<<remainder[i][5];						
		gotoxy(67,6+i); foreColor(6);cout<<"$ "<<remainder[i][6];		
	}
		gotoxy(46,20+col); foreColor(6);cout<<"Total of product : ";foreColor(6);cout<<"$ ";foreColor(4);cout<<Amount;	
		if(ix==0)
     	{
     		 gotoxy(15,20+col); foreColor(2);cout<<"No Product";	
		}
		else if(ix==1)
     	{
     		 gotoxy(15,20+col); foreColor(2);cout<<"There is a type of product";	
		}
		else
     	{
     		 gotoxy(15,20+col); foreColor(2);cout<<"There are ";foreColor(4);cout<<ix;foreColor(2);cout<<" types of product";	
		}
	}while(getch()!=27);
	Interface(0);
}//showRemainderProduct();

void editProduct()
{
	int b;
	gotoxy(15,4);foreColor(130);cout<<"Press key =>";
	gotoxy(15,5);foreColor(130);cout<<"1. Update Name   2.Update Quantity   3.Update Price";
	switch(getch()){
	case '1':
		setcursor(1,0);
		start1:
		Interface(0);
		char id2[10];
		fp_product=fopen("Product.txt","rb");
		rewind(fp_product);
		fp_product1=fopen("Product1.txt","wb");
		fp_remainder1=fopen("Remainder1.txt","wb");
		gotoxy(32,4);cout<<"Input ID to Update :  ";gotoxy(53,4);cin>>id2;
		b=0;
			while(fread(&Pro,sizeof(Product),1,fp_product)==1)
			{
				if(strcmp(Pro.id , id2)==0)
				{
					b=1;
					productHeader();
					gotoxy(40,6);cout<<Pro.id;
					gotoxy(40,10);cout<<Pro.quantity;
					gotoxy(40,12);cout<<Pro.unitPrice;		
					gotoxy(40,14);cout<<Pro.date;
					gotoxy(40,16);cout<<Pro.productOf;
					Pro.total=Pro.unitPrice * Pro.quantity;		
					gotoxy(40,18);cout<<"$ "<<Pro.total;		
					validateCharacters(40,8);int z=cha1.length(); char p3[z]; cha1.copy(p3, z); p3[z] = '\0';
					strcpy(Pro.name,p3);
					gotoxy(40,8);cout<<Pro.name;
					gotoxy(26,20);foreColor(135);cout<<"Press Arrow key up/down to finish";	
				}
				fwrite(&Pro,sizeof(Product),1,fp_product1);	
				fwrite(&Pro,sizeof(Product),1,fp_remainder1);	
			}
			fclose(fp_product);	
			fclose(fp_product1);	
			fclose(fp_remainder);	
			fclose(fp_remainder1);	
			remove("Product.txt");
			rename("Product1.txt","Product.txt");
			remove("Remainder.txt");
			rename("Remainder1.txt","Remainder.txt");
			fp_product=fopen("Product.txt","a+b");
			fp_remainder=fopen("Remainder.txt","a+b");
			fclose(fp_product);	
			fclose(fp_remainder);		
		if(b==0)
		{
			gotoxy(34,18);foreColor(135);cout<<"This ID is not found..!";
			gotoxy(17,20);foreColor(135);cout<<"Press Enter to search again or Arrow key up/down to finish";
			if(getch()==13)
			{
				goto start1;
			} 	
		}	
		setcursor(0,0);
		break;
	case '2':
		setcursor(1,0);	
		start2:
		Interface(0);
		char id3[10];
		fp_product=fopen("Product.txt","rb");
		rewind(fp_product);
		fp_product1=fopen("Product1.txt","wb");
		fp_remainder1=fopen("Remainder1.txt","wb");
		gotoxy(32,4);cout<<"Input ID to Update :  ";gotoxy(53,4);cin>>id3;
			b=0;
			while(fread(&Pro,sizeof(Product),1,fp_product)==1)
			{
				if(strcmp(Pro.id , id3)==0)
				{
					b=1;
					productHeader();			
					gotoxy(40,6);cout<<Pro.id;
					gotoxy(40,8);cout<<Pro.name;
					gotoxy(40,12);cout<<Pro.unitPrice;		
					gotoxy(40,14);cout<<Pro.date;
					gotoxy(40,16);cout<<Pro.productOf;
					validateNumbers(40,10); Pro.quantity=atoi(pass.c_str()); gotoxy(40,10);cout<<Pro.quantity;
					Pro.total=Pro.unitPrice * Pro.quantity;			
					gotoxy(40,18);cout<<"$ "<<Pro.total;
					gotoxy(26,20);foreColor(135);cout<<"Press Arrow key up/down to finish";	
				}
				fwrite(&Pro,sizeof(Product),1,fp_product1);	
				fwrite(&Pro,sizeof(Product),1,fp_remainder1);	
			}
			fclose(fp_product);	
			fclose(fp_product1);	
			fclose(fp_remainder);	
			fclose(fp_remainder1);	
			remove("Product.txt");
			rename("Product1.txt","Product.txt");
			remove("Remainder.txt");
			rename("Remainder1.txt","Remainder.txt");
			fp_product=fopen("Product.txt","a+b");
			fp_remainder=fopen("Remainder.txt","a+b");
			fclose(fp_product);	
			fclose(fp_remainder);		
			if(b==0)
		{
			gotoxy(34,18);foreColor(135);cout<<"This ID is not found..!";
			gotoxy(17,20);foreColor(135);cout<<"Press Enter to search again or Arrow key up/down to finish";
			if(getch()==13)
			{
				goto start2;
			} 	
		}	
		setcursor(0,0);
		break;
	case '3':
	setcursor(1,0);
	start3:
	Interface(0);
	char id4[10];
	fp_product=fopen("Product.txt","rb");
	rewind(fp_product);
	fp_product1=fopen("Product1.txt","wb");
	fp_remainder1=fopen("Remainder1.txt","wb");
	gotoxy(32,4);cout<<"Input ID to Update :  ";gotoxy(53,4);cin>>id4;	
		b=0;
		while(fread(&Pro,sizeof(Product),1,fp_product)==1)
		{
			if(strcmp(Pro.id , id4)==0)
			{
				b=1;
				productHeader();	
				gotoxy(40,6);cout<<Pro.id;
				gotoxy(40,8);cout<<Pro.name;
				gotoxy(40,10);cout<<Pro.quantity;
				gotoxy(40,14);cout<<Pro.date;
				gotoxy(40,16);cout<<Pro.productOf;
				validateNumbers(40,12);	Pro.unitPrice=atoi(pass.c_str()); gotoxy(40,12);cout<<Pro.unitPrice;		
				Pro.total= Pro.unitPrice * Pro.quantity;
				gotoxy(40,18);cout<<"$ "<<Pro.total;
				gotoxy(26,20);foreColor(135);cout<<"Press Arrow key up/down to finish";	
			}
			fwrite(&Pro,sizeof(Product),1,fp_product1);	
			fwrite(&Pro,sizeof(Product),1,fp_remainder1);	
		}
		fclose(fp_product);	
		fclose(fp_product1);	
		fclose(fp_remainder);	
		fclose(fp_remainder1);	
		remove("Product.txt");
		rename("Product1.txt","Product.txt");
		remove("Remainder.txt");
		rename("Remainder1.txt","Remainder.txt");
		fp_product=fopen("Product.txt","a+b");
		fp_remainder=fopen("Remainder.txt","a+b");
		fclose(fp_product);	
		fclose(fp_remainder);				
		if(b==0)
		{
			gotoxy(34,18);foreColor(135);cout<<"This ID is not found..!";
			gotoxy(17,20);foreColor(135);cout<<"Press Enter to search again or Arrow key up/down to finish";
			if(getch()==13)
			{
				goto start3;
			} 	
		}	
	setcursor(0,0);
	break;
	}//switch();
}//update();
void deleteProduct()
{
	int b,c=0;
	char Date[12];
	gotoxy(15,4);foreColor(130);cout<<"Press key ";
	gotoxy(15,5);foreColor(130);cout<<"1. Delete by Pro_ID   2. Delete by Date   3.DELETE All";
	switch(getch()){
	case '1':
	setcursor(1,0);
	start:
	Interface(0);
	char id[10];
	fp_remainder=fopen("Remainder.txt","rb");
	fp_remainder1=fopen("Remainder1.txt","wb");
	fp_product=fopen("Product.txt","rb");
	fp_product1=fopen("Product1.txt","wb");
	rewind(fp_product);
	
	gotoxy(32,4);cout<<"Input Pro_ID to Delete :  ";gotoxy(56,4);cin>>id;
	b=0;
	while(fread(&Pro,sizeof(Product),1,fp_product))
	{
		if(strcmp(Pro.id , id)!=0)
		{
			fwrite(&Pro,sizeof(Product),1,fp_product1);
			fwrite(&Pro,sizeof(Product),1,fp_remainder1);			
		}
		if(strcmp(Pro.id, id)==0)
		{
			b=1;
			gotoxy(33,20);foreColor(4);cout<<"Deleted successfully..!";
		}
	}	
		if(b==0)
		{
			gotoxy(32,18);foreColor(135);cout<<"This Pro_ID is not found..!";
			gotoxy(17,20);foreColor(135);cout<<"Press Enter to search again or Arrow key up/down to finish";
			if(getch()==13)
			{
				goto start;
			} 	
		}	
	fclose(fp_product);
	fclose(fp_product1);
	remove("Product.txt");
	rename("Product1.txt","Product.txt");
	fclose(fp_remainder);
	fclose(fp_remainder1);
	remove("Remainder.txt");
	rename("Remainder1.txt","Remainder.txt");
	setcursor(0,0);
	break;
	case '2':
	setcursor(1,0);
	start1:
	Interface(0);
	fp_remainder=fopen("Remainder.txt","rb");
	fp_remainder1=fopen("Remainder1.txt","wb");
	fp_product=fopen("Product.txt","rb");
	fp_product1=fopen("Product1.txt","wb");
	rewind(fp_product);
	
	gotoxy(48,4);cout<<"dd/mm/yyyy";
	gotoxy(25,4);cout<<"Input Date to Delete : ";
	validateNumbers(48,4); c=pass.length(); Date[c]; pass.copy(Date, c); Date[c] = '\0';
	b=0;
	while(fread(&Pro,sizeof(Product),1,fp_product))
	{
		if(strcmp(Pro.date , Date)!=0)
		{
			fwrite(&Pro,sizeof(Product),1,fp_product1);
			fwrite(&Pro,sizeof(Product),1,fp_remainder1);
		}
		if(strcmp(Pro.date,Date)==0)
		{
			b=1;
			gotoxy(33,20);foreColor(4);cout<<"Deleted successfully..!";
		}
	}	
		if(b==0)
		{
			gotoxy(33,18);foreColor(135);cout<<"This Date is not found..!";
			gotoxy(17,20);foreColor(135);cout<<"Press Enter to search again or Arrow key up/down to finish";
			if(getch()==13)
			{
				goto start1;
			} 	
		}
	fclose(fp_product);
	fclose(fp_product1);	
	remove("Product.txt");
	rename("Product1.txt","Product.txt");
	fclose(fp_remainder);
	fclose(fp_remainder1);
	remove("Remainder.txt");
	rename("Remainder1.txt","Remainder.txt");
	setcursor(0,0);
	break;
	
	case '3':
	setcursor(0,0);
		boxfunction1(27,6,31,3);
   		gotoxy(30,7);foreColor(135);cout<<"Are you Sure to Delete All ?";	
   		gotoxy(30,9);foreColor(135);cout<<"ENTER =>YES     Up/Down =>NO";
   		if(getch()==13)
	   	{
			fp_remainder=fopen("Remainder.txt","rb");
			fp_product=fopen("Product.txt","rb");
			rewind(fp_product);
			rewind(fp_remainder);
			while(fread(&Pro,sizeof(Product),1,fp_product))	
			while(fread(&Pro,sizeof(Product),1,fp_remainder))	
			fclose(fp_product);
			fclose(fp_remainder);	
			remove("Product.txt");
			remove("Remainder.txt");			
			gotoxy(33,20);foreColor(4);cout<<"Deleted successfully..!";
			getch();
		}		
	break;
	}//switch();
}
void searchProduct()
{
	int b,n;
	float Amount=0;
	char Date[20];
	gotoxy(15,4);foreColor(130);cout<<"Press key =>";
	gotoxy(15,5);foreColor(130);cout<<"1. Search by Product Name   2. Search by Date";
	switch(getch()){
	case '1':
	setcursor(1,0);
	start:
	Interface(0);
	char Name[20];
	gotoxy(25,4);cout<<"Input Product Name to Search :  ";gotoxy(56,4);gets(Name);
	fp_product=fopen("Product.txt","rb");
	rewind(fp_product);
	b=0;
	while(fread(&Pro,sizeof(Product),1,fp_product))
	{
		if(strcmp(Pro.name, Name)==0)
		{
			b=1;
		gotoxy(29,6);foreColor(180);cout<<"     Product Information    ";
		for(int i=0;i<7;i++)
		{
			gotoxy(29,8+i*2);foreColor(180);cout<<Put[i];
			gotoxy(39,8+i*2);foreColor(150);cout<<"                  ";
		}
//		productHeader();
			gotoxy(40,8);cout<<Pro.id;
			gotoxy(40,10);cout<<Pro.name;
			gotoxy(40,12);cout<<Pro.quantity;
			gotoxy(40,14);cout<<Pro.unitPrice;	
			gotoxy(40,16);cout<<Pro.date;
			gotoxy(40,18);cout<<Pro.productOf;
			Pro.total= Pro.unitPrice * Pro.quantity;
			gotoxy(40,20);cout<<"$ "<<Pro.total;
			gotoxy(26,21);foreColor(135);cout<<"Press Arrow key up/down to finish";	
		}
	}
	if(b==0)
		{
			gotoxy(30,18);foreColor(135);cout<<"This Product Name is not found..!";
			gotoxy(17,20);foreColor(135);cout<<"Press Enter to search again or Arrow key up/down to finish";
			if(getch()==13)
			{
				goto start;
			} 	
		}
	fclose(fp_product);
	setcursor(0,0);
	break;
	
	case '2':
	setcursor(1,0);
	start1:
	Interface(0);
	gotoxy(48,4);cout<<"dd/mm/yyyy";
	gotoxy(25,4);cout<<"Input Date to Search : ";
	validateNumbers(48,4); int z=pass.length(); char p4[z]; pass.copy(p4, z); p4[z] = '\0';
	fp_product=fopen("Product.txt","rb");
	rewind(fp_product);
	productMenus(0);
	boxbox1(0);
	b=0;
	n=0;
	while(fread(&Pro,sizeof(Product),1,fp_product))
	{
		if(strcmp(Pro.date, p4)==0)
		{
			b=1;
			gotoxy(15,6+n); foreColor(7);cout<<Pro.id;		
			gotoxy(21,6+n); foreColor(7);cout<<Pro.name;	
			gotoxy(34,6+n); foreColor(7);cout<<Pro.quantity;		
			gotoxy(40,6+n); foreColor(7);cout<<"$ "<<Pro.unitPrice;		
			gotoxy(48,6+n); foreColor(7);cout<<Pro.date;		
			gotoxy(61,6+n); foreColor(7);cout<<Pro.productOf;
			gotoxy(68,6+n); foreColor(6);cout<<"$ "<<Pro.total;		
			Amount+=Pro.total;
			n++;
			
		}
		gotoxy(46,20); foreColor(6);cout<<"Total of product : ";foreColor(4);cout<<Amount;foreColor(6);cout<<" $";	
	}
	if(b==0)
		{
			gotoxy(17,20);foreColor(7);cout<<"Press Enter to search again or Arrow key up/down to finish";
			if(getch()==13)
			{
				goto start1;
			} 	
		}	
		else if(n==1)
     	{
     		 gotoxy(15,20); foreColor(2);cout<<"There is a type of product";	
		}
		else if(n>1)
     	{
     		 gotoxy(15,20); foreColor(2);cout<<"There are ";foreColor(4);cout<<n;foreColor(2);cout<<" types of product";	
		}
	fclose(fp_product);
	setcursor(0,0);
	break;
 }//switch();
}//search product

void Payment::saleProduct()
{
	setcursor(1,0);
	float amount=0,amount1,Price=0,contain=0;
	int b;
	Pay.AmountTotal=0;
do{
	Interface(0);
	fp_payment=fopen("Payment.txt","a+b");
	rewind(fp_payment);
		saleMenus();
		r:
		validateCharacters(27,6); int a=cha1.length(); char cus[a];cha1.copy(cus,a);cus[a]= '\0';
		if(strcmp(cus,"")==0){ goto r;}
		strcpy(Pay.Ex_customer,cus);
		gotoxy(27,6);cout<<Pay.Ex_customer;
		r1:
		validateNumbers(27,8); int c=pass.length(); char phone[c]; pass.copy(phone, c); phone[c] = '\0';
		if(strcmp(phone,"")==0){ goto r1;}
		strcpy(Pay.Ex_phone,phone);
		gotoxy(27,8);cout<<Pay.Ex_phone;
		r2:
		gotoxy(27,10);cout<<"dd/mm/yyyy";
		validateNumbers(27,10); c=pass.length(); char w2[c]; pass.copy(w2, c); w2[c] = '\0';
		if(strcmp(w2,"")==0){ goto r2;}
		strcpy(Pay.Ex_date,w2);
		gotoxy(27,10);cout<<Pay.Ex_date;
		again2:
		bang();
		gotoxy(26,12);foreColor(150);cout<<"                ";
		gotoxy(27,12);fflush(stdin);gets(Pay.Ex_Proid);
		fp_remainder=fopen("Remainder.txt","rb");
		rewind(fp_remainder);
		b=0;
		while(fread(&Pro,sizeof(Product),1,fp_remainder))		
		{
			if(strcmp(Pay.Ex_Proid,Pro.id)==0)	
			{
				b=1;
				strcpy(Pay.Ex_product,    Pro.name);
				Pay.Ex_product_of=Pro.productOf;
				//////////////////////////////
				if(Pro.unitPrice>0 && Pro.unitPrice<=10){ Pay.Ex_price=Pro.unitPrice+1; }
				else if(Pro.unitPrice>10 && Pro.unitPrice<=20){ Pay.Ex_price=Pro.unitPrice+2; }
				else if(Pro.unitPrice>20 && Pro.unitPrice<=30){ Pay.Ex_price=Pro.unitPrice+3; }
				else if(Pro.unitPrice>40 && Pro.unitPrice<=50){ Pay.Ex_price=Pro.unitPrice+4; }
				else {  Pay.Ex_price=Pro.unitPrice+10; } 
				/////////////////////////////
				gotoxy(30,18);foreColor(150);cout<<"Your product has only "<<Pro.quantity;
				if(Pro.quantity==0)
				{
					gotoxy(20,20);foreColor(150);cout<<"This Product ID is Empty..! Please Enter again.!";
					getch();
					goto again2;
				}
			}
		}		
		if(b==0)
		{
			gotoxy(30,18);foreColor(135);cout<<"This Product ID is Empty..!";
			gotoxy(19,20);foreColor(135);cout<<"Press < Enter > to Input again or < Escape > to finish";
			if(getch()==13)
			{
				goto again2;
			}
			else{ goto end;}
		}
		fclose(fp_remainder);
		
		gotoxy(27,14);cout<<Pay.Ex_product;		
		gotoxy(27,16);cout<<Pay.Ex_product_of;		
		put:
		r3:
		gotoxy(58,6);foreColor(150);cout<<"                 ";
		validateNumbers(60,6); Pay.Ex_qty=atoi(pass.c_str());
		if(Pay.Ex_qty==0){goto r3;}
		gotoxy(60,6);cout<<Pay.Ex_qty;
		///////////////////////////////////

//		validateNumbers(60,8);Pay.Ex_price=atoi(pass.c_str());
//		gotoxy(60,8);cout<<Pay.Ex_price;
		///////////////////////////////////

		fp_remainder=fopen("Remainder.txt","rb");
		rewind(fp_remainder);
		while(fread(&Pro,sizeof(Product),1,fp_remainder))		
		{
			if(strcmp(Pay.Ex_Proid,Pro.id)==0)
			{
				if(Pay.Ex_qty>Pro.quantity)
				{	
					gotoxy(30,18);foreColor(150);cout<<"Your product has only "<<Pro.quantity;
					gotoxy(30,20);foreColor(135);cout<<"Press Enter to Input again";
					getch();
					goto put;
				}
			}
		}
		fclose(fp_remainder);
		fp_remainder=fopen("Remainder.txt","rb+");
		rewind(fp_remainder);
		while(fread(&Pro,sizeof(Product),1,fp_remainder))
		{
			if(strcmp(Pay.Ex_Proid,Pro.id)==0)	
			{
				if(Pay.Ex_qty<=Pro.quantity)
				{
					fseek(fp_remainder, -sizeof(Product), SEEK_CUR);
					contain=Pro.quantity-Pay.Ex_qty;
					Pro.quantity=contain;
					fwrite(&Pro,sizeof(Product),1,fp_remainder);	
					break;
				}
			}
		}	
		fclose(fp_remainder);
		gotoxy(60,8);cout<<"$ "<<Pay.Ex_price;
		r7:
		validateNumbers(60,10);Pay.Ex_discount=atoi(pass.c_str());
		if(pass==""){ goto r7;}
		gotoxy(60,10);cout<<Pay.Ex_discount;
		amount=Pay.Ex_price*Pay.Ex_qty;
		amount1=amount*Pay.Ex_discount/100;
		Pay.Ex_amount=amount-amount1;
		Pay.AmountTotal+=Pay.Ex_amount;
		gotoxy(60,12);cout<<"$ "<<amount;		
		gotoxy(60,14);cout<<"$ "<<amount1;		
		gotoxy(60,16);foreColor(150);cout<<"$ "<<Pay.Ex_amount;		
		fwrite(&Pay,sizeof(Payment),1,fp_payment);
		gotoxy(20,20);foreColor(135);cout<<"Press < Enter > to buy more or < Escape > to pay";
if(getch()==13)
{
	again:
	Interface(0);
	bang();
	saleMenus();
	gotoxy(27,6);cout<<Pay.Ex_customer;
	gotoxy(27,8);cout<<Pay.Ex_phone;
	gotoxy(27,10);cout<<Pay.Ex_date;
	again1:
	bang();
	foreColor(150);
	gotoxy(27,12);fflush(stdin);gets(Pay.Ex_Proid);	
	fp_remainder=fopen("Remainder.txt","rb");
	rewind(fp_remainder);
	b=0;
	while(fread(&Pro,sizeof(Product),1,fp_remainder))		
	{
			if(strcmp(Pay.Ex_Proid,Pro.id)==0)	
			{
				b=1;
				strcpy(Pay.Ex_product,Pro.name);
				Pay.Ex_product_of=Pro.productOf;
				///////////////////////////
				if(Pro.unitPrice>0 && Pro.unitPrice<=10){ Pay.Ex_price=Pro.unitPrice+1; }
				else if(Pro.unitPrice>10 && Pro.unitPrice<=20){ Pay.Ex_price=Pro.unitPrice+2; }
				else if(Pro.unitPrice>20 && Pro.unitPrice<=30){ Pay.Ex_price=Pro.unitPrice+3; }
				else if(Pro.unitPrice>40 && Pro.unitPrice<=50){ Pay.Ex_price=Pro.unitPrice+4; }
				else {  Pay.Ex_price=Pro.unitPrice+10; } 
				///////////////////////////
				gotoxy(30,18);foreColor(150);cout<<"Your product has only "<<Pro.quantity;
				if(Pro.quantity==0)
				{
					gotoxy(20,20);foreColor(135);cout<<"This Product ID is Empty..! Please Enter again.!";
					getch();
					goto again2;
				}
			}
	}
		if(b==0)
		{
			gotoxy(30,18);foreColor(135);cout<<"This Product ID is Empty..!";
			gotoxy(19,20);foreColor(135);cout<<"Press < Enter > to Input again or < Escape > to finish";
				if(getch()==13)
			{
				goto again1; 
			}
			else{ goto end1; }
		}
		fclose(fp_remainder);
		
		gotoxy(27,14);cout<<Pay.Ex_product;		
		gotoxy(27,16);cout<<Pay.Ex_product_of;		
		put1:
		r4:
		gotoxy(58,6);foreColor(150);cout<<"                 ";
		validateNumbers(60,6); Pay.Ex_qty=atoi(pass.c_str());
		if(Pay.Ex_qty==0){goto r4;}
		gotoxy(60,6); cout<<Pay.Ex_qty;
		///////////////////////////////////

//		validateNumbers(60,8);Pay.Ex_price=atoi(pass.c_str());
//		gotoxy(60,8);cout<<Pay.Ex_price;    

		///////////////////////////////////	
		fp_remainder=fopen("Remainder.txt","rb");
		rewind(fp_remainder);
		while(fread(&Pro,sizeof(Product),1,fp_remainder))		
		{
			if(strcmp(Pay.Ex_Proid,Pro.id)==0)
			{
				if(Pay.Ex_qty>Pro.quantity)
				{	
					gotoxy(30,18);foreColor(135);cout<<"Your product has only "<<Pro.quantity;
					gotoxy(30,20);foreColor(135);cout<<"Press Enter to Input again";
					getch();
					goto put1;
				}	
			}
		}
		fclose(fp_remainder);
		fp_remainder=fopen("Remainder.txt","rb+");
		rewind(fp_remainder);
		while(fread(&Pro,sizeof(Product),1,fp_remainder))
		{
			if(strcmp(Pay.Ex_Proid,Pro.id)==0)	
			{
				if(Pay.Ex_qty<=Pro.quantity)
				{
					fseek(fp_remainder, -sizeof(Product), SEEK_CUR);
					contain=Pro.quantity-Pay.Ex_qty;
					Pro.quantity=contain;
					fwrite(&Pro,sizeof(Product),1,fp_remainder);	
					break;
				}
			}
		}	
		fclose(fp_remainder);
		gotoxy(60,8);cout<<"$ "<<Pay.Ex_price;
		r6:
		validateNumbers(60,10); Pay.Ex_discount=atoi(pass.c_str());
		if(pass==""){ goto r6;}
		gotoxy(60,10); cout<<Pay.Ex_discount;
		amount=Pay.Ex_price*Pay.Ex_qty;
		amount1=amount*Pay.Ex_discount/100;
		Pay.Ex_amount=amount-amount1;
		Pay.AmountTotal+=Pay.Ex_amount;
		gotoxy(60,12);cout<<"$ "<<amount;		
		gotoxy(60,14);cout<<"$ "<<amount1;			
		gotoxy(60,16);foreColor(150);cout<<"$ "<<Pay.Ex_amount;		
		fwrite(&Pay,sizeof(Payment),1,fp_payment);
	gotoxy(20,20);foreColor(135);cout<<"Press < Enter > to buy more or < Escape > to pay";
	if(getch()==13)
	{
		goto again;
	}
}
}while(getch()!=27);
end:
end1:
bang();
gotoxy(15,18);foreColor(135);cout<<"Welcome to our stock!, "<<Pay.Ex_customer<<". Your Bill: "<<"$ "<<Pay.AmountTotal;		
	getch();
	Interface(0);
	fclose(fp_payment);
setcursor(0,0);
}
void Payment::showExport()
{
setcursor(0,0);
int ix=0,col=0;
float Total=0;
fp_payment=fopen("Payment.txt","rb");
rewind(fp_payment);
while(fread(&Pay,sizeof(Payment),1,fp_payment))
{
	stringstream pa[100][7];
	
		pa[ix][0]<<Pay.Ex_customer;
		pa[ix][1]<<Pay.Ex_product;
		pa[ix][2]<<Pay.Ex_discount;
		pa[ix][3]<<Pay.Ex_qty;
		pa[ix][4]<<Pay.Ex_price;	
		pa[ix][5]<<Pay.Ex_date;
		pa[ix][6]<<Pay.Ex_amount;
		Total+=Pay.Ex_amount;
		
		payment[ix][0]=pa[ix][0].str();
		payment[ix][1]=pa[ix][1].str();
		payment[ix][2]=pa[ix][2].str();
		payment[ix][3]=pa[ix][3].str();
		payment[ix][4]=pa[ix][4].str();
		payment[ix][5]=pa[ix][5].str();
		payment[ix][6]=pa[ix][6].str();
		ix++;
		if(ix>13){ col++; }
}		
fclose(fp_payment);
	Interface(col);
	paymentMenus(col);
	boxbox2(col);
float Total8=0,Total9=0;
do{
	string temp="";
	for(int i=0; i<ix; i++)
	{
		for(int j=i+1; j<ix; j++)
		{
			Total8= atof(payment[i][6].c_str());
			Total9=atof(payment[j][6].c_str());
			if( Total8 < Total9)
			{
				for(int l=0;l<7;l++)
				{
					temp=payment[i][l];
					payment[i][l]=payment[j][l];
					payment[j][l]=temp;
				}
			}
		}			
	}	
	for(int i=0; i<ix; i++)
	{
		gotoxy(14,6+i); foreColor(7);cout<<payment[i][0];		
		gotoxy(27,6+i); foreColor(7);cout<<payment[i][1];		
		gotoxy(39,6+i); foreColor(7);cout<<payment[i][2]<<" %";		
		gotoxy(45,6+i); foreColor(7);cout<<payment[i][3];		
		gotoxy(51,6+i); foreColor(7);cout<<"$ "<<payment[i][4];		
		gotoxy(57,6+i); foreColor(7);cout<<payment[i][5];		
		gotoxy(69,6+i); foreColor(6);cout<<"$ "<<payment[i][6];		
	}
		gotoxy(47,20+col); foreColor(6);cout<<"Total of product : ";foreColor(6);cout<<"$ ";foreColor(4);cout<<Total;
     	if(ix==0)
     	{
     		gotoxy(15,20+col); foreColor(2);cout<<"No Customer";	
		}
		else if(ix==1)
     	{
     		gotoxy(15,20+col); foreColor(2);cout<<"There is a Customer";	
		}
		else
     	{
     		gotoxy(15,20+col); foreColor(2);cout<<"There are ";foreColor(4);cout<<ix;foreColor(2);cout<<" Customers";	
		}
	}while(getch()!=27);
	Interface(0);
}
void Payment::searchExport()
{
int b,B;
char custom[30], ID[10],Date[15];
float Total=0;	
Interface(0);
int i=0,n1=0,n=0,col=0;		
gotoxy(14,4);foreColor(130);cout<<"Press key =>";
gotoxy(14,5);foreColor(130);cout<<"1.Search Customer's Name   2.Search Product ID   3.Search Date";
	switch(getch())
	{
		case '1':
			setcursor(1,0);
			start:
			Interface(0);
			fp_payment=fopen("Payment.txt","rb");
			rewind(fp_payment);
			gotoxy(25,4);cout<<"Input Customer's Name to Search :   ";gotoxy(58,4);gets(custom);
			paymentMenus(col);
			i=0;	
			b=0;
			col=0;
			while(fread(&Pay,sizeof(Payment),1,fp_payment))
			{
				if(strcmp(custom,Pay.Ex_customer)==0)
				{
					b=1;
					gotoxy(14,6+i); foreColor(7);cout<<	Pay.Ex_customer;
					gotoxy(27,6+i); foreColor(7);cout<<	Pay.Ex_product;
					gotoxy(39,6+i); foreColor(7);cout<<	Pay.Ex_discount<<" %";
					gotoxy(45,6+i); foreColor(7);cout<<	Pay.Ex_qty;
					gotoxy(51,6+i); foreColor(7);cout<<"$ "<< Pay.Ex_price;		
					gotoxy(57,6+i); foreColor(7);cout<< Pay.Ex_date;		
					gotoxy(69,6+i); foreColor(6);cout<<"$"<<Pay.Ex_amount;		
					Total+=Pay.Ex_amount;		
	     			i++;
	     			if(i>13)
	     			{
	     				col++;	
					}
	     		}
			}//while();
				boxbox2(col);
				gotoxy(15,20+col); foreColor(2);cout<<"Telephone : "<<Pay.Ex_phone;
				gotoxy(46,20+col); foreColor(6);cout<<"Total of product : ";foreColor(6);cout<<"$ ";foreColor(4);cout<<Total;	
				if(b==0)
				{
					gotoxy(15,20);foreColor(7);cout<<" Press Enter to search again or Arrow key up/down to finish ";
					if(getch()==13)
					{
						goto start;
					} 	
				}		
			fclose(fp_payment);
			setcursor(0,0);
	    break;
	    case '2':
			setcursor(1,0);
	    	start1:
			Interface(0);
			gotoxy(25,4);cout<<"Input Product ID to Search :  ";gotoxy(53,4);cin>>ID;
			paymentMenus(0);
			boxbox2(0);
			fp_payment=fopen("Payment.txt","rb");
			rewind(fp_payment);
			n=0;
			b=0;
			while(fread(&Pay,sizeof(Payment),1,fp_payment))
			{
				if(strcmp(ID,Pay.Ex_Proid)==0)
				{	b=1;
					gotoxy(14,6+n); foreColor(7);cout<<Pay.Ex_customer;
					gotoxy(27,6+n); foreColor(7);cout<<Pay.Ex_product;
					gotoxy(39,6+n); foreColor(7);cout<<Pay.Ex_discount<<" %";
					gotoxy(45,6+n); foreColor(7);cout<<Pay.Ex_qty;
					gotoxy(51,6+n); foreColor(7);cout<<"$ "<<Pay.Ex_price;		
					gotoxy(57,6+n); foreColor(7);cout<<Pay.Ex_date;		
					gotoxy(69,6+n); foreColor(6);cout<<"$ "<<Pay.Ex_amount;		
					Total+=Pay.Ex_amount;
					n++;
				}
			}//while();	
			gotoxy(46,20); foreColor(6);cout<<"Total of product : ";foreColor(6);cout<<"$ ";foreColor(4);cout<<Total;
			gotoxy(15,20); foreColor(2);cout<<"There are ";foreColor(4);cout<<n;foreColor(2);cout<<" Customers";
				if(b==0)
				{
					gotoxy(15,20);foreColor(7);cout<<" Press Enter to search again or Arrow key up/down to finish ";
					if(getch()==13)
					{
						goto start1;
					} 	
				}	
			fclose(fp_payment);
			setcursor(0,0);
			break;
			
			case '3':
			setcursor(1,0);
	    	start2:
			Interface(0);
			gotoxy(48,4);cout<<"dd/mm/yyyy";
			gotoxy(25,4);cout<<"Input Date to Search : ";
			validateNumbers(48,4); int c=pass.length(); char w9[c]; pass.copy(w9, c); w9[c] = '\0';
			paymentMenus(0);
			boxbox2(0);
			fp_payment=fopen("Payment.txt","rb");
			rewind(fp_payment);
			n1=0;
			B=0;
			while(fread(&Pay,sizeof(Payment),1,fp_payment))
			{
				if(strcmp(Pay.Ex_date,w9)==0)
				{	B=1;
					gotoxy(14,6+n1); foreColor(7);cout<< Pay.Ex_customer;
					gotoxy(27,6+n1); foreColor(7);cout<< Pay.Ex_product;
					gotoxy(39,6+n1); foreColor(7);cout<< Pay.Ex_discount<<" %";
					gotoxy(45,6+n1); foreColor(7);cout<< Pay.Ex_qty;
					gotoxy(51,6+n1); foreColor(7);cout<<"$ "<< Pay.Ex_price;		
					gotoxy(57,6+n1); foreColor(7);cout<< Pay.Ex_date;		
					gotoxy(69,6+n1); foreColor(6);cout<<"$ "<< Pay.Ex_amount;		
					Total+=Pay.Ex_amount;
					n1++;
				}
			}//while();
			gotoxy(46,20); foreColor(6);cout<<"Total of product : ";foreColor(6);cout<<"$ ";foreColor(4);cout<<Total;		    
			gotoxy(15,20); foreColor(2);cout<<"There are ";foreColor(4);cout<<n1;foreColor(2);cout<<" Customers";
				if(B==0)
				{
					gotoxy(15,20);foreColor(7);cout<<" Press Enter to search again or Arrow key up/down to finish ";
					if(getch()==13)
					{
						goto start2;
					} 	
				}		
			fclose(fp_payment);
			setcursor(0,0);
			break;
	  }//switch();
}//search();

void Payment::deleteExport(){
int b=0,c=0;
char custom[30],date[12];
Interface(0);
gotoxy(14,4);foreColor(130);cout<<"Press key =>";
gotoxy(14,5);foreColor(130);cout<<"1.Delete Customer's Name   2.Delete by Date   3.Delete All";
switch(getch()){
case '1':
		setcursor(1,0);
		fp_payment=fopen("Payment.txt","rb");
		fp_payment1=fopen("Payment1.txt","wb");
		rewind(fp_payment);
		start3:
		Interface(0);
		gotoxy(25,4);foreColor(2);cout<<"Input Customer's Name to Delete :   ";gotoxy(59,4);gets(custom);
		b=0;
		while(fread(&Pay,sizeof(Payment),1,fp_payment))
		{
			if(strcmp(custom,Pay.Ex_customer)!=0)
			{
				fwrite(&Pay,sizeof(Payment),1,fp_payment1);
			}
			if(strcmp(custom,Pay.Ex_customer)==0)
			{
				b=1;
				gotoxy(33,20);foreColor(4);cout<<"Deleted successfully..!";
			}
		}
		if(b==0)
		{
			gotoxy(29,18);foreColor(135);cout<<"This Customer's Name is not found..!";
			gotoxy(17,20);foreColor(135);cout<<"Press Enter to search again or Arrow key up/down to finish";
			if(getch()==13)
			{
				goto start3;
			} 	
		}	
		fclose(fp_payment);
		fclose(fp_payment1);
		remove("Payment.txt");
		rename("Payment1.txt","Payment.txt");
	setcursor(0,0);
   break;
   
case '2':
	setcursor(1,0);
	fp_payment=fopen("Payment.txt","rb");
	fp_payment1=fopen("Payment1.txt","wb");
	rewind(fp_payment);
	start4:
	Interface(0);
	gotoxy(48,4);foreColor(2);cout<<"dd/mm/yyyy";
	gotoxy(25,4);foreColor(2);cout<<"Input Date to Delete : ";//cin>>Date;
	validateNumbers(48,4); c=pass.length(); date[c]; pass.copy(date, c); date[c] = '\0';
	//validateNumbers(48,4); int c=pass.length(); char w[c]; pass.copy(w, c); w[c] = '\0';
	b=0;
while(fread(&Pay,sizeof(Payment),1,fp_payment))
{
	if(strcmp(Pay.Ex_date,date)!=0)
	{
		fwrite(&Pay,sizeof(Payment),1,fp_payment1);
	}
	if(strcmp(Pay.Ex_date,date)==0)
	{
		b=1;
		gotoxy(33,20);foreColor(4);cout<<"Deleted successfully..!";
	}
}//while
		if(b==0)
		{
			gotoxy(32,18);foreColor(135);cout<<"This Date is not found..!";
			gotoxy(17,20);foreColor(135);cout<<"Press Enter to search again or Arrow key up/down to finish";
			if(getch()==13)
			{
				goto start4;
			} 	
		}	

	fclose(fp_payment);
	fclose(fp_payment1);
	remove("Payment.txt");
	rename("Payment1.txt","Payment.txt");
   break;
   case '3':	
	boxfunction1(27,6,31,3);
   	gotoxy(30,7);foreColor(135);cout<<"Are you Sure to Delete All ?";	
   	gotoxy(30,9);foreColor(135);cout<<"ENTER =>YES     Up/Down =>NO";	
   	if(getch()==13)
   	{
		fp_payment=fopen("Payment.txt","rb");
		rewind(fp_payment);
		while(fread(&Pay,sizeof(Payment),1,fp_payment))	
		fclose(fp_payment);
		remove("Payment.txt");
		gotoxy(33,20);foreColor(4);cout<<"Deleted successfully..!";
		getch();
	}	
	setcursor(0,0);
	break;
 }//switch();
}
void About(){
setcursor(0,0);
information();
	for(int i=0;i<20;i++)	
	{
	gotoxy(44+i,5);	foreColor(130);cout<<"*";
	gotoxy(44+i,20);foreColor(130);cout<<"*";
	gotoxy(43-i,5);	foreColor(130);cout<<"*";
	gotoxy(43-i,20);foreColor(130);cout<<"*";
	gotoxy(44+i,7);foreColor(130);cout<<"*";
	gotoxy(43-i,7);foreColor(130);cout<<"*";
	gotoxy(44+i,18);foreColor(130);cout<<"*";
    gotoxy(43-i,18);foreColor(130);cout<<"*";
	delay(30);
	}//for
	do{
		gotoxy(36,19);foreColor(130);cout<<"NO ONE IS PERFECT";
		 gotoxy(30,9);foreColor(150);cout<<"                            ";
		gotoxy(30,10);foreColor(150);cout<<"   Teacher:SIM SOVANDETH    ";
		gotoxy(30,11);foreColor(150);cout<<"        MR.LAI THOURA       ";
		gotoxy(30,12);foreColor(150);cout<<"          R U P P           ";
		gotoxy(30,13);foreColor(150);cout<<"         012403032          ";
		gotoxy(30,14);foreColor(150);cout<<"    laithoura@gmail.com     ";
		gotoxy(30,15);foreColor(150);cout<<"     Copyright(c) 2016      ";		
		gotoxy(30,16);foreColor(150);cout<<"                            ";
	}while(getch()!=27);				
	Interface(0);
}

void createAccount()
{ 
int b=0;
int n=1;
setcursor(1,0);
	fp_product=fopen("Login.txt","rb");
	rewind(fp_product);
	again:       
       	for(int i=0;i<29;i++)
       	{
       		for(int j=0;j<5;j++)	
       		{
       			gotoxy(29+i,9);foreColor(150);cout<<(char)0;
       			gotoxy(31+i,11+j);foreColor(0);cout<<(char)0;
       			gotoxy(29+i,10+j);foreColor(180);cout<<(char)0;
       		}
		}	
		gotoxy(29,9);foreColor(150);cout<<" Create Account ";
	    gotoxy(31,11);foreColor(110);cout<<" Username :";
	    gotoxy(31,13);foreColor(110);cout<<" Password :";
	    gotoxy(42,11);foreColor(110);cout<<"              ";
	    gotoxy(42,13);foreColor(110);cout<<"              ";	    
		r8:
	    validateCharacters(43,11); int a = cha1.length();char user[a]; cha1.copy(user, a); user[a] = '\0';	  
		if(strcmp(user,"")==0){ goto r8;}
		r9:
		Password(43,13); int a1=password.length();char pass1[a1];password.copy(pass1,a1);pass1[a1]='\0';			
		if(strcmp(pass1,"")==0){ goto r9;}
	b=0;
	while(fread(&Create,sizeof(Product),1,fp_product))
	{
		if(strcmp(Create.User ,user)==0 || strcmp(user,"admin")==0)
		{	
			b=1;	
			gotoxy(22,17);foreColor(135);cout<<" Already Exist..! Enter to Input new username ";
			gotoxy(28,19); foreColor(135);cout<<"Press Arrow key up/down to finish";
			if(getch()==13)
			{			
				user=="";
				pass1=="";
				for(int i=0;i<50;i++)
				{ gotoxy(22+i,17);foreColor(135);cout<<char(0);
				  gotoxy(22+i,19);foreColor(135);cout<<char(0);
				}
				goto again; 
			}
			else { break;}											
		}
		n++;		
	}
	fclose(fp_product);

	if(b==0 && n<=10)
	{		
	   		fp_product=fopen("Login.txt","a+b");
			rewind(fp_product);
			strcpy(Create.User,user);	
			strcpy(Create.Pass,pass1);	
			fwrite(&Create,sizeof(Product),1,fp_product);
			fclose(fp_product);
			gotoxy(29,17); foreColor(135);cout<<"Press Arrow key up/down to finish";		
	}
	if(b==0 && n>10) 
	{
		for(int i=0;i<50;i++)
		{ 
			gotoxy(22+i,17);foreColor(135);cout<<char(0);
		}
	    gotoxy(28,17);foreColor(135);cout<<"You can create only 10 user accounts";
		gotoxy(29,19); foreColor(135);cout<<"Press Arrow key up/down to finish";		
	}
setcursor(0,0);
}

int main(){
login();
foreColor(0);
Home:
setcursor(0,0);
int press=0;
Interface(0);
while(1){
	switch(getch())
	{
		case 77:
		y=4;
		press=(press<5)? press+1 : 0 ;
		for(int i=0;i<6;i++)
		{
			if(i==press)
			{
				gotoxy(y,1);foreColor(282);cout<<mainMenus[i];
			}
			else
			{
				gotoxy(y,1);foreColor(444);cout<<mainMenus[i];
			}
			y+=11;
		}
		break;
		case 75:
		y=4;
		press=(press<=0)? 5 : press-1;
		for(int i=0;i<6;i++)
		{
			if(i==press)
			{
				gotoxy(y,1);foreColor(282);cout<<mainMenus[i];
			}
			else
			{
				gotoxy(y,1);foreColor(444);cout<<mainMenus[i];
			}
			y+=11;
		}	
		break;	
		case 13:
			foreColor(0);
			if(press==5)
			{
				setcursor(0,0);
				boxfunction(26,12,40,1);
				for(int i=0;i<40;i++)
				{
	  				gotoxy(28,12);foreColor(150);cout<<"Finshing";		
					gotoxy(27+i,13);foreColor(180);cout<<(char)0;
					gotoxy(28,14);foreColor(150);cout<<61+i<<" %";		
					delay(10);
				}
				exit(0); 
			}
			else if(press==0)
			{
				string Main[]={"  Export  "," In Stock ","  Import  ","  Staff   ","  Login   ","  Back    "};
				int press1=0;
				int y=3;
				boxfunction(1,2,10,12);
				for(int i=0;i<6;i++)
				{	
					if(i==0)
					{
						gotoxy(2,y);foreColor(180);cout<<Main[i];
					}
					else 
					{
						gotoxy(2,y);foreColor(150);cout<<Main[i];
					}
						y+=2;
				}
					
					while(1)
					{
						boxfunction(12,2,65,19);
						switch(getch()){
					case 80:
						boxfunction(1,2,10,12);
						y=3;
						press1=(press1<5)? press1+1:0;
					for(int i=0;i<6;i++)
					{
						if(i==press1)
						{
							gotoxy(2,y);foreColor(180);cout<<Main[i];
						}
						else 
						{
							gotoxy(2,y);foreColor(150);cout<<Main[i];
						}
						y+=2;
					}	
					break;	
					
					case 72:
					boxfunction(1,2,10,12);
					y=3;
					press1=(press1<=0)? 5 : press1-1;
					for(int i=0;i<6;i++)
					{
						if(i==press1)
						{
							gotoxy(2,y);foreColor(180);cout<<Main[i];
						}
						else 
						{
							gotoxy(2,y);foreColor(150);cout<<Main[i];
						}
						y+=2;
					}	
					break;
					
					case 13:
					if(press1==0)
					{
						Pay.showExport();
					}
					else if(press1==1)
					{
						showRemainderProduct();
					}
					else if(press1==2)
					{
						showProduct();					
					}
					
					else if(press1==3)
					{
						St.showStaff();
					}
					else if(press1==4)
					{
						createAccount();
					}
					else if(press1==5)
					{
						goto Home;
					}
					break;	
			      }//switch
			      
 			    }//while;
			
			}//Main
			
			else if(press==1)
			{
				
				string staff[]={"  Add     ",
							    "  Show    ",
							    "  Edit    ",
							    "  Delete  ",
							    "  Search  ",
							    "  Back    "};
				int press2=0;
				int y=3;
				boxfunction(1,2,10,12);
				
				for(int i=0;i<6;i++)
				{	
					if(i==0)
					{
						gotoxy(2,y);foreColor(180);cout<< staff[i];
					}
					else 
					{
						gotoxy(2,y);foreColor(150);cout<< staff[i];
					}
						y+=2;
					}
					while(1)
					{
					boxfunction(12,2,65,19);
					switch(getch()){
					case 80:
					boxfunction(1,2,10,12);
					y=3;
					press2=(press2<5)? press2+1:0;
					for(int i=0;i<6;i++)
					{
						if(i==press2)
						{
							gotoxy(2,y);foreColor(180);cout<< staff[i];
						}
						else 
						{
							gotoxy(2,y);foreColor(150);cout<< staff[i];
						}
						y+=2;
					}	
					break;	
					case 72:
					boxfunction(1,2,10,12);
					y=3;
					press2=(press2<=0)? 5 : press2-1;
					for(int i=0;i<6;i++)
					{
						if(i==press2)
						{
							gotoxy(2,y);foreColor(180);cout<< staff[i];
						}
						else 
						{
							gotoxy(2,y);foreColor(150);cout<< staff[i];
						}
						y+=2;
					}	
					break;
					case 13:					
					y=3;
					for(int i=0;i<6;i++)
					{	
					if(i==0)
					{
					gotoxy(2,y);foreColor(180);cout<< staff[i];
					}
					else 
					{
					gotoxy(2,y);foreColor(150);cout<< staff[i];
					}
						y+=2;
					}
				
					if(press2==0)
					{
						St.addStaff();
					}
					
					else if(press2==1)
					{
						St.showStaff();
					}
					else if(press2==2)
					{
						St.editStaff();
					}
					
					else if(press2==3)
					{
						St.deleteStaff();	
					}
					else if(press2==4)
					{
						St.searchStaff();
					}
					else if(press2==5)
					{
						goto Home;
					}
					break;	
			      }//switch
 			    }//while
			}//Staff
			else if(press==2)
			{
				string Goods[]={"  Add     ",
							    "  Show    ",
							    "  Edit    ",
							    "  Delete  ",
							    "  Search  ",
							    "  Back    "};
				int press3=0;
				int y=3;
				boxfunction(1,2,10,12);
				for(int i=0;i<6;i++)
				{	
					if(i==0)
					{
					gotoxy(2,y);foreColor(180);cout<< Goods[i];
					}
					else 
					{
					gotoxy(2,y);foreColor(150);cout<< Goods[i];
					}
						y+=2;
					}
					while(1)
					{
					boxfunction(12,2,65,19);
					switch(getch()){
					case 80:
					boxfunction(1,2,10,12);
					y=3;
					press3=(press3<5)? press3+1:0;
					for(int i=0;i<6;i++)
					{
						if(i==press3)
						{
							gotoxy(2,y);foreColor(180);cout<< Goods[i];
						}
						else 
						{
							gotoxy(2,y);foreColor(150);cout<< Goods[i];
						}
						y+=2;
					}	
					break;	
					case 72:
					boxfunction(1,2,10,12);
					y=3;
					press3=(press3<=0)? 5 : press3-1;
					for(int i=0;i<6;i++)
					{
						if(i==press3)
						{
							gotoxy(2,y);foreColor(180);cout<< Goods[i];
						}
						else 
						{
							gotoxy(2,y);foreColor(150);cout<< Goods[i];
						}
						y+=2;
					}	
					break;
					case 13:
					Interface(0);
					if(press3==0)
					{
						addProduct();
					}
					else if(press3==1)
					{
						showProduct();
					}
					else if(press3==2)
					{
						editProduct();
					}
					else if(press3==3)
					{
						deleteProduct();					
					}
					else if(press3==4)
					{
						searchProduct();
					}
					else if(press3==5)
					{
						goto Home;
					}
					break;	
			      }//switch
 			    }//while
			}//product
			else if(press==3)
			{
				string Payment[]={"  Pay     ",
								  "  Show    ",
								  "  Search  ",
								  "  Delete  ",								 
								  "  Back    "};
				int press4=0;
				int y=3;
				boxfunction(1,2,10,10);
				for(int i=0;i<5;i++)
				{	
					if(i==0)
					{
					gotoxy(2,y);foreColor(180);cout<<Payment[i];
					}
					else 
					{
					gotoxy(2,y);foreColor(150);cout<<Payment[i];
					}
						y+=2;
					}
					while(1)
					{
					boxfunction(12,2,65,19);
					switch(getch()){
					case 80:
					boxfunction(1,2,10,10);
					y=3;
					press4=(press4<4)? press4+1:0;
					for(int i=0;i<5;i++)
					{
						if(i==press4)
						{
							gotoxy(2,y);foreColor(180);cout<<Payment[i];
						}
						else 
						{
							gotoxy(2,y);foreColor(150);cout<<Payment[i];
						}
						y+=2;
					}	
					break;	
					case 72:
					boxfunction(1,2,10,10);
					y=3;
					press4=(press4<=0)? 4 : press4-1;
					for(int i=0;i<5;i++)
					{
						if(i==press4)
						{
							gotoxy(2,y);foreColor(180);cout<<Payment[i];
						}
						else 
						{
							gotoxy(2,y);foreColor(150);cout<<Payment[i];
						}
						y+=2;
					}	
					break;
					case 13:
					if(press4==0)
					{
						Pay.saleProduct();
					}
					else if(press4==1)
					{
						Pay.showExport();
					}
					else if(press4==2)
					{
						Pay.searchExport();	
					}
					else if(press4==3)
					{
							Pay.deleteExport();
					}
					else if(press4==4)
					{
						goto Home;
					}
					break;	
			      }//switch
 			    }//while
			}//Payment
		else if(press==4)
		{	
			About();
		}
		break;				
	}//switch
}//while
	return 0;
}

void boxbox(int col)
{
	for(int i=13; i<=76; i++)
	{
		gotoxy(i,3);cout<<(char)196;
		gotoxy(i,21+col);cout<<(char)196; 
		gotoxy(i,19+col);cout<<(char)196; 
		gotoxy(77,5);cout<<(char)180; 
		gotoxy(i+1,5);cout<<(char)196; 
		gotoxy(13,5);cout<<(char)195; 
	}
	for(int i=3; i<=(20+col); i++)
	{
		gotoxy(13, i);cout<<(char)179;		
		gotoxy(77, i);cout<<(char)179;		
	}
	for(int i=3;i<(19+col);i++)
	{
		gotoxy(19, i);cout<<(char)179;					
		gotoxy(36, i);cout<<(char)179;				
		gotoxy(45, i);cout<<(char)179;			
		gotoxy(52, i);cout<<(char)179;
		gotoxy(66, i);cout<<(char)179;
	}
		gotoxy(19,3);cout<<(char)194; 
		gotoxy(36,3);cout<<(char)194;
		gotoxy(45,3);cout<<(char)194;
		gotoxy(52,3);cout<<(char)194;
		gotoxy(66,3);cout<<(char)194;
		
		gotoxy(19,5);cout<<(char)197;
		gotoxy(36,5);cout<<(char)197;
		gotoxy(45,5);cout<<(char)197;
		gotoxy(52,5);cout<<(char)197;
		gotoxy(66,5);cout<<(char)197;
		
		gotoxy(19,19+col);cout<<(char)193;
		gotoxy(36,19+col);cout<<(char)193;
		gotoxy(45,19+col);cout<<(char)193;	
		gotoxy(52,19+col);cout<<(char)193;	
		gotoxy(66,19+col);cout<<(char)193;	
		
		gotoxy(13,3);cout<<(char)218;
		gotoxy(77,3);cout<<(char)191;
		gotoxy(13,21+col);cout<<(char)192;
		gotoxy(77,21+col);cout<<(char)217;
}// box............................

void boxbox1(int col)
{
	for(int i=13; i<=76; i++)
	{
		gotoxy(i,3);cout<<(char)196;
		gotoxy(i,21+col);cout<<(char)196;  
		gotoxy(i,19+col);cout<<(char)196;  
		gotoxy(77,5);cout<<(char)180; 
		gotoxy(i+1,5);cout<<(char)196;
		gotoxy(13,5);cout<<(char)195; 
	}
	for(int i=3; i<=20+col; i++)
	{
		gotoxy(13, i);cout<<(char)179;		
		gotoxy(77, i);cout<<(char)179;		
	}
	for(int i=3;i<19+col;i++)
	{
		gotoxy(19, i);cout<<(char)179;					
		gotoxy(33, i);cout<<(char)179;				
		gotoxy(39, i);cout<<(char)179;			
		gotoxy(46, i);cout<<(char)179;
		gotoxy(58, i);cout<<(char)179;
		gotoxy(66, i);cout<<(char)179;
	}
		gotoxy(19,3);cout<<(char)194; 
		gotoxy(33,3);cout<<(char)194;
		gotoxy(39,3);cout<<(char)194;
		gotoxy(46,3);cout<<(char)194;
		gotoxy(58,3);cout<<(char)194;
		gotoxy(66,3);cout<<(char)194;
		
		gotoxy(19,5);cout<<(char)197;
		gotoxy(33,5);cout<<(char)197;
		gotoxy(39,5);cout<<(char)197;
		gotoxy(46,5);cout<<(char)197;
		gotoxy(58,5);cout<<(char)197;
		gotoxy(66,5);cout<<(char)197;
		
		gotoxy(19,19+col);cout<<(char)193;
		gotoxy(33,19+col);cout<<(char)193;
		gotoxy(39,19+col);cout<<(char)193;	
		gotoxy(46,19+col);cout<<(char)193;	
		gotoxy(58,19+col);cout<<(char)193;	
		gotoxy(66,19+col);cout<<(char)193;	
		
		gotoxy(13,3);cout<<(char)218;
		gotoxy(77,3);cout<<(char)191;
		gotoxy(13,21+col);cout<<(char)192;
		gotoxy(77,21+col);cout<<(char)217;
}// box............................

void boxbox2(int col)
{
	for(int i=13; i<=76; i++)
	{
		gotoxy(i,3);cout<<(char)196;
		gotoxy(i,21+col);cout<<(char)196;  
		gotoxy(i,19+col);cout<<(char)196;  
		gotoxy(77,5);cout<<(char)180; 
		gotoxy(i+1,5);cout<<(char)196; 
		gotoxy(13,5);cout<<(char)195; 
	}
	for(int i=3; i<=20+col; i++)
	{
		gotoxy(13, i);cout<<(char)179;		
		gotoxy(77, i);cout<<(char)179;		
	}
	for(int i=3;i<19+col;i++)
	{
		gotoxy(26, i);cout<<(char)179;					
		gotoxy(38, i);cout<<(char)179;					
		gotoxy(43, i);cout<<(char)179;			
		gotoxy(49, i);cout<<(char)179;
		gotoxy(56, i);cout<<(char)179;
		gotoxy(68, i);cout<<(char)179;
	}
		gotoxy(26,3);cout<<(char)194; 
		gotoxy(38,3);cout<<(char)194; 
		gotoxy(43,3);cout<<(char)194;
		gotoxy(49,3);cout<<(char)194;
		gotoxy(56,3);cout<<(char)194;
		gotoxy(68,3);cout<<(char)194;
		
		gotoxy(26,5);cout<<(char)197;
		gotoxy(38,5);cout<<(char)197;
		gotoxy(43,5);cout<<(char)197;
		gotoxy(49,5);cout<<(char)197;
		gotoxy(56,5);cout<<(char)197;
		gotoxy(68,5);cout<<(char)197;
		
		gotoxy(26,19+col);cout<<(char)193;
		gotoxy(38,19+col);cout<<(char)193;
		gotoxy(43,19+col);cout<<(char)193;	
		gotoxy(49,19+col);cout<<(char)193;	
		gotoxy(56,19+col);cout<<(char)193;	
		gotoxy(68,19+col);cout<<(char)193;	
		
		gotoxy(13,3);cout<<(char)218;
		gotoxy(77,3);cout<<(char)191;
		gotoxy(13,21+col);cout<<(char)192;
		gotoxy(77,21+col);cout<<(char)217;
}// box............................

void boxfunction(int x,int y, int w,int h)
{
	foreColor(150);
	for(i=0;i<=w;i++)
	{	
		gotoxy(x+i,y);cout<<(char)196;	
		gotoxy(x+i,y+h+1);cout<<(char)196;
	}
	for(i=0;i<=h;i++)
	{	
		gotoxy(x,y+i);cout<<(char)179;
		gotoxy(x+w+1,y+i);cout<<(char)179;
	}
		gotoxy(x,y);cout<<(char)218;	
		gotoxy(x+w+1,y+h+1);cout<<(char)217;
		gotoxy(x,y+h+1);cout<<(char)192;	
		gotoxy(x+w+1,y);cout<<(char)191;	
		foreColor(0);
}//box();
void boxfunction1(int x,int y, int w,int h)
{
	foreColor(135);
	for(i=0;i<=w;i++)
	{	
		gotoxy(x+i,y);cout<<(char)196;	
		gotoxy(x+i,y+h+1);cout<<(char)196;
	}
	for(i=0;i<=h;i++)
	{	
		gotoxy(x,y+i);cout<<(char)179;
		gotoxy(x+w+1,y+i);cout<<(char)179;
	}
		gotoxy(x,y);cout<<(char)218;	
		gotoxy(x+w+1,y+h+1);cout<<(char)217;
		gotoxy(x,y+h+1);cout<<(char)192;	
		gotoxy(x+w+1,y);cout<<(char)191;	
		foreColor(0);
}//box();
void Interface(int col){
//cls();
foreColor(0);
for(int i=2;i<12;i++)
{
	for(int j=3;j<22+col;j++)
	{
		gotoxy(i,j);foreColor(110);cout<<(char)0;
	}
}
for(int i=3;i<23+col;i++)
{
	gotoxy(12,i);foreColor(135);cout<<"                                  ";
	gotoxy(46,i);foreColor(135);cout<<"                                  ";
}
for(int i=0;i<80;i++)
{
	gotoxy(i,1);foreColor(120);cout<<(char)0;
	gotoxy(i,23+col);foreColor(0);cout<<(char)0;
}
gotoxy(68,1);foreColor(120);cout<<__DATE__;
int y=4;
boxfunction(1,2,76,19+col);
boxfunction(0,0,78,23+col);
for(int i=0;i<6;i++)
{
	if(i==0)
	{
		gotoxy(y,1);foreColor(282);cout<<mainMenus[i];
	}
	else
	{
		gotoxy(y,1);foreColor(444);cout<<mainMenus[i];
	}
	y+=11;
}
boxfunction(1,2,10,19+col);
gotoxy(41,23+col);foreColor(2);cout<<"Enter < Select >";
gotoxy(61,23+col);foreColor(4);cout<<"Escape < Finish >";
gotoxy(2,23+col);foreColor(2);cout<<"Right ->";
gotoxy(12,23+col);foreColor(2);cout<<"Left <-";
gotoxy(23,23+col);foreColor(2);cout<<"Down ";
gotoxy(33,23+col);foreColor(2);cout<<"Up ";
}//interface();

void stock()
{
	system("COLOR 9B");
	do{
	cls();
		for(int i=0;i<3;i++)	
		{
			gotoxy(14,6+i);foreColor(180);cout<<(char)0;
			gotoxy(15,6+i);foreColor(180);cout<<(char)0;
			gotoxy(21,9+i);foreColor(180);cout<<(char)0;	
			gotoxy(22,9+i);foreColor(180);cout<<(char)0;	
		
			gotoxy(28,7+i);foreColor(180);cout<<(char)0;	
			gotoxy(29,7+i);foreColor(180);cout<<(char)0;	
			gotoxy(28,10+i);foreColor(180);cout<<(char)0;	
			gotoxy(29,10+i);foreColor(180);cout<<(char)0;	
		
			gotoxy(43,7+i);foreColor(180);cout<<(char)0;	
			gotoxy(44,7+i);foreColor(180);cout<<(char)0;		
			gotoxy(35,7+i);foreColor(180);cout<<(char)0;	
			gotoxy(36,7+i);foreColor(180);cout<<(char)0;
			
			gotoxy(35,10+i);foreColor(180);cout<<(char)0;	
			gotoxy(36,10+i);foreColor(180);cout<<(char)0;		
			gotoxy(43,10+i);foreColor(180);cout<<(char)0;	
			gotoxy(44,10+i);foreColor(180);cout<<(char)0;	
			
			gotoxy(46,7+i);foreColor(180);cout<<(char)0;	
			gotoxy(47,7+i);foreColor(180);cout<<(char)0;	
			gotoxy(46,10+i);foreColor(180);cout<<(char)0;	
			gotoxy(47,10+i);foreColor(180);cout<<(char)0;
			
			gotoxy(58,7+i);foreColor(180);cout<<(char)0;	
			gotoxy(59,7+i);foreColor(180);cout<<(char)0;	
			gotoxy(58,10+i);foreColor(180);cout<<(char)0;	
			gotoxy(59,10+i);foreColor(180);cout<<(char)0;			
		}
		for(int i=0;i<9;i++)
		{
			gotoxy(14+i,9);foreColor(180);cout<<(char)0;
			gotoxy(14+i,6);foreColor(180);cout<<(char)0;
			gotoxy(14+i,12);foreColor(180);cout<<(char)0;
		}
		for(int i=0;i<10;i++)
		{
		 	gotoxy(24+i,6);foreColor(180);cout<<(char)0;
			gotoxy(35+i,6);foreColor(180);cout<<(char)0;
			gotoxy(35+i,12);foreColor(180);cout<<(char)0;
			gotoxy(46+i,6);foreColor(180);cout<<(char)0;
			gotoxy(46+i,12);foreColor(180);cout<<(char)0;
		}
		gotoxy(61,9);foreColor(180);cout<<(char)0;
		gotoxy(60,9);foreColor(180);cout<<(char)0;
		gotoxy(62,8);foreColor(180);cout<<(char)0;
		gotoxy(63,8);foreColor(180);cout<<(char)0;
	
		gotoxy(64,7);foreColor(180);cout<<(char)0;
		gotoxy(65,7);foreColor(180);cout<<(char)0;
		
		gotoxy(64,6);foreColor(180);cout<<(char)0;
		gotoxy(65,6);foreColor(180);cout<<(char)0;
	
		gotoxy(62,10);foreColor(180);cout<<(char)0;
		gotoxy(63,10);foreColor(180);cout<<(char)0;
		
		gotoxy(64,11);foreColor(180);cout<<(char)0;
		gotoxy(65,11);foreColor(180);cout<<(char)0;
		
		gotoxy(64,12);foreColor(180);cout<<(char)0;
		gotoxy(65,12);foreColor(180);cout<<(char)0;
		
		gotoxy(58,6);foreColor(180);cout<<(char)0;
		gotoxy(59,6);foreColor(180);cout<<(char)0;	
		gotoxy(23,15);foreColor(155);cout<<" M A N A G E M E N T   S Y S T E M ";		
		gotoxy(27,18);foreColor(155);cout<<"<< Press Key to Continue >>";
		for(int i=0;i<13;i++)
		{
			gotoxy(26-i,18);foreColor(159);cout<<"<";
			gotoxy(54+i,18);foreColor(159);cout<<">";
			delay(150);
		}
	}while(!kbhit());
}



