#include "ternaryTree.h" 
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <cassert>      // assert
#include <iostream> //cerr cout 


using namespace kTree; 

size_t string2Int(const std::string& args){
    if(args.size() > 8){
        std::cerr<<"Please keep array size less than 9 decimal places"<<std::endl; 
        exit(0);
    }
    size_t res = 0;
    for(auto it=args.rbegin();it!=args.rend();it++){
        int val = *it - '0';
        if(val<0 || val>9){
            std::cerr<<"Invalid number"<<std::endl;
            exit(0); 
        }
        res+=val;
        res*=10; 
        
    }
    return res; 

}

int main(int argc,char *argv[]){
    if(argc != 2){
        std::cerr<<"Usage: test <size of arr>"<<std::endl;
        return 0;
    }
    std::string args(argv[1]); 
    size_t vecSize = string2Int(args); 
    std::vector<int> vec(vecSize) ; 
    for(size_t i=0;i<vecSize;i++){
        vec[i] = i;
    }
    std::random_shuffle (vec.begin(), vec.end() );
    ternTree* tree = new ternTree();
    for(int c : vec){
        tree->insert(c);
    }
    std::vector<int> sortedVec(vecSize);
    tree->inOrderTraverse(sortedVec);

    for(size_t i=0;i<vecSize;i++){
        assert(sortedVec[i] == vec[i]); 
    } 




}
