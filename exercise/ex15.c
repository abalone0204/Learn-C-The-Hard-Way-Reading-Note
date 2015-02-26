#include <stdio.h>

int main(int argc, char *argv[]){
    int ages[] = {23, 43, 12, 89, 2};

    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    int count = sizeof(ages)/sizeof(int);
    int i = 0;

    // First, normal assignment

    for( i = count-1; i >= 0; i--) {
        printf("%s has %d years alive\n", 
            names[i], ages[i]);
    }
    printf("---\n");

    // Second, setup the pointers to the start of the arrays
    int *cur_age = ages+count-1;
    char **cur_name = names+count-1;


    for( i = 0; i < count; i++) {
        printf("%s is %d years old\n", 
            *(cur_name-i), *(cur_age-i));
    }
    printf("---\n");

    // Third, pointers are just arrays
    cur_age -= count-1;
    cur_name -= count-1;
    for(i = 0; i < count; i++) {
        printf("%s is %d years old\n", 
            cur_name[count-1-i], cur_age[count-1-i]);   
    }
    printf("---\n");
    // Fourth, stupid and complex way
    for(cur_age = ages+count-1, cur_name = names+count-1;
        cur_age >= ages;
        cur_name--, cur_age--)
    {
        printf("%s lived %d years so far\n", 
            *cur_name, *cur_age);
    }
    printf("----\n");
    int arr[] = {1, 2, 3};
    int *test = arr;
    for(i = 0; i <3; i++) {
        printf("test array[%d] : %d\n", i, test[i]);
    }
    printf("-----\n");
    char *text = "Text";
    char **text_ptr = &text;
    printf("test text: %s\n", text);
    printf("another text ptr: %s\n", *text_ptr);
    return 0;
}
