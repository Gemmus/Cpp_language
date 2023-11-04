/////////////////////////////////////////////////////
//               Returning a pointer:              //
/////////////////////////////////////////////////////

// prototype of a function
int *getMax(int *arr, int n);

// application
int main(void) { 
  int maxValue;
  int array[6] = {3, 5, 2, 8, 6, 7};
  printf ("%d", *getMax(array, 6));
  //Right value
  maxValue = *getMax(array, 6);
  *getMax(array, 6) = *getMax(array, 6)*10;
  //Left value
}

// implementation getMax
int *getMax(int *arr, int n) {
  int i, maxi = 0;
  for (i = 1; i < n; i++)
    if (arr[i] > arr[maxi]) 
      maxi = i;
  return &arr[maxi];
}


/////////////////////////////////////////////////////
//              Returning a reference:             //
/////////////////////////////////////////////////////

// prototype of a function
int &getMax(int *arr, int n);

// application
int main(void) {
  int maxValue;
  int array[6] = {3, 5, 2, 8, 6, 7};
  printf ("%d", getMax(array, 6));
  //Right value
  maxValue = getMax(array, 6);
  getMax(array, 6) = getMax(array, 6)*10;
  //Left value
}

// implementation getMax
int &getMax(int *arr, int n) {
  int i, maxi = 0;
  for (i = 1; i < n; i++)
    if (arr [i] > arr[maxi])
      maxi = i;
  return arr[maxi];
}
