#include <stdio.h>

int main(int argc, char *argv[]){
    int i = 0;
    if(argc == 1){
        printf("You only have one arguments, you suck\n");
    } else if(argc > 1 && argc < 4){
        printf("Here is you argument:\n");
        for(i = 0; i < argc; i++){
            printf("argv[%d]: %s\n", i, argv[i]);
        }
    } else {
        printf("You have too many arguments, you suck\n");
    }
    return 0;
}
