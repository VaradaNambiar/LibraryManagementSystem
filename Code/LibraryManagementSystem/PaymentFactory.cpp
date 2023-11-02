#pragma once

#include "PaymentFactory.h"

using namespace std;
using namespace PaymentGatewayEnvironment;


PaymentGatewayChoice PaymentGatewayEnvironment::PaymentGateway::StringToPaymentGatewayEnum(string option)
{
	if (option == "RazorPay")
		return PaymentGatewayChoice::RazorPay;
	else if (option == "PhonePe")
		return PaymentGatewayChoice::PhonePe;
	else
		return PaymentGatewayChoice::None;
}

Upi* RazorPay::createUpi()
{
	return new RazorPayUpi();
}

CreditCards* RazorPay::createCreditCard()
{
	return new RazorPayCreditCards();
}

Upi* PaymentGatewayEnvironment::PhonePe::createUpi()
{
	return new PhonePeUpi();
}

CreditCards* PaymentGatewayEnvironment::PhonePe::createCreditCard()
{
	return new PhonePeCreditCards();
}
