#include "PaymentManager.h"
#include <iostream>
#include "PaymentFactory.h"

using namespace PaymentGatewayEnvironment;
using namespace std;

bool PaymentManager::RecordPayment(Buyer person, Book bk)
{

	bool done = false;
	// record details -> buyer name, book name, payment gateway, payment method, amt
	// to database 
	done = true;
	return done;
}

PaymentManager* PaymentManager::GetInstance()
{
	//double check lock
	if(instance==nullptr)
	{
		mtx.lock();
		{
			if(instance == nullptr)
			{
				instance = new PaymentManager();
			}
		}
		mtx.unlock();
	}
	return instance;
}

bool PaymentManager::BuyBook(Buyer person, Book bk)
{
	cout << " choose gateway: Razerpay or PhonePe " << endl;
	string option;
	cin >> option;
	const auto paymentGateway = PaymentGatewayFactory::createPaymentGateway(option);
	cout << "Credit card payment" << endl;
	CreditCards* creditCard = paymentGateway->createCreditCard();
	bool is_payment_sucessful = creditCard->MakeCardPayment(bk.GetCost());
	if(is_payment_sucessful)
	{
		if(!person.GetInventory().IsBookExist(bk))
			person.AddBook(bk);
		person.DownloadBook(bk);
	}
	RecordPayment(person, bk);
	return is_payment_sucessful;
}

