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

#define SIZE 50


//if the charecter is a capital letter returns lowercase
void isCapital(char *letter)
{
    if(*letter <= 90 && *letter >= 65)
        *letter=*letter+32;
}


// check the character is between in a-z --- a boolean function, if it is in interval function return 1
int isInSide(char *letter)
{
    if(*letter>=97 && *letter<=122)
        return 1;
    else
        return 0;
}


char overFlow(char *letter)
{
    
    if(*letter > 122)
        *letter= *letter - 26;
   
    if(*letter < 97)
        *letter= *letter + 26;
    return *letter;
}


//change the value of character for direction if value break the limits if states keep the value within limits
//direction == 1 >> +
//direction == 2 >> -
void floating(char *letter,int value,int direction)
{
    if(direction==1)
    {
        *letter=*letter+value;
        overFlow(letter);
    }
    
    if (direction==2)
    {
        *letter=*letter-value;
        overFlow(letter);
        
    }
}


void kripto(char string[], int value,int direction)
{
    
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
            if(isInSide(&string[i]) == 1)
                floating(&string[i], value, direction);
        }
    }
}


//for solving encrypted text
void rekripto(char string[], int value,int direction)
{
    if (direction==1)
        kripto(string, value, 2);
    
    if (direction==2)
        kripto(string, value, 1);
}

//for see the all variants
void possibleVariations(char string[])
{
    char variant[SIZE];
    strcpy(variant, string);//variant=string;
    for (int i=1; i<26; i++)
    {
        rekripto(variant, 1, 1);
        printf("Variant %d= %s\n",i,variant);
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char word[SIZE]="ali atla bakalım?";
    int value=10;
    int direction=1;
    //scanf("%[^\n]",word);
    
    
    printf("işlemden önce yazı: %s\n",word);
    
    kripto(word,value,direction);
    
    printf("işlemden sonra yazı: %s\n",word);
    
    possibleVariations(word);
    
    
    return 155;
}

//add menu
// If you want calculate size of string you can copy this function
/*
 int calculateSize(char string[])
 {
 int size;
 for(size=0;string[size]!='\0';size++)
 {
 
 }
 return size;
 }
 */

