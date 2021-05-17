#include <stdio.h>
#include <stdlib.h>
#define NP 3
#define NA 4

void TypeConsumption(int [][NA]);
void BuildingsConsuption(int [][NA], int []);
int TotalConsumption(int []);
void pcConsResident(int [][NA], int, float [][NA]);
void Overview(int [], int);
void perApartment(float [][NA]);

int main()
{

    int condC[NP][NA], buildingC[NP], totalC;
    float pcResident[NP][NA];

    TypeConsumption(condC);
    BuildingsConsuption(condC, buildingC);
    totalC = TotalConsumption(buildingC);
    pcConsResident(condC, totalC, pcResident);
    Overview(buildingC, totalC);
    perApartment(pcResident);

    return 0;

}

void TypeConsumption(int condC[][NA])
{
    int i, j;
    for (i=0; i < NP; i++)
    {
        for (j=0; j < NA; j++)
        {
            printf("Digite o consumo do apartamento %i do predio %c: ", j+1, i+65);
            scanf("%i", &condC[i][j]);
        }
    }
}

void BuildingsConsuption(int condC[][NA], int buildingC[])
{
    int i, j;
    for (i=0; i < NP; i++)
    {
        buildingC[i] = 0;
        for (j=0; j < NA; j++)
        {
            buildingC[i] += condC[i][j];
        }
    }
}

int TotalConsumption(int buildingC[])
{
    int i, s;
    s = 0;
    for (i=0; i < NP; i++)
    {
        s += buildingC[i];
    }
    return s;
}

void pcConsResident(int condC[][NA], int totalC, float pcResident[][NA])
{
    int i, j;
    for (i=0; i < NP; i++)
    {
        for (j=0; j < NA; j++)
        {
            pcResident[i][j] = (float) condC[i][j] / totalC * 100;
        }
    }
}

void Overview(int buildingC[], int totalC)
{
    int i;
    printf("\n");
    for (i=0; i<NP; i++)
    {
        printf("Building %c: %i kWh\n", i+65, buildingC[i]);
    }
    printf("\nTotal Consumption: %i kWh", totalC);
}

void perApartment(float pcResident[][NA])
{
    int i, j, max_val, max_idx;
    printf("\n\n");
    for (i=0; i < NP; i++)
    {
        max_val = 0;
        max_idx = 0;
        for (j=0; j < NA; j++)
        {
            if (pcResident[i][j] > max_val)
            {
                max_val = pcResident[i][j];
                max_idx = j;
            }
        }
        for (j=0; j < NA; j++)
        {
            if (j == max_idx)
            {
                printf("%.2f%%!\t", pcResident[i][j]);
            }
            else
            {
                printf("%.2f%%\t", pcResident[i][j]);
            }
        }
        printf("\n");
    }
}


