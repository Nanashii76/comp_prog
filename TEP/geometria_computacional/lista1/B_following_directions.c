#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include <stdbool.h>

void mapping(char ch, int* x, int* y){

    switch(ch){
        case 'U':
            *y+=1;
            break;
        case 'D':
            *y-=1;
            break;
        case 'L':
            *x-=1;
            break;
        case 'R':
            *x+=1;
            break;
        default: break;
    }

}

void solve(char *str, int size){

    int x,y;
    x = y = 0;
    bool pass = false;
    
    for(int i = 0; i < size; ++i) {
        mapping(str[i],&x,&y);
        if(x == 1 and y == 1)
            pass = true;
    }

    //printf("(%d,%d)\n", x, y);

    if(pass)
        printf("Yes\n");
    else
        printf("No\n");
}

int main(void){

    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d",&n);;
        char directions[n+1];
        scanf("%s", directions);
        //printf("%s\n", directions); 
        solve(directions,n);
    }

    return 0;

}