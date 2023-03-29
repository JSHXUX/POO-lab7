#include "Vector.h"
int main()
{
	Vector<int> s;
	s.push(1);
	s.push(17);
	s.push(8);
	s.push(15);
	s.insert(2, 100);
	s.sort(compare);
	s.print();
	int var = s.get(3);
	printf("%d\n", s.firstIndexOf(var));
	s.set(3, s.counter());
	s.set(0, 8);
	s.set(1, 9);
	s.print();
	printf("%d\n", s.firstIndexOf(8,equal));

	Vector<char> t;
	t.push('a');
	t.push('c');
	t.push('z');
	t.push('f');
	t.insert(2, 'p');
	t.sort(compare);
	t.print();
	char var2 = t.get(3);
	printf("%d\n", t.firstIndexOf(var2));
	t.set(3, 't');
	t.set(0, 'x');
	t.set(1, 'y');
	t.print();
	printf("%d\n", t.firstIndexOf('x', equal));
	return 0;
}