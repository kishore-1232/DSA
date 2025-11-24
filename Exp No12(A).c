#include <stdio.h>

#define SIZE 10

int hash_table[SIZE];

/* Initialize hash table */
void init()
{
    for (int i = 0; i < SIZE; i++)
        hash_table[i] = -1;
}

/* Hash function */
int hash(int key)
{
    return key % SIZE;
}

/* Insert using Linear Probing */
void insert(int key)
{
    int index = hash(key);

    if (hash_table[index] == -1)
    {
        hash_table[index] = key;
    }
    else
    {
        int i = (index + 1) % SIZE;

        while (i != index && hash_table[i] != -1)
        {
            i = (i + 1) % SIZE;
        }

        if (i == index)
            printf("Hash table is full. Cannot insert %d\n", key);
        else
            hash_table[i] = key;
    }
}

/* Search using Linear Probing */
int search(int key)
{
    int index = hash(key);

    if (hash_table[index] == key)
        return index;

    int i = (index + 1) % SIZE;

    while (i != index && hash_table[i] != -1)
    {
        if (hash_table[i] == key)
            return i;

        i = (i + 1) % SIZE;
    }

    return -1;
}

/* Display Hash Table */
void display()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("Index %d -> %d\n", i, hash_table[i]);
    }
}


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
