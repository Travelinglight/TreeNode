#include "TreeNode.h"
#include <string>
using namespace std;
class A {
public:
	int x;
};
class B {
public:
	int y;
};

int main() {
	{
		A a, b, c, d, i;
		B e, f, g, h;
		a.x = 11;
		b.x = 12;
		c.x = 13;
		d.x = 14;
		i.x = 1000;
		e.y = 21;
		f.y = 22;
		g.y = 23;
		h.y = 24;

		Node<A, B> Nd1(a, &e);
		Nd1.AddLft(c, &g);
		Node<A, B> *Nd2 = new Node<A, B>(b, &f);
		Nd2->AddLft(d, &h);

		Nd1.AddRgt(Nd2->getLft());
		Nd2->AddRgt(Nd1.getLft());
		Nd1.AddLft(NULL);
		Nd2->AddLft(NULL);
		Nd1.AddLft(Nd2);
		
		Node<A, B> Nd5(Nd1);
		// Nd5 = Nd1;
		cout << Nd5.getID().x << ' ' << Nd5.getRcd()->y << ' ' << Nd5.getHeight() << endl;
		cout << Nd1.getID().x << ' ' << Nd1.getRcd()->y << ' ' << Nd1.getHeight() << endl;
		Node<A, B> *Modify = Nd5.getLft();
		Modify->ModifyID(i);
		cout << Nd5.getLft()->getID().x << endl;
		Modify->getRcd()->y++;
		cout << Nd1.getLft()->getRcd()->y << endl;
		cout << Nd5.getLft()->getRcd()->y << endl;

		Node<A, int> Nd6(a, 5);
		cout << Nd6.getID().x << ' ' << *Nd6.getRcd() << ' ' << Nd6.getHeight() << endl;

		Node<string> Nd7("haha");
		cout << Nd7.getID() << endl;
		Nd7.ModifyID("hahaha");
		cout << Nd7.getID() << endl;

		Node<int> Nd8(8);
		Nd8.ModifyID(88);
	}
	system("pause");
}