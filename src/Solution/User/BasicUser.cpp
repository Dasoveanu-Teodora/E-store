#include "BasicUser.h"

using namespace std;

BasicUser::BasicUser():User(),costTransport(0)
{
	//throw("undefined");
}

BasicUser::BasicUser(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf, const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl, int id, const string &nume, const string &prenume, const string &email, float costTransport) : User(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf, judetl, localitatel, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email)
{   
	this->costTransport=costTransport;
	//throw("undefined");
}

BasicUser::BasicUser(const BasicUser &unp) : User(unp)
{
	costTransport=unp.costTransport;
	//throw("undefined");
}

BasicUser &BasicUser::operator=(const BasicUser &unp)
{
	if(this!= &unp)
	{
		User::operator=(unp);
		costTransport=unp.costTransport;
	}
	//throw("undefined");
	return *this;
}

void BasicUser::setTransportCost(int cost)
{
	costTransport=cost;
	//throw("undefined");
}

float BasicUser::getTransportCost()
{
	return costTransport;
	//throw("undefined");
}

void BasicUser::displayUser()
{  
	cout <<"Utilizator obisnuit" <<endl<<endl;
	cout <<"Datele de facturare: "<<getBillingData()<<endl;
	cout <<"Datele de livrare: " <<getDeliveryData()<<endl;
	cout <<"Numele de familie: " <<getLastName()<<endl;
	cout <<"Prenumele: "<<getFirstName()<<endl;
	cout <<"Email: "<< getEmail()<<endl;
	cout <<"Id-ul utilizatorului: "<< getUserID()<<endl;
	cout <<"Costul trasnportului: "<<costTransport; 
	//throw("undefined");
}

string BasicUser::getUserType()
{
	
	return "nonPremium";
	//throw("undefined");
}

json BasicUser::toJSON()
{
	return json(*this);
}
