#include <stdio.h>
#include <stdlib.h>

struct set {
  int key;
  int data;
};

struct set *array;
int capacity = 10;
int size = 0;

int hashFunction(int key)
{
  return key % capacity;
}

void init_array()
 {
  array = (struct set *)malloc(capacity * sizeof(struct set));
  for (int i = 0; i < capacity; i++)
    {
    array[i].key = 0;
    array[i].data = 0;
  }
}

void insert(int key, int data)
 {
  int index = hashFunction(key);
  if (array[index].data == 0)
    {
    array[index].key = key;
    array[index].data = data;
    size++;
    printf("\nKey (%d) has been inserted\n", key);
  } else {
    int i = (index + 1) % capacity;  // Start linear probing from next slot
    while (i != index)
     {
      if (array[i].data == 0)
      {
        array[i].key = key;
        array[i].data = data;
        size++;
        printf("\nKey (%d) has been inserted\n", key);
        return;
      }
      i = (i + 1) % capacity;  // Move to the next slot
    }
    printf("\nCollision occurred, no available slots to insert the key (%d)\n", key);
  }
}

void remove_element(int key)
 {
  int index = hashFunction(key);
  if (array[index].data == 0)
    {
    printf("\nThis key does not exist\n");
  }
  else
    {
    int i = index;
    while (array[i].key != key)
    {
      i = (i + 1) % capacity;  // Search for the key using linear probing
      if (i == index)
      {
        printf("\nThis key does not exist\n");
        return;
      }
    }
    array[i].key = 0;
    array[i].data = 0;
    size--;
    printf("\nKey (%d) has been removed\n", key);
  }
}

void display()
{
  for (int i = 0; i < capacity; i++)
    {
    if (array[i].data == 0)
    {
      printf("\narray[%d]: /", i);
    }
  else
    {
      printf("\nkey: %d array[%d]: %d", array[i].key, i, array[i].data);
    }
  }
  printf("\n");
}

int size_of_hashtable()
{
  return size;
}

int main()
 {
  int choice, key, data, n;
  int c = 0;
  init_array();

  do {
    printf("1. Insert item in the Hash Table\n"
           "2. Remove item from the Hash Table\n"
           "3. Check the size of Hash Table\n"
           "4. Display the Hash Table\n"
           "Please enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
     {
      case 1:
        printf("Enter key: ");
        scanf("%d", &key);
        printf("Enter data: ");
        scanf("%d", &data);
        insert(key, data);
        break;

      case 2:
        printf("Enter the key to delete: ");
        scanf("%d", &key);
        remove_element(key);
        break;

      case 3:
        n = size_of_hashtable();
        printf("Size of Hash Table is: %d\n", n);
        break;

      case 4:
        display();
        break;

      default:
        printf("Invalid Input\n");
    }


    scanf("%d", &c);
  } while (c == 1);

  return 0;
}
