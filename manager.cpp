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
	cout << "管理员：" << this->m_Name << endl;
	cout << "+-----------------------------+" << endl;
	cout << "|******* 欢迎管理员登录 ******| " << endl;
	cout << "+-----------------------------+" << endl;
	cout << "|*******  1. 添加账号  *******|" << endl;
	cout << "|*******  2. 查看账号  *******|" << endl;
	cout << "|*******  3. 查看机房  *******|" << endl;
	cout << "|*******  4. 清空预约  *******|" << endl;
	cout << "|*******  0. 注销登录  *******|" << endl;
	cout << "+-----------------------------+" << endl;
	cout << "请输入您的操作：" << endl;
}


void Manager::addPerson()
{
	cout << "请输入要添加的账号类型：" << endl;
	cout << "1 - 学生代表" << endl;
	cout << "2 - 教    师" << endl;

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
		errTip = "学生学号重复，重新输入！";

	}
	else if (select == 2)
	{
		filename = TEACHER_FILE;
		tip = "please enter teacher id";
		errTip = "教职工号重复，请重新输入！";
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
	cout << "学号" << s.m_Id <<" " << "姓名" << s.m_Name << " " << "密码" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "职工号" << t.m_Teaid << " " << "姓名" << t.m_Name << " " << "密码" << t.m_Pwd << endl;
}
void Manager::showPerson()
{
	cout << "请选择查看的内容：" << endl;
	cout << "1 - 查看学生账号" << endl;
	cout << "2 - 查看教师账号" << endl;

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

void Manager::getComputer()//获取机房信息
{
	ifstream ifs;
	ifs.open(ROOMS_FILE, ios::in);
	
	computerRoom c;
	while (ifs >> c.m_ComId && ifs>>c.m_MaxNum)
	{
		comRoom.push_back(c);
	}
	cout << "当前机房数量为：" << comRoom.size() << endl;
	ifs.close();
}
void Manager::showComputer()//查看机房信息
{
	for (vector<computerRoom>::iterator it = comRoom.begin(); it != comRoom.end(); it++)
	{
		cout << "机房编号：" << it->m_ComId << "机房最大容量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::clearfile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空预约信息完成" << endl;
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