 #include <stdio.h>
 #include <string.h>

int main(int argc, char *argv[])
{
    int cxflag = 0;
    int csflag = 0;
    int jflag = 0;

    char *c;
    switch(opt(c))
    {
        case '-cx':
            jflag = 1;
            break;
        case '-cs':
            jflag = 1;
            break;
        case '-j':
            jflag = 1;
            break;
        default:
            printhelp();
            break;
    }
}

int opt(char *c)
{
    if(!strcmp(*c,"-cx"))
        return 0;
    if(!strcmp(*c,"-cs"))
        return 1;
    if(!strcmp(*c,"-j"))
        return 2;
    return -1;
}

void printhelp()
{
    cout << "-cx -> C++" << endl;
    cout << "-cs -> C#" << endl;
    cout << "-j -> Java" << endl;
}
