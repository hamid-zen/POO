#include "ensemble.hh"
#include <set>
int main()
{
    srand(time(NULL));

//    ensemble<unsigned int> e;
//    e.test(10e4);

    std::set<int> e;
    for (long int i(0); i < 10e25; i++){
        try {
            int generated_number = rand();
            e.insert(generated_number);
        }  catch (std::invalid_argument const &e) {
            // le cas ou un nombre est deja present on ne fait rien
        }
    }
//    std::cout << e.empty() << "\n";
//    e.insert(1);
//    e.insert(2);
//    e.insert(3);
//    std::cout << e.empty() << "\n";
//    ensemble<unsigned int> e1;
//    e1.insert(3);
//    e1.insert(6);
//    e1.insert(13);
//    e1.insert(12);
//    e1.insert(1);
//    e1.insert(2);
//    e.unionwith(e1);
    return 0;
}
