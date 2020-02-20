#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include <time.h>




void arg_fail ()
{
    printf("Please check your arguments Ex: ./executable -d int_value \n");
}

int main(int argc, char *argv[]) {

    int timing = 20;

    if((argc > 1) && (argc !=3)) {
        arg_fail();
        return 0;
    }

    if(argc == 3)
    {


        if(!strcmp(argv[1],"-d"))
        {
            //if(IsValidNumber(argv[2]))
            if(atoi(argv[2])!=0)
            {
                timing= atoi(argv[2]);
            }

            else
            {
                arg_fail();
                return 0;
            }

        }

        else
        {
            arg_fail();
            return 0;

        }
    }

    char line[50];

    char *word;
    int old = 0;
    int new = 0;
    const char delim[2] = " ";
    time_t t1,t2;
    t1 = time(NULL);
    t2 = time(NULL);
    while((t2-t1) < timing) {

        FILE* in_file = fopen("/proc/meminfo","r");
        if(!in_file) exit(-1);
        int line_num=0;
        while(fgets(line,50,in_file) != 0) {
            if(line_num == 2 ) { //|| line_num == 2) {
                word = strtok(line, delim);
                while(word != NULL) {
                    word = strtok(NULL, delim);
                    old = new;
                    new = atoi(word);
                    printf("Delta(MemAvailable) : %d\n",new-old);
                    break;
                }
                //parse_string(line);
                //printf("%s",line);
            }
            line_num++;
            if(line_num==3) break;
            t2 =time(NULL);
        }

        sleep(1);
        fclose(in_file);
    }
    return 0;
}
