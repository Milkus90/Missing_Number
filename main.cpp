
/* Task 2
 *
 * You are given all numbers between 1,2,…,n except one. Your task is to find the missing number.
 *
 * Output:
 * Print the missing number. */

#include <iostream>
#include <set>

// fillSet + removeRandom just to create set with random missing number

void fillSet(std::set<int> &set, const int n){
    for(int i = 1 ; i <= n ; i++){
        set.insert(i);
    }
}

void removeRandom(std::set<int> &set){
    srand(long(&set));
    int n = set.size();
    int r = (rand()%n)+1;
    set.erase(r);
    std::cout << "The drawn and removed number is: " << r << std::endl;
}


void findMissing(const std::set<int> set){

    // zadanie dotyczyło zbioru nie nieposortowanego, stad taki sposob sprawdzania, ktorej liczby brakuje
    // moze kiedys dopisze stworzenie nieposegregowanego zbioru z losowo brakujaca liczba
    // dla posortowanego najlepiej byloby binary searchem?

    for (int i = 1 ; i <= (int(set.size())+1) ; i++){
        bool found = false;
        for(std::set<int>::iterator it = set.begin() ; it != set.end() ; it ++){
            if (i == *it){
                // std::cout << "The number: " << i << " is in the set.\n";
                break;
            } else if(it == (--set.end())){
                found = true;
                std::cout << "The missing number is: " << i << std::endl;
                break;
            }

        }
        if(found) break;     // to break the loop after the missing number is found,
                            //couse we know there is only one missing and there is no need to check the rest
    }
}



int main()
{
    int n = 30;

    //std::cout << "Define the the set size: ";
    //std::cin >> n;

    std::set<int> set;
    fillSet(set, n);
    std::cout << "Your set: \n";

    for(std::set<int>::iterator it = set.begin() ; it != set.end() ; it++){
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    removeRandom(set);
    std::cout << "Set with the random number removed: \n";

    for(std::set<int>::iterator it = set.begin() ; it != set.end() ; it++){
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
    findMissing(set);
    return 0;
}
