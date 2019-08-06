#include<stdio.h>
int main()
{
    int i,j;    //for loops
    int m,n;    //for m*n field
    int cno=0,line=0;      //for field no.
    char arr[110][110];
    while(scanf("%d%d%*c",&m,&n)){
            if(m==0&&n==0)
                break;
            if(line)
                printf("\n");
            line=1;
            for(i=1;i<m+1;i++){
                for(j=1;j<n+1;j++){
                    scanf("%c",&arr[i][j]);
                }
                scanf("%*c");
            }

            for(i=0;i<m+2;i++){
                for(j=0;j<n+2;j++){
                    if(arr[i][j]!='*')
                        arr[i][j]='0';
                }
            }

            for(i=1;i<m+1;i++){
                for(j=1;j<n+1;j++){
                    if(arr[i][j]=='*'){
                        if(arr[i-1][j-1]!='*')
                           arr[i-1][j-1]++;
                        if(arr[i-1][j]!='*')
                            arr[i-1][j]++;
                        if(arr[i-1][j+1]!='*')
                            arr[i-1][j+1]++;
                        if(arr[i][j-1]!='*')
                            arr[i][j-1]++;
                        if(arr[i+1][j-1]!='*')
                            arr[i+1][j-1]++;
                        if(arr[i+1][j]!='*')
                            arr[i+1][j]++;
                        if(arr[i+1][j+1]!='*')
                            arr[i+1][j+1]++;
                        if(arr[i][j+1]!='*')
                            arr[i][j+1]++;

                    }
                }
            }
            printf("Field #%d:\n",++cno);

            for(i=1;i<m+1;i++){
                for(j=1;j<n+1;j++){
                    printf("%c",arr[i][j]);
                }
                printf("\n");
            }
    }
    return 0;
}
