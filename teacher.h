#pragma once
#include<iostream>
#include"identity.h"
#include"orderFile.h"
#include<vector>

using namespace std;

class Teacher : public identity
{
public:
	Teacher();

	Teacher(int teaid, string name, string pwd);

	virtual void operMenu(); 

	void showMyOrder();//�鿴ԤԼ

	void validOrder();

	int m_Teaid;
};