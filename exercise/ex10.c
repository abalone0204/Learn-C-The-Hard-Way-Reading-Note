#include <stdio.h>

int main(int argc, char *argv[]){
    int i = 0;
    // why skip argv[0]?
    char *states[]={
        "California", "Oregon",
        "Washington", "Texas"
    };

    for(i = 1; i< argc; i++){
        printf("arg %d: %s\n", i, argv[i]);
    }

    // That's the answer
    printf("first argv is: %s\n", argv[0]);

    int num_states = 4;
    states[1] = NULL;
    for(i=0; i < num_states; i++){
        printf("state %d: %s\n", i, states[i]);
    }
    return 0;
}
