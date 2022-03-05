#include "PremiumUser.h"

using namespace std;

PremiumUser::PremiumUser():User()
{
	premiumSubscriptionCost=0;
	//throw("undefined");
}

PremiumUser::PremiumUser(const string &judetf, const string &localitatef, const string &stradaf, int nr_stradaf, const string &blocf, int apartamentf,
						 const string &judetl, const string &localitatel, const string &stradal, int nr_stradal, const string &blocl, int apartamentl,
						 int id, const string &nume, const string &prenume, const string &email, int premiumSubscriptionCost, const map<int, int> &discounts)
	: User(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf, judetl, localitatel, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email)
{
	this->premiumSubscriptionCost=premiumSubscriptionCost;
	this->discounts=discounts;

	
	//throw("undefined");
}

PremiumUser::PremiumUser(const PremiumUser &up) : User(up)
{//verifica daca e mai mic (size)
	discounts=up.discounts;
	premiumSubscriptionCost=up.premiumSubscriptionCost;
	//throw("undefined");
}

const PremiumUser &PremiumUser::operator=(const PremiumUser &up)
{	
	if( this != &up)
	{	User::operator=(up);
		premiumSubscriptionCost=up.premiumSubscriptionCost;
		discounts=up.discounts;
	}
	return *this;
	//throw("undefined");
}

void PremiumUser::displayUser()
{ 	
	cout <<"Utilizator premium" <<endl<<endl;
	cout <<"Datele de facturare: "<<getBillingData()<<endl;
	cout <<"Datele de livrare: " <<getDeliveryData()<<endl;
	cout <<"Numele de familie: " <<getLastName()<<endl;
	cout <<"Prenumele: "<<getFirstName()<<endl;
	cout <<"Email: "<< getEmail()<<endl;
	cout <<"Id-ul utilizatorului: "<< getUserID()<<endl;
	cout <<"Abonament: "<<premiumSubscriptionCost<<endl;

	map<int,int>::iterator it;
	cout <<"Reduceri"<<endl<<endl;
	for (it=discounts.begin(); it!=discounts.end(); ++it)
    	cout << "Id produs: "<< it->first << "  =>  " << "Reducere: " <<it->second << '\n';
	
	//throw("undefined");
}

string PremiumUser::getUserType()
{
	
	return "premium";
	//throw("undefined");
}

float PremiumUser::getTransportCost()
{
	return 0;
	//throw("undefined");
}

map<int, int> &PremiumUser::getDiscounts()
{
	return discounts;
	//throw("undefined");
}

void PremiumUser::setDiscounts(map<int, int> red)
{
	discounts=red;
	//throw("undefined");
}

void PremiumUser::setPremiumSubscriptionCost(int cap)
{
	premiumSubscriptionCost=cap;
	//throw("undefined");
}

int PremiumUser::getPremiumSubscriptionCost()
{
	return premiumSubscriptionCost;
	//throw("undefined");
}

json PremiumUser::toJSON()
{
	return json(*this);
}