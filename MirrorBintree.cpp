
 void MirrorBintree()
 {
   // _MirrorBintree_one(_pRoot); 
    _MirrorBintree_two(_pRoot); 
 } 
 /*void _MirrorBintree_one(PNode pRoot)
 {
     if(pRoot==NULL&&pRoot->_pLeft==NULL&&pRoot->_pRight==NULL)
	        return;
	 PNode temp=pRoot->_pLeft;
	 pRoot->_pLeft=pRoot->_pRight;
	 pRoot->_pRight=temp;
	 if(pRoot->_pLeft)
			 _MirrorBintree_one(pRoot->_pLeft);
	 if(pRoot->_pRight)
			 _MirrorBintree_one(pRoot->_pRight); 
 } */
 void _MirrorBintree_two(PNode pRoot)
 {
      if(pRoot==NULL)
			  return;
	  stack<PNode> s;
	  s.push(pRoot);
	  while(!s.empty())
	  {
	       PNode cur=s.top();
		   s.pop();  
		   std::swap(cur->_pLeft,cur->_pRight);
		 if(cur->_pLeft)
				 s.push(cur->_pLeft);
		 if(cur->_pRight)
		         s.push(cur->_pRight); 
	  } 
 } 
