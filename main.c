#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

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
    float MonthlySalary;
} Employee;

// struct Employee2{
//     int BirthYear;
//     char FirstName[50];
//     char LastName[50];
//     char City[50];
//     float MonthlySalary;
// };

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




void PrintEmployee(const Employee *p){
    printf("Student information:\n");
    printf("%s %s\n",p->FirstName, p->LastName);
    printf("%s Birth year:%d\n",p->City, p->BirthYear);
}



int main(){


    // -std=c99
    // return pekare!!! what???
    // Handledning - Yuri först

    int i;
    scanf(" %d", &i);
    Employee employees[i];



    //long long tieden;
    struct tm *timinfo;

    time_t tid;
    time(&tid);
    timinfo = localtime(&tid);
    printf("Year%d", timinfo->tm_year+1900 );


    

    return 0;
}


