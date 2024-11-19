#include <iostream>
using namespace std;
class SparseMatrix;
class MatrixTerm{
	friend class SparseMatrix;
	private:
		int col;
		int row;
		int value;
};
class SparseMatrix{
	public:
		SparseMatrix::SparseMatrix(int therow=0,int thecol=0,int theterms=0){
			COL = thecol;
			ROW = therow;
			TERMS = theterms;
			smarray = new MatrixTerm[TERMS];
		}
		SparseMatrix Transpose();
		SparseMatrix FastTranspose();
	private:
		int COL;
		int ROW;
		int TERMS;
		MatrixTerm* smarray;
};
SparseMatrix SparseMatrix::Transpose(){
	SparseMatrix a(ROW,COL,TERMS);
	int currentA=0;
	if(TERMS>0){
		for(int i=0;i<COL;i++){
			for(int j=0;j<TERMS;j++){
				if(smarray[j].col==i){
					a.smarray[currentA].row = smarray[currentA].col;
					a.smarray[currentA].col = smarray[currentA].row;
					a.smarray[currentA].value = smarray[currentA].value;
					currentA++;
				}
			}
		}
	}
	return a;
}
SparseMatrix SparseMatrix::FastTranspose(){
	SparseMatrix a(COL,ROW,TERMS);
	if(TERMS>0){
		int* rowSize = new int[COL];
		int* rowStart = new int[COL];
		for(int i=0;i<TERMS;i++){
			rowSize[smarray[i].col]++;
		}
		for(int i=0;i<COL;i++){
			rowStart[i] = rowStart[i-1]+rowSize[i-1];
		}
		for(int i=0;i<TERMS;i++){
			int j = rowStart[smarray[i].col];
			a.smarray[j].row = smarray[i].col;
			a.smarray[j].col = smarray[i].row;
			a.smarray[j].value = smarray[i].value;
			rowStart[smarray[i].col]++;
		}
		delete[] rowSize;
		delete[] rowStart;
	}
	return a;
}








