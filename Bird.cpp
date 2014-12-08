// Bird.cpp
// Contains the definitions for the Bird class.
#ifndef BIRD_CPP
#define BIRD_CPP
#include "Bird.h"

Bird::Bird() 
{
	setName("");
	setIdentity(-1);
}

Bird::Bird(string birdName, int birdID) 
{
	setName(birdName);
	setIdentity(birdID);
}

Bird::Bird(const Bird& bird) 
{
	setName(bird.name);
	setIdentity(bird.identity);
}

string Bird::getName() const 
{
	return(name);
}

int Bird::getIdentity() const
{
	return(identity);
}

void Bird::setName(string birdName) 
{
	name = birdName;
}

void Bird::setIdentity(int birdID) 
{
	identity = birdID;
}

bool Bird::operator==(const Bird& that) const 
{
	if(getIdentity() == that.getIdentity() && getName() == that.getName()) 
	{
		return(true);
	}
	return(false);
}

bool Bird::operator!=(const Bird& that) const 
{
	if(!(*this == that)) 
	{
		return(true);
	}
	return(false);
}

bool Bird::operator<(const Bird& that) const 
{
	if(getIdentity() < that.getIdentity())
	{
		return(true);
	}
	return(false);
}

bool Bird::operator>(const Bird& that) const 
{
	if(getIdentity() > that.getIdentity()) 
	{
		return(true);
	}
	return(false);
}

bool Bird::operator<=(const Bird& that) const 
{
	if((getIdentity() < that.getIdentity()) || *this == that) 
	{
		return(true);
	}
	return(false);
}

bool Bird::operator>=(const Bird& that) const 
{
	if((getIdentity() > that.getIdentity()) || *this == that) 
	{
		return(true);
	}
	return(false);
}

ostream& operator<<(ostream& sout, const Bird& bird) 
{
	sout << bird.getName() << bird.getIdentity();
	return(sout);
}

istream& operator>>(istream& sin, Bird& bird) 
{
	sin >> bird.name;
	sin >> bird.identity;
	return(sin);
}
#endif