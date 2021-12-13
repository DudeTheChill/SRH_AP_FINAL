// AP_FINAL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <list>
#include "TravelInfo.h"
#include "TravelItem.h"

int mainMenu() {
	int c;
	system("cls");
	cout << "Please Select Your Desired Action: \n";
	cout << "1. Create New Travel List \n";
	cout << "2. Display Travel List \n";
	cout << "3. Display A single Travel info \n";
	cout << "4. Delete Item \n";
	cout << "5. Delete Travel List \n";
	cout << "6. Update Travel List \n";
	cout << "7. Export Travel List \n";
	cout << "0. Exit \n";
	cin >> c;
	return c;
}

void showById(list<TravelInfo> ti, list<TravelItem> items_list) {
	int temp;
	TravelInfo output;
	cout << "\n Please enter the travel id that you are looking for";
	cin >> temp;
	for (list<TravelInfo>::iterator it = ti.begin(); it != ti.end(); ++it) {
		if (temp == it->getId()) {
			output = (*it);
			temp = -1;
			break;
		}
	}
	if (temp == -1)
	{
		output.printOut(items_list);
	}
	else
	{
		cout << "No Travel info with the given id found";
	}
}


void main()
{
	
	int userChoice = 1;
	int i = 0;
	int tempID, temp;
	list<TravelInfo> til;
	list<TravelItem> item_list;
	TravelInfo ti;
	TravelItem item;
	FILE *fp;
	//this part is for reading trip.txt file
	int ssize = sizeof(TravelInfo);
	fp = fopen("trip.txt", "rb+");
	if (fp == NULL)	{fp = fopen("trip.txt", "wb+");}
	while (fread(&ti, ssize, 1, fp) == 1){til.push_back(ti);}
	fclose(fp);
	//this part is for reading trip.txt file

	//this part is for reading item.txt file
    ssize = sizeof(TravelItem);
	fp = fopen("item.txt", "rb+");
	if (fp == NULL)	{fp = fopen("item.txt", "wb+");	}
	while (fread(&item, ssize, 1, fp) == 1)	{item_list.push_back(item);	}
	fclose(fp);
	//this part is for reading trip.txt file


	while (userChoice != 0)
	{

		userChoice = mainMenu();
		switch (userChoice)
		{
		case 1:
			if (til.empty())
			{
				ti.createTravelInfo(0,0);
			}
			else
			{
				ti.createTravelInfo(til.back().getId(), &item_list);
			}
			//get travel items:
			cout << "\n Now, Please enter the list of items that you want to take with yourself:";
			while (i != 1)
			{
				if (item_list.empty())
				{
					item.createItem(0, ti.getId());
				}
				else
				{
					item.createItem(item_list.back().getItemID(), ti.getId());
				}
				item_list.push_back(item);
				cout << "\n Do you want to add more Items? Enter 1 if you want to quit:";
				cin >> i;
			}
			
			til.push_back(ti);
			i = 0;
			system("PAUSE");
			break;
	
		case 2: 
			cout << "Travel ID" << "\t" << "Destination" << "\t" << "Starting Date" << "\t" << "end Date" << "\n";
			for (list<TravelInfo>::iterator it = til.begin(); it != til.end(); ++it) {
				cout << it->getId() << "\t" << it->getDestination() << "\t" << it->getStartDate() << "\t" << it->getEndDate() << "\n";
			}
			system("PAUSE");
			break;

		case 3:
			showById(til, item_list);
			system("PAUSE");
			break;

		case 4:
			cout << "Please Enter The Item ID that you want to delete:";
			cin >> tempID;
			item_list = ti.removeItem(item_list, tempID, true);
			system("PAUSE");
			break;

		case 5:
			cout << "\n Please enter the travel id that you want to delete:";
			cin >> temp;
			for (list<TravelInfo>::iterator it = til.begin(); it != til.end(); ++it) {
				if (temp == it->getId()) {
					item_list = (*it).removeItem(item_list, temp, false);
					it = til.erase(it);
					break;
				}
			}
			break;

		case 7:
			cout << "\n Please enter the travel id that you want to export:";
			cin >> temp;
			for (list<TravelInfo>::iterator it = til.begin(); it != til.end(); ++it) {
				if (temp == it->getId()) {
					(*it).exportList(item_list);
					break;
				}
			}
			break;

		case 0: 
			break;

		default:
			printf_s("Please Enter A Number Between 0 to 9 \n");
			system("PAUSE");
			break;
		}
	}

	ssize = sizeof(TravelItem);
	fp = fopen("item.txt", "w");
	for (list<TravelItem>::iterator it = item_list.begin(); it != item_list.end(); ++it) {
		fwrite(&(*it), ssize, 1, fp);
	}
	fclose(fp);
	ssize = sizeof(TravelInfo);
	fp = fopen("trip.txt", "w");
	for (list<TravelInfo>::iterator it = til.begin(); it != til.end(); ++it) {
		fwrite(&(*it), ssize, 1, fp);
	}
	fclose(fp);

	
}
