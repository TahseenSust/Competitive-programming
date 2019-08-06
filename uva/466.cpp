#include<bits/stdc++.h>
using namespace std;

bool is90(char miror1[][100],char miror2[][100],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           // printf("%c %c\n\n",miror1[i][j],miror2[j][n-1]);
            if(miror1[i][j]!=miror2[j][n-i-1]){
                return false;
            }
        }
    }
    return true;
}
bool is180(char miror1[][100],char miror2[][100],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(miror1[i][j]!=miror2[n-1-i][n-1-j]){
                return false;
            }
        }
    }
    return true;
}

bool is270(char miror1[][100],char miror2[][100],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //printf("%c %c\n",miror1[i][j],miror2[n-j-1][i]);
            if(miror1[i][j]!=miror2[n-j-1][i]){
                return false;
            }
        }
    }
    return true;
}

bool isVertical(char miror1[][100],char miror2[][100],int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(miror1[i][j]!=miror2[n-1-i][j]){
                return false;
            }
        }
    }
    return true;
}

int isCombination(char miror1[][100],char miror2[][100],int n){
    char miror[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            miror[i][j]=miror1[n-1-i][j];
        }
    }
    if(is90(miror,miror2,n)){
        return 1;
    }else if(is180(miror,miror2,n)){
        return 2;
    }else if(is270(miror,miror2,n)){
        return 3;
    }

}

bool isPreservation(char miror1[][100],char miror2[][100],int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(miror1[i][j]!=miror2[i][j]){
                return false;
            }
        }
    }
    return true;
}
//bool isImproper(char miror1[][100],char miror2[][100],int n){
//    for(int i=0;i<n;i++){
//        miror2[i][n]=miror2[i][0];
//    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            if(miror1[j][i]!=miror2[j][i+1]){
//                return false;
//            }
//        }
//    }
//    return true;
//}
int main()
{
    //freopen("input.txt","r",stdin);
    int n,cn=0;
    while(scanf("%d",&n)!=EOF){
        char miror1[100][100];
        char miror2[100][100];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf(" %c",&miror1[i][j]);
            }
            for(int j=0;j<n;j++){
                scanf(" %c",&miror2[i][j]);
            }
        }
        cn++;
        if(isPreservation(miror1,miror2,n)){
            printf("Pattern %d was preserved.\n",cn);
        }else if(is90(miror1,miror2,n)){
            printf("Pattern %d was rotated 90 degrees.\n",cn);
        }else if(is180(miror1,miror2,n)){
            printf("Pattern %d was rotated 180 degrees.\n",cn);
        }else if(is270(miror1,miror2,n)){
            printf("Pattern %d was rotated 270 degrees.\n",cn);
        }else if(isVertical(miror1,miror2,n)){
            printf("Pattern %d was reflected vertically.\n",cn);
        }else{

            if(isCombination(miror1,miror2,n)==1){
                printf("Pattern %d was reflected vertically and rotated 90 degrees.\n",cn);
            }else if(isCombination(miror1,miror2,n)==2){
                printf("Pattern %d was reflected vertically and rotated 180 degrees.\n",cn);
            }else if(isCombination(miror1,miror2,n)==3){
                printf("Pattern %d was reflected vertically and rotated 270 degrees.\n",cn);
            }else{
                printf("Pattern %d was improperly transformed.\n",cn);
            }
        }
    }
}
/*
5
X...X ....X
.X... ...X.
...X. .X...
..X.X ..X..
....X XX..X
6
....XX X....X
...X.. X.X...
XX..X. .X..X.
..X... ...X.X
...X.. ..X...
..X..X ..X...
2
X. X.
.X .X
4
..X. ...X
XX.. ....
.... XX..
...X ..X.
5
X.... .X...
.X... ..X..
.X... ..X..
...X. ....X
....X X....
4
.X.. ..X.
.X.X X...
.... ..XX
..X. ....
2
.. XX
XX ..
*/
