#ifndef MAIN_CPP_ACTIVITY_H
#define MAIN_CPP_ACTIVITY_H
#include <string>
#include <vector>

class Activity {
private:
    std::string _sActivity;
    int _iCost;
    std::vector<std::string> _vAvailableLocations;
public:
    //Get and Set functions for the Activity Variable.
    std::string GetActivity();
    void SetActivity(std::string sActivity);

    //Get and Set functions for the Cost Variable.
    int GetCost();
    void SetCost(int iCost);

    //Gets/Returns a vector of all available Locations for this Activity.
    std::vector<std::string>GetAvailableLocations();

    //Sets Available locations for activity, overload function allows for an Available Location to be modified at a specific index.
    void SetAvailableLocation(std::vector<std::string>vAvailableLocations);
    void SetAvailableLocation(int iVectorIndex, std::string sAvailableLocation);

    //Delete element from Vector of Available Locations based on Specified Index.
    void RemoveAvailableLocation(int iVectorIndex);
    //Add element to Vector of Available Locations.
    void AddAvailableLocation(std::string sNewLocation);

    //Constructor that requires declaration of all Class Variables as they are all required.
    Activity(std::string sActivity, int iCost, std::vector<std::string>vAvailableLocations);
};

#endif //MAIN_CPP_ACTIVITY_H
