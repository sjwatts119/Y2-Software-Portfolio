//
#ifndef MAIN_CPP_USERHOLIDAY_H
#define MAIN_CPP_USERHOLIDAY_H

#include <string>
#include <vector>
#include "Holiday.h"
#include "Activity.h"
#include "User.h"

class UserHoliday {
private:
    std::vector<Holiday> _vHoliday;
    std::vector<Activity>_vActivities;
    std::vector<User>_vFamily;
public:



UserHoliday(std::vector<Holiday>& vHoliday, std::vector<Activity>& vActivities, std::vector<User>& vFamily);

};

#endif //MAIN_CPP_USERHOLIDAY_H
