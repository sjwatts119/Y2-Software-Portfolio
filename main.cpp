#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

#include "Holiday.h"
#include "Activity.h"
#include "User.h"
#include "UserHoliday.h"

//Clears the screen
void ClearScreen(){
    //Clears the screen
    std::cout << std::string(50, '\n');
}

//Prompts the user to press enter to continue
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
    ClearScreen();

    //Prints the Main Menu
    std::cout << " Please choose from the following options:" << std::endl << std::endl;
    std::cout << "1. Manage your Family" << std::endl;
    std::cout << "2. Add Holiday" << std::endl;
    std::cout << "3. View Booked Holidays" << std::endl;
    std::cout << "4. Cancel a Booking" << std::endl;
    std::cout << "5. Load Report" << std::endl;
    std::cout << "6. Login to Admin Area" << std::endl;
    std::cout << "0. Quit" << std::endl << std::endl;
    std::cout << "Please make a Selection: ";

}

//Prints the Manage Family Menu to the screen.
void FamilyMenu(){
    ClearScreen();

    //Prints the Family Menu
    std::cout << "You are now managing your Family." << std::endl;

    std::cout << " Please choose from the following options:" << std::endl << std::endl;
    std::cout << "1. Add a Family Member" << std::endl;
    std::cout << "2. Remove a Family Member" << std::endl;
    std::cout << "3. Modify a Family Member" << std::endl;
    std::cout << "0. Back" << std::endl << std::endl;
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
        ClearScreen();

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
            ClearScreen();
            std::cout << std::endl;
            std::cout << "You have no family members to remove." << std::endl;
            Confirm();
            return;
        }
        //Clear the screen
        ClearScreen();

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

    //If Family Vector is Empty, the user will be returned to the Family Management Menu.
    if(vFamily.empty()) {
        ClearScreen();
        std::cout << std::endl;
        std::cout << "You have no family members to Modify." << std::endl;
        Confirm();
        return;
    }

    do{
        //Clear the screen
        ClearScreen();

        //Print out the Family Vector to the screen.
        PrintFamily(vFamily);

        //Ask the user to select a Person to modify.
        int iChoice = 0;
        std::cout << "Please make a Selection: ";
        std::cin >> iChoice;

        //If the user selects 0, return to the Family Management Menu.
        if (iChoice == 0) {
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

//Provides a menu for the user to select from to Manage the Family.
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
            case 0:
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
        std::cout << "Location #"<< i+1 << ": "<< std::endl;
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
            std::cout << "Activity #"<< iCount << ": "<< std::endl;
            std::cout << Activity.GetActivity() << std::endl;
            std::cout << "Price (Per Person): " << Activity.GetCost() << std::endl;
            std::cout << "\n";

            //Iterates the counter.
            iCount++;
        }
    }
    std::cout << "0: Back" << std::endl;
}

//Allows the user to choose a location.
int ChooseLocation(std::vector<Holiday>&vHolidays, std::vector <User>&vFamily){
    do{
        //Clear the screen
        ClearScreen();

        //Print the Holidays Vector to the screen.
        PrintLocations(vHolidays);

        //Ask the user to select a location.
        std::cout << "Please select a Holiday Location: ";
        int iChoice = 0;
        std::cin >> iChoice;

        //If the user selects 0, return to the Main Menu.
        if (iChoice == 0) {
            //Returning -1 to handle user wanting to return the main menu.
            return -1;
        }
        else if (vHolidays[iChoice-1].GetMinimumTravellers() > vFamily.size()) {
            std::cout << "Sorry, this location is not available for your group size." << std::endl;

            std::string sChoice;
            bool bStop = false;
            do {
                std::cout << "Would you like to try another location? (y/n): ";
                std::cin >> sChoice;

                if (sChoice == "y" || sChoice == "Y") {
                    //Loop until the user selects a valid location or returns to the menu.
                    bStop = true;
                } else if (sChoice == "n" || sChoice == "N") {
                    //Returning -1 to handle user wanting to return the main menu.
                    return -1;
                } else {
                    std::cout << "Please enter a valid option." << std::endl;
                }
            } while (!bStop);
        }
        else{
            //Returns the index of the Holiday Location in the Holiday Vector.
            return iChoice-1;
        }
    }while(true);
}

//Allows the user to choose an activity.
int ChooseActivities(std::vector<Holiday>&vHolidays, std::vector<Activity>&vActivities, int iLocationIndex){
    ClearScreen();

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

void PreviewCost(std::vector<Holiday>&vHolidays, std::vector<Activity>&vActivities, std::vector<User>&vFamily, int &iLocationIndex, std::vector<int>&vActivityIndexes){
    int iAdults = 0;
    int iChildren = 0;

    //Iterates through the vector of users and counts the number of adults and children.
    for(auto User : vFamily){
        if(User.GetAge() >= 18){ iAdults++; }
        else{ iChildren++; }
    }

    //Multiples location cost by the number of adults and children.
    double dLocationCost = (iAdults+iChildren) * vHolidays[iLocationIndex].GetCost();

    //Iterates through the vector of indexes and adds the cost of the activities to the total cost.
    double dActivityCost = 0;
    for(auto iIndex : vActivityIndexes){
        dActivityCost = (iChildren + iAdults) * vActivities[iIndex].GetCost();
    }

    //Calculates the total cost of the trip without VAT or Discount being applied.
    double totalCost = dLocationCost + dActivityCost;

    //Add 20% to the total cost for VAT.
    double totalTaxedCost = totalCost * 1.2;

    double dDiscount = 0;
    if (FamilyDiscount(vFamily)) {
        //10% Discount from totalCost if family is eligible for discount.
        totalCost = totalCost * 0.9;
        dDiscount = totalCost * 0.1;
    }

    //Prints the total cost Summary of the trip with breakdowns of the costs.
    ClearScreen();
    std::cout << "Here is a Cost Summary of your Holiday:" << std::endl;
    std::cout << "Location Cost: " << dLocationCost << std::endl;
    std::cout << "Activity Cost: " << dActivityCost << std::endl;
    std::cout << "VAT: " << totalTaxedCost - totalCost << std::endl;
    //If there is a discount, print it.
    if (dDiscount != 0) {
        std::cout << "Family Discount: " << dDiscount << std::endl;
    }
    std::cout << "Total Cost: " << totalCost << std::endl;
}

//Allows the user to manage the Current holiday
void AddHoliday(std::vector<Holiday>&vHolidays, std::vector<Activity>&vActivities, std::vector<User>&vFamily, std::vector<UserHoliday>&vUserHolidays){
    ClearScreen();

    //If the Family Vector is empty, print an error message and return to the Main Menu.
    if(vFamily.empty()){
        std::cout << "You must add a family member before you can add a Holiday." << std::endl;

        //Get the user to press enter to continue.
        Confirm();

        return;
    }

    //Prompting the user to select a location.
    std::cout << "Here are the Holiday Locations we have Available: " << std::endl;

    //Print the Holiday Management Menu and ask the user to make a selection. Returns the index of the Holiday Location in the Holiday Vector + 1, we need to subtract one to get the real index.
    int iLocationIndex = ChooseLocation(vHolidays, vFamily);

    //If function returns -1, the user has selected to return to the main menu, or couldn't add a location due to group size, so the function returns.
    if (iLocationIndex == -1) {
        return;
    }
    else{
        bool bStop = false;
        //Vector for storing the Activities chosen by the user.
        std::vector<int> vSelectedActivitiesIndexes;
        std::vector<Activity> vSelectedActivities;

        std::cout << "Now you have selected a location, please select at least one Activity: " << std::endl;
        Confirm();

        //Loops through all activities, adding the user's selected ones to the vector.
        for (auto vSelectedActivityIndex : vSelectedActivitiesIndexes) {
            vSelectedActivities.push_back(vActivities[vSelectedActivityIndex]);
        }

        do{
            //If user selects anything other than 0, they want to add an activity.
            if (ChooseActivities(vHolidays, vActivities, iLocationIndex) != 0) {
                vSelectedActivitiesIndexes.push_back(ChooseActivities(vHolidays, vActivities, (iLocationIndex-1)));

                std::cout << "Would you like to add another activity to your trip? (y/n)";
                std::string sChoice;
                std::cin >> sChoice;

                if(sChoice == "n" || sChoice == "N"){

                    bool bStop2 = false;

                    do{
                        //Prints the total Cost breakdown of the Holiday.
                        PreviewCost(vHolidays, vActivities, vFamily, iLocationIndex, vSelectedActivitiesIndexes);

                        //Ask the user if they would like to confirm the trip.
                        std::cout << "Would you like to Confirm this Holiday Booking?: " << std::endl;
                        std::cout << "(y/n): ";
                        std::string sConfirm;
                        std::cin >> sConfirm;

                        if(sConfirm == "y" || sConfirm == "Y"){
                            //Making a new vector from the user's chosen location.
                            std::vector<Holiday> vSelectedLocation;
                            vSelectedLocation.push_back(vHolidays[iLocationIndex]);

                            //Adds the Holiday to the UserHoliday Vector.
                            vUserHolidays.emplace_back(UserHoliday(vSelectedLocation, vSelectedActivities, vFamily));
                            std::cout << "Holiday Booking Confirmed! You will now be returned to the Holiday Management Menu." << std::endl;
                            Confirm();
                            bStop2 = true;
                        }
                        else if(sConfirm == "n" || sConfirm == "N"){
                            std::cout << "Holiday Booking Cancelled! You will now be returned to the Holiday Management Menu." << std::endl;
                            Confirm();
                            bStop2 = true;
                        }
                        else{
                            std::cout << "Please enter a valid option." << std::endl;
                        }
                    }while(!bStop2);

                    bStop = true;
                }
            }
            else{
                bStop = true;
            }

        }while(!bStop);
    }
};

void ViewBookings(std::vector<Holiday>&vHolidays, std::vector<Activity>&vActivities, std::vector<User>&vFamily, std::vector<UserHoliday>&vUserHolidays){
    ClearScreen();

    //If the UserHoliday Vector is empty, print an error message and return to the Main Menu.
    if(vUserHolidays.empty()){
        std::cout << "You have no bookings to view." << std::endl;

        //Get the user to press enter to continue.
        Confirm();

        return;
    }

    std::cout << "Here are your Current Bookings: " << std::endl;

    int iCount = 1;
    //Iterates through the UserHoliday Vector and prints the details of each of the user's Holidays.
    for(auto UserHoliday : vUserHolidays){
        //New Line
        std::cout << std::endl;

        //Shows what number booking it is.
        std::cout << "Booking " << iCount << ": " << std::endl;
        std::cout << std::endl;

        //Shows the location of the holiday.
        std::cout << "Holiday Location: " << UserHoliday.GetLocation() << std::endl;
        std::cout << "Activities: " << std::endl;

        //Shows the activities of the holiday.
        for(int iIndex = 0; iIndex < UserHoliday.GetActivities().size(); iIndex++){
            std::cout << "Activity: " << UserHoliday.GetActivities()[iIndex] << std::endl;
            std::cout << "Activity Price: " << UserHoliday.GetActivitiesPrice()[iIndex] << std::endl;
        }

        //Shows the family members of the holiday.
        std::cout << "Family Members: " << std::endl;
        for(auto FamilyMember : UserHoliday.GetFamily()){
            std::cout << FamilyMember.GetName() << std::endl;
        }

        //Iterates the count.
        iCount++;
    }

}

void LoadReport(){

};

void Admin(){

};

void CancelBooking(std::vector<Holiday>&vHolidays, std::vector<Activity>&vActivities, std::vector<User>&vFamily, std::vector<UserHoliday>&vUserHolidays){
    ClearScreen();

    //If the UserHoliday Vector is empty, print an error message and return to the Main Menu.
    if(vUserHolidays.empty()){
        std::cout << "You have no bookings to cancel." << std::endl;

        //Get the user to press enter to continue.
        Confirm();

        return;
    }
    else{
        bool bStop = false;
        do{
            //Prints the current bookings.
            ViewBookings(vHolidays, vActivities, vFamily, vUserHolidays);

            //Asks the user which booking they would like to cancel.
            std::cout << "Please enter the number of the booking you would like to cancel: ";
            int iBookingNumber;
            std::cin >> iBookingNumber;

            if(iBookingNumber == 0){
                //The user wants to return to the main menu.
                bStop = true;
            }
            else if(iBookingNumber > vUserHolidays.size() || iBookingNumber < 0){
                //If the user enters a number that is not in the range of the UserHoliday Vector, print an error message and return to the Main Menu.
                std::cout << "Please enter a valid booking number." << std::endl;

                //Get the user to press enter to continue.
                Confirm();

                return;
            }
            else{
                //Removes the UserHoliday from the UserHoliday Vector.
                vUserHolidays.erase(vUserHolidays.begin() + iBookingNumber - 1);
                std::cout << "Booking Cancelled!" << std::endl;

                //Get the user to press enter to continue.
                Confirm();
            }
        }while (!bStop);
    }
}


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
                AddHoliday(vHolidays,vActivities, vFamily, vUserHolidays);

                std::cout << "Here are the Holidays you have booked:" << std::endl;

                for (auto vUserHoliday : vUserHolidays) {
                    std::cout << "Location: " << vUserHoliday.GetLocation() << std::endl;

                    for(int i = 0; i <= vUserHoliday.GetActivities().size(); i++){
                        std::cout << "Activity: " << vUserHoliday.GetActivities()[i] << std::endl;
                        std::cout << "Activity Cost: " << vUserHoliday.GetActivitiesPrice()[i] << std::endl;
                    }
                }

                break;
            case 3:
                ViewBookings(vHolidays, vActivities, vFamily, vUserHolidays);
                break;
            case 4:
                CancelBooking(vHolidays, vActivities, vFamily, vUserHolidays);
            case 5:
                LoadReport();
                break;
            case 6:
                Admin();
                break;
            case 0:
                bStop = true;
                break;
            default:
                std::cout << "Error: Please make a Selection.";
                break;

        }
    } while(!bStop);
    return 0;
}
