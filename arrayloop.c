#include <stdio.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], int* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%d", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your arrayAdd function here
int arrayAdd(int arr, int size, int inc) {
  for (int count = 0; count < size; ++count) {
    arr[count] = arr[count] + inc;
  }
  
  return arr;
}



int main(int argc, char* argv[]) 
{
  // the variable which controls the size of the array
  int size = 100;
  
  // the variable which increments the values in the array
  int inc = 3;
  
  // for testing only - do not change
  getTestInput(argc, argv, &size, &inc);

  printf("array loop size: %d, inc %d\n", size, inc);
  
  // add your code below to:
  // - initialize a 'size' element int array
  int intarray[size];
  // - fill it with the square of each index using a for loop i.e. 0, 1, 4, 9 etc
  for (int count = 0; count <= size; ++count) {
    intarray[count] = count^2;
  }
  // - pass the array to arrayAdd to add the increment of inc
  arrayAdd(intarray, size, inc);
  // - print out the array
  for (int it = 0; it < size; ++it) {
    printf("%d ", intarray[it]);
  }



  
}
