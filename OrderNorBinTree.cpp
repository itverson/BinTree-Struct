#include<iostream>
#include<stack>
#include<queue>
#include<unistd.h>
using namespace std;
template<class T>
struct BinTreeNode
{
    BinTreeNode<T>* _pLeft;
	BinTreeNode<T>* _pRight;
	T _data;
  BinTreeNode(const T& data)
		  :_data(data)
		   ,_pLeft(NULL)
		   ,_pRight(NULL){}  
};
template<class T>
class BinTree
{
 public:		
   typedef BinTreeNode<T> Node;
   typedef Node* PNode;
 private:
   PNode _pRoot;
 public:
   BinTree()
		   :_pRoot(NULL){} 
   void CreatBinTree(const T* arr,const int size,const T& invalue)
   {
        int index=0;
		_CreatBinTree(_pRoot,arr,size,index,invalue); 
    }
   
   void preOrder() 
   {
       _preOrder(_pRoot);
	   cout<<endl;
   } 
   
   void inOrder() 
   {
       _inOrder(_pRoot);
	   cout<<endl;
   }
   void postOrder() 
   {
       _postOrder(_pRoot);
	   cout<<endl;
   }
   void inOrderNor()
   {
       if(_pRoot==NULL)
			   return;
	   PNode cur=_pRoot;
	   stack<PNode> s; 
	   while(cur||!s.empty())
	   {
	         while(cur)
			 {
			    s.push(cur);
				cur=cur->_pLeft;
			 } 
			 cur=s.top();
			 s.pop();
			   cout<<cur->_data<<" ";		 
			if(cur->_pRight)
			{
			   cur=cur->_pRight;
			}
			else
			{
			   cur=NULL;
			} 
	   } 
	   cout<<endl;
   } 
   void preOrderNorone()
   {
       if(_pRoot==NULL)
			   return;
	   PNode cur=_pRoot;
	   stack<PNode> s; 
	   while(cur||!s.empty())
	   {
	         while(cur)
			 {
			   cout<<cur->_data<<" ";		 
			    s.push(cur);
				cur=cur->_pLeft;
			 } 
			 cur=s.top();
			 s.pop();
			if(cur->_pRight)
			{
			   cur=cur->_pRight;
			}
			else
			{
			   cur=NULL;
			} 
	   } 
	   cout<<endl;
   } 
   void preOrderNortwo()
   {
       if(_pRoot==NULL)
	      return;
	   PNode cur=_pRoot;
	   stack<PNode> s;
	   while(cur||!s.empty())
	   {
	        if(cur)
			cout<<cur->_data<<" ";
			if(cur->_pRight)
			{
			   s.push(cur->_pRight); 
			}
			if(cur->_pLeft)
			{
			   s.push(cur->_pLeft); 
			} 
           if(!s.empty())
		   {
		       cur=s.top();
			   s.pop(); 
		   } 
		   else
		   {
		      cur=NULL;
		   } 
	   } 
	   cout<<endl;
   } 
   void postOrderNor() 
   {
      if(_pRoot==NULL)
			  return;
	  PNode cur=_pRoot;
	  PNode pre=NULL;
	  stack<PNode> s;
	  while(cur||!s.empty())
	  {
	     while(cur&&cur!=pre)
		 {
		    s.push(cur);
			cur=cur->_pLeft;
		 } 
		 if(s.empty())
		 {
				 cout<<endl;
				 return; 
		 } 
	     cur=s.top();
		 if(cur->_pRight&&cur->_pRight!=pre)
		 {
		         cur=cur->_pRight;
		 } 
		 else
		 {
		   cout<<cur->_data<<" ";
		   s.pop(); 
		   pre=cur;
		 } 
	  } 
   } 
   void leveOrder() 
   {
       if(_pRoot==NULL)
			   return;
	   PNode cur=_pRoot;
	   queue<PNode> s;
	   while(cur||!s.empty())
	   {
	       if(cur)
				   cout<<cur->_data<<" ";
		   if(cur->_pLeft)
				   s.push(cur->_pLeft);
	       if(cur->_pRight)
				   s.push(cur->_pRight);
		   if(!s.empty()) 
		   {
				   cur=s.front();
                    s.pop(); 
		   }else
		   {
		   cur=NULL;
		   } 
	   } 
	   cout<<endl;
   }
 private:
   void _CreatBinTree(PNode& pRoot,const T* arr,const int size,int& index,const T& invalue)
   {
	  if(index<size&&arr[index]!=invalue)
	  {
	      pRoot=new Node(arr[index]); 
	      _CreatBinTree(pRoot->_pLeft,arr,size,++index,invalue); 
	      _CreatBinTree(pRoot->_pRight,arr,size,++index,invalue); 
	  } 
   } 
   void _preOrder(PNode pRoot)
   {
       if(pRoot)
	   {
	      cout<<pRoot->_data<<" ";
		  _preOrder(pRoot->_pLeft); 
		  _preOrder(pRoot->_pRight); 
	   } 
   } 
   void _inOrder(PNode pRoot)
   {
       if(pRoot)
	   {
		  _inOrder(pRoot->_pLeft); 
	      cout<<pRoot->_data<<" ";
		  _inOrder(pRoot->_pRight); 
	   } 
   } 
   void _postOrder(PNode pRoot)
   {
       if(pRoot)
	   {
		  _postOrder(pRoot->_pLeft); 
		  _postOrder(pRoot->_pRight); 
	      cout<<pRoot->_data<<" ";
	   } 
   } 
}; 
int main()
{
	char arr[]="ABD##E##CF###";
	int size=sizeof(arr)/sizeof(*arr);
	BinTree<char> s;
	s.CreatBinTree(arr,size,'#'); 
s.preOrder();
	s.preOrderNorone();
	s.preOrderNortwo(); 
	s.inOrderNor(); 
	s.inOrder(); 
	s.postOrder(); 
	s.postOrderNor(); 
	s.leveOrder(); 
  s.preOrder(); 
   return 0;
} 
