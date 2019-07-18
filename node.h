#include <string>

using namespace std;

class node{
	
	friend class queue;
	
	public:
		node(int a, string d, node *b);
		void print() const;
		
		void setFoodAndTime();
		
		int getTime();
		string getFood();
		
		void setTime(int a);
		void setFood(string a);
		void setPrevious(node * a);
	private:
		int time;
		string food;
		node * previous;
};

void node::print() const{
	cout<<previous<<' '<<time<<' '<<food<<' '<<endl;
}

void node::setFoodAndTime(){
	int foodInt = rand() % 10 + 1;
	if(foodInt <= 6)
		food = "hamburger";
		
	else
		food = "hotdog";
		
	time = rand() % 5 + 1;
}

int node::getTime(){
	return time;	
}

string node::getFood(){
	return food;	
}

void node::setTime(int a){
	time = a;	
}

void node::setFood(string a){
	food = a;	
}

void node::setPrevious(node * a){
	previous = a;	
}

node::node(int a = 0, string d = " ", node * b = NULL){
	time = a;
	food = d;
	previous = b;
	
	setFoodAndTime();
}


