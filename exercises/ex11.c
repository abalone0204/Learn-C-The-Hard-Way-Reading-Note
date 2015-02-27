#include <stdio.h>

int main(int argc, char *argv[]){
    int i = argc;
    while(i > 0) {
        printf("arg %d: %s\n", i-1, argv[i-1]);
        i--;
    }
    char *countries[] = {
        "Taipei", "Taichung",
        "KS", "Tainan"
    };

    int country_num = 4;
    i = country_num;
    while(i > 0){
        printf("countries[%d] : %s\n", i-1, countries[i-1]);
        i--;
    }

    // Extra copy loop
    i =0;
    while(1){
        countries[i] = argv[i];
        i++;
    }

    i=0;
    while(i<argc){
        printf("copy loop %d: %s\n", i, countries[i]);
        i++;
    }

    return 0;
}
