#pragma once
#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include"globelfile.h"
using namespace std;

class orderFile
{
public:
	orderFile();

	void updataOrder();

	map<int, map<string, string>> m_orderData;

	int m_size;
};