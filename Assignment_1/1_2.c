/*
open file in given mode-
    accepts file name and mode (R, W, RW, A) from user
    converts mode to flags (O_RDONLY, O_WRONLY, O_RDWR, O_APPEND, | O_CREAT)
    opens file accordingly and display file descriptor

*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<ctype.h>

int main()
{
    int fd =0;
    char fname[100];
    char mode;
    int flag =0;

    printf("Enter file name:");
    scanf("%s",fname);

    printf("Enter mode one of them:\n1)R\n2)W\n3)M(RW)\n4)A\n");
    scanf(" %c",&mode);

    mode = toupper(mode);

    switch (mode)
    {
        case 'R':
            flag = O_RDONLY;
            break;

        case 'W':
            flag = O_WRONLY | O_CREAT;
            break;

        case 'M':  // read +write
            flag = O_RDWR | O_CREAT;
            break;

        case 'A':
            flag = O_CREAT | O_APPEND | O_WRONLY;
            break;

        default:
            printf("Inavlid option....\n");
            return 1;
    }
    

    fd = open(fname, flag,0777);


    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("\nFile opened sucessfully with fd:%d\n",fd);

    close(fd);

    return 0;
}



/*
if(strcmp(mode , "R") == 0)
    {
        flag = O_RDONLY;
    }
    else if(strcmp(mode, "W") == 0)
    {
        flag = O_WRONLY | O_CREAT;
    }
    else if(strcmp(mode,"RW") == 0)
    {
        flag = O_RDWR | O_CREAT ;
    }
    else if(strcmp(mode , "A") == 0)
    {
        flag = O_CREAT | O_APPEND ;
    }
    else
    {
        printf("Invalid option.. choose one of the above\n");
        return 1;
    }

*/