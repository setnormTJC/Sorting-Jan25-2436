#include <iostream>

#include<vector>

#include <algorithm>
using namespace std;

//class Date //do this instead of string if you like 
//{
//    int m; 
//    int d; 
//    int y; 
//};

class Shoe
{
public: 
    double shoePrice; 
    int customerStars; //review/rating
    string arrivalDate; //Jan 31, 2024

    Shoe(double sPrice, int cStars, string aDate)
        :shoePrice(sPrice), customerStars(cStars), arrivalDate(aDate)
    {}
};

int main()
{
    
    Shoe myShoes{ 120.99, 4, "Jan 1, 2023" };

    vector<Shoe> shoeList; 
    shoeList.push_back(myShoes);

    shoeList.push_back(Shoe{99.45, 3, "Mar 43, 20'120"});
 

    //std::sort()
    cout << myShoes.arrivalDate << "\t" << myShoes.customerStars
        << "\t" << myShoes.shoePrice << endl; 

    return 0;
}