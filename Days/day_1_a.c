#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "days.hpp"

int day_1_a()
{
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("../Inputs/day1.txt", "r");
    if (fp == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1)
    {
        printf("Retrieved line of length %zu:\n", read);
        printf("Line:%s", line);
        printf("Len:%s");
    }

    fclose(fp);
    if (line)
    {
        free(line);
    }

    exit(EXIT_SUCCESS);
}