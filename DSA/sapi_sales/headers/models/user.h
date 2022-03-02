//
// Created by Kriszta Oniga on 2/23/2022.
//

#ifndef DSA_USER_H
#define DSA_USER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "useful.h"
#include "errors.h"
#include "messages.h"
//Felhasznaloval kapcsolatos fuggvenyek deklaracioja
enum UserType{
    STUDENT,
    TEACHER
};

enum Gender{
    FEMALE,
    MALE,
};

enum Specialization{
    INFORMATICCS,
    COMPUTER_SCIENCE,
    AUTOMATION,
    TELECOMMUNICATION,
    MATHEMATICS_INFORMATICS,
    ENGINEERING,
};
typedef struct {
    int year;
    int month;
    int day;
}DATE;

typedef struct {
    unsigned int id;
    char name[50];
    enum UserType type;
    enum Gender gender;
    enum Specialization specialization;
    DATE date;
}User;

char* getUserType(enum UserType type);
char* getGender(enum Gender type);
char* getSpecialization(enum Specialization type);

void createUser(User** user);

void setUserData(User* user, char* name, enum UserType type, enum Gender gender, enum Specialization specialization, int year, int month, int day );
void printUser(User* user, char*);

void deleteUser(User** user);

#endif //DSA_USER_H
