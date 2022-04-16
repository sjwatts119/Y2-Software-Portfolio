#include <iostream>
#include <vector>

class Location {
private:
    std::string _sLocation;
    int _iCost;
    int _iMinimumTravellers;
public:
    //Get and Set functions for the Location Variable.
    std::string GetLocation(){return _sLocation;}
    void SetLocation(std::string sLocation){_sLocation = sLocation;}

    //Get and Set functions for the Cost Variable.
    int GetCost(){return _iCost;}
    void SetCost(int iCost){_iCost = iCost;}

    //Get and Set functions for the Minimum Travellers Variable.
    int GetMinimumTravellers(){return _iMinimumTravellers;}
    void SetMinimumTravellers(int iMinimumTravellers){_iMinimumTravellers = iMinimumTravellers;}

    //Constructor that requires declaration of all Class Variables as they are all required.
    Location (std::string sLocation, int iCost, int iMinimumTravellers) {
        _sLocation = sLocation;
        _iCost = iCost;
        _iMinimumTravellers = iMinimumTravellers;}
};

class Activity {
private:
    std::string _sActivity;
    int _iCost;
    std::vector<std::string> _vAvailableLocations;
public:
    //Get and Set functions for the Activity Variable.
    std::string GetLocation(){return _sActivity;}
    void SetLocation(std::string sActivity){_sActivity = sActivity;}

    //Get and Set functions for the Cost Variable.
    int GetCost(){return _iCost;}
    void SetCost(int iCost){_iCost = iCost;}

    //Gets/Returns a vector of all available Locations for this Activity.
    std::vector<std::string>GetAvailableLocations(){return _vAvailableLocations;}

    //Sets Available locations for activity, overload function allows for an Available Location to be modified at a specific index.
    void SetAvailableLocation(std::vector<std::string>vAvailableLocations){_vAvailableLocations = vAvailableLocations;}
    void SetAvailableLocation(int iVectorIndex, std::string sAvailableLocation){_vAvailableLocations[iVectorIndex] = sAvailableLocation;}

    //Delete element from Vector of Available Locations based on Specified Index.
    void RemoveAvailableLocation(int iVectorIndex){_vAvailableLocations.erase(_vAvailableLocations.begin() + iVectorIndex);}
    //Add element to Vector of Available Locations.
    void AddAvailableLocation(std::string sNewLocation){_vAvailableLocations.push_back(sNewLocation);}

    //Constructor that requires declaration of all Class Variables as they are all required.
    Activity(std::string sActivity, int iCost, std::vector<std::string>vAvailableLocations){
        _sActivity = sActivity;
        _iCost = iCost;
        _vAvailableLocations = vAvailableLocations;
    }
};

//Method for initialising default Location Values in the Locations Vector (By Reference) as set out in the brief.
void InitialiseLocations(std::vector<Location>&vLocations){
    vLocations.push_back(Location("Florida", 1300, 4));
    vLocations.push_back(Location("Paris", 600, 2));
    vLocations.push_back(Location("Milan", 950, 2));
    vLocations.push_back(Location("Tokyo", 1800, 4));
}

//Method for initialising default Activity Values in the Activities Vector (By Reference) as set out in the brief.
void InitialiseActivities(std::vector<Activity>&vActivities){
    vActivities.push_back(Activity("Theme Park", 80, {"Florida", "Paris", "Tokyo"}));
    vActivities.push_back(Activity("Guided Tours", 35, {"Paris", "Milan", "Tokyo"}));
    vActivities.push_back(Activity("Sky Diving", 80, {"Florida"}));
}

int main() {
    std::vector<Location>vLocations;
    std::vector<Activity>vActivities;

    InitialiseLocations(vLocations);
    InitialiseActivities(vActivities);













    /*std::vector<std::string> vTest = vActivities[0].GetAvailableLocations();

    for (int i=0; i < vTest.size(); i++) {
        std::cout << vTest[i] << " ";
    }

    vActivities[0].RemoveAvailableLocation(1);
    vActivities[0].AddAvailableLocation("New Ting");
    vTest = vActivities[0].GetAvailableLocations();

    for (int i=0; i < vTest.size(); i++) {
        std::cout << vTest[i] << " ";
    }*/


    return 0;
}
