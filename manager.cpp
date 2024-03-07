#include"manage.h"


Manager::Manager()
{
	

}


	

Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();
}

void Manager::operMenu()
{
	cout << "����Ա��" << this->m_Name << endl;
	cout << "+-----------------------------+" << endl;
	cout << "|******* ��ӭ����Ա��¼ ******| " << endl;
	cout << "+-----------------------------+" << endl;
	cout << "|*******  1. ����˺�  *******|" << endl;
	cout << "|*******  2. �鿴�˺�  *******|" << endl;
	cout << "|*******  3. �鿴����  *******|" << endl;
	cout << "|*******  4. ���ԤԼ  *******|" << endl;
	cout << "|*******  0. ע����¼  *******|" << endl;
	cout << "+-----------------------------+" << endl;
	cout << "���������Ĳ�����" << endl;
}


void Manager::addPerson()
{
	cout << "������Ҫ��ӵ��˺����ͣ�" << endl;
	cout << "1 - ѧ������" << endl;
	cout << "2 - ��    ʦ" << endl;

	string filename;
	string tip;
	ofstream ofs;
	string errTip;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		filename = STUDENT_FILE;
		tip = "please enter student id";
		errTip = "ѧ��ѧ���ظ����������룡";

	}
	else if (select == 2)
	{
		filename = TEACHER_FILE;
		tip = "please enter teacher id";
		errTip = "��ְ�����ظ������������룡";
	}
	else
	{
		cout << "bad request!" << endl;
		system("pause");
		system("cls");
		return;
	}

	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while(true)
	{
		cin >> id;

		bool ret =	this->checkRepeat(id, select);
		if (ret)
		{
			cout << errTip << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{

			break;
		}
	}
	cout << "name :" << endl;
	cin >> name;
	cout << "Passwd:" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;
	cout << "successful!" << endl;

	system("pause");
	system("cls");
	ofs.close();

	this->initVector();

}
void printStudent(Student& s)
{
	cout << "ѧ��" << s.m_Id <<" " << "����" << s.m_Name << " " << "����" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "ְ����" << t.m_Teaid << " " << "����" << t.m_Name << " " << "����" << t.m_Pwd << endl;
}
void Manager::showPerson()
{
	cout << "��ѡ��鿴�����ݣ�" << endl;
	cout << "1 - �鿴ѧ���˺�" << endl;
	cout << "2 - �鿴��ʦ�˺�" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		if(!vStu.empty())
		{
			for_each(vStu.begin(), vStu.end(), printStudent);
		}
		else
		{
			cout << "the student vector is null" << endl;
		}
	}
	else if(select == 2)
	{
		if (!vTea.empty())
		{
			for_each(vTea.begin(), vTea.end(), printTeacher);
		}
		else
		{
			cout << "the teacher vector is null" << endl;
		}

	}
	system("pause");
	system("cls");
}

void Manager::getComputer()//��ȡ������Ϣ
{
	ifstream ifs;
	ifs.open(ROOMS_FILE, ios::in);
	
	computerRoom c;
	while (ifs >> c.m_ComId && ifs>>c.m_MaxNum)
	{
		comRoom.push_back(c);
	}
	cout << "��ǰ��������Ϊ��" << comRoom.size() << endl;
	ifs.close();
}
void Manager::showComputer()//�鿴������Ϣ
{
	for (vector<computerRoom>::iterator it = comRoom.begin(); it != comRoom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId << "�������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::clearfile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "���ԤԼ��Ϣ���" << endl;
	system("pause");
	system("cls");
	return;
}
void  Manager::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "open failed!" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs>>s.m_Id && ifs>>s.m_Name && ifs>>s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "student number:" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_Teaid && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "teacher number:" << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_Teaid)
			{
				return true;
			}
		}
	}
	return false;
}