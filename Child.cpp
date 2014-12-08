// Child.cpp
// Contains the definitions for the Child class.
#ifndef CHILD_CPP
#define CHILD_CPP
#include "Child.h"

Child::Child() 
{
	setFirstName("");
	setLastName("");
	setAge(-1);
	setBehavior(true);
}

Child::Child(string first, string last, int yearsOld) 
{
	setFirstName(first);
	setLastName(last);
	setAge(yearsOld);
	setBehavior(true);
}

Child::Child(string first, string last, int yearsOld, bool naughty) 
{
	setFirstName(first);
	setLastName(last);
	setAge(yearsOld);
	setBehavior(naughty);
}

Child::Child(const Child& child) 
{
	setFirstName(child.firstName);
	setLastName(child.lastName);
	setAge(child.age);
	setBehavior(child.behavior);
}

string Child::getFirstName() const 
{
	return(firstName);
}

string Child::getLastName() const 
{
	return(lastName);
}

int Child::getAge() const 
{
	return(age);
}

bool Child::getBehavior() const 
{
	return(behavior);
}

void Child::setFirstName(string first) 
{
	firstName = first;
}

void Child::setLastName(string last) 
{
	lastName = last;
}

void Child::setAge(int yearsOld) 
{
	age = yearsOld;
}

void Child::setBehavior(bool naughty) 
{
	behavior = naughty;
}

bool Child::operator==(const Child& that) const 
{
	if(getLastName() == that.getLastName() && getFirstName() == that.getFirstName() && getAge() == that.getAge()) 
	{
		return(true);
	}
	return(false);
}

bool Child::operator!=(const Child& that) const 
{
	if(!(*this == that)) 
	{
		return(true);
	}
	return(false);
}

bool Child::operator<(const Child& that) const 
{
	if(lastName == that.lastName) 
	{
		if(firstName < that.firstName) 
		{
			return(true);
		}
	}
	if(lastName < that.lastName) 
	{
		return(true);
	}
	return(false);
}

bool Child::operator>(const Child& that) const 
{
	if((*this != that) && !(*this < that)) 
	{
		return(true);
	}
	return(false);
}

bool Child::operator<=(const Child& that) const 
{
	if(*this < that || *this == that)
	{
		return(true);
	}
	return(false);
}

bool Child::operator>=(const Child& that) const 
{
	if(*this > that || *this == that) 
	{
		return(true);
	}
	return(false);
}

ostream& operator<<(ostream& sout, const Child& that)
{
	sout << that.getFirstName() << that.getLastName() << that.getAge() << that.getBehavior();
	return(sout);
}

istream& operator>>(istream& sin, Child& that)
{
	sin >> that.firstName;
	sin >> that.lastName;
	sin >> that.age;
	return(sin);
}


#endif