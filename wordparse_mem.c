#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{

    time_t t1, t2;
    int timing = 10;
    char temp[50];
    char word[15];
    char word2[15];
    int old = 0, new = 0;

    t1 = time(NULL);
    t2 = time(NULL);

    while ((t2 - t1) < timing)
    {
        FILE *fp = fopen("/proc/meminfo", "r");
        int line_num = 0;

        if (fp == NULL)
        {
            printf("Error opening the file\n");
            exit(1);
        }

        while (fscanf(fp, "%s %s %*s", word, word2) == 2)
        {
            if (line_num == 1)
            {   //Change this line number to get appropriate data
                new = atoi(word2);
                printf("%s %d, delta : %d\n", word, new, new - old);
                old = new;
                break;
            }
            line_num++;
        }

        t2 = time(NULL);
        fclose(fp);
        sleep(1);
    }
    return 0;
}
