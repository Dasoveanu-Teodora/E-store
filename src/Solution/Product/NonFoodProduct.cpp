#include "NonFoodProduct.h"

NonFoodProduct::NonFoodProduct():Product()
{
	yearsOfWarranty=0;
	price=0;
	//throw("undefined");
}

NonFoodProduct::NonFoodProduct(const string &category, int id, const string &producer, const string &name, float price, int yearsOfWarranty, int quantity) : Product(category, id, name, quantity)
{ 
	this->producer=producer;
	this->yearsOfWarranty=yearsOfWarranty;
	this->price=price;
	//throw("undefined");
}

NonFoodProduct::NonFoodProduct(const NonFoodProduct &pn) : Product(pn)
{
	producer=pn.producer;
	yearsOfWarranty=pn.yearsOfWarranty;
	price=pn.price;
	//throw("undefined");
}

void NonFoodProduct::setYearsOfWarranty(int garantieAni)
{
	yearsOfWarranty=garantieAni;
	//throw("undefined");
}

void NonFoodProduct::setPrice(float price)
{
	this->price=price;
	//throw("undefined");
}

void NonFoodProduct::setProducer(const string &producer)
{
	this->producer=producer;
	//throw("undefined");
}

int NonFoodProduct::getYearsOfWarranty()
{
	return yearsOfWarranty;
	//throw("undefined");
}

float NonFoodProduct::getPrice()
{
	return price;
	//throw("undefined");
}

string &NonFoodProduct::getProducer()
{
	return producer;
	//throw("undefined");
}

bool NonFoodProduct::operator==(const NonFoodProduct &obj) const
{
	 
	if( (name==obj.name) && (quantity==obj.quantity) && (category==obj.category) && (id==obj.id) && (producer==obj.producer) && (yearsOfWarranty==obj.yearsOfWarranty) && (price==obj.price) )
			return true;
		else
			return false;

	//throw("undefined");
}

const NonFoodProduct &NonFoodProduct::operator=(const NonFoodProduct &a)
{   Product::operator=(a);
    producer=a.producer;
	yearsOfWarranty=a.yearsOfWarranty;
	price=a.price;
	//throw("undefined");
	return *this;
}

string NonFoodProduct::getProductType()
{
	string s="nealimentar";
	return s;
	//throw("undefined");
}

json NonFoodProduct::toJSON()
{
	return json(*this);
}

void NonFoodProduct::display()
{
	cout << "Product Nealimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl
		 << endl;
}
