#include<CNumberFactory.h>
/* class CNumberFactory
{
public:
	virtual void Add(int number) {};
	virtual void Sub(int number) {};
	virtual int GetValue() {return -1;};

	virtual void SetValue(int number) {};
	CNumberFactory *Create();
}; */
class CNumber :public CNumberFactory{
    private:
    int temp;
    public:
    void SetValue(int number){
        temp=number;
    }
    int GetValue(){
        int a=temp;
        return a;
    }
    void Add(int number){
        temp+=number;
    }
    void Sub(int number){
        temp-=number;
    }
};

CNumberFactory *CNumberFactory::Create()
{
    CNumberFactory *p= new CNumber();
	return p;
}
