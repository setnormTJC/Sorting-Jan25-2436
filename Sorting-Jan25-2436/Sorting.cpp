#include <algorithm>
#include<iomanip>
#include <iostream>
#include<vector>

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
    {};

    //overload the output operator (<< the "stream insertion operator")
    friend ostream& operator << (ostream& os, const Shoe& shoeObj);
    //declares this overloaded operator 

    //overload the LESS THAN operator for shoe objects: 
    bool operator < (const Shoe& otherShoe)
    {
        return (this->customerStars < otherShoe.customerStars);
    }
};

//definition of overloaded output operator (<<) for `Shoe` objects: 

ostream& operator << (ostream& os, const Shoe& shoeObj)
{
    os << left << setw(10) << shoeObj.shoePrice <<
        setw(10) << shoeObj.customerStars <<
        setw(10) << shoeObj.arrivalDate << endl; 
    return os; 
}

void printShoeList(vector<Shoe> shoes)
{
    for (Shoe& shoeObj : shoes)
    {
        cout << shoeObj; 
    }
}

/// <summary>
/// 
/// </summary>
/// <param name="leftShoe"></param>
/// <param name="rightShoe"></param>
/// <returns></returns>
bool compareShoesByPrice(const Shoe& leftShoe, const Shoe& rightShoe)
{
    return (leftShoe.shoePrice < rightShoe.shoePrice);
}



int main()
{
    cout << std::boolalpha;  //displays true instead of 1 and false instead of 0
    

    Shoe myShoes{ 120.99, 4, "Jan 1, 2023" }; //Altra
    //Shoe herShoes{ 99.99, 1, "Some date" }; 
    //cout << (myShoes < herShoes) << endl; 
    //cout << myShoes;
    vector<Shoe> shoeList; 


    shoeList.push_back(myShoes);
    //cout << shoeList[0];
    //cout << shoeList.at(0);



    shoeList.push_back(Shoe{99.45, 3, "Mar 3, 2020"});
    shoeList.push_back(Shoe{ 178.60, 2, "April 1, 2022" });

    cout << "UNSORTED shoe list" << endl;
    printShoeList(shoeList);
    
    std::sort(shoeList.begin(), shoeList.end());
    cout << "\n\n\nSorted by review: " << endl; 
    printShoeList(shoeList); 


    cout << "\n\nSorted by PRICE: " << endl; 
    std::sort(shoeList.begin(), shoeList.end(), compareShoesByPrice);
    printShoeList(shoeList); 
        //cout << compareShoesByPrice << endl; 

    cout << "\n\nSorted by arrival date " << endl; 
    std::sort(shoeList.begin(), shoeList.end(),
        [](Shoe& leftShoe, Shoe& rightShoe) //sortByArrivalDate
        {
            return leftShoe.arrivalDate < rightShoe.arrivalDate; 
        }
    );

    printShoeList(shoeList);

    //
    ////cout << "\n\n\nMain function address: " << main << endl;
    ////cout << "Compare shoes by price function address: " << compareShoesByPrice << endl;
    //cout << "\n\n\nshoe list - sorted by price? " << endl;
    //std::sort(shoeList.begin(), shoeList.end(), compareShoesByPrice); //this is a FUNCTION POINTER
    //printShoeList(shoeList);

    //cout << "\n\nNow, sorted by popularity (number of \"stars\") \a: " << endl;
    //std::sort(shoeList.begin(), shoeList.end());
    //printShoeList(shoeList);

    //a last way to sort class objects by a certain member variable
    //using "lambda functions" - > HOORAY!

    //auto greaterThan5 = [](int a) 
    //    {
    //        return (a > 5); 
    //    }; 

    //cout << typeid(greaterThan5).name() << endl; 
    //[]() {}
    //vector<int> nums = { 6, 7, 8, -9 };

    //cout << std::all_of(nums.begin(), nums.end(), greaterThan5) << endl; //C++ standard library algorithm 
    
    //std::sort(shoeList.begin(), shoeList.end());
    
    
    //    []()
    //    {

    //    })
    //auto a = 5.0f; //doubles occupy DOUBLE the space of floats 
    //auto a = 'c';
    //cout << typeid(a).name() << endl; 

    //cout << typeid(thing).name() << endl; 

    return 0;
}