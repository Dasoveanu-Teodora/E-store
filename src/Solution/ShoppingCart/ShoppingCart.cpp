#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	this->payMethod = "-";
}

ShoppingCart::ShoppingCart(const string &payMethod)
{
	this->payMethod=payMethod;
	//throw("undefined");
}

string &ShoppingCart::getPayMethod()
{  
	return payMethod;
	//throw("undefined");
}

void ShoppingCart::setPayMethod(const string &payMethod)
{
	this->payMethod=payMethod;
	//throw("undefined");
}

void ShoppingCart::addProduct(int id, int quantity)
{
	shoppingCart.insert({id,quantity}) ;
	//throw("undefined");
}

void ShoppingCart::raiseQuantity(int id, int quantity)
{
	shoppingCart.find(id)->second+=quantity;
	//throw("undefined");
}

void ShoppingCart::lowerQuantity(int id, int quantity)
{   
		shoppingCart.find(id)->second=shoppingCart.find(id)->second - quantity;
	//throw("undefined");
}

int ShoppingCart::getQuantity(int productID)
{   
	if( shoppingCart.find(productID) !=  shoppingCart.end() )      //->second !=0)
	    return shoppingCart.find(productID)->second;
	else 
		return -1;
	//throw("undefined");
}

void ShoppingCart::deleteProduct(int productID)
{
	shoppingCart.erase(productID);
	
	//throw("undefined");
}

map<int, int> &ShoppingCart::getShoppingCart()
{
	return shoppingCart;
	//throw("undefined");
}

void ShoppingCart::displayShoppingCart()
{	
	map<int,int>::iterator it;
	cout <<"Cosul de cumparaturi"<<endl<<endl;
	for (it=shoppingCart.begin(); it!=shoppingCart.end(); ++it)
    	cout << "Id produs: "<< it->first << "  =>  " << "Cantitate: " <<it->second << '\n';
	//throw("undefined");
}

json ShoppingCart::toJSON()
{
  return json(*this);
}