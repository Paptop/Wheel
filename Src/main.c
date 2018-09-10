#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node* next_node;
} Node;

typedef struct List
{
  Node* head;
  Node* tail;
  int elem_count;
} List;

List* create_list()
{
  List* list = (List *)malloc(sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  list->elem_count = 0;
}

void free_list(List* list)
{
  Node* ptr = list->head;
  while(ptr != NULL)
  {
    Node* next = ptr->next_node;
    free(ptr);   
    ptr = next;
  }

  free(list);
}

int push_to_front(List* list, int data)
{
  if(list == NULL)
  {
     return 1;
  }

  Node* new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  list->elem_count++;

  if(list->head == NULL)
  {
    list->tail = new_node;  
    list->head = new_node;
    new_node->next_node = NULL;
    return 0;
  }

  new_node->next_node = list->head;
  list->head = new_node;

  return 0; 
}

int push_to_back(List* list, int data)
{
  if(list == NULL)
  {
    return 1;
  }
  
  Node* new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  list->elem_count++;

  if(list->head == NULL)
  {
    list->tail = new_node;  
    list->head = new_node;
    new_node->next_node = NULL;
    return 0;
  }

  list->tail->next_node = new_node;
  list->tail = new_node;
  return 0;
}

int pop_front(List* list)
{
  if(list == NULL || list->head == NULL)
  {
    return 1;
  }

  Node* newHead = list->head->next_node; 
  Node* oldHead = list->head;
  list->head = newHead;
  list->elem_count--;
  free(oldHead);
  return 0;
}

void print_list(List* list)
{
  Node* node = list->head;

  while(node != NULL)
  {
    printf("\033[1;31m"); 
    printf("[%d] ", node->data);
    node = node->next_node; 
  }
  printf("\nTotal in list :%d\n", list->elem_count);
  printf("\033[0m");
}

Node* find(List* list, int data)
{
  Node* node = list->head;

  while(node != NULL)
  {
    if(node->data == data)
    {
       return node;
    }
    node = node->next_node;
  }
  return NULL;
}

Node* at(List* list, int index)
{
  if(index < 0 || index >= list->elem_count)
  {
     return NULL;
  }

  Node* node = list->head;
  int i = 0; 
  while(node != NULL)
  {
    if( i == index)
    {
      return node;
    }
      
    node = node->next_node;
  }

  return NULL;
}

int main()
{
  List* list = create_list();
  int input = 0;

  while(1)
  {
    printf("\n");
    printf("0 - Exit\n");
    printf("1 - Display List\n");
    printf("2 - Push to front\n");
    printf("3 - Push to back\n");
    printf("4 - Pop front\n");
    printf("5 - Find by value\n");
    printf("6 - Find by index\n");
    printf("\n");
    scanf("%d",&input); 
    switch(input)
    {
      case 0:
        break;
      case 1:
        print_list(list);
        break;
      case 2:
        { 
          int value = 0;
          printf("Value :");
  	  scanf("%d", &value);
          push_to_front(list,value);
        }
        break;
      case 3:
        {
          int value = 0;
          printf("Value :");
  	  scanf("%d", &value);
          push_to_back(list,value);
        }
        break;
      case 4:
        {
          pop_front(list);
        }
        break;
      case 5:
        {
          int value = 0;
          printf("Value :");
          scanf("%d", &value);
          Node* node = find(list,value);
          if(node == NULL)
          {
             printf("Element not found in list");
          }
          else
          {
             printf("Element found in list with value=%d", node->data);
          }  
        }
        break;
      case 6:
        {
          int index = 0;
          printf("Index :");
          scanf("%d", &index);
          Node* node = at(list,index);
          if(node == NULL)
          {
            printf("Element not found in list");
          }
          else
          {
            printf("Element found : %d", node->data);
          }
        }
        break;
    }

    if(input == 0)
    {
      break;
    }
  }

  free_list(list);
  return 0;
}
