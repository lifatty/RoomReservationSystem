#include"student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Student::operMenu()
{
	cout << "ѧ������" << this->m_Name << endl;
	cout << "+-----------------------------+" << endl;
	cout << "|****** ��ӭѧ�������¼ *****| " << endl;
	cout << "+-----------------------------+" << endl;
	cout << "|*******  1. ����ԤԼ  *******|" << endl;
	cout << "|*******  2. �ҵ�ԤԼ  *******|" << endl;
	cout << "|*******  3. ����ԤԼ  *******|" << endl;
	cout << "|*******  4. ȡ��ԤԼ  *******|" << endl;
	cout << "|*******  0. ע����¼  *******|" << endl;
	cout << "+-----------------------------+" << endl;
	cout << "���������Ĳ�����" << endl;
}
//vector<computerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++
void Student::getOrder()
{
	ifstream ifs;
	ifs.open(ROOMS_FILE, ios::in);
	
	computerRoom co;
	while (ifs >> co.m_ComId&& ifs >> co.m_MaxNum)
	{
		vCom.push_back(co);
	}
	ifs.close();
}

void Student::applyOrder()
{
	int data = 0;
	int interval = 0;
	int room = 0;

	cout << "��������ʱ��Ϊ��һ������!" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1 - ��һ" << endl;
	cout << "2 - �ܶ�" << endl;
	cout << "3 - ����" << endl;
	cout << "4 - ����" << endl;
	cout << "5 - ����" << endl;

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		else
			cout << "��������" << endl;
	}

	cout << "����������ԤԼ��ʱ�Σ�" << endl;
	cout << "1 - ����" << endl;
	cout << "2 - ����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		else
			cout << "��������" << endl;
	}

	cout << "����������ԤԼ�Ļ�����" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "�Ż�����������" << vCom[i].m_MaxNum << endl;
	}
	/*
	cout << "1 - 1�Ż�����������" << vCom[0].m_MaxNum << endl;
	cout << "2 - 2�Ż�����������" << vCom[1].m_MaxNum << endl;
	cout << "3 - 3�Ż�����������" << vCom[2].m_MaxNum << endl;
	*/

	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) break;
		else cout << "�����������������룡" << endl;
	}

	cout << "ԤԼ�ɹ��������..." << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "data:" << data << " ";
	ofs << "interval:" << interval << " ";
	ofs << "StuId:" << this->m_Id << " ";
	ofs << "StuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyOrder()
{
	orderFile of;
	if (of.m_size == 0)
	{
		cout << "ԤԼΪ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		
		if (atoi(of.m_orderData[i]["StuId"].c_str()) == this->m_Id)
		{
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
			cout << "ʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "������" << of.m_orderData[i]["roomId"];
			string status = "״̬��";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else if (of.m_orderData[i]["status"] == "0")
			{
				status += "ȡ��ԤԼ";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()
{
	orderFile of;
	if (of.m_size == 0)
	{
		cout << "ԤԼΪ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << " ��";
		
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
		cout << "ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << "����" << of.m_orderData[i]["roomId"];
		string status = "״̬��";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ��";
		}
		else if (of.m_orderData[i]["status"] == "0")
		{
			status += "ȡ��ԤԼ";
		}
		cout << status << endl;
		
	}
	system("pause");
	system("cls");
}

void Student::cancelOrder()
{
	orderFile of;
	if (of.m_size == 0)
	{
		cout << "ԤԼΪ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����ԤԼ��¼���£�" << endl;

	vector<int> vec;
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderData[i]["StuId"].c_str()) == this->m_Id)
		{
			//����л�ԤԼ�ɹ��ļ�¼����ȡ��
			if(of.m_orderData[i]["status"]=="1"|| of.m_orderData[i]["status"] == "2")
			{
				vec.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
				cout << "ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << "����" << of.m_orderData[i]["roomId"];
				string status = "״̬��";
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				else if (of.m_orderData[i]["status"] == "-1")
				{
					status += "ԤԼʧ��";
				}
				else if (of.m_orderData[i]["status"] == "0")
				{
					status += "ȡ��ԤԼ";
				}
				cout << status << endl;
			}
		}
	}

	cout << "������Ҫȡ���ļ�¼������0���أ�" << endl;
	int select = 0;
	
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= vec.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderData[vec[select-1]]["status"] = "0";
				of.updataOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;	
	}
	system("pause");
	system("cls");
}