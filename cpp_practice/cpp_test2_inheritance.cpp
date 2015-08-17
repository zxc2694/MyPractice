#include<iostream>

using namespace std;

class SetInt {
	public:
		void setNum(int n){
			Num1 = n;
		}
		void setNum2(int m){
			Num2 = m;
		}
	protected:
		int Num1;
		int Num2;
};
class AddNum : public SetInt{
	public :
		int addNum(){
			return Num1+Num2;
		}
};

int main(void)
{
	AddNum t;
	t.setNum(10);
	t.setNum2(20);
	cout << t.addNum() << endl;
	return 0;
}
