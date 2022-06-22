#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Holiday.h"
#include "Activity.h"
#include "User.h"

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

void MainMenu(){
    system("cls");

    std::cout << " Please choose from the following options:" << std::endl << std::endl;
    std::cout << "1. Manage your Family" << std::endl;
    std::cout << "2. Select a Holiday Location" << std::endl;
    std::cout << "3. Manage Holiday Activities" << std::endl;
    std::cout << "4. Confirm Holiday" << std::endl;
    std::cout << "5. Load Report" << std::endl;
    std::cout << "6. Login to Admin Area" << std::endl << std::endl;
    std::cout << "Please make a Selection: ";
}

void FamilyMenu(){
    system("cls");

    std::cout << "You are now managing your Family." << std::endl;

    std::cout << " Please choose from the following options:" << std::endl << std::endl;
    std::cout << "1. Add a Family Member" << std::endl;
    std::cout << "2. Remove a Family Member" << std::endl;
    std::cout << "3. Modify a Family Member" << std::endl;
    std::cout << "4. Confirm" << std::endl << std::endl;
    std::cout << "Please make a Selection: ";
}

void ManageUsers(std::vector<User>&vFamily){
    FamilyMenu()







};

void ManageLocations(){

};

void ManageActivities(){

};

void ConfirmHoliday(){

};

void LoadReport(){

};

void Admin(){

};


int main() {
    std::vector<Holiday>vHolidays;
    std::vector<Activity>vActivities;
    std::vector<User>vFamily;

    InitialiseHolidays(vHolidays);
    InitialiseActivities(vActivities);


    bool bStop = false;
    int iChoice = 0;

    do{
        Menu();

        std::cin >> iChoice;

        switch (iChoice) {
            case 1:
                ManageUsers(vFamily);
                break;
            case 2:
                ManageLocations();
                break;
            case 3:
                ManageActivities();
                break;
            case 4:
                ConfirmHoliday();
                bStop = true;
                break;
            case 5:
                LoadReport();
                break;
            case 6:
                Admin();
                break;
            default:
                std::cout << "Error: Please make a Selection.";
                break;

        }
    } while(!bStop);




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
