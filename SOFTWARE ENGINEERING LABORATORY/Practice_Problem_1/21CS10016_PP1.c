/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Product
{
  int id;
  char name[50];
  struct Product *next;
} product;
typedef struct Product_purchased
{
  int id;
  int num;
  struct Product_purchased *next;
} productp;

typedef struct Inventory
{
  int product_id;
  int num_available;
  struct Inventory *next;
} inventory;

typedef struct Shops_and_Warehouse
{
  int id;
  char name[50];
  int zipcode;
  inventory *available;
  struct Shops_and_Warehouse *next;
} shop_warehouse;

typedef struct Delivery_agent
{
  int id;
  char name[50];
  int zipcode;
  int products_delivered;
  struct Delivery_agent *next;
} agent;

typedef struct Customer
{
  int id;
  char name[50];
  int zipcode;
  productp *list;
  struct Customer *next;
} customer;

typedef struct Order
{
  int c_id;
  int p_id;
  int num;
} order;

shop_warehouse *create1(shop_warehouse *head)
{
  shop_warehouse *temp = (shop_warehouse *)malloc(sizeof(shop_warehouse));
  int temp1;
  printf("Enter shop id:\n");
  scanf("%d", &temp1);
  temp->id = temp1;
  printf("Enter shop name:\n");
  scanf("%s", temp->name);
  printf("Enter shop zipcode:\n");
  scanf("%d", &temp1);
  temp->zipcode = temp1;
  temp->available = NULL;
  if (head == NULL)
  {
    temp->next = NULL;
    return temp;
  }

  shop_warehouse *p = head;

  while (p->next != NULL)
  {
    p = p->next;
  }
  p->next = temp;
  temp->next = NULL;
  return head;
}

product *create2(product *head)
{
  product *temp = (product *)malloc(sizeof(product));
  int temp1;
  printf("Enter product id:\n");
  scanf("%d", &temp1);
  temp->id = temp1;
  printf("Enter product name:\n");
  scanf("%s", temp->name);

  if (head == NULL)
  {
    temp->next = NULL;
    return temp;
  }

  product *p = head;

  while (p->next != NULL)
  {
    p = p->next;
  }
  p->next = temp;
  temp->next = NULL;
  return head;
}

agent *create3(agent *head)
{
  agent *temp = (agent *)malloc(sizeof(agent));
  int temp1;
  printf("Enter agent id:\n");
  scanf("%d", &temp1);
  temp->id = temp1;
  printf("Enter agent name:\n");
  scanf("%s", temp->name);
  printf("Enter agent zipcode:\n");
  scanf("%d", &temp1);
  temp->zipcode = temp1;
  temp->products_delivered = 0;

  if (head == NULL)
  {
    temp->next = NULL;
    return temp;
  }

  agent *p = head;

  while (p->next != NULL)
  {
    p = p->next;
  }
  p->next = temp;
  temp->next = NULL;
  return head;
}

customer *create4(customer *head)
{
  customer *temp = (customer *)malloc(sizeof(customer));
  int temp1;
  printf("Enter customer id:\n");
  scanf("%d", &temp1);
  temp->id = temp1;
  printf("Enter customer name:\n");
  scanf("%s", temp->name);
  printf("Enter customer zipcode:\n");
  scanf("%d", &temp1);
  temp->zipcode = temp1;
  temp->list = NULL;

  if (head == NULL)
  {
    temp->next = NULL;
    return temp;
  }

  customer *p = head;

  while (p->next != NULL)
  {
    p = p->next;
  }
  p->next = temp;
  temp->next = NULL;
  return head;
}

void print_inventory(inventory *head)
{
  inventory *ptr = head;
  printf("In Inventory: ");
  do
  {
    printf("Product ID: %d Number of products available: %d ", ptr->product_id, ptr->num_available);
    ptr = ptr->next;
  } while (ptr != head);
}

void print1(shop_warehouse *head)
{
  shop_warehouse *ptr = head;
  printf("Printing shop and warehouse list:\n");
  while (ptr)
  {
    printf("ID: %d Name: %s ZIP Code: %d\n", ptr->id, ptr->name, ptr->zipcode);
    ptr = ptr->next;
  }
}

void print2(product *head)
{
  product *ptr = head;
  printf("Printing product list:\n");
  while (ptr)
  {
    printf("ID: %d Name: %s\n", ptr->id, ptr->name);
    ptr = ptr->next;
  }
}

void print3(agent *head)
{
  agent *ptr = head;
  printf("Printing agent list:\n");
  while (ptr)
  {
    printf("ID: %d Name: %s ZIP Code: %d Products Delivered: %d\n", ptr->id, ptr->name, ptr->zipcode, ptr->products_delivered);
    ptr = ptr->next;
  }
}

void print4(customer *head)
{
  customer *ptr = head;
  printf("Printing customer list:\n");
  while (ptr)
  {
    printf("ID: %d Name: %s ZIP Code: %d \n", ptr->id, ptr->name, ptr->zipcode);
    ptr = ptr->next;
  }
}

void delete1(shop_warehouse *head)
{
  print1(head);
  int id;
  printf("Enter ID number of shop and warehouse to delete:\n");
  scanf("%d", &id);
  shop_warehouse *prev = NULL, *current = head;
  while (current != NULL)
  {
    if (current->id == id)
    {
      if (current == head)
      {
        head = head->next;
        free(current);
        current = head;
      }
      else
      {
        prev->next = current->next;
        free(current);
        current = prev->next;
      }
    }
    else
    {
      prev = current;
      current = current->next;
    }
  }
}

void delete2(product *head)
{
  print2(head);
  int id;
  printf("Enter ID number of product to delete:\n");
  scanf("%d", &id);
  product *prev = NULL, *current = head;
  while (current != NULL)
  {
    if (current->id == id)
    {
      if (current == head)
      {
        head = head->next;
        free(current);
        current = head;
      }
      else
      {
        prev->next = current->next;
        free(current);
        current = prev->next;
      }
    }
    else
    {
      prev = current;
      current = current->next;
    }
  }
}

void delete3(agent *head)
{
  print3(head);
  int id;
  printf("Enter ID number of agent to delete:\n");
  scanf("%d", &id);
  agent *prev = NULL, *current = head;
  while (current != NULL)
  {
    if (current->id == id)
    {
      if (current == head)
      {
        head = head->next;
        free(current);
        current = head;
      }
      else
      {
        prev->next = current->next;
        free(current);
        current = prev->next;
      }
    }
    else
    {
      prev = current;
      current = current->next;
    }
  }
}

void delete4(customer *head)
{
  print4(head);
  int id;
  printf("Enter ID number of customer to delete:\n");
  scanf("%d", &id);
  customer *prev = NULL, *current = head;
  while (current != NULL)
  {
    if (current->id == id)
    {
      if (current == head)
      {
        head = head->next;
        free(current);
        current = head;
      }
      else
      {
        prev->next = current->next;
        free(current);
        current = prev->next;
      }
    }
    else
    {
      prev = current;
      current = current->next;
    }
  }
}

void add_product(shop_warehouse *list_shop, product *list_product)
{
  int s_id, p_id, num;
  printf("Enter shop id to add products:\n");
  scanf("%d", &s_id);
  printf("Enter product id to add to the shop:\n");
  scanf("%d", &p_id);
  printf("Enter number of items of that product to enter:\n");
  scanf("%d", &num);
  shop_warehouse *curr1 = list_shop;
  while (curr1 != NULL)
  {
    if (curr1->id == s_id)
      break;
    curr1 = curr1->next;
  }
  inventory *ptr = (inventory *)malloc(sizeof(inventory));
  ptr->num_available = num;
  ptr->product_id = p_id;
  inventory *curr2 = curr1->available;
  if (curr2 == NULL)
  {
    curr1->available = ptr;
    ptr->next = NULL;
    return;
  }
  inventory *p = curr2;
  while (p->next)
  {
    p = p->next;
  }
  p->next = ptr;
  ptr->next = NULL;
}

order *take_order()
{
  order *ptr = (order *)malloc(sizeof(order));
  printf("Enter the Customer id:\n");
  scanf("%d", &ptr->c_id);
  printf("Enter the Product id:\n");
  scanf("%d", &ptr->p_id);
  printf("Enter the number of items:\n");
  scanf("%d", &ptr->c_id);
  return ptr;
}

void process_order(order *item, agent *list_agent, customer *list_customer, shop_warehouse *shop)
{
  int c_zip, c_id = item->c_id;
  customer *temp1 = list_customer;
  inventory *temp3;
  while (temp1)
  {
    if (temp1->id == c_id)
      break;
    temp1 = temp1->next;
  }
  int flag = 0;
  c_zip = temp1->zipcode;
  shop_warehouse *temp2 = shop;
  while (temp2)
  {
    if (temp2->zipcode == c_zip)
    {
      temp3 = temp2->available;
      while (temp3)
      {
        if (temp3->product_id == item->p_id && temp3->num_available >= item->num)
        {
          flag = 1;
          break;
        }
        temp3 = temp3->next;
      }
    }
    if (flag == 1)
      break;
    temp2 = temp2->next;
  }
  if (flag)
  {
    productp *pur_made = (productp *)malloc(sizeof(productp));
    pur_made->id = item->p_id;
    pur_made->num = item->num;
    productp *temp4 = temp1->list;
    if (temp4 == NULL)
    {
      pur_made->next = NULL;
      temp1->list = pur_made;
    }
    else
    {
      while (temp4->next != NULL)
      {
        temp4 = temp4->next;
      }
      temp4->next = pur_made;
      pur_made->next = NULL;
    }

    temp3->num_available -= item->num;
    agent *temp5 = list_agent, *agent_choosen = list_agent;
    while (temp5)
    {
      if (temp5->products_delivered < agent_choosen->products_delivered)
      {
        agent_choosen = temp5;
      }
      temp5 = temp5->next;
    }
    agent_choosen->products_delivered += item->num;
    printf("Order for customer ID %d: Product ID: %d Number of items ordered: %d Delivery agent assigned: %d", item->c_id, item->p_id, item->num, agent_choosen->id);
  }
  else
  {
    printf("Purchase can not be made\n");
  }
}

void show_purchase(int c_id, customer *list)
{
  customer *temp = list;
  while (temp)
  {
    if (temp->id == c_id)
      break;
    temp = temp->next;
  }
  productp *temp2 = temp->list;
  while (temp2)
  {
    printf("Item ID: %d Quantity bought: %d", temp2->id, temp2->num);
    temp2 = temp2->next;
  }
}

void show_inventory(int s_id, shop_warehouse *list)
{
  shop_warehouse *temp = list;
  while (temp)
  {
    if (temp->id == s_id)
      break;
    temp = temp->next;
  }
  inventory *temp2 = temp->available;
  while (temp2)
  {
    printf("Product ID: %d Quantity available: %d\n", temp2->product_id, temp2->num_available);
    temp2 = temp2->next;
  }
}

char show_menu1()
{
  char key;
  printf("Enter C for create:\nEnter D for delete:\nEnter P for print:\nEnter A to add prodcuts to shop:\nEnter O to give order:\nEnter L to show list:\nEnter X to exit:\n");
  scanf("%c", &key);
  return key;
}

int main()
{
  shop_warehouse *list_shop = NULL;
  product *list_product = NULL;
  agent *list_agent = NULL;
  customer *list_customer = NULL;
  order *taken_order = NULL;

  printf("------===Welcome to Service===------\n---------Press Enter key to begin---------");
  char key, key2, waste;
  int id;
  do
  {
    waste = getc(stdin);
    key = show_menu1();
    switch (key)
    {
    case 'C':
    case 'c':
    {
      printf("Enter C to create Customer entity:\nEnter P to create Product entity:\nEnter S to create Shop entity:\nEnter A to create Agent entity:\n");
      waste = getc(stdin);
      scanf("%c", &key2);
      switch (key2)
      {
      case 'c':
      case 'C':
        list_customer = create4(list_customer);
        break;
      case 'p':
      case 'P':
        list_product = create2(list_product);
        break;
      case 'S':
      case 's':
        list_shop = create1(list_shop);
        break;
      case 'A':
      case 'a':
        list_agent = create3(list_agent);
        break;
      }
      break;
    }
    case 'D':
    case 'd':
      printf("Enter C to delete Customer entity:\nEnter P to delete Product entity:\nEnter S to delete Shop entity:\nEnter A to delete Agent entity:\n");
      waste = getc(stdin);
      scanf("%c", &key2);
      switch (key2)
      {
      case 'c':
      case 'C':
        delete4(list_customer);
        break;
      case 'p':
      case 'P':
        delete2(list_product);
        break;
      case 'S':
      case 's':
        delete1(list_shop);
        break;
      case 'A':
      case 'a':
        delete3(list_agent);
        break;
      }
      break;
    case 'P':
    case 'p':
      printf("Enter C to print Customer entity:\nEnter P to print Product entity:\nEnter S to print Shop entity:\nEnter A to print Agent entity:\n");
      waste = getc(stdin);
      scanf("%c", &key2);
      switch (key2)
      {
      case 'c':
      case 'C':
        print4(list_customer);
        break;
      case 'p':
      case 'P':
        print2(list_product);
        break;
      case 'S':
      case 's':
        print1(list_shop);
        break;
      case 'A':
      case 'a':
        print3(list_agent);
        break;
      }
      break;
    case 'A':
    case 'a':
      add_product(list_shop, list_product);
      break;
    case 'o':
    case 'O':
      taken_order = take_order();
      process_order(taken_order, list_agent, list_customer, list_shop);
      break;
    case 'l':
    case 'L':
      printf("Enter C to list all the purchases made by a customer:\nEnter S to list the inverntory a shop:\n");
      waste = getc(stdin);
      scanf("%c", &key2);
      switch (key2)
      {
      case 'c':
      case 'C':
        printf("Enter Customer id:\n");
        scanf("%d", &id);
        show_purchase(id, list_customer);
        break;
      case 'S':
      case 's':
        printf("Enter shop id:\n");
        scanf("%d", &id);
        show_inventory(id, list_shop);
        break;
      }
      break;

    default:
      break;
    }

  } while (key != 'X' && key != 'x');
}