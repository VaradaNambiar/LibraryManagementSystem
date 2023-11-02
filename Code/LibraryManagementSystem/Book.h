#pragma once
#include <string>


using namespace std;

class Book
{
private:
	string name;
	double cost;

public:
	Book(string title) : name(title) {};
	string GetTitle() { return name; }
	bool operator==(const Book& book2);
	float GetCost() const;
};

inline bool Book::operator==(const Book& book2)
{
	if (this->name == book2.name)
		return true;
	else
		return false;
}

inline float Book::GetCost() const
{
	return cost;
}
