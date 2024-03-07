#include<iostream>
#include"identity.h"
#include"globelfile.h"
#include<string>
#include<fstream>
#include"student.h"
#include"teacher.h"
#include"manage.h"
using namespace std;

void ManagerMenu(identity*& manager)
{
	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;

		int select;
		cin >> select;

		if (select == 1)//添加账号
		{
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			man->getComputer();
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			man->clearfile();
		}
		else//注销登录
		{
			delete manager;
			cout << "logout is successful" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void StudentMenu(identity*& student)
{
	while (true)
	{
		student->operMenu();
		Student* Stu = (Student*)student;

		int select;
		cin >> select;

		if (select == 1)//申请预约
		{
			Stu->getOrder();
			Stu->applyOrder();
		}
		else if (select == 2)//我的预约
		{
			Stu->showMyOrder();
		}
		else if (select == 3)//所有预约
		{
			Stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			Stu->cancelOrder();
		}
		else//注销登录
		{
			delete student;
			cout << "logout is successful" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void TeacherMenu(identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();
		Teacher* Tea = (Teacher*)teacher;

		int select;
		cin >> select;

		if (select == 1)//查看预约
		{
			Tea->showMyOrder();
		}
		else if (select == 2)//审核预约
		{
			Tea->validOrder();
		}
		else//注销登录
		{
			delete teacher;
			cout << "logout is successful" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//void confirmation(ifstream& ifs, int& id, string& name, string& pwd, Identity* person, int type)
void LoginIn(string filename, int type)
{
	identity* person = NULL;
	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		cout << "the file is not exit!" << endl;
		ifs.close();
		return; 
	}

	int id;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "please input student id_num:" ;
		cin >> id;
	}
	if (type == 2)
	{
		cout << "please input teacher id_num:";
		cin >> id;
	}
	cout << "please input user_name:";
	cin >> name;
	cout << "please input user_passwd:";
	cin >> pwd;

	if (type == 1)//student
	{
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "student have login!" << endl;
				

				system("pause");
				system("cls");

				person = new Student(id, name, pwd);
				StudentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)//teacher
	{
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "teacher have login!" << endl;
				

				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				//teacher menu
				return;
			}
		}
	}
	else if (type == 3)//manager
	{
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "manager have login!" << endl;
				

				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				ManagerMenu(person);	
				return;
			}
		}
	}
	cout << "failed!" << endl;
	
	system("pause");
	system("cls");
	return;

}

int main()
{
	int select = 0;

	while(true)
	{
		cout << "+-----------------------------+" << endl;
		cout << "|****** 欢迎使用预约系统 *****|" << endl;
		cout << "+-----------------------------+" << endl;
		cout << "|*******  1. 学生代表  *******|" << endl;
		cout << "|*******  2. 教    师  *******|" << endl;
		cout << "|*******  3. 管 理 员  *******|" << endl;
		cout << "|*******  0. 退    出  *******|" << endl;
		cout << "+-----------------------------+" << endl;
		cout << "请输入你的选择:";
		cin >> select;
		switch (select) {
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "had exit! " << endl;
			system("pause");
			//system("cls");
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
		

	}


	system("pause");
}