#include "FoodProduct.h"
#include <typeinfo>

FoodProduct::FoodProduct():Product(),leiPerKg(0)
{	
	//throw("undefined");
}

FoodProduct::FoodProduct(const string &categorie, int id, const string &nume, float leiPerKg, const string &taraOrigine, int cantitate) : Product(categorie, id, nume, cantitate)
{
	this->leiPerKg=leiPerKg;
	this->countryOfOrigin=taraOrigine;
	//throw("undefined");
}

FoodProduct::FoodProduct(const FoodProduct &pa) : Product(pa)
{	this->leiPerKg=pa.leiPerKg;
	this->countryOfOrigin=pa.countryOfOrigin;
	//throw("undefined");
}

void FoodProduct::setLeiPerKg(float leiPerKg)
{
	this->leiPerKg=leiPerKg;
	//throw("undefined");
}

void FoodProduct::setCountryOfOrigin(const string &countryOfOrigin)
{
	this->countryOfOrigin=countryOfOrigin;
	//throw("undefined");
}

float FoodProduct::getLeiPerKg()
{    
	return leiPerKg;
	//throw("undefined");
}

string &FoodProduct::getCountryOfOrigin()
{
	return countryOfOrigin;
	//throw("undefined");
}

const FoodProduct &FoodProduct::operator=(const FoodProduct &a)
{
	Product::operator=(a);
	this->leiPerKg=a.leiPerKg;
	this->countryOfOrigin=a.countryOfOrigin;
	//throw("undefined");
	return *this;
}

string FoodProduct::getProductType()
{   
	
	//throw("undefined");
	//aici in functie de copilator pot aparea probleme
	return "alimentar";
}

json FoodProduct::toJSON()
{
	return json(*this);
}

void FoodProduct::display()
{
	cout << "Product alimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Categorie : " << this->category << endl;
	cout << "ID : " << this->id << endl;
	cout << "Cantitate (stoc): " << this->quantity << endl;
	cout << "Lei per KG : " << this->leiPerKg << endl;
	cout << "Tara de Origine : " << this->countryOfOrigin << endl
		 << endl;
}