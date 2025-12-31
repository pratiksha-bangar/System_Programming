/*
Read N Byte from file
Accept file name and number of bytes N
read exactly N bytes using read() and print on console
if contant less than N bytes then print available bytes
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int fd =0;
    char fname[100];
    int readbyte=0;
    int iRet =0;
    char *buffer =NULL;

    printf("Enter file name:");
    scanf("%s",fname);

    printf("How many bytes you want to read:");
    scanf("%d",&readbyte);

    fd = open(fname,O_RDONLY);          // open file

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("File opened sucessfully with fd :%d\n",fd);

    buffer = (char *)malloc(readbyte);

    iRet = read(fd,buffer,readbyte );       // read data

    printf("Data Read:%d bytes\n",iRet);

    close(fd);

    return 0;
}