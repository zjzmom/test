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
	ofs << "姓名： " << this->m_name<< "\t" << "学号： " << this->m_num << "\t" << "数学成绩： " << this->m_math << "\t" << "英语成绩: " << this->m_English;
	ofs.close();
}

void student::in()
{
	ifstream ifs;
	ifs.open("student.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
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
		cout << "文件打开失败" << endl;
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
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入学号" << endl;
	cin >> num;
	cout << "请输入数学成绩" << endl;
	cin >> math;
	cout << "请输入英语成绩" << endl;
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