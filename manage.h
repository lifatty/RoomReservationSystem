#pragma once
#include<iostream>
#include<fstream>

#include<vector>
#include<algorithm>
#include"identity.h"
#include"student.h"
#include"teacher.h"
#include"globelfile.h"
#include"computerRoom.h"
using namespace std;

class Manager : public identity
{
public:
	Manager();

	Manager(string name, string pwd);

	
	virtual void operMenu();


	void addPerson();

	void showPerson();

	void getComputer();

	void showComputer();

	void clearfile();

	void initVector();

	vector<Student> vStu;

	vector<Teacher> vTea;

	vector<computerRoom> comRoom;


	bool checkRepeat(int id, int type);

};