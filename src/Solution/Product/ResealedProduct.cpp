#include "ResealedProduct.h"

using namespace std;

ResealedProduct::ResealedProduct(): NonFoodProduct(),DiscountedProduct(),ReturnedProduct(){
	wearPercentage=0;
	//throw("undefined");
}

ResealedProduct::ResealedProduct(const string &category, int id, const string &producer, const string &name, float price, int yearsOfWarranty, int discountPercentage, const string &reason, int wearPercentage, int quantity)
	: NonFoodProduct(category, id, producer, name, price, yearsOfWarranty, quantity),
		DiscountedProduct(category, id, producer, name, price, yearsOfWarranty, discountPercentage, quantity),
		ReturnedProduct(category, id, producer, name, price, yearsOfWarranty, reason, quantity)
{
	this->wearPercentage=wearPercentage;
	//throw("undefined");
}

ResealedProduct::ResealedProduct(const ResealedProduct &pr) :NonFoodProduct(pr), DiscountedProduct(pr), ReturnedProduct(pr)
{
	wearPercentage=pr.wearPercentage;
	//throw("undefined");
}

void ResealedProduct::setWearPercentage(int wearPercentage)
{
	this->wearPercentage=wearPercentage;
	//throw("undefined");
}

float ResealedProduct::getWearPercentage()
{
	return wearPercentage;
	//throw("undefined");
}

const ResealedProduct &ResealedProduct::operator=(const ResealedProduct &a)
{   
	if(this!=&a){
	DiscountedProduct::operator=(a);
	ReturnedProduct::operator=(a);
	NonFoodProduct::operator=(a);
	wearPercentage=a.wearPercentage;
	}
	//throw("undefined");
	return *this;
}

string ResealedProduct::getProductType()
{
	
	return "resigilat";
	//throw("undefined");
}

json ResealedProduct::toJSON()
{
	return json(*this);
}

void ResealedProduct::display()
{
	cout << "Product Resigilat" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl;
	cout << "Procent Reducere: " << this->discountPercentage << endl;
	cout << "Procent Uzura: " << this->wearPercentage << endl;
	cout << "Motiv retur: " << this->reason << endl
         << endl;
}
