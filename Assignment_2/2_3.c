/*
list all files from directory
Accept direcrory name
use opendir()n/ readdir() to print only name (skip . and ..)

*/

#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>

int main()
{  
    char fname[100];
    DIR *dp;
    struct dirent *d;

    printf("Entre Directory name:");
    scanf("%s",fname);

    dp = opendir(fname);

    if(dp == NULL)
    {
        printf("Unable to open Directory");
        return -1;
    }
    printf("Directory opened sucessfully\n\n");


    printf("Files\n:");
    while((d= readdir(dp)) != NULL)
    {
        if(strcmp(d->d_name, ".") != 0 && strcmp(d->d_name, "..") !=0)
        {
            printf("%s\n",d->d_name);
        }
    }

    closedir(dp);

    return 0;
}