/* Hashing is a technique used in computer science to efficiently map data (often called a key) to a specific location in a data structure 
called a hash table. 
The key idea behind hashing is to use a hash function to convert the key into an index in an array or table where the data is stored.
Collisions: When two keys hash to the same index, a collision occurs. Handling collisions is a critical aspect of hashing.
Chaining is a method for handling collisions in hash tables. Instead of trying to find another open slot in the table when a collision 
occurs, chaining involves storing multiple elements at the same index using a secondary data structure like a linked list.
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define TABLE_SIZE 10
// Structure to store the number and its frequency
struct number
{
    int number;
    int frequency;
    struct number *next;
};
typedef struct number number;

number *hash_table[TABLE_SIZE];
int hash(int n)
{
    int hash_value=n%(TABLE_SIZE);
    return hash_value;
}
void init_hash_tabel()
{
	for(int i=0;i<TABLE_SIZE;i++)
	{
		hash_table[i]=0;
	}
}
number *create_a_node(int n)
{
	number *newnode=(number*)malloc(sizeof(number));
	newnode->number=n;
	newnode->frequency=1;
	newnode->next=NULL;
	return newnode;
}
void hash_table_insert(int n)
{
	number *temp=hash_table[hash(n)];
	int flag=0;
	while (temp!=NULL)
	{
		if(temp->number==n)
		{
			temp->frequency++;
			flag=1;
			break;
		}
		temp=temp->next;
	}
	if(flag==0)
	{
	number *creatednode=NULL;
	creatednode=create_a_node(n);
    creatednode->next=hash_table[hash(n)];
	hash_table[hash(n)]=creatednode;
	//hash_table[hash(n)]->next=NULL;
	}
}
void print_hash_table()
{
	number *temp=NULL;
	for(int i=0;i<TABLE_SIZE;i++)
	{
		temp=hash_table[i];
	    if(temp==NULL)
		printf("%d------\n",i);
		while (temp!=NULL)
		{
			printf("%d------%d-%d\n",i,temp->number,temp->frequency);
			temp=temp->next;
		}
	}
}
int main()
{
    init_hash_tabel();
	hash_table_insert(1);
	hash_table_insert(1);
	hash_table_insert(1);
	hash_table_insert(1);
	hash_table_insert(76);
	hash_table_insert(76);
	hash_table_insert(76);
	hash_table_insert(76);
	hash_table_insert(1176);
	print_hash_table();
    return 0;
}