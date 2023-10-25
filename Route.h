//********************************************************************
// ASU CSE310 Spring 2023 Assignment #8
// Name of Author: Sreeram Kondapalli
// ASU ID: 1221440298
// Description: //---- is where you should add your own code
//********************************************************************

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Site represents one vertex of the map
struct Site
{
    string siteName;
    int rank;
    struct Site* parent;

   //C++ don't provide a default constructor, need it here.
   Site()
   {
        //----
        //----
        this->siteName = "";
        this->rank = 0;
        this->parent = nullptr;
   }

   //overloaded constructor
   Site(string name)
   {
      //----
      //----
      this->siteName = name;
      this->rank = 0;
      this->parent = nullptr;
   }
};

//Route represents one edge of the map which connects two historical sites of Rome
class Route
{
    private:
       struct Site* site1;
       struct Site* site2;
       double distance;

	public:
	   Route();
       Route(Site* site1, Site* site2, double distance);
       Site* getSite1();
       Site* getSite2();
       double getDistance();
       void printRoute();
};

//finish each function according to above definition
//----
//----

Route::Route()
{
   this->site1 = nullptr;
   this->site2 = nullptr;
   this->distance = 0;
}

Route::Route(Site* site1, Site* site2, double distance)
{
   this->site1 = site1;
   this->site2 = site2;
   this->distance = distance;
}

Site* Route::getSite1()
{
   return this->site1;
}

Site* Route::getSite2()
{
   return this->site2;
}

double Route::getDistance()
{
   return this->distance;
}

void Route::printRoute()
{
   cout << left;
    cout << setw(33) << site1->siteName
         << setw(8) << "<--->"
         << setw(33) << site2->siteName
         << setw(3) << " = "
         << setw(8) << right << fixed << setprecision(1) << getDistance()
         << endl;
}
