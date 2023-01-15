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
int File_prov();	//Проверка на наличие файла;
int All_weap();		//Вывод данных из таблицы;
void Vved();		//Ввод данных в таблицу;
void Tabl_shapka(); //Верхняя часть таблицы;
void Table_end();  //Нижняя часть таблицы;
void Viddil();
void Str_viddil(int k); //преображения числа в строку;
void Radok(int n); //Вывод строки;

void DeleteMenu(); //Удаление(меню);
void Delete1();		//Удаление(тип оружия);
void Delete2();		 //Удаление(страна-производитель);

void Sort_menu(); //Сортировка(меню);
void Sort1();	//Сортировка по названию;
void Sort2();	//Сортировка по магазину;

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
char p_m[80]; //пункт меню
do {
system("cls");
start:
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
cout << endl << endl << "\n\tГоловне меню програми:" <<endl;
cout << endl << "\t1.Введення даних про зброю";           //Vved();
cout << endl << "\t2.Перегляд усiєї зброї у базі даних"; //All_weap();
cout << endl << "\t3.Виконання запитів";  //Zapit_menu();
cout << endl << "\t4.Сортування записів";   //Sort_weap();
cout << endl << "\t5.Видалення записів";    //Delete_menu();
cout << endl << "\t6.Вихiд з програми";
cout << endl << endl << "\tОберiть пункт меню:";
cin >> p_m;
switch (p_m[0])
{
case '1':Vved(); break;
case '2':All_weap(); break;
case '3':Zapit_menu(); break;
case '4':Sort_menu(); break;
case '5':DeleteMenu(); break;
case '6':cout << endl << "Кінець роботи"; getch();return 0;
default:system("cls");
cout << endl << endl << "Обрано невірнo!";
goto start;
}
}// end do
while (p_m[0] != '6');//кінець циклу
_getch();
return 0;
}
void Tabl_shapka()
{
 	SetConsoleOutputCP(866);
cout << endl << "ЪДДДДДДДДДДВДДДДДДДДДДДДДДДДДВДДДДДДДДДДДДДДДДДВДДДДДДДДВДДДДДДВДДДДДДДДДВДДДДДДДДДВДДДДДДДДДДДДДДДДДДДДДї";
cout <<endl<<"і ";
SetConsoleOutputCP(1251);
cout << " Тип     ";
	
 	SetConsoleOutputCP(866);
cout << "і ";
SetConsoleOutputCP(1251);
cout << "    Країна -    ";
 	SetConsoleOutputCP(866);
cout <<"і ";
SetConsoleOutputCP(1251);
cout <<"  Назва зброї   ";
 	SetConsoleOutputCP(866);
cout << "і ";
SetConsoleOutputCP(1251);
cout << "Калібр ";
 	SetConsoleOutputCP(866);
cout <<"і ";
SetConsoleOutputCP(1251);
cout <<"Вага ";
 	SetConsoleOutputCP(866);
cout <<"і ";
SetConsoleOutputCP(1251);
cout <<"Довжина ";
 	SetConsoleOutputCP(866);
cout <<"і ";
SetConsoleOutputCP(1251);
cout <<"Ємність ";
 	SetConsoleOutputCP(866);
cout <<"і";
SetConsoleOutputCP(1251);
cout <<"   Відповідальний    ";
 	SetConsoleOutputCP(866);
cout <<"і";
cout << endl ;
 	SetConsoleOutputCP(866);
cout <<"і";
SetConsoleOutputCP(1251);
cout <<"  зброї   ";
 	SetConsoleOutputCP(866);
cout <<"і";
SetConsoleOutputCP(1251);
cout <<"    виробник     ";
 	SetConsoleOutputCP(866);
cout <<"і                 ";
cout <<"і";
SetConsoleOutputCP(1251);
cout <<"   (мм) ";
 	SetConsoleOutputCP(866);
cout <<"і";
SetConsoleOutputCP(1251);
cout <<"  (г) ";
 	SetConsoleOutputCP(866);
cout <<"і";
SetConsoleOutputCP(1251);
cout <<"  (мм)   ";
 	SetConsoleOutputCP(866);
cout <<"і";
SetConsoleOutputCP(1251);
cout <<"магазину ";
 	SetConsoleOutputCP(866);
cout <<"і";
cout <<"                     і";
cout << endl << "ГДДДДДДДДДДЕДДДДДДДДДДДДДДДДДЕДДДДДДДДДДДДДДДДДЕДДДДДДДДЕДДДДДДЕДДДДДДДДДЕДДДДДДДДДЕДДДДДДДДДДДДДДДДДДДДД\xB4 ";
}
void Table_end()
{
SetConsoleOutputCP(866);
cout << endl << "АДДДДДДДДДДБДДДДДДДДДДДДДДДДДБДДДДДДДДДДДДДДДДДБДДДДДДДДБДДДДДДБДДДДДДДДДБДДДДДДДДДБДДДДДДДДДДДДДДДДДДДДДЩ";
}
void Viddil()
{
cout << endl << "Оберіть тип зброї : 1 - пістолет, ";
cout << endl << " 2 - пістолет-кулемет, ";
cout << endl << " 3 - гвинтівка,";
cout << endl << " 4 - автомат,";
cout << endl << " 5 - снайперська гвинтівка.";
cout << endl << "Уведiть : ";
}
void Str_viddil(int k) 
{
switch (k)
{
case 1: strcpy(str, "пістолет "); break;
case 2: strcpy(str, " ПК "); break;
case 3: strcpy(str, "гвинтівка"); break;
case 4: strcpy(str, "автомат "); break;
case 5: strcpy(str, " СГ "); break;
}
}
void Radok(int n) 
{
Str_viddil(tov.tip_or);


//printf("\n|%-9s | ", str);
SetConsoleOutputCP(866);
cout<<endl<<"і";

SetConsoleOutputCP(1251);
cout<<setw(9)<<str;

SetConsoleOutputCP(866);
cout<<" і";

SetConsoleOutputCP(1251);
cout<<setw(16)<<tov.kraina;

SetConsoleOutputCP(866);
cout<<" і";

SetConsoleOutputCP(1251);
cout<<setw(16)<<tov.nazvanie;

SetConsoleOutputCP(866);
cout<<" і";

SetConsoleOutputCP(1251);
cout<<setw(7)<<tov.kalibr;

SetConsoleOutputCP(866);
cout<<" і";

SetConsoleOutputCP(1251);
cout<<setw(5)<<tov.waga;
//printf("%-11s|%-16s|%-8.2f | % -2i |", tov.kraina,tov.nazvanie, tov.kalibr,tov.waga);

SetConsoleOutputCP(866);
cout<<" і";
SetConsoleOutputCP(1251);
cout<<setw(8)<<tov.dowj;
SetConsoleOutputCP(866);
cout<<" і";
SetConsoleOutputCP(1251);
cout<<setw(8)<<tov.emnist;
SetConsoleOutputCP(866);
cout<<" і";
SetConsoleOutputCP(1251);
cout<<setw(21)<<tov.vidpow;//<<" "<<setw(5)<<tov.vidpow1;
SetConsoleOutputCP(866);
cout <<"і";
//printf("%-8i |%-7i |%-13s |", tov.dowj, tov.emnist,tov.vidpow);

}


int All_weap()
{
int i, n = 1,z;
z = File_prov();
switch (z)
{
case 1:{
	cout << endl << " Файл не знайдено. Додайте запис для створення файлу.";
	getch();
	break;
}
case 2:
{
cout << endl << " Файл пустий. Додайте записи у файл.";
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
	cout<<endl<<"\n\tВиберіть запит:";
	cout<<endl<<"\t1. Середня вага зброї з максимальним обсягом магазину.";
	cout<<endl<<"\t2. Мінімальна вага по обраному типу зброї.";
	cout<<endl<<"\t3. Найменша довжина зброї окремої країни-виробника.";
	cout<<endl<<"\t4. Найменша (по довжині) зброя, котра має калібр у діапазоні [x;y].";
	cout<<endl<<"\t5. Відсоткове співвідношення кількості кожного типу зброї до загальної кількості.";
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
cout << "Файл не знайдено. Додайте записи у файл.";
_getch();
return;
}
if (z == 2)
{
cout << "Файл-пустой!";
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
cout << endl << "Максимальний об'єм магазину: "<<max_obmag<< ".";

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
cout << endl << "Середнья вага зброї з максимальним об'ємом магазину дорівнює: "<<sred;
_getch();
}


void Zapit2() // tov – глобальний масив
{
int i, n = 1, p = 1,z;
int poshuk_viddil;
int min_waga = 0;
z = File_prov();
if (z ==1)
{
cout << "Файл не знайдено. Додайте записи у файл.";
_getch();
return;
}
if (z == 2)
{
cout << "Файл-пустой!";
fclose(f);
_getch();
}
All_weap();
SetConsoleOutputCP(1251);
m2:
Viddil(); //виведення списку типів зброї
cin >> poshuk_viddil;
if (poshuk_viddil >= 1 && poshuk_viddil <= 5)p = 0;
else
{
cout << endl << "Невірні дані.";
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
cout << endl << "Немає зброї типу " << str << "!";
}
else {
f = fopen("MyFile", "rb");
while(fread(&tov,size,1,f)==1)
if (tov.tip_or == poshuk_viddil && tov.waga < min_waga)min_waga = tov.waga;
SetConsoleOutputCP(1251);
cout << endl << "Мінімальна вага по типу зброї "<<str<<"="<<min_waga<< ".";
rewind(f);
Tabl_shapka();
while(fread(&tov,size,1,f)==1)
if (tov.tip_or == poshuk_viddil && tov.waga == min_waga) {
Radok(n);//вивед. рядка
n++;
}
Table_end();
SetConsoleOutputCP(1251);
cout << endl << "Усього зброї " << n - 1 << " за мінімальною вагою типу " << str << ".";
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
cout << "Файл не знайдено. Додайте записи у файл.";
_getch();
return;
}
if (z == 2)
{
cout << "Файл-пустой!";
fclose(f);
_getch();
}
All_weap();
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
cout<<endl<<"Уведіть країну-виробника для пошуку мінімальної довжини зброї: ";
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
if (min_dlina == -1)cout << endl << "Немає зброї країни-виробника " << strana_p << "!";
else {
f = fopen("MyFile", "rb");
while(fread(&tov,size,1,f)==1)
if ((strcmp(strana_p,tov.kraina)==0) && (tov.dowj < min_dlina))min_dlina = tov.dowj;
SetConsoleOutputCP(1251);
cout << endl << "Мінімальна довжина по країні-виробнику "<<strana_p<< ": "<<min_dlina;
rewind(f);

Tabl_shapka();
while(fread(&tov,size,1,f)==1)
if ((strcmp(strana_p,tov.kraina)==0) && (tov.dowj == min_dlina)) {
Radok(n);//вивед. рядка
n++;
}
Table_end();
SetConsoleOutputCP(1251);
cout << endl << "Усього зброї " << n - 1 << " з мінімальною довжиною країни-виробника " << strana_p << ".";
}
_getch();
}


void Zapit4()
{
	char x[80],y[80];
	int z,min_dlina,ff=0,kol_d=0,x1,y1,i,prov=0;  //z-проверка на наличие файла, ff-проверка на наличие искаемого
	SetConsoleOutputCP(1251);		   //kol_d-количество оружия в диапазоне
z = File_prov();
if (z ==1)
{
cout << "Файл не знайдено. Додайте записи у файл.";
_getch();
return;
}
if (z == 2)
{
cout << "Файл-пустой!";
fclose(f);
_getch();
}
	zap4:
	cout << endl << "Уведіть початок діапазону:";
	cin >> x;
	if(!isdigit(x[0]))
	{
		cout<<endl<<"Невірні дані!";
		goto zap4;	
	}	
	zap41:
	cout << endl << "Уведіть кінець діапазону";
	cin >> y;
	if(!isdigit(y[0]))
	{
		cout<<endl<<"Невірні дані!";
		goto zap41;	
	}
	x1=atoi(x);
	y1=atoi(y);
	if(x>y)
	{
		cout<<endl<<"Початок діапазону більше кінця!";
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
		cout << endl << "Не було зброї, котра має калібр у діапазоні [" << x <<";"<< y <<"]";
		cout << endl << "Натисніть ENTER для виходу у головне меню.";
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
	cout << endl << "Було знайдено " << kol_d << " мінімальної по довжині зброї у діапазоні [" << x1 <<"; "<< y1 <<"]";
	Tabl_shapka();
	while(fread(&tov,size,1,f)==1)
	if (tov.dowj==min_dlina && tov.kalibr>x1 && tov.kalibr<y1)
	{
		Radok(n);//вивед. рядка
		n++;
	}
	Table_end();
	SetConsoleOutputCP(1251);
	cout << endl << "Натисніть ENTER для виходу у головне меню.";
	getch();
}



void Zapit5()							//	4 1 3 2 5 = 100%    15=100%
{										//   15/100=4/x        x=100(const)*4(kol1)/15(kolall)
	SetConsoleOutputCP(1251);
	int kol1=0,kol2=0,kol3=0,kol4=0,kol5=0; //Количество всех типов оружия по отдельности
	int kolall;   //сумма всего оружия на складе (сумма kol1 kol2 и тд)
	float per1,per2,per3,per4,per5;   //готовые процентные соотношения
	int z;
	z = File_prov();
if (z ==1)
{
cout << "Файл не знайдено. Додайте записи у файл.";
_getch();
return;
}
if (z == 2)
{
cout << "Файл-пустой!";
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
	cout<<"ЪДДДДДДДДДДДВДДДДДДДДДДДДДДДДДВДДДДДДДДДДДДДДДДї";
	cout<<endl<<"і   ";
	SetConsoleOutputCP(1251);
	cout<<"Тип     ";
	SetConsoleOutputCP(866);
	cout<<"і    ";
	SetConsoleOutputCP(1251);
	cout<<"Кількість    ";
	SetConsoleOutputCP(866);
	cout<<"і  ";
	SetConsoleOutputCP(1251);
	cout<<"Відсоткове    ";
	SetConsoleOutputCP(866);
	cout<<"і";
	cout<<endl<<"і  ";
	SetConsoleOutputCP(1251);
	cout<<"зброї    ";
	SetConsoleOutputCP(866);
	cout<<"і      ";
	SetConsoleOutputCP(1251);
	cout<<"зброї      ";
	SetConsoleOutputCP(866);
	cout<<"і ";
	SetConsoleOutputCP(1251);
	cout<<"співвідношення ";
	SetConsoleOutputCP(866);
	cout<<"і";
	cout<<endl<<"ГДДДДДДДДДДДЕДДДДДДДДДДДДДДДДДЕДДДДДДДДДДДДДДДД\xB4";
		cout<<endl<<"і ";
	SetConsoleOutputCP(1251);
	cout<<"пістолет  ";
	SetConsoleOutputCP(866);
	cout<<"і";
	cout<<setw(17)<<kol1;
	cout<<"і";
	cout<<setw(15)<<per1<<"%";
	cout<<"і";
	
		cout<<endl<<"і ";
	SetConsoleOutputCP(1251);
	cout<<"ПК        ";
	SetConsoleOutputCP(866);
	cout<<"і";
	cout<<setw(17)<<kol2;
	cout<<"і";
	cout<<setw(15)<<per2<<"%";
	cout<<"і";
	
		cout<<endl<<"і ";
	SetConsoleOutputCP(1251);
	cout<<"гвинтівка ";
	SetConsoleOutputCP(866);
	cout<<"і";
	cout<<setw(17)<<kol3;
	cout<<"і";
	cout<<setw(15)<<per3<<"%";
	cout<<"і";
	
		cout<<endl<<"і ";
	SetConsoleOutputCP(1251);
	cout<<"автомат   ";
	SetConsoleOutputCP(866);
	cout<<"і";
	cout<<setw(17)<<kol4;
	cout<<"і";
	cout<<setw(15)<<per4<<"%";
	cout<<"і";
	
			cout<<endl<<"і ";
	SetConsoleOutputCP(1251);
	cout<<"СГ        ";
	SetConsoleOutputCP(866);
	cout<<"і";
	cout<<setw(17)<<kol5;
	cout<<"і";
	cout<<setw(15)<<per5<<"%";
	cout<<"і";	
	cout<<endl<<"АДДДДДДДДДДДБДДДДДДДДДДДДДДДДДБДДДДДДДДДДДДДДДДЩ";


	SetConsoleOutputCP(1251);
	cout << endl << endl <<"Натисніть ENTER для виходу у головне меню.";
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
cout << endl << "Уведiть " << numm + 1 << " - у зброю : ";


setlocale(LC_ALL,"russian");
//Ввод типа оружия
do{
tip:
cout << endl << "Оберіть тип зброї : 1 - пістолет, ";
cout << endl << " 2 - пістолет - кулемет, ";
cout << endl << " 3 - гвинтівка,";
cout << endl << " 4 - автомат,";
cout << endl << " 5 - снайперська гвинтівка.";
cin>>g;
g[1]='\0';
if (g[0] != '1' && g[0] != '2'&& g[0] != '3' && g[0] != '4' && g[0] != '5')
{
	cout << endl << "Уведені невірні дані.";
	goto tip;
}

else{
	vvedprov:
	cout<<endl<<"Буде обрано "<<g[0]<<" тип зброї, підтвердити?(1-так, 0 - ні)";
	cin>>prov;
	if(prov[0]=='0')goto tip;
	if(prov[0]!='0' && prov[0]!='1')
	{
		system("cls");
		cout<<endl<<"Невірні дані!";
		goto vvedprov;
	}
}						  

} while (prov[0]=='0');
value=atoi(g);
tov.tip_or=value;
SetConsoleOutputCP(1251);


//Ввод страны-производителя
cout << endl << "Уведіть країну-виробник: ";
while(getchar()!='\n')continue;
gets(buf);
buf[17]='\0';
for(i=1;i<=16;i++)
if(islower(buf[0]))buf[0]=toupper(buf[0]);
for(i=1;i<=16;i++)
if(isupper(buf[i]))
buf[i]=tolower(buf[i]);
strcpy(tov.kraina,buf); 
cout<<endl<<"Введена страна-производитель: "<<tov.kraina;


//Ввод названия оружия
SetConsoleCP(1251);
cout << endl << "Уведіть назву зброї: ";
gets(buf);
buf[16]='\0';
strcpy(tov.nazvanie,buf); 


//Ввод массы оружия
do{
cout << endl << "Уведіть вагу зброї(г): ";
cin>>gg;
gg[4]='\0'; 
if(isdigit(gg[0])&&isdigit(gg[1])&&isdigit(gg[2])&&((isdigit(gg[3]))||(gg[3]=='\0')))
{
	value=atoi(gg);
	tov.waga=value;
}
else cout<<endl<<"Невірні дані!";
}while(tov.waga<100||tov.waga>7000);



//Ввод калибра оружия
do{
cout << endl << "Уведіть калібр зброї(мм): ";
cin>>ggg;
ggg[2]='\0';
if(isdigit(ggg[0])&&((isdigit(ggg[1]))||(ggg[1]=='\0')))
{
	value=atoi(ggg);
	tov.kalibr=value;
}
else cout<<endl<<"Невірні дані!";
}while(tov.kalibr<4||tov.kalibr>20);



//Ввод длинны оружия
do{
cout << endl << "Уведіть довжину зброї(мм):";
cin>>gggg;
gggg[4]='\0';
if(isdigit(gggg[0])&&isdigit(gggg[1])&&isdigit(gggg[2])&&((isdigit(gggg[3]))||(gggg[3]=='\0')))
{
	value=atoi(gggg);
	tov.dowj=value;
}
else cout<<endl<<"Невірні дані!";
}while(tov.dowj<100||tov.dowj>5000);



//Ввод ёмкости магазина
do{
cout << endl << "Уведіть ємність магазину зброї(кількість патронів): ";
cin >>ggggg; 
ggggg[2]='\0';
if(isdigit(ggggg[0])&&((isdigit(ggggg[1]))||(ggggg[1]=='\0')))
{
	value=atoi(ggggg);
	tov.emnist=value;
}
else cout<<endl<<"Невірні дані!";
}while(tov.emnist<1||tov.emnist>50);



//Ввод ответственного за оружие
int n,space=0,to=0,metspace,metto;
vidp:
cout << endl << "Уведіть відповідального за зброю(формату: Іванов І. І.): ";  
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
	cout<<endl<<"Уведено невірно!";
	space=0;
	to=0;
	goto vidp;
}
strcpy(tov.vidpow,buf); 
cout << endl << "Відповідальний за зброю: "<<tov.vidpow;

fwrite(&tov,size,1,f);

n++;
i++;
cout << endl << "Хотите продолжить ввод? (y-da)";
cin >> otw;
numm++;
} while (otw == 'y');
SetConsoleOutputCP(1251);
cout << endl << "Уведені дані про "<<numm<<" зброї.";
cout << endl << "Нажмите Enter для выхода в главное меню.";
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
	cout<<endl<<"\n\tВиберіть тип видалення:\n";
	cout<<endl<<"\t1. По типу зброї.";
	cout<<endl<<"\t2. По країні-виробнику.";
	cout<<endl<<"\t3. Вихід без видалення.";
	cin>>tip_del;
	if(tip_del[0]!='1' && tip_del[0]!='2' && tip_del[0]!='3')
	{
		cout<<endl<<"Даного типу видалення не існує!";
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
void Delete1()   //Удаление по типу оружия
{
  int nom,prov_del,z;
  z = File_prov();
if (z ==1)
{
cout << "Файл не знайдено. Додайте записи у файл.";
_getch();
return;
}
if (z == 2)
{
cout << "Файл-пустой!";
fclose(f);
_getch();
return;
}
  All_weap();
  mdel1:
  	SetConsoleOutputCP(1251);
  cout<<endl<<"Введите тип оружия, который хотите удалить: ";
  cout << endl <<"1 - пістолет, ";
cout << endl << " 2 - пістолет - кулемет, ";
cout << endl << " 3 - гвинтівка,";
cout << endl << " 4 - автомат,";
cout << endl << " 5 - снайперська гвинтівка.";
  cin>>nom;
  if(nom<1||nom>5)
  {
    cout<<endl<<"Зброї даного типу не існує.";
    goto mdel1;
  }
  f=fopen("MyFile","rb");
  cout<<endl<<"Після підтвердження буде видалено дані записи:";
  Tabl_shapka();
  while(fread(&tov,size,1,f)==1)
  if (nom==tov.tip_or)
  {
  Radok(n);//вивед. рядка
  n++;
  }
  Table_end();
  SetConsoleOutputCP(1251);
  provdel:
  cout<<endl<<"Видалити ці записи?(1-так;0-ні)";
  cin>>prov_del;
  if(prov_del==0)
  {
  	fclose(f);
  	return;
  }
  if(prov_del!=1&&prov_del!=0)
  {
  	SetConsoleOutputCP(1251);
  	cout<<endl<<"Некоректні дані!";
  	goto provdel;
  }
  cout<<endl<<"Записи видалено!";
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
  cout<<endl<<"Натисніть ENTER для виходу у головне меню.";  
  return;    
}

void Delete2()   //Удаление по стране-производителю
{
	int proverka=0,prov_del,z;
  char buf[300];
  char strana[200];
  z = File_prov();
  if (z ==1)
{
cout << "Файл не знайдено. Додайте записи у файл.";
_getch();
return;
}
if (z == 2)
{
cout << "Файл-пустой!";
fclose(f);
_getch();
return;
}
  All_weap();
  SetConsoleOutputCP(1251);
  SetConsoleCP(1251);
  cout<<endl<<"Уведіть країну-виробник, продукцію якої буде видалено:"<<endl;
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
  	cout<<endl<<"Не було зброї країни-виробника: "<<strana;
  	cout<<endl<<"Натисніть ENTER для виходу у головне меню.";
  	getch();
  	return;
  }
  rewind(f);
  cout<<endl<<"Після підтвердження буде видалено дані записи:";
  Tabl_shapka();
  while(fread(&tov,size,1,f)==1)
  if (strcmp(strana,tov.kraina)==0)
  {
  Radok(n);//вивед. рядка
  n++;
  }
  Table_end();
  SetConsoleOutputCP(1251);
  provdel2:
  cout<<endl<<"Видалити ці записи?(1-так;0-ні)";
  cin>>prov_del;
  if(prov_del==0)
  {
  	fclose(f);
  	return;
  }
  if(prov_del!=1&&prov_del!=0)
  {
  	SetConsoleOutputCP(1251);
  	cout<<endl<<"Некоректні дані!";
  	goto provdel2;
  }
  cout<<endl<<"Записи видалено!";
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
   cout<<endl<<"Натисніть ENTER для виходу у головне меню.";
  return;    
}


void Sort_menu() //Меню сортировки
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char tip_sort[80];
	msort:
	cout<<endl<<"\tУведіть тип сортування зброї:";
	cout<<endl<<"\n\t1.За назвою(по алфавіту)";
	cout<<endl<<"\t2.За обсягом магазину(за зменшенням)";
	cout<<endl<<"\t3.Вихід без сортування";
	cin>>tip_sort;
	if(tip_sort[0]!='1' && tip_sort[0]!='2' && tip_sort[0]!='3')
	{
		cout<<endl<<"Даного типу сортування записів не існує!";
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
        cout << endl << "Файл не відкрито.";
        getch();
        return;
    }
    if (kol_zap == 0) {
        cout << endl << "Файл пустий.";
        getch();
        return;
    }
    //rewind(f);
    if (kol_zap == 1)
    {
    	cout << endl <<"Сортування не має сенсу - у файлі один запис.";
    	All_weap();
    	return;
	}

	cout <<endl<< "Сортування" << endl;
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
    cout <<endl<< "Сортування" << endl;
    if ((f = fopen("MyFile", "rb")) == NULL)
    {
        cout << endl << "Файл не відкрито.";
        getch();
        return;
    }
    if (kol_zap == 0) {
        cout << endl << "Файл пустий.";
        getch();
        return;
    }
    if (kol_zap == 1)
    {
    	cout << endl <<"Сортування не має сенсу - у файлі один запис.";
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
