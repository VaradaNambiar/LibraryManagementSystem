// LibraryManagementSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Inventory.h"
#include "Actors.h"
#include "Book.h"
#include "PaymentManager.h"

using namespace std;

PaymentManager* PaymentManager::instance = nullptr;
mutex PaymentManager::mtx;

int main()
{
    SystemInventory* library = SystemInventory::GetInstance();

    Book DaVinciCode = Book("DaVinciCode");
    Book MockingJay = Book("How to kill a mokingjay");
    Book WingsOfFire = Book("Wings of fire");

	Seller rahul;
    rahul.AddBook(DaVinciCode);
    rahul.AddBook(MockingJay);
    rahul.AddBook(WingsOfFire);
    library->ShowBooks();
    cout << endl;

	Buyer varada;
    varada.AddBook(DaVinciCode);
    cout << "Varada Inventory" << endl;
    varada.DisplayItemsInInventory();
    cout << endl;

    cout << "Download book" << endl;
    varada.DownloadBook(DaVinciCode);
    cout << endl;

	cout << "Remove book" << endl;
    varada.RemoveBook(DaVinciCode);
    varada.DisplayItemsInInventory();
    cout << endl;

	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    cout << "    Buying/downloading a book" << endl;
    cout << endl;
    PaymentManager* paymentManager = PaymentManager::GetInstance();
    paymentManager->BuyBook(varada, DaVinciCode);
    varada.DisplayItemsInInventory();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
