/* An implementation of Stack data structure */

#include <iostream>
#include <new>
#include <string>
#include <sstream>
using namespace std;

#if !defined __STACK_H
#define __STACK_H

namespace stk{
	class Stack{
		private:
			int *p;
			int top,length;

			string str()const;
		public:
			Stack();
			Stack(const int);
			Stack(const Stack&);
			~Stack();

			void push(int);
			int pop();
			int get_length()const;
			bool is_empty()const;
			Stack operator=(const Stack&);
			friend ostream& operator<<(ostream&,Stack&);

			class StackException{
				private:
					string desc;
				public:
					StackException(string exp){ desc="Exception : "+exp; }
					string get_exp(){ return desc; }
			};
	};

	Stack::Stack(){
		top=-1;
		length=0;
		p=0;
	}

	Stack::Stack(const int size){
		top=-1;
		length=size;
		try{
			p=new int[length];
		}catch(bad_alloc ba){
			cout<<"Memory can not be alllocated
";
			return;
		}
	}

	Stack::Stack(const Stack &o){
		top=o.top;
		length=o.length;
		try{
			p=new int[length];
		}catch(bad_alloc ba){
			cout<<"Memory allocation failed
";
			return;
		}
		for(int i=0;i<length;i++)
			p[i]=o.p[i];
	}

	Stack::~Stack(){
		if(p!=0)
			delete [] p;
	}

	void Stack::push(int elem){
		if(p==0){
			try{
				p=new int[1];
			}catch(bad_alloc ba){
				throw StackException("Memory fault
");
			}
			length++;
			top++;
			p[top]=elem;
		}
		else if(top==(length-1)){
			int *q;
			try{
				q=new int[length+1];
			}catch(bad_alloc ba1){
				throw StackException("Memory fault
");
			}
			for(int i=0;i<length;i++)
				q[i]=p[i];
			length++;
			top++;
			q[top]=elem;
			delete [] p;
			p=q;
		}
		else{
			top++;
			p[top]=elem;
		}
	}

	int Stack::pop(){
		if(p==0 || top==-1){
			throw StackException("Stack empty!
");
		}
		int ret=p[top];
		top--;
		length--;

		if(top==-1){
			delete [] p;
			p=0;
		}
		else{
			int *q;
			try{
				q=new int[length];
			}catch(bad_alloc ba){
				throw StackException("Memory fault
");
			}
			for(int i=0;i<length;i++)
				q[i]=p[i];
			delete [] p;
			p=q;
		}

		return ret;
	}

	int Stack::get_length()const{
		return length;
	}

	bool Stack::is_empty()const{
		return ((p==0)? true : false);
	}

	string Stack::str()const{  // private member function
		stringstream ss;
		for(int i=0;i<length;i++){
			ss << p[i];
			if(i!=(length-1))
				ss << ", ";
		}
		//ss<<"
";
		return ss.str();
	}
	Stack Stack::operator=(const Stack &stk){
		length=stk.length;
		top=stk.top;
		if(p!=0)
			delete [] p;
		try{
			p=new int[length];
		}catch(bad_alloc ba){
			throw StackException("Memory fault in copying!
");
		}
		for(int i=0;i<length;i++)
			p[i]=stk.p[i];
		return *this;
	}
	ostream& operator<<(ostream &o,Stack &s){
		o<<s.str();
		return o;
	}
} // namespace stk;
#endif
