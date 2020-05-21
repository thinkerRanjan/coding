#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class People
{
private:

protected:
	string name;
	int age;
public:
	People()
	{
		cout << "People default constructor called\n";
	}

	People(string n, int a):name(n), age(a)
	{
		cout << "People constructor called\n";	
	}

	~People()
	{
		cout << "People destructor called\n";
	}

	int getAge()
	{
		return age;
	}

	void setAge(int x)
	{
		age = x;
	}

	void judge()
	{
		if(age >= 70)
			cout << "You are old :)\n";
		else
			cout << "You are not that old\n";
	}
};

class Faculty : public People
{
private:
	string department;
public:
	Faculty()
	{
		cout << "Faculty default constructor called\n";
	}

	Faculty(string n, int a, string dept)
	{
		name = n;
		age = a;
		dept = department;
		cout << "Faculty constructor called\n";
	}

	~Faculty()
	{
		cout << "Faculty destructor called\n";
	}

};

class Student: public People
{
private:
	string stream;
public:
	Student()
	{
		cout << "Student default constructor called\n";
	}
	Student(string n, int a, string s)
	{
		name = n;
		age = a;
		stream = s;
		cout << "Student constructor called\n";
	}

	~Student()
	{
		cout << "Student destructor called\n";
	}

};


class Experimenter:public Faculty, public Student
{
private:
	string labName;
	Experimenter()
	{
		cout << "Experimenter default constructor called\n";
	}
	Experimenter(string n, int a, string dept, string ln)
	{
		labName = ln;
		name = n;
		age = a;
		department = dept;
		cout << "Experimenter constructor called\n";
	}
	
	~Experimenter()
	{
		cout << "Experimenter destructor called\n";
	}


}



int main(int argc, char** argv)
{
	int age;
       	string name, dept, stream;
	int kind;

	cout << "\nEnter your name: ";
	cin >> name;
	cout << "Enter the age: ";
	cin >> age;
	cout << "Are you a faculty member or a student?(0 or 1): ";
	cin >> kind;
	cout << endl;

	cout << "-----------------Operating on objects------------------------\n";
	if(!kind)
	{	
		cout << "Enter your department: ";
		cin >> dept;
		cout << endl;
		
		Faculty *p1 = new Faculty(name, age, dept);
		cout << p1->getAge() << endl;			
		delete(p1);
	}
	else
	{
		cout << "Enter your stream: ";
		cin >> stream;
		Student *s1 = new Student(name, age, stream);
		cout << s1->getAge() << endl;
		delete(s1);
	}

	Experimenter *e1 = new Experimenter();

}
