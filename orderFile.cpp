#include"orderFile.h"

orderFile::orderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string data;
	string interval;
	string StuId;
	string StuName;
	string roomId;
	string status;
	this->m_size = 0;

	while (ifs >> data && ifs >> interval && ifs >> StuId && ifs >> StuName && ifs >> roomId && ifs >> status)
	{

		string key;
		string value;
		map<string, string> m;

		int pos = data.find(":");
		if (pos != -1)
		{
			key = data.substr(0, pos);
			value = data.substr(pos + 1, data.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = StuId.find(":");
		if (pos != -1)
		{
			key = StuId.substr(0, pos);
			value = StuId.substr(pos + 1, StuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = StuName.find(":");
		if (pos != -1)
		{
			key = StuName.substr(0, pos);
			value = StuName.substr(pos + 1, StuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		this->m_orderData.insert(make_pair(m_size, m));
		this->m_size++;
	}
	ifs.close();

}

void orderFile::updataOrder()
{
	if (this->m_size == 0) {
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_size; i++) {
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stu_ID:" << this->m_orderData[i]["stu_ID"] << " ";
		ofs << "stu_name:" << this->m_orderData[i]["stu_name"] << " ";
		ofs << "room_ID:" << this->m_orderData[i]["room_ID"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << " ";
	}

	ofs.close();

}
