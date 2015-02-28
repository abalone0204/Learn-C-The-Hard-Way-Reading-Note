#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex19.h"

int Monster_attack(void *self, int damage)
{
    Monster *monster = self;

    printf("You attack %s!\n", monster->_(description));

    monster->hit_points -= damage;

    if(monster->hit_points > 0) {
        printf("It's still alive.\n");
        return 0;
    } else {
        printf("It is dead!\n");
        return 1;
    }
}

int Monster_init(void *self)
{
    Monster *monster = self;
    monster->hit_points = 10;
    return 1;
}

// Simillar to the way using struct, check object.h

Object MonsterProto = {
    .init = Monster_init,
    .attack = Monster_attack;
};

void *Room_move(void *self, Direction direction)
{
    Room *room = self;
    Room *next = NULL;

    if(direction == NORTH && room->north) {
        printf("You go north, into: \n");
        next = room->north;
    } else if(direction == EAST && room->east) {
        printf("You go east, into: \n");
        next = room->east;
    } else if(direction == WEST && room->west) {
        printf("You go west, into: \n");
        next = room->west;
    } else if(direction == SOUTH && room->south){
        printf("You go south, into: \n");
        next = room->south;
    } else {
        printf("You can't go that direction.");
        next = NULL;
    }
    return next;
}

int Room_attack(void *self, int damage)
{
    Room *room = self;
    Monster *monster = room->bad_guy;

    if(monster) {
        monster->_(attack)(monster, damage);
        return 1;
    } else {
        printf("You flail in the air at nothing. Idiot!\n", );
        return 0;
    }
}

Object RoomProto = {
    .move = Room_move,
    .attack = Room_attack;
};

void *Map_move(void *self, Direction direction)
{
    Map *map = self;
    Room *location = map->location;
    Room *next = NULL;

    next = location->_(move)(location, direction);
    if(next) {
        map->location = next;
    }

    return next;
}

int Map_attack(void *self, int damage)
{
    Map *map = self;
    Room *location = map->location;
    // This line tell the player that they can't attack Map(or location wheter you prefer)
    return location->_(attack)(location, damage);
}

int Map_init(void *self)
{
    Map *map = self;

    // make some rooms for a small map
    // Remember NEW, the macro we define in object.h?
    Room *hall = NEW(Room, "The great Hall");
    Room *throne = NEW(Room, "The throne room");
    Room arena = NEW(Room, )
}
Object MapProto = {
    .init = Map_init,
    .attack = Map_attack,
    .move = Map_move;
};

int process_input(Map *game)
{
    printf("\n> ");

    
}

int main(int argc, char *argv[]){
    
    return 0;
}
