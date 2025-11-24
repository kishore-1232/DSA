#include <stdio.h>

#define SIZE 10

int hash_table[SIZE];


void init()
{
    for (int i = 0; i < SIZE; i++)
        hash_table[i] = -1;
}


int hash(int key)
{
    return key % SIZE;
}


void insert(int key)
{
    int index = hash(key);

    if (hash_table[index] == -1)
    {
        hash_table[index] = key;
        return;
    }
    else
    {
        int i = 1;
        int newIndex;

        while (i < SIZE)
        {
            newIndex = (index + i * i) % SIZE;

            if (hash_table[newIndex] == -1)
            {
                hash_table[newIndex] = key;
                return;
            }
            i++;
        }
    }

    printf("Hash table is full! Cannot insert %d\n", key);
}


int search(int key)
{
    int index = hash(key);

    if (hash_table[index] == key)
        return index;

    int i = 1;
    int newIndex;

    while (i < SIZE)
    {
        newIndex = (index + i * i) % SIZE;

        if (hash_table[newIndex] == key)
            return newIndex;

        if (hash_table[newIndex] == -1)
            return -1;

        i++;
    }

    return -1;
}


void display()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("Index %d -> %d\n", i, hash_table[i]);
    }
}

/
int main()
{
    init();

    
    insert(12);
    insert(22);
    insert(32);
    insert(42);
    insert(52);

    display();

    int key = 32;
    int pos = search(key);

    if (pos != -1)
        printf("\nKey %d found at index %d\n", key, pos);
    else
        printf("\nKey %d not found\n", key);

    return 0;
}
