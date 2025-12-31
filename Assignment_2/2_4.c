/*
List fils with type------
Accept Directory name 
print each entry with its type - (Regular/Directory Link/FIFO/socket/char/Block)
use stat for accurate type
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main()
{
    char fname[100];
    char path[512];
    DIR *dp;
    struct dirent *d;
    struct stat sobj;
    

    printf("\nEnter Directory name:");
    scanf("%s",fname);

    dp = opendir(fname);

    if(dp == 0)
    {
        printf("\nUnable to open Directory");
        return -1;
    }
    printf("\nDirectory open sucessfully\n");


    while((d = readdir(dp)) != NULL)
    {
        snprintf(path, sizeof(path), "%s/%s", fname, d->d_name);

        if (stat(path, &sobj) == -1)
            continue;

        printf("%s : ", d->d_name);

        if (S_ISREG(sobj.st_mode))
            printf("Regular File");
        else if (S_ISDIR(sobj.st_mode))
            printf("Directory");
        else if (S_ISLNK(sobj.st_mode))
            printf("Symbolic Link");
        else if (S_ISFIFO(sobj.st_mode))
            printf("FIFO");
        else if (S_ISSOCK(sobj.st_mode))
            printf("Socket");
        else if (S_ISCHR(sobj.st_mode))
            printf("Character Device");
        else if (S_ISBLK(sobj.st_mode))
            printf("Block Device");
        else
            printf("Unknown");

        printf("\n");
    }

    closedir(dp);
    return 0;    
}

