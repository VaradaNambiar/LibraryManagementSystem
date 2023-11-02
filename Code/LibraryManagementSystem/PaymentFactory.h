#pragma once
#include <string>

#include "PaymentMethods.h"

class PaymentGateway;
using namespace std;

enum PaymentGatewayChoice
{
	None,
	RazorPay,
	PhonePe,
};

namespace PaymentGatewayEnvironment
{
	class PaymentGateway
	{
	public:
		static PaymentGatewayChoice StringToPaymentGatewayEnum(string option);
		virtual Upi* createUpi() = 0;
		virtual CreditCards* createCreditCard() = 0;
	};
	
	class RazorPay : public PaymentGateway
	{
	public:
		Upi* createUpi() override;
		CreditCards* createCreditCard() override;
	};

	class PhonePe : public PaymentGateway
	{
	public:
		Upi* createUpi() override;
		CreditCards* createCreditCard() override;
	};

	class PaymentGatewayFactory
	{
	public:
		static PaymentGateway* createPaymentGateway(string option)
		{

			const auto gateway = PaymentGateway::StringToPaymentGatewayEnum(option);
			switch (gateway)
			{
			case PaymentGatewayChoice::RazorPay:
				return new RazorPay();
			default:
				return new PhonePe();
			}
		};
	};
}
