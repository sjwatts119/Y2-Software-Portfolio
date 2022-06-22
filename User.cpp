#include "User.h"

std::string User::GetName(){
    return this->name;
}
void User::SetName(std::string name) {
    this->name = name;
}
int User::GetAge(){
    return this->age;
}
void User::SetAge(int age) {
    this->age = age;
}
//If user is under 18, True is returned, if not, returns false.
bool User::Under18() {
    return this->age < 18;
}
User::User(std::string name, int age) {
    this->name = name;
    this->age = age;
}