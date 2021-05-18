#include "info_mai_usor.h"
#include <algorithm>
#include <cmath>

namespace info {

////////////////////////////////////////////////////////////////////////////////////////   ARITMETICA

double aritmetica::adunare(double x, double y) {
    return x + y;
}

double aritmetica::scadere(double x, double y) {
    return x - y;
}

double aritmetica::inmultire (double x, double y) {
    return x * y;
}

double aritmetica::impartire (double x, double y) {
    return x / y;
}

double aritmetica::radical (double x) {
    return sqrt(x);
}

double aritmetica::cmmdc (double x, double y) {
    while(x != y) {
        if(x > y)
            x-=y;
        else y-=x;
    }
    return x;
}

double aritmetica::cmmmc (double x, double y) {
    double cmmdc = aritmetica::cmmdc(x, y);
    return (x*y)/cmmdc;
}

/////////////////////////////////////////////////////////////////////////////////////////   VECTORI

void vectori::inversare_vector (long long tablou[], unsigned long long n) {
    for(unsigned long long i = 0; i <= n/2; i++)
        std::swap(tablou[i], tablou[n-i-1]);
}

///////////////////////////////////////   SORTARE

void vectori::sortare_vector::bubble_sort (long long v[], unsigned long long n) {
    bool sortat;
    do {
        sortat = true;
        for(unsigned long long i = 0 ; i < n - 1 ; i ++)
            if(v[i] > v[i+1]) {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                sortat = false;
            }
    } while(!sortat);
}

void vectori::sortare_vector::selection_sort (long long v[], unsigned long long n) {
    for(unsigned long long i = 0 ; i < n - 1 ; i ++)
        for(unsigned long long j = i + 1 ; j < n ; j ++)
            if(v[i] > v[j]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
}

void vectori::sortare_vector::insertion_sort (long long v[], unsigned long long n) {
    for(unsigned long long i = 1 ; i < n ; i ++) {
        long long x = v[i];
        unsigned long long p = i - 1;
        while(p >= 0 && v[p] > x)
            v[p + 1] = v[p], p --;
        v[p + 1] = x;
    }
}

void swap(long long *a, long long *b) {
  long long t = *a;
  *a = *b;
  *b = t;
}

long long part(long long v[],unsigned long long low, unsigned long long high) {

  // select the rightmost element as pivot
  long long pivot = v[high];

  // pointer for greater element
  unsigned long long i = (low - 1);

  // traverse each element of the v
  // compare them with the pivot
  for (unsigned long long j = low; j < high; j++) { /// from j < high
    if (v[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&v[i], &v[j]);
    }
  }

  // swap pivot with the greater element at i
  swap(&v[i + 1], &v[high]);

  // return the partition point
  return (i + 1);
}

void vectori::sortare_vector::quick_sort (long long v[], unsigned long long n, unsigned long long st, unsigned long long dr) {
    if(st < dr){

        long long piv = part(v, st, dr);
        vectori::sortare_vector::quick_sort(v, n, st, piv - 1);
        vectori::sortare_vector::quick_sort(v, n, piv+1, dr);

    }
}

}
