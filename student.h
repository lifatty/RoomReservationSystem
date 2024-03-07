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

	void getOrder();//��ȡ������Ϣ

	void applyOrder();//����ԤԼ

	void showMyOrder();//�鿴ԤԼ

	void showAllOrder();//�鿴�����˵�ԤԼ

	void cancelOrder();//ȡ��ԤԼ

	vector<computerRoom> vCom;

	int m_Id;
};