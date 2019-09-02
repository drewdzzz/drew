#include <stdio.h>
#define INPUTFILE_NAME "onegin.txt"
#define OUTPUTFILE_NAME "oneginOut.txt"
#define SIZE 50
#define STRING_LIMIT 50
//#define DEBUG

//{----------------------------------------------------------------------------
//! @brief �������� ������� ����������
//!
//! @param sortingArray ������, ������� ������������ ����������
//!
//! @param left ����� ����� ������� ��������� ����������
//!
//! @param right ����� ������ ������� ��������� ����������
//!
//!
//}----------------------------------------------------------------------------
void quickSort ( char sortingArray[SIZE][STRING_LIMIT], int left, int right);

//{----------------------------------------------------------------------------
//!
//! @brief ������� ��������� ��������� ����� � ������
//!
//! @param fp �����, �� �������� �������������� ����
//!
//! @param poem ��������� ������ ���� char, � ������� ����� �������������� ����
//!
//! @param [out] *sizeofpoem ��������, � ������� ��������� ������ ���-�� ����� (�������������� ���������� STRING_LIMIT)
//!
//! @par ��� �����:
//! @code
//! readInput ( fp, poem, &sizeofpoem);
//! @endcode
//}----------------------------------------------------------------------------

void readInput ( FILE* fp, char poem[SIZE][STRING_LIMIT], int* sizeofpoem );
//int bubbleSort ( char poem [SIZE][STRING_LIMIT], int );
int main ()
{
    FILE* fp;
    if ( !(fp = fopen ( INPUTFILE_NAME, "r")) )
    {
        printf ("Input file is not open");
        return 1;
    }
    int sizeofpoem = STRING_LIMIT;
    char poem[SIZE][STRING_LIMIT];
    readInput ( fp, poem, &sizeofpoem );

    #ifdef DEBUG
    printf ("Reading complete!\n");
            for ( int i = 0; i < sizeofpoem; i++)
            puts(poem[i]);
    #endif

    quickSort ( poem, 0, sizeofpoem-1);
    //bubbleSort ( poem, sizeofpoem);

    #ifdef DEBUG
    printf ("Poem Sorted!");
    #endif
    fclose(fp);
    if ( !(fp = fopen ( OUTPUTFILE_NAME, "w")) )
    {
        printf ("Output file is not open");
        return 1;
    }
    for (int i = 0; i < sizeofpoem; i++)
            fputs ( poem[i], fp);

    return 0;
}

void readInput ( FILE* fp, char inputArray[SIZE][STRING_LIMIT], int* sizeofpoem)
{
    for (int i = 0; i < *sizeofpoem; i++)
        if (!feof (fp))
            fgets ( inputArray[i], SIZE, fp);
        else
        {
            *sizeofpoem = i;
            return;
        }
}




void quickSort ( char sortingArray[SIZE][STRING_LIMIT], int left, int right)
{

    void swap ( char [SIZE][STRING_LIMIT], int, int);
    int strcmp (char*, char*);

    char* mid = sortingArray[ (left + right) / 2];

    int l = left;
    int r = right;
    while ( right > left )
    {
        while ( strcmp ( sortingArray[left], mid) < 0 )    left++;
        while ( strcmp ( sortingArray[right] , mid ) > 0 ) right--;
        if (left < right) swap ( sortingArray, left, right);
        left++;
        right--;
    }


    if ( l < right ) quickSort( sortingArray, l, right);
    if ( r > left  ) quickSort( sortingArray, left, r);
}

/*
int bubbleSort( char poem [SIZE][STRING_LIMIT], int arraySize)
{
    int strcmp (char*, char*);
    void swap ( char [SIZE][STRING_LIMIT], int, int);
    for (int i = 0; i < arraySize; i++)
        for (int j = i; j < arraySize; j++)
            if ( strcmp ( poem[i], poem[j]) > 0 )
            {
                swap (poem, i, j);
                #ifdef DEBUG
                    printf("SWAPPED!");
                #endif
            }
}
*/



//{----------------------------------------------------------------------------
//! @brief ���������� ����� (�� ������������ � ��������)
//!
//! @return ���������� ������� ����� ����� ������� ����������� ������� ��������� ����� (0 ���� �����, >0 ���� a>b, <0 ���� a<b)
//!
//!
//!
//!
//}----------------------------------------------------------------------------

int strcmp ( char* a, char* b )
{
    #ifdef DEBUG
        printf ("IS COMPARING...\n");
    #endif
    int i = 0;
    char* string1 = a;
    char* string2 = b;
    while ( string1[i] != '\0' && string2[i] != '\0' )
    {
        if ( string1[i] >= 'A' && string1[i] <= 'Z' ) string1 += 'a' - 'A';
        if ( string2[i] >= 'A' && string2[i] <= 'Z' ) string2 += 'a' - 'A';
        if ( string1[i] != string2[i] ) return string1[i] - string2[i];
        i++;
    }

    return string1[i] - string2[i];
}


//{----------------------------------------------------------------------------
//!
//! @brief ������� �������� ������� ��� �������� � ������� char
//!
//! @param array ������, � ������� �������� ��������
//! @param a ������ ������� ��������
//! @param b ������ ������� ��������
//!
//}----------------------------------------------------------------------------

void swap (char array[SIZE][STRING_LIMIT], int a, int b)
{
    #ifdef DEBUG
        printf("IS SWAPPING...\n");
    #endif
    for (int i = 0; i < SIZE; i++)
    {
        char temp = array[a][i];
        array[a][i] = array[b][i];
        array[b][i] = temp;
    }
}

