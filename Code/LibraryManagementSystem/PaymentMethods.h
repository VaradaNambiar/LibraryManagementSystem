#pragma once

using namespace std;

// Abstract factory
class Upi 
{
public:
	virtual bool MakeUpiPayment(float amt) = 0;
};

class RazorPayUpi: public Upi
{
public:
	bool MakeUpiPayment(float amt) override;
};
class PhonePeUpi : public Upi
{
public:
	bool MakeUpiPayment(float amt) override;
};

class CreditCards
{
public:
	virtual bool MakeCardPayment(float amt) = 0;
};
class RazorPayCreditCards: public CreditCards
{
public:
	bool MakeCardPayment(float amt) override;
};
class PhonePeCreditCards : public CreditCards
{
public:
	bool MakeCardPayment(float amt) override;
};