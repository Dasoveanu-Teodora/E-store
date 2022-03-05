#include "utility.h"

bool Utility::compare_price( Product * res1,  Product * res2) {
   
   NonFoodProduct *nfp1=dynamic_cast<NonFoodProduct*>(res1);
   NonFoodProduct *nfp2=dynamic_cast<NonFoodProduct*>(res2);


   if( nfp1->getPrice()<nfp2->getPrice())
        return true;
   else
       return false;
}

bool Utility::compare_food( Product * p1,  Product * p2) {
   
   FoodProduct *fp1=dynamic_cast<FoodProduct*>(p1);
   FoodProduct *fp2=dynamic_cast<FoodProduct*>(p2);

   if(fp1->getName() < fp2->getName())
        return true;
   else 
      { 
        if(fp1->getName() == fp2->getName())
           
             if(fp1->getCountryOfOrigin()<fp2->getCountryOfOrigin()) 
                return true;  
             else
             {  
                if(fp1->getCountryOfOrigin()==fp2->getCountryOfOrigin())
                    if(fp1->getLeiPerKg()<fp2->getLeiPerKg())
                        return true;
                    else
                        return false;
                else
                    return false;   
             }      
        else
             return false;
              
      }
}

bool Utility::compare_ID(User *u1,User*u2){
     return (u1->getUserID()< u2->getUserID());

}