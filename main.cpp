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

		if (select == 1)//����˺�
		{
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			man->getComputer();
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			man->clearfile();
		}
		else//ע����¼
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

		if (select == 1)//����ԤԼ
		{
			Stu->getOrder();
			Stu->applyOrder();
		}
		else if (select == 2)//�ҵ�ԤԼ
		{
			Stu->showMyOrder();
		}
		else if (select == 3)//����ԤԼ
		{
			Stu->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			Stu->cancelOrder();
		}
		else//ע����¼
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

		if (select == 1)//�鿴ԤԼ
		{
			Tea->showMyOrder();
		}
		else if (select == 2)//���ԤԼ
		{
			Tea->validOrder();
		}
		else//ע����¼
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
		cout << "|****** ��ӭʹ��ԤԼϵͳ *****|" << endl;
		cout << "+-----------------------------+" << endl;
		cout << "|*******  1. ѧ������  *******|" << endl;
		cout << "|*******  2. ��    ʦ  *******|" << endl;
		cout << "|*******  3. �� �� Ա  *******|" << endl;
		cout << "|*******  0. ��    ��  *******|" << endl;
		cout << "+-----------------------------+" << endl;
		cout << "���������ѡ��:";
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
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			break;
		}
		

	}


	system("pause");
}