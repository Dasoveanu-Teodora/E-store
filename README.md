I  implemented a store that includes source files and headers for
Products, which are of two types, food and non-food, derived from the basic class Product. Non-food products in turn are a parent class for discounted and returned products. Resealed products are both discounted and returned. This is where the Dead Diamound problem comes in, which we avoid by virtualizing the parent classes, that is, for the reduced products and the one with the returned products. Thus we must call the manufacturers and the specific methods for the attributes from non-food products for the handling of a resealed product time object.
The user hierarchy includes the aggregate class Address, which includes the location data, which is in the general user class, which contains details for the purchase. There are two types of users, one Basic who has to pay the cost of transport and another who has discounts and does not have to pay the transport, but who has to pay a subscription, premiumSubscription.

 In the shopping cart we have a container in which we add products, these are identified by a key that represents the product id that is in the Product class.
Also here we have added options to remove an object from the cart or add it: lowerQuantity and raiseQuantity. When we want to remove an object from the basket we use deleteProduct.

The Server class links all operations, contains the list of products and users, and a container for identifying each user's cart.
Here are the functions for adding and deleting products from the cart.
Mainly, I chose to go through the cart and find out if I have any key what the id is looking for. If I found it, I test to see if I have the product valid on the server and if I can perform the necessary operations on it.
To check if a user is not found, respectively a product, I chose to increment a counter whenever the ids do not match.
Thus, if an id never appears, the number of occurrences will be maximum, ie the number of products / ids on the server, so I return false.

Query Solver is a class with which we query
data from the server, basically go through the lists, test the necessary conditions, sort the list where appropriate.
The most interesting thing was to see how a dynamic cast works, we can call methods for a derived object that is in an inhomogeneous list of pointers to the parent class type.

In working with LRU cahe the most important is the implementation of processRequests in which they build the lru vector of the given capacity and make successive permutations, making sure that the numbers are not repeated to create the ids corresponding to the requests

In the utility class we implemented the necessary ones for the different types of list sources, we implemented comparison functions between two products or two users.

Otherwise, for all the classes in the Product, User, Server, LRU cache, Shopping Cart Hierarchies, we implemented the get-sets and sets, as well as the operators necessary for a better handling.


