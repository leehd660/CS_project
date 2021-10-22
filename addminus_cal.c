#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char num1[] = "10.25";
    char num2[] = "9.75";
    // string num1 = "10.25";
    // std::string num2 = "9.75";

    bool a1 = false;
    char b1[] = "";
    int c1 = 0;
    bool a2 = false;
    char b2[] = "";
    int c2 = 0;


    for (int i = 0; i < strlen(num1); i++)
    {
        if (strcmp(&num1[0],"-")==0)
        {
            a1 = true;
        }
        if (strcmp(&num1[i],"." )==0) {
            c1 = -(strlen(num1)-i-1);
        }
        else {
            strcat(b1,&num1[i]);
        }
    }
    printf("b : %s c: %d", b1,c1 );
    
    
}