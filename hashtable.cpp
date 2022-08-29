#pragma
#include<iostream>
using namespace std;
template<class T>
class hash_node
{
	T data;
 hash_node<T>* nxt;
 hash_node<T>* pre;
public:
 hash_node<T>(T& data)
	{
		this->data = data;
		nxt = NULL;
		pre = NULL;
	}
	void set_data(T& data)
	{
		this->data = data;
	}
	void set_nxt (hash_node<T>* nxt)
	{
		this->nxt = nxt;
	}
	void set_pre (hash_node<T>* pre)
	{
		this->pre = pre;
	}
	T& get_data()
	{
		return data;
	}
 hash_node<T>* get_nxt()
	{
		return nxt;
	}
 hash_node<T>* get_pre()
	{
		return pre;
	}
};
template<class T>
class HashTable
{
 hash_node<T>** cable;
	int size;
public:
	HashTable(int size=50)
	{
		cable = new hash_node<T>*[size]();
		for (int a = 0; a < size; a++)
		{
			cable[a] = NULL;
		}
		this->size = size;
	}
	int num(T& data)
{
	int count = 0;
	for (int a = 0; data.out_username()[a]!='\0'; a++)
		{count += data.out_username()[a];
        //cout<<arr[a]<<" ";
        }
        //cout<<endl;
	return count;
}
	int generator(T data)
	{
		return num(data) % size;
	}
	void insert(T& material)
	{
	 hash_node<T>* neo = new hash_node<T>(material);
	 hash_node<T>* dam = cable[generator(material)];
	//  cout<<neo->get_data().out_username();
		if (dam == NULL)
		{
			cable[generator(material)] = neo;
		}
		else
		{
			while (dam->get_nxt() != NULL)
			{
				dam = dam->get_nxt();
			}
			dam->set_nxt(neo);
			neo->set_pre(dam);
		}
	}
 int search_num(string data)
 {
	int count=0;
	for(int a=0;data[a]!='\0';a++)
	{
		count+=data[a];
	}
	return count%size;
 }
 hash_node<T>* hash_search(T data)
	{
	 hash_node<T>* dam = cable[generator(data)];
		if (cable == NULL)
		{
			cout << "the cable is empty " << endl;
			return NULL;
		}
		else
		{
			if (dam == NULL)
			{
				cout << "the index is empty" << endl;
				return NULL;
			}
			else
			{
				while (dam != NULL)
				{
					if (data.out_username() == dam->get_data().out_username())
					{
						return dam;
					}
					dam = dam->get_nxt();
				}
				cout << "the data not found" << endl;
				return NULL;
			}
		}
	}
	hash_node<T>* account_search(string data)
	{
	 hash_node<T>* dam = cable[search_num(data)];
		if (cable == NULL)
		{
			// cout << "the cable is empty " << endl;
			return NULL;
		}
		else
		{
			if (dam == NULL)
			{
				// cout << "the data not found : " <<search_num(data)<< endl;
				return NULL;
			}
			else
			{
				while (dam != NULL)
				{
					if (data == dam->get_data().out_username())
					{
						return dam;
					}
					dam = dam->get_nxt();
				}
				// cout << "the data not found" << endl;
				return NULL;
			}
		}
	}
 hash_node<T>* last_node (hash_node<T>* hash_node)
	{
	 hash_node->get_pre()->set_nxt(NULL);
		return hash_node;
	}
 hash_node<T>* mid_node (hash_node<T>* hash_node)
	{
	 hash_node->get_pre()->set_nxt(hash_node->get_nxt());
	 hash_node->get_nxt()->set_pre(hash_node->get_pre());
		return hash_node;
	}
 hash_node<T>* first_node (hash_node<T>* hash_node)
	{
		return hash_node->get_nxt();
	}
	bool remove(T data)
	{
		if (cable == NULL)
		{
			cout << "the cable is empty" << endl;
			return false;
		}
		else
		{
		 hash_node<T>* dam = cable[generator(data)];
			if (dam == NULL)
			{
				cout << "the index is empty :" <<cable[6]<< endl;
				return false;
			}
			while (dam!= NULL)
			{
				if (data == dam->get_data())
				{
					
					if (dam->get_nxt() == NULL&&dam->get_pre()!=NULL)
					{
						delete dam;
						dam->get_pre()->set_nxt(NULL);
						return true;
					}
					else if (dam->get_pre() == NULL&&dam->get_nxt()!=NULL)
					{
						delete dam;
						//delete cable[generator(data)]; 
						cable[generator(data)]=dam->get_nxt();
						//delete first_node(dam);
						return true;
					}
					else if(dam->get_pre()==NULL&&dam->get_nxt()==NULL)
					{
						delete dam;
						//delete cable[generator(data)]; 
						cable[generator(data)]=NULL;
					//	cout << dam->get_data() << endl;

						return true;
					}
					else
					{
						dam->get_pre()->set_nxt(dam->get_nxt());
						dam->get_nxt()->set_pre(dam->get_pre());
						delete dam;
						return true;
					}
					return dam;
				}
				dam = dam->get_nxt();
			}
			cout << "the data not found " << endl;
			return false;
		}
	}
	void traverse()
	{
		if (cable == NULL)
		{
			cout << "empty cable " << endl;
		}
		else
		{
			for (int a = 0; a < size; a++)
			{
			 hash_node<T>* mover = cable[a];
				while (mover != NULL)
				{
					cout <<mover->get_data()<<"->"<<endl;
					mover = mover->get_nxt();
				}
			}
		}
		cout << endl;
	}
	void write_hash(ofstream& fout)
	{
		if (cable == NULL)
		{
			cout << "empty cable " << endl;
		}
		else
		{
			for (int a = 0; a < size; a++)
			{
			 hash_node<T>* mover = cable[a];
				while (mover != NULL)
				{
					fout << mover->get_data();
					mover = mover->get_nxt();
				}
			}
		}
		cout << endl;
	}
	
};
// int main()
// {
// 	HashTable<string> obj(7);
// 	obj.insert("12/04/2022-qawwalli day");
// 	obj.insert("11/02/2023-murre trip");
// 	obj.insert("01/07/2022-speech");
// 	obj.insert("11/04/2022-urs");
// 	obj.insert("11/04/2023-kwjQJ");
// 	obj.insert("10/04/2022-Iehfiuwgfbkj");
// 	obj.insert("02/07/2022-jdiWFHIUFA");
// 	obj.traverse();
// 	if (obj.remove("11/04/2022-urs"))
// 	{
// 		cout << "deleted " << endl;
// 	}
// 	obj.traverse();
// 	//cout<<obj.search("ali@gmail.com")->get_data()<<endl;
// 	return 0;
// }
