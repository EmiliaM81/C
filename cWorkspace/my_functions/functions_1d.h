#ifndef FUNCTIONS_1D_H
#define FUNCTIONS_1D_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * @brief Wypisuje tablicę liczb calkowitych od wskaznika first
 * do wskaznika last-1.
 *
 * @param first wskaznik do pierwszego elementu tablicy, ktory ma byc wypisany.
 * @param last wskaznik za ostatnim elementem tablicy, ktory ma byc wypisany.
 * @param header lancuch do wyswietlenia na poczatku jako naglowek.
 */
void i_array_print(const int *first, const int *last, const char *header);

/**
 * @brief Wypisuje tablicę liczb zmiennoprzecinkowych od wskaznika first
 * do wskaznika last-1.
 *
 * @param first wskaznik do pierwszego elementu tablicy, ktory ma byc wypisany.
 * @param last wskaznik za ostatnim elementem tablicy, ktory ma byc wypisany.
 * @param header lancuch do wyswietlenia na poczatku jako naglowek.
 */
void d_array_print(const double *first, const double *last, const char *header);

/**
 * @brief Zeruje tablicę liczb calkowitych od wskaznika first
 * do wskaznika last-1.
 *
 * @param first wskaznik do pierwszego elementu tablicy, ktory ma byc wyzerowany.
 * @param last wskaznik za ostatnim elementem tablicy, ktory ma byc wyzerowany.
 */
void i_array_set_zero(int *first, int *last);

/**
 * @brief Zeruje tablicę liczb zmiennoprzecinkowych od wskaznika first
 * do wskaznika last-1.
 *
 * @param first wskaznik do pierwszego elementu tablicy, ktory ma byc wyzerowany.
 * @param last wskaznik za ostatnim elementem tablicy, ktory ma byc wyzerowany.
 */
void d_array_set_zero(double *first, double *last);

/**
 * @brief Wypelnia tablice losowymi wartosciami calkowitymi z przedzialu [min, max].
 *
 * @param first wskaznik do pierwszego elementu tablicy, ktory ma byc wypelniony.
 * @param last wskaznik za ostatnim elementem tablicy, ktory ma byc wypelniony.
 * @param min poczatek przedzialu losowania.
 * @param max koniec przedzialu losowania.
 */
void i_array_set_random(int *first, int *last, int min, int max);

/**
 * @brief Wypelnia tablice losowymi wartosciami zmiennoprzecinkowymi z przedzialu [min, max].
 *
 * @param first wskaznik do pierwszego elementu tablicy, ktory ma byc wypelniony.
 * @param last wskaznik za ostatnim elementem tablicy, ktory ma byc wypelniony.
 * @param min poczatek przedzialu losowania.
 * @param max koniec przedzialu losowania.
 */
void d_array_set_random(double *first, double *last, double min, double max);

/**
 * @brief
 *
 * @param first
 * @param last
 */
double suma(double *first, double *last);

/**
 * @brief
 *
 * @param first
 * @param last
 */
double srednia(double *first, double *last);

/**
 * @brief
 *
 * @param first
 * @param last
 */
double iloczyn(double *first, double *last);

/**
 * @brief
 *
 * @param first
 * @param last
 */
double *min(double *first, double *last);

/**
 * @brief
 *
 * @param first
 * @param last
 */
double *max(double *first, double *last);

#endif