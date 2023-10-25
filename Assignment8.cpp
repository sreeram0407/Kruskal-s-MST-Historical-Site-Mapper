//************************************************************************
// Name: Sreeram Kondapalli
// Description: this is the main program that reads input from keyboard,
// it then use disjoint set data structure to perform Kruskal MST algorithm
// on the graph.
// //---- is where you need to add your own codes
//**************************************************************************

//include necessary header file
//----
#include "Map.h"

using namespace std;

void getArrSiteInfo(string oneArrSiteInfo, string& arrSiteName, double& distance);

int main()
{
    //Maximum possible sites and route number
    const int MAX_SITE_NUM = 50, MAX_ROUTE_NUM = 100;
    int numOfSites = 0, numOfRoutes = 0;  //counter used to track actual number of sites and routes


   //create an array of Site which store all Site (vertex of the graph)
   //----
   Site* arrayOfSites = new Site[MAX_SITE_NUM];

   //create an array of Route which store all Route (edges of the graph)
   //----
   Route* arrayOfRoutes = new Route[MAX_ROUTE_NUM];

   //declare all necessary local variables here
   string token = "", name = "", oneArrSiteInfo = "", delimiter = ",";
   double distance = 0.0;

   string oneLine;

   getline(cin, oneLine);

   while(oneLine.compare("End") != 0)
   {
      //get one line of the input, extract the first token
      //create a Site object if it does not exist in site array,
      //insert it inside the site array. This will be first point of the 'aNewRoute'


      Site* siteA = nullptr;
      token = oneLine.substr(0,oneLine.find(delimiter));
      oneLine.erase(0, oneLine.find(delimiter) + 1);

      for(int i = 0; i < numOfSites; i++)
      {
         if(token == arrayOfSites[i].siteName)
         {
            siteA = &arrayOfSites[i];
            break;
         }
      }

      if(siteA == nullptr)
      {
         Site newSite = Site(token);
         arrayOfSites[numOfSites] = newSite;
         siteA = &arrayOfSites[numOfSites];
         numOfSites = numOfSites + 1;
      }

      while(oneLine != "")
      {
            oneArrSiteInfo = oneLine.substr(0, oneLine.find(delimiter));
            if(oneArrSiteInfo != "")
            {
               getArrSiteInfo(oneArrSiteInfo, name, distance);
               Site* siteB =  nullptr;

               for(int i = 0; i < numOfSites; i++)
               {
                  if(name == arrayOfSites[i].siteName)
                  {
                     siteB = &arrayOfSites[i];
                     break;
                  }
               }

               if(siteB == nullptr)
               {
                  Site newSite = Site(name);
                  arrayOfSites[numOfSites] = newSite;
                  siteB = &arrayOfSites[numOfSites];
                  numOfSites = numOfSites + 1;
               }

               arrayOfRoutes[numOfRoutes] = Route(siteA,siteB,distance);
               numOfRoutes = numOfRoutes + 1;
            }
         
         oneLine.erase(0, oneLine.find(delimiter) + 1);
      }
      

      //extract the arrival site info. check whether it exists in
      //site array or not, if not, create a new Site object, add it inside.
      //This site will be the second point of the 'aNewRoute'
      //----
      //----

      //by using the two sites we got above, create a new route, add
      //it inside route array
      //----
      //----

      //get next line
      getline(cin, oneLine);
   } //repeat until the 'End'

   //Create a Map object by using site array and route array
   //----
   Map* map = new Map(numOfSites,numOfRoutes,arrayOfSites,arrayOfRoutes);

   cout << "Total historical sites you will visit: " << numOfSites << endl;
   //Run Kruskal MST algorithm on above map
   //----
   map->MST_Kruskal();
}
//****************************************************************
//By giving a string, for example 'Pantheon(300.5)', this function
//extract the arrival site 'Pantheon' and distance '300.5' meters
//Note: the delimiter is left and right parenthesis
//****************************************************************
void getArrSiteInfo(string oneArrSiteInfo, string& arrSiteName, double& distance)
{
   //----
   //----
   if(oneArrSiteInfo != "")
   {
      int pos = oneArrSiteInfo.find("(");
      string token = oneArrSiteInfo.substr(0, pos);
      arrSiteName = token;
      oneArrSiteInfo.erase(0, pos + 1);

      pos = oneArrSiteInfo.find(")");
      token = oneArrSiteInfo.substr(0, pos);
      distance = stod(token);
      oneArrSiteInfo.erase(0, pos + 1);
   }
}

