#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <cctype>
#include <string>
#include <limits>

char str[10];
int n=0,num=-1;
FILE *f;
FILE *g;
struct Gun
{
int tip_or;
char kraina[15];
char nazvanie[16];
float kalibr;
int waga;
int dowj;
int emnist;
char vidpow[21];
};

int size=sizeof(struct Gun);
struct Gun tov;
int File_prov();	//�������� �� ������� �����;
int All_weap();		//����� ������ �� �������;
void Vved();		//���� ������ � �������;
void Tabl_shapka(); //������� ����� �������;
void Table_end();  //������ ����� �������;
void Viddil();
void Str_viddil(int k); //������������ ����� � ������;
void Radok(int n); //����� ������;

void DeleteMenu(); //��������(����);
void Delete1();		//��������(��� ������);
void Delete2();		 //��������(������-�������������);

void Sort_menu(); //����������(����);
void Sort1();	//���������� �� ��������;
void Sort2();	//���������� �� ��������;

void Zapit_menu();
void Zapit1();
void Zapit2();
void Zapit3();
void Zapit4();
void Zapit5();

using namespace std;
int main()
{
	system("color F0");
	system("chcp 1251 >nul");
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
char p_m[80]; //����� ����
do {
system("cls");
start:
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
cout << endl << endl << "\n\t������� ���� ��������:" <<endl;
cout << endl << "\t1.�������� ����� ��� �����";           //Vved();
cout << endl << "\t2.�������� ��i�� ���� � ��� �����"; //All_weap();
cout << endl << "\t3.��������� ������";  //Zapit_menu();
cout << endl << "\t4.���������� ������";   //Sort_weap();
cout << endl << "\t5.��������� ������";    //Delete_menu();
cout << endl << "\t6.���i� � ��������";
cout << endl << endl << "\t����i�� ����� ����:";
cin >> p_m;
switch (p_m[0])
{
case '1':Vved(); break;
case '2':All_weap(); break;
case '3':Zapit_menu(); break;
case '4':Sort_menu(); break;
case '5':DeleteMenu(); break;
case '6':cout << endl << "ʳ���� ������"; getch();return 0;
default:system("cls");
cout << endl << endl << "������ �����o!";
goto start;
}
}// end do
while (p_m[0] != '6');//����� �����
_getch();
return 0;
}
void Tabl_shapka()
{
 	SetConsoleOutputCP(866);
cout << endl << "��������������������������������������������������������������������������������������������������������Ŀ";
cout <<endl<<"� ";
SetConsoleOutputCP(1251);
cout << " ���     ";
	
 	SetConsoleOutputCP(866);
cout << "� ";
SetConsoleOutputCP(1251);
cout << "    ����� -    ";
 	SetConsoleOutputCP(866);
cout <<"� ";
SetConsoleOutputCP(1251);
cout <<"  ����� ����   ";
 	SetConsoleOutputCP(866);
cout << "� ";
SetConsoleOutputCP(1251);
cout << "����� ";
 	SetConsoleOutputCP(866);
cout <<"� ";
SetConsoleOutputCP(1251);
cout <<"���� ";
 	SetConsoleOutputCP(866);
cout <<"� ";
SetConsoleOutputCP(1251);
cout <<"������� ";
 	SetConsoleOutputCP(866);
cout <<"� ";
SetConsoleOutputCP(1251);
cout <<"������ ";
 	SetConsoleOutputCP(866);
cout <<"�";
SetConsoleOutputCP(1251);
cout <<"   ³�����������    ";
 	SetConsoleOutputCP(866);
cout <<"�";
cout << endl ;
 	SetConsoleOutputCP(866);
cout <<"�";
SetConsoleOutputCP(1251);
cout <<"  ����   ";
 	SetConsoleOutputCP(866);
cout <<"�";
SetConsoleOutputCP(1251);
cout <<"    ��������     ";
 	SetConsoleOutputCP(866);
cout <<"�                 ";
cout <<"�";
SetConsoleOutputCP(1251);
cout <<"   (��) ";
 	SetConsoleOutputCP(866);
cout <<"�";
SetConsoleOutputCP(1251);
cout <<"  (�) ";
 	SetConsoleOutputCP(866);
cout <<"�";
SetConsoleOutputCP(1251);
cout <<"  (��)   ";
 	SetConsoleOutputCP(866);
cout <<"�";
SetConsoleOutputCP(1251);
cout <<"�������� ";
 	SetConsoleOutputCP(866);
cout <<"�";
cout <<"                     �";
cout << endl << "���������������������������������������������������������������������������������������������������������\xB4 ";
}
void Table_end()
{
SetConsoleOutputCP(866);
cout << endl << "����������������������������������������������������������������������������������������������������������";
}
void Viddil()
{
cout << endl << "������ ��� ���� : 1 - �������, ";
cout << endl << " 2 - �������-�������, ";
cout << endl << " 3 - ��������,";
cout << endl << " 4 - �������,";
cout << endl << " 5 - ����������� ��������.";
cout << endl << "����i�� : ";
}
void Str_viddil(int k) 
{
switch (k)
{
case 1: strcpy(str, "������� "); break;
case 2: strcpy(str, " �� "); break;
case 3: strcpy(str, "��������"); break;
case 4: strcpy(str, "������� "); break;
case 5: strcpy(str, " �� "); break;
}
}
void Radok(int n) 
{
Str_viddil(tov.tip_or);


//printf("\n|%-9s | ", str);
SetConsoleOutputCP(866);
cout<<endl<<"�";

SetConsoleOutputCP(1251);
cout<<setw(9)<<str;

SetConsoleOutputCP(866);
cout<<" �";

SetConsoleOutputCP(1251);
cout<<setw(16)<<tov.kraina;

SetConsoleOutputCP(866);
cout<<" �";

SetConsoleOutputCP(1251);
cout<<setw(16)<<tov.nazvanie;

SetConsoleOutputCP(866);
cout<<" �";

SetConsoleOutputCP(1251);
cout<<setw(7)<<tov.kalibr;

SetConsoleOutputCP(866);
cout<<" �";

SetConsoleOutputCP(1251);
cout<<setw(5)<<tov.waga;
//printf("%-11s|%-16s|%-8.2f | % -2i |", tov.kraina,tov.nazvanie, tov.kalibr,tov.waga);

SetConsoleOutputCP(866);
cout<<" �";
SetConsoleOutputCP(1251);
cout<<setw(8)<<tov.dowj;
SetConsoleOutputCP(866);
cout<<" �";
SetConsoleOutputCP(1251);
cout<<setw(8)<<tov.emnist;
SetConsoleOutputCP(866);
cout<<" �";
SetConsoleOutputCP(1251);
cout<<setw(21)<<tov.vidpow;//<<" "<<setw(5)<<tov.vidpow1;
SetConsoleOutputCP(866);
cout <<"�";
//printf("%-8i |%-7i |%-13s |", tov.dowj, tov.emnist,tov.vidpow);

}


int All_weap()
{
int i, n = 1,z;
z = File_prov();
switch (z)
{
case 1:{
	cout << endl << " ���� �� ��������. ������� ����� ��� ��������� �����.";
	getch();
	break;
}
case 2:
{
cout << endl << " ���� ������. ������� ������ � ����.";
fclose(f);
_getch();
return -1;
}
default:
int i, n = 1;
Tabl_shapka();
rewind(f);
while (fread(&tov,size, 1, f) == 1)
{
Radok(n);
n++;
}
Table_end();
fclose(f);
_getch();
return n-1;
}
}

void Zapit_menu()
{					   
	char zap_otw[80];
	SetConsoleOutputCP(1251);
	cout<<endl<<"\n\t������� �����:";
	cout<<endl<<"\t1. ������� ���� ���� � ������������ ������� ��������.";
	cout<<endl<<"\t2. ̳������� ���� �� �������� ���� ����.";
	cout<<endl<<"\t3. �������� ������� ���� ������ �����-���������.";
	cout<<endl<<"\t4. �������� (�� ������) �����, ����� �� ����� � ������� [x;y].";
	cout<<endl<<"\t5. ³�������� ������������ ������� ������� ���� ���� �� �������� �������.";
	cin>>zap_otw;
	switch(zap_otw[0])
	{
		case '1':{
			Zapit1();
			break;
		}
		case '2':{
			Zapit2();
			break;
		}
		case '3':{
			Zapit3();
			break;
		}
		case '4':{
			Zapit4();
			break;
		}
		case '5':{
			Zapit5();
			break;
		}
	}
}

void Zapit1() 
{
int i, n = 0, p = 1,z;
float sred,sum_em=0,kol_max=0;
int poshuk_viddil;
int max_obmag;
z = File_prov();
if (z ==1)
{
cout << "���� �� ��������. ������� ������ � ����.";
_getch();
return;
}
if (z == 2)
{
cout << "����-������!";
fclose(f);
_getch();
}

f = fopen("MyFile", "rb");
while(fread(&tov,size,1,f)==1)
max_obmag = tov.emnist;
rewind(f);

while(fread(&tov,size,1,f)==1)
if (tov.emnist > max_obmag)max_obmag = tov.emnist;
SetConsoleOutputCP(1251);
cout << endl << "������������ ��'�� ��������: "<<max_obmag<< ".";

rewind(f);
while(fread(&tov,size,1,f)==1)
if (tov.emnist == max_obmag)
{
	kol_max++;
	sum_em+=tov.waga;	
	sred=sum_em/kol_max;
}
rewind(f);
n=0;
Tabl_shapka();
while(fread(&tov,size,1,f)==1)
if (tov.emnist == max_obmag)
{
	Radok(n);
	n++;
}
Table_end();
fclose(f);
SetConsoleOutputCP(1251);
cout << endl << "�������� ���� ���� � ������������ ��'���� �������� �������: "<<sred;
_getch();
}


void Zapit2() // tov � ���������� �����
{
int i, n = 1, p = 1,z;
int poshuk_viddil;
int min_waga = 0;
z = File_prov();
if (z ==1)
{
cout << "���� �� ��������. ������� ������ � ����.";
_getch();
return;
}
if (z == 2)
{
cout << "����-������!";
fclose(f);
_getch();
}
All_weap();
SetConsoleOutputCP(1251);
m2:
Viddil(); //��������� ������ ���� ����
cin >> poshuk_viddil;
if (poshuk_viddil >= 1 && poshuk_viddil <= 5)p = 0;
else
{
cout << endl << "����� ���.";
goto m2;
}
f = fopen("MyFile", "rb");
while(fread(&tov,size,1,f)==1)
{
	if(tov.tip_or == poshuk_viddil)min_waga = tov.waga;
}
fclose(f);
Str_viddil(poshuk_viddil);
if (min_waga == 0) {
SetConsoleOutputCP(1251);	
cout << endl << "���� ���� ���� " << str << "!";
}
else {
f = fopen("MyFile", "rb");
while(fread(&tov,size,1,f)==1)
if (tov.tip_or == poshuk_viddil && tov.waga < min_waga)min_waga = tov.waga;
SetConsoleOutputCP(1251);
cout << endl << "̳������� ���� �� ���� ���� "<<str<<"="<<min_waga<< ".";
rewind(f);
Tabl_shapka();
while(fread(&tov,size,1,f)==1)
if (tov.tip_or == poshuk_viddil && tov.waga == min_waga) {
Radok(n);//�����. �����
n++;
}
Table_end();
SetConsoleOutputCP(1251);
cout << endl << "������ ���� " << n - 1 << " �� ��������� ����� ���� " << str << ".";
}
fclose(f);
_getch();
}




void Zapit3()
{
	int i, n = 1, p = 1,z,min_dlina=-1;
int poshuk_viddil;
char buf[100],strana_p[100];
SetConsoleOutputCP(1251);
z = File_prov();
if (z ==1)
{
cout << "���� �� ��������. ������� ������ � ����.";
_getch();
return;
}
if (z == 2)
{
cout << "����-������!";
fclose(f);
_getch();
}
All_weap();
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
cout<<endl<<"������ �����-��������� ��� ������ �������� ������� ����: ";
while(getchar()!='\n')continue;
gets(buf);
buf[14]='\0';
strcpy(strana_p,buf);
f = fopen("MyFile", "rb");
while(fread(&tov,size,1,f)==1)
{
	if(strcmp(strana_p,tov.kraina)==0)min_dlina = tov.dowj;
}
fclose(f);
SetConsoleOutputCP(1251);
if (min_dlina == -1)cout << endl << "���� ���� �����-��������� " << strana_p << "!";
else {
f = fopen("MyFile", "rb");
while(fread(&tov,size,1,f)==1)
if ((strcmp(strana_p,tov.kraina)==0) && (tov.dowj < min_dlina))min_dlina = tov.dowj;
SetConsoleOutputCP(1251);
cout << endl << "̳������� ������� �� ����-��������� "<<strana_p<< ": "<<min_dlina;
rewind(f);

Tabl_shapka();
while(fread(&tov,size,1,f)==1)
if ((strcmp(strana_p,tov.kraina)==0) && (tov.dowj == min_dlina)) {
Radok(n);//�����. �����
n++;
}
Table_end();
SetConsoleOutputCP(1251);
cout << endl << "������ ���� " << n - 1 << " � ��������� �������� �����-��������� " << strana_p << ".";
}
_getch();
}


void Zapit4()
{
	char x[80],y[80];
	int z,min_dlina,ff=0,kol_d=0,x1,y1,i,prov=0;  //z-�������� �� ������� �����, ff-�������� �� ������� ���������
	SetConsoleOutputCP(1251);		   //kol_d-���������� ������ � ���������
z = File_prov();
if (z ==1)
{
cout << "���� �� ��������. ������� ������ � ����.";
_getch();
return;
}
if (z == 2)
{
cout << "����-������!";
fclose(f);
_getch();
}
	zap4:
	cout << endl << "������ ������� ��������:";
	cin >> x;
	if(!isdigit(x[0]))
	{
		cout<<endl<<"����� ���!";
		goto zap4;	
	}	
	zap41:
	cout << endl << "������ ����� ��������";
	cin >> y;
	if(!isdigit(y[0]))
	{
		cout<<endl<<"����� ���!";
		goto zap41;	
	}
	x1=atoi(x);
	y1=atoi(y);
	if(x>y)
	{
		cout<<endl<<"������� �������� ����� ����!";
		goto zap4;
	}
	f = fopen("MyFile", "rb");
	while(fread(&tov,size,1,f)==1)
	{
		if(tov.kalibr>x1&&tov.kalibr<y1)
		{
			min_dlina = tov.dowj;
			ff++;
		}
	}
	if(ff==0)
	{
		SetConsoleOutputCP(1251);
		cout << endl << "�� ���� ����, ����� �� ����� � ������� [" << x <<";"<< y <<"]";
		cout << endl << "�������� ENTER ��� ������ � ������� ����.";
		getch();
		fclose(f);
		return;
	}
	rewind(f);

	while(fread(&tov,size,1,f)==1)
	{
		if(tov.dowj<min_dlina && tov.kalibr>x1 && tov.kalibr<y1)
		{
			min_dlina = tov.dowj;
		}
	}
	rewind(f);
		while(fread(&tov,size,1,f)==1)
	{
		if(tov.dowj==min_dlina && tov.kalibr>x1 && tov.kalibr<y1)
		{
			kol_d++;
		}
	}
	rewind(f);
	SetConsoleOutputCP(1251);
	cout << endl << "���� �������� " << kol_d << " �������� �� ������ ���� � ������� [" << x1 <<"; "<< y1 <<"]";
	Tabl_shapka();
	while(fread(&tov,size,1,f)==1)
	if (tov.dowj==min_dlina && tov.kalibr>x1 && tov.kalibr<y1)
	{
		Radok(n);//�����. �����
		n++;
	}
	Table_end();
	SetConsoleOutputCP(1251);
	cout << endl << "�������� ENTER ��� ������ � ������� ����.";
	getch();
}



void Zapit5()							//	4 1 3 2 5 = 100%    15=100%
{										//   15/100=4/x        x=100(const)*4(kol1)/15(kolall)
	SetConsoleOutputCP(1251);
	int kol1=0,kol2=0,kol3=0,kol4=0,kol5=0; //���������� ���� ����� ������ �� �����������
	int kolall;   //����� ����� ������ �� ������ (����� kol1 kol2 � ��)
	float per1,per2,per3,per4,per5;   //������� ���������� �����������
	int z;
	z = File_prov();
if (z ==1)
{
cout << "���� �� ��������. ������� ������ � ����.";
_getch();
return;
}
if (z == 2)
{
cout << "����-������!";
fclose(f);
_getch();
}
	
	
	f = fopen("MyFile", "rb");
	while(fread(&tov,size,1,f)==1)
	switch(tov.tip_or)
	{
		case 1:kol1++;break;
		case 2:kol2++;break;
		case 3:kol3++;break;
		case 4:kol4++;break;
		case 5:kol5++;break;
	}
	kolall=kol1+kol2+kol3+kol4+kol5;
	per1=(100*kol1)/kolall;
	per2=(100*kol2)/kolall;
	per3=(100*kol3)/kolall;
	per4=(100*kol4)/kolall;
	per5=(100*kol5)/kolall;
	
	cout<<endl;
	SetConsoleOutputCP(866);
	cout<<"����������������������������������������������Ŀ";
	cout<<endl<<"�   ";
	SetConsoleOutputCP(1251);
	cout<<"���     ";
	SetConsoleOutputCP(866);
	cout<<"�    ";
	SetConsoleOutputCP(1251);
	cout<<"ʳ������    ";
	SetConsoleOutputCP(866);
	cout<<"�  ";
	SetConsoleOutputCP(1251);
	cout<<"³��������    ";
	SetConsoleOutputCP(866);
	cout<<"�";
	cout<<endl<<"�  ";
	SetConsoleOutputCP(1251);
	cout<<"����    ";
	SetConsoleOutputCP(866);
	cout<<"�      ";
	SetConsoleOutputCP(1251);
	cout<<"����      ";
	SetConsoleOutputCP(866);
	cout<<"� ";
	SetConsoleOutputCP(1251);
	cout<<"������������ ";
	SetConsoleOutputCP(866);
	cout<<"�";
	cout<<endl<<"�����������������������������������������������\xB4";
		cout<<endl<<"� ";
	SetConsoleOutputCP(1251);
	cout<<"�������  ";
	SetConsoleOutputCP(866);
	cout<<"�";
	cout<<setw(17)<<kol1;
	cout<<"�";
	cout<<setw(15)<<per1<<"%";
	cout<<"�";
	
		cout<<endl<<"� ";
	SetConsoleOutputCP(1251);
	cout<<"��        ";
	SetConsoleOutputCP(866);
	cout<<"�";
	cout<<setw(17)<<kol2;
	cout<<"�";
	cout<<setw(15)<<per2<<"%";
	cout<<"�";
	
		cout<<endl<<"� ";
	SetConsoleOutputCP(1251);
	cout<<"�������� ";
	SetConsoleOutputCP(866);
	cout<<"�";
	cout<<setw(17)<<kol3;
	cout<<"�";
	cout<<setw(15)<<per3<<"%";
	cout<<"�";
	
		cout<<endl<<"� ";
	SetConsoleOutputCP(1251);
	cout<<"�������   ";
	SetConsoleOutputCP(866);
	cout<<"�";
	cout<<setw(17)<<kol4;
	cout<<"�";
	cout<<setw(15)<<per4<<"%";
	cout<<"�";
	
			cout<<endl<<"� ";
	SetConsoleOutputCP(1251);
	cout<<"��        ";
	SetConsoleOutputCP(866);
	cout<<"�";
	cout<<setw(17)<<kol5;
	cout<<"�";
	cout<<setw(15)<<per5<<"%";
	cout<<"�";	
	cout<<endl<<"������������������������������������������������";


	SetConsoleOutputCP(1251);
	cout << endl << endl <<"�������� ENTER ��� ������ � ������� ����.";
	getch();
}



void Vved()
{

int i,numm, p = 1,value;
char otw,g[80],gg[80],ggg[80],gggg[80],ggggg[80];
char buf[100],prov[80];
numm = 0;
f=fopen("MyFile","ab");
do
{
cout << endl << "����i�� " << numm + 1 << " - � ����� : ";


setlocale(LC_ALL,"russian");
//���� ���� ������
do{
tip:
cout << endl << "������ ��� ���� : 1 - �������, ";
cout << endl << " 2 - ������� - �������, ";
cout << endl << " 3 - ��������,";
cout << endl << " 4 - �������,";
cout << endl << " 5 - ����������� ��������.";
cin>>g;
g[1]='\0';
if (g[0] != '1' && g[0] != '2'&& g[0] != '3' && g[0] != '4' && g[0] != '5')
{
	cout << endl << "������ ����� ���.";
	goto tip;
}

else{
	vvedprov:
	cout<<endl<<"���� ������ "<<g[0]<<" ��� ����, ����������?(1-���, 0 - �)";
	cin>>prov;
	if(prov[0]=='0')goto tip;
	if(prov[0]!='0' && prov[0]!='1')
	{
		system("cls");
		cout<<endl<<"����� ���!";
		goto vvedprov;
	}
}						  

} while (prov[0]=='0');
value=atoi(g);
tov.tip_or=value;
SetConsoleOutputCP(1251);


//���� ������-�������������
cout << endl << "������ �����-��������: ";
while(getchar()!='\n')continue;
gets(buf);
buf[17]='\0';
for(i=1;i<=16;i++)
if(islower(buf[0]))buf[0]=toupper(buf[0]);
for(i=1;i<=16;i++)
if(isupper(buf[i]))
buf[i]=tolower(buf[i]);
strcpy(tov.kraina,buf); 
cout<<endl<<"������� ������-�������������: "<<tov.kraina;


//���� �������� ������
SetConsoleCP(1251);
cout << endl << "������ ����� ����: ";
gets(buf);
buf[16]='\0';
strcpy(tov.nazvanie,buf); 


//���� ����� ������
do{
cout << endl << "������ ���� ����(�): ";
cin>>gg;
gg[4]='\0'; 
if(isdigit(gg[0])&&isdigit(gg[1])&&isdigit(gg[2])&&((isdigit(gg[3]))||(gg[3]=='\0')))
{
	value=atoi(gg);
	tov.waga=value;
}
else cout<<endl<<"����� ���!";
}while(tov.waga<100||tov.waga>7000);



//���� ������� ������
do{
cout << endl << "������ ����� ����(��): ";
cin>>ggg;
ggg[2]='\0';
if(isdigit(ggg[0])&&((isdigit(ggg[1]))||(ggg[1]=='\0')))
{
	value=atoi(ggg);
	tov.kalibr=value;
}
else cout<<endl<<"����� ���!";
}while(tov.kalibr<4||tov.kalibr>20);



//���� ������ ������
do{
cout << endl << "������ ������� ����(��):";
cin>>gggg;
gggg[4]='\0';
if(isdigit(gggg[0])&&isdigit(gggg[1])&&isdigit(gggg[2])&&((isdigit(gggg[3]))||(gggg[3]=='\0')))
{
	value=atoi(gggg);
	tov.dowj=value;
}
else cout<<endl<<"����� ���!";
}while(tov.dowj<100||tov.dowj>5000);



//���� ������� ��������
do{
cout << endl << "������ ������ �������� ����(������� �������): ";
cin >>ggggg; 
ggggg[2]='\0';
if(isdigit(ggggg[0])&&((isdigit(ggggg[1]))||(ggggg[1]=='\0')))
{
	value=atoi(ggggg);
	tov.emnist=value;
}
else cout<<endl<<"����� ���!";
}while(tov.emnist<1||tov.emnist>50);



//���� �������������� �� ������
int n,space=0,to=0,metspace,metto;
vidp:
cout << endl << "������ ������������� �� �����(�������: ������ �. �.): ";  
while(getchar()!='\n')continue;
gets(buf);
n=strlen(buf);
buf[21]='\0';

for(i=0;i<=n;i++)
{
	if(isspace(buf[i])){
	space++;
	metspace=i;	
	}
	if(buf[i]=='.'){
	to++;
	metto=i;	
	}
}														
if(space==2 && to==2 && buf[metto]=='.' && buf[metto-3]=='.' && buf[metto-5]==' ' && metto+1==n && isupper(buf[metto-1]) && isupper(buf[metto-4]))
{
	if(islower(buf[0]))buf[0]=toupper(buf[0]);
	for(i=1;i<=metspace-3;i++)
	if(isupper(buf[i]))
	buf[i]=tolower(buf[i]);
}
else
{
	cout<<endl<<"������� ������!";
	space=0;
	to=0;
	goto vidp;
}
strcpy(tov.vidpow,buf); 
cout << endl << "³����������� �� �����: "<<tov.vidpow;

fwrite(&tov,size,1,f);

n++;
i++;
cout << endl << "������ ���������� ����? (y-da)";
cin >> otw;
numm++;
} while (otw == 'y');
SetConsoleOutputCP(1251);
cout << endl << "������ ��� ��� "<<numm<<" ����.";
cout << endl << "������� Enter ��� ������ � ������� ����.";
fclose(f);
_getch();
}



int File_prov()
{
if ((f=fopen("MyFile","rb")) == NULL)return 1;
else 
if(fread(&tov, size, 1, f) == 0)return 2;
else
{
rewind(f);	
return 3;
}
}


void DeleteMenu()
{
	char tip_del[80];
	mdel_menu:
	SetConsoleOutputCP(1251);
	cout<<endl<<"\n\t������� ��� ���������:\n";
	cout<<endl<<"\t1. �� ���� ����.";
	cout<<endl<<"\t2. �� ����-���������.";
	cout<<endl<<"\t3. ����� ��� ���������.";
	cin>>tip_del;
	if(tip_del[0]!='1' && tip_del[0]!='2' && tip_del[0]!='3')
	{
		cout<<endl<<"������ ���� ��������� �� ����!";
		goto mdel_menu;
	}
	else
	{
		switch(tip_del[0])
		{
			case '1':{
				Delete1();
				break;
			}
			case '2':{
				Delete2();
				break;
			case '3':{
				
				break;
			}
			}
		}
	}
}
void Delete1()   //�������� �� ���� ������
{
  int nom,prov_del,z;
  z = File_prov();
if (z ==1)
{
cout << "���� �� ��������. ������� ������ � ����.";
_getch();
return;
}
if (z == 2)
{
cout << "����-������!";
fclose(f);
_getch();
return;
}
  All_weap();
  mdel1:
  	SetConsoleOutputCP(1251);
  cout<<endl<<"������� ��� ������, ������� ������ �������: ";
  cout << endl <<"1 - �������, ";
cout << endl << " 2 - ������� - �������, ";
cout << endl << " 3 - ��������,";
cout << endl << " 4 - �������,";
cout << endl << " 5 - ����������� ��������.";
  cin>>nom;
  if(nom<1||nom>5)
  {
    cout<<endl<<"���� ������ ���� �� ����.";
    goto mdel1;
  }
  f=fopen("MyFile","rb");
  cout<<endl<<"ϳ��� ������������ ���� �������� ��� ������:";
  Tabl_shapka();
  while(fread(&tov,size,1,f)==1)
  if (nom==tov.tip_or)
  {
  Radok(n);//�����. �����
  n++;
  }
  Table_end();
  SetConsoleOutputCP(1251);
  provdel:
  cout<<endl<<"�������� �� ������?(1-���;0-�)";
  cin>>prov_del;
  if(prov_del==0)
  {
  	fclose(f);
  	return;
  }
  if(prov_del!=1&&prov_del!=0)
  {
  	SetConsoleOutputCP(1251);
  	cout<<endl<<"��������� ���!";
  	goto provdel;
  }
  cout<<endl<<"������ ��������!";
  f=fopen("MyFile","rb");
  g=fopen("MyFileDel","wb");
  int i, n=1;
  while(fread(&tov,size,1,f)==1)
  {
    if(nom!=tov.tip_or)
	{
		fwrite(&tov,size,1,g);
	}
    n++;
  }       
  fclose(f);
  fclose(g);
  g=fopen("MyFileDel","rb");
  f=fopen("MyFile","wb");
  while(fread(&tov,size,1,g)==1)
  {
    fwrite(&tov,size,1,f);
  }
  fclose(f);
  fclose(g);
  All_weap();
  cout<<endl<<"�������� ENTER ��� ������ � ������� ����.";  
  return;    
}

void Delete2()   //�������� �� ������-�������������
{
	int proverka=0,prov_del,z;
  char buf[300];
  char strana[200];
  z = File_prov();
  if (z ==1)
{
cout << "���� �� ��������. ������� ������ � ����.";
_getch();
return;
}
if (z == 2)
{
cout << "����-������!";
fclose(f);
_getch();
return;
}
  All_weap();
  SetConsoleOutputCP(1251);
  SetConsoleCP(1251);
  cout<<endl<<"������ �����-��������, ��������� ��� ���� ��������:"<<endl;
  while(getchar()!='\n') continue;
  gets(buf);
  buf[14]='\0';
strcpy(strana, buf);

  f=fopen("MyFile","rb");
  
  while(fread(&tov,size,1,f)==1)
  if(strcmp(strana,tov.kraina)==0)
  proverka++;
  if(proverka==0)
  {
  	cout<<endl<<"�� ���� ���� �����-���������: "<<strana;
  	cout<<endl<<"�������� ENTER ��� ������ � ������� ����.";
  	getch();
  	return;
  }
  rewind(f);
  cout<<endl<<"ϳ��� ������������ ���� �������� ��� ������:";
  Tabl_shapka();
  while(fread(&tov,size,1,f)==1)
  if (strcmp(strana,tov.kraina)==0)
  {
  Radok(n);//�����. �����
  n++;
  }
  Table_end();
  SetConsoleOutputCP(1251);
  provdel2:
  cout<<endl<<"�������� �� ������?(1-���;0-�)";
  cin>>prov_del;
  if(prov_del==0)
  {
  	fclose(f);
  	return;
  }
  if(prov_del!=1&&prov_del!=0)
  {
  	SetConsoleOutputCP(1251);
  	cout<<endl<<"��������� ���!";
  	goto provdel2;
  }
  cout<<endl<<"������ ��������!";
  rewind(f);
  g=fopen("MyFileDel","wb");
    int i, n=0;
  while(fread(&tov,size,1,f)==1)
  if(strcmp(strana,tov.kraina)!=0)
	fwrite(&tov,size,1,g);

  SetConsoleOutputCP(1251);  
  	fclose(f);
  	fclose(g);
  	g=fopen("MyFileDel","rb");
  	f=fopen("MyFile","wb");
 	 while(fread(&tov,size,1,g)==1)
  	{
  	  fwrite(&tov,size,1,f);
	 }
  	fclose(f);
  	fclose(g);
  	All_weap(); 
 	//}
 	SetConsoleOutputCP(1251);
   cout<<endl<<"�������� ENTER ��� ������ � ������� ����.";
  return;    
}


void Sort_menu() //���� ����������
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char tip_sort[80];
	msort:
	cout<<endl<<"\t������ ��� ���������� ����:";
	cout<<endl<<"\n\t1.�� ������(�� �������)";
	cout<<endl<<"\t2.�� ������� ��������(�� ����������)";
	cout<<endl<<"\t3.����� ��� ����������";
	cin>>tip_sort;
	if(tip_sort[0]!='1' && tip_sort[0]!='2' && tip_sort[0]!='3')
	{
		cout<<endl<<"������ ���� ���������� ������ �� ����!";
		goto msort;
	}
	else
	{
		switch(tip_sort[0])
		{
			case '1':{
				Sort1();
				break;
			}
			case '2':{
				Sort2();
				break;
			}
			case '3':{
				
				break;
			}
		}
	}
}

void Sort1()
{int kol_zap;
kol_zap=All_weap();
    //system("cls");
    //system("color F5");
    //All_weap();
    SetConsoleOutputCP(1251);
    
    if ((f = fopen("MyFile", "rb")) == NULL)
    {
        cout << endl << "���� �� �������.";
        getch();
        return;
    }
    if (kol_zap == 0) {
        cout << endl << "���� ������.";
        getch();
        return;
    }
    //rewind(f);
    if (kol_zap == 1)
    {
    	cout << endl <<"���������� �� �� ����� - � ���� ���� �����.";
    	All_weap();
    	return;
	}

	cout <<endl<< "����������" << endl;
    fclose(f);
    int i;
    Gun rab[2];
 f = fopen("MyFile", "r+b");
m_sort:

    fseek(f, 0, SEEK_SET);
    for (i = 0; i <= kol_zap; i++)
    {
        fread(&rab[0], size, 1, f);
        fread(&rab[1], size, 1, f);

        if (strcmp(rab[0].kraina, rab[1].kraina) > 0)
        {
            fseek(f, -size * 2, SEEK_CUR);
            fwrite(&rab[1], size, 1, f);
            fwrite(&rab[0], size, 1, f);
            goto m_sort;
        }
        fseek(f, -size, SEEK_CUR);
    }
   
    fclose(f);
     All_weap();
 }


void Sort2()
{
	int kol_zap;
kol_zap=All_weap();
SetConsoleOutputCP(1251);
    cout <<endl<< "����������" << endl;
    if ((f = fopen("MyFile", "rb")) == NULL)
    {
        cout << endl << "���� �� �������.";
        getch();
        return;
    }
    if (kol_zap == 0) {
        cout << endl << "���� ������.";
        getch();
        return;
    }
    if (kol_zap == 1)
    {
    	cout << endl <<"���������� �� �� ����� - � ���� ���� �����.";
    	All_weap();
    	return;
	}
    else
    {
    //rewind(f);
    fclose(f);
    int i;
    Gun rab[2];
 f = fopen("MyFile", "r+b");
m_sort:

    fseek(f, 0, SEEK_SET);
    for (i = 0; i <= kol_zap; i++)
    {
        fread(&rab[0], size, 1, f);
        fread(&rab[1], size, 1, f);

        if (rab[0].emnist<rab[1].emnist)
        {
            fseek(f, -size * 2, SEEK_CUR);
            fwrite(&rab[1], size, 1, f);
            fwrite(&rab[0], size, 1, f);
            goto m_sort;
        }
        
		fseek(f, -size, SEEK_CUR);
    }

    fclose(f);
    All_weap();
}
}
