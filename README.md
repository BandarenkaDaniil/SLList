# Singly Linked List module

This is my simple singly linked list module with basic functionality providing handling multiple c-strings in your projects.

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
  
> **Note:** all the functions, processing list, works with *pointer on list*. So I advice to **use a pointer-variable**. An example is given below:
   
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
