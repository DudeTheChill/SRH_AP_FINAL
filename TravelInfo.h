#pragma once
#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include "TravelItem.h"

using namespace std;

class TravelInfo
{
private:
	int id;
	string startDate;
	string endDate;
	string Destination;
public:
	TravelInfo() {}
	//setters 
	void setId(int id) { this->id = id; }
	void setEndDate(string endDate) { this->endDate = endDate; }
	void setStartDate(string startDate) { this->startDate = startDate; }
	void setDestination(string destination) { this->Destination = destination; }
	//getters
	int getId() { return this->id; }
	string getEndDate() { return this->endDate; }
	string getStartDate() { return this->startDate; }
	string getDestination() { return this->Destination; }



	//general methods:
	void createTravelInfo(int pId, list<TravelItem> *items_list) {
		
		int i = 0;
		TravelItem item;
		this->id = ++pId;
		cout << "\n Where do you want to go?";
		cin >> this->Destination;
		cout << "\n When are you planning to leave?";
		cin >> this->startDate;
		cout << "\n When are you planning to come back?";
		cin >> this->endDate;

	}


	void printOut(list<TravelItem> items_list) {

		cout << "\n ID:" << this->id;
		cout << "\n Start Date:" << this->startDate;
		cout << "\n End Date:" << this->endDate;
		cout << "\n Destination:" << this->Destination;
		
		list<TravelItem> ti = listTravelItems(items_list);
		for (list<TravelItem>::iterator it = ti.begin(); it != ti.end(); ++it) {
			cout << "\n from " << it->getItemName() << " bring " << it->getItemCount() << " (item ID: " << it->getItemID() << ")";
		}
	}


	list<TravelItem> listTravelItems(list<TravelItem> ti) {
		list<TravelItem> output;
		for (list<TravelItem>::iterator it = ti.begin(); it != ti.end(); ++it) {
			if(this->id == it->getTravelID()){
				output.push_back((*it));
			}
		}
		return output;
	}



	//remove items list of a certain travel
	//if tyoe is true, it will remove and item with id == id
	//if type is false, it will delete all items that belong to travel list with id == id
	list<TravelItem> removeItem(list<TravelItem> ti, int id, bool type) {
		
		if (type)
		{
			for (list<TravelItem>::iterator it = ti.begin(); it != ti.end(); ++it) {
				if (id == it->getItemID()) {
				    it = ti.erase(it);
					if (ti.end() == it)
					{
						break;
					}
				}
			}
			return ti;
		}
		else
		{
			for (list<TravelItem>::iterator it = ti.begin(); it != ti.end(); ++it) {
				if (this->getId() == it->getTravelID()) {
					it = ti.erase(it);
					if (ti.end() == it)
					{
						break;
					}
				}
			}
			return ti;
		}
	}

	void exportList(list<TravelItem> item_list) {
		list<TravelItem> items = listTravelItems(item_list);
		ofstream myfile(this->Destination + ".txt");
		myfile << "##### Travel Preparation List to: " << this->Destination << " #####" << endl;
		myfile << "Start Date: " << this->startDate << endl;
		myfile << "End Date: " << this->endDate << endl;
		myfile << "##### List Of Items That You Need To Pack #####" << endl;
		for (list<TravelItem>::iterator it = items.begin(); it != items.end(); ++it) {
			myfile << "Bring "<< (*it).getItemCount() << " of " << (*it).getItemName() << endl;
		}

	}

	

};

