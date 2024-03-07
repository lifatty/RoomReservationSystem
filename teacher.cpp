#include"teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int teaid, string name, string pwd)
{
	this->m_Teaid = teaid;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
void Teacher::operMenu()
{
	cout << "��ʦ��" << this->m_Name << endl;
	cout << "+-----------------------------+" << endl;
	cout << "|******** ��ӭ��ʦ��¼ *******| " << endl;
	cout << "+-----------------------------+" << endl;
	cout << "|*******  1. �鿴ԤԼ  *******|" << endl;
	cout << "|*******  2. ���ԤԼ  *******|" << endl;
	cout << "|*******  0. ע����¼  *******|" << endl;
	cout << "+-----------------------------+" << endl;
	cout << "���������Ĳ�����" << endl;
}

void Teacher::showMyOrder()
{
	orderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_size; i++) {
		cout << i + 1 << "��";

		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
		cout << "\tʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << "\tѧ�ţ�" << of.m_orderData[i]["stu_ID"];
		cout << "\t������" << of.m_orderData[i]["stu_name"];
		cout << "\t�����ţ�" << of.m_orderData[i]["room_ID"];
		string status = " ״̬��";
		if (of.m_orderData[i]["status"] == "1") status += "�����";
		else if (of.m_orderData[i]["status"] == "2") status += "ԤԼ�ɹ�";
		else if (of.m_orderData[i]["status"] == "-1") status += "ԤԼʧ�ܣ����δͨ��";
		else if (of.m_orderData[i]["status"] == "0") status += "ԤԼ��ȡ��";
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

void Teacher::validOrder()
{
	orderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����˵�ԤԼ��¼���£�" << endl;

	vector<int> vec;
	int index = 0;
	for (int i = 0; i < of.m_size; i++) {
		if (of.m_orderData[i]["status"] == "1") {
			vec.push_back(i);
			cout << ++index << "��";
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
			cout << "\tʱ��Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "\tѧ�ţ�" << of.m_orderData[i]["stu_ID"];
			cout << "\t������" << of.m_orderData[i]["stu_name"];
			cout << "\t�����ţ�" << of.m_orderData[i]["room_ID"];
			string status = " ״̬�������";
			cout << status << endl;
		}
	}

	cout << "������Ҫ��˵ļ�¼������0���أ�" << endl;
	int select = 0;
	int ret = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= vec.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽����" << endl;
				cout << "1 - ͨ��" << endl;
				cout << "2 - ��ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_orderData[vec[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[vec[select - 1]]["status"] = "-1";
				}
				of.updataOrder();
				cout << "������" << endl;
				break;
			}
		}
	}
}

