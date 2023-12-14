#include "Matrix.h"
#include "bits/stdc++.h"
using namespace std;

int main(int argc, char *argv[]) {
	double pi = M_PI;

	vector <vector<double>> dVec_A;
    dVec_A.push_back({2,-2});
    dVec_A.push_back({3,-5});
	Matrix A(dVec_A);
	cout << "A =" << endl;
	A.printMatrix();

	vector <vector<double>> dVec_B;
    dVec_B.push_back({-2,0});
    dVec_B.push_back({4,2});
	Matrix B(dVec_B);
	cout << "B =" << endl;
	B.printMatrix();

	vector <vector<double>> dVec_C;
    dVec_C.push_back({-1,2,0});
    dVec_C.push_back({2,0,3});
	Matrix C(dVec_C);
	cout << "C =" << endl;
	C.printMatrix();

	vector <vector<double>> dVec_E;
    dVec_E.push_back({2,-1});
    dVec_E.push_back({pi,log10(2)});
	dVec_E.push_back({-2,3});
	Matrix E(dVec_E);
	cout << "E =" << endl;
	E.printMatrix();

	vector <vector<double>> dVec_F;
    dVec_F.push_back({1,2,3});
    dVec_F.push_back({2,3,4});
	dVec_F.push_back({3,5,7});
	Matrix F(dVec_F);
	cout << "F =" << endl;
	F.printMatrix();

	vector <vector<double>> dVec_I;
    dVec_I.push_back({1,0,0});
    dVec_I.push_back({0,1,0});
	dVec_I.push_back({0,0,1});
	Matrix I(dVec_I);
	cout << "I =" << endl;
	I.printMatrix();

	// can use function or operator overloading
	Matrix A_2B;
	// A_2B = A + B.multiplyConstant(2);
	// cout << "A + 2B =" << endl;
	// A_2B.printMatrix();
	A_2B = A + (B*2);
	cout << "A + 2B =" << endl;
	A_2B.printMatrix();

	Matrix C_BEt;
	C_BEt = C - (B * E.transpose());
	cout << "C - B * transpose(E) =" << endl;
	C_BEt.printMatrix();

	Matrix At;
	At = A.transpose();
	cout << "transpose(A) =" << endl;
	At.printMatrix();

	Matrix M;
	M = A * B;
	cout << "M =" << endl;
	M.printMatrix();
	Matrix N;
	N = B * A;
	cout << "N =" << endl;
	N.printMatrix();

	// can use function or operator overloading
	// if (M.equal_TorF(N)) cout << "M is equal to N" << endl;
	// else cout << "M is not equal to N" << endl;
	if (M == N) cout << "M is equal to N" << endl;
	else cout << "M is not equal to N" << endl;

	Matrix P;
	P = C.transpose() * B.transpose();
	cout << "P =" << endl;
	P.printMatrix();
	Matrix Q;
	Q = (B * C).transpose();
	cout << "Q =" << endl;
	Q.printMatrix();

	// can use function or operator overloading
	// if (P.equal_TorF(Q)) cout << "P is equal to Q" << endl;
	// else cout << "P is not equal to Q" << endl;
	if (P == Q) cout << "P is equal to Q" << endl;
	else cout << "P is not equal to Q" << endl;

	Matrix A_inverse;
	cout << "A ";
	A_inverse = A.inverse();
	cout << "inverse(A) =" << endl;
	A_inverse.printMatrix();


	vector <vector<double>> dVec_T;
    dVec_T.push_back({(double)1/6,(double)1/2,(double)1/3});
    dVec_T.push_back({(double)1/2,(double)1/4,(double)1/4});
	dVec_T.push_back({(double)1/3,(double)1/4,(double)5/12});
	Matrix T(dVec_T);
	cout << "T =" << endl;
	T.printMatrix();

	Matrix T_5;
	T_5 = T.power(5);
	cout << "T^5 =" << endl;
	T_5.printMatrix();

	Matrix T_10;
	T_10 = T.power(10);
	cout << "T^10 =" << endl;
	T_10.printMatrix();

	Matrix T_20;
	T_20 = T.power(20);
	cout << "T^20 =" << endl;
	T_20.printMatrix();
	
	Matrix T_30;
	T_30 = T.power(30);
	cout << "T^30 =" << endl;
	T_30.printMatrix();
}
