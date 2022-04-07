//
// Created by Kriszta Oniga on 2/23/2022.
//
#include "user.h"
#include "messages.h"
#include "errors.h"
#include "product.h"

//Fuggvenyek definicioja

char* getUserType(enum UserType type) {
    switch (type) {
        case STUDENT:
            return "Student";
        case TEACHER:
            return "Teacher";
        default:
            return "Undefined";
    }
}

char *getGender(enum Gender type) {
    switch (type) {
        case MALE:
            return "Male";
        case FEMALE:
            return "Female";
        default:
            return "Undefined";
    }
}

char *getSpecialization(enum Specialization type) {
    switch (type) {
        case INFORMATICS:
            return "Informatic";
        case COMPUTER_SCIENCE:
            return "Computer scientist";
        case DEPARTMENT_OF_MATHEMATICS_AND_INFORMATICS:
            return "Department of mathematics and informatics";
        case AUTOMATION :
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

void createUser(User **user) {
    *user = (malloc(sizeof (User)));
    if(!(*user)){
        printErrorMessage(MEMORY_ALLOCATION);
    }
    (*user)->id = ++numberOfUsers;
    createProductArray(&(*user)->myProducts, MAX_PRODUCTS);
}

void setUsersData(
        User * user,
        char *name,
        enum UserType type,
        enum Gender gender,
        enum Specialization specialization,
        BirthDate birthDate) {
    if (!user) {
        printErrorMessage(NULL_POINTER_EXCEPTION);
    }
    user->specialization = specialization;
    user->birthDate = birthDate;
    user->gender = gender;
    user->type = type;
    strcpy(user->name, name);
}

void printUser(User *user, char *destination) {
    if(!user) {
        printErrorMessage(NULL_POINTER_EXCEPTION);
    }
    freopen(destination, "w", stdout);
    printf("\n\t%s details: "
           "\n\t\t - ID: %i"
           "\n\t\t - Type: %s "
           "\n\t\t - Gender: %s"
           "\n\t\t - Specialization: %s "
           "\n\t\t - Birth date: %i.%i.%i \n",
           user->name,
           user->id,
           getUserType(user->type),
           getGender(user->gender),
           getSpecialization(user->specialization),
           user->birthDate.year, user->birthDate.month, user->birthDate.day);
    printMyProducts(user, destination);
    printf("\n");
    freopen("CON", "w", stdout);
}

void deleteUser(User **user){
    if(*user != NULL){
        deleteProductArray(&(*user)->myProducts);
        free(*user);
        *user = NULL;
        printDeletedMessage(USER);
    }
}


void addNewProductToUser(User *user, Product *newProduct, int position) {
    if(!addNewProduct(user->myProducts, newProduct, position)){
        printErrorMessage(ADD_PRODUCT_ERROR);
    }
}

void printMyProducts(User *user, char *destination) {
    printf("\n\tPRODUCTS:\n\n");
    for (int i = 0; i < user->myProducts->maxProducts; ++i) {
        if(user->myProducts->products[i] != NULL)
            printProduct(user->myProducts->products[i], destination);
    }
}

void readUserProducts(User *user){
    int nrOfProducts;
    scanf("%i\n", &nrOfProducts);
    for (int i = 0; i < nrOfProducts; ++i) {
        Product  *newProduct;
        createProduct(&newProduct);
        scanf("%[^\n]"
              "%i"
              "%i\n",
              newProduct->name,
              &newProduct->type,
              &newProduct->amount);
        addNewProductToUser(user, newProduct, i);
    }
}

