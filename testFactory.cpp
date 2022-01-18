#include <stack>

#include "Physics_World.h"
#include "GeoUtils.h"
#include "RunTimer.h"
#include "BinarySearchTree.h"



int main(int argc, char* argv[])
{
	//starting time do not edit code between solid comment lines
	//_________________________________________________________________________
	RunTimer timer(SECONDS);
	timer.start();
	//_________________________________________________________________________
	//add test code between starred areas
	//*************************************************************************
	/*MatrixXd A = MatrixXd::Random(6, 6);
	cout << "Here is a random 6x6 matrix, A:" << endl << A << endl << endl;

	EigenSolver<MatrixXd> es(A);
	cout << "The eigenvalues of A are:" << endl << es.eigenvalues() << endl;
	cout << "The matrix of eigenvectors, V, is:" << endl << es.eigenvectors() << endl << endl;

	complex<double> lambda = es.eigenvalues()[0];
	cout << "Consider the first eigenvalue, lambda = " << lambda << endl;
	VectorXcd v = es.eigenvectors().col(0);
	cout << "If v is the corresponding eigenvector, then lambda * v = " << endl << lambda * v << endl;
	cout << "... and A * v = " << endl << A.cast<complex<double> >() * v << endl << endl;

	MatrixXcd D = es.eigenvalues().asDiagonal();
	MatrixXcd V = es.eigenvectors();
	cout << "Finally, V * D * V^(-1) = " << endl << V * D * V.inverse() << endl;*/
	TriangleSolver test(5, 3, 4);
	test.displayTriangleData();

	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.display();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
