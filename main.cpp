#include "KMP.h"

#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector< std::vector< int > > matrix;

void find_accurate(int pattern_n, int pattern_m, int img_n, int img_m, matrix& pattern, matrix& img){
    //  ищем каждую строку паттерна в каждой строке изображения. Работает это за куб.
    std::vector< std::vector< std::vector< int > > > matches;
    matches.resize(img_n);
    for(int i = 0; i < img_n; ++i) {
        matches[i].resize(pattern_n);
    }
    for(int i = 0; i < img_n; ++i){
        for(int j = 0; j < 	pattern_n; ++j){
            KMP kmp = KMP(pattern[j], img[i]);
            matches[i][j] = kmp.find();
        }
    }

    //  ищем по матрице найденных совпадений строк вхождения паттерна в изображение. Так как
    //  мы уже получили куб в асимптотике, тут не будем заморачиваться и просто наивно пройдемся за тот же куб.

    /*for(int i = 0; i < matches.size(); ++i){
        for(int j = 0; j < matches[i].size(); ++j){
            for(int k = 0; k < matches[i][j].size(); ++k){
                std::cout << matches[i][j][k] << ",";
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }*/

    for(int i = 0; i < img_n - pattern_n + 1; ++i){
        std::vector< int > possible = matches[i][0];
        int j = 1;
        while(possible.size() > 0 && j < pattern_n){
            int k = 0;
            while(k < possible.size()){
                if(std::find(matches[i][j].begin(), matches[i][j].end(), possible[k]) == matches[i][j].end()){
                    possible.erase(possible.begin() + k);
                } else{
                    ++k;
                }
            }
            ++j;
        }
        for(int k = 0; k < possible.size(); ++k){
            std::cout << "FOUND PATTERN on " << i << " " << possible[k] << "\n";
        }
    }
}

void find_approximate(int pattern_n, int pattern_m, int img_n, int img_m, matrix& pattern, matrix& img){
	// same code as in previous

	//  ищем каждую строку паттерна в каждой строке изображения. Работает это за куб.
    std::vector< std::vector< std::vector< int > > > matches;
    matches.resize(img_n);
    for(int i = 0; i < img_n; ++i) {
        matches[i].resize(pattern_n);
    }
    for(int i = 0; i < img_n; ++i){
        for(int j = 0; j < 	pattern_n; ++j){
            KMP kmp = KMP(pattern[j], img[i]);
            matches[i][j] = kmp.find();
        }
    }

    //  ищем по матрице найденных совпадений строк вхождения паттерна в изображение. Так как
    //  мы уже получили куб в асимптотике, тут не будем заморачиваться и просто наивно пройдемся за тот же куб.

    /*for(int i = 0; i < matches.size(); ++i){
        for(int j = 0; j < matches[i].size(); ++j){
            for(int k = 0; k < matches[i][j].size(); ++k){
                std::cout << matches[i][j][k] << ",";
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }*/

    for(int i = 0; i < img_n - pattern_n + 1; ++i){
        std::vector< int > possible = matches[i][0];
        int j = 1;
        while(possible.size() > 0 && j < pattern_n){
            int k = 0;
            while(k < possible.size()){
                if(std::find(matches[i][j].begin(), matches[i][j].end(), possible[k]) == matches[i][j].end()){
                    possible.erase(possible.begin() + k);
                } else{
                    ++k;
                }
            }
            ++j;
        }
        for(int k = 0; k < possible.size(); ++k){
            std::cout << "FOUND PATTERN on " << i << " " << possible[k] << "\n";
        }
    }
}


int main(){
    //  считываем изображения
    int pattern_n, pattern_m, img_n, img_m;
    matrix pattern, img;

    std::cout << "Size of image (n, m):\n";

    std::cin >> img_n >> img_m;
    img.resize(img_n);

    for(int i = 0; i < img_n; ++i){
        img[i].resize(img_m);
    }

    std::cout << "Image:\n";

    for(int i = 0; i < img_n; ++i){
        for(int j = 0; j < img_m; ++j){
            std::cin >> img[i][j];
        }
    }


    std::cout << "Size of pattern (n, m):\n";

    std::cin >> pattern_n >> pattern_m;
    pattern.resize(pattern_n);

    for(int i = 0; i < pattern_n; ++i){
        pattern[i].resize(pattern_m);
    }


    std::cout << "Pattern:\n";

    for(int i = 0; i < pattern_n; ++i){
        for(int j = 0; j < pattern_m; ++j){
            std::cin >> pattern[i][j];
        }
    }

    std::cout << "Type of find (1 - accurate, 2 - approximate): ";

    int type;
    std::cin >> type;

    if(type == 1) {
        find_accurate(pattern_n, pattern_m, img_n, img_m, pattern, img);
    } else {
        find_approximate(pattern_n, pattern_m, img_n, img_m, pattern, img);
    }





    return 0;
}
/* for(int i = 0; i < matches.size(); ++i){
     for(int j = 0; j < matches[i].size(); ++j){
         for(int k = 0; k < matches[i][j].size(); ++k){
             std::cout << matches[i][j][k] << ",";
         }
         std::cout << " ";
     }
     std::cout << "\n";
 }
*/