// recursive Binary Search
#include <iostream>
using namespace std;

/*fungsi binary search dengan parameter data arrary, index ke-1,
index ke-n, data yg dicari */
int binarySearch(int arr[], int l, int r, int x)
{
  if (r >= l)
  {
    int mid = l + (r - l) / 2;

    // jika data tengah adalah data yang dicari
    if (arr[mid] == x)
      return mid;

    // jika data yang dicari adalah kurang dari data tengah
    if (arr[mid] > x)
      return binarySearch(arr, l, mid - 1, x);

    // lainnya jika data yang dicari lebih dari data tengah
    return binarySearch(arr, mid + 1, r, x);
  }

  // We reach here when element is not
  // present in array
  return -1;
}

int main(void)
{
  int arr[] = {2, 3, 4, 10, 40};
  int x = 10;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = binarySearch(arr, 0, n - 1, x);
  (result == -1) ? cout << "Data tidak ditemukan"
                 : cout << "Data ditemukan di index ke - " << result;
  return 0;
}

// Sorting
// for (i = 0; i < sizeof(arr); i++)
// {
//   for (j = 0; j < sizeof(arr); j++)
//   {
//     if (arr[j] > arr[j + 1])
//     {
//       temp = arr[j];
//       arr[j] = arr[j + 1];
//       arr[j + 1] = temp;
//     }
//   }
// }
