/*
Find largest file in Directory ---------
Accept directory name 
find and print :
    largest file name
    its size in bytes
consider only regular files
*/


#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>

int main()
{
    char dname[100];
    char path[512];
    DIR *dp;
    struct dirent *d;
    struct stat sobj;
    char largest_file[256] ="";
    long max_size =0;

    printf("\nEnter Directory Name:");
    scanf("%s",dname);

    dp = opendir(dname);

    if(dp == 0)
    {
        printf("\nUnable to open directory");
        return -1;
    }
    printf("\nDirectory Open Successfully\n");

    while((d = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", dname, d->d_name);

        stat(path, &sobj);

        if (S_ISREG(sobj.st_mode))
        {
            if (sobj.st_size > max_size)
            {
                max_size = sobj.st_size;
                strcpy(largest_file, d->d_name);
            }
        }
    }

    printf("\nLargest File is:%s",largest_file);
    printf("\nSize is:%ld",max_size);

    closedir(dp);
    return 0; 
}