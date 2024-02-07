// Lab1bCOSC2436.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

class Gun {
public:
    double gunPrice;
    int numRoundsInMagazine; //the amount of bullets needed to fill a magazine
    //I'm gonna include a third variable so you know which guns I'm talking about. XD
    string gunName;

    /*Gun(double gPrice, int nRIM, string gName)
        :gunPrice(gPrice), numRoundsInMagazine(nRIM), gunName(gName)
    {};*/

    //this is the way I was taught to create new constructors, so I'm gonna use it since I'm more familiar with this style. :)
    Gun(double gPrice, int nRIM, string gName) {
        gunPrice = gPrice;
        numRoundsInMagazine = nRIM;
        gunName = gName;
    }

    //overloading output operator, as shown in class
    friend ostream& operator << (ostream& os, const Gun& gun);

    bool operator < (const Gun& otherGun) {
        return (this->numRoundsInMagazine > otherGun.numRoundsInMagazine);
    }
};

ostream& operator<<(ostream& os, const Gun& gun)
{
    os << left << setw(10) << gun.gunPrice << setw(10)
        << gun.numRoundsInMagazine << setw(10) <<
        gun.gunName << endl;
    return os;
    // TODO: insert return statement here
}

void printGunList(vector<Gun> gunList) {
    for (Gun& eachGun : gunList) {
        cout << eachGun;
    }
}

bool compareGunPrices(const Gun& firstGun, const Gun& nextGun) {
    return (firstGun.gunPrice < nextGun.gunPrice);
}

bool compareGunPricesbyDescending(const Gun& firstGun, const Gun& nextGun) {
    //Got it on the first try, whoop whoop! XD
    return (firstGun.gunPrice > nextGun.gunPrice);
}

int main()
{
    cout << std::boolalpha;

    vector<Gun> gunsList;
    gunsList.push_back(Gun{ 599.00, 26, "CZ Combat 9MM" });
    gunsList.push_back(Gun{ 1149.99, 8, "Colt 1911P6 .45" });
    gunsList.push_back(Gun{ 299.99, 6, "Beretta PICO .380" });

    cout << "The guns I chose, in the order I wrote them:" << endl;
    printGunList(gunsList);

    std::sort(gunsList.begin(), gunsList.end());
    cout << "\n\n\nGuns sorted by number of rounds in the magazine:" << endl;
    printGunList(gunsList);

    cout << "\n\nGuns sorted by price:" << endl;
    std::sort(gunsList.begin(), gunsList.end(), compareGunPrices);
    printGunList(gunsList);

    cout << "\n\nGuns sorted by price in DESCENDING order:" << endl;
    std::sort(gunsList.begin(), gunsList.end(), compareGunPricesbyDescending);
    printGunList(gunsList);


    return 0;
}
