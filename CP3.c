#include <stdio.h>
#include <conio.h>
#include <math.h>

char leap_year(short y);
char check_calendar(short y, short m, short d);
short n_choice(short y, short m);
char quit();

int main(){

    short year = 0, month = 0, day = 0, date = 0, n = 0;
    char check = 0;

    do{
        do{
            printf("Enter the day of the month (1-31): ");
            if (scanf("%d%c", &date, &check) != 2 || check != '\n'){
                printf("Invalid input!\n");
                check = 0;
            }
            else if (date < 1 || date > 31){
                printf("The day should be between 1 and 31!\n");
                check = 0;
            }
            fflush(stdin);
        }while(!check);

        do{
            printf("Enter the month (1-12): ");
            if (scanf("%d%c", &month, &check) != 2 || check != '\n'){
                printf("Invalid input!\n");
                check = 0;
            }
            else if (month < 1 || month > 12){
                printf("The month should be between 1 and 12!\n");
                check = 0;
            }
            fflush(stdin);
        }while(!check);

        do{
            printf("Enter the year (1900-2099): ");
            if (scanf("%d%c", &year, &check) != 2 || check != '\n'){
                printf("Invalid input!\n");
                check = 0;
            }
            else if (year < 1900 || year > 2099){
                printf("The year should be between 1900 and 2099!\n");
                check = 0;
            }
            fflush(stdin);
        }while(!check);

        if (!check_calendar(year, month, date)){
            printf("\nThe day does't exist!\n");
        }
        else{
            n = n_choice(year, month);

            day = (int)(floor(year * 365.25) + floor(month * 30.56) + date + n) % 7;

            printf("\n%02d/%02d/%d - ", date, month, year);

            switch (day)
            {
            case 0:
                printf("It's Monday!\n");
                break;

            case 1:
                printf("It's Tuesday!\n");
                break;

            case 2:
                printf("It's Wednesday!\n");
                break;

            case 3:
                printf("It's Thursday!\n");
                break;

            case 4:
                printf("It's Friday!\n");
                break;

            case 5:
                printf("It's Saturday!\n");
                break;

            case 6:
                printf("It's Sunday!\n");
                break;
            }
        }
    }while(quit());

    return 0;
}

char leap_year(short y){
    if ((y % 100 != 0 && y % 4 == 0) || (y % 100 == 0 && y % 400 == 0)){
        return 1;
    }
    else{
        return 0;
    }
}

char check_calendar(short y, short m, short d){
    if (m == 2){
        if (leap_year(y)){
            if (d > 29){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if (d > 28){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if (m < 8){
        if ((m % 2 == 0 && d > 30) || d > 31){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        if ((m % 2 == 1 && d > 30) || d > 31){
            return 0;
        }
        else{
            return 1;
        }
    }
}

short n_choice(short y, short m){

    if (leap_year(y) && m < 3){
        return 1;
    }
    else if (m < 3){
        return 2;
    }
    else{
        return 0;
    }
}

char quit(){

    printf("\nCheck another day (Any key / esc)...\n");
    
    if (getch() == 27){
        return 0;
    }
    else{
        printf("\n");
        return 1;
    }
}