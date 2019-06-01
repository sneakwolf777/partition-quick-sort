#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define M 20
// 20 element max
int x[M] ;


// Print elements of array
void print_array(int lo, int hi)
{
  int i ;
  printf("[") ;
  for(i=lo;i<=hi;i++) {
    
    printf(" %d  ",x[i]) ;
  }
  printf("]") ;
  printf("\n") ;
}


// Create an array with random numbers
void create_array() 
{
  int i ;

  for(i = 0; i < M; i++)
  {
    x[i] = rand() % 100 + 1 ;
  }

}

// Swap the elements in array
void swap(int a, int b)
{
  int temp ;
  temp = x[a] ;
  x[a] = x[b] ;
  x[b] = temp ; 
}

// Keep checking the left
int check_left(int pivot, int left, int right)
{ 
  while(x[pivot] > x[left] && left != right)
  {
    left++ ;
  }

  return left ;
}




// Keep checking the right
int check_right(int pivot, int right, int left)
{
  while(x[pivot] <= x[right] && right != left)
  {
    right-- ; 
  }

  if(right == left && x[left - 1] < x[right])
    right = left - 1 ;

  return right ;
}




void partition(int lo, int hi)  
{
  int left, right, pivot ;
  
  if (lo < hi)
  {

    pivot = lo ;
    left = pivot+1 ;
    right = hi ;

    while(left - right < 0)
    {
      // Compare pivot with current index of left and right sides
      left = check_left(pivot, left, hi) ;
      right = check_right(pivot, right, left) ;
      
      // Swap the left and right comparison values
      if(left - right < 0)
        swap(left, right) ;
    }

    // If left == right and current x[pivot] > x[right] 
    // then check the next lowest value or x[pivot+1]
    for (int i = pivot; i < right; ++i)
    {
      // If left and right comparisons intersect then swap the pivot value 
      if(x[i] > x[right])
      {
        swap(i, right) ;
	break ;
      }
    }

    // Recursively check and swap partitions of the array
    // Sort first and second halves
    if(left != right)
    { 
      partition(pivot, right) ;
      partition(right+1, hi) ;
    }

    //if only two elements left to partition, then partition only one element
    else
    {
      partition(pivot, hi-1) ;
      partition(right, right) ;
    }

  }
 
}




int main()
{
  create_array() ;   
  print_array(0,M-1) ;
  printf("\n\n\n") ;
  partition(0,M-1) ;
  print_array(0,M-1) ;   
}

