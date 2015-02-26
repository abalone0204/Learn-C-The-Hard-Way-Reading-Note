#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


// Create a Person structure(Like the class in OO language)
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

// Resturn a pointer that pointed to a memory block 
// which has a Person struct inside
struct Person *Person_create(char *name, int age, int height, int weight)
{
    // Create a poninter name who and pointed it to a block contained Person struct
    // and use malloc to allocate a block which has the size of a Person
    // structure to it 
    struct Person *who = malloc(sizeof(struct Person));

    // Assert that who is a valid pointer
    assert(who != NULL);

    // strdup will return a pointer to it
    // Since in the structure Person it has char *name
    who->name = strdup(name);
    who->age = age;
    who->height = height;

    return who;
}

void Person_destroy(struct Person *who)
{
    assert(who != NULL);

    free(who->name);
    free(who);
}

void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge%d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}


int main(int argc, char *argv[]){
    // Make two people structures
    struct Person *joe = Person_create(
        "Joe Alex", 32, 64, 140);
    struct Person *frank = Person_create(
        "Frank Blank", 20, 72, 180);

    // Print them out and where they are in memory
    printf("Joe is at memory location: %p\n", joe);
    Person_print(joe);
    printf("Frank is at memory location: %p\n", frank);
    Person_print(frank);

    // Make everyone age 20 years and print them again
    printf("20 years later...\n");

    joe->age += 20;
    joe->height -=2;
    joe->weight +=40;
    Person_print(joe);

    frank->age += 20;
    frank->height -=2;
    frank->weight +=20;
    Person_print(frank);

    // destroy them
    Person_destroy(joe);
    Person_destroy(frank);

    // Create my own person
    struct Person *denny = Person_create(
        "Denny Ku", 23, 55, 174);
    printf("My own Person:\n");
    Person_print(denny);
    // Person_destroy(denny);



    return 0;
}
