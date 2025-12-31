/*
open file -
Accept file name from user and open it using open()
print : success message + returned file descriptor
handles error using perror()
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd =0;
    char fname[100];

    printf("Enter file name you want to open:");
    scanf("%s",fname);

    fd = open(fname,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file");
        return -1;
    }

    printf("File open sucessfully with fd :%d\n",fd);

    close(fd);
    return 0;
}