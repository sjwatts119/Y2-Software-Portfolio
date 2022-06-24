#include "Activity.h"

std::string Activity::GetActivity() {
    return this->_sActivity;
}
void Activity::SetActivity(std::string sActivity) {
    this->_sActivity = sActivity;
}

//Get and Set functions for the Cost Variable.
int Activity::GetCost() {
    return this->_iCost;
}
void Activity::SetCost(int iCost) {
    this->_iCost = iCost;
}

//Gets/Returns a vector of all available Locations for this Activity.
std::vector<std::string> Activity::GetAvailableLocations() {
    return this->_vAvailableLocations;
}

//Sets Available locations for activity, overload function allows for an Available Location to be modified at a specific index.
void Activity::SetAvailableLocation(std::vector<std::string>vAvailableLocations) {
    this->_vAvailableLocations = vAvailableLocations;
}
void Activity::SetAvailableLocation(int iVectorIndex, std::string sAvailableLocation) {
    this->_vAvailableLocations[iVectorIndex] = sAvailableLocation;
}

//Delete element from Vector of Available Locations based on Specified Index.
void Activity::RemoveAvailableLocation(int iVectorIndex){
    this->_vAvailableLocations.erase(this->_vAvailableLocations.begin() + iVectorIndex);
}
//Add element to Vector of Available Locations.
void Activity::AddAvailableLocation(std::string sNewLocation){
    this->_vAvailableLocations.push_back(sNewLocation);
}

//Constructor that requires declaration of all Class Variables as they are all required.
Activity::Activity(std::string sActivity, int iCost, std::vector<std::string>vAvailableLocations){
    this->_sActivity = sActivity;
    this->_iCost = iCost;
    this->_vAvailableLocations = vAvailableLocations;
}