#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareArr(char data1[], char data2[]);
void prosedur();

// variable global
char companyName[10][255]; // maks nama perusahaan 100 character
int companyWaste[10][4]; // tiga parameter limbah yang di awasi plus daya perusahaan
float aveComp[10][1];
int numCompany = 0;
char categorizeEmis[10][255];
char categorizeCompa[10][255];
char categorizeChar[10][1];

// struct for linked list
typedef struct data{
    char companyName[255];
    int companyWaste[4];
    float aveComp;
    char categorizeEmis[255];
    char categorizeCompa[255];
    char categorizeChar;
    struct data *ptrComp;
} comp;

// struct for binaryTree
typedef struct dataTree{
    char companyName[255];
    int companyWaste[4];
    float aveComp;
    char categorizeEmis[255];
    char categorizeCompa[255];
    char categorizeChar;
    struct dataTree *ptrR;
    struct dataTree *ptrL;
}compTree;

// initialization linked list
comp *currentPtr = NULL;
comp *ptrDepan = NULL;

compTree *topPtr = NULL;

void intiLinkedList()
{
    int i;

    for (i = 0; i < numCompany; i++)
    {
        comp *newComp = (comp*)malloc(sizeof(comp));
        newComp->aveComp = aveComp[i][0];
        newComp->categorizeChar = *categorizeChar[i];
        strcpy(newComp->categorizeCompa, categorizeCompa[i]);
        //newComp->categorizeCompa = categorizeCompa[i];
        strcpy(newComp->categorizeEmis, categorizeEmis[i]);
        //newComp->categorizeEmis = categorizeEmis[i];
        //newComp->companyName = companyName[i];
        strcpy(newComp->companyName, companyName[i]);
        newComp->companyWaste[0] = companyWaste[i][0];
        newComp->companyWaste[1] = companyWaste[i][1];
        newComp->companyWaste[2] = companyWaste[i][2];
        newComp->companyWaste[3] = companyWaste[i][3];
        newComp->categorizeChar = categorizeChar[i][0];
        newComp->ptrComp = NULL;
        if (currentPtr == NULL)
        {
            currentPtr = newComp;
            ptrDepan = newComp;
        }
        else
        {
            currentPtr->ptrComp = newComp;
            currentPtr = newComp;
        }
    }

}

void showLinkedData()
{
    comp *ptrPenje;
    ptrPenje = ptrDepan;
    int i;
    i = 0;

    while(ptrPenje != NULL)
    {
        printf("Company - %d : \n", (i+1));
        printf("\tName : %s", ptrPenje->companyName);
        printf("\tNO2 Composition : %d\n", ptrPenje->companyWaste[0]);
        printf("\tCO Composition : %d\n", ptrPenje->companyWaste[1]);
        printf("\tParticulate Composition : %d\n", ptrPenje->companyWaste[2]);
        printf("\tPower Company : %d\n", ptrPenje->companyWaste[3]);
        printf("\tCompany Category : %s\n", ptrPenje->categorizeCompa);
        printf("\tCompany Emission : %s\n", ptrPenje->categorizeEmis);
        printf("\tCompany Average Emission : %.3f\n", ptrPenje->aveComp);
        printf("\tCompany Category (ABCD) : %c\n", ptrPenje->categorizeChar);
        ptrPenje = ptrPenje->ptrComp;
        i = i + 1;
    }
}

void searchNameLinked(char masukkan[])
{
    comp *ptrPenje;
    int i, compare;
    ptrPenje = ptrDepan;
    i = 0;

    while (ptrPenje != NULL)
    {
        compare = compareArr(masukkan, ptrPenje->companyName);
        if (compare == 1)
        {
            printf("Company - %d : \n", (i+1));
            printf("\tName : %s", ptrPenje->companyName);
            printf("\tNO2 Composition : %d\n", ptrPenje->companyWaste[0]);
            printf("\tCO Composition : %d\n", ptrPenje->companyWaste[1]);
            printf("\tParticulate Composition : %d\n", ptrPenje->companyWaste[2]);
            printf("\tPower Company : %d\n", ptrPenje->companyWaste[3]);
            printf("\tCompany Category : %s\n", ptrPenje->categorizeCompa);
            printf("\tCompany Emission : %s\n", ptrPenje->categorizeEmis);
            printf("\tCompany Average Emission : %.3f\n", ptrPenje->aveComp);
            printf("\tCompany Category (ABCD) : %c\n", ptrPenje->categorizeChar);
            i = i + 1;
            break;
        }
        else
        {
            ptrPenje = ptrPenje->ptrComp;
        }
    }
}

void addDataLinked()
{
    comp *newComp = (comp*)malloc(sizeof(comp));
    newComp->ptrComp = NULL;
    printf("Name Company : ");
    scanf(" %255[^\n]s", newComp->companyName);
    strcat(newComp->companyName, "\n");
    printf("NO2 Composition : ");
    scanf("%d", &newComp->companyWaste[0]);
    printf("CO Composition : ");
    scanf("%d", &newComp->companyWaste[1]);
    printf("Particulate Composition : ");
    scanf("%d", &newComp->companyWaste[2]);
    printf("Power Company : ");
    scanf("%d", &newComp->companyWaste[3]);
    newComp->aveComp = (int) (newComp->companyWaste[0] + newComp->companyWaste[1] + newComp->companyWaste[2]) / 3;
    if (newComp->companyWaste[3] <= 570)
    {
        strcpy(newComp->categorizeCompa, "Industri Skala Kecil");
        if (newComp->companyWaste[0] <= 700 && newComp->companyWaste[1] <= 400 && newComp->companyWaste[2] <= 75)
        {
            strcpy(newComp->categorizeEmis, "Industri Lulus Uji Emisi");
        }
        else
        {
            strcpy(newComp->categorizeEmis, "Industri Tidak Lulus Uji Emisi");
        }

        // categprize rate value of company
        if (newComp->companyWaste[2] <= 20)
        {
            newComp->categorizeChar = 'A';
        }
        else if (newComp->companyWaste[2] <= 45 && newComp->companyWaste[2] >= 21)
        {
            newComp->categorizeChar = 'B';
        }
        else if (newComp->companyWaste[2] >= 46 && newComp->companyWaste[2] <= 75)
        {
            newComp->categorizeChar = 'C';
        }
        else if (newComp->companyWaste[2] >= 76)
        {
            newComp->categorizeChar = 'D';
        }
    }
    else
    {
        strcpy(newComp->categorizeCompa, "Industri Skala Besar");
        if (newComp->companyWaste[0] <= 1000 && newComp->companyWaste[1] <= 600 && newComp->companyWaste[2] <= 150)
        {
            strcpy(newComp->categorizeEmis, "Industri Lulus Uji Emisi");
        }
        else
        {
            strcpy(newComp->categorizeEmis, "Industri Tidak Lulus Uji Emisi");
        }

        // categprize rate value of company
        if (newComp->companyWaste[2] <= 50)
        {
            newComp->categorizeChar = 'A';
        }
        else if (newComp->companyWaste[2] <= 100 && newComp->companyWaste[2] >= 51)
        {
            newComp->categorizeChar = 'B';
        }
        else if (newComp->companyWaste[2] > 100 && newComp->companyWaste[2] <= 150)
        {
            newComp->categorizeChar = 'C';
        }
        else if (newComp->companyWaste[2] > 150)
        {
            newComp->categorizeChar = 'D';
        }
    }
    currentPtr->ptrComp = newComp;
    currentPtr = newComp;
}

void hapusCompany(char dihapus[])
{
    comp *ptrPenjelajah;
    comp *ptrSebPenjelajah;
    ptrSebPenjelajah = ptrDepan;
    ptrPenjelajah = ptrSebPenjelajah;

    while(ptrPenjelajah != NULL)
    {
        int searc = compareArr(dihapus, ptrPenjelajah->companyName);
        if (searc == 1)
        {
           if (ptrPenjelajah == ptrDepan)
            {
                ptrDepan = ptrPenjelajah->ptrComp;
                ptrPenjelajah->ptrComp = NULL;
                free(ptrPenjelajah);
            }
            else if (ptrPenjelajah == currentPtr)
            {
                currentPtr = ptrSebPenjelajah;
                currentPtr->ptrComp = NULL;
                free(ptrPenjelajah);
                free(ptrSebPenjelajah);
            }
            else
            {
                ptrSebPenjelajah->ptrComp = ptrPenjelajah->ptrComp;
                ptrPenjelajah->ptrComp= NULL;
                free(ptrPenjelajah);
                free(ptrSebPenjelajah);
            }
        }
        ptrSebPenjelajah = ptrPenjelajah;
        ptrPenjelajah = ptrPenjelajah->ptrComp;
    }

}

void initBinTree()
{
    int i;

    for (i = 0; i < numCompany; i++)
    {
        compTree *newComp = (compTree*)malloc(sizeof(compTree));
        newComp->aveComp = aveComp[i][0];
        newComp->categorizeChar = *categorizeChar[i];
        strcpy(newComp->categorizeCompa, categorizeCompa[i]);
        //newComp->categorizeCompa = categorizeCompa[i];
        strcpy(newComp->categorizeEmis, categorizeEmis[i]);
        //newComp->categorizeEmis = categorizeEmis[i];
        //newComp->companyName = companyName[i];
        strcpy(newComp->companyName, companyName[i]);
        newComp->companyWaste[0] = companyWaste[i][0];
        newComp->companyWaste[1] = companyWaste[i][1];
        newComp->companyWaste[2] = companyWaste[i][2];
        newComp->companyWaste[3] = companyWaste[i][3];
        newComp->categorizeChar = categorizeChar[i][0];
        newComp->ptrL = NULL;
        newComp->ptrR = NULL;
        if (topPtr == NULL)
        {
            topPtr = newComp;
        }
        else
        {
            compTree *ptrPenje = topPtr;
            while(ptrPenje != NULL)
            {
                if (newComp->aveComp > ptrPenje->aveComp)
                {
                    if(ptrPenje->ptrR != NULL)
                    {
                        ptrPenje = ptrPenje->ptrR;
                    }
                    else
                    {
                        ptrPenje->ptrR = newComp;
                        break;
                    }
                }
                else
                {
                    if(ptrPenje->ptrL != NULL)
                    {
                        ptrPenje = ptrPenje->ptrL;
                    }
                    else
                    {
                        ptrPenje->ptrL = newComp;
                        break;
                    }
                }
            }
        }
    }
}

void inOrder(compTree *treePtr);

void showBinTree()
{
    compTree *ptrPenje;
    ptrPenje = topPtr;
    inOrder(ptrPenje);
}

void searcAveBinTree(float searchData)
{
    compTree *ptrPenje;
    ptrPenje = topPtr;
    while(1)
    {
        printf("Dicari : %f\n", searchData);
        printf("Database : %f\n", ptrPenje->aveComp);
        if(ptrPenje->aveComp > searchData)
        {
            ptrPenje = ptrPenje->ptrR;
        }
        else if(ptrPenje->aveComp < searchData)
        {
            ptrPenje = ptrPenje->ptrL;
        }
        else
        {
            printf("\tName : %s", ptrPenje->companyName);
            printf("\tNO2 Composition : %d\n", ptrPenje->companyWaste[0]);
            printf("\tCO Composition : %d\n", ptrPenje->companyWaste[1]);
            printf("\tParticulate Composition : %d\n", ptrPenje->companyWaste[2]);
            printf("\tPower Company : %d\n", ptrPenje->companyWaste[3]);
            printf("\tCompany Category : %s\n", ptrPenje->categorizeCompa);
            printf("\tCompany Emission : %s\n", ptrPenje->categorizeEmis);
            printf("\tCompany Average Emission : %.3f\n", ptrPenje->aveComp);
            printf("\tCompany Category (ABCD) : %c\n", ptrPenje->categorizeChar);
            printf("\n\n");
            break;
        }
    }
}

void inOrder(compTree *treePtr)
{
    if (treePtr != NULL)
    {
        inOrder(treePtr->ptrL);
        printf("\tName : %s", treePtr->companyName);
        printf("\tNO2 Composition : %d\n", treePtr->companyWaste[0]);
        printf("\tCO Composition : %d\n", treePtr->companyWaste[1]);
        printf("\tParticulate Composition : %d\n", treePtr->companyWaste[2]);
        printf("\tPower Company : %d\n", treePtr->companyWaste[3]);
        printf("\tCompany Category : %s\n", treePtr->categorizeCompa);
        printf("\tCompany Emission : %s\n", treePtr->categorizeEmis);
        printf("\tCompany Average Emission : %.3f\n", treePtr->aveComp);
        printf("\tCompany Category (ABCD) : %c\n", treePtr->categorizeChar);
        printf("\n\n");
        inOrder(treePtr->ptrR);
    }
}


// diatas tambahan code baru
// tambahana code baru diatas
//
/*
    code baru diatas

          _   _                  _____          _
         | \ | |                / ____|        | |
         |  \| | _____      __ | |     ___   __| | ___
         | . ` |/ _ \ \ /\ / / | |    / _ \ / _` |/ _ \
         | |\  |  __/\ V  V /  | |___| (_) | (_| |  __/
         |_| \_|\___| \_/\_/    \_____\___/ \__,_|\___|


                  _____  _         _
                 |  __ \(_)       | |
                 | |  | |_    __ _| |_ __ _ ___
                 | |  | | |  / _` | __/ _` / __|
                 | |__| | | | (_| | || (_| \__ \
                 |_____/|_|  \__,_|\__\__,_|___/



*/

// moving data from txt file to array in program
void printCompany()
{
    FILE *ptrFile;
    char nameComp[255];
    int num, i;


    ptrFile = fopen("comp.txt", "r");

    i = 0;
    while(fgets(companyName[i], 255, (FILE*)ptrFile) != NULL)
    {
        fgets(nameComp, 255, (FILE*)ptrFile);
        companyWaste[i][0] = atoi(nameComp);

        fgets(nameComp, 255, (FILE*)ptrFile);
        companyWaste[i][1] = atoi(nameComp);

        fgets(nameComp, 255, (FILE*)ptrFile);
        companyWaste[i][2] = atoi(nameComp);

        fgets(nameComp, 255, (FILE*)ptrFile);
        companyWaste[i][3] = atoi(nameComp);

        numCompany++;
        i++;
    }
}

// categorize company based their emission and power
void categorizeComp()
{
    int i;

    printf("\n");
    for (i = 0; i < numCompany; i++)
    {
        if (companyWaste[i][3] <= 570)
        {
            strcpy(categorizeCompa[i], "Industri Skala Kecil");
            if (companyWaste[i][0] <= 700 && companyWaste[i][1] <= 400 && companyWaste[i][2] <= 75)
            {
                strcpy(categorizeEmis[i], "Industri Lulus Uji Emisi");
            }
            else
            {
                strcpy(categorizeEmis[i], "Industri Tidak Lulus Uji Emisi");
            }

            // categprize rate value of company
            if (companyWaste[i][2] <= 20)
            {
                categorizeChar[i][0] = 'A';
            }
            else if (companyWaste[i][2] <= 45 && companyWaste[i][2] >= 21)
            {
                categorizeChar[i][0] = 'B';
            }
            else if (companyWaste[i][2] >= 46 && companyWaste[i][2] <= 75)
            {
                categorizeChar[i][0] = 'C';
            }
            else if (companyWaste[i][2] >= 76)
            {
                categorizeChar[i][0] = 'D';
            }


        }
        else
        {
            strcpy(categorizeCompa[i], "Industri Sekala Besar");
            if (companyWaste[i][0] <= 1000 && companyWaste[i][1] <= 600 && companyWaste[i][2] <= 150)
            {
                strcpy(categorizeEmis[i], "Industri Lulus Uji Emisi");
            }
            else
            {
                strcpy(categorizeEmis[i], "Industri Tidak Lulus Uji Emisi");
            }

            // categprize rate value of company
            if (companyWaste[i][2] <= 50)
            {
                categorizeChar[i][0] = 'A';
            }
            else if (companyWaste[i][2] <= 100 && companyWaste[i][2] >= 51)
            {
                categorizeChar[i][0] = 'B';
            }
            else if (companyWaste[i][2] > 100 && companyWaste[i][2] <= 150)
            {
                categorizeChar[i][0] = 'C';
            }
            else if (companyWaste[i][2] > 150)
            {
                categorizeChar[i][0] = 'D';
            }

        }
    }

}

// view all company, with parameter
void viewAll()
{
    int i;

    for (i = 0; i < numCompany; i++)
    {
        printf("Company - %d : \n", (i+1));
        printf("\tName : %s", companyName[i]);
        printf("\tNO2 Composition : %d\n", companyWaste[i][0]);
        printf("\tCO Composition : %d\n", companyWaste[i][1]);
        printf("\tParticulate Composition : %d\n", companyWaste[i][2]);
        printf("\tPower Company : %d\n", companyWaste[i][3]);
        printf("\tCompany Category : %s\n", categorizeCompa[i]);
        printf("\tCompany Emission : %s\n", categorizeEmis[i]);
        printf("\tCompany Average Emission : %.3f\n", aveComp[i][0]);
        printf("\tCompany Category (ABCD) : %c\n", categorizeChar[i][0]);
    }

}

// rating nilai dari tiap-tiap perusahaan
void rateComp()
{
    int i;
    float aver;

    for (i = 0; i < numCompany; i++)
    {
        aver = (int) (companyWaste[i][0] + companyWaste[i][1] + companyWaste[i][2]) / 3;
        aveComp[i][0] = aver;
    }

}

// sorting ascent company based on average emission using bubble sort
void sortAscentComp()
{
    int i, j;
    char transCompName[255];
    char transCatComp[255];
    char transEmisComp[255];
    int transNO2, transCO, transPartciulate, transPower;
    float transAvr;

    for (i = 0; i < numCompany - 1; i++)
    {
        for (j = i+1; j < numCompany; j++)
        {
            if (aveComp[i][0] > aveComp[j][0])
            {
                // change array average
                transAvr = aveComp[i][0];
                aveComp[i][0] = aveComp[j][0];
                aveComp[j][0] = transAvr;

                // change array transCompName
                strcpy(transCompName, companyName[i]);
                strcpy(companyName[i], companyName[j]);
                strcpy(companyName[j], transCompName);

                // change array company parameter
                transNO2 = companyWaste[i][0];
                transCO = companyWaste[i][1];
                transPartciulate = companyWaste[i][2];
                transPower = companyWaste[i][3];
                companyWaste[i][0] = companyWaste[j][0];
                companyWaste[i][1] = companyWaste[j][1];
                companyWaste[i][2] = companyWaste[j][2];
                companyWaste[i][3] = companyWaste[j][3];
                companyWaste[j][0] = transNO2;
                companyWaste[j][1] = transCO;
                companyWaste[j][2] = transPartciulate;
                companyWaste[j][3] = transPower;

                // change catgorize company
                strcpy(transCatComp, categorizeCompa[i]);
                strcpy(categorizeCompa[i], categorizeCompa[j]);
                strcpy(categorizeCompa[j], transCatComp);

                // change categorize emission
                strcpy(transEmisComp, categorizeEmis[i]);
                strcpy(categorizeEmis[i], categorizeEmis[j]);
                strcpy(categorizeEmis[j], transEmisComp);

            }
        }
    }

}

// sorting descent
void sortDescentComp()
{
    int i, j;
    char transCompName[255];
    char transCatComp[255];
    char transEmisComp[255];
    int transNO2, transCO, transPartciulate, transPower;
    float transAvr;

    for (i = 0; i < numCompany - 1; i++)
    {
        for (j = i+1; j < numCompany; j++)
        {
            if (aveComp[i][0] < aveComp[j][0])
            {
                // change array average
                transAvr = aveComp[i][0];
                aveComp[i][0] = aveComp[j][0];
                aveComp[j][0] = transAvr;

                // change array transCompName
                strcpy(transCompName, companyName[i]);
                strcpy(companyName[i], companyName[j]);
                strcpy(companyName[j], transCompName);

                // change array company parameter
                transNO2 = companyWaste[i][0];
                transCO = companyWaste[i][1];
                transPartciulate = companyWaste[i][2];
                transPower = companyWaste[i][3];
                companyWaste[i][0] = companyWaste[j][0];
                companyWaste[i][1] = companyWaste[j][1];
                companyWaste[i][2] = companyWaste[j][2];
                companyWaste[i][3] = companyWaste[j][3];
                companyWaste[j][0] = transNO2;
                companyWaste[j][1] = transCO;
                companyWaste[j][2] = transPartciulate;
                companyWaste[j][3] = transPower;

                // change catgorize company
                strcpy(transCatComp, categorizeCompa[i]);
                strcpy(categorizeCompa[i], categorizeCompa[j]);
                strcpy(categorizeCompa[j], transCatComp);

                // change categorize emission
                strcpy(transEmisComp, categorizeEmis[i]);
                strcpy(categorizeEmis[i], categorizeEmis[j]);
                strcpy(categorizeEmis[j], transEmisComp);
            }
        }
    }

}

// searching by name
void searchName(char masukkan[])
{
    int i, compare;
    int found = 0;


    for (i = 0; i < numCompany; i++)
    {
        compare = compareArr(masukkan, companyName[i]);
        if (compare == 1)
        {
            printf("Perusahaan : \n");
            printf("\tName : %s", companyName[i]);
            printf("\tNO2 Composition : %d\n", companyWaste[i][0]);
            printf("\tCO Composition : %d\n", companyWaste[i][1]);
            printf("\tParticulate Composition : %d\n", companyWaste[i][2]);
            printf("\tPower Company : %d\n", companyWaste[i][3]);
            printf("\tCompany Category : %s\n", categorizeCompa[i]);
            printf("\tCompany Emission : %s\n", categorizeEmis[i]);
            printf("\tCompany Average Emission : %.3f\n", aveComp[i][0]);
            printf("\tCompany Category (ABCD) : %c\n", categorizeChar[i][0]);
        }
    }
}

// searching by rating company
void searchValue(char dicari)
{
    int asciiData, asciiData2, i;
    int ind = 1;
    asciiData = dicari;
    if (asciiData >= 65 && asciiData <= 90)
        asciiData += 32;

    for (i = 0; i < numCompany; i++)
    {
        asciiData2 = categorizeChar[i][0];
        if (asciiData2 >= 65 && asciiData2 <= 90)
            asciiData2 += 32;

        if (asciiData2 == asciiData)
        {
            printf("Perusahaan -%d : \n", ind);
            printf("\tName : %s", companyName[i]);
            printf("\tNO2 Composition : %d\n", companyWaste[i][0]);
            printf("\tCO Composition : %d\n", companyWaste[i][1]);
            printf("\tParticulate Composition : %d\n", companyWaste[i][2]);
            printf("\tPower Company : %d\n", companyWaste[i][3]);
            printf("\tCompany Category : %s\n", categorizeCompa[i]);
            printf("\tCompany Emission : %s\n", categorizeEmis[i]);
            printf("\tCompany Average Emission : %.3f\n", aveComp[i][0]);
            printf("\tCompany Category (ABCD) : %c\n", categorizeChar[i][0]);
            ind++;
        }
    }

}

// comparing to array without case sensitiv
int compareArr(char data1[], char data2[])
{
    int jumData;
    for (jumData = 0; data1[jumData] != '\0'; ++jumData);
    int i;
    int res = 1;
    int asciiData1, asciiData2;

    for (i = 0; i < jumData; i++)
    {
        asciiData1 = data1[i];
        asciiData2 = data2[i];
        if (asciiData1 >= 65 && asciiData1 <= 90)
            asciiData1 += 32;

        if (asciiData2 >= 65 && asciiData2 <= 90)
            asciiData2 += 32;

        if (asciiData1 != asciiData2)
        {
            res = 0;
            break;
        }
    }

    return res;

}

void prosedur()
{
    printf("\t\t====== PENJELASAN TATA CARA DAN PROSEDUR EMISSIONCHECKED PROGRAM ======\n\n\n");
	printf("Pada program EmissionChecked terdapat 5 menu pilihan yaitu: ");
	printf("\n1. Tampilkan Data Perusahaan \n2. Urutkan Data Perusahaan \n3. Cari Data Perusahaan \n4. Prosedur Penggunaan Aplikasi \n5. Exit Program");
	printf("\n\n>>> Menu 1 : \"Tampilkan Data Perusahaan\" \nMenu ini digunakan untuk menampilkan data perusahaan yang telah dimasukkan dalam txt yang dalam hal ini inputnya berasal dari sensor.");
	printf("\n> Cara Penggunaan: \nMasukkan angka 1 pada Menu pilihan -> Output akan mengeluarkan Data");
	printf("\n\n>>> Menu 2 : \"Urutkan Data Perusahaan\" \nMenu ini digunakan untuk mengurutkan perusahaan sesuai dengan tingkat emisi yang tercatat dengan pilihan ascending dan Descending");
	printf("\n> Cara Penggunaan: \nMasukkan angka 2 pada Menu pilihan -> Masukkan angka 1 untuk Ascending dan angka 2 untuk Descending -> Output akan mengeluarkan data sekaligus dengan data-data input gas yang dimasukkan");
	printf("\n\n>>> Menu 3 : \"Cari Data Perusahaan\" \nMenu ini digunakan untuk mencari data perusahaan berdasarkan nama perusahaan atau rating");
	printf("\n> Cara Penggunaan: \nMasukkan angka 3 pada Menu pilihan -> Masukkan angka 1 untuk berdasarkan nama perusahaan dan angka 2 untuk berdasarkan rating \n-> Apabila memilih 1 maka user akan diminta untuk memasukkan nama perusahaan, apabila memilih 2 maka user akan diminta untuk memasukkan a/b/c/d (A memiliki tingkat emisi yang paling baik)");
	printf("\n\n>>> Menu 4 : \"Prosedur Penggunaan Aplikasi\" \nMenu ini digunakan untuk menampilkan prosedur/tata cara menggunakan program ini.");
	printf("\n> Cara Penggunaan: \nMasukkan angka 4 pada Menu pilihan -> Program akan menampilkan seluruh prosedur dan penjelasan program ini");
	printf("\n\n>>> Menu 5 : \"Exit Program\" \nMenu ini digunakan untuk mengakhiri program EMISSIONCHECKED");
	printf("\n> Cara Penggunaan: \nMasukkan angka 5 pada Menu pilihan -> Program akan keluar\n");
}

#endif // FUNC_H_INCLUDED
