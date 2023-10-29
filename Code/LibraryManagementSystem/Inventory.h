#pragma once
#include <mutex>
#include <list>

#include "Book.h"

class Inventory
{
private:
	std::list<Book> books;
public:
	void ShowBooks();
	void AddToCollection(const Book book) ;
	void RemoveFromCollection(const Book book);
	const Book GetBook(string title);
	bool IsBookExist(Book bk) const;
};

class SystemInventory: public Inventory
{
private:
	static SystemInventory* instance;
	static std::mutex mx;
	SystemInventory() {};

public:
	static SystemInventory* GetInstance();
};

class UserInventory: public Inventory
{
//public:
	//virtual void AddToInventory(Book bk) = 0;
	//virtual void RemoveFromInventory(Book book) = 0;
};

//class BuyerInventory: public UserInventory
//{
//public:
//	void AddToInventory(Book book) override;
//	void RemoveFromInventory(Book book) override;
//	void DownloadBook(Book book);
//};
//
//class SellerInventory: public UserInventory
//{
//public:
//	void AddToInventory(Book book) override;
//	void RemoveFromInventory(Book book) override;
//	void AddToMainLibrary(Book book);
//	void RemoveFromMainLibrary(Book book);
//
//};
//
