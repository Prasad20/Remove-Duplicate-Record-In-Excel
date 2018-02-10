#include<bits/stdc++.h>

using namespace std;

char c;

string d="";

string da="";

char g;

string fns="";

FILE *fp;

map<string,int> m;  
map<string,string> mb;  // birth
map<string,char> mg; // gender
map<string,string> mf; // fn

bool fncheck()
{	  
	map<string,string>::iterator it;
	
	it = mf.find(d);
	
	if(it!=mf.end() && it->second.compare(fns)==0)
	{
		return true;
	}
	else
	{
		return false;
	}		
}

bool gender()
{	  
	map<string,char>::iterator it;
	
	it = mg.find(d);
	
	if(it!=mg.end() && it->second==g)
	{
		return true;
	}
	else
	{
		return false;
	}		
}

bool date()
{	  
	map<string,string>::iterator it;
	
	it = mb.find(d);
	
	if(it!=mb.end() && it->second.compare(da)==0)
	{
		return true;
	}
	else
	{
		return false;
	}		
}

bool name()
{

	map<string,int>::iterator it;
	
	it = m.find(d);
	
	if(it!=m.end())
	{
		return true;
	}
	else
	{
		return false;
	}

}

int main()
{
	
    freopen("output.txt","w",stdout);

 	  int sflag = 0,nsame = 0;
      
      bool n,b,gen,f;
      
      int i=0,k=0;


   fp = fopen("in.txt","r");
   while(1)
    {
      c= fgetc(fp);
     
      if(k==0)
      {
      	if(c!='\n')
      	{
      	    cout<<c;
			continue;	
		}
		cout<<endl;
		k++;
		continue;
	  }
    
      if(c=='\n')
      {
      	if(nsame==1)
      	{
      		m.insert(make_pair(d,1));
      		mb.insert(make_pair(d,da));
      		mg.insert(make_pair(d,g));
      		mf.insert(make_pair(d,fns));
		}
		
			i=0;
			nsame=0;
			sflag=0;
			d.erase();
			da.erase();
			fns.erase();
	  }
      else if(c==',')
      {
      	if(nsame==0)
      	{
		   switch(i)
      		{
			    case 0 :    n = name();
							if(!n)
      						{
      			  				nsame=1;
				 			}
							break;
							
				case 1 : 	b = date();
							if(b)
				 			{
				 				nsame = 1;
							}
							break;
							
				case 2:     gen = gender();
							if(gen)
				 			{
				 				nsame = 1;
							}
							break;
							
				case 3:     f = fncheck();
							if(f)
				 			{
				 				nsame = 1;
							}
							break;	
			}
		}
      	i++;
	  }
	  else if(c==' ')
	  {
	  	sflag = 1;
	  }
	  else if(sflag==0 && i==0)
	 	 	{
	  			d+=c;
	  		}
	  else if(i==1)
	  		{
	  			da+=c;
	  		}
	  else if(i==2)
	  		{
	  			g=c;
	  		}		
	  else if(i==3)
	  		{
	  			fns+=c;
	  		}
      
      
      
      if( feof(fp) )
	  {
         break ;
      }
      
   }
   
   	map<string,int>::iterator it = m.begin();
   	map<string,string>::iterator it1 = mb.begin();
   	map<string,char>::iterator it2 = mg.begin();
   	map<string,string>::iterator it3 = mf.begin();
   	
      for(it;it!=m.end();it++,it1++,it2++,it3++)
      {
     	cout<<it->first<<","<<it1->second<<","<<it2->second<<","<<it3->second<<endl;
	  }
	 
   fclose(fp);
   return(0);
}
