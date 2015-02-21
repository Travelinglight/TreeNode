TreeNode(C++)
================
This is a template class in c++. It is used for tree-like data structure, such as AVL tree, Splay tree, etc. 
Template
----------------
- **T1** &#160;the ID to identify a node;
- **T2** &#160;the record or the content of a node;

Members
----------------
- **T1 ID** &#160;The ID to identify a node;
- **T2 Rcd** &#160;The record or the content of a node;
- **Node \*Lft** &#160;The left son of the current node;
- **Node \*Rgt** &#160;The right son of the current node;
- **int height** &#160;The height of the node;

User Interface
----------------
- **Node()** &#160;The default constructor of the Node class;
- **Node(const T1 &id, const T2 \* const rcd = NULL)** &#160;The constructor of the Node with ID and the record pointer, which has the default value NULL;
- **Node(const T1 &id, const T2 &rcd)** &#160;The constructor of the Node with the ID and the record;
- **Node(const Node<T1, T2> &New)** &#160;The copy constructor of the Node;
- **~Node()** &#160;The destructor of the Node class;
- **bool setID(const T1 &tmp)** &#160;To modify the ID of a Node;
- **bool setHeight(int h)** &#160;To modify the height of a Node;
- **bool operator=(const Node<T1, T2> &b)** &#160;To copy the Node ID and Record of another node, but remain the sons;
- **bool operator=(const T1 &id)** &#160;To assign the ID of a Node;
- **bool copy(const Node<T1, T2> \* const b)** &#160;To copy the Node including its sons;
- **bool AddLft(Node<T1, T2> \*lft)** &#160;To assign the Node with a left son Node, but not delete the original left son. The height is updated automatically;
- **bool AddRgt(Node<T1, T2> \*rgt)** &#160;To assign the Node with a right son Node, but not delete the original right son;The height is updated automatically;
- **bool AddLft(const T1 &lftID, const T2 \* const lftRcd = NULL)** &#160;To create and add a left son to the current Node, without deleting the original left son;The height is updated automatically;
- **bool AddRgt(const T1 &rgtID, const T2 \* const RgtRcd = NULL)** &#160;To create and add a right son to the current Node, without deleting the original right son;The height is updated automatically;
- **Node<T1, T2> \*getLft()** &#160;To get the pointer to the left son;
- **Node<T1, T2> \*getRgt()** &#160;To get the pointer to the right son;
- **int getHeight()** &#160;To get the height of the Node;
- **const T1 &getID()** &#160;To get the ID of the Node, without allowing modification;
- **T2 \*getRcd()** &#160;To get the pointer to the record of the Node, allowing modification; 
- **void print()** &#160;To print the Node. This function can be used only if the print functions has been defined for T1 class;

Notice
----------------
- if you want to add a NULL children, you should use tpye cast like (Node<T1, T1>*)NULL;
