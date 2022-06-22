#ifndef MAIN_CPP_USER_H
#define MAIN_CPP_USER_H

#include <string>

class User {
private:
    std::string name;
    int age;
public:
    std::string GetName();
    void SetName(std::string name);

    int GetAge();
    void SetAge(int age);

    bool Under18();

    User(std::string name, int age);
};

#endif //MAIN_CPP_USER_H
