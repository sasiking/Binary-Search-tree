#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class BinTree{
public:
    struct btree{
        int data;
        btree *left,*right;
    }*tree;
    BinTree()
    {
        tree=NULL;
    }
    btree* insert(btree *tree,int val)
    {
        if(tree==NULL){
        btree *temp;
        temp = new btree;
        temp->data=val;
        temp->left=NULL;
        temp->right=NULL;
        tree=temp;
        }
        else if(tree->data>val)
        tree->left=insert(tree->left,val);
        else
        tree->right=insert(tree->right,val);
        return(tree);
    }//fun closed
    int search(btree *tree,int val)
    {
        if(tree==NULL)
        return(0);
        else if(tree->data==val)
        return(1);
        else if(val<tree->data)
        return(search(tree->left,val));
        else
        return(search(tree->right,val));
    }//func closed
    void inorder(btree *tee)
    {
        if(tee==NULL)
        return;
        if(tee!=NULL){
        inorder(tee->left);
        cout<<tee->data<<" ";
        inorder(tee->right);
        }//if closed
    }// func closed
    void preorder(btree *tee)
    {
        if(tee==NULL)
        return;
        if(tee!=NULL){
        cout<<tee->data<<" ";
        preorder(tee->left);
        preorder(tee->right);
        }//if closed
    }//func closed
    void postorder(btree *tee)
    {
        if(tee==NULL)
        return;
        if(tee!=NULL){
        postorder(tee->left);
        postorder(tee->right);
        cout<<tee->data<<" ";
        }//if closed
    }//func closed
    btree* FindMax(btree *tee)
    {
        if(tee==NULL)
        return(NULL);
        else if(tee->right==NULL)
        return(tee);
        else
        return(FindMax(tee->right));
    }//func closed
    btree* Delete(btree *t,int val)
    {
        btree *temp,*temp1;
        temp=t;
        temp1=NULL;
        if(val<temp->data)
        temp->left=Delete(temp->left,val);
        else if(val>temp->data)
        temp->right=Delete(temp->right,val);
        else{
            if((temp->left!=NULL)&&(temp->right!=NULL)){
            temp1=FindMax(temp->left);
            temp->data=temp1->data;
            temp->left=Delete(temp->left,temp->data);
        }//if closed
        else if((temp->left==NULL)&&(temp->right==NULL))
        temp=NULL;
        else{
            if(temp->left!=NULL)
            temp=temp->left;
            else
            temp=temp->right;
            }//else closed
        }//else2 closed
        return(temp);
    }//func closed
};//class closed
void main()
{
    BinTree b;
    BinTree::btree *tre,*tri;
    tre=NULL;
    tri=NULL;
    int n,ch,m;
    clrscr();
    do{
        cout<<"\n1.Insert\n2.Search\n3.PreOrder\n4.InOrder\n5.PostOrder\n6.FindMax\n7.Delete\n8.Exit";
        cout<<"\nEnter your choice \n";
        cin>>ch;
        clrscr();
        switch(ch){
            case 1:cout<<"Enter value to insert\n";
                   cin>>n;
                   tre=b.insert(tre,n);
                   break;
            case 2:cout<<"Enter an Element to search\n";
                   cin>>n;
                   m=b.search(tre,n);
                   if(m==1)
                   cout<<"\nElement found";
                   if(m==0)
                   cout<<"\nElement not found";
                   break;
            case 3:b.preorder(tre);
                   break;
            case 4:b.inorder(tre);
                   break;
            case 5:b.postorder(tre);
                   break;
            case 6:tri=b.FindMax(tre);
                   cout<<"\nLargest Element in Tree = "<<tri->data;
                   break;
            case 7:cout<<"Enter the Element you want to Delete \n";
                   cin>>n;
                   m=b.search(tre,n);
                   if(m==0)
                   cout<<"Entered Element Not Found";
                   else{
                   tre=b.Delete(tre,n);
                   cout<<"Deleted Element = "<<n;
                   }
                   break;
            case 8:exit(0);
        }
    }while(ch>=1&&ch<=8);
    getch();
}