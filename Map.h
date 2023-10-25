//********************************************************************
// ASU CSE310 Spring 2023 Assignment #8
// Name of Author: Sreeram Kondapalli
// ASU ID: 1221440298
// Description: This is the header file that defines an undirected graph
//              with an array of sites and routes
//********************************************************************

//include necessary header file here

#include "Route.h"
using namespace std;

class Map
{
   private:
      int numOfSites, numOfRoutes;
      Site* setOfSites;   //an array of Site. Note: you are NOT allowed to change it to Site**
      Route* setOfRoutes; //an array of Route. Note: you are NOT allowed to change it to Route**

   public:
      // Constructor that takes in number of sites, number of routes, site array and route array
      Map(int numOfSites, int numOfRoutes, Site* siteArray, Route* routeArray);

      // Destructor to deallocate memory allocated for setOfSites and setOfRoutes
     ~Map();

      // Creates a new set containing a single site
      void make_set(Site* oneSite);

      // Finds and returns the set that a given site belongs to
      Site* find_set(Site* oneSite);

      // Links two sets together
      void link(Site* aSite, Site* bSite);

      // Joins two sets together
      void Union(Site* aSite, Site* bSite);

      // Sorts the array of routes in ascending order based on their weights
      void sortRoutes();

      // Finds and returns the minimum spanning tree using Kruskal's algorithm
      void MST_Kruskal();

      // Add any auxiliary functions in case you need them
      //----

      // Auxiliary function that sorts an array of Route objects using the QuickSort algorithm
      void QuickSort(Route*, int low, int high);

      // Helper function used by QuickSort to partition an array of Route objects
      int Partition(Route* arr, int low, int high);
};



//finish each function according to above definition
Map::Map(int numOfSites, int numOfRoutes, Site* siteArray, Route* routeArray)
{
   // Constructor that initializes the private variables with the values of input parameters
   this->numOfSites = numOfSites;
   this->numOfRoutes = numOfRoutes;
   this->setOfSites = siteArray;
   this->setOfRoutes = routeArray;
}

void Map::make_set(Site* oneSite)
{
   // Create a new set containing a single site
   oneSite->parent = oneSite;
   oneSite->rank = 0;
}

Site* Map::find_set(Site* oneSite)
{
   // Find and return the set that a given site belongs to
   if(oneSite != oneSite->parent)
   {
      oneSite->parent = find_set(oneSite->parent);
   }
   return oneSite->parent;
}

void Map::link(Site* aSite, Site* bSite)
{
   // Links two sets together
   if(aSite->rank > bSite->rank)
   {
      bSite->parent = aSite;
   }
   else{
      aSite->parent = bSite;
      if(aSite->rank == bSite->rank)
      {
         bSite->rank++;
      }
   }
}

void Map::Union(Site* aSite, Site* bSite)
{
   // Joins two sets together
   link(find_set(aSite), find_set(bSite));
}

void Map::sortRoutes()
{
   // Sorts the array of routes in ascending order based on their weights
   QuickSort(setOfRoutes,0,numOfRoutes-1);
}

void Map::QuickSort(Route* arr, int low, int high)
{
   // Auxiliary function that sorts an array of Route objects using the QuickSort algorithm
   if(low < high)
   {
      int partition1 = Partition(arr, low, high);
      QuickSort(arr, low, partition1 - 1);
      QuickSort(arr, partition1 + 1, high);
   }
}


int Map::Partition(Route* arr, int low, int high)
{
   int pivot = arr[high].getDistance();
   int i = (low - 1);

   for(int j = low; j <= high - 1; j++)
   {
      if(arr[j].getDistance() < pivot){
         i++;
         swap(arr[i], arr[j]);
      }
   }
   swap(arr[i+1], arr[high]);
   return (i + 1);
}

//*******************************************************************
//This function performs the Kruskal algorithm on the graph
void Map::MST_Kruskal()
{
   cout << "\nMST Kruskal Algorithm Result\n" << endl;
   double totalDistance = 0.0;


   for(int i = 0; i < numOfSites; i++)
   {
      make_set(&setOfSites[i]);
   }
   sortRoutes();
   for(int i = 0; i < numOfRoutes; i++)
   {
      if(find_set(setOfRoutes[i].getSite1()) != find_set(setOfRoutes[i].getSite2()))
      {
         setOfRoutes[i].printRoute();
         totalDistance += setOfRoutes[i].getDistance();
         Union(setOfRoutes[i].getSite1(), setOfRoutes[i].getSite2());
      }
   }
   cout << "=====================================================================================" << endl;
    cout << "Total Distance: " << totalDistance << " meters" << endl;
}
