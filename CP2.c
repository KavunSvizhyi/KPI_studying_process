#include <stdio.h>
#include <conio.h>
#include <math.h>

short check_sides(double x, double y, double z);
double perimeter(double x, double y, double z);
double semiperimeter(double x, double y, double z);
double area(double x, double y, double z);
double hight(double main_side, double s1, double s2);
double median(double main_side, double s1, double s2);
double bisector(double main_side, double s1, double s2);
short quit();

int main(){

    double a, b, c;
    short dec;
    char check;
    
    do{ // цикл виходу з програми
        a = b = c = 0;
        do{ // цикл для перевірки введених даних (сторін трикутника)
            do{
                printf("Enter the first side of the triangle (a): ");
                if (scanf("%lf%c", &a, &check) != 2 || check != '\n'){
                    printf("Invalid input!\nTry again.\n");
                }
                else if (a < 0.001 || a > 1000){
                    check = 0;
                    printf("The lenght should be between 0.001 and 1000!\nTry again.\n");
                }
                fflush(stdin);
            }while(!check);

            do{
                printf("Enter the second side of the triangle (b): ");
                if (scanf("%lf%c", &b, &check) != 2 || check != '\n'){
                    printf("Invalid input!\nTry again.\n");
                }
                else if (b < 0.001 || b > 1000){
                    printf("The lenght should be between 0.001 and 1000!\nTry again.\n");
                }
                fflush(stdin);
            }while(b < 0.001 || b > 1000 || check != '\n'); 

            do{
                printf("Enter the third side of the triangle (c): ");
                if (scanf("%lf%c", &c, &check) != 2 || check != '\n'){
                    printf("Invalid input!\nTry again.\n");
                }
                else if (c < 0.001 || c > 1000){
                    printf("The lenght should be between 0.001 and 1000!\nTry again.\n");
                }
                fflush(stdin);
            }while(c < 0.001 || c > 1000 || check != '\n'); 

        }while(!check_sides(a, b, c));

        do{ // цикл для введення кількості знаків після коми
            printf("Enter the acuracy (# of decimal places): ");
            if (scanf("%d%c", &dec, &check) != 2 || check != '\n'){
                printf("Invalid input!\nTry again.\n");
                dec = -1;
            }
            else if (dec < 0 || dec > 15){
                printf("The number should be between 0 and 15!\nTry again.\n");
            }
            fflush(stdin);
        } while (dec < 0 || dec > 15 || check != '\n');
        
        
        for (short i = 0; i < 60; i++){
            printf("-");
        } // розмежування рядків

        printf("\nRESULTS:\n");
        printf("Perimeter: %.*lf\n", dec, perimeter(a,b,c));
        printf("Semiperimeter: %.*lf\n", dec, semiperimeter(a,b,c));
        printf("Area: %.*lf\n\n", dec, area(a,b,c));

        printf("Hight(A): %.*lf\n", dec, hight(a,b,c));
        printf("Median(A): %.*lf\n", dec, median(a,b,c));
        printf("Bisector(A): %.*lf\n\n", dec, bisector(a,b,c));

        printf("Hight(B): %.*lf\n", dec, hight(b,a,c));
        printf("Median(B): %.*lf\n", dec, median(b,a,c));
        printf("Bisector(B): %.*lf\n\n", dec, bisector(b,a,c));

        printf("Hight(C): %.*lf\n", dec, hight(c,b,a));
        printf("Median(C): %.*lf\n", dec, median(c,b,a));
        printf("Bisector(C): %.*lf\n", dec, bisector(c,b,a));
        
        for (short i = 0; i < 60; i++){
            printf("-");
        } // розмежування рядків

    }while(quit());

    return 0;
}

short check_sides(double x, double y, double z){
    if (x + y > z && x + z > y && y + z > x){
        return 1;
    }
    else{
        printf("This triangle doesn't exist!\nTry again.\n");
        return 0;
    }
}

double perimeter(double x, double y, double z){
    return x+y+z;
}

double semiperimeter(double x, double y, double z){
    return perimeter(x,y,z)/2;
}

double area(double x, double y, double z){
    return sqrt(semiperimeter(x,y,z)*(semiperimeter(x,y,z)-x)*(semiperimeter(x,y,z)-y)*(semiperimeter(x,y,z)-z));
}

double hight(double main_side, double s1, double s2){
    return (2*area(main_side, s1 ,s2)/main_side);
}

double median(double main_side, double s1, double s2){
    return (sqrt(2*pow(s1,2)+2*pow(s2,2)-pow(main_side,2)))/2;
}

double bisector(double main_side, double s1, double s2){
    return (2/(s1+s2))*(sqrt(s1*s2*semiperimeter(main_side,s1,s2)*(semiperimeter(main_side,s1,s2)-main_side)));
}

short quit(){
    
    printf("\nTry another triangle (Any key / esc)...\n");
    
    if (getch() == 27){
        return 0;
    }
    else{
        return 1;
    }
}