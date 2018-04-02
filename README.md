TreeNode(C++)
================

This is a template class implemented in c++. It is used for tree-like data structure, such as AVL tree, Splay tree, etc. 

Template
----------------
- **T1** &#160;the ID of a node;
- **T2** &#160;the record or the content of a node.

Members
----------------
- **T1 ID** &#160;The ID of a node;
- **T2 Rcd** &#160;The record or the content of a node;
- **Node \*Lft** &#160;The left child of the current node;
- **Node \*Rgt** &#160;The right child of the current node;
- **int height** &#160;The height of the node.

User Interface
----------------
- **Node()** &#160;The default constructor of the Node class;
- **Node(const T1 &id, const T2 \* const rcd = NULL)** &#160;The constructor of the Node with ID and the record pointer, which has the default value NULL;
- **Node(const T1 &id, const T2 &rcd)** &#160;The constructor of the Node with the ID and the record;
- **Node(const Node<T1, T2> &New)** &#160;The copy constructor of the Node;
- **~Node()** &#160;The destructor of the Node class;
- **bool setID(const T1 &tmp)** &#160;Modify the ID of a Node;
- **bool setHeight(int h)** &#160;Modify the height of a Node;
- **bool operator=(const Node<T1, T2> &b)** &#160;Copy the Node ID and Record of another node, but keep the children;
- **bool operator=(const T1 &id)** &#160;Assign an ID to a Node;
- **bool copy(const Node<T1, T2> \* const b)** &#160;Copy the Node including its children;
- **bool AddLft(Node<T1, T2> \*lft)** &#160;Assign the Node with a left child Node rather than delete the original left child. The height is updated automatically;
- **bool AddRgt(Node<T1, T2> \*rgt)** &#160;Assign the Node with a right child Node rather than delete the original right child. The height is updated automatically;
- **bool AddLft(const T1 &lftID, const T2 \* const lftRcd = NULL)** &#160;Create and add a left child to the current Node, without deleting the original left child. The height is updated automatically;
- **bool AddRgt(const T1 &rgtID, const T2 \* const RgtRcd = NULL)** &#160;Create and add a right child to the current Node, without deleting the original right child. The height is updated automatically;
- **Node<T1, T2> \*getLft()** &#160;Get the pointer to the left child;
- **Node<T1, T2> \*getRgt()** &#160;Get the pointer to the right child;
- **int getHeight()** &#160;Get the height of the Node;
- **const T1 &getID()** &#160;Get the ID of the Node, without allowing modification;
- **T2 \*getRcd()** &#160;Get the pointer to the record of the Node, allowing modification; 
- **void print()** &#160;Print the Node. This function can be used only if the print functions have been defined for T1 class.

Notice
----------------
- If you want to add a NULL child, you should use type cast like (Node<T1, T1>*)NULL.
