#include<iostream>
using namespace std;
template<class T>
class link_list_node
{
	T data;
	link_list_node* pre;
	link_list_node* nxt;
public:
	link_list_node(T data = 0, link_list_node* pre = NULL, link_list_node* nxt = NULL) :data(data), pre(pre), nxt(nxt) {};
	void set_data(T data)
	{
		this->data = data;
	}
	void set_pre(link_list_node* pre)
	{
		this->pre = pre;
	}
	void set_nxt(link_list_node* nxt)
	{
		this->nxt = nxt;
	}
	T get_data()
	{
		return data;
	}
	link_list_node* get_pre()
	{
		return pre;
	}
	link_list_node* get_nxt()
	{
		return nxt;
	}
};
template<class T>
class list
{
	link_list_node<T>* tail;
public:
	list()
	{
		tail = NULL;
	}
	link_list_node<T>* get_head()
	{
		return tail->get_nxt();
	}
    void set_tail(link_list_node<T>* tail)
    {
        this->tail=tail;
    }
    link_list_node<T>* get_tail()
    {
        return tail;
    }
	void insert(T data)
	{
		link_list_node<T>* neo = new link_list_node<T>(data);
		if (tail == NULL)
		{
			tail = neo;
			tail->set_nxt(tail);
			tail->set_pre(tail);
		}
		else
		{
			link_list_node<T>* mover = tail->get_nxt();
			tail->set_nxt(neo);
			neo->set_pre(tail);
			/*while (mover->get_pre() != tail)
			{
				cout << "mover" << mover->get_data();
				mover = mover->get_pre();
			}*/
			neo->set_nxt(mover);
			mover->set_pre(tail);
			tail = neo;
		}
	}
	void traverse()
	{
		link_list_node<T>* mover = tail->get_nxt();
		while (mover != tail)
		// for(int a=0;a<15;a++)
		{
			cout << mover->get_data() << "->";
			mover = mover->get_nxt();
		}
		cout << tail->get_data();
	}
	void reverse_traverse(link_list_node<T>* tail=NULL,int count=5)
	{
		// link_list_node<T>* mover = tail;
		// cout << mover->get_data() <<endl;
		// for(int a=0;a<5;a++)
		// {
		// 	mover = mover->get_pre();
		// 	cout <<"           "<<mover->get_data() <<endl;
		// }
		if(count<=0)
		return;
		reverse_traverse(tail->get_pre(),count-1);
		// if(count==1)
		// cout<<tail->get_data()<<endl;
		// else 
		cout<<"           "<<tail->get_data()<<endl;
	}
    void list_write(ofstream& fout)
	{
		link_list_node<T>* mover = tail->get_nxt();
		while (mover != tail)
		{
			fout << mover->get_data() <<",";
			mover = mover->get_nxt();
		}
		fout << tail->get_data()<<",";
	}
	int search(T data = 0, link_list_node<T>* mover = NULL, int num = 0)
	{
		if (mover != tail)
		{
			if (data != mover->get_data())
			{
				return search(data, mover->get_nxt(), ++num);

			}
			else
			{
				return num;
			}
		}
		else
		{
			if (data == mover->get_data())
			{
				return num;
			}
			else
			{
				return -1;
			}
		}
	}
	int max(link_list_node<T>* root=NULL, T data = 0)
	{
		if (root == tail)
		{
			if (data < tail->get_data())
				//cout << tail->get_data() << "->";
				return tail->get_data();
				//cout << data << "->";
			return data;
		}
		if (data < root->get_data())
			data = root->get_data();
			root = root->get_nxt();
		//cout << data << "->";
			return max(root, data);
			//return data;
			//cout << data << "->";

			
	}
	link_list_node<T>* address(link_list_node<T>* head, T data)
	{
		if (head == tail)
		{
			if (data == tail->get_data())return tail;
			return NULL;
		}
			else
			{
				if (data == head->get_data())return head;
				return address(head->get_nxt(), data);
			}
	}
	link_list_node<T>* trace(link_list_node<T>* head,int index)
	{
		if (index == 0)
			return head;
		else if (index < 0)
			return NULL;
		else
		{
			return trace(head->get_nxt(), index-1);
		}
	}
	int sum(T* array, int num, int index)
	{
		if (num==0)
		{
			return array[num];
		}
		else
		{
			cout <<array[index]<<" "<<array[--index] << ",";
			return array[num] + sum(array, num-1,index);
		}
	}
	int product(T* array, int index)
	{
		if (index == 0)
		{
			return array[index];
		}
		else
		{
			return array[index] * product(array, index-1);
		}
	}
    void operator=(list<T>& obj)
    {
        set_tail(obj.get_tail());
    }
};
// int main()
// {
// 	int* array = new int[5]{ 1,2,3,4,5 };
// 	list<int> obj;
// 	obj.insert(455);
// 	obj.insert(12);
// 	obj.insert(23);
// 	obj.insert(398);
// 	obj.insert(75);
// 	obj.insert(16);
// 	obj.insert(17);
// 	obj.insert(67);
// 	obj.traverse();
// 	cout <<endl;
// 	obj.sum(array, 4,4);
// 	/*if (obj.address(obj.get_head(), 7) != NULL)
// 	{
// 		cout <<"found" << (obj.address(obj.get_head(), 75))->get_data() << endl;
// 	}
// 	else
// 	{
// 		cout << "the data not found" << endl;
// 	}*/
// 	//obj.max(obj.get_head());
// 	/*cout << endl;
// 	if (obj.search(11, obj.get_head()) != -1)
// 	{
// 		cout << "found at : " << obj.search(11, (obj.get_head())) << endl;
// 	}
// 	else
// 	{
// 		cout << "not found" << endl;
// 	}*/
// }
