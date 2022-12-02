#include <iostream>
using namespace std;
class Building{
public:
    Building(){}
	Building(char *name,int floor,int room,int area){
		strcpy(this->name,name);
		this->floor = floor;
		this->room = room;
		this->area = area;
	}
	virtual void display(){
		cout<<"Name:"<<name<<endl;
		cout<<"Floor:"<<floor<<endl;
		cout<<"Room:"<<room<<endl;
		cout<<"Area:"<<area<<endl;
	}
	Building * createTeachBuilding(char *name,int floor,int room,int area,char *function);
	Building * creatDormBuilding(char *name,int floor,int room,int area,int peoples);
protected:
	char name[20];
	int floor;
	int room;
	int area;

}; 
class TeachBuilding :public Building{
    private:
    char function[20];
    public:
    TeachBuilding(char *name,int floor,int room,int area,char *function){
        strcpy(this->name,name);
        this->floor = floor;
		this->room = room;
		this->area = area;
        strcpy(this->function,function);
    }
    void display(){
        cout<<"Name:"<<name<<endl;
		cout<<"Floor:"<<floor<<endl;
		cout<<"Room:"<<room<<endl;
		cout<<"Area:"<<area<<endl;
        cout<<"Function:"<<function<<endl;
    }
};
class DormBuilding :public Building{
    private:
    int peoples;
    public:
    DormBuilding(char *name,int floor,int room,int area,int peoples){
        strcpy(this->name,name);
        this->floor = floor;
		this->room = room;
		this->area = area;
        this->peoples=peoples;
    }
    void display(){
        cout<<"Name:"<<name<<endl;
		cout<<"Floor:"<<floor<<endl;
		cout<<"Room:"<<room<<endl;
		cout<<"Area:"<<area<<endl;
        cout<<"Peoples:"<<peoples<<endl;
    }
};
Building* Building::createTeachBuilding(char *name,int floor,int room,int area,char *function){
	Building *p=new TeachBuilding(name,floor,room,area,function);
    return p;
}

Building * Building::creatDormBuilding(char *name,int floor,int room,int area,int peoples){
	Building *p=new DormBuilding(name,floor,room,area,peoples);
    return p;
}