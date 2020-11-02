 /*
 * AlvarezA1.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Enrique Alvarez412-1
 */

#ifndef ALVAREZA4_H_
#define ALVAREZA4_H_
#include <string>
#include <iostream>
#include "Student.h"
using namespace std;




template <class T>
class LL
{
private:
	struct LLnode
	{
		struct LLnode * fwdPtr;
		T theData;
	};

	LLnode * header;

public:

LL()
{header = nullptr;}

void push_front(T);								//not required
void push_back(T); 								//this - done
void push_back_helper(LLnode *, LLnode *);			//helper
int list_length(); 								//this - done
int list_length_helper(LLnode*, int);				//helper
Student retrieve_front ();						//not required
Student retrieve_back(); 						//this - done
Student retrieve_back_helper(LLnode*, LLnode*); 	//helper
void display_list();							//this - done
void display_listHelper(LLnode *); 					//helper
void destroy_list(); 							//this - done
bool search_list(int); 							//this - done
bool search_list_helper(LLnode *, int); 			//helper
bool delete_node(int); 							//this - done
bool delete_node_helper(LLnode*, LLnode*, int); 	//helper


};


template <class T>
void LL<T>::push_front(T s){
		LLnode * temp;
			temp = header;

			LLnode * newFront;
			newFront = new LLnode;
			newFront -> theData = s;
			header = newFront;
			newFront -> fwdPtr = temp;
	}
template <class T>
void LL<T>::push_back(T s){
		LLnode * endNode;
		LLnode * nodeptr;

		endNode = new LLnode;
		endNode ->theData = s;
		endNode -> fwdPtr = nullptr;
			nodeptr = header;
			push_back_helper(nodeptr,endNode);
	}
template <class T>
void LL<T>::push_back_helper(LLnode * nodeptr,LLnode* endNode){
	if(nodeptr->fwdPtr !=nullptr){
		nodeptr = nodeptr -> fwdPtr;
		push_back_helper(nodeptr,endNode);
	}
	else{
		nodeptr -> fwdPtr = endNode;
	}
}
template <class T>
int LL<T>::list_length(){
		LLnode * temp;
			temp = header;
		int counter =0;
		counter =list_length_helper(temp,counter);
		return counter;
	}
template <class T>
int LL<T>::list_length_helper(LLnode * temp,int currCount){
	if(temp!= nullptr){
		temp = temp -> fwdPtr;
		currCount++;
		list_length_helper(temp, currCount);
	}
	if(temp==nullptr){
		return currCount;
	}
}

template <class T>
Student LL<T>::retrieve_front(){
		LLnode * frontPtr;
		frontPtr = header;
		return frontPtr->theData;
	}
template <class T>
Student LL<T>::retrieve_back(){
		LLnode * looper;
		LLnode * prev;
		looper = header;
		Student s = retrieve_back_helper(looper, prev);
		return s;
}
template <class T>
Student LL<T>::retrieve_back_helper(LLnode * looper,LLnode* prev){
	if(looper!=nullptr){
		prev = looper;
		looper = looper-> fwdPtr;
		retrieve_back_helper(looper, prev);
	}
	if(looper == nullptr){
		return prev->theData;
	}

}
template <class T>
void LL<T>::display_list(){
		cout << "nodes listed from 0 onwards" << endl;
				if(header == nullptr)
				{
					cout<< "the list contains no elements"<< endl;
				}
				else{
					display_listHelper(header);
				}
	}
template<class T>
void LL<T>::display_listHelper(LLnode * temp){

	if(temp!=nullptr){
	cout  << " " <<  temp->theData.studentID << "   " << temp ->theData.studentName << "  " << temp-> fwdPtr<< endl;
								display_listHelper(temp -> fwdPtr);
	}
}


template <class T>
void LL<T>::destroy_list(){
	LLnode * temp = header;
	if(temp != nullptr){
		temp = temp -> fwdPtr;
		delete header;
		header = temp;
		destroy_list();
	}
	else{
		delete header;
		delete temp;
		cout << "list is now empty after list destroy" << endl;
	}
}

template <class T>
bool LL<T>:: search_list(int sID){
	LLnode * temp = header;
	bool b;
	if(header == nullptr)
		cout << "empty list search???" << endl;
	b = search_list_helper(temp, sID);
	if(b){
		return true;
	}
	else{
		return false;
	}
}

template <class T>
bool LL<T>::search_list_helper(LLnode* temp, int sID){
	if(temp!= nullptr){
	if(temp -> theData.studentID == sID){
		return true;
	}
	else{
		search_list_helper(temp->fwdPtr, sID);
		}
	}
}

template <class T>
bool LL<T>:: delete_node(int sID){
	LLnode * temp = header;
	LLnode * tempTrail;
	if(header == nullptr)
		cout << "empty list???" << endl;
	bool foo;
	foo = delete_node_helper(temp, tempTrail, sID);
	return foo;
	return false;
}
template <class T>
bool LL<T>::delete_node_helper(LLnode* temp,LLnode * tempTrail,int sID){
	if(temp -> fwdPtr != nullptr){
		tempTrail = temp;
		temp = temp -> fwdPtr;
		if(temp ->theData.studentID == sID){
			tempTrail -> fwdPtr = temp ->fwdPtr;
			delete temp;
			return true;
		}
	}
	delete_node_helper(temp,tempTrail,sID);
}

#endif /* ALVAREZA2_H_ */
