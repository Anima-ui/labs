#include <stdio.h>
#include <stdlib.h>

int getline3(char** string, size_t* size, FILE* stream)
{
    int position = 0;
    int symbol = 0;
    if (*size == 0 || *string == NULL)
    {
        *size = 10;
        *string = malloc(*size);
        if (*string == NULL) return -1;
    }
    while ((symbol = fgetc(stream)) != EOF && symbol != '\n')
    {
        if (position + 1 >= *size)
        {
            *size *= 2;
            char* temp_ptr = realloc(*string, *size);
            if (temp_ptr == NULL) return -1;
            *string = temp_ptr;
        }
        (*string)[position++] = (char)symbol;
    }
    if (position == 0 && symbol == EOF) return -1;
    (*string)[position] = '\0';
    return position;
}

int maxWordLength(const char* str) 
{
    int maxLen = 0, currentLen = 0;

    while (*str != '\0') 
    {
        if (*str == ' ' || *str == '\n' || *str == '\t') 
        {
            if (currentLen > maxLen) 
            {
                maxLen = currentLen;
            }
            currentLen = 0;
        }
        else 
        {
            currentLen++;
        }
        str++;
    }
    if (currentLen > maxLen) 
    {
        maxLen = currentLen;
    }
    return maxLen;
}

void sortByMaxWordLength(char** arr, int n)
{
    for (int i = 1; i < n; ++i)
    {
        char* key = arr[i];
        int keyMaxWordLen = maxWordLength(key);
        int j = i - 1;
        while (j >= 0 && maxWordLength(arr[j]) < keyMaxWordLen) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int zadan3()
{
    int n;
    while(1)
    {
        printf("input number of strings: ");
        if (!scanf_s("%d", &n))
        {
            while (getchar() != '\n');
            system("cls");
            continue;
        }
        getchar();
        break;
    }

    char** arr = (char**)malloc(n * sizeof(char*));
    if (arr == NULL) 
        return 1;

    for (int i = 0; i < n; ++i) {
        printf("input string %d: ", i + 1);

        size_t size = 100; 
        arr[i] = (char*)malloc(size * sizeof(char));
        if (arr[i] == NULL)
            return 1;
        getline3(&arr[i], &size, stdin);
    }

    printf("\nbefore sort:\n");
    for (int i = 0; i < n; ++i) 
    {
        printf("%s\n", arr[i]); 
    }

    sortByMaxWordLength(arr, n);

    printf("\nafter sort:\n");
    for (int i = 0; i < n; ++i) 
    {
        printf("%s\n", arr[i]);
    }
    for (int i = 0; i < n; ++i) 
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}