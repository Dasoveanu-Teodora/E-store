#include "QuerySolver.h"

using namespace std;

/* NU MODIFICATI */
QuerySolver::QuerySolver()
{
  server = Server::GetInstance();
}

/* NU MODIFICATI */
QuerySolver::~QuerySolver()
{
  if (server != nullptr)
  {
    server = nullptr;
  }
}

list<Product *> QuerySolver::Query_3a()
{

  list<Product *> ess_prod;
  list<Product *>::iterator ip;

  for (ip = server->getProductsList().begin(); ip != server->getProductsList().end(); ++ip)
  {
    if (((*ip)->getCategory() == "espressor") && ((*ip)->getProductType() == "redus"))
    {
      ess_prod.push_back(*ip);
    }
  }

  return ess_prod;
}

list<User *> QuerySolver::Query_3b()
{

  list<User *> non_premium;
  list<User *>::iterator iu;

  for (iu = server->getUsersList().begin(); iu != server->getUsersList().end(); ++iu)
    if (((*iu)->getUserType() == "nonPremium") && ((*iu)->getTransportCost() <= 11.5))
    {
      non_premium.push_back(*iu);
    }

  return non_premium;
}

list<Product *> QuerySolver::Query_3c()
{

  list<Product *> rese_prod;
  list<Product *>::iterator ip;

  for (ip = server->getProductsList().begin(); ip != server->getProductsList().end(); ++ip)
    if ((*ip)->getProductType() == "resigilat")
    {
      ResealedProduct *res = dynamic_cast<ResealedProduct *>(*ip);

      if (res->getReason() == "lipsa_accesorii")
      {
        rese_prod.push_back(res);
      }
    }

  rese_prod.sort(Utility::compare_price);

  return rese_prod;
}

list<Product *> QuerySolver::Query_3d()
{

  list<Product *>::iterator ipa;
  list<Product *> food_prod;

  for (ipa = server->getProductsList().begin(); ipa != server->getProductsList().end(); ++ipa)
  {
    if ((*ipa)->getProductType() == "alimentar")
    {
      food_prod.push_back(*ipa);
    }
  }

  food_prod.sort(Utility::compare_food);

  return food_prod;
}

list<User *> QuerySolver::Query_3e()
{

  list<User *> ushome;
  list<User *>::iterator iu;

  map<string, int> mc;
  map<string, int>::iterator im;

  for (iu = server->getUsersList().begin(); iu != server->getUsersList().end(); ++iu)
  {
    if (mc.find((*iu)->getBillingData().getCounty()) == mc.end())
      mc.insert(pair<string, int>((*iu)->getBillingData().getCounty(), 1));
    else
    {
      im = mc.find((*iu)->getBillingData().getCounty());
      im->second++;
    }
  }
  int currentMax = 0;
  string key;

  for (im = mc.begin(); im != mc.end(); im++)
  {
    if (im->second > currentMax)
    {
      currentMax = im->second;
      key = im->first;
    }
  }

  for (iu = server->getUsersList().begin(); iu != server->getUsersList().end(); ++iu)
  {
    if ((*iu)->getBillingData().getCounty() == key)
      if (((*iu)->getDeliveryData().getBlock() == "-") && ((*iu)->getDeliveryData().getApartment() == 0))
      {
        ushome.push_back(*iu);
      }
  }

  ushome.sort(Utility::compare_ID);

  mc.clear();
  return ushome;
}

list<User *> QuerySolver::Query_3f()
{
  list<User *> usedisc;
  list<User *>::iterator iu;
  list<User *>::iterator iuse;
  list<Product *>::iterator ip;
  map<int, int> disc;
  map<int,int> ::iterator md;

  for(iu=server->getUsersList().begin();iu!=server->getUsersList().end();++iu)
  {     
      if((*iu)->getUserType()=="premium")
      {
        int ok=1;
        for(iuse=usedisc.begin();iuse!=usedisc.end();++iuse)
          if((*iu)->getUserID()==(*iuse)->getUserID())
            ok=0;
             
        if(ok==1)  
        {  
          PremiumUser *premusr = dynamic_cast<PremiumUser*>(*iu);
          disc=premusr->getDiscounts();
          for(md=disc.begin();md!=disc.end();++md) 
            { 
              int oki=1;
              for(ip=server->getProductsList().begin();ip!=server->getProductsList().end();++ip)
                { 
                  if((*md).first==(*ip)->getId())
                  {
                     if( ((*ip)->getCategory()=="telefon") || ((*ip)->getCategory()=="imprimanta") )
                     {
                       usedisc.push_back(*iu);
                        oki=0;
                        break;
                     }
                  }
                 }  
               if(oki==0)
                    break;
              }          
          }
        } 
    }
  return usedisc; 
}

