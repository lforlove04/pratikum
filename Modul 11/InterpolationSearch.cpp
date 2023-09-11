// C++ program to implement interpolation search
#include <bits/stdc++.h>
using namespace std;

/*
fungsi interpolation search
parameter:
arr = data
n = banyak data
x = data yang dicari
*/
int interpolationSearch(int arr[], int n, int x)
{
  // menentukan index awal dan index akhir
  int lo = 0, hi = (n - 1);

  // Selama data sudah diurutkan dan data yang dicari berada di antara index awal dan akhir
  while (lo <= hi && x >= arr[lo] && x <= arr[hi])
  {
    // Jika index awal sama dengan index akhir
    if (lo == hi)
    {
      // jika data yang dicari berada pada index awal maka kembalikan index awal
      if (arr[lo] == x)
        return lo;
      // jika tidak maka tidak ketemu kembalikan -1
      return -1;
    }
    // menentukan posisi dengan rumus interpolasi
    int pos = lo + (((double)(hi - lo) /
                     (arr[hi] - arr[lo])) *
                    (x - arr[lo]));

    // jika data ketemu
    if (arr[pos] == x)
      return pos;

    // jika data yang dicari lebih besar daripada data pada posisi tersebut
    if (arr[pos] < x)
      lo = pos + 1;

    // jika data yang dicari lebih kecil daripada data pada posisi tersebut
    else
      hi = pos - 1;
  }
  return -1;
}

int main()
{
  // Array Data
  int arr[] = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
  int n = sizeof(arr) / sizeof(arr[0]);

  int x = 18; // data yang dicari
  int index = interpolationSearch(arr, n, x);

  // juka data ditemukan
  if (index != -1)
    cout << "Data ditemukan pada index ke-" << index;
  else
    cout << "Data tidak ditemukan.";
  return 0;
}