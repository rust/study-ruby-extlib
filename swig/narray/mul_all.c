float mul_all(float array[], int nx)
{
  float result = 1.0;
  int i;

  for(i=0; i<nx; i++){
    result = result * array[i];
  }
  return result;
}
