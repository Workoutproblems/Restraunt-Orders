class queue{
	public:
		bool isEmpty();
		
		void addQueue(node * a);
		void deleteQueue();
		int getTimeOrder();
		void decrement();
		int getNumCustomers();
		
		void print();
		
		queue(node * a, node * b, int c, int d, int e);
		
	private:
		node * front;
		node * back;		
		int numCustomers;
		int hamOff;
		int hotOff;
		int timeOrder;
};

bool queue::isEmpty(){
	if(front == NULL || back == NULL)
		return 1;	
		
	return 0;
}

void queue::addQueue(node * a){
	if(isEmpty()){
		front = a;
		back = a;
		numCustomers++;
	}
	
	else{
		node * temp = back;
		back = a;
		back->previous = temp;
		numCustomers++;
	}
	
	if(a->food[1] == 'o')
		a->time += hotOff;
	else
		a->time += hamOff;
}

void queue::deleteQueue(){
	if(!isEmpty()){
		node * temp = front;
		node * temp2 = back;
		
		if(temp == temp2){
			front = NULL;
			back = NULL;
			delete temp;
		}
		
		else{
		while(temp2->previous != front){
			temp2 = temp2->previous;	
		}
		
		front = temp2;
		front->previous = NULL;
		delete temp;
		}
		
		numCustomers--;
	}
}

int queue::getTimeOrder(){
	if(!isEmpty())
		return front->time;
}	

void queue::decrement(){
	if(!isEmpty())
		front->time--;	
}

int queue::getNumCustomers(){
	return numCustomers;	
}

void queue::print(){
	cout<<"printing"<<endl;
	if(!isEmpty()){
		node * temp = back;
		while(temp != NULL){
			temp->print();
			temp = temp->previous;
		}
	}
	cout<<"numCustomers:"<<numCustomers<<endl;
}

queue::queue(node * a = NULL, node * b = NULL, int c = 0, int d = 0, int e = 0){
	front = a;
	back = b;	
	numCustomers = c;
	timeOrder = 0;
	hamOff = d;
	hotOff = e;
	
}
