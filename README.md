# Singly Linked List module

This is my simple singly linked list module with basic functionality providing handling multiple c-strings in your projects.

## Usage
- Include the module

   `#include "SLList.h"`

- Declare list variable

  `struct SLList source_list;`
  
- Initialize working with list

  `sll_init(&source_list);`
  
- Do with your list all what you want

   - add new string to list's end 
   
      `sll_push(&source_list, "some_text");`
      
   - remove string from list's end 
   
      `sll_pop(&source_list);`
      > **Note:** this function returns poped string so you can 
      
   - get list's size
   
      `sll_terminate(&source_list);`
  
- Terminate working with list

  `sll_terminate(&source_list);`
