#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

#include "Holiday.h"
#include "Activity.h"
#include "User.h"
#include "UserHoliday.h"

void clearScreen(){
    //Clears the screen
    std::cout << std::string(50, '\n');
}

void Confirm(){
    std::cout << "Press Enter to Continue...";
    //Make sure the user presses enter before continuing.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

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

//Prints the Main Menu to the screen.
void MainMenu(){
    clearScreen();

    //Prints the Main Menu
    std::cout << " Please choose from the following options:" << std::endl << std::endl;
    std::cout << "1. Manage your Family" << std::endl;
    std::cout << "2. Manage Holiday" << std::endl;
    std::cout << "3. Confirm Holiday" << std::endl;
    std::cout << "4. Load Report" << std::endl;
    std::cout << "5. Login to Admin Area" << std::endl << std::endl;
    std::cout << "Please make a Selection: ";
}

//Prints the Manage Family Menu to the screen.
void FamilyMenu(){
    clearScreen();

    //Prints the Family Menu
    std::cout << "You are now managing your Family." << std::endl;

    std::cout << " Please choose from the following options:" << std::endl << std::endl;
    std::cout << "1. Add a Family Member" << std::endl;
    std::cout << "2. Remove a Family Member" << std::endl;
    std::cout << "3. Modify a Family Member" << std::endl;
    std::cout << "4. Confirm" << std::endl << std::endl;
    std::cout << "Please make a Selection: ";
}

//Prints the Current Family Members to the screen.
void PrintFamily(std::vector<User>&vFamily){
    //Print out the Family Vector to the screen.
    for(int i = 0; i < vFamily.size(); i++){
        std::cout << i+1 << ": " << vFamily[i].GetName() << " (" << vFamily[i].GetAge() << ")" << std::endl;

        if(i == vFamily.size()-1){
            std::cout << "0: Back" << std::endl;
        }
    }
}

//Allows the user to add a new Family Member to the Family Vector.
void AddUser(std::vector<User>&vFamily) {
    bool bStop = false;

    do{
        clearScreen();

        std::string sName;
        int iAge = 0;

        //Prompts the user to enter the name of the new user
        std::cout << "Please Enter the Person's Name: ";
        std::cin >> sName;
        std::cout << "Please enter the Person's Age: ";
        std::cin >> iAge;

        //Push back the Family Vector with the new Person's Information.
        vFamily.emplace_back(User(sName, iAge));

        //Prompts the user to add another Person or not.
        std::string sChoice;
        std::cout << "Would you like to add another user? (y/n): ";
        std::cin >> sChoice;

        //If the user wants to add another Person, the loop will continue. If not, the loop will stop.
        if (sChoice == "n" || sChoice == "N"){
            std::cout << "\n" << std::endl;
            std::cout << "You will now be returned to the Family Management Menu." << std::endl;
            Confirm();
            bStop = true;
        }
    } while(!bStop);
}

//Allows the user to remove a Family Member from the Family Vector.
void DeleteUser(std::vector<User>&vFamily){
    bool bStop = false;

    do{
        //If Family Vector is Empty, the user will be returned to the Family Management Menu.
        if(vFamily.empty()) {
            clearScreen();
            std::cout << std::endl;
            std::cout << "You have no family members to remove." << std::endl;
            Confirm();
            return;
        }
        //Clear the screen
        clearScreen();

        //Print out the Family Vector to the screen.
        PrintFamily(vFamily);

        //Ask the user to select a Person to remove.
        int iChoice = 0;
        std::cout << "Please enter the number of the user you would like to remove: ";
        std::cin >> iChoice;

        //Remove the User from the Family Vector.
        vFamily.erase(vFamily.begin() + iChoice - 1);

        //Ask the user if they would like to remove another user.
        std::string sChoice = "n";
        std::cout << "Would you like to remove another user? (y/n): ";
        std::cin >> sChoice;

        //If the user does not want to remove another user, stop the loop. If they do, continue the loop.
        if (sChoice == "n" || sChoice == "N"){
            std::cout << "\n";
            std::cout << "You will now be returned to the Family Management Menu." << std::endl;
            Confirm();
            bStop = true;
        }
    } while(!bStop);
}

//Allows the user to modify a Family Member in the Family Vector.
void ModifyUser(std::vector<User>&vFamily){
    bool bStop = false;

    do{
        //Clear the screen
        clearScreen();

        //Print out the Family Vector to the screen.
        PrintFamily(vFamily);

        //Ask the user to select a Person to modify.
        int iChoice = 0;
        std::cout << "Please make a Selection: ";
        std::cin >> iChoice;

        //If the user selects 0, return to the Family Management Menu.
        if (iChoice == 0) {
            std::cout << "\n";
            std::cout << "You will now be returned to the Family Management Menu." << std::endl;
            Confirm();
            bStop = true;
        }
        else{
            bool bStop2 = false;

            //Ask for what information the user would like to modify.
            std::cout << "What would you like to modify? (name/age/cancel): ";
            std::string sChoice;
            std::cin >> sChoice;

            do{
                //If the user wants to modify the name, ask for the new name.
                if (sChoice == "name" || sChoice == "Name") {
                    std::string sName;
                    std::cout << "Please enter the new name: ";
                    std::cin >> sName;
                    vFamily[iChoice - 1].SetName(sName);
                    bStop2 = true;
                }
                    //If the user wants to modify the age, ask for the new age.
                else if (sChoice == "age" || sChoice == "Age") {
                    int iAge = 0;
                    std::cout << "Please enter the new age: ";
                    std::cin >> iAge;
                    vFamily[iChoice - 1].SetAge(iAge);
                    bStop2 = true;
                }
                    //If the user wants to cancel, stop the loop.
                else if (sChoice == "cancel" || sChoice == "Cancel") {
                    std::cout << "\n";
                    std::cout << "You will now be returned to the Family Management Menu." << std::endl;
                    Confirm();
                    bStop2 = true;
                }
                    //If the user enters an invalid input, ask them to try again.
                else {
                    std::cout << "Please enter a valid option." << std::endl;
                }
            }
            while(!bStop2);
        }
    } while(!bStop);
}

//Checks if the Family is Eligible for the Discount.
bool FamilyDiscount(std::vector<User>&vFamily){
    int iUnder18 = 0;

    //If the Family Vector has Four Members, and two of them are under the age of 18, return true.
    if(vFamily.size() == 4){
        //Loop through the Family Vector.
        for(auto & Person : vFamily){
            //If the Person is under 18, increment the counter.
            if(Person.GetAge() < 18){
                iUnder18++;
            }
        }
        //If there are two Under 18s, and if Family Size is 4, return true.
        if(iUnder18 == 2){
            return true;
        }
        //If there are not two Under 18s, return false.
        else{
            return false;
        }
    }
    //If Family Size is not 4, return false.
    else{
        return false;
    }
}

//provides a menu for the user to select from to Manage the Family.
void ManageUsers(std::vector<User>&vFamily){
    bool bStop = false;
    int iChoice = 0;

    do {
        //Print the Family Management Menu and ask the user to make a selection.
        FamilyMenu();
        std::cin >> iChoice;

        //Switch statement to handle the user's selection.
        switch (iChoice) {
            case 1:
                AddUser(vFamily);
                break;
            case 2:
                DeleteUser(vFamily);
                break;
            case 3:
                ModifyUser(vFamily);
                break;
            case 4:
                bStop = true;
                break;
            default:
                std::cout << "Error: Please make a Selection.";
                break;

        }
    }while(!bStop);
};

//Prints the Location Management Menu.
void PrintLocations(std::vector<Holiday>&vHolidays){
    //Clear Input Buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Here are the locations we have available: " << std::endl;
    std::cout << "\n";

    //Print out the Holiday Vector to the screen.
    for(int i = 0; i < vHolidays.size(); i++) {
        std::cout << "Activity "<< i+1 << ": "<< std::endl;
        std::cout << "Location: " << ": " << vHolidays[i].GetLocation() << std::endl;
        std::cout << "Price (Per Person): " << ": " << vHolidays[i].GetCost() << std::endl;
        std::cout << "Minimum Travellers: " << ": " << vHolidays[i].GetMinimumTravellers() << std::endl;
        std::cout << "\n";

        //If the current location is the last one in the vector, print 0 to return to the main menu.
        if(i == vHolidays.size()-1) {
            std::cout << "0: Back" << std::endl;
        }
    }
}

//Prints the Activity Management Menu.
void PrintActivities(std::vector<Holiday>&vHolidays, std::vector<Activity>&vActivities, int iLocation){
    //Clear Input Buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    int iCount = 1;

    for(auto Activity : vActivities){
        std::vector<std::string> vAvailableLocations = Activity.GetAvailableLocations();

        //If the current activity is available in the current location, print it out.
        if(std::find(vAvailableLocations.begin(), vAvailableLocations.end(), vHolidays[iLocation].GetLocation()) != vAvailableLocations.end()){
            std::cout << "Activity "<< iCount << ": "<< std::endl;
            std::cout << Activity.GetActivity() << std::endl;
            std::cout << "Price (Per Person): " << Activity.GetCost() << std::endl;
            std::cout << "\n";

            //Iterates the counter.
            iCount++;
        }
    }
}

//Allows the user to choose a location.
int ChooseLocation(std::vector<Holiday>&vHolidays){
    //Clear the screen
    clearScreen();

    //Print the Holidays Vector to the screen.
    PrintLocations(vHolidays);

    //Ask the user to select a location.
    std::cout << "Please select a Holiday Location: ";
    int iChoice = 0;
    std::cin >> iChoice;

    //If the user selects 0, return to the Main Menu.
    if (iChoice == 0) {
        std::cout << "\n";
        std::cout << "You will now be returned to the Main Menu." << std::endl;
        Confirm();
    }
    else{
        //Returns the index of the Holiday Location in the Holiday Vector.
        return iChoice-1;
    }
}

//Allows the user to choose an activity.
int ChooseActivities(std::vector<Holiday>&vHolidays, std::vector<Activity>&vActivities, int iLocationIndex){
    clearScreen();

    PrintActivities(vHolidays, vActivities, iLocationIndex);

    std::cout << "Please make a Selection:";
    int iChoice = 0;
    std::cin >> iChoice;

    if (iChoice == 0) {
        std::cout << "\n";
        std::cout << "You will now be returned to the Main Menu." << std::endl;
        Confirm();
        return 0;
    }
    else{
        std::cout << "Would you like to add this activity to your trip? (y/n)";
        std::string sChoice;
        std::cin >> sChoice;

        //Returns the index of the Activity in the Activity Vector.
        return iChoice;
    }
}

//Allows the user to manage their holiday
void ManageHoliday(std::vector<Holiday>&vHolidays, std::vector<Activity>&vActivities, std::vector<User>&vFamily, std::vector<UserHoliday>&vUserHolidays){
    clearScreen();

    //If the Family Vector is empty, print an error message and return to the Main Menu.
    if(vFamily.empty()){
        std::cout << "You must add a family member before you can add a holiday." << std::endl;

        //Get the user to press enter to continue.
        Confirm();

        return;
    }

    //Print the Holiday Management Menu and ask the user to make a selection. Returns the index of the Holiday Location in the Holiday Vector.
    int iLocationIndex = ChooseLocation(vHolidays);

    //If the user selects -1(0 on their prompt), return to the Main Menu.
    if (iLocationIndex < 0){
        std::cout << "You will be returned to the main menu." << std::endl;
        return;
    }

    bool bStop = false;
    std::vector<int> vSelectedActivities;
    do{
        if (ChooseActivities(vHolidays, vActivities, iLocationIndex) != 0) {
            vSelectedActivities.push_back(ChooseActivities(vHolidays, vActivities, (iLocationIndex-1)));

            std::cout << "Would you like to add another activity to your trip? (y/n)";
            std::string sChoice;
            std::cin >> sChoice;

            if(sChoice == "n" || sChoice == "N"){
                //If the user does not want to add another activity, return to the holiday management menu.
                bStop = true;
            }
        }
        else{
            bStop = true;
        }

    }while(!bStop);
};

double CalculateCost(std::vector<Holiday>&vHolidays, std::vector<Activity>&vActivities, std::vector<User>&vFamily, std::vector<UserHoliday>&vUserHolidays){
    double totalCost= 0;

    //START HERE TOMORROW
    //START HERE TOMORROW
    //START HERE TOMORROW
    //START HERE TOMORROW
    //START HERE TOMORROW
    //START HERE TOMORROW
    //START HERE TOMORROW



    if (FamilyDiscount(vFamily)) {
        //10% Discount from totalCost if family is eligible for discount.
        totalCost = totalCost * 0.9;
    }

}

void UserConfirmation(){

};

void LoadReport(){

};

void Admin(){

};


int main() {
    //Creating Vectors to be used throughout the program.
    std::vector<Holiday>vHolidays;
    std::vector<Activity>vActivities;
    std::vector<User>vFamily;
    std::vector<UserHoliday>vUserHolidays;

    //Initialising the Vectors with Default Values.
    InitialiseHolidays(vHolidays);
    InitialiseActivities(vActivities);

    bool bStop = false;

    //Main Menu Loop.
    do{
        //Print the main menu.
        MainMenu();

        int iChoice = 0;
        std::cin >> iChoice;

        //Switch statement to handle the user's choice.
        switch (iChoice) {
            case 1:
                ManageUsers(vFamily);
                break;
            case 2:
                ManageHoliday(vHolidays,vActivities, vFamily, vUserHolidays);
                break;
            case 3:
                UserConfirmation();
                bStop = true;
                break;
            case 4:
                LoadReport();
                break;
            case 5:
                Admin();
                break;
            default:
                std::cout << "Error: Please make a Selection.";
                break;

        }
    } while(!bStop);
    return 0;
}
