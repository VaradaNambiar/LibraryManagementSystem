#include "Inventory.h"

#include <iostream>

using namespace std;

bool Inventory::IsBookExist(Book bk) const
{
	for (Book book : books)
	{
		if (bk.GetTitle() == book.GetTitle())
			return true;
	}
	return false;
}

void Inventory::ShowBooks()
{
	cout << "---------------This inventory contains the following books--------------" << endl;
	for (Book book : books)
	{
		cout << book.GetTitle() << endl;
	}
	cout << "------------------------------------------------------------------------------" << endl;
}

void Inventory::AddToCollection(const Book book)
{
	if (IsBookExist(book))
		cout << "book already exists in inventory. Abort addition of book to your inventory." << endl;
	else
		books.push_back(book);
}

void Inventory::RemoveFromCollection(const Book book)
{
	if (!IsBookExist(book))
		cout << "This book does not exist in the inventory" << endl;
	else
	{
		books.remove_if([book](Book bk) {return bk == book; });
	}
}

const Book Inventory::GetBook(string title)
{
	for (Book bk : books)
	{
		if (bk.GetTitle() == title)
			return bk;
	}
std::exception("Book does not exist in inventory");
}
SystemInventory* SystemInventory::instance = nullptr;

mutex SystemInventory::mx;

SystemInventory* SystemInventory::GetInstance()
{
	// early initialisation because we definitely need main library
	// hence can avoid double check lock

	mx.lock();
	if (instance == NULL)
	{
		instance = new SystemInventory();
	}
	mx.unlock();
	return instance;
}



//void BuyerInventory::AddToInventory(Book book)
//{
//	AddToCollection(book);
//}
//
//void BuyerInventory::RemoveFromInventory(Book book)
//{
//	RemoveFromCollection(book);
//}
//
