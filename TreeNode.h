/*
base64.cpp and base64.h

Copyright (C) 2015-2019 Kingston Chan

This source code is provided 'as-is', without any express or implied
warranty. In no event will the author be held liable for any damages
arising from the use of this code.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this source code must not be misrepresented; you must not
claim that you wrote the original source code. If you use this source code
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original source code.

3. This notice may not be removed or altered from any source distribution.

Kingston Chan 

*/
#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class NULLT {};

inline int MAX(int a, int b) {
	return a > b ? a : b;
}

//------------------------------------Tree node-----------------------------------------
template<class T1, class T2 = NULLT>
class Node {

private:
	T1 ID;
	T2 *Rcd;	// record
	Node *Lft, *Rgt;
	int height;

public:
	// constructor and destructor
	Node();
	Node(T fill);
	Node(const Node<T1, T2> &New);
	~Node();

	// modify the info of private members
	bool ModifyID(const T1 &tmp);
	bool operator=(const T &cnt, bool init);
	bool AddLft(Node<T1, T2> *lft);
	bool AddRgt(Node<T1, T2> *rgt);
	bool AddLft(T1 lftID);
	bool AddRgt(T1 rgtID);

	// get the info of private members
	Node<T1, T2> *getLft() { return Lft; }
	Node<T1, T2> *getRgt() { return Rgt; }
	int getHeight() const { return height; }
	T1 getID() const { return ID; }
	T2 getRcd() const { return Rcd; }
};

////////////////////////////////////////////////////////////////////////////////
//        NAME: Node
// DESCRIPTION: Constructor of Node class.
//   ARGUMENTS: none
// USES GLOBAL: none
// MODIFIES GL: height, Lft, Rgt
//     RETURNS: none
//      AUTHOR: Kingston Chan
// AUTHOR/DATE: KC 2015-02-05
//							KC 2015-02-05
////////////////////////////////////////////////////////////////////////////////
template<class T1, class T2 = NULLT>
Node<T1, T2>::Node() {
	height = 0;
	Rcd = new T2;
	Lft = Rgt = NULL;
}

////////////////////////////////////////////////////////////////////////////////
//        NAME: Node
// DESCRIPTION: Constructor of Node class.
//   ARGUMENTS: T fill - the content of the node
// USES GLOBAL: none
// MODIFIES GL: content, height, Lft, Rgt
//     RETURNS: none
//      AUTHOR: Kingston Chan
// AUTHOR/DATE: KC 2015-02-05
//							KC 2015-02-05
////////////////////////////////////////////////////////////////////////////////
template<class T1, class T2 = NULLT>
Node<T1, T2>::Node(T1 fill) {
	ID = fill;
	Rcd = new T2;
	Lft = Rgt = NULL;	// no sons at first
	height = 0;
}

////////////////////////////////////////////////////////////////////////////////
//        NAME: Node
// DESCRIPTION: Copy constructor of Node class, copy the content only.
//   ARGUMENTS: const Node<T> &New - the Node that is to be copied
// USES GLOBAL: none
// MODIFIES GL: content, height, Lft, Rgt
//     RETURNS: none
//      AUTHOR: Kingston Chan
// AUTHOR/DATE: KC 2015-02-05
//							KC 2015-02-05
////////////////////////////////////////////////////////////////////////////////
template<class T1, class T2 = NULLT>
Node<T1, T2>::Node(const Node<T1, T2> &New) {
	ID = New.ID;
	Rcd = new T2;
	Rcd = New.getRcd;
	height = 0;
	Lft = NULL;
	Rgt = NULL;
}

////////////////////////////////////////////////////////////////////////////////
//        NAME: ~Node
// DESCRIPTION: Destructor of Node class.
//   ARGUMENTS: none
// USES GLOBAL: none
// MODIFIES GL: content, height, Lft, Rgt
//     RETURNS: none
//      AUTHOR: Kingston Chan
// AUTHOR/DATE: KC 2015-02-05
//							KC 2015-02-05
////////////////////////////////////////////////////////////////////////////////
template<class T1, class T2 = NULLT>
Node<T>::~Node() {
	if (Lft)
		delete Lft;
	if (Rgt)
		delete Rgt;
	//cout << "delete " << content << endl;
}

////////////////////////////////////////////////////////////////////////////////
//        NAME: ModifyContent
// DESCRIPTION: To modify the content of a Node.
//   ARGUMENTS: const T &tmp - the new content value
// USES GLOBAL: none
// MODIFIES GL: content
//     RETURNS: bool
//      AUTHOR: Kingston Chan
// AUTHOR/DATE: KC 2015-02-05
//							KC 2015-02-05
////////////////////////////////////////////////////////////////////////////////
template<class T1, class T2 = NULLT>
bool Node<T>::ModifyContent(const T &tmp) {
	content = tmp;
	return true;
}

////////////////////////////////////////////////////////////////////////////////
//        NAME: operator=
// DESCRIPTION: Assignment operation of the Node's content.
//   ARGUMENTS: const T &cnt - the content that is to be assigned
// USES GLOBAL: none
// MODIFIES GL: content
//     RETURNS: bool
//      AUTHOR: Kingston Chan
// AUTHOR/DATE: KC 2015-02-05
//							KC 2015-02-05
////////////////////////////////////////////////////////////////////////////////
template<class T1, class T2 = NULLT>
bool Node<T>::operator=(const T &cnt) {
	content = cnt;
	return true;
}

////////////////////////////////////////////////////////////////////////////////
//        NAME: AddLft
// DESCRIPTION: Concatenate a left son.
//   ARGUMENTS: Node<T> *lft - the left son that is to be concatenated
// USES GLOBAL: none
// MODIFIES GL: Lft, height
//     RETURNS: bool
//      AUTHOR: Kingston Chan
// AUTHOR/DATE: KC 2015-02-05
//							KC 2015-02-05
////////////////////////////////////////////////////////////////////////////////
template<class T1, class T2 = NULLT>
bool Node<T>::AddLft(Node<T> *lft) {

	Lft = lft; // assign the left son

	// update the height
	height = 0;
	if (Lft != NULL)
		height = MAX(height, Lft->height + 1);
	if (Rgt != NULL)
		height = MAX(height, Rgt->height + 1);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
//        NAME: AddLft
// DESCRIPTION: Concatenate a left son.
//   ARGUMENTS: T lft - the content of the left son that is to be concatenated
// USES GLOBAL: none
// MODIFIES GL: Lft, height
//     RETURNS: bool
//      AUTHOR: Kingston Chan
// AUTHOR/DATE: KC 2015-02-05
//							KC 2015-02-05
////////////////////////////////////////////////////////////////////////////////
template<class T1, class T2 = NULLT>
bool Node<T>::AddLft(T lft) {

	Node *Tmp = new Node(lft);
	Tmp->Lft = 0;
	Tmp->Rgt = 0;
	Tmp->height = 0;
	Lft = Tmp;

	// update the height
	height = 0;
	if (Lft != NULL)
		height = MAX(height, Lft->height + 1);
	if (Rgt != NULL)
		height = MAX(height, Rgt->height + 1);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
//        NAME: AddRgt
// DESCRIPTION: Concatenate a right son.
//   ARGUMENTS: Node<T> *rgt - the right son that is to be concatenated
// USES GLOBAL: none
// MODIFIES GL: Rgt, height
//     RETURNS: bool
//      AUTHOR: Kingston Chan
// AUTHOR/DATE: KC 2015-02-05
//							KC 2015-02-05
////////////////////////////////////////////////////////////////////////////////
template<class T1, class T2 = NULLT>
bool Node<T>::AddRgt(Node<T> *rgt) {

	Rgt = rgt; // assign the left son

	// update the height
	height = 0;
	if (Lft != NULL)
		height = MAX(height, Lft->height + 1);
	if (Rgt != NULL)
		height = MAX(height, Rgt->height + 1);

	return true;
}

////////////////////////////////////////////////////////////////////////////////
//        NAME: AddRgt
// DESCRIPTION: Concatenate a right son.
//   ARGUMENTS: T rgt - the content of the right son that is to be concatenated
// USES GLOBAL: none
// MODIFIES GL: Rgt, height
//     RETURNS: bool
//      AUTHOR: Kingston Chan
// AUTHOR/DATE: KC 2015-02-05
//							KC 2015-02-05
////////////////////////////////////////////////////////////////////////////////
template<class T1, class T2 = NULLT>
bool Node<T1, T2>::AddRgt(T rgt) {

	Node *Tmp = new Node(rgt);
	Tmp->Lft = 0;
	Tmp->Rgt = 0;
	Tmp->height = 0;
	Rgt = Tmp;

	// update the height
	height = 0;
	if (Lft != NULL)
		height = MAX(height, Lft->height + 1);
	if (Rgt != NULL)
		height = MAX(height, Rgt->height + 1);

	return true;
}

#endif