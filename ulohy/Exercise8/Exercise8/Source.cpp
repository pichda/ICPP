#include "Matrix.h"

int main(int argc, char** argv) {
	Matrix<int> m{ 3,3 };
	int jednodpole[] = { 0,1,2,3,4,5,6,7,8 };
	m.SetMatrixFrom(jednodpole);
	Matrix<int> mt = m.Transposition();
	mt.PrintMatrix();
	Matrix<int> maa = m.Sum(mt);
	maa.PrintMatrix();
	Matrix<int> ma = m.Sum(2);
	Matrix<int> md = m.Product(2);
	Matrix<int> mmt = m.Product(mt);
	Matrix<double> mmt_d = mmt.Parse<double>();
	Matrix<double> n_d{ 3,3 };
	double jednodpole_d[] = { 4.5,5,0,2,-0.5,7,1.5,9,6 };
	n_d.SetMatrixFrom(jednodpole_d);
	Matrix<double> mmtn_d = mmt_d.Product(n_d);
	Matrix<int> r = mmtn_d.Parse<int>();
	Matrix<int> t{ 3,3 };
	int tpole[] = { 85,225,236,292,819,866,499,1413,1496 };
	t.SetMatrixFrom(tpole);
	Matrix<int> d{ 3,3 };
	d.SetMatrixFrom(tpole);
	std::cout << "r==t ? " << (r.IsIdentical(t) ? "true" : "false") << std::endl;
	std::cout << "is t==d? " << (t.IsIdentical(d) ? "true" : "false") << std::endl;
	return 0;
}