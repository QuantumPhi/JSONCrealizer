 #include <stdio.h>
 #include <string.h>

int type(char *c)
{
    char *tok = strtok(c,".");
    tok = strtok(NULL," ");
    if(strcmp(tok,"cpp") == 0 || strcmp(tok,"cxx") == 0)
        return 0;
    if(strcmp(tok,"cs") == 0)
        return 1;
    if(strcmp(tok,"java") == 0)
        return 2;
    return -1;
}

void printhelp()
{
    puts("Usage:");
    puts("serializer [-options] <FILE>\n");
    puts("Options:");
}

int main(int argc, char **argv)
{
    int cxflag = 0;
    int csflag = 0;
    int jflag = 0;

    char *c = argc == 2 ? argv[1] : " ";
    switch(type(c))
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

    FILE *fp;
    char *line;
    char *name;
    char[] *param;
    bool marker = false;
    if(strcmp(c," ") != 0)
    {
        fp = fopen(c,"r");
        while(scanf(fp, "%s", line) != EOF)
        {
            char *tok = strtok(line," ");
            while(tok != NULL)
            {
                if(marker)
                {
                    marker = false;
                    name = tok;
                }
                if(strcmp(tok,"class") == 0)
                    marker = true;
                tok = strtok(NULL," ");
            }
        }
    }
}
