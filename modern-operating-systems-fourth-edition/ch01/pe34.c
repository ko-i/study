// 2020-11-17 created by Akson

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TRUE 1
#define COMLEN 50
#define PARANUM 50
#define PARALEN 50

void type_prompt();
int read_command(char * command, char *parameters[]);

int main(int argc, char const *argv[])
{
    char * command;
    char * parameters[PARALEN];
    int para_num;

    for(int i = 0; i < 5; i++)
    {
        type_prompt();
        para_num = read_command(command, parameters);
        int status;

        if(fork() != 0)
        {
            printf("I am father%d.\n", i);
            waitpid(-1, &status, 0);
            printf("I(father%d) finished!\n", i);
        }
        else
        {
            printf("I am child%d.\n", i);
            execve(command, parameters, 0);
            printf("I(child%d) finished!\n", i);
        }
    }

    free(command);
    for(int i = 0; i < para_num; i++)
    {
        free(parameters[i]);
    }
    
    return 0;
}

void type_prompt()
{
    printf("Please enter a filename and patameters:\n");
}

int read_command(char * command, char **parameters)
{
    command = (char *)malloc(COMLEN * sizeof(char));
    parameters = (char **)malloc(1 * sizeof(char*));
    parameters[0] = (char*)malloc(PARALEN * sizeof(char));

    scanf("%s %s", command, parameters[0]);

    printf("Get %s and %s success", command, parameters[0]);

    return 1;
}
