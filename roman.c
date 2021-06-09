#include <stdio.h>
#include <stdlib.h>
#include<string.h>
static int roman_to_integer(char c)
{
    switch(c) {
    case 'I':  
        return 1;  
    case 'V':  
        return 5;  
    case 'X':  
        return 10;  
    case 'L':  
        return 50;  
    case 'C':  
        return 100;  
    case 'D':  
        return 500;  
    case 'M':  
        return 1000;  
    default:
        return 0;
    }
}

int roman_to_int (char *s)
{
    int i, int_num = roman_to_integer(s[0]);

    for (i = 1; s[i] != '\0'; i++) {
        int prev_num = roman_to_integer(s[i - 1]);
        int cur_num = roman_to_integer(s[i]);
        if (prev_num < cur_num) {
            int_num = int_num - prev_num + (cur_num - prev_num);
        } else {
            int_num += cur_num;
        }
    }
    return int_num;
}

void decimal2roman(int num){
    int decimal[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1}; 
    char *symbol[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};  
    int i = 0;
 
    while(num){ 
        while(num/decimal[i]){  
            printf("%s",symbol[i]); 
            num -= decimal[i]; 
        }
        i++;   
    }
}
int main()
 {
    char str[100],*seperator;
    int Fnum,Snum,res;
    gets(str);

    seperator=strtok(str,"+");
    Fnum=roman_to_int(seperator);
    seperator=strtok(NULL, "-");
    Snum=roman_to_int(seperator);
    
    res=Fnum+Snum;

    decimal2roman(res);

    return 0;
}