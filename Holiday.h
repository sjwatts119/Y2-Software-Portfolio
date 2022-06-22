#ifndef MAIN_CPP_HOLIDAY_H
#define MAIN_CPP_HOLIDAY_H
#include <string>

class Holiday {
private:
    std::string _sLocation;
    int _iCost;
    int _iMinimumTravellers;
public:
    //Get and Set functions for the Location Variable.
    std::string GetLocation();
    void SetLocation(std::string sLocation);

    //Get and Set functions for the Cost Variable.
    int GetCost();
    void SetCost(int iCost);

    //Get and Set functions for the Minimum Travellers Variable.
    int GetMinimumTravellers();
    void SetMinimumTravellers(int iMinimumTravellers);

    //Constructor that requires declaration of all Class Variables as they are all required.
    Holiday (std::string sLocation, int iCost, int iMinimumTravellers);
};

#endif //MAIN_CPP_HOLIDAY_H
