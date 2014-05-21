 #include <stdio.h>
 #include <string.h>

void printhelp()
{
    puts("Usage:");
    puts("serializer [-options] <FILE>\n");
    puts("Options:");
    puts("-f <FILENAME>.json -> Print to file");
    puts("-p -> Print to console");
}

int main(int argc, char **argv)
{
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
