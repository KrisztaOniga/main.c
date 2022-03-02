//
// Created by Kriszta Oniga on 2/23/2022.
//
#include "user.h"
#include "messages.h"
#include "errors.h"
//Fuggvenyek definicioja

char* getUserType(enum UserType type){
    switch (type) {
        case STUDENT:
            return "Student";
        case TEACHER:
            return "Teacher";
        default:
            return "Undefined";
    }
}

char* getGender(enum Gender type){
    switch (type) {
        case MALE:
            return "Male";
        case FEMALE:
            return "Female";
        default:
            return "Undefined";
    }
}

char* getSpecialization(enum Specialization type){
    switch(type){
        case INFORMATICCS:
            return "Informatics";
        case COMPUTER_SCIENCE:
            return "Computer science";
        case AUTOMATION:
            return "Automation";
        case TELECOMMUNICATION:
            return "Telecommunication";
        case MATHEMATICS_INFORMATICS:
            return "Mathematics and Informatics";
        case ENGINEERING:
            return "Engineering";
        default:
            return "Undefined";
    }
}
void createUser(User** user) {
    *user = (User *) malloc(sizeof(User));
    if(!(*user)){
        printErrorMessage(MEMORY_ALLOCATION);
    }
}

void setUserData(User *user, char *name, enum UserType type, enum Gender gender, enum Specialization specialization,
        int year, int month, int day) {
    user->id = ++numberOfUsers;
    user->specialization = specialization;
    user->date.year = year;
    user->date.month = month;
    user->date.day = day;
    user->gender = gender;
    user->type = type;
    strcpy(user->name, name);
}

void printUser(User *user, char* destination ) {
    printf("%s details:\n"
           "\t - ID: %i\n"
           "\t - TYPE: %s\n"
           "\t - GENDER: %s\n"
           "\t - SPECIALIZATION: %s\n"
           "\t - BIRTH YEAR: %i\n"
           "\t - BIRTH MONTH: %i\n"
           "\t - BIRTH DAY: %i\n",
           user->name, user->id, getUserType(user->type), getGender(user->gender), getSpecialization(user->specialization),
           user-> date.year, user -> date.month, user -> date.day);
}

void deleteUser(User **user) {
    free(*user);
}