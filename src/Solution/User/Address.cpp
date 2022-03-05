#include "Address.h"

using namespace std;

Address::Address():number(0),apartment(0)
{
	county=string();
	locality=string();
	street=string();
	block=string();
	//throw("undefined");
}

Address::Address(const Address &address)
{ 
	county=address.county;
	locality=address.locality;
	street=address.street;
	number=address.number;
	block=address.block;
	apartment=address.apartment;
	//throw("undefined");
}

Address::Address(const string &jud, const string &loc, const string &str, int nr, const string &bl, int ap): county(jud), locality(loc), street(str), number(nr), block(bl), apartment(ap)
{
	//throw("undefined");
}

const Address &Address::operator=(const Address &adr)
{	
	if(this != &adr){
		county=adr.county;
		locality=adr.locality;
		street=adr.street;
		number=adr.number;
		block=adr.block;
		apartment=adr.apartment;
	}
	return *this;
	//throw("undefined");
}

void Address::setStrada(const string &str)
{
	street=str;
	//throw("undefined");
}

void Address::setNumber(int nr)
{
	number=nr;
	//throw("undefined");
}

void Address::setBlock(const string &bl)
{
	block=bl;
	//throw("undefined");
}

void Address::setApartment(int ap)
{
	apartment=ap;
	//throw("undefined");
}

void Address::setCounty(const string &jud)
{
	county=jud;
	//throw("undefined");
}

void Address::setLocality(const string &loc)
{
	locality=loc;
	//throw("undefined");
}

string &Address::getStreet()
{
	return street;
	//throw("undefined");
}

int Address::getNumber()
{
	return number;
	//throw("undefined");
}
string &Address::getBlock()
{
	return block;
	//throw("undefined");
}

int Address::getApartment()
{
	return apartment;
	//throw("undefined");
}

string &Address::getCounty()
{
	return county;
	//throw("undefined");
}

string &Address::getLocality()
{
	return locality;
	//throw("undefined");
}

bool Address::operator==(const Address &address)
{
	return ( (county == address.county) && (locality == address.locality) && (street == address.street) && (number == address.number) && (block == address.block ) && (apartment == address.apartment) );

	//throw("undefined");
}

bool Address::operator!=(const Address &address)
{
	return (!(*this==address));
	//throw("undefined");
}

ostream &operator<<(ostream &os, const Address &a)
{
	os << "Adresa" << endl;
	os << "Judet: " << a.county << endl;
	os << "Localitate: " << a.locality << endl;
	os << "Street: " << a.street << endl;
	os << "Numar: " << a.number << endl;
	os << "Bloc " << a.block << endl;
	os << "Apartament: " << a.apartment<< endl;
    	
	//throw("undefined");
 return os;
}

json Address::toJSON()
{
	return json(*this);
}