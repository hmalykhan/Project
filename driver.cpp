#include"account.cpp"
void solver(account source,string day)
{
    ofstream fout("rough.txt",ios::out);
    if(fout.is_open())
    {
        source.out_events().write_heap(fout);
        fout<<day<<","<<'\n';
        fout.close();
    }
    else{
        cout<<"The reading file is not open"<<endl;
    }
    ifstream fin("rough.txt");
    account obj;
    source.in_events(obj.out_events());
    if(fin.is_open())
    {
        // obj.set_events(fin);
        string data = "\0",arr ="\0";
         getline(fin,arr,'\n');
        //  cout<<arr<<endl;
            int count=0,a=0;
            do{
                if(arr[a]!=','&&arr[a]!='\0')
                    {  
                        data=data+arr[a];
                    }
                else
                {
                    if(data!="\0")
                    {
                    // cout<<data<<"/";
                    source.out_events().insert(data);
                    }
                    data="\0";
                }   
                }while(arr[a++]!='\0');
                obj.out_events().heapsort();
        fin.close();
    }
    else{
        cout<<"The writing file is not open"<<endl;
    }
    source.out_events().traverse_heap();
    // ofstream fout("rough.txt",ios::out);
    fout.open("rough.txt",ios::app);
    if(fout.is_open())
    {
        source.out_events().write_heap(fout);
        fout<<day<<","<<'\n';
        fout.close();
    }
    else{
        cout<<"The reading file is not open"<<endl;
    }
}
bool event_formats(string arr)
{
    for(int a=0;a<11;a++)
    {
        if(a>=0&&a<=1)
        {
            if(arr[a]<'0'&&arr[a]>'9')
            {
                return false;
            }
        }
        else if(a==2)
        {
            if(arr[a]!='/')
            {
                return false;
            }
        }
         else if(a>=3&&a<=4)
        {
            if(arr[a]<'0'&&arr[a]>'9')
            {
                return false;
            }
        }
        else if(a==5)
        {
            if(arr[a]!='/')
            {
                return false;
            }
        }
        else if(a>=6&&a<=9)
        {
            if(arr[a]<'0'&&arr[a]>'9')
            {
                return false;
            }
        }
        else if(a==10)
        {
            if(arr[a]!='-')
            {
                return false;
            }
        }
    }
    return true;
}
void friends_with_timeline(HashTable<account>& source, avl_node<string>* root = NULL)
	{
		if (root == NULL)
		{
			return;
		}
		//cout <<"                   "<<root->get_data() <<endl;
        cout<<source.account_search(root->get_data())->get_data().out_name()<<"'s email address : "<<root->get_data()<<endl;
		cout<<"Timeline of "<<source.account_search(root->get_data())->get_data().out_name()<<" : "<<endl;
        source.account_search(root->get_data())->get_data().out_timeline().reverse_traverse(source.account_search(root->get_data())->get_data().out_timeline().get_tail());
        cout<<endl;
        // ->get_data().out_timeline().reverse_traverse();
		friends_with_timeline(source,root->get_left());
		//cout << root->get_data() << "->";
		friends_with_timeline(source,root->get_right());
		//cout << root->get_data() << "->";
	}
void mail(account& obj, string username)
{
    string mail="\0";
    cout<<"Write the message : ";
    getline(cin,mail);
    obj.out_timeline().insert(username+" :- "+mail);
    // obj.out_timeline().reverse_traverse(obj.out_timeline().get_tail());
}
void Import(HashTable<account>& obj)
{
    string username = "\0", file = "data.txt";
    ifstream fin(file);
    bool token=true;
    if(fin.is_open())
    {
           while(getline(fin,username))
            {
                // cout<<"1";
                account accounts;
                // account accounts2;
                accounts.getting_data(fin,username);
                // accounts2=accounts;
                // cout<<accounts2;
                obj.insert(accounts);
                // obj.traverse();
           }
        fin.close();
        cout<<"the data has been fetched successfully 'Alhamdulillah'"<<endl;
    }
    else
    {
        cout<<"the fetching file has not opened"<<endl;
    }
}
void Export(HashTable<account>& obj)
{
      ofstream fout("write.txt",ios::out);
    if(fout.is_open())
    {
        // cout<<obj.account_search("hmalykhan@gmail.com")->get_data()<<endl;
        obj.write_hash(fout);
        // obj.traverse();
        fout.close();
        cout<<"the data has been returned successfully 'Alhamdulillah'"<<endl;
    }
    else
    {
        cout<<"the writing file has not opened"<<endl;
    }
}
void login(HashTable<account>& source)
{
    bool token=false;
    int num=0;
    string username="\0",password="\0";
    do
    {
        cout<<"Enter your username/Enter 0 to go back : ";
        getline(cin,username);
        if(source.account_search(username)==NULL)
        {
            cout<<"The username : "<<username<<"has not found "<<endl;
        }
        if(username=="0")
        {
            token=true;
            break;
        }
    }while(source.account_search(username)==NULL);
    if(token)
    {
        token=false;
        return;
    }
    // account source.account_search(username)->get_data();=source.account_search(username)->get_data();
    do
    {
        cout<<"Enter your password/Enter 0 to go  back : ";
        getline(cin,password);
        if(source.account_search(username)->get_data().out_password()!=password)
        {
            cout<<"your passwprd does not match"<<endl;
        }
        if(password=="0")
        {
            token = true;
            break;
        }
    }while(source.account_search(username)->get_data().out_password()!=password);
    if(token)
    {
        token=false;
        return;
    }
    string up_coming_event=source.account_search(username)->get_data().out_events().upcoming_event();
    cout<<"Your name : "<<source.account_search(username)->get_data().out_name()<<endl;
    cout<<"Your Class year : "<<source.account_search(username)->get_data().out_class_year()<<endl;
    cout<<"Latest event to attend : "<<up_coming_event<<endl;
    cout<<"Timeline : "<<endl;
    source.account_search(username)->get_data().out_timeline().reverse_traverse(source.account_search(username)->get_data().out_timeline().get_tail());
    // source.account_search(username)->get_data();.out_timeline().traverse();
    cout<<endl;
    cout<<"List of events to be attend : "<<endl;
    source.account_search(username)->get_data().out_events().traverse_heap();
    while(true)
    {

    cout<<"Posting to your timeline : 1"<<endl;
    cout<<"Add/remove an event from your events list : 2"<<endl;
    cout<<"Friend list : 3"<<endl;
    cout<<"add/remove a friend : 4"<<endl;
    cout<<"Log out : 5"<<endl;
    cin>>num;
    cin.ignore();
    if(num==1)
    {
        string post="\0";
        cout<<"Enter the post : ";
        getline(cin,post);
        source.account_search(username)->get_data().out_timeline().insert("You :- "+ post);
        continue;
    }
    else if(num==2)
    {
        int num4=0;
        cout<<"To add an event : 1"<<endl;
        cout<<"To discard an expired event : 2"<<endl;
        cout<<"To display the list of events : 3"<<endl;
        cout<<"To go back : 4"<<endl;
        cin>>num4;
        cin.ignore();
        if(num4==1)
        {
        string event="\0";
        do
        {
            cout<<"Enter the event's name in the format of 'dd/mm/yyyy-Event Name' : ";
            getline(cin,event);
        } while (!event_formats(event));
        // source.account_search(username)->get_data().out_events().set_current(source.account_search(username)->get_data().out_events().get_dev());
        // source.account_search(username)->get_data().out_events().insert(event);
        solver(source.account_search(username)->get_data(),event);

        // source.account_search(username)->get_data().out_events().heapsort();
        continue;
        }
        else if(num4==2)
        {
            source.account_search(username)->get_data().out_events().remove_event();
            cout<<"Expired event has been discard"<<endl;
            continue;
        }
        else if(num4==3)
        {
            cout<<"List of events to be attend : "<<endl;
            source.account_search(username)->get_data().out_events().traverse_heap();
            continue;
        }
        else if(num4==4)
        {
            break;
        }
        else
        {
            cout<<"Enter the right option"<<endl;
            continue;
        }
    }
    else if(num==3)
    {
        int num3=0;
        cout<<"Your friends list :- "<<endl;
        friends_with_timeline(source,source.account_search(username)->get_data().out_friends().get_root());
        cout<<"To see a friend's profile : 1"<<endl;
        cout<<"To mail friend : 2"<<endl;
        cout<<"To go back : 3"<<endl;
        cin>>num3;
        cin.ignore();
        if(num3==1)
        {
            string address="\0";
            do
            {
                cout<<"Enter the email address of your friend/Enter 0 to go back : ";
                getline(cin,address);
                if(address=="0")
                {
                    token=true;
                    break;
                }
                else if(source.account_search(username)->get_data().out_friends().search(address)==NULL)
                {
                    cout<<address<<" is not in your friend list"<<endl;
                    continue;
                }
                else
                {
                    cout<<"The name of your freind : "<<source.account_search(username)->get_data().out_name()<<endl;
                    cout<<"The Class year of your frind : "<<source.account_search(username)->get_data().out_class_year()<<endl;
                    cout<<"The Events of your friend to attend : ";
                    source.account_search(username)->get_data().out_events().traverse_heap();
                    cout<<endl;
                    cout<<"The timeline of your friend : ";
                    source.account_search(username)->get_data().out_timeline().reverse_traverse();
                    cout<<endl;
                }
            } while (true);
            if(token)
                {
                    token=false;
                    cout<<"gotten out";
                    continue;
                } 
        }
        else if(num3==2)
        {
            bool token=false;
            string address="\0";
                do
                {
                    cout<<"Enter the email address of your friend/Enter 0 to go back : ";
                    getline(cin,address);
                    if(source.account_search(username)->get_data().out_friends().search(address)==NULL)
                    {
                        cout<<"The "<<address<<" is not in your friend list"<<endl;
                    }
                    if(address=="0")
                    {
                        token=true;
                        break;
                    }
                } while (source.account_search(username)->get_data().out_friends().search(address)==NULL);
                // source.account_search(address)==NULL
                if(token)
                {
                    token=false;
                    cout<<"gotten out";
                    continue;
                }
                 mail(source.account_search(address)->get_data(),username);
                 continue;
            }
        else if(num3==3)
        continue;
        else
        {
            cout<<"Enter the right option"<<endl;
            continue;
        }

    }
    else if(num==4)
    {
        int num2=0;
        cout<<"To add a friend : 1"<<endl;
        cout<<"To remove a friend : 2"<<endl;
        cout<<"to go back : 3"<<endl;
        cin>>num2;
        cin.ignore();
        if(num2==1)
        {
            bool token=false;
    string man="\0";
            do
            {
                cout<<"Enter the name of friend : ";
                getline(cin,man);
                if(man=="0")
                {
                    token=true;
                    break;
                }
                else if(source.account_search(man)==NULL)
                {
                    cout<<"The "<<man<<" has not found in system"<<endl;
                }
                else if(source.account_search(username)->get_data().out_friends().search(man)!=NULL)
                {
                    cout<<"The "<<man<<" is already in your friend list"<<endl;
                }
                else if(man==username)
                {
                    cout<<"Your username cannot be added in your friend list"<<endl;
                }
            } while (source.account_search(man)==NULL||source.account_search(username)->get_data().out_friends().search(man)!=NULL||man==username);
            if(token)
            {
                token = false;
                cout<<"gotten out"<<endl;
                continue;
            }
            source.account_search(username)->get_data().out_friends().insert(source.account_search(username)->get_data().out_friends().get_root(),man);
            cout<<"the freind has been added"<<endl;
            continue;
        }
        else if(num2==2)
        {bool token=false;
     string man="\0";
            do
            {
                cout<<"Enter the name of friend/Enter 0 to go back : ";
                getline(cin,man);
                if(man=="0")
                {
                    token=true;
                    break;
                }
            } while (source.account_search(username)->get_data().out_friends().search(man)==NULL);
            if(token)
            {
                token=false;
                cout<<"gotten out"<<endl;
                continue;
            }
            if(source.account_search(username)->get_data().out_friends().remove(man))
                cout<<"The "<<man<<" has been removed from freind list"<<endl;
                continue;
        }
        else if(num2==3)
        continue;
        else
        cout<<"Enter the right option"<<endl;
        continue;
    }
    else if(num==5)
    {
        break;
    }
    else
    {
        cout<<"Enter the right option"<<endl;
        continue;
    }
    }
}
void fun(account& obj,HashTable<account>& source)
{
    bool token=false;
     string man="\0";
            do
            {
                cout<<"Enter the name of friend/Enter 0 to go back : ";
                getline(cin,man);
                if(man=="0")
                {
                    token=true;
                    break;
                }
            } while (obj.out_friends().search(man)==NULL);
            if(token)
            {
                token=false;
                cout<<"gotten out"<<endl;
                // continue;
            }
            if(obj.out_friends().remove(man))
                cout<<"The "<<man<<" has been removed from freind list"<<endl;
            // else
                // cout<<"The "<<man<<" has not found in your freind list"<<endl;
}
void create_account(HashTable<account>& source)
{
    account obj;
    string arr="\0",username="\0";
    cout<<"Enter your username : ";
    getline(cin,username);
    obj.in_username(username);
    cout<<"Enter your password : ";
    getline(cin,arr);
    obj.in_password(arr);
    cout<<"Enter your complete name : ";
    getline(cin,arr);
    obj.in_name(arr);
    cout<<"Enter your class year : ";
    getline(cin,arr);
    obj.in_class_year(arr);
     do
    {
        cout<<"Enter the event's name in the format of 'dd/mm/yyyy-Event Name'/To quit enter 0 : ";
        getline(cin,arr);
        if(arr=="0")
            break;
        else if(!event_formats(arr))
            {
                cout<<"Enter the right format --> ";
                continue;
            }
        else
            obj.out_events().insert(arr);
    } while (arr!="0");
    obj.out_events().heapsort();
    do
            {
                cout<<"Enter the name of friend//To quit enter 0 : ";
                getline(cin,arr);
                if(arr=="0")
                break;
                else if(arr==username)
                {
                    cout<<"The username can not be added in frind list"<<endl;
                    continue;
                }
                else if(source.account_search(arr)==NULL)
                {
                    cout<<"The "<<arr<<" has not found in system"<<endl;
                    continue;
                }
                else
                obj.out_friends().set_root(obj.out_friends().insert(obj.out_friends().get_root(),arr));
                // if(source.account_search(arr)==NULL && arr!="0" && arr!=username)
                // {
                //     cout<<"The "<<arr<<" has not found in system"<<endl;
                //     continue;
                // }
                // else if(arr==username)
                // {
                //     cout<<"The username can not be added in frind list"<<endl;
                //     continue;
                // }
                // else if(arr=="0")
                // {
                //     break;
                // }
                // else if(arr!="0" && arr!=username)
                // obj.out_friends().insert(obj.out_friends().get_root(),arr);
            } while (source.account_search(arr)==NULL||arr!="0"||arr==username);
     do
    {
        cout<<"Enter the posts in your timeline/To quit enter 0 : ";
        getline(cin,arr);
        if(arr=="0")
        break;
        else
        obj.out_timeline().insert("you :- "+arr);
    } while (true);
    source.insert(obj);
    cout<<"The data has been transferred"<<endl;
}
int main()
{
    HashTable<account> obj;
    Import(obj); 
    // // fun(obj.account_search("aneeq@gmail.com")->get_data(),obj);
    // // obj.account_search("aneeq@gmail.com")->get_data().out_friends().friends_with_timeline(obj,obj.account_search("aneeq@gmail.com")->get_data().out_friends().get_root());
    // login(obj);
    int gear=0;
    while(true)
    {
        cout<<"Login : 1"<<endl;
        cout<<"Create an account : 2"<<endl;
        cout<<"Exit : 3"<<endl;
        cin>>gear;
        cin.ignore();
        if(gear==1)
        {
            login(obj);
            continue;
        }
        else if(gear==2)
        {
            create_account(obj);
            continue;
        }
        else if(gear==3)
        {
            break;
        }
        else
        cout<<"Enter the right option"<<endl;
        continue;
    }
    Export(obj);
    return 0;
}
