#include <stdio.h>

int main(int argc, char *argv[]){
    int areas[] = {10, 12, 13, 14, 20};
    char name[] = "Zed";
    char full_name[] = {
        'Z', 'e', 'd',
        ' ', 'A', '.', ' ',
        'S', 'h', 'a', 'w', '\0'
    };

    printf("The size of an int: %ld\n", sizeof(int));
    printf("The size of areas(int[]): %ld\n", sizeof(areas));
    printf("The number of ints in areas: %ld\n", sizeof(areas)/sizeof(int));
    printf("The first of areas is %d, the second one is %d\n", areas[0], areas[1]);
    printf("The size of a char: %ld\n", sizeof(char));
    printf("The size of name(char[]): %ld\n", sizeof(name));
    printf("The size of full_name: %ld \n", sizeof(full_name));
    printf("The number of chars in full_name(char[]): %ld\n", sizeof(full_name)/sizeof(char));
    printf("name = \"%s\" and full_name =\" %s\"\n", name, full_name);
    // Extra credit
    areas[0] = 100;
    name[0] = areas[0];
    printf("=====Extra Credit======\n");
    printf("replace name[0] to areas[0], name: %s\n", name);
    return 0;
}
