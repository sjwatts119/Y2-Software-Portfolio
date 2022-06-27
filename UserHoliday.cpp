#include "UserHoliday.h"

UserHoliday::UserHoliday(std::vector<Holiday>& vHoliday, std::vector<Activity>& vActivities, std::vector<User>& vFamily){
    this->_vHoliday = vHoliday;
    this->_vActivities = vActivities;
    this->_vFamily = vFamily;
}

std::string UserHoliday::GetLocation(){
    return _vHoliday.at(0).GetLocation();
}

double UserHoliday::GetLocationPrice(){
    return _vHoliday.at(0).GetCost();
}

//Return Holiday Activities
std::vector<std::string> UserHoliday::GetActivities(){
    std::vector<std::string> vActivities;
    for(auto & _vActivity : _vActivities){
        vActivities.push_back(_vActivity.GetActivity());
    }
    return vActivities;
}

std::vector<double> UserHoliday::GetActivitiesPrice(){
    std::vector<double> vActivitiesPrice;
    for(auto & Activity : _vActivities){
        vActivitiesPrice.push_back(Activity.GetCost());
    }
    return vActivitiesPrice;
};

std::vector<User> UserHoliday::GetFamily(){
    return _vFamily;
}


