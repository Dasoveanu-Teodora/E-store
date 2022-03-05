#include "LRUCache.h"
#include <algorithm>

using namespace std;

LRUCache::LRUCache(int capacity)
{
	this->capacity=capacity;
	size=0;
 	vector<int > init(capacity,0);
	 lru=init;
 	 init.clear();
}

vector<int> LRUCache::processRequests(vector<int> requestsNo)
{  
   int k=0;	
   for (int i=0;i<requestsNo.size();i++)
   {
	   if(lru.size()<capacity)
	   {
		   for(int j=0;j<lru.size();j++)
		   {
			   if(requestsNo[i]==lru[j])
			   {
				   for(int n=j;n>0;n--)
				     lru[n]=lru[n-1];
				  
				   break;
			   }
			   lru[k++]=requestsNo[i];
		   }
	   }
	   else
		   { for(int j=capacity;j>0;j--)
		   		lru[j]=lru[j-1];
			 lru[0]=requestsNo[i];
		   } 
	}
	return lru;
	

/*int k=0;	
   for (int i=0;i<requestsNo.size();i++)
   {
	   if(lru.size()<capacity)
	   {
		   for(int j=0;j<lru.size();j++)
		   {
			   if(requestsNo[i]==lru[j])
			   {
				   for(int n=j;n>0;n--)
				     lru[n]=lru[n-1];
				  
				   break;
			   }
			   size++;
			   lru[k++]=requestsNo[i];
		   }
	   }
	   else
		   { for(int j=capacity;j>0;j--)
		   		lru[j]=lru[j-1];
			 lru[0]=requestsNo[i];
		   } 
	}

*/	
	return lru;
	
}

int LRUCache::getCapacity()
{
	return capacity;
}

int LRUCache::getSize()
{
	return size;
}

vector<int> LRUCache::getLRU()
{
 	return lru;
}

int LRUCache::getLRUCapacity()
{
	return lru.capacity();
}

void LRUCache::setCapacity(int capacity)
{
	this->capacity=capacity;
}

void LRUCache::setLRU(vector<int> aux)
{
	lru=aux;
}