#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Holiday.h"
#include "Activity.h"

//Method for initialising default Location Values in the Locations Vector (By Reference) as set out in the brief.
void InitialiseHolidays(std::vector<Holiday>&vHolidays){
    vHolidays.emplace_back(Holiday("Florida", 1300, 4));
    vHolidays.emplace_back(Holiday("Paris", 600, 2));
    vHolidays.emplace_back(Holiday("Milan", 950, 2));
    vHolidays.emplace_back(Holiday("Tokyo", 1800, 4));
}

//Method for initialising default Activity Values in the Activities Vector (By Reference) as set out in the brief.
void InitialiseActivities(std::vector<Activity>&vActivities){
    vActivities.push_back(Activity("Theme Park", 80, {"Florida", "Paris", "Tokyo"}));
    vActivities.push_back(Activity("Guided Tours", 35, {"Paris", "Milan", "Tokyo"}));
    vActivities.push_back(Activity("Sky Diving", 110, {"Florida"}));
}

int main() {
    std::vector<Holiday>vHolidays;
    std::vector<Activity>vActivities;

    InitialiseHolidays(vHolidays);
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
