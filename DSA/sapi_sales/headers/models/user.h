//
// Created by Kriszta Oniga on 2/23/2022.
//

#ifndef DSA_USER_H
#define DSA_USER_H

#include "useful.h"
#include "product.h"
#include "product_array.h"

enum UserType{
    TEACHER,
    STUDENT
};

enum Gender {
    MALE,
    FEMALE
};

enum Specialization {
    INFORMATICS,
    COMPUTER_SCIENCE,
    DEPARTMENT_OF_MATHEMATICS_AND_INFORMATICS,
    AUTOMATION,
    TELECOMMUNICATION,
    MATHEMATICS_INFORMATICS,
    ENGINEERING
};

typedef struct {
    unsigned int year;
    unsigned int month;
    unsigned int day;
}BirthDate;

typedef struct {
    unsigned int id;
    char name[50];
    char *pName;
    enum UserType type;
    enum Gender gender;
    BirthDate birthDate;
    enum Specialization specialization;
    ProductArray *myProducts;
}User;

char *getUserType(enum UserType type);

char *getGender(enum Gender type);

char *getSpecialization(enum Specialization type);

void createUser( User ** user);

void setUsersData(
        User * user,
        char *name,
        enum UserType type,
        enum Gender gender,
        enum Specialization specialization,
        BirthDate birthDate
);

void printUser(User *user, char *destination);

void deleteUser(User **user);

void addNewProductToUser(User *user, Product *newProduct, int position);

void printMyProducts(User *user, char *destination);

void readUserProducts(User* user);

#endif //DSA_USER_H
