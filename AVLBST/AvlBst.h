//
//  AvlBst.hpp
//  AVLBST
//
//  Created by Eric Jones on 11/20/22.
//

#ifndef AvlBst_h
#define AvlBst_h

#include <stdio.h>

template <typename T>


class AvlBst {

   struct TreeNode {
      T val;
      TreeNode *left;
      TreeNode *right;
      int height;
      
      TreeNode(T value) {
         this->val = value;
         left = nullptr;
         right = nullptr;
         height = 1;
      }
   };
   
   public :
   AvlBst();
   ~AvlBst();
   bool insert(T val);
   bool remove(T val);
   int getHeight();
   void displayInOrder();
private:
   
   TreeNode* insertHelper(TreeNode *node, T val);
   bool removeHelper(TreeNode *node);
   int getHeightHelper(TreeNode *node);
   void deleteTree(TreeNode *node);
   void displayInOrder(TreeNode *node);
   int height(TreeNode *node);
   TreeNode* leftRotate(TreeNode *node);
   TreeNode* rightRotate(TreeNode *node);
   
   
   
   TreeNode *root;
   int count;
   
   
};


#endif /* AvlBst_h */
