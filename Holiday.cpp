#include "Holiday.h"

std::string Holiday::GetLocation() {
    return this->_sLocation;
}
void Holiday::SetLocation(std::string sLocation) {
    this->_sLocation = sLocation;
}
int Holiday::GetCost() {
    return this->_iCost;
}
void Holiday::SetCost(int iCost) {
    this->_iCost = iCost;
}
int Holiday::GetMinimumTravellers() {
    return this->_iMinimumTravellers;
}
void Holiday::SetMinimumTravellers(int iMinimumTravellers) {
    this->_iMinimumTravellers = iMinimumTravellers;
}

Holiday::Holiday(std::string sLocation, int iCost, int iMinimumTravellers) {
    this->_sLocation = sLocation;
    this->_iCost = iCost;
    this->_iMinimumTravellers = iMinimumTravellers;
}