# Singly-Linked List module

This is my simple singly-linked list module with basic functionality for handling multiple c-strings in your projects.

## Usage
- **Include** the module

   ```C
   #include "SLList.h"
   ```

- Declare **list variable**

  ```C
  struct SLList source_list;
  ```
  
- **Initialize** working with list

  ```C
  sll_init(&source_list);
  ```
  
- Do with your list what you want

   - **add** new **string** to list's end 
   
      ```C
      sll_push(&source_list, "some_text");
      ```
      
   - **remove string** from list's end 
   
      ```C
      sll_pop(&source_list);
      ```
      
   - get list's **size**
   
      ```C 
      sll_size(&source_list);
      ```
      
    - find out if the list **is empty**
    
      ```C 
      sll_is_empty(&source_list);
      ```
  
- **Terminate** working with list

   ```C
   sll_terminate(&source_list);
   ```
  
> **Note:** all the functions, processing list, works with *pointer on list*. So I advice to **use a pointer-variable**. This makes & using unnecessary. An example is given below:
   
```C
struct SLList *source_list = malloc(sizeof(struct SLList*));

sll_init(source_list);

...
   
sll_terminate(source_list);
	
free(source_list);
```

## Code Example

```C

#include <stdio.h>
#include <stdlib.h>

#include "SLList.h"

int main(int argc, char *argv[])
{
	struct SLList *source_list = malloc(sizeof(struct SLList*));

	sll_init(source_list);

	printf("%d\n", sll_size(source_list));

	sll_push(source_list, "First string");
	sll_push(source_list, "Second string");
	sll_push(source_list, "Third string");

	printf("%d\n", sll_size(source_list)); 
	
	
	struct Node *temp = source_list->head;

	while (temp->next != NULL)
	{
		printf("%s\n", temp->next->value);

		temp = temp->next;
	}

	sll_terminate(source_list);
	
	free(source_list);

	return 0;
}

/*
	OUTPUT:
	0
	3
	First string
	Second string
	Third string
*/

```

## Sentinel Using

If you want to find some value in list, you have to use while loop.

```C
struct Node *temp = source_list->head; 

while (temp != NULL)
{
	if (temp->value == some_found_value)
	{
		...
	}

	temp = temp->next;
}
```

At the moment everything is allright. But if want to pop last element, you need to use:

```C
struct Node *temp = source_list->head;

while (temp != NULL)
{
	temp = temp->next;
}
```

Here you found last element, but you need to redirect previous Node "next" field to NULL.
because of list is singly-linked, you cannot address previous Node

```C
struct Node *temp = source_list->head;

while (temp->next->next != NULL)
{
	temp = temp->next;
}
```

To resolve it I use a sentinel in the list's begin. Sentinel is an empty Node containing nothing. It provides me an opportunity to use code:

```C
temp->next = NULL;
```

Here temp pointers to penultimate element and we can delete the last element.

The following is the structure of singly-linked list with sentinel node

![alt text](https://github.com/BondarenkoDaniil/SLList/blob/master/list%20with%20sentinel%20structure.png?raw=true "Logo Title Text 1")

To learn more about lists with sentinels you can visit this [Wikipage](https://en.wikipedia.org/wiki/Sentinel_node).
