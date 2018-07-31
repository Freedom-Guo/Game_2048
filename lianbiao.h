#ifndef LIANBIAO
#define LIANBIAO

#include <stdio.h>
#include <stdlib.h>
#include <QString>

typedef struct grade
{
    int score;
    int arg[4][4];
    struct grade *prior;
    struct grade *next;
} scores;

typedef struct user
{
    QString name;
    int rank;
    int best;
    scores *head_score;
    struct user *next;
} players;

#endif // LIANBIAO
