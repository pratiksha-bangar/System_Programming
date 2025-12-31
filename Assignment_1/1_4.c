/*
Display Complete file Information
Accept file name and display the file metadata using stat()
size, inode , permission,hardlinks, owner(git,uid),file type, last access/modify time
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<time.h>

int main()
{
    char fname[100];
    struct stat sobj;
    int iRet=0;

    printf("\nEnter file name:");
    scanf(" %s",fname);

    iRet =stat(fname,&sobj);

    printf("\n\n--------------- file metedata -------------- \n");
    printf("Inode No: %ld\n",sobj.st_ino);
    printf("Hard Link Count:%ld\n",sobj.st_nlink);
    printf("Total Size:%ld\n",sobj.st_size);
    printf("owner gid:%u\n",sobj.st_gid);
    printf("Owner uid:%u\n",sobj.st_uid);

    printf("Last Access Time:%s",ctime(&sobj.st_atime));
    printf("Last Modify Time:%s",ctime(&sobj.st_mtime));


    printf("File type:");
    if(S_ISREG(sobj.st_mode))
    {
        printf("Regular file:\n");
    }
    else if(S_ISDIR(sobj.st_mode))
    {
        printf("Directory File\n");
    }
    else if(S_ISCHR(sobj.st_mode))
    {
        printf("Character Device\n");
    }
    else if(S_ISBLK(sobj.st_mode))
    {
        printf("Block Device\n");
    }
    else if(S_ISFIFO(sobj.st_mode))
    {
        printf("FIFO/pipe\n");
    }
    else if(S_ISLNK(sobj.st_mode))
    {
        printf("Symbolic Link\n");
    }
    else
    {
        printf("Unknown\n");
    }



    return 0;
}