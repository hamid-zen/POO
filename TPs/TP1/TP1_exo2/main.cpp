#include <iostream>
#include <string>
#include <cmath>

int nbOccurences(std::string s, char c){
    int result(0);
    for(auto caractere : s)
        // Pour les besoins de la fonction nbVoyelles on transforme en minuscule
        if (tolower(caractere) == c)
            result++;
    return result;
}

int nbVoyelles(std::string s){
    // On init un tableau de voyelles
    std::string voyelles("aeyiuo");

    int result(0);

    // Pour chaque voyelle on calcule le nombre d'occurences
    for(char c : voyelles)
        result += nbOccurences(s, c);

    return result;
}

bool palindrome(std::string s){
    if (s == "")
        return true;
    if (s.at(0) != s.at(s.length()-1))
        return false;
    return palindrome(s.substr(1, s.length()-2));
}

std::string chiffrer(std::string s, int decalage){

    // On commence par initaliser notre resultat
    std::string result("");

    for(char c:s){

        char lettreChifree = c;

        // On check si le char est une lettre min
        if((c<91) and (c>64))
            // On calcule la lettre chifrée de la lettre dans l'alphabet
            lettreChifree = (((c-65)+decalage)%26)+65;
        else if ((c<123) and (c>96))
            // On calcule la lettre chifrée de la lettre dans l'alphabet
            lettreChifree = (((c-97)+decalage)%26)+97;

        result += lettreChifree;
    }
    return result;
}

std::string dechiffrer(std::string s, int decalage){

    // On commence par initaliser notre resultat
    std::string result("");

    for(char c:s){

        char lettreChifree = c;

        // On check si le char est une lettre min
        if((c<91) and (c>64))
            // On calcule la lettre chifrée de la lettre dans l'alphabet
            lettreChifree = (((c-65)-decalage+26)%26)+65;
        else if ((c<123) and (c>96))
            // On calcule la lettre chifrée de la lettre dans l'alphabet
            lettreChifree = (((c-97)-decalage+26)%26)+97;

        result += lettreChifree;
    }
    return result;
}

int int_of_string(std::string chiffre){
    if(chiffre == "")
        return 0;
    else
        return ((chiffre.at(0)-48)*pow(10, chiffre.length()-1))+int_of_string(chiffre.substr(1, chiffre.length()-1));
}

int main()
{

//    int n = nbVoyelles("HAmid zenine");
//    std::cout<<n;

//    std::cout<<palindrome("radar")<<"\n";
//    std::cout<<palindrome("cooc")<<"\n";
//    std::cout<<palindrome("toto")<<"\n";

//    std::cout<<"ABCabcxyzXYZ.?/.: \n";
//    std::cout<<chiffrer("ABCabcxyzXYZ.?/.:", 3)<<"\n";
//    std::cout<<dechiffrer(chiffrer("ABCabcxyzXYZ.?/.:", 3), 3)<<"\n";

//    std::cout<<int_of_string("1234")<<"\n";
//    std::cout<<int_of_string("")<<"\n";
//    std::cout<<int_of_string("34")<<"\n";

    return 0;
}
