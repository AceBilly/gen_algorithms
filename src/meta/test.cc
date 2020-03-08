int main(void) {
  int* arr;
  int* p = new int[5]{1, 2, 3, 4, 5};
  int* arr = p;
  p = reinterpret_cast<int[5]>(arr);
}