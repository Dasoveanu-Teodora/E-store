#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "../Solution/Product/NonFoodProduct.h"
#include "../Solution/Product/FoodProduct.h"
#include "../Solution/User/BasicUser.h"
#include "../Solution/User/PremiumUser.h"


class Utility{

public:
    static bool compare_price( Product *,  Product  *) ;
     static bool compare_food( Product *,  Product  *) ;
     static bool compare_ID(User * ,User *);

};