#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

template <typename T> class ensemble
{
using type_ensemble = std::vector<T>;

public:
    ensemble() =default;
    ensemble(ensemble const &e) =default;
    ~ensemble() =default;

    bool empty() const
    {
        return _ensemble.size() == 0;
    }

    bool find(const T &e) const
    {
        return (std::find(_ensemble.begin(), _ensemble.end(), e) != _ensemble.end());
    }

    void insert(const T &e)
    {
        if (find(e))
            throw std::invalid_argument("insert: element deja present");
        _ensemble.push_back(e);
    }

    void unionwith(ensemble<T> const &e) noexcept {
        for (auto n: e._ensemble)
            try {
                insert(n);
            }  catch (std::invalid_argument const e) {
                // le cas ou un nombre est deja present on ne fait rien
            }
    }

    void test(long int number_of_values) {
        for (long int i(0); i < number_of_values; i++){
            try {
                int generated_number = rand();
                insert(generated_number);
            }  catch (std::invalid_argument const &e) {
                // le cas ou un nombre est deja present on ne fait rien
            }
        }
    }
private:
    type_ensemble _ensemble;
};
