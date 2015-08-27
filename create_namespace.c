#define _GNU_SOURCE
#include <ctype.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


 /*******************************************\
 * Example code for Linux network namespaces *
 *                                           *
 * Author: Mike Wilson <geekinutah@gmail.com>*
 *                                           *
 \*******************************************/

static char child_stack[1048576];

void
usage(char *progname)
{
    printf("%s, a simple program to create or enter linux network namespaces\n",
            progname);
    printf("\n\nSimply invoke it and a shell will be created in a new network namespace.\n");
    printf("    Options:\n");
    printf("      -h display this message.\n");
}

int use_clone()
{
    printf("Welcome to your new network namespace!\n");
    printf("Here's the new output of 'ip link show'\n");
    system("/sbin/ip link show");
    printf("\n\n");
    system("/bin/bash");
    printf("Back to the old namespace.\n");
}

int
main (int argc, char **argv)
{
    int clone_flag = 0;
    char *nsfile = NULL;
    int index;
    int c;

    opterr = 0;

    while ((c = getopt (argc, argv, "h")) != -1)
        switch (c)
        {
            case 'h':
                usage(argv[0]);
                break;
        }

    if (getuid())
    {
        printf("User is not root!\n");
        exit(1);
    }
    printf("Switching to the new namespace, here's us running ip link show in the current namespace:\n");
    system("/sbin/ip link show");
    printf("\n\n");
    pid_t child_pid = clone(use_clone, child_stack+1048576, CLONE_NEWPID | CLONE_NEWNET | SIGCHLD, NULL);
    waitpid(child_pid, NULL, 0);

    return 0;
}
