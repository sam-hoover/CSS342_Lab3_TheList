// ListDriver.cpp
// Contains main for the List342 class. Contains functions used to test
// List342 functionality.
#include "List342.h"
#include "Bird.h"
#include "Child.h"

void testInt();
void testBird();
void testChild();
void testBuildList();
void profTest();

int main() 
{
	cout << "INTEGER TEST" << endl << endl;
	testInt();
	cout << "any key to continue.";
	cin.get();
	system("cls");

	cout << "BIRD TEST" << endl << endl;
	testBird();
	cout << "any key to continue.";
	cin.get();
	system("cls");

	cout << "CHILD TEST" << endl << endl;
	testChild();
	cout << "any key to continue.";
	cin.get();
	system("cls");

	cout << "BUILDLIST TEST" << endl;
	testBuildList();
	cout << "any key to continue.";
	cin.get();
	system("cls");

	cout << "PROF TEST" << endl << endl;
	profTest();

	cout << "any key to exit.";
	cin.get();
	return(0);
}

void testInt() 
{
	int constructorTestNum = 7;
	int result;
	int target = 3;
	bool answer;
	List342<int> list;
	List342<int> list1(&constructorTestNum);
	List342<int> list2(list1);
	List342<int> list3;
	List342<int> list4;

	cout << "TESTING CONSTRUCTORS" << endl;
	cout << "list(): " << list << endl;
	cout << "list1(&7): " << list1 << endl;
	cout << "list2(list1): " << list2 << endl << endl;

	cout << "TESTING CLEAR LIST: list1 & list2" << endl;
	list1.ClearList();
	list2.ClearList();
	cout << "list: " << list << endl;
	cout << "list1: " << list1 << endl;
	cout << "list2: " << list2 << endl << endl;

	cout << "TESTING INSERT" << endl;
	int arr[7] = {1, 5, 4, 6, 2, 7, 3};
	for(int i = 0; i < 7; i++) 
	{
		cout << "list.Insert(" << arr[i] << ")" << endl;
		bool temp = list.Insert(&arr[i]);
		cout << "list: " << list << endl;
	}
	cout << endl;

	answer = list.Peek(target, result);
	cout << "TESTING PEEK" << endl;
	cout << "list.Peek(3): " << answer << endl;
	target = 19;
	answer = list.Peek(target, result);
	cout << "list.Peek(19): " << answer << endl;
	cout << "list: " << list << endl << endl;

	cout << "TESTING REMOVE" << endl;
	cout << "list: " << list << endl;
	target = 3;
	answer = list.Remove(target, result);
	cout << "list.Remove(3): " << answer << endl;

	cout << "list: " << list << endl;
	target = 1;
	answer = list.Remove(target, result);
	cout << "list.Remove(1): " << answer << endl;

	cout << "list: " << list << endl;
	target = 7;
	answer = list.Remove(target, result);
	cout << "list.Remove(7): " << answer << endl;

	cout << "list: " << list << endl;
	target = 19;
	answer = list.Remove(target, result);
	cout << "list.Remove(19): " << answer << endl;
	cout << "list: " << list << endl << endl;

	int first[3] = {21, 9, 11};
	for(int i = 0; i < 3; i++) 
	{
		bool temp = list3.Insert(&first[i]);
	}
	int second[3] = {17, 8, 12};
	for(int i = 0; i < 3; i++) 
	{
		bool temp = list4.Insert(&second[i]);
	}

	cout << "TESTING MERGE" << endl;
	cout << "list: " << list << endl;
	cout << "list1: " << list1 << endl;
	cout << "list2: " << list2 << endl;
	cout << "list3: " << list3 << endl;
	cout << "list4: " << list4 << endl;

	list.Merge(list1, list2);
	cout << "list.Merge(list1, list2):" << endl;
	cout << "list: " << list << endl;
	cout << "list1: " << list1 << endl;
	cout << "list2: " << list2 << endl;

	list.Merge(list, list);
	cout << "list.Merge(list, list):" << endl;
	cout << "list: " << list << endl;
	cout << "list1: " << list1 << endl;
	cout << "list2: " << list2 << endl;

	list1.Merge(list, list);
	cout << "list1.Merge(list, list):" << endl;
	cout << "list: " << list << endl;
	cout << "list1: " << list1 << endl;
	cout << "list2: " << list2 << endl;

	list3.Merge(list1, list4);
	cout << "list3.Merge(list1, list4):" << endl;
	cout << "list1: " << list1 << endl;
	cout << "list3: " << list3 << endl;
	cout << "list4: " << list4 << endl << endl;

	cout << "TESTING OPERATORS" << endl;
	cout << "re-setting lists..." << endl;
	for(int i = 0; i < 7; i++) 
	{
		bool temp = list.Insert(&arr[i]);
	}
	for(int i = 0; i < 3; i++) 
	{
		bool temp = list1.Insert(&first[i]);
	}
	for(int i = 0; i < 3; i++) 
	{
		bool temp = list2.Insert(&second[i]);
	}
	
	cout << "list: " << list << endl;
	cout << "list1: " << list1 << endl;
	cout << "list2: " << list2 << endl;
	cout << "list3: " << list3 << endl;
	cout << "list4: " << list4 << endl << endl;

	cout << "list4 = list1 + list2" << endl;
	list4 = list1 + list2;
	cout << "list4: " << list4 << endl << endl;

	cout << "list1 += list2" << endl;
	list1 += list2;
	cout << "list1: " << list1 << endl << endl;

	cout << "Does list1 == list4?  "; 
	if(list1 == list4) 
	{
		cout << "Equal!" << endl;
	} 
	else 
	{
		cout << "Not Equal!" << endl;
	}

	cout << "Does list1 != list2?  "; 
	if(list1 != list3) 
	{
		cout << "Not Equal!" << endl;
	} 
	else 
	{
		cout << "Equal!" << endl;
	}

	cout << endl << "list: " << list << endl;
	cout << "list1: " << list1 << endl;
	cout << "list2: " << list2 << endl;
	cout << "list3: " << list3 << endl;
	cout << "list4: " << list4 << endl << endl;
}

void testBird() 
{
	List342<Bird> tweety1, tweety2, tweety3, tweety4, tweety5;
	Bird Eagle("Eagle", 109);
	Bird Hawk("Hawk", 44);
	Bird Vulture("Vulture", 23);
	Bird Duck("Duck", 21);
	Bird Swallow("Swallow", 4);
	Bird Buzzard("Buzzard", 35);
	Bird Osprey("Osprey", 97);
	Bird Crow("Crow", 61);
	Bird Falcon("Falcon", 101);
	Bird Parrot("Parrot", 2);

	cout << "TESTING INSERT" << endl;
	cout << "tweety1.Insert(Eagle)" << endl;
	tweety1.Insert(&Eagle);
	cout << "tweety1.Insert(Hawk)" << endl;
	tweety1.Insert(&Hawk);
	cout << "tweety1.Insert(Falcon)" << endl;
	tweety1.Insert(&Falcon);
	cout << "tweety1.Insert(Osprey)" << endl;
	tweety1.Insert(&Osprey);
	cout << "tweety2.Insert(Vulture)" << endl;
	tweety2.Insert(&Vulture);
	cout << "tweety2.Insert(Buzzard)" << endl;
	tweety2.Insert(&Buzzard);
	cout << "tweety2.Insert(Crow)" << endl;
	tweety2.Insert(&Crow);
	cout << "tweety3.Insert(Duck)" << endl;
	tweety3.Insert(&Duck);
	cout << "tweety3.Insert(Swallow)" << endl;
	tweety3.Insert(&Swallow);
	cout << "tweety3.Insert(Parrot)" << endl << endl;
	tweety3.Insert(&Parrot);

	cout << "tweety1: " << tweety1 << endl;
	cout << "tweety2: " << tweety2 << endl;
	cout << "tweety3: " << tweety3 << endl;
	cout << "tweety4: " << tweety4 << endl;
	cout << "tweety5: " << tweety5 << endl << endl;

	cout << "TESTING OPERATORS" << endl;
	cout << "Does tweety2 match tweety3?  ";
	if(tweety2 == tweety3) 
	{
		cout << "they match!" << endl;
	} 
	else if(tweety2 != tweety3)
	{
		cout << "they don't match!" << endl;
	}

	cout << "tweety4 = tweety2 + tweety3" << endl;
	tweety4 = tweety2 + tweety3;
	cout << "tweety4: " << tweety4 << endl;
	cout << "tweety2: " << tweety2 << endl;
	cout << "tweety3: " << tweety3 << endl << endl;

	cout << "tweety2 += tweety3" << endl;
	tweety2 += tweety3;
	cout << "tweety2: " << tweety2 << endl;
	cout << "tweety3: " << tweety3 << endl << endl;

	cout << "tweety1: " << tweety1 << endl;
	cout << "tweety2: " << tweety2 << endl;
	cout << "tweety3: " << tweety3 << endl;
	cout << "tweety4: " << tweety4 << endl;
	cout << "tweety5: " << tweety5 << endl << endl;

	cout << "TESTING MERGE" << endl;
	tweety5.Merge(tweety2, tweety4);
	cout << "tweety5.Merge(tweety2, tweety4)" << endl;
	cout << "tweety2: " << tweety2 << endl;
	cout << "tweety4: " << tweety4 << endl;
	cout << "tweety5: " << tweety5 << endl << endl;

	tweety3.Merge(tweety3, tweety5);
	cout << "tweety3.Merge(tweety3, tweety5)" << endl;
	cout << "tweety3: " << tweety3 << endl;
	cout << "tweety5: " << tweety5 << endl << endl;


	cout << "TESTING CLEARLIST" << endl;
	cout << "tweety3.ClearList()" << endl;
	tweety3.ClearList();
	cout << "tweety3: " << tweety3 << endl << endl;

	cout << "TESTING COPY CONSTRUCTOR & EQUALS" << endl;
	cout << "tweety1: " << tweety1 << endl;
	cout << "tweety2: " << tweety2 << endl;
	cout << "tweety3: " << tweety3 << endl;
	cout << "tweety4: " << tweety4 << endl;
	cout << "tweety5: " << tweety5 << endl << endl;
	
	cout << "List342<Bird> tweety6(tweety1)" << endl;
	List342<Bird> tweety6(tweety1);
	cout << "tweety2 = tweety6" << endl << endl;
	tweety2 = tweety6;

	cout << "tweety1: " << tweety1 << endl;
	cout << "tweety2: " << tweety2 << endl;
	cout << "tweety3: " << tweety3 << endl;
	cout << "tweety4: " << tweety4 << endl;
	cout << "tweety5: " << tweety5 << endl;
	cout << "tweety6: " << tweety6 << endl;
}

void testChild() 
{
	Child Bilbo("Bilbo", "Baggins", 111);
	Child Gandalf("Gandalf", "Greyhame", 999);
	Child Frodo("Frodo", "Baggins", 29);
	Child Samwise("Samwise", "Gamgee", 19);
	Child Luke("Luke", "Skywalker", 67);
	Child Vadar("Darth", "Vadar", 91);
	Child Han("Han", "Solo", 84);
	Child Leia("Princess", "Leia", 45);
	Child Kirk("James", "Kirk", 34);
	Child Bones("Leonard", "McCoy", 29);
	Child Uhura("Nyota", "Uhura", 19);
	Child Scotty("Montgomery", "Scott", 27);
	Child result;

	List342<Child> lordOfTheRings;
	List342<Child> starWars;
	List342<Child> starTrek;
	List342<Child> sciFi;
	List342<Child> awesomeness;

	cout << "LordOfTheRings: " << lordOfTheRings << endl;
	cout << "StarWars: " << starWars << endl;
	cout << "StarTrek: " << starTrek << endl;
	cout << "SciFi: " << sciFi << endl;
	cout << "Awesomeness: " << awesomeness << endl << endl;

	cout << "TESTING INSERT" << endl;
	cout << "lordOfTheRings.Insert(Gandalf)" << endl;
	lordOfTheRings.Insert(&Gandalf);
	cout << "lordOftheRings: " << lordOfTheRings << endl;
	cout << "lordOfTheRings.Insert(Frodo)" << endl;
	lordOfTheRings.Insert(&Frodo);
	cout << "lordOftheRings: " << lordOfTheRings << endl;
	cout << "lordOfTheRings.Insert(Samwise)" << endl;
	lordOfTheRings.Insert(&Samwise);
	cout << "lordOftheRings: " << lordOfTheRings << endl;
	cout << "lordOfTheRings.Insert(Bilbo)" << endl;
	lordOfTheRings.Insert(&Bilbo);
	cout << "lordOftheRings: " << lordOfTheRings << endl;

	cout << "starWars.Insert(Luke)" << endl;
	starWars.Insert(&Luke);
	cout << "starWars: " << starWars << endl;
	cout << "starWars.Insert(Leia)" << endl;
	starWars.Insert(&Leia);
	cout << "starWars: " << starWars << endl;
	cout << "starWars.Insert(Vadar)" << endl;
	starWars.Insert(&Vadar);
	cout << "starWars: " << starWars << endl;
	cout << "starWars.Insert(Han)" << endl;
	starWars.Insert(&Han);
	cout << "starWars: " << starWars << endl;


	cout << "starTrek.Insert(Bones)" << endl;
	starTrek.Insert(&Bones);
	cout << "starTrek: " << starTrek << endl;
	cout << "starTrek.Insert(Kirk)" << endl;
	starTrek.Insert(&Kirk);
	cout << "starTrek: " << starTrek << endl;
	cout << "starTrek.Insert(Uhura)" << endl;
	starTrek.Insert(&Uhura);
	cout << "starTrek: " << starTrek << endl;
	cout << "starTrek.Insert(Scotty)" << endl;
	starTrek.Insert(&Scotty);
	cout << "starTrek: " << starTrek << endl << endl;

	cout << "LordOfTheRings: " << lordOfTheRings << endl;
	cout << "StarWars: " << starWars << endl;
	cout << "StarTrek: " << starTrek << endl;
	cout << "SciFi: " << sciFi << endl;
	cout << "Awesomeness: " << awesomeness << endl << endl;

	cout << "TESTING OPERATORS" << endl;
	cout << "sciFi = starTrek + starWars" << endl;
	sciFi = starTrek + starWars;

	cout << "awesomeness += SciFi" << endl;
	awesomeness += sciFi;
	cout << "awesomeness: " << awesomeness << endl;
	cout << "awesomeness += lordOfTheRings" << endl;
	awesomeness += lordOfTheRings;
	cout << "awesomeness: " << awesomeness << endl << endl;

	cout << "does awesomeness == lordOfTheRings + starTrek + starWars? "; 
	if(awesomeness == (lordOfTheRings + starTrek + starWars)) 
	{
		cout << "Yup, that's awesome!" << endl;
	} 
	else 
	{
		cout << "No, that's not awesome!" << endl;
	}

	cout << "does starTrek != starWars? ";
	if(starTrek != starWars)
	{
		cout << "Those aren't the same thing!" << endl;
	} 
	else
	{
		cout << "Those are totally the same...jedi mind-meld." << endl;
	}
	cout << endl;

	cout << "TESTING REMOVE" << endl;
	cout << "Remove Scotty from awesomeness.  " << awesomeness.Remove(Scotty, result) << endl;
	cout << "Remove Frodo from awesomeness.  " << awesomeness.Remove(Frodo, result) << endl;
	cout << "Remove Luke from awesomeness.  " << awesomeness.Remove(Luke, result) << endl;
	cout << "Remove Kirk from awesomeness.  " << awesomeness.Remove(Kirk, result) << endl;
	cout << "Remove Vadar from awesomeness.  " << awesomeness.Remove(Vadar, result) << endl;
	cout << "Remove Bones from awesomeness.  " << awesomeness.Remove(Bones, result) << endl;
	cout << "Remove Samwise from awesomeness.  " << awesomeness.Remove(Samwise, result) << endl << endl;
	cout << "awesomeness: " << awesomeness << endl << endl;
	
	cout << "TESTING CLEAR" << endl;
	cout << "sciFi.ClearList()" << endl;
	sciFi.ClearList();
	cout << "sciFi: " << sciFi << endl << endl;
	cout << "awesomness.ClearList()" << endl;
	awesomeness.ClearList();
	cout << "awesomeness: " << awesomeness << endl << endl;
	
	cout << "TESTING MERGE" << endl;
	cout << "lordOfTheRings.Merge(lordOfTheRings, lordOfTheRings)" << endl;
	lordOfTheRings.Merge(lordOfTheRings, lordOfTheRings);
	cout << "sciFi.Merge(starWars, starTrek)" << endl;
	sciFi.Merge(starWars, starTrek);
	cout << "awesomeness.Merge(lordOfTheRings, sciFi)" << endl;
	awesomeness.Merge(lordOfTheRings, sciFi);

	cout << "LordOfTheRings: " << lordOfTheRings << endl;
	cout << "StarWars: " << starWars << endl;
	cout << "StarTrek: " << starTrek << endl;
	cout << "SciFi: " << sciFi << endl;
	cout << "Awesomeness: " << awesomeness << endl << endl;

}

void testBuildList() 
{
	List342<Bird> tweety;
	List342<Child> kiddies("childFile.txt");
	tweety.BuildList("birdFile.txt");
	cout << "tweety.BuildList(\"birdFile.txt\")" << endl;
	cout << "List342<Child> kiddies(\"childFile.txt\")" << endl << endl;
	cout << "tweety: " << tweety << endl << endl;
	cout << "kiddies: " << kiddies << endl << endl;

}

void profTest() 
{
	Child c1("ann", "hanlin", 7), c2("pradnya", "dhala", 8);
	Child c3("bill", "vollmann", 13), c4("cesar", "ruiz", 6);
	Child c5("piqi", "tang", 7), c6("pete", "rose", 13), c7("hank", "aaron", 3);
	Child c8("madison", "fife", 7), c9("miles", "davis", 65);
	Child c10("john", "zorn", 4), c11;
	List342<Child> class1, class2, soccer, chess;
	int a = 1, b = -1, c = 13;
	class1.Insert(&c1);
	class1.Insert(&c2);
	class1.Insert(&c3);
	class2.Insert(&c4);
	class2.Insert(&c5);
	class2.Insert(&c6);
	class2.Insert(&c7);
	soccer.Insert(&c6);
	soccer.Insert(&c4);
	soccer.Insert(&c9);
	chess.Insert(&c10);
	chess.Insert(&c7);
	cout << "This is class1: " << class1 << endl;
	cout << "This is class2: " << class2 << endl;
	if (class1 != class2)
	{
		cout << "class1 is different than class 2" << endl;
	}
	if (class1.Peek(c2, c11))
	{
		cout << c11 << " is in class1" << endl;
	}
	if (class1.Remove(c1, c11))
	{
		class2.Insert(&c11);
		cout << c1 << " has been removed from class1 and placed in class2" << endl;
	}
	cout << "This is class2: " << class2 << endl;
	cout << "This is the chess club: " << chess << endl;
	chess.ClearList();
	chess.Insert(&c9);
	cout << "this is now the chess club: " << chess << endl;
	List342<Child> soccer2 = soccer;
	// Note that the Merge function is probably not as intuitive as we like
	// but the fact the lists allow duplicates confuse the situation.
	chess.Merge(soccer, class2);
	cout << "this is now the chess club: " << chess << endl;
	if (soccer.isEmpty())
	{
		cout << "The soccer club is now empty" << endl;
	}
		cout << "This is the soccer2 club: " << soccer2 << endl;
	List342<int> numbers;
	numbers.Insert(&a);
	numbers.Insert(&b);
	numbers.Insert(&c);
	cout << "These are the numbers: " << numbers << endl;
}

