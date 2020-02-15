#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include <time.h> 
//aa123bb456cc
void parse_string(char *p){
    while (*p) { // While there are more characters to process...
    if ( isdigit(*p)){
        // Found a number
        long val = strtol(p, &p, 10); // Read number
        printf("%ld\n", val); // and print it.
    } else {
        // Otherwise, move on to the next character.
        p++;
    }
}
}

int main(int argc, char *argv[]){

  if(argc >3) {
      printf("Please check your arguments\n");
      return 0;
  }

  int runs = 20;
  if(argc == 3) 
  {
      if(!strcmp(argv[1],"-d"))
      {
          runs= atoi(argv[2]);
      }
  }
  
  char line[50];
 
int mema=0;
char temp;
time_t t1,t2;
t1 = time(NULL);
t2 = time(NULL);
while((t2-t1) <= runs){

    FILE* in_file = fopen("/proc/meminfo","r");
    if(!in_file) exit(-1);
    int line_num=0;
    while(fgets(line,50,in_file) != 0){
    if(line_num == 1 || line_num == 2)
    //parse_string(line);
    printf("%s",line);
    line_num++;
    if(line_num==3) break;
    t2 =time(NULL);
  }
  
  //sleep(1);
  //runs--;
  fclose(in_file);
}
  
  return 0;
}
