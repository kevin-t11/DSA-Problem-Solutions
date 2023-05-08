#include <bits/stdc++.h>
using namespace std;

void mergeInplace(int start, int mid, int end, int arr[]) {
  int total_len = end - start + 1;
  int gap = (total_len / 2) + (total_len % 2); // ceil (total_len /2)

  while (gap > 0) {
    int i = start, j = start + gap;

    while (j <= end) {
      if (arr[i] > arr[j])
        swap(arr[i], arr[j]);
      i++;
      j++;
    }
    gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2);
  }
}

void mergeSort(int start, int end, int arr[]) {
  if (start >= end)
    return;
  int mid = start + (end - start) / 2;

  mergeSort(start, mid, arr);
  mergeSort(mid + 1, end, arr);
  mergeInplace(start, mid, end, arr);
}

int main() {
  int arr[] = {1, 2, 5, 13, 8, 9, 7, 10, 6, 4, 3};
  int n = 11;

  mergeSort(0, n - 1, arr);

  cout << "priting the resultant array" << endl;
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
}