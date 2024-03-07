#pragma once
#include<iostream>
#include "identity.h"
#include<fstream>
#include"orderFile.h"
#include"globelfile.h"
#include"computerRoom.h"
using namespace std;

class Student : public identity
{
public:
	Student();

	Student(int id, string name, string pwd);

	virtual void operMenu();

	void getOrder();//获取机房信息

	void applyOrder();//申请预约

	void showMyOrder();//查看预约

	void showAllOrder();//查看所有人的预约

	void cancelOrder();//取消预约

	vector<computerRoom> vCom;

	int m_Id;
};