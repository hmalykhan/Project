#include<iostream>
using namespace std;
template<class T>
class heap
{
    T *cable;
    T* heap_arr;
    int size,current,dev;
    public:
    int get_dev()
    {
        return dev;
    }
    void set_dev(int dev)
    {
        this->dev=dev;
    }
    heap(int  size = 50)
    {
        cable=new T[size]();
        heap_arr=new T[size]();
        this->size=size;
        current=-1;
        dev=-1;
    }
    void set_cable(T* cable)
    {
        this->cable=cable;
    }
    T* get_cable()
    {
        return cable;
    }
    void set_current(int current)
    {
        this->current=current;
    }
    int get_total()
    {
        return current;
    }
    void swap(T &a, T &b)
    {
        T c=a;
        a=b;
        b=c;
    }
    int prior(string from)
    {
    int month=0,year=0,date=0,count=0;
        for(int a=0;from[a]!='-';a++)
        {
            if(from[a]>='0'&&from[a]<='9')
            {
                count++;
                if(count<=2)
                {
                    if(count==1)
                    {
                        date=date+((from[a]-48)*30);
                    }
                    else
                     date=date+(from[a]-48);
                }
                else if(count>=3&&count<=4)
                {
                     if(count==3)
                     {
                        month+=((from[a]-48)*30);
                     }
                else if(count==4)
                {
                    month=month+(from[a]-48);
                    date=date+(month*12);
                }
                }
                else if(count>=5&&count<=8)
                {
                if(count==8)
                {
                    year+=((from[a]-48)*30);
                    date=date+(year*year*year);
                }
                else 
                year+=(from[a]-48);
                }
            }
        }
        return date;
    }
    void insert(T data)
    {
        if(current<size)
        {
            cable[++current]=data;
            ++dev;
            int mover=current;
            while((current>0)&&(prior(cable[mover])<prior(cable[(mover-1)/2])))
            {
               swap(cable[mover],cable[(mover-1)/2]);
                mover=(mover-1)/2;
            }
        }
        else
        {
            cout<<"the size exceeds from the cable "<<endl;
        }
    }
    void after_insert(T data)
    {
        if(current<size)
        {
            cable[++dev]=data;
            ++current;
            int mover=dev;
            while((dev>0)&&(prior(cable[mover])>prior(cable[(mover-1)/2])))
            {
               swap(cable[mover],cable[(mover-1)/2]);
                mover=(mover-1)/2;
            }
        }
        else
        {
            cout<<"the size exceeds from the cable "<<endl;
        }
    }
    int left(int mover)
    {
        if(((mover*2)+1)<=current)
        return (mover*2)+1;
        return -1;
    }
     int right(int mover)
    {
        if((mover*2)+2<=current)
        return (mover*2)+2;
        return -1;
    }
    int max(int a,int b)
    {
        if(a!=-1 &&b !=-1)
        {
            if(prior(cable[a])>prior(cable[b]))
            return a;
            return b;
        }
        else if(a!=-1&&b==-1)
        {
            return a;
        }
        else
        {
            return -1;
        }
    }
     int min(int a,int b)
    {
        if(a!=-1 &&b !=-1)
        {
            if(prior(cable[a])<prior(cable[b]))
            return a;
            return b;
        }
        else if(a!=-1&&b==-1)
        {
            return a;
        }
        else
        {
            return -1;
        }
    }
    T remove()
    {
        if(cable==NULL)
        {
            cout<<endl<<" the cable is empty "<<endl;
            return NULL;
        }
        else
        {
            T dam=cable[0];
        cable[0]=cable[current--];
        int mover=0;
        while(mover<current && min(left(mover),right(mover))!=-1)
        {
            if(prior(cable[mover])>prior(cable[min(left(mover),right(mover))]))
            {
                // cout<<prior(cable[mover])<<" & "<<prior(cable[min(left(mover),right(mover))])<<" then ";
                swap(cable[mover],cable[min(left(mover),right(mover))]);
                // cout<< prior(cable[mover])<<" & "<<prior(cable[min(left(mover),right(mover))])<<endl;
                mover=max(left(mover),right(mover));
            }
            else
           {
             break;
           }
        }
        return dam;
        }
    }
     void erase()
    {
        if(cable==NULL)
        {
            cout<<endl<<" the cable is empty "<<endl;
            // return NULL;
        }
        else
        {
            // T dam=cable[0];
        cable[0]=cable[current--];
        dev--;
        int mover=0;
        while(mover<current && min(left(mover),right(mover))!=-1)
        {
            if(prior(cable[mover])>prior(cable[min(left(mover),right(mover))]))
            {
                // cout<< swap(cable[mover]<<" & "<<cable[min(left(mover),right(mover))])<<" then ";
                swap(cable[mover],cable[min(left(mover),right(mover))]);
                // mover=min(left(mover),right(mover));
            }
            else
           {
             break;
           }
        }
        // return dam;
        }
    }
    void traverse(int a=0)
    {
        if(a>dev)
            return;
        traverse(a*2+1);
        cout<<cable[a]<<endl;
        traverse(a*2+2);
    }
   string upcoming_event()
    {
        // cout<<prior(cable[0]);
        return cable[dev];
    }
    void remove_event()
    {
        // set_dev(get_dev()-1);
        // set_current(get_total()-1);
        --dev;
        // --current;
    }
    void heapsort()
    {
         for (int a=current;a>-1;a--)
        {
             cable[a]=remove();
        }
    }
    void traverse_heap()
    {
        // // string *heap= new string[current]{};
        // for (int a=current;a>=0;a--)
        // {
        //      heap_arr[a]=remove();
        //     //  cout<<cable[a]<<" ";
        // }
        for(int a=dev;a>=0;a--)
       {
            cout<<"                              "<<cable[a]<<","<<prior(cable[a])<<endl;
        }
    }
    void write_heap(ofstream& fout)
    {
        // string *heap= new string[current]{};
        // for (int a=current;a>=0;a--)
        // {
        //      heap_arr[a]=remove();
        // }
        for(int a=dev+1;a>=0;a--)
       {
                fout<<cable[a]<<",";

        }

    }
    void operator = (heap<T>& obj)
    {
        set_cable(obj.get_cable());
        set_current(obj.get_total());
        set_dev(obj.get_dev());
    }
};