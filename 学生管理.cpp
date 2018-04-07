#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include"student.h"
using namespace std;
struct Teacher {
	string name;
	string code;
	string teachclass;
	int classspace;
	string place; 
};
struct Student
{
	string name;
	string code;
	long long schoolnumber;
	string grade;
	string studentclass[5];
	int classes;
};
Teacher teacher[20];
Student student[100];
int c1 = 0, m1 = 0, h1 = 0, e1 = 0, p1 = 0;
int i = 0, k = 0;
void Login();
void regis()
{
	int m=0, t=0,j;
	string s1[100], s2[100], a2[100];
	long long a1[100];
	cout << "*******【欢迎进入学生选课系统】*******" << endl;
	cout << "      注册：                          " << endl;
	cout << "            学生（student）           " << endl;
	cout << "            教师（teacher）           " << endl;
	cout << "      登录:                           " << endl;
	cout << "            login                     " << endl;
	cout << "**************************************" << endl;
	cout << "选择您要进行的方式：";
	cout << endl;
	fstream file3("studentlogin.txt", ios::in);
	fstream file4("teacherlogin.txt",ios::in);
	while (file3 >> a1[t] >> s1[t])
	{
		t++;
	}
	while (file4 >> a2[m] >> s2[m])
	{
		m++;
	}
	i = t-1;
	k = m-1;
	file3.close();
	file4.close();
	string identity;
	fstream file1("studentlogin.txt", ios::app );
	fstream file2("teacherlogin.txt", ios::app );
	fstream file5("student.txt", ios::app);
	fstream file6("teacher.txt", ios::app);
	while (cin >> identity)
	{
		if (identity == "student")
		{
			i++;
			system("cls");
			cout << "姓名："; cin >> student[i].name; 
			cout << endl;file5<< student[i].name<<" ";
			cout << "年级："; cin >> student[i].grade;
			cout << endl; file5 << student[i].grade << " ";
		renumber:cout << "学号："; 
			cin >> student[i].schoolnumber; 
			file1 << endl;
			file1 << student[i].schoolnumber<<" ";
			cout << endl;
			file5 << student[i].schoolnumber <<endl;
			cout << "密码：";
			int i = 0;
			char ch;
			while ((ch = _getch()) != 13)
			{
				student[i].code += ch;	                                                                  
				cout << "*";
			}  
			file1 << student[i].code<<endl;
			cout << endl;
			file1.close();
			file5.close();
			file2.close();
			file6.close();
			system("cls");
		    Login();
		}
		else if (identity == "teacher")
		{
			k++;
			system("cls");
			cout << "姓名："; cin >> teacher[k].name; 
			file2 << teacher[k].name << " "; 
			cout << endl; file6 << teacher[k].name << " ";
			cout << "密码：";  int i = 0;
			char ch;
			while ((ch = _getch()) != 13)
			{
				teacher[k].code += ch;
				cout << "*";
			}
			file2 << teacher[k].code <<endl;
			cout << endl;
			cout << "请确认你所任教的学科："; 
			cin >> teacher[k].teachclass; 
			cout << endl; file6 << teacher[k].teachclass << " ";
			cout << "请输入您的课程容量：";
			cin >> teacher[k].classspace;cout << endl; 
			file6 << teacher[k].classspace << " ";
			cout << "请输入上课地点：";
			cin >> teacher[k].place; cout << endl;
			file6 << teacher[k].place <<endl;
			file1.close();
			file2.close();
			file5.close();
			file6.close();
			system("cls"); 
			Login();
		}
		else if (identity == "Login")
		{
			file1.close();
			file2.close();
			file5.close();
			file6.close();
			Login();
		}
		else
		{
			cout << "身份识别错误" << endl;
			continue;
		}

	}
}
void menu1();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
void saveall()
{
	char s[80];
	ifstream file1;
	ofstream file2;
	file1.open("C:\\studentcontrol\\studentwite.txt", ios::in);
	file2.open("C:\\studentcontrol\\student.txt", ios::app);
	while (!file1.eof())
	{
		file1.getline(s, sizeof(s),'\n');
		file2 << s << endl;
	}
	file1.close();
	file2.close();
}
void save()
{
	ofstream file1;
	file1.open("C:\\studentcontrol\\studentwite.txt", ios::out);
	file1 << student[i].name << " " << student[i].grade << " " << student[i].schoolnumber << " ";
		file1 << student[i].studentclass << " ";
	file1 << endl;
	file1.close();
}
void Studentadd1()
{
	int m=0,j,n=0,q,w;
	char ch;
	ifstream file("student.txt", ios::in);
	Student s[100];
	while (file >> student[m].name >> student[m].grade >> student[m].schoolnumber)
	{
		m++;
	}
	string c;
		cout << "********************************" << endl;
		cout << "                                " << endl;
		cout << " 可选课程：                     " << endl;
		cout << "           chinese              " << endl;
		cout << "           math                 " << endl;
		cout << "           history              " << endl;
		cout << "           english              " << endl;
		cout << "           pe                   " << endl;
		cout << "                                " << endl;
		cout << "********************************" << endl;
		while (cin >> student[i].studentclass[n])
		{
			for (q = 0; q < n; q++)
			{
				if (student[i].studentclass[q] == student[i].studentclass[n])
				{
					cout << "不能重复选课，请再次输入：" << endl;
					continue;
				}
			}
			if (student[i].studentclass[n] != "chinese"&&student[i].studentclass[n] != "math"&&student[i].studentclass[n] != "history"&&student[i].studentclass[n] != "english"&&student[i].studentclass[n] != "pe")
			{
				cout << "没有该课程，请重新输入" << endl;
			}
			else
			{
				if (student[i].studentclass[n] == "chinese")c1++;
				if (student[i].studentclass[n] == "math")m1++;
				if (student[i].studentclass[n] == "history")h1++;
				if (student[i].studentclass[n] == "english")e1++;
				if (student[i].studentclass[n] == "pe")p1++;
				cout << "是否继续选课?(yes/no)" << endl;
				cin >> c;
				if (c == "yes")
				{
					n++;
					continue;
				}
				else
				{
					n++;
					file.close();
					ofstream file1("student.txt", ios::out);
					for (j = 0; j <= m; j++)
					{
						file1 << student[j].name << " " << student[j].grade << " " << student[j].schoolnumber << " ";
						for (q = 0; q < n; q++)
							file1 << student[j].studentclass[q] << " ";
						file1 << endl;
					}
					student[i].classes = n;
					file1.close();
					menu1();
				}
			}
		}
}
void Studentfind()
{
	int time = 2,j;
	string c;
	cout << "********************************" << endl;
	cout << " 已选课程：                     " << endl;
	for (j = 0; j < student[i].classes; j++)
		cout << student[i].studentclass[j] << endl;
	cout << i << endl;
	cout << "********************************" << endl;
		cout << "是否返回主菜单"<<endl;
		cin >> c;
		if (c == "是")
			return;
		else
			Sleep(time * 1000);
}
void Studentdelet()
{
	int time = 2,m=0,j,q,w;
	string c,s,b;
	/*if (student[i].studentclass == "Chinese")c1--;
	if (student[i].studentclass == "Math")m1--;
	if (student[i].studentclass == "History")h1--;
	if (student[i].studentclass == "English")e1--;
	if (student[i].studentclass == "PE")p1--;
	student[i].studentclass = "none";*/
	ifstream file("student.txt", ios::in);
	while (file >> student[m].name >> student[m].grade >> student[m].schoolnumber)
	{
		m++;
	}
	deletec:cout << "你要删除的课程：" << endl;
	cin >> c;
	for (j = 0; j < student[i].classes; j++)
	{
		if (student[i].studentclass[j] == c)
		{
			for (q =j; q < student[i].classes - 1; q++)
				student[i].studentclass[q] = student[i].studentclass[q + 1];
			cout << "是否继续删除" << endl;
			cin >> s;
			if (s == "yes")
				goto deletec;
			else
			{
					ofstream file1("student.txt", ios::out);
				for (q = 0; q <= m; j++)
				{
					file1 << student[q].name << " " << student[q].grade << " " << student[q].schoolnumber << " ";
					for (w = 0; w < student[i].classes - 1; w++)
						file1 << student[q].studentclass[w] << " ";
					file1 << endl;
					student[i].classes--;
					menu1();
				}
			}
		}
	}
}
void changecode()
{
	string s;
	string d;
	string b;
	int m=0,j;
	cs:cout << "请输入新密码：";
	 int i = 0;
	char ch;
	while ((ch = _getch()) != 13)
	{
		s += ch;
		cout << "*";
	}  cout << endl;
	cout << "请再次确认密码：";
	 int k = 0;
	char c;
	while ((c = _getch()) != 13)
	{
		d +=c;
		cout << "*";
	}  cout << endl;
	if (s == d)
		student[i].code=s;
	else
	{
		cout << "输入不一致，请重新输入：" << endl;
		goto cs;
	}
	cout << "是否验证新密码（是/否）" << endl;
	cin >> b;
	if (b == "是")
	{
		cout << student[i].code << endl;
		ifstream file1("studentlogin.txt", ios::in);
		while (file1 >> student[m].schoolnumber >> student[m].code)
		{
			m++;
		}
		student[i].code = s;
		file1.close();
		ofstream file("studentlogin.txt", ios::out);
		for (j = 0; j < m; j++)
			file << student[j].schoolnumber << " " << student[j].code << endl;
		int time = 3;
		Sleep(time * 1000);
		menu1();
	}
	else
		menu1();
}
void menu1()
{
	string order;
	cout << "********************************" << endl;
	cout << "                                " << endl;
	cout << "            1 开始选课          " << endl;
	cout << "            2 查看选课情况      " << endl;
	cout << "            3 退课              " << endl;
	cout << "            4 修改密码          " << endl;
	cout << "            5 退出系统          " << endl;
	cout << "                                " << endl;
	cout << "********************************" << endl;
		tt:cin >> order;
		if (order == "1")
		{
			Studentadd1();
		}
		if (order == "2")
		{
			Studentfind();
			menu1();
		}
		if (order == "3")
		{
			Studentdelet();
			save();
			menu1();
		}
		if (order == "4")
		{
			changecode();
		}
		if (order == "5")
		{
			//saveall();
			regis();
		}
		else
		{
			cout << "请重新输入：" << endl;
			goto tt;
		}
}
void menu2();
void teacheradd()
{
	ofstream file1;
	file1.open("student.txt", ios::app);
	string c;
	cout << "请输入您要添加的学生信息" << endl;
	cout << "姓名："; cin >> student[i].name;
	file1 << student[i].name << " ";
	cout << endl;
	cout << "年级：";
	cin >> student[i].grade; file1 << student[i].grade << " "; 
	cout << endl;
	cout << "学号："; 
	cin >> student[i].schoolnumber; 
	file1 << student[i].schoolnumber << " "; 
	cout << endl;
	/*cout << "是否添加入本课程？（是/否）" << endl;
	cin >> c;
	if (c == "是")
	{
		/*student[i].studentclass =teacher[k].teachclass;
		file1 << student[i].studentclass << endl;
		if (student[i].studentclass == "chinese")c1++;
		if (student[i].studentclass == "math")m1++;
		if (student[i].studentclass == "history")h1++; 
		if (student[i].studentclass == "english")e1++;
		if (student[i].studentclass == "pe")p1++;
	}
	else if (c == "否")
	{
		cout << "请输入要添加的课程" << endl;
		cin >> student[i].studentclass;
		file1 << student[i].studentclass <<endl;
		if (student[i].studentclass == "chinese")c1++; 
		if (student[i].studentclass == "math")m1++;
		if (student[i].studentclass == "history")h1++; 
		if (student[i].studentclass == "english")e1++;
		if (student[i].studentclass == "pe")p1++;
	}*/
	file1.close();
	menu2();
	
}
void findall()
{
	char s[1000];
	ifstream file1;
	file1.open("C:\\studentcontrol\\student.txt", ios::in);
	while (!file1.eof())
	{
		file1.getline(s, sizeof(s), '\n');
		cout << s << endl;
	}
	file1.close();
	menu2();
}
void findclass()
{
	if (teacher[k].teachclass == "chinese")cout << c1<<endl; 
	if (teacher[k].teachclass == "math")cout << m1 << endl;
	if (teacher[k].teachclass == "history")cout << h1 << endl; 
	if (teacher[k].teachclass == "english")cout << e1 << endl;
	if (teacher[k].teachclass == "pe")cout << p1 << endl;
 	menu2();
}
void teacherchange()
{
	string s;
	string d;
	string b;
   cs:cout << "请输入新密码：";
	cin >> s; s = _getch(); cout << endl;
	cout << "请再次确认密码：";
	cin >> d; d = _getch(); cout << endl;
	if (s == d)
		student[i].code = s;
	else
	{
		cout << "输入不一致，请重新输入：" << endl;
		goto cs;
	}
	cout << "是否验证新密码（是/否）" << endl;
	cin >> b;
	if (b == "是")
	{
		cout << student[i].code << endl;
		int time = 3;
		Sleep(time * 1000);
		menu1();
	}
	else
		menu1();
}
void menu2()
{
	string order; 
	cout << "********************************" << endl;
	cout << "                                " << endl;
	cout << "            1 添加新学生        " << endl;
	cout << "            1 查看选课信息      " << endl;
	cout << "            2 显示本课程信息    " << endl;
	cout << "            3 查看学生信息      " << endl;
	cout << "            4 修改密码          " << endl;
	cout << "            5  退出             " << endl;
	cout << "********************************" << endl;
	gg:cin >> order;
	if (order == "1")
	{
		teacheradd();
	}
	if (order == "2")
	{
		findall();
	}
	if (order == "3")
	{
		findclass();
	}
	if (order == "4")
	{
		teacherchange();
	}
	if (order == "5")
	{
		regis();
		k++;
	}
	else
	{
		cout << "请重新输入：" << endl;
		goto gg;
	}
	
}
void Login()
{
	int n,t=0,m=0,j,q;
	int time=2;
	string s1[100],s2[100],a2[100];
	long long a1[100];
	long long d;
	string c;
	int f = 1;
	string b;
	ifstream file1;
	ifstream file2;
	file1.open("studentlogin.txt", ios::in);
	file2.open("teacherlogin.txt", ios::in);
	file1.seekg(0, ios::beg); 
	file2.seekg(0, ios::beg);
	if (!file1)
	{
		cout << "file could not be open" << endl;
		abort();
	}
	if (!file2)
	{
		cout << "file could not be open" << endl;
		abort();
	}
	while (file1 >> a1[t] >> s1[t])
	{
		t++;
	}
	while (file2 >> a2[m] >> s2[m])
	{
		m++;
	}
	cout << "**********【学生选课系统】************" << endl;
	cout << "                                      " << endl;
	cout << "            1  学生端                 " << endl;
	cout << "            2  教师端                 " << endl;
	cout << "                                      " << endl;
	cout << "**************************************" << endl;
	cin >> n;
	while (f)
	{
		if (n == 1)
		{
			cout << "学号:"; cin >> d; cout << endl;
			cout << "密码:";
			char ch;
			while ((ch = _getch()) != 13)
			{
				b += ch;
				cout << "*";
			}  cout << endl;
			for (j = 0; j < t; j++)
			{
				if (d == a1[j]&&b==s1[j])
				{
					file1.close();
					file2.close();
					i = j;
					cout << i << endl;
					menu1();
				}
				else if (d == a1[j])
				{
					reset:cout << "密码输入错误，请重新输入。" << endl;
					string passw;
					char r;
					while ((r = _getch()) != 13)
					{
						passw += r;
						cout << "*";
					}  cout << endl;
					{
						if (passw == s1[j])
						{
							file1.close();
							file2.close();
							i = j;
							cout << i<<endl;
							menu1();
						}
						else
							goto reset;
					}
				}
			}
			cout << "您未注册，请先注册。" << endl;
			cout << "是否注册？(yes/no)" << endl;
			string pass;
			cin >> pass;
			if(pass =="yes")
				regis();
			else
				regis();
				
		}
		if (n == 2)
		{
			cout << "姓名:"; cin >> c; cout << endl;
			cout << "密码:"; 
			char ch;
			while ((ch = _getch()) != 13)
			{
				b += ch;
				cout << "*";
			}  cout << endl;
			for (j = 0; j < m; j++)
			{
				if (c == a2[j] && b == s2[j])
				{
					k = j;
					menu1();
				}
				else if (c == a2[j]&&b!=s2[j])
				{
				resets:cout << "密码输入错误，请重新输入。" << endl;
					string passw;
					char r;
					while ((r = _getch()) != 13)
					{
						passw += r;
						cout << "*";
					}  cout << endl;
					for (q = 0; q < t; q++)
					{
						if (passw == s2[j])
						{
							k = j;
							menu1();
						}
						else
							goto resets;
					}
				}
			}
			cout << "您未注册，请先注册。" << endl;
			cout << "是否注册？(yes/no)" << endl;
			string password;
			cin >> password;
			if (password == "yes")
				regis();
			else
				regis();
		}
	}
}
int main()
{
	cout << "学生选课系统" << endl;
	//注册
	regis();
	//登录
	Login();
}
