// Bird.h
// Contains the class declarations for the Bird class.
#ifndef BIRD_H
#define BIRD_H
#include <iostream>
#include <string>
using namespace std;

class Bird 
{
	friend istream& operator>>(istream& sin, Bird& bird);
	friend ostream& operator<<(ostream& sout, const Bird& bird);

	public:
		Bird();
		Bird(string birdName, int birdID);
		Bird(const Bird& bird);

		string getName() const;
		int getIdentity() const;
		void setName(string birdName);
		void setIdentity(int birdID);

		bool operator<(const Bird& that) const;
		bool operator>(const Bird& that) const;
		bool operator<=(const Bird& that) const;
		bool operator>=(const Bird& that) const;
		bool operator==(const Bird& that) const;
		bool operator!=(const Bird& that) const;

	private:
		string name;
		int identity;
};

#endif