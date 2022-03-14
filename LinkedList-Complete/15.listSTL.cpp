#include<iostream>
#include<list>

using namespace std;

int main(){

	list<int> l; //declaring an empty list

	//declarr+initialise
	list<int> l1{1,2,3,10,8,5};

	//diff data types
	list<string> l2{"apple", "guava", "mango", "banana"};
	
	//iterating using iterators
	for(auto it = l2.begin(); it!=l2.end(); it++){
		cout<<(*it)<<"->";
	}
	cout<<endl;

	//adding to tail and head
	l2.push_back("pineapple");
	l2.push_front("kiwi");

	//iterate
	for(string s: l2){
		cout<<s<<"->";
	}
	cout<<endl;

	//sort
	l2.sort(); //lexicographical sorting

	//iterate
	for(string s: l2){
		cout<<s<<"->";
	}
	cout<<endl;

	//reverse
	l2.reverse();
	//iterate
	for(string s: l2){
		cout<<s<<"->";
	}
	cout<<endl;

	//fetching the first and last element
	cout<<l2.front()<<endl;
	cout<<l2.back()<<endl;

	//removing first element
	l2.pop_front();
	//removing last elem
	l2.pop_back();

	//iterate
	for(string s: l2){
		cout<<s<<"->";
	}
	cout<<endl;

	l2.push_back("guava");
	l2.push_back("orange");
	l2.push_back("water melon");

	for(string s:l2){
		cout<<s<<"->";
	}
	cout<<endl;

	//removing by value
	string f;
	cin>>f;
	l2.remove(f); //will remove all the occurances of sting f

	for(string s:l2){
		cout<<s<<"->";
	}
	cout<<endl;

	//erasing one or more element at a particular index
	
	//auto it = l2.begin()+3; //we cant add three.. because direct access is not allowed in list as underlying memory isn't linear
	//therefore we will have to do it++ the number of times 
	auto it = l2.begin();
	it++;
	it++;
	l2.erase(it); //will remove the  element at index 2

	for(string s:l2){
		cout<<s<<"->";
	}
	cout<<endl;

	//insert element after 2nd element
	it = l2.begin();
	it++;
	it++;
	l2.insert(it,"fruit juice");

	for(string s:l2){
		cout<<s<<"->";
	}
	cout<<endl;

	return 0;
}
