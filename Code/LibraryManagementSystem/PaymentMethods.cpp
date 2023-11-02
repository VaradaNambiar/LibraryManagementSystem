#pragma once

#include "PaymentMethods.h"

#include <iostream>

using namespace std;

bool RazorPayUpi::MakeUpiPayment(float amt)
{
	bool is_success = false;
	cout << "Gateway : RazorPay" << endl;
	cout << " Mode: UPI" << endl;

	// <insert unique implementation code> 
	cout << "Payment in progress" << endl;
	// if successful 
	cout << "Payment success!" << endl;
	is_success = true;

	return is_success;
}

bool PhonePeUpi::MakeUpiPayment(float amt)
{
	bool is_success = false;
	cout << "Gateway : PhonePe" << endl;
	cout << " Mode: UPI" << endl;

	// <insert unique implementation code> 
	cout << "Payment in progress" << endl;
	// if successful 
	cout << "Payment success!" << endl;
	is_success = true;

	return is_success;
}

bool RazorPayCreditCards::MakeCardPayment(float amt)
{
	bool is_success = false;
	cout << "Gateway : RazorPay" << endl;
	cout << " Mode: Credit Card" << endl;

	// <insert unique implementation code> 
	cout << "Payment in progress" << endl;
	// if successful 
	cout << "Payment success!" << endl;
	is_success = true;

	return is_success;
}

bool PhonePeCreditCards::MakeCardPayment(float amt)
{
	bool is_success = false;
	cout << "Gateway : PhonePe" << endl;
	cout << " Mode: Credit Card" << endl;

	// <insert unique implementation code> 
	cout << "Payment in progress" << endl;
	// if successful 
	cout << "Payment success!" << endl;
	is_success = true;

	return is_success;
}
