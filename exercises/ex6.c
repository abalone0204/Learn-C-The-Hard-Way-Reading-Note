#include <stdio.h>

int main(int argc, char *argv[]){
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.56;
    char initial = 'A';
    char first_name[] = "Denny";
    char last_name[] = "Ku";

    printf("You are %d miles away\n", distance);
    printf("Hex: You are %x miles away\n", distance);
    printf("Octol: You are %o miles away\n", distance);

    printf("You are %f levels of power \n", power);
    printf("You have %f awesome super power\n", super_power);
    printf("I have a first name %s\n", first_name);
    printf("I have a last name %s\n", last_name);
    printf("Initial: %c\n", initial);
    return 0;
}
