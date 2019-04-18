#ifndef ARRAY_ASSIST_FUNCTIONS_H
#define ARRAY_ASSIST_FUNCTIONS_H
#include <cstdlib>
#include <assert.h>

namespace array_assist
{

template <typename T>
void insert(T* array, std::size_t &numbUsed, std::size_t pos, const T &item);

template <typename T>
void split(T* array, std::size_t &numbUsed, std::size_t pos, T* array_destination, std::size_t &destUsed);

template <typename T>
std::size_t get_sorted_index(T* array, std::size_t numbUsed, const T &item);

template <typename T>
void copy(const T* array, const std::size_t numbUsed, T* destination);

template <typename T>
void remove(T* array, std::size_t &numbUsed, std::size_t pos);

}

template <typename T>
void array_assist::insert(T* array, std::size_t &numbUsed, std::size_t pos, const T &item)
{
    T last_val = item, current_val;
    for(pos; pos < numbUsed; pos++)
    {
        current_val = array[pos];
        array[pos] = last_val;
        last_val = current_val;
    }

    array[numbUsed] = last_val;
    numbUsed++;
}

template <typename T>
void array_assist::remove(T* array, std::size_t &numbUsed, std::size_t pos)
{
    assert (pos < numbUsed);
    for(int i = pos+1; i < numbUsed; i++)
        array[i-1] = array[i];
    numbUsed--;
}

template <typename T>
void array_assist::split(T* array, std::size_t &numbUsed, std::size_t pos, T* array_destination, std::size_t &destUsed)
{
    if(!numbUsed)
        return;

    destUsed = 0;
    std::size_t total = numbUsed;
    for(std::size_t i = pos; i < total; i++)
    {
        destUsed++;
        numbUsed--;
        *(array_destination + (i - pos)) = *(array + i);
    }
}

template <typename T>
std::size_t array_assist::get_sorted_index(T* array, std::size_t numbUsed, const T &item)
{
    if(!numbUsed)
        return 0;

    std::size_t i = 0;
    while(array[i] < item && i < numbUsed)
        i++;
    return i;
}

template <typename T>
void array_assist::copy(const T* array,  const std::size_t numbUsed, T* destination)
{
    for(std::size_t i = 0; i < numbUsed; i++)
        destination[i] = array[i];
}

#endif // ARRAY_ASSIST_FUNCTIONS_H
