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
	cout << "学生代表：" << this->m_Name << endl;
	cout << "+-----------------------------+" << endl;
	cout << "|****** 欢迎学生代表登录 *****| " << endl;
	cout << "+-----------------------------+" << endl;
	cout << "|*******  1. 申请预约  *******|" << endl;
	cout << "|*******  2. 我的预约  *******|" << endl;
	cout << "|*******  3. 所有预约  *******|" << endl;
	cout << "|*******  4. 取消预约  *******|" << endl;
	cout << "|*******  0. 注销登录  *******|" << endl;
	cout << "+-----------------------------+" << endl;
	cout << "请输入您的操作：" << endl;
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

	cout << "机房开放时间为周一至周五!" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1 - 周一" << endl;
	cout << "2 - 周二" << endl;
	cout << "3 - 周三" << endl;
	cout << "4 - 周四" << endl;
	cout << "5 - 周五" << endl;

	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		else
			cout << "输入有误" << endl;
	}

	cout << "请输入申请预约的时段：" << endl;
	cout << "1 - 上午" << endl;
	cout << "2 - 下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		else
			cout << "输入有误" << endl;
	}

	cout << "请输入申请预约的机房：" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "号机房，容量：" << vCom[i].m_MaxNum << endl;
	}
	/*
	cout << "1 - 1号机房，容量：" << vCom[0].m_MaxNum << endl;
	cout << "2 - 2号机房，容量：" << vCom[1].m_MaxNum << endl;
	cout << "3 - 3号机房，容量：" << vCom[2].m_MaxNum << endl;
	*/

	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) break;
		else cout << "输入有误请重新输入！" << endl;
	}

	cout << "预约成功，审核中..." << endl;

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
		cout << "预约为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		
		if (atoi(of.m_orderData[i]["StuId"].c_str()) == this->m_Id)
		{
			cout << "预约日期：周" << of.m_orderData[i]["data"];
			cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "机房号" << of.m_orderData[i]["roomId"];
			string status = "状态：";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "预约失败";
			}
			else if (of.m_orderData[i]["status"] == "0")
			{
				status += "取消预约";
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
		cout << "预约为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << " 、";
		
		cout << "预约日期：周" << of.m_orderData[i]["data"];
		cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "机房" << of.m_orderData[i]["roomId"];
		string status = "状态：";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		else if (of.m_orderData[i]["status"] == "0")
		{
			status += "取消预约";
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
		cout << "预约为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "您的预约记录如下：" << endl;

	vector<int> vec;
	int index = 1;
	for (int i = 0; i < of.m_size; i++)
	{
		if (atoi(of.m_orderData[i]["StuId"].c_str()) == this->m_Id)
		{
			//审核中或预约成功的记录进行取消
			if(of.m_orderData[i]["status"]=="1"|| of.m_orderData[i]["status"] == "2")
			{
				vec.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周" << of.m_orderData[i]["data"];
				cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << "机房" << of.m_orderData[i]["roomId"];
				string status = "状态：";
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "预约成功";
				}
				else if (of.m_orderData[i]["status"] == "-1")
				{
					status += "预约失败";
				}
				else if (of.m_orderData[i]["status"] == "0")
				{
					status += "取消预约";
				}
				cout << status << endl;
			}
		}
	}

	cout << "请输入要取消的记录，输入0返回：" << endl;
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
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;	
	}
	system("pause");
	system("cls");
}