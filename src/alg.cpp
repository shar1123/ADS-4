// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        k++;
    }
  }
  return k;
}
int countPairs2(int *arr, int len, int value) {
  int k = 0;
  int l = 0;
  int r = len - 1;
  for (int i = 0; i < r; i++) {
    for (int j = r - 1; j > l; j--) {
      if (arr[j] > value) {
        r -= 1;
      }
      if (arr[i] + arr[j] == value) {
        k += 1;
      }
    }
    l += 1;
  }
  return k;
}
int countPairs3(int* arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = left/2 + right/ 2;
      if (arr[mid] == target) {
        int countSame = 1;
        int l = mid - 1;
        while (l > i && arr[l] == target) {
          countSame++;
          l--;
        }
        int r = mid + 1;
        while (r < len && arr[r] == target) {
          countSame++;
            r++;
        }
        k += countSame;
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return k;
}
