#ifndef TERNARYTREE_H
#define TERNARY_TREE_H
#include <cstddef>
#include <vector> //vector data type

namespace kTree{
    class ternTree{
        public:
            ternTree(); 
            void insert(int); 
            void inOrderTraverse(std::vector<int>&); 
        private:
            struct node{ //ternary tree node
                node *left = NULL;
                node *right = NULL;
                node *middle = NULL;
                int lo,hi;
                enum numSet{NONE,LO,BOTH}; //flag to check which ints have been set
                numSet nflag;  
                 
                node();
                node(int); 
                node(int,int);

            };

            node* root;
            size_t size;

            void insert(int,node*);
            void addVal(int,node*);
            void inOrderTraverse(int&,std::vector<int>&,node*);

    };

    //template <class RandomAccessIterator>
    //sort (RandomAccessIterator first, RandomAccessIterator last);
};

#endif

