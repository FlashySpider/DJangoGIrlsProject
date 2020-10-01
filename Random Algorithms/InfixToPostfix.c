#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

//------------STACK-------------
typedef struct stack{
    char * data;
    int top;
    int capacity;
} Stack;

bool isEmpty(Stack *s){
    if(s->top == -1){
        return true;
    } else{
        return false;
    }
}

bool isFull(Stack *s){
    if(s->top == s->capacity - 1){
        return true;
    } else{
        return false;
    }
}

bool push(Stack *s, char data){
    if(!isFull(s)){
        s->top += 1;
        s->data[s->top] = data;
        return true;
    } else {
        return false;
    }
}

char pop(Stack *s){
    if(!isEmpty(s)){
        return s->data[s->top--];
    }
}

Stack * stack_init(int ofSize){
    if(ofSize <= 0){
        return NULL;
    }

    Stack *s = (Stack *)malloc(sizeof(Stack));
    if(!s){
        return NULL;
    }

    s->top = -1;
    s->capacity = ofSize;

    s->data = (char *)malloc(ofSize * sizeof(char));
    if(!s->data){
        return NULL;
    }

    return s;
}

//---------------------------------

int precedence(char c){
    switch(c){
        case '+' : return 1;
        case '-' : return 1;
        case '*' : return 2;
        case '/' : return 2;
        case '^' : return 3;
    }
    return INT_MIN;
}

bool isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
        return true;
    }
    else {
        return false;
    }
}

bool isOperand(char c){
    int asciiValue = (int)c;
    if((asciiValue >= 65 && asciiValue <= 90) ||  (asciiValue >= 97 && asciiValue <= 122)){
        return true;
    } else{
        return false;
    }
}

void InfixToPostfix(char *exp){
    int len_exp = strlen(exp);

    Stack *s = stack_init(len_exp);
    char *temp = exp;

    while(*temp != '\0'){

        if(*temp == '('){
            push(s, *temp);
        }

        else if(isOperator(*temp)){

            if(precedence(*temp) > precedence(s->data[s->top])){
                push(s, *temp);
            }
            else{
                while(!isEmpty(s) && s->top != '(' && precedence(s->data[s->top]) >= precedence(*temp)){
                    printf("%c", pop(s));
                }
                push(s, *temp);
            }

        }

        else if(isOperand(*temp)){
            printf("%c",*temp);

        }

        else if(*temp == ')'){
            while(s->data[s->top] != '('){
                printf("%c", pop(s));
            }
            pop(s);
        }

        temp += 1;
    }

    while(!isEmpty(s)){
        printf("%c", pop(s));
    }

    printf("\n");

}


int main(){

    char *exp1 = "(a+(b*c))"; 
    char *exp2 = "((a+b)*(z+x))";
    char *exp3 = "((a+t)*((b+(a+c))^(c+d)))";
    char *exp4 = "c+d*b/(a-e)^b";
    char *exp5 = "a+b*(c^d-e)^(f+g*h)-i";

    InfixToPostfix(exp1);
    InfixToPostfix(exp2);
    InfixToPostfix(exp3);
    InfixToPostfix(exp4);
    InfixToPostfix(exp5);

    return 0;
}