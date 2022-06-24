#include "UserHoliday.h"




UserHoliday::UserHoliday(std::vector<Holiday>& vHoliday, std::vector<Activity>& vActivities, std::vector<User>& vFamily){
    this->_vHoliday = vHoliday;
    this->_vActivities = vActivities;
    this->_vFamily = vFamily;
}