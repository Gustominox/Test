#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "auxiliares.h"


int isFloat (char *s){
  char *str = NULL;
  double flt = strtod (s, &str);
  if (!str  ||  *str)
      return 0;
  return 1;
}


int isInteger (char *s){
  while(*s){
    if(!isdigit(*s)) return 0;   
    s++;
  }
  return 1;
}


int compare(char* content, char* value, OPERATOR oper){
    int isValid = 1;
    
    switch(oper){

        case LT:
            if(isInteger(value)){
                if(atoi(content) < atoi(value)) isValid = 0;
            }
            else if(isFloat(value)){
                if(atof(content) < atof(value)) isValid = 0;
            } else {
                int k = 0;
                while(k < strlen(value) && k < strlen(content)){
                    if(content[k] == value[k])
                        k++;
                    else if(content[k] < value[k]){
                        break;
                    }
                    else if(content[k] > value[k]){
                        isValid = 0;
                        break;
                    }
                }
            }
            break;
        
        case EQ:
            if(isInteger(value)){
                if(atoi(content) == atoi(value)) isValid = 0;
            }
            else if(isFloat(value)){
                if(atof(content) == atof(value)) isValid = 0;
            } else {
                int k = 0;
                while(k < strlen(value) && k < strlen(content)){
                    if(content[k] == value[k]){
                        isValid = 0;
                        k++;
                    }
                    else{
                        isValid = 1;
                        break;
                    }
                }
            }
            break;

        case GT:
            if(isInteger(value)){
                if(atoi(content) > atoi(value)) isValid = 0;
            }
            else if(isFloat(value)){
                if(atof(content) > atof(value)) isValid = 0;
            } else {
                int k = 0;
                while(k < strlen(value) && k < strlen(content)){
                    if(content[k] == value[k])
                        k++;
                    else if(content[k] > value[k]){
                        break;
                    }
                    else if(content[k] < value[k] || content[k] == '\n'){
                        isValid = 0;
                        break;
                    }
                }
            }
            break;
    }
    return isValid;
}


void swap(char **xp, char **yp){
    char** temp = xp; 
    xp = yp; 
    yp = temp; 
}


void ordenaDecresc(int ***arr, int linhas){ 
    int linhaAtual, linhaPost;

    for (linhaAtual = 0; linhaAtual < linhas - 1; linhaAtual++)
      for (linhaPost = linhaAtual+1; linhaPost < linhas; linhaPost++)

        if(arr[linhaAtual][2] < arr[linhaPost][2])
          swap(arr[linhaAtual], arr[linhaPost]);
}

