#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// 2023-03-07
// -std=c99
// 0.5 KORT om struktar (repetition video)
// input, ->, .
// &struct
// copy! Nice :)
// 1. struct + typedef vs struct
// 2. titta på en struct i runtime struct tm (time)
// 3. Två övningar på structs
// 4. Kodartisdag!        
//
typedef struct {
    int BirthYear;
    char FirstName[50];
    char LastName[50];
    char City[50];
} Employee;

typedef struct {
    Employee *employees;
    int antal;
} State;


void InputEmployee(Employee *p){
    printf("Ny employee:\n");
    printf("First name:");
    scanf(" %s", p->FirstName);
    printf("Last name:");
    scanf(" %s", p->LastName);
    printf("City:");
    scanf(" %s", p->City);
    printf("Birth year:");
    scanf(" %d", &p->BirthYear);
}

// allokera malloc realloc
//          calloc = malloc + memset och 0-ställs alla bytes
//          calloc

void CreateEmployee(State *state){
    //state->antal = state->antal + 1; 
    state->antal++;
    if(state->antal == 1)
        state->employees = (Employee *)malloc(1 * sizeof(Employee));
    else
        state->employees = (Employee *)realloc(state->employees, state->antal * sizeof(Employee));
    InputEmployee(&state->employees[state->antal-1]);
} 





void PrintEmployee(const Employee *p){
    printf("Employee information:\n");
    printf("%s %s\n",p->FirstName, p->LastName);
    printf("%s Birth year:%d\n",p->City, p->BirthYear);
}

void ListAllEmployees(const State *state){
    printf("Listing all employes\n*******************\n");
    for(int i = 0; i < state->antal;i++)
    {
        // Employee *p = state->employees;
        // Employee *toPrint = &p[i];
        // PrintEmployee(toPrint);

        PrintEmployee(&state->employees[i]);
    }
        
} 


// i funktionen där du lägger in anställda och använder malloc och realloc 
// på videon så använde du inte free() i slutet

// COPY BY VALUE - när vi anropar en fuinktion så kommer ALLTID värdet i orginiallådan
// att KOPIERAS in i en NY LÅDA inuti funktionen
int add(int i, int j){
    int r = i + j;
    i = i + 1; //
    return r;
}

// pekare  = en address  som heter i
// som har värdet 1000

// int 
// int *



int add2(int *i, int *j){
    // i = 1000
    //j=1004
    // *i = vad finns på address 1000 -> 12
    // *j = vad finns på addtess 1004 -> 13

    
    int r = *i + *j;
    r = r + 12;
    *i += *i + 1; //
    return r;
}

int main(){
    int i=12; // Leker att i ligger på address 1000 -1003
    int j = 13; // Leker att i ligger på address 1004 -1007
    int r = add(i,j);
    printf("%d",i);

    int r = add2(&i,&j);//Resultatet av uttrycket &i ? 1000
    printf("%d",i);


    scanf("%d", &i);



    State state = {NULL,0};

    while(1){
        printf("1. Skapa employee\n");
        printf("2. Lista alla\n");
        printf("3. Avsluta\n");
        printf("Action:");
        int sel;
        scanf(" %d", &sel);
        if(sel == 1)
            CreateEmployee(&state);
        else if(sel == 2)
            ListAllEmployees(&state);
        else if(sel == 3)
            break;

    }
  return 0;
}


