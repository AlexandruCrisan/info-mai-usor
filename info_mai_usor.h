#pragma once

namespace info {

class aritmetica {
public:
    static double adunare (double x, double y);
    static double scadere (double x, double y);
    static double inmultire (double x, double y);
    static double impartire (double x, double y);
    static double radical (double x);
    static double cmmdc (double x, double y);
    static double cmmmc (double x, double y);
};

class vectori {
public:
    static void inversare_vector (long long tablou[], unsigned long long n);

    class sortare_vector{
    public:
        static void selection_sort (long long v[], unsigned long long n);
        static void bubble_sort (long long v[], unsigned long long n);
        static void insertion_sort (long long v[], unsigned long long n);
        static void quick_sort (long long v[], unsigned long long n, unsigned long long st, unsigned long long dr);
    };
};
}
