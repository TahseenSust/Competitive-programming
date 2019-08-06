#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char num[25];
    int n,flag=0;
    while(scanf("%d %s",&n,num)&&n!=0){
        for(int k=0;k<5;k++){
            if(k==0){
                flag=0;
                for(int i=0;num[i];i++){
                    if(flag)
                        printf(" ");
                    flag=1;
                    if(num[i]=='1'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf(" ");
                        }
                        printf(" ");

                    }else if(num[i]=='2'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf("-");
                        }
                        printf(" ");
                    }else if(num[i]=='3'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf("-");
                        }
                        printf(" ");
                    }else if(num[i]=='4'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf(" ");
                        }
                        printf(" ");
                    }else if(num[i]=='5'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf("-");
                        }
                        printf(" ");
                    }else if(num[i]=='6'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf("-");
                        }
                        printf(" ");
                    }else if(num[i]=='7'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf("-");
                        }
                        printf(" ");
                    }else if(num[i]=='8'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf("-");
                        }
                        printf(" ");
                    }else if(num[i]=='9'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf("-");
                        }
                        printf(" ");
                    }else if(num[i]=='0'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf("-");
                        }
                        printf(" ");
                    }

                }
            }else if(k==1){
                for(int q=0;q<n;q++){
                    flag=0;
                    for(int i=0;num[i];i++){
                        if(flag)
                            printf(" ");
                        flag=1;
                        if(num[i]=='1'){
                            printf(" ");
                            for(int j=0;j<n;j++)
                                printf(" ");
                            printf("|");
                        }else if(num[i]=='2'){
                            printf(" ");
                            for(int j=0;j<n;j++){
                                printf(" ");
                            }
                            printf("|");
                        }else if(num[i]=='3'){
                            printf(" ");
                            for(int j=0;j<n;j++){
                                printf(" ");
                            }
                            printf("|");
                        }else if(num[i]=='4'){
                            printf("|");
                            for(int j=0;j<n;j++){
                                printf(" ");
                            }
                            printf("|");
                        }else if(num[i]=='5'){
                            printf("|");
                            for(int j=0;j<n;j++){
                                printf(" ");
                            }
                            printf(" ");
                        }else if(num[i]=='6'){
                            printf("|");
                            for(int j=0;j<n;j++){
                                printf(" ");
                            }
                            printf(" ");
                        }else if(num[i]=='7'){
                            printf(" ");
                            for(int j=0;j<n;j++){
                                printf(" ");
                            }
                            printf("|");
                        }else if(num[i]=='8'){
                            printf("|");
                            for(int j=0;j<n;j++){
                                printf(" ");
                            }
                            printf("|");
                        }else if(num[i]=='9'){
                            printf("|");
                            for(int j=0;j<n;j++){
                                printf(" ");
                            }
                            printf("|");
                        }else if(num[i]=='0'){
                            printf("|");
                            for(int j=0;j<n;j++){
                                printf(" ");
                            }
                            printf("|");
                        }

                    }
                    if(q!=n-1)
                        printf("\n");
                }
                }else if(k==2){
                    flag=0;
                    for(int i=0;num[i];i++){
                        if(flag) printf(" ");
                        flag=1;
                        if(num[i]=='1'){
                            printf(" ");
                            for(int j=0;j<n;j++)
                                printf(" ");
                            printf(" ");

                        }else if(num[i]=='2'){
                            printf(" ");
                            for(int j=0;j<n;j++){
                                printf("-");
                            }
                            printf(" ");
                        }else if(num[i]=='3'){
                            printf(" ");
                            for(int j=0;j<n;j++){
                                printf("-");
                            }
                            printf(" ");
                        }else if(num[i]=='4'){
                            printf(" ");
                            for(int j=0;j<n;j++){
                                printf("-");
                            }
                            printf(" ");
                        }else if(num[i]=='5'){
                            printf(" ");
                            for(int j=0;j<n;j++){
                                printf("-");
                            }
                            printf(" ");
                        }else if(num[i]=='6'){
                            printf(" ");
                            for(int j=0;j<n;j++){
                                printf("-");
                            }
                            printf(" ");
                        }else if(num[i]=='7'){
                            printf(" ");
                            for(int j=0;j<n;j++){
                                printf(" ");
                            }
                            printf(" ");
                        }else if(num[i]=='8'){
                            printf(" ");
                            for(int j=0;j<n;j++){
                                printf("-");
                            }
                            printf(" ");
                        }else if(num[i]=='9'){
                            printf(" ");
                            for(int j=0;j<n;j++){
                                printf("-");
                            }
                            printf(" ");
                        }else if(num[i]=='0'){
                            printf(" ");
                            for(int j=0;j<n;j++){
                                printf(" ");
                            }
                            printf(" ");
                        }
                    }
                }else if(k==3){
                    for(int q=0;q<n;q++){
                        flag=0;
                        for(int i=0;num[i];i++){
                            if(flag) printf(" ");
                            flag=1;
                            if(num[i]=='1'){
                                printf(" ");
                                for(int j=0;j<n;j++)
                                    printf(" ");
                                printf("|");
                            }else if(num[i]=='2'){
                                printf("|");
                                for(int j=0;j<n;j++){
                                    printf(" ");
                                }
                                printf(" ");
                            }else if(num[i]=='3'){
                                printf(" ");
                                for(int j=0;j<n;j++){
                                    printf(" ");
                                }
                                printf("|");
                            }else if(num[i]=='4'){
                                printf(" ");
                                for(int j=0;j<n;j++){
                                    printf(" ");
                                }
                                printf("|");
                            }else if(num[i]=='5'){
                                printf(" ");
                                for(int j=0;j<n;j++){
                                    printf(" ");
                                }
                                printf("|");
                            }else if(num[i]=='6'){
                                printf("|");
                                for(int j=0;j<n;j++){
                                    printf(" ");
                                }
                                printf("|");
                            }else if(num[i]=='7'){
                                printf(" ");
                                for(int j=0;j<n;j++){
                                    printf(" ");
                                }
                                printf("|");
                            }else if(num[i]=='8'){
                                printf("|");
                                for(int j=0;j<n;j++){
                                    printf(" ");
                                }
                                printf("|");
                            }else if(num[i]=='9'){
                                printf(" ");
                                for(int j=0;j<n;j++){
                                    printf(" ");
                                }
                                printf("|");
                            }else if(num[i]=='0'){
                                printf("|");
                                for(int j=0;j<n;j++){
                                    printf(" ");
                                }
                                printf("|");
                            }
                        }
                        if(q!=n-1)
                            printf("\n");
                    }
                }else if(k==4){
                flag=0;
                for(int i=0;num[i];i++){
                    if(flag) printf(" ");
                    flag=1;
                    if(num[i]=='1'){
                        printf(" ");
                        for(int j=0;j<n;j++)
                            printf(" ");
                        printf(" ");

                    }else if(num[i]=='2'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf("-");
                        }
                        printf(" ");
                    }else if(num[i]=='3'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf("-");
                        }
                        printf(" ");
                    }else if(num[i]=='4'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf(" ");
                        }
                        printf(" ");
                    }else if(num[i]=='5'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf("-");
                        }
                        printf(" ");
                    }else if(num[i]=='6'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf("-");
                        }
                        printf(" ");
                    }else if(num[i]=='7'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf(" ");
                        }
                        printf(" ");
                    }else if(num[i]=='8'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf("-");
                        }
                        printf(" ");
                    }else if(num[i]=='9'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf("-");
                        }
                        printf(" ");
                    }else if(num[i]=='0'){
                        printf(" ");
                        for(int j=0;j<n;j++){
                            printf("-");
                        }
                        printf(" ");
                    }

                }
            }
            //if(k!=4)
                printf("\n");
        }
        printf("\n");
    }
}
