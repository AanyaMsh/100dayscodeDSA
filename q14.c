// Check Identity Matrix
// Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.
#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, mat[100][100];
    bool isIdentity = true;

    scanf("%d", &n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i==j && mat[i][j]!=1) || (i!=j && mat[i][j]!=0)){
                isIdentity=false;
                break;
            }
        }
    }

    printf("%s\n", isIdentity ? "Identity Matrix" : "Not an Identity Matrix");
}
