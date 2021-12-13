#pragma once
#include <string>
#include <iostream>
using namespace std;
class TravelItem
{
private:
	int itemId;
	int travelId;
	int itemCount;
	string itemName;
public:
	TravelItem() {}

	//setters
	void setItemID(int itemId){
		this->itemId = itemId;
	}
	void setTravelID(int travelId) {
		this->travelId = travelId;
	}
	void setItemCount(int itemCount) {
		this->itemCount = itemCount;
	}
	void setItemName(string itemName) {
		this->itemName = itemName;
	}

	//getters
	int getItemID() {
		return this->itemId;
	}
	int getTravelID() {
		return this->travelId;
	}
	int getItemCount() {
		return this->itemCount;
	}
	string getItemName() {
		return this->itemName;
	}

	//General methods:
	void createItem(int item_id, int travel_id) {

		this->itemId = ++item_id;
		this->travelId = travel_id;
		cout << "\n What is the item that you want to add to list?";
		cin >> this->itemName;
		cout << "\n How many of this item do you want to take?";
		cin >> this->itemCount;
		cout << "\n item successfuly added to list";

	}


};

