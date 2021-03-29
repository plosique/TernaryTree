#include "ternaryTree.h" 
#include <cassert> 
#include <algorithm>
#include <iostream> 
#include <vector>  //vector data type

using namespace kTree; 



ternTree::node::node(){
    nflag = NONE;
}

ternTree::node::node(int val):lo(val){
    nflag = LO;
}

ternTree::node::node(int l,int h):lo(l),hi(h){
    nflag = BOTH;
}

ternTree::ternTree(){
    this->root = new node();
    this->size = 0;
}


void ternTree::insert(int ins){
    insert(ins,this->root); 
}


void ternTree::insert(int ins,node* cur){
    assert(cur != NULL);

    if(cur->nflag!=node::BOTH){
        addVal(ins,cur); 
    }else{
        if(ins<cur->lo){
            if(cur->left == NULL){
                cur->left = new node(); 
            }
            insert(ins,cur->left);
        }else if(ins<cur->hi){
            if(cur->middle == NULL){
                cur->middle = new node(); 
            }
            insert(ins,cur->middle);
        }else{
            if(cur->right == NULL){
                cur->right = new node();
            }
            insert(ins,cur->right);
        }
    }
    
}

void ternTree::addVal(int ins,node *cur){
    assert(cur->nflag==node::NONE || cur->nflag == node::LO ); // should only be called when cur->nflag is NONE or LO

    if(cur->nflag==node::NONE){
        cur->lo = ins;
        cur->nflag = node::LO;
    }else if(cur->nflag == node::LO){
        cur->hi = ins;
        if(cur->lo>cur->hi){
            std::swap(cur->lo,cur->hi);
        }
        cur->nflag = node::BOTH; 
    }


    this->size++;
} 

void ternTree::inOrderTraverse(std::vector<int> &order){
    if(this->size == 0){
        std::cerr<<"Tree is empty"<<std::endl;
        return; 
    }
    if(order.size() < this->size){
        std::cerr<<"input vector is too small"<<std::endl;
        return;
    }
    int id = 0;
    inOrderTraverse(id,order,this->root);
    
    
}

void ternTree::inOrderTraverse(int &id,std::vector<int>& order,node* cur){
    if(cur == NULL || cur->nflag == node::NONE ){
        return;
    }
    inOrderTraverse(id,order,cur->left); 
    order[id] = cur->lo; 
    id++; 

    inOrderTraverse(id,order,cur->middle);

    if(cur->nflag == node::BOTH){
        order[id] = cur->hi;
        id++;
        inOrderTraverse(id,order,cur->right);     
    }

}



