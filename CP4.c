#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>

char choise();
short nums_size(double *arr, short s);
char sort(double *arr, short s);
char quit();

const long long int DEC_RAND = 1e14; 

int main(){

    srand(time(NULL));

    long long int range = 0, rand_min = 0, rand_max = 0;
    short dec = 0, nums = 0, size = 0, order = 0;
    char check = 0;

    do{
        do{ // Введення розміру масиву
                printf("Enter the size of the array (2-100): ");
                if (scanf("%d%c", &size, &check) != 2 || check != '\n'){
                    printf("Invalid input!\n");
                    check = 0;
                }
                else if(size < 2 || size > 100){
                    printf("It should be a number between 2 and 100!\n");
                    check = 0;
                }
                fflush(stdin);
        }while(!check);

        double array[size];

        do{ // Введення кількості цифр після коми
            printf("Enter the number of decimal places(0-14): ");
            if (scanf("%d%c", &dec, &check) != 2 || check != '\n'){
                printf("Invalid input!\n");
                check = 0;
            }
            else if(dec < 0 || dec > 14){
                printf("The number is out of the program's accuracy!\n");
                check = 0;
            }
            fflush(stdin);
        }while(!check);

        nums = 15 - dec;
        range = pow(10,nums);

        if(choise()){
            for (short i = 0; i < size; i++){ // Введення елементів масиву вручну
                do{
                    printf("Enter #%d element (up to %d integer digit%c): ", i+1, nums, nums == 1 ? '\0' : 's');
                    if (scanf("%lf%c", &array[i], &check) != 2 || check != '\n'){
                        printf("Invalid input!\n");
                        check = 0;
                    }
                    else if(array[i] >= range || array[i] <= -range){
                        printf("The amount of digits is out of the range!\n");
                        check = 0;
                    }
                    fflush(stdin);
                }while(!check);
            }
        }
        else{
            do{ // Введення мінімального значення числа
                printf("Enter the MIN integer (up to %d digit%c): ", nums, nums == 1 ? '\0' : 's');
                if (scanf("%lld%c", &rand_min, &check) != 2 || check != '\n'){
                    printf("Invalid input!\n");
                    check = 0;
                }
                else if(rand_min >= range || rand_min <= -range){
                    printf("The amount of digits is out of the range!\n");
                    check = 0;
                }
                else if(rand_min == range-1){
                    printf("With the current number MAX cannot exist!\n");
                    check = 0;
                }
                fflush(stdin);
            }while(!check);

            do{ // Введення максимального значення числа
                printf("Enter the MAX integer (up to %d digit%c): ", nums, nums == 1 ? '\0' : 's');
                if (scanf("%lld%c", &rand_max, &check) != 2 || check != '\n'){
                    printf("Invalid input!\n");
                    check = 0;
                }
                else if(rand_max >= range || rand_max <= -range){
                    printf("The amount of digits is out of the range!\n");
                    check = 0;
                }
                else if(rand_max <= rand_min){
                    printf("The MAX cannot be less or equal to the MIN!\n");
                    check = 0;
                }
                fflush(stdin);
            }while(!check);

            for (short i = 0; i < size; i++){ // Заповнення масиву випадковими числами
                array[i] = (rand_min + rand() * (rand_max-rand_min) / RAND_MAX);
                array[i] != rand_max ? array[i] += (rand() * DEC_RAND / RAND_MAX)/1e14 : array[i];
            }
        }

        nums = nums_size(array, size);

        printf("\nYour array:\n");
        for (short i = 0; i < size; i++){ // Виведення масиву
            printf("%*.*lf %c", nums+dec+1, dec, array[i], i%5 == 4 || i == size - 1 ? '\n' : '|');
        }

        order = sort(array, size);

        printf("\n\nSorted array:\n");
        for (short i = 0; i < size; i++){ // Виведення відсортованого масиву
            printf("%*.*lf %c", nums+dec+1, dec, order ? array[i] : array[size-1-i], i%5 == 4 || i == size - 1 ? '\n' : '|');
        }

    }while(quit());

    return 0;
}

char choise(){
    printf("\nType the array manually (Enter) or randomly (Any key)...");

    if (getch() == 13){
        printf("\n\n");
        return 1;
    }
    else{
        printf("\n\n");
        return 0;
    }
}

short nums_size(double *arr, short s){
    double temp = fabs(arr[0]);
    short count = 1;
    
    for (short i = 1; i < s - 1; i++){
        if (temp < fabs(arr[i+1])){
            temp = fabs(arr[i+1]);
        }
    }

    while(temp == pow(10,count) || temp-pow(10,count) > 0){
        count++;
    }

    return count+1;
}

char sort(double *arr, short s){
    for(short i = 0; i < s - 1; i++){
        for(short j = 0; j < s - i - 1; j++){
            if(arr[j] > arr[j+1]){
                double temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    char button = 0;

    printf("\nSort in ascending order (+) or descending order (-)...");

    do{
        button = getch();
        if (button == 43){
            return 1;
        }
        else if (button == 45){
            return 0;
        }
        button = 0;
    }while(!button);
}

char quit(){

    printf("\nSort another array of numbers (Any key / esc)...");
    
    if (getch() == 27){
        return 0;
    }
    else{
        printf("\n\n");
        return 1;
    }
}