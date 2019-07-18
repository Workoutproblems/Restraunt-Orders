#include <iostream>
#include <windows.h>
#include <time.h>
#include "node.h"
#include "queue.h"



using namespace std;

int main(int argc, char * argv[]){
	srand(time(NULL));
	
	int clock = 0;
	queue Alice(NULL, NULL, 0, 7, 0);
	queue Bob(NULL, NULL, 0, 5, 3);
	
	//Total number of hotdog orders
	double numHot = 0;
	//Total time spent cooking hotdogs
	double timeHot = 0;
	//Total number of hamburger orders
	double numHam = 0;
	//Total time spent cooking hamburgers
	double timeHam = 0;
	//Total number of customers
	double numCust = 0;
	//Total time of all the customers waiting in queue
	double timeCust = 0;
	
	while(clock <= 4320){
		
		if(clock % 5 == 0){
			int newCustomer = rand() % 10 + 1;
			if(newCustomer <= 7){
				//create new customer
				node * customer = new node();
				customer->setFoodAndTime();
				//choose queue, add to queue
				int queueChoice = rand() % 2;
				if(queueChoice == 1){
					Alice.addQueue(customer);
					
					//Customers are added to their respective queues
					//The time it takes for the nodes to complete is
					//determined inside the addQueue function.
					//	time = time + offest
					//I did it this way because the offsets were different
					//respectives to the queues.
					
					if(customer->getFood()[1] == 'o'){
						numHot++;
						timeHot += customer->getTime();
						numCust++;
					}
					else{
						numHam++;
						timeHam += customer->getTime();
						numCust++;
					}
				}
				else{
					Bob.addQueue(customer);
					
					if(customer->getFood()[1] == 'o'){
						numHot++;
						timeHot += customer->getTime();
						numCust++;
					}
					else{
						numHam++;
						timeHam += customer->getTime();
						numCust++;	
					}
				}
			}	
		
		}
		
		timeCust = timeCust + Alice.getNumCustomers() + Bob.getNumCustomers();
		
		//If the time left on the order is 0, delete it and decrement the new order
		//If time left on order isn't 0, decrement it
		
		if(Alice.getTimeOrder() != 0){
			Alice.decrement();	
		}
		
		if(!Alice.getTimeOrder() && Alice.getNumCustomers()){
			Alice.deleteQueue();
		}
		
		if(Bob.getTimeOrder() != 0){
			Bob.decrement();
		}
		if(!Bob.getTimeOrder() && Bob.getNumCustomers()){
			Bob.deleteQueue();
		}
		clock++;
	}
		
		cout<<endl<<"Alice: "<<endl;
		Alice.print();
		cout<<endl;
		cout<<"Bob:"<<endl;
		Bob.print();
		cout<<endl;
	
	//Avg Hot dog time = total hotdog time / number of hotdog orders
	double avgHot = timeHot / numHot;
	double avgHam = timeHam / numHam;
	//Average number of customers in the queue = total customer waiting time / total time
	double avgCust = timeCust / clock;
	//Average customer wait time = total customer wait time / number of customers
	double avgWait = timeCust / numCust;
	
	cout<<"total customers served: "<<numCust<<endl;
	
	cout<<"avgHot: "<<avgHot<<endl;
	cout<<"avgHam: "<<avgHam<<endl;
	cout<<"avgCust: "<<avgCust<<endl;
	cout<<"avgWait: "<<avgWait<<endl;
	
	return 0;	
}
