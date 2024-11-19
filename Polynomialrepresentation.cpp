#define MaxDegree 100
/*representation1
class Polynomial{
	private:
		int degree;
		float coef[MaxDegree+1];
};
representation2
class Polynomial{
	private:
		int degree;
		float* coef;
	public:
		Polynomial::Polynomial(int d){
			degree = d;
			coef = new float [degree+1];
		}
};*/
//representation3
class Polynomial;
class Term{
	friend class Polynomial;
	private:
		float coef;
		int exp;
};
class Polynomial{
	public:
		Polynomial::Polynomial(int theterms=0,int thecapacity=1){
			terms = theterms;
			capacity = thecapacity;
			Termarray = new Term[capacity];
		}
		Polynomial Add(const Polynomial& b);
		void NewTerm(const float& thecoef,const int& theexp);
	private:
		int terms;
		int capacity;
		Term* Termarray;
};
Polynomial Polynomial::Add(const Polynomial& b){
	Polynomial c;
	int posA=0,posB=0;
	while(posA<terms&&posB<b.terms){
		if(Termarray[posA].exp<b.Termarray[posB].exp){
			c.NewTerm(Termarray[posA].coef,Termarray[posA].exp);
			posA++;
		}
		else if(Termarray[posA].exp>b.Termarray[posB].exp){
			c.NewTerm(b.Termarray[posB].coef,b.Termarray[posB].exp);
			posB++;
		}
		else{
			float t = Termarray[posA].coef+b.Termarray[posB].coef;
			if(t)	c.NewTerm(Termarray[posA].coef+b.Termarray[posB].coef,Termarray[posA].exp);
			posA++;
			posB++;
		}
	}
	for(;posA<terms;posA++){
		c.NewTerm(Termarray[posA].coef,Termarray[posA].exp);
		posA++;
	}
	for(;posB<b.terms;posB++){
		c.NewTerm(b.Termarray[posB].coef,b.Termarray[posB].exp);
		posB++;
	}
	return c;
}
void Polynomial::NewTerm(const float& thecoef,const int& theexp){
	if(terms==capacity){
		capacity*=2;
		Term* temp = new Term[capacity];
		copy(Termarray,Termarray+terms,temp);
		delete[] Termarray;
		Termarray = temp;
	}
	Termarray[terms].coef = thecoef;
	Termarray[terms].exp = theexp;
	terms++;
}
	
