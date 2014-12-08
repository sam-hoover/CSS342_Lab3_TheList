// Child.h
// Contains the declarations for the Child class.
#ifndef CHILD_H
#define CHILD_H
#include <iostream>
#include <string>
using namespace std;

class Child 
{
	friend ostream& operator<<(ostream& sout, const Child& that);
	friend istream& operator>>(istream& sin, Child& that);

	public:
		Child();
		Child(string first, string last, int yearsOld);
		Child(string first, string last, int yearsOld, bool naughty);
		Child(const Child& child);

		string getFirstName() const;
		string getLastName() const;
		int getAge() const;
		bool getBehavior() const;
		void setFirstName(string first);
		void setLastName(string last);
		void setAge(int yearsOld);
		void setBehavior(bool naughty);

		bool operator==(const Child& that) const;
		bool operator!=(const Child& that) const;
		bool operator<(const Child& that) const;
		bool operator>(const Child& that) const;
		bool operator<=(const Child& that) const;
		bool operator>=(const Child& that) const;

	private:
		string firstName;
		string lastName;
		int age;
		bool behavior;
};

#endif