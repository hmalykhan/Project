#pragma
#include<iostream>
// #include"driver.cpp"
// #include"account.cpp"
// #include"Hashtable.cpp"
using namespace std;
template<class T>
class avl_node
{
	T data;
	avl_node<T>* left;
	avl_node<T>* right;
	int height;
public:
	avl_node<T>(T data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
		height = 1;
	}
	void set_data(T data)
	{
		this->data = data;
	}
	void set_left(avl_node<T>* left)
	{
		this->left = left;
	}
	void set_right(avl_node<T>* right)
	{
		this->right = right;
	}
	void set_height(int height)
	{
		this->height = height;
	}
	T get_data()
	{
		return data;
	}
	avl_node<T>* get_left()
	{
		return left;
	}
	avl_node<T>* get_right()
	{
		return right;
	}
	int get_height()
	{
		return height;
	}
};
template<class T>
class avl
{
	avl_node<T>* root;
public:
	avl()
	{
		root = NULL;
	}
	void set_root(avl_node<T>* root)
	{
		this->root = root;
	}
	avl_node<T>* get_root()
	{
		return root;
	}
	int height(avl_node<T>* avl_node)
	{
		if (avl_node == NULL)
		{
			return 0;
		}
		return avl_node->get_height();
	}
	int balance_factor(avl_node<T>* avl_node)
	{
		if (avl_node == NULL)
			return 0;
		return height(avl_node->get_left()) - height(avl_node->get_right());
	}
	int max(int a, int b)
	{
		if (a > b)
		return a;
		return b;
	}
	avl_node<T>* right(avl_node<T>* x)
	{
		avl_node<T>* y = x->get_left();
		avl_node<T>* t2 = y->get_right();
		y->set_right(x);
		x->set_left(t2);
		x->set_height(max(height(x->get_left()), height(x->get_right())) + 1);
		y->set_height(max(height(y->get_left()), height(y->get_right())) + 1);
		return y;
	}
	avl_node<T>* left(avl_node<T>* x)
	{
		avl_node<T>* y = x->get_right();
		avl_node<T>* t2 = y->get_left();
		y->set_left(x);
		x->set_right(t2);
		x->set_height(max(height(x->get_left()), height(x->get_right())) + 1);
		y->set_height(max(height(y->get_left()), height(y->get_right())) + 1);
		return y;
	}
	avl_node<T>* insert(avl_node<T>* root = NULL, T data = 0)
	{
		if (root == NULL)
		{
			return new avl_node<T> (data);

		}
		else if(data > root->get_data())
		{
			root->set_right(insert(root->get_right(), data));
		}
		else if (data < root->get_data())
		{
			root->set_left(insert(root->get_left(), data));
		}
		else
		{
			return root;
		}
		root->set_height(max(height(root->get_left()), height(root->get_right()))+1);
		int bf = balance_factor(root);
		//the next line will crash the code as root->get_right() is null having no data by extracting its data the program will crash.
		//cout << endl << bf << "  " << data << "  " << root->get_data() << "   " << endl;//root->get_right()->get_data() << endl;
		if (bf == -2)
		{
			if (data > root->get_right()->get_data())
			{
				return left(root);
			}
			else
			{
				root->set_right(right(root->get_right()));
				return left(root);
			}
		}
		else if (bf == 2)
		{
			if (data < root->get_left()->get_data())
			{
				return right(root);
			}
			else
			{
				root->set_left(left(root->get_left()));
				return right(root);
			}
		}
		return root;
	}
	avl_node<T>* max(avl_node<T>* root)
	{
		avl_node<T>* mover=root;
		while(mover->get_right()!=NULL)
		{
			mover=mover->get_right();
		}
		return mover;
	}
	avl_node<T>* min(avl_node<T>* root)
	{
		avl_node<T>* mover=root;
		while(mover->get_left()!=NULL)
		{
			mover=mover->get_left();
		}
		return mover;
	}
	bool remove(T data)
	{
		avl_node<T>* mover=root;
		avl_node<T>* follow=mover;
		bool token=true;
		while(mover!=NULL)
		{
			if(data==mover->get_data())
			{
				if(mover->get_left()==NULL&&mover->get_right()==NULL)
				{
					if(token)
					{
						delete mover;
						follow->set_right(NULL);
						return true;
					}
					else
					{
						delete mover;
						follow->set_left(NULL);
						return true;
					}

				}
				else if(mover->get_left()!=NULL&&mover->get_right()!=NULL)
				{
					mover->set_data(max(mover->get_left())->get_data());
					if(mover->get_left()->get_right()==NULL)
					{
						delete max(mover->get_left());
						mover->set_left(NULL);
					}
					return true;
				}
				else
				{
					if(mover->get_left()!=NULL)
					{
						if(token)
						{
							follow->set_right(mover->get_left());
							delete mover;
							mover=NULL;
							// follow->get_right()=NULL;
							return true;
						}
						follow->set_left(mover->get_left());
							delete mover;
							mover=NULL;
							// follow->get_left()=NULL;
							return true;
					}
					else if(mover->get_right()!=NULL)
					{
						if(token)
						{
							follow->set_right(mover->get_right());
							delete mover;
							mover=NULL;
							// follow->get_right()=NULL;
							return true;
						}
						follow->set_left(mover->get_right());
							delete mover;
							mover=NULL;
							// follow->get_left()=NULL;
							return true;
					}
				}
			}
			else if(data>mover->get_data())
			{
				follow=mover;
				mover=mover->get_right();
				token=true;
			}
			else
			{
				follow=mover;
				mover=mover->get_left();
				token=false;
			}
		}
		return false;
	}
	avl_node<T>* search(T data)
	{
		avl_node<T>* mover=root;
		{
			while(mover!=NULL)
			{
				if(data==mover->get_data())
				{
					// cout<<endl<<" found : "<<mover->get_data()<<endl;
					return mover;
				}
				else if(data>mover->get_data())
				{
					mover=mover->get_right();
				}
				else if(data<mover->get_data())
				{
					mover=mover->get_left();
				}
			}
			// cout<<"Friend not found "<<endl;
			return NULL;

		}
	}
	void avl_traverse(avl_node<T>* root=NULL)
	{
		if (root == NULL)
		{
			return;
		}
		cout <<"                   "<<root->get_data() <<endl;
		// cout<<"Timeline of "<<root->get_data()<<" : ";
		// obj.account_search(root->get_data())->get_data().out_friends().reverse_traverse();
		avl_traverse(root->get_left());
		//cout << root->get_data() << "->";
		avl_traverse(root->get_right());
		//cout << root->get_data() << "->";

	}
	// void friends_with_timeline(HashTable<account>& source, avl_node<T>* root = NULL)
	// {
	// 	if (root == NULL)
	// 	{
	// 		return;
	// 	}
	// 	cout <<"                   "<<root->get_data() <<endl;
	// 	cout<<"Timeline of "<<root->get_data()<<" : ";
	// 	friends_with_timeline(source,root->get_left());
	// 	//cout << root->get_data() << "->";
	// 	friends_with_timeline(source,root->get_right());
	// 	//cout << root->get_data() << "->";
	// }
	void avl_write(ofstream& fout,avl_node<T>* root = NULL)
	{
		if (root == NULL)
		{
			return;
		}
		fout << root->get_data() << ",";
		avl_write(fout,root->get_left());
		//cout << root->get_data() << "->";
		avl_write(fout,root->get_right());
		//cout << root->get_data() << "->";

	}
	void operator = (avl<T>& obj)
	{
		set_root(obj.get_root());
	}
};
// int main()
// {
// 	avl<string> obj;
// 	obj.set_root(obj.insert(obj.get_root(), "12/04/2022-qawwalli day"));
// 	obj.set_root(obj.insert(obj.get_root(), "11/02/2023-murre trip"));
// 	obj.set_root(obj.insert(obj.get_root(), "01/07/2022-speech"));
// 	obj.set_root(obj.insert(obj.get_root(), "11/04/2022-urs"));
// 	obj.set_root(obj.insert(obj.get_root(), "11/04/2023-kwjQJ"));
// 	obj.set_root(obj.insert(obj.get_root(), "10/04/2022-Iehfiuwgfbkj"));
// 	obj.set_root(obj.insert(obj.get_root(), "02/07/2022-jdiWFHIUFA"));
// 	obj.set_root(obj.insert(obj.get_root(), "iyoqeof"));
// 	obj.traverse(obj.get_root());
// 	if(obj.remove("02/07/2022-jdiWFHIUFA"))
// 	{
// 		cout<<endl<<" deleted"<<endl;
// 	}
// 	else
// 	{
// 		cout<<" the data not found "<<endl;	
// 	}
// 	obj.traverse(obj.get_root());
// 	obj.search("10/04/2022-Iehfiuwgfbkj");
// 	return 0;
// }