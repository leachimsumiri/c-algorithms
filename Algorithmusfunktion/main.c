//
//  main.c
//  Algorithmusfunktion
//
//  Created by Michael Irimus on 08.03.18.
//  Copyright © 2018 Michael Irimus. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

// Vorlesung 08.03.2018 Laufzeitfunktionen

int f(int **a, int n){
    int i, j, result;
    result = 0;//1
    for(i=0; i<n; i++){// 1 + (n+1) + n
        for(j=0; j<n; j++){// n + n(n+1) + n^2
            result = result + a[i][j];//2* n^2
        }
    }
    return result;
}
// T (n) = 4n^2 + 4n + 4  --> O(n2)

int f2(int **a, int n){
    int i, j, result;
    result = 0;//1
    for(i=0; i<n; i++){// 1 + (n+1) + n
        for(j=0; j<n; j+=2){// n + n((n/2)+1) + (n/2)^2
            result = result + a[i][j];// 2* (n/2)^2
        }
    }
    return result;
}
// T (n) = 2n^2 + 4n + 4  --> O(n2)

int f3(int **a, int n){
    int i,result;
    result=0;//1
    for(i=1; i<n; i=i*2){// 1 + log2n-1 + 1 + 2*(log2n - 1)
        result=result+a[i][i];// 2 * (log2n - 1)
    }
    return result;
}
// T (n) = 5*log2n - 1  --> O(logn)

int f4(int **a, int n){
    int i,j,result;
    result = 0;//1
    for(i=0;i<n;i++){// 1 + n+1 + n
        for(j=0;j<i;j++){// n + (n(n+1))/2 + (n(n-1))/2
            result=result+a[i][j];// 2* (n(n-1))/2
        }
    }
    return result;
}
// T(n) = 2n^2 + 2n + 3



//FAKULTÄT

long f5(int n){
    if(n>1){//1
        return n * f5(n-1);//3
    }
    return 1;//1
}
// Tn(n) = 4(n-1)+2  --> O(n)

long f6(int n){
    if(n>1){
        return f6(n-1) + f6(n-1); // besser 2 * f6(n-1); --> O(n)
    }
    return 1;
}

//tn>1(n) = 6 -> 2^(n-1)-1
//tn=1(n) = 2 -> 2^(n-1)

//T(n) = 8 * 2^(n-1)-6  --> O(2^n)
