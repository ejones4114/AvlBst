//
//  AvlBst.cpp
//  AVLBST
//
//  Created by Eric Jones on 11/20/22.
//

#include "AvlBst.h"
#include <iostream>
#include <math.h>

template<typename T>
AvlBst<T>::AvlBst() {
   this->root = nullptr;
   this->count = 0;
}

template<typename T>
AvlBst<T>::~AvlBst() {
   delete root;
}

template<typename T>
bool AvlBst<T>::insert(T val) {
   root = insertHelper(this->root, val);
   return true;
}

template<typename T>
bool AvlBst<T>::remove(T val) {
   return false;
}

template<typename T>
int AvlBst<T>::getHeight() {
   return getHeightHelper(this->root);
}

template<typename T>
void AvlBst<T>::displayInOrder() {
   displayInOrder(this->root);
}

template<typename T>
void AvlBst<T>::displayInOrder(TreeNode *node) {
   if(node == nullptr) {
      return;
   }
   displayInOrder(node->left);
   std::cout << node->val << std::endl;
   displayInOrder(node->right);
}


template<typename T>
typename AvlBst<T>::TreeNode* AvlBst<T>::insertHelper(TreeNode *node, T val) {
   if(node == nullptr) {
      return new TreeNode(val);
   }
   else if(node->val > val) {
      node->left = insertHelper(node->left, val);
   } else if (node->val < val) {
      node->right = insertHelper(node->right, val);
   }
   node->height = 1 + std::max(height(node->left), height(node->right));
   int bal = height(node->left) - height(node->right);
   
   if(bal < -1) {
      if(val > node->right->val) {
         return leftRotate(node);
      } else {
         node->right = rightRotate(node->right);
         return leftRotate(node);
      }
   } else {
      if(bal > 1) {
         if(val < node->left->val) {
            return rightRotate(node);
         } else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
         }
      }
   }
   return node;
}

template<typename T>
bool AvlBst<T>::removeHelper(TreeNode *node) {
   return true;
}

template<typename T>
int AvlBst<T>::getHeightHelper(TreeNode *node) {
   if(node == nullptr) {
      return -1;
   } else
      return std::max(1 + getHeightHelper(node->left), 1 + getHeightHelper(node->right));
}

template<typename T>
void AvlBst<T>::deleteTree(TreeNode *node) {
   return;
}

template<typename T>
int AvlBst<T>::height(TreeNode *node) {
   if(node == nullptr) {
      return 0;
   }
   return node->height;
}

template<typename T>
typename AvlBst<T>::TreeNode* AvlBst<T>::rightRotate(TreeNode *node) {
   TreeNode * head = node->left;
   node->left = head->right;
   head->right = node;
   node->height = 1 + (std::max(height(node->left), height(node->right)));
   head->height = 1 + (std::max(height(head->left), height(head->right)));
   return head;
}

template<typename T>
typename AvlBst<T>::TreeNode* AvlBst<T>::leftRotate(TreeNode *node) {
   TreeNode * head = node->right;
   node->right = head->left;
   head->left = node;
   node->height = 1 + (std::max(height(node->left), height(node->right)));
   head->height = 1 + (std::max(height(head->left), height(head->right)));
   return head;
}

