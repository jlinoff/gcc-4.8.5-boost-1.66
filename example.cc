// Example implementation of a quicksort that uses a number
// of C++-11 constructs.
#include <algorithm>
#include <chrono>
#include <utility>
#include <vector>
#include <iostream>
#include <random>
using namespace std;

template <typename T>
auto insertionSort(vector<T>& a, size_t beg, size_t end) -> void
{
  for(auto i=beg+1; i<=end; ++i) {
    // all items from beg to i-1 are sorted
    // insert the new one in the appropriate slot
    auto j = i;
    while (j>0 && a[j-1] > a[j]) {
      swap(a[j], a[j-1]);
      --j;
    }
  }
}

template<typename T>
auto partition(vector<T>& a, size_t beg, size_t end) -> size_t
{
  // Randomly select the pivot using a uniform distribution.
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<size_t> dis(beg, end);
  auto idx = dis(mt);
  T pivot = a[idx];
  swap(a[end], a[idx]); // reserve the end slot

  auto i = beg;
  if (end > 0) {
    for(auto j=beg; j<end; ++j) {  // up to end - 1
      if (a[j] <= pivot) {
        swap(a[i], a[j]);
        ++i;
      }
    }
  }
  swap(a[i], a[end]);
  return i;
}

template <typename T, size_t M=32>
auto quickSort(vector<T>& a, size_t beg, size_t end) -> void
{
  if ((end - beg) < M) {
    insertionSort(a, beg, end);
  }
  else {
    auto pivot = partition(a, beg, end);
    if (pivot > 0) {
      quickSort(a, 0, pivot-1);   // left
    }
    if (pivot < end) {
      quickSort(a, pivot+1, end); // right
    }
  }
}

auto test() -> bool
{
  int M = 100000; // range of numbers in the array
  int N = 1000;   // array size

  cout << "test" << endl;
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<size_t> dis(1, M);

  vector<int> a;
  cout << "populating array with N=" << N << " where 1 <= a[i] <= " << M << endl;
  auto now = chrono::system_clock::now();
  do {
    if (a.size()) {
      cout << "trying again - previous attempt was already sorted" << endl;
    }
    a.clear();
    for(auto i=1; i<N; ++i) {
      int ran = dis(mt);
      a.push_back(ran);
    }
  } while (is_sorted(a.begin(), a.end()));
  auto end = chrono::system_clock::now();
  auto ms = chrono::duration_cast<chrono::milliseconds>(end-now).count();
  cout << "elapsed time: " << ms << "ms" << endl;

  cout << "sorting..." << endl;
  now = chrono::system_clock::now();
  quickSort(a, 0, a.size()-1);
  end = chrono::system_clock::now();
  ms = chrono::duration_cast<chrono::milliseconds>(end-now).count();
  cout << "elapsed time: " << ms << "ms" << endl;

  cout << "testing..." << endl;
  if (is_sorted(a.begin(), a.end())) {
    cout << "PASSED" << endl;
    return true;
  }
  cout << "FAILED" << endl;
  return false;
}

int main()
{
  return test() ? 0 : 1;
}
