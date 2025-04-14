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
    for (int j = r-1; j > l; j++) {
      if (arr[j] > value) {
        r--;
      }
      if (arr[i] + arr[j] == value) {
        k++;
      }
    }
    l++;
  }
  return k;
}
bool binary(int* arr, int l, int r, int target, bool fl) {
  int result = -1;
  while (l <= r) {
    int mid = l/2 + r/ 2;
    if (arr[mid] == target) {
      result = mid;
      if (fl) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    } else if (arr[mid] < target) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return result;
}
int countPairs3(int* arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    int first = binary(arr, i + 1, len - 1, target, true);
    if (first != -1) {
      int last = binary(arr, first, len - 1, target, false);
      k += last - first + 1;
    }
  }
  return k;
}
