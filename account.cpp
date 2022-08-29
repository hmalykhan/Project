#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Hashtable.cpp"
#include"heap.cpp"
#include"avl.cpp"
#include"list.cpp"
using namespace std;
// void add_friend()
// {bool token=false;
//     string arr="\0";
//             do
//             {
//                 cout<<"Enter the name of friend : ";
//                 getline(cin,arr);
//                 if(source.account_search(arr)==NULL)
//                 {
//                     cout<<"The "<<arr<<" has not found in system"<<endl;
//                     continue;
//                 }
//                 obj.events.insert(arr);
//             } while (source.account_search(arr)==NULL||arr!="0");
//             }
// template<class T>
class account
{
    string username,password,class_year,name;
    heap<string> events;
    avl<string> friends;
    list<string> timeline;
public:
    account()
    {
        username="\0";
        password="\0";
        class_year="\0";
        name="\0";
    }
    void set_username(ifstream& fin,string username)
    {
        this->username=username;
        //getline(fin,this->username,'\n');
    }
    void set_password(ifstream& fin)
    {
        getline(fin,password,'\n');
    }
    void set_name(ifstream& fin)
    {
        getline(fin,name,'\n');
    }
    void set_class_year(ifstream& fin)
    {
        getline(fin,class_year,'\n');
    }
    void set_events(ifstream& fin)
    {
        string data = "\0",arr ="\0";
         getline(fin,arr,'\n');
            int count=0,a=0;
            do{
                if(arr[a]!=','&&arr[a]!='\0')
                    {  
                        data=data+arr[a];
                    }
                else
                {
                    if(data!="\0")
                    events.insert(data);
                    // cout<<data<<"/";
                    data="\0";
                }   
                }while(arr[a++]!='\0');
                events.heapsort();
    }
    void set_friends(ifstream& fin)
    {
         string data = "\0",arr ="\0";
         getline(fin,arr,'\n');
            int count=0,a=0;
            do{
                if(arr[a]!=','&&arr[a]!='\0')
                    {  
                        data=data+arr[a];
                    }
                else
                {
                    if(data!="\0")
                    friends.set_root(friends.insert(friends.get_root(), data));
                    // cout<<data<<"/";
                    data="\0";
                }   
                }while(arr[a++]!='\0');
    }
    void set_timeline(ifstream& fin)
    {
         string data = "\0",arr ="\0";
         getline(fin,arr,'\n');
            int count=0,a=0;
            do{
                if(arr[a]!=','&&arr[a]!='\0')
                    {  
                        data=data+arr[a];
                    }
                else
                {
                    if(data!="\0")
                    timeline.insert(data);
                    // cout<<data<<"/";
                    data="\0";
                }   
                }while(arr[a++]!='\0');
    }
    void get_username(ofstream& fout)
    {
        fout<<username<<"\n";
    }
    void get_password(ofstream& fout)
    {
        fout<<password<<"\n";
    }
    void get_name(ofstream& fout)
    {
        fout<<name<<"\n";
    }
    void get_class_year(ofstream& fout)
    {
        fout<<class_year<<"\n";
    }
    void get_events(ofstream& fout)
    {
        events.write_heap(fout);
        fout<<"\n";
    }
    void get_friends(ofstream& fout)
    {
         friends.avl_write(fout,friends.get_root());
        fout<<"\n";
    }
    void get_timeline(ofstream& fout)
    {
         timeline.list_write(fout);
        fout<<"\n";
    }
    void operator = (account& obj)
    {
        username=obj.username;
        password=obj.password;
        name=obj.name;
        class_year=obj.class_year;
        events=obj.events;
        friends=obj.friends;
        timeline=obj.timeline;
    }
    void in_username(string username)
    {
        this->username=username;
    }
    void in_password(string password)
    {
        this->password=password;
    }
    void in_name(string name)
    {
        this->name=name;
    }
    void in_class_year(string class_year)
    {
        this->class_year=class_year;
    }
    void in_events(heap<string> events)
    {
        this->events=events;
    }
    string out_username()
    {
        return username;
    }
    string out_password()
    {
        return password;
    }
    string out_name()
    {
        return name;
    }
    string out_class_year()
    {
        return class_year;
    }
    heap<string>& out_events()
    {
        return events;
    }
    avl<string>& out_friends()
    {
        return friends;
    }
    list<string>& out_timeline()
    {
        return timeline;
    }
    void getting_data(ifstream& fin, string username)
    {
        set_username(fin,username);
        set_password(fin);
        set_name(fin);
        set_class_year(fin);
        set_events(fin);
        // events.heapsort();
        set_friends(fin);
        set_timeline(fin);
    }
    friend ofstream& operator<<(ofstream& fout,account& obj);
    friend ostream& operator<<(ostream& out,account& obj);
    // friend istream& operator>>(istream& in,account& obj);
};
ofstream& operator<<(ofstream& fout,account& obj)
{
    obj.get_username(fout);
    obj.get_password(fout);
    obj.get_name(fout);
    obj.get_class_year(fout);
    obj.get_events(fout);
    obj.get_friends(fout);
    obj.get_timeline(fout);
    return fout;
}
ostream& operator<<(ostream& out,account& obj)
{
    out<<obj.out_username()<<endl;
    out<<obj.out_password()<<endl;
    out<<obj.out_name()<<endl;
    out<<obj.out_class_year()<<endl;
    obj.out_events().traverse_heap();
    out<<endl;
    obj.out_friends().avl_traverse(obj.out_friends().get_root());
    out<<endl;
    obj.out_timeline().traverse();
    out<<endl;
    return out;
}
// istream& operator>>(istream& in,account& obj)
// {
//     string arr="\0";
//     cout<<"Enter the username : ";
//     getline(in,obj.username);
//     cout<<"Enter the password : ";
//     getline(in,obj.password);
//     do
//             {
//                 cout<<"Enter the name of friend : ";
//                 getline(cin,arr);
//                 if(source.account_search(arr)==NULL)
//                 {
//                     cout<<"The "<<arr<<" has not found in system"<<endl;
//                     continue;
//                 }
//                 obj.events.insert(arr);
//             } while (source.account_search(arr)==NULL||arr!="0");
//      do
//     {
//         cout<<"Enter the friend's email/To quit enter 0 : ";
//         getline(in,arr);
//         obj.events.insert(arr);
//     } while (arr!="0");
    
// }