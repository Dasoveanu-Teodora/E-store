#include "Server.h"

using namespace std;

/* NU MODIFICATI */
Server::Server() {}

/* NU MODIFICATI */
Server *Server::GetInstance()
{
	if (!instance)
	{
		instance = new Server;
	}

	return instance;
}

/* NU MODIFICATI */
Server::~Server()
{
	if (instance != NULL)
		instance = NULL;

	if (!__UserID__ProductsCart__.empty())
		__UserID__ProductsCart__.clear();
}

void Server::set__UserID__ProductsCart__()
{
	list<User *>::iterator it;

	for (it = usr.begin(); it != usr.end(); ++it)
	{
		pair<int, ShoppingCart *> aux((*it)->getUserID(), new ShoppingCart);
		__UserID__ProductsCart__.insert(aux);
	}
	//throw("undefined");
}

list<Product *> &Server::getProductsList()
{
	return prod;
	//throw("undefined");
}

list<User *> &Server::getUsersList()
{
	return usr;
	//throw("undefined");
}

map<int, ShoppingCart *> Server::get__UserID__ProductsCart__()
{
	return __UserID__ProductsCart__;
	//throw("undefined");
}

bool Server::requestAddProduct(int userID, int productID, int quantity)
{   
	map<int, ShoppingCart *>::iterator iuc;
	list<Product *>::iterator iprod;

	if (quantity <= 0)
		return false;

	 int contor_Users = 0; //contoriez pt a vedea daca am parcurs lista de useri fara sa gasesc vreun user cu acelasi id

	for (iuc= __UserID__ProductsCart__.begin(); iuc != __UserID__ProductsCart__.end(); ++iuc)
	{
	    int contor_produs = 0; // analog pt lista de produse
		if (iuc->first == userID)
		{  
			
			for ( iprod= prod.begin(); iprod!= prod.end(); ++iprod)
			{     
				if ((*iprod)->getId() == productID) //  verific daca gasessc produsul in lista de produse din server
				{  
					
					int cartProductQuantity = iuc->second->getQuantity(productID); 
									
																							 
					if ( (*iprod)->checkQuantity(quantity))   //   verific daca cantitatea produsului din lista de produse este suficienta
					{                                            // verific daca produsul se afla sau nu in cos
						if (cartProductQuantity == -1)        // daca nu se afla
						{
							iuc->second->addProduct(productID, quantity);   //il adaug
							(*iprod)->decreaseQuantity(quantity);             //il scad de pe server
						}
						else
						{                                                  //dac se afla
							iuc->second->raiseQuantity(productID, quantity);   //ii cresc cantitatea din cos
							(*iprod)->decreaseQuantity(quantity);              //il scad de pe server
						}
					}
					else
						return false;          //nu am avut cantitatea suficienta in lista de produse
				}
				else
				{
					contor_produs++;             //produsele nu corespund
				}
				

				if (contor_produs== prod.size()) // numarul produselor diferite este egal cu numarul total de produse, adica nu am gasit in lista
				                                  // de produse produsul cautat
					return false;
			}



		}
		else
		{
			contor_Users++;   //userii nu corespund
		}
		
		if (contor_Users== __UserID__ProductsCart__.size()) //analog
			return false;
	}

	return true;

}

bool Server::requestDeleteProduct(int userID, int productID, int quantity)
{
	map<int, ShoppingCart *>::iterator uIDc;
	list<Product *>::iterator ip;
	
	if (quantity <= 0)
		return false;

	int contor_Users = 0;   //analog

	for (uIDc = __UserID__ProductsCart__.begin(); uIDc != __UserID__ProductsCart__.end(); ++uIDc)
	{
	    int contor_produs = 0;  //analog
		if (uIDc->first == userID)
		{
			for (ip = prod.begin(); ip != prod.end(); ++ip)
			{
				if ((*ip)->getId() == productID) // cautam produsul in server
				{
					if (uIDc->second->getQuantity(productID) != -1) // cautam produsul in cosul de cumparaturi
					{
						if (uIDc->second->getQuantity(productID) < quantity) // verificam daca vrem sa stergem o cantitate mai mare decat cea existenta in cos
						{
							(*ip)->increaseQuantity(uIDc->second->getQuantity(productID));              //stergem tot ce e disponiil in ocs
							uIDc->second->deleteProduct(productID);                                     //stergem produsul din cos
						}
						else                    //daca scoatem o parte din produsele din cos
						{
							(*ip)->increaseQuantity(quantity);         //punem cantitatea scoasa din cos in server        
							uIDc->second->lowerQuantity(productID, quantity);    //o scadem din cos
						}
					}
					else
						return false;         //nu avem produsul in cos
				}
				else
				{
					contor_produs++;   
				}

				if (contor_produs== prod.size())
					return false;
			}
		}
		else
		{
			contor_Users++;
		}

		if (contor_Users == __UserID__ProductsCart__.size())
			return false;
	}

	return true;

}

/* NU MODIFICATI */
void Server::populateProducts(const json &input)
{
	prod = ObjectFactory::getProductList(input["shoppingCart"]);
}

/* NU MODIFICATI */
void Server::populateUsers(const json &input)
{
	usr = ObjectFactory::getUserList(input["useri"]);
}