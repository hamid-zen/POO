#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

std::vector<int> saisie(){
    std::vector<int> result;

    int number_of_elements = rand()%20;

    for (int i(0); i<number_of_elements; i++)
        result.push_back(rand()%10);

    return result;
}

int max_vecteur_indice(const std::vector<int> &v){
    int max_value = v[0];

    for (std::vector<int>::size_type i(0); i!=v.size(); i++)
        if (v[i] > max_value)
            max_value = v[i];

    return max_value;
}

int max_vecteur_itterator(const std::vector<int> &v){
    int max_value = v[0];

    for (auto i(v.begin()); i!=v.end(); i++)
        if (*i > max_value)
            max_value = *i;

    return max_value;
}

int max_vecteur_intervalLoop(const std::vector<int> &v){
    int max_value = v[0];

    for (auto value:v)
        if (value > max_value)
            max_value = value;

    return max_value;
}

int main() {
    srand(time(NULL));

    std::vector<int> v1 = saisie(); // Construction à vide
    for (auto i : v1)
        std::cout << i << " ";
    std::cout<<"\n";

    std::cout<<"max_indice = "<<max_vecteur_indice(v1)<<"\n";
    std::cout<<"max_itterator = "<<max_vecteur_itterator(v1)<<"\n";
    std::cout<<"max_intervalLoop = "<<max_vecteur_intervalLoop(v1)<<"\n";

//    for (int i(0); i<10; i++)
//        v1.push_back(i);
//    std::vector<int> v2(v1); // Construction par recopie
//    // Parcours par indice
//    for (std::vector<int>::size_type i(0); i<v1.size(); ++i)
//        std::cout << v1[i];
//    // Parcours par itérateur
//    for (std::vector<int>::const_iterator i(v1.begin()); i!=v1.end(); ++i)
//        std::cout << *i;
//    // Parcours et modification par itérateur
//    for (std::vector<int>::iterator i(v1.begin()); i!=v1.end(); ++i)
//        *i = *i +1;
//    // Parcours et modification par itérateur
//    for (auto i(v1.begin()); i!=v1.end(); ++i)
//        *i = *i +1;
//    // Parcours par boucle for d'intervalle (valeur)
//    for (auto i : v1)
//        std::cout << i << " ";
//    // Parcours par boucle for d'intervalle (référence)
//    for (auto & i : v1)
//        i *= 2;
//    // Utilisation de l'opérateur d'affectation.
//    v2 = v1;
    return 0;
}
