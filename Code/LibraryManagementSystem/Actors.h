#pragma once
#include <list>
#include "Inventory.h"

class Actor
{
protected:
	string name;
};

class Maintainers : public Actor
{
private:
	UserInventory myInventory;
public:
	UserInventory GetInventory();
	void AddBook(Book book);
	void RemoveBook(Book book);
	void DisplayItemsInInventory();
};


inline UserInventory Maintainers::GetInventory()
{
	return myInventory;
}


inline void Maintainers::AddBook(Book book)
{
	myInventory.AddToCollection(book);
}

inline void Maintainers::RemoveBook(Book book)
{
	myInventory.RemoveFromCollection(book);
}

inline void Maintainers::DisplayItemsInInventory()
{
	GetInventory().ShowBooks();
}

class Buyer : public Maintainers
{
public:
	void DownloadBook(Book book);
};


class Seller : public Maintainers
{
private:
	UserInventory myInventory;
	void AddBookToLibrary(const Book book);
	void RemoveBookFromLibrary(const Book book);

public:
	UserInventory GetInventory();
	void AddBook(const Book book); // add book to main library as well 
	void RemoveBook(const Book book);
	bool operator==(const Seller& person);
};

class SellerManager
{
private:
	list<Seller> sellerList;
	SellerManager();
	static SellerManager* instance;
	static mutex mx;
public:
	static SellerManager* GetInstance();
	void AddSeller(Seller person);
	void RemoveSeller(Seller person);
};

class Admin : public Actor
{
private:
	SellerManager* mgrInstance = SellerManager::GetInstance();
public:
	void AddSeller(Seller seller);
	void RemoveSeller(Seller seller);
};


inline void Seller::AddBook(Book book)
{
	if (!myInventory.IsBookExist(book))
	{
		myInventory.AddToCollection(book);
		AddBookToLibrary(book);
	}
	else
		cout << "This book already exists in your inventory" << endl;

}

inline void Seller::RemoveBook(Book book)
{
	if (!myInventory.IsBookExist(book))
		cout << "This book does not exist in the inventory to remove" << endl;
	else
	{
		myInventory.RemoveFromCollection(book);
		RemoveBookFromLibrary(book);
	}
}

inline bool Seller::operator==(const Seller& other)
{
	return (name == other.name);
}

inline void Seller::AddBookToLibrary(Book book)
{
	if (!myInventory.IsBookExist(book))
		cout << "Cannot add a book to server that is absent in your inventory!" << endl;
	else
	{
		 SystemInventory* library= SystemInventory::GetInstance();
		 library->AddToCollection(book);
	}
}

inline void Seller::RemoveBookFromLibrary(const Book book)
{
	if (!myInventory.IsBookExist(book))
		cout << "This book does not exist in your inventory to remove" << endl;
	else
	{
		 SystemInventory* library= SystemInventory::GetInstance();
		library->RemoveFromCollection(book);
	}
}

inline SellerManager* SellerManager::GetInstance()
{
	if (instance == NULL)
	{
		mx.lock();
		if (instance == NULL)
		{
			instance = new SellerManager();
		}
	}
	return instance;
}

inline void SellerManager::AddSeller(Seller person)
{
	sellerList.push_back(person);
}

inline void SellerManager::RemoveSeller(Seller person)
{
	sellerList.remove_if([person](Seller seller) {return seller == person; });
}

inline void Admin::AddSeller(Seller seller)
{
	mgrInstance->AddSeller(seller);
}

inline void Admin::RemoveSeller(Seller seller)
{
	mgrInstance->RemoveSeller(seller);
}

inline void Buyer::DownloadBook(Book bk)
{
	cout << "Downloading......." << endl;
	cout << "Download complete!" << endl;
}

