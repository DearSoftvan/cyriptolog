//
//  main.c
//  Kriptolog
//
//  Created by Safvan Öztürk on 10/04/2019.
//  Copyright © 2019 Safvan Öztürk. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//if the charecter is a capital letter returns lowercase
void isCapital(char *letter)
{
    if(*letter <= 90 && *letter >= 65)
        *letter=*letter+32;
}

// check the character is between in a-z --- a boolean function
int isInSide(char *letter)
{
    if(*letter>=97 && *letter<=122)
        return 1;
    else
        return 0;
}

//change the value of character for direction if value break the limits if states keep the value within limits
//direction == 1 >> +
//direction == 2 >> -
void floating(char *letter,int value,int direction)
{
    if(direction==1)
    {
        *letter=*letter+value;
        if (*letter>122)
            *letter=*letter-26;
    }
    
    if (direction==2)
    {
        *letter=*letter-value;
        if(*letter<97)
            *letter=*letter+26;
    }
}



void kripto(char string[], int value,int direction)
{
    int size;
    for(size=0;string[size]!='\0';size++)
    {
        
    }
    for(int i=0;string[i]!='\0';i++)
    {
        if (string[i] =='\0')
        {
            printf("error canım\n");
            break;
        }
        else
        {
            isCapital(&string[i]);
            if(isInSide(&string[i])==1)
                floating(&string[i], value, direction);
        }
    }
}
void rekripto(char string[], int value,int direction)
{
    if (direction==1)
        kripto(string, value, 2);
    
    if (direction==2)
        kripto(string, value, 1);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char word[50]="ali";
    //scanf("%[^\n]",word);
    
    
    printf("işlemden önce yazı: %s\n",word);
    
    kripto(word,1,1);
    
    printf("işlemden sonra yazı: %s\n",word);
    
    rekripto(word, 1, 2);
    
    printf("rekripto: %s\n",word);
    
    return 155;
}
// Simge ve Türkçe karekterler ve son harf de bozuyor aritmetiği bozuyor.>> revizyondan sonra problemler ortadan kalkmış olmalı
