#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student
{
	string name;
	string surname;
	int age;
public:
	Student() = default;
	Student(const char* n, const char* sur, int a)
		: name(n), surname(sur), age(a) { }
	void Print() {
		cout << "Name: " << name << ", Surname: " << surname << ", Age: " << age << endl;
	}
	void SaveFile() {
		ofstream write("text1.txt");
		if (write.is_open()) {
			write << name << " " << surname << " " << age << endl;
			write.close();
		}
		else {
			cout << "error with file opening" << endl;
		}
	}
	void ReadFile()
	{
		ifstream read("text1.txt");
		if (read.is_open()) {
			read >> name >> surname >> age;
			read.close();
		}
		else {
			cout << "error with file opening" << endl;
		}
	}
};


int main() {
	Student st("vakera", "dad", 16);
	st.SaveFile();
	st.ReadFile();
	st.Print();
}