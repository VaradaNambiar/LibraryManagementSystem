#pragma once
#include <string>


using namespace std;

class Book
{
private:
	string name;

public:
	Book(string title) : name(title) {};
	string GetTitle() { return name; }
	bool operator==(const Book& book2);
};

inline bool Book::operator==(const Book& book2)
{
	if (this->name == book2.name)
		return true;
	else
		return false;
}
