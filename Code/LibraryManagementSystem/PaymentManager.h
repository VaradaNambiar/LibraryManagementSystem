#pragma once
#include "Actors.h"
#include "Book.h"

using namespace std;

class PaymentManager
{
private: // singleton
	PaymentManager() {};
	static PaymentManager* instance;
	bool RecordPayment(Buyer person, Book bk);
	static mutex mtx;

public:
	static PaymentManager* GetInstance();
	bool BuyBook(Buyer person, Book bk);
};
