#include<bits/stdc++.h>

using namespace std;

char c;									// read input from input file;

string d="";							// stores name from inout file
 
string da="";							// stores birthday from inout file

string g="";							// stores gender from inout file

string fns="";							// stores family name from inout file

FILE *fp;

map<string,int> m;      				//name database
map<string,string> mb;				   // birthday database
map<string,string> mg; 				   // gender database
map<string,string> mf; 				  // family database 

bool fncheck()							// fncheck() --> checks whether for a name family name is same or not in database 
{	  
	map<string,string>::iterator it;
	map<string,int>::iterator it1 = m.find(d);
	
	it = mf.find(d);
	
	if(it!=mf.end() && it->second.compare(fns)==0)
	{
		return true;										// database exists
	}
	
	string tp = d;
	
	int temp = it1->second;
	
	for(int i=1;i<=temp;i++)
	{
		tp+=i+'0';
		it = mf.find(tp);
		if(it!=mf.end() && it->second.compare(fns)==0)
		{
			return true;									// database exists
		}
		tp = d;
	}
		
	return false;											// database doesn't exists
		
}

bool gender()												//checks whether for a name gender is same or not in database
{	  
	map<string,string>::iterator it;
	map<string,int>::iterator it1 = m.find(d);
	
	it = mg.find(d);
	
	if(it!=mg.end() && it->second.compare(g)==0)
	{	
		return true;										// database exists
	}
	
	string tp = d;
	
	int temp = it1->second;
	
	for(int i=1;i<=temp;i++)
	{
		tp+=i+'0';
		it = mg.find(tp);
		if(it!=mg.end() && it->second.compare(g)==0)
		{
			return true;									// database exists
		}
		
		tp = d;
	}
				
		return false;										// database doesn't exists
}

bool date()													//date() --> checks whether for a name birth of day is same or not in database
{	  
	map<string,string>::iterator it;
	map<string,int>::iterator it1 = m.find(d);
	
	it = mb.find(d);
	
	if(it!=mb.end() && it->second.compare(da)==0)
	{
		return true;
	}
	
	string tp = d;
	
	int temp = it1->second;
	
	for(int i=1;i<=temp;i++)
	{
		tp+=i+'0';
		it = mb.find(tp);
		if(it!=mb.end() && it->second.compare(da)==0)
		{
			return true;									// database exists
		}
		tp = d;
	}
		
	return false;											// database doesn't exists
		
}

bool name()													//name() --> checks whether a name is present in database or not
{

	map<string,int>::iterator it;
	
	it = m.find(d);
	
	if(it==m.end())
	{
		return true;										// database exists
	}
	else
	{
		return false;										// database doesn't exists
	}

}

int main()
{
	
   
 	  int sflag = 0,nsame = 0;
      
      bool n,b,gen,f;
      
      int i=0,k=0;
	
map<string,int>::iterator it = m.begin();
   
   freopen("output.csv","w",stdout);				// output file name 

   fp = fopen("in.csv","r");						// input file name
   
   while(1)											// Run loop untill input file reaches to eof.		
    {
      c= fgetc(fp);									//read from input file
     
      if(k==0)										// To add 1st line as it is as in csv 1st line defines the column names
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
          
      if(c==',' || c=='\n')						
      {
      	if(nsame==0)								//nsame == 0 -->current data exists in database 
      	{											//nsame == 1 -->current data doesn't exists in database
		   switch(i)
      		{
			    case 0 :    n = name();				//  name()  -->  checks whether name already exists or not in database
							if(n)
      						{
      			  				nsame=1;			// nsame(not same) --> if name doesn't exists then no need to check for other functions like gender, fn, Birth of day 
				 			}
							break;
							
				case 1 : 	b = date();            //   date() --> checks whether for a name birth of day is same or not in database
							if(!b)
				 			{
				 				nsame = 1;			// nsame(not same) -->if different birthday are different for same name then other functions beneath are not called 
							}
							break;
							
				case 2:     gen = gender();   		//  gender()--> checks whether for a name gender is same or not in database
							if(!gen)
				 			{
				 				nsame = 1;			//nsame(not same) -->if different gender are different for same name then other functions beneath are not called 
							}
							break;
							
				case 3:     f = fncheck();			// fncheck() --> checks whether for a name family name is same or not in database 
							if(!f)
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
	  else if(sflag==0 && i==0)						// add name to string d;
	 	 	{
	  			d+=c;
	  		}
	  else if(i==1)									// add date of birth to string da;
	  		{			
	  			da+=c;
	  		}
	  else if(i==2)									// add gender to string g;
	  		{
	  			g+=c;
	  		}		
	  else if(i==3)									// add family name to string fns;
	  		{
	  			fns+=c;
	  		}
	  		
	  		
	  if(c=='\n')									// checks whether data exists in database and if not present then add it to database else ignore and set all values to initial values
      {
      	if(nsame==1)
      	{
      		if(n)
      			m.insert(make_pair(d,1));
      		else
      		{
			 	it = m.find(d);
				m[d] = it->second+1; 
			 	int temp1 = it->second;
			 	d+= temp1+'0';
      			m.insert(make_pair(d,it->second+1));
			}
      		mb.insert(make_pair(d,da));
      		mg.insert(make_pair(d,g));
      		mf.insert(make_pair(d,fns));
		}
		
			i=0;
			nsame=0;
			sflag=0;
			d.erase();
			da.erase();
			g.erase();
			fns.erase();
	  }
	  
      if( feof(fp) )									// if input file reaches eof then exit from loop
	  {
         break ;
      }
      
   }
   
   	map<string,string>::iterator it1 = mb.begin();     
   	map<string,string>::iterator it2 = mg.begin();
   	map<string,string>::iterator it3 = mf.begin();
   	it=m.begin();
   	
   	it++;
   	it1++;
   	it2++;
   	it3++;
   	
   	
      for(;it!=m.end();it++,it1++,it2++,it3++)			// write database into output file. 
      {
      	string tp = it->first;
      	int s = tp.size()-1;
      	
     	while(tp[s]>='0' && tp[s]<='9')
      	{
      		tp.erase(s,s+1);
			s--;	
		}
      	
     	cout<<tp<<","<<it1->second<<","<<it2->second<<","<<it3->second<<endl;
	  }
	 
   fclose(fp);
   return(0);
}
