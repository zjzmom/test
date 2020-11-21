#include<iostream>
using namespace std;
#include<string>
#include<fstream>

class student
{
public:
	student()
	{
		m_English = 0;
		m_math = 0;
		m_num = 0;
		m_name = " ";
	}
	student(string name, int num, int math, int English)
	{
		m_English = English;
		m_math = math;
		m_num = num;
		m_name = name;
	}
	void save();
	void in();
	void read();
	void binsave();
private:
	string m_name;
	int m_num;
	int m_math;
	int m_English;
};

void student::save()
{
	ofstream ofs;
	ofs.open("student.txt", ios::app);
	ofs << "������ " << this->m_name<< "\t" << "ѧ�ţ� " << this->m_num << "\t" << "��ѧ�ɼ��� " << this->m_math << "\t" << "Ӣ��ɼ�: " << this->m_English;
	ofs.close();
}

void student::in()
{
	ifstream ifs;
	ifs.open("student.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	char c;
	while ((c = ifs.get()) != EOF)//EOF end of file
	{
		cout << c;
	}
	ifs.close();
}

void student:: binsave()
{
	ofstream ofs;
	ofs.open("student1.txt", ios::app| ios::binary);
	ofs.write((const char*)&*this, sizeof(student));
	ofs.close();
}
void student::read()
{
	ifstream ifs;
	ifs.open("student1.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	student s;
	ifs.read((char*)&s,sizeof(student));
	ifs.close();
}


void test()
{
	string name;
	int math, num, English;
	cout << "����������" << endl;
	cin >> name;
	cout << "������ѧ��" << endl;
	cin >> num;
	cout << "��������ѧ�ɼ�" << endl;
	cin >> math;
	cout << "������Ӣ��ɼ�" << endl;
	cin >> English;
	student stu(name,num,math,English);
	stu.save();
	stu.binsave();
	stu.in();
	stu.read();
}


int main()
{
	test();

	system("pause");
	return 0;

}