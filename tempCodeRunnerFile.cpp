int main()
{
	avl<string> obj;
	obj.set_root(obj.insert(obj.get_root(), "12/04/2022-qawwalli day"));
	obj.set_root(obj.insert(obj.get_root(), "11/02/2023-murre trip"));
	obj.set_root(obj.insert(obj.get_root(), "01/07/2022-speech"));
	obj.set_root(obj.insert(obj.get_root(), "11/04/2022-urs"));
	obj.set_root(obj.insert(obj.get_root(), "11/04/2023-kwjQJ"));
	obj.set_root(obj.insert(obj.get_root(), "10/04/2022-Iehfiuwgfbkj"));
	obj.set_root(obj.insert(obj.get_root(), "02/07/2022-jdiWFHIUFA"));
	obj.set_root(obj.insert(obj.get_root(), "iyoqeof"));
	obj.traverse(obj.get_root());
	if(obj.remove("02/07/2022-jdiWFHIUFA"))
	{
		cout<<endl<<" deleted"<<endl;
	}
	else
	{
		cout<<" the data not found "<<endl;	
	}
	obj.traverse(obj.get_root());
	obj.search("10/04/2022-Iehfiuwgfbkj");
	return 0;
}