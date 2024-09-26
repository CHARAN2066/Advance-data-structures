#include<bits/stdc++.h>
using namespace std;


// Function to swap two elements
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}


// Function to heapify up (maintain max heap property)
void heapify_up(int max_heap[],int index)
{
    int parent_index=(index-1)/2;

    // If the current element is greater than its parent, swap them
    if(index>0&&(max_heap[index]>max_heap[parent_index]))
    {
        swap(&max_heap[index],&max_heap[parent_index]);
        heapify_up(max_heap,parent_index);
    }
}



// Function to heapify down (maintain max heap property)
void heapify_down(int max_heap[],int *size,int index)
{
    int largest=index;
    int left_child=2*index+1;
    int right_child=2*index+2;
    if(left_child<(*size)&&max_heap[left_child]>max_heap[largest])
    largest=left_child;
    else if(right_child>(*size)&&max_heap[right_child]>max_heap[largest])
    largest=right_child;
    if(largest!=index)
    {
        swap(max_heap[largest],max_heap[index]);
        heapify_down(max_heap,size,largest);
    }
}


// Function to insert an element into the max heap
void insert(int val,int *size,int max_heap[])
{
    
    max_heap[*(size)]=val;
    (*size)++;
    heapify_up(max_heap,*size-1);
}



// Function to delete the root element (maximum element) from the max heap
void delete_the_element(int max_heap[],int *size)
{
    if((*size)<0)
    cout<<"Heap is empty"<<endl;
    else
    {
        int root=max_heap[0];
        max_heap[0]=max_heap[(*size)-1];  // Replace root with the last element
        (*size)--;
        heapify_down(max_heap,size,0);    // Heapify down from the root
    }
}
int main()
{
    int max_heap[1000];
    int size=0;
    int choice;
    while (1)
    {
        cout<<"1.Insert the element"<<endl;
        cout<<"2.Get the maximum in the element"<<endl;
        cout<<"3. Delete the element"<<endl;
        cin>>choice;
        if(choice==1)
        {
            int val;
            cin>>val;
            insert(val,&size,max_heap);
            cout<<"The element is inserted"<<endl;
        }
        else if(choice==2)
        {
            cout<<"the max is"<<(max_heap[0]);
        }
        else if(choice==3)
        {
            delete_the_element(max_heap,&size);
            cout<<"The element is deleted"<<endl;
        }
        else
        break;
    }
    // insert(10,&size,max_heap);
}