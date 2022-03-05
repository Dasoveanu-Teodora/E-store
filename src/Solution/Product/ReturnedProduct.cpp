#include "ReturnedProduct.h"

ReturnedProduct::ReturnedProduct():NonFoodProduct()
{
	//throw("undefined");
}

ReturnedProduct::ReturnedProduct(const string &categorie, int id, const string &producator, const string &nume, float pret, int garantieAni, const string &motiv, int cantitate)
	: NonFoodProduct(categorie, id, producator, nume, pret, garantieAni, cantitate),reason(motiv)
{
	
	//throw("undefined");
}

ReturnedProduct::ReturnedProduct(const ReturnedProduct &prodRet) : NonFoodProduct(prodRet)
{
	reason=prodRet.reason;
	//throw("undefined");
}


const ReturnedProduct &ReturnedProduct::operator=(const ReturnedProduct &a)
{
	NonFoodProduct::operator=(a);
	reason=a.reason;
	//throw("undefined");
	return *this;
}

string &ReturnedProduct::getReason()
{
    return reason;
	//throw("undefined");
}

void ReturnedProduct::setReason(string &reason)
{
	this->reason=reason;
	//throw("undefined");
}

string ReturnedProduct::getProductType()
{
	
	return "returnat";
	//throw("undefined");
}

json ReturnedProduct::toJSON()
{
	return json(*this);
}

void ReturnedProduct::display()
{
	cout << "Product Returnat" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl;
	cout << "Motiv : " << this->reason << endl
		 << endl;
}
