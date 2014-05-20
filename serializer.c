 #include <stdio.h>
 #include <string.h>

int opt(char *c)
{
    if(strcmp(c," ") == 0)
        return -1;
    if(strcmp(c,"-cx") == 0)
        return 0;
    if(strcmp(c,"-cs") == 0)
        return 1;
    if(strcmp(c,"-j") == 0)
        return 2;
    return -1;
}

void printhelp()
{
    puts("Usage:");
    puts("sigmund [-options] <FILE>\n");
    puts("Options:");
    puts("-cx -> C++");
    puts("-cs -> C#");
    puts("-j -> Java\n");
}

int main(int argc, char *argv[])
{
    int cxflag = 0;
    int csflag = 0;
    int jflag = 0;

    char *c = argc == 2 ? argv[1] : " ";
    switch(opt(c))
    {
        case 0:
            cxflag = 1;
            break;
        case 1:
            csflag = 1;
            break;
        case 2:
            jflag = 1;
            break;
        default:
            printhelp();
            break;
    }
}
