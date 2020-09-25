#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	ll n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	ll char1=0,char2=0;
	map<char,int> m1,m2;
	vector<vector<int> > ar1(27,vector<int>()),ar2(27,vector<int>());
	
	for(int i='a';i<='z';i++)
	{
		m1[i]=0;
		m2[i]=0;
	}
	m1['?']=m2['?']=0;
	//cout<<a<<" "<<b<<endl;
	for(int i=0;i<n;i++)
	{
		m1[a[i]]++;
		m2[b[i]]++;
		
		if(a[i]!='?')
		{
			ar1[a[i]-'a'].push_back(i);
			char1++;
		}
		else
		{
			ar1[26].push_back(i);
		}
		if(b[i]!='?')
		{
			ar2[b[i]-'a'].push_back(i);
			char2++;
		}
		else
		{
			ar2[26].push_back(i);
		}
	}
	
	ll ans=0;
	for(int i='a';i<='z';i++)
	{
		ans+=min(m1[i],m2[i]);
	}
	
	//cout<<char1<<" "<<char2<<endl;
	ll tmp1=min(char1-ans,(ll)m2['?']);
	ll tmp2=min(char2-ans,(ll)m1['?']);
	//cout<<tmp1<<" "<<tmp2<<" "<<ans<<endl;
	ans+=tmp1+tmp2+min(m1['?']-tmp2,m2['?']-tmp1);
	
	cout<<ans<<endl;
	
	for(int i='a';i<='z';i++)
	{
		for(int j=0;j<min(m1[i],m2[i]);j++)
		{
			cout<<ar1[i-'a'][j]+1<<" "<<ar2[i-'a'][j]+1<<endl;
			ar1[i-'a'][j]=ar2[i-'a'][j]=-1;
		}
		
	}
	vector<int>::iterator it=ar1[0].begin();
	ll j=0;
	for(int i=0;i<tmp1;i++)
	{
		bool bo=1;
		
		while(bo)
		{
			for(;it!=ar1[j].end()&&bo;it++)
			{
				if(*it!=-1)
				{
					cout<<*it+1<<" ";
					*it=-1;
					bo=0;
				}
			}
			if(it==ar1[j].end())
			{
				j++;
				it=ar1[j].begin();
			}
		}
		cout<<ar2[26][i]+1<<endl;
	}
	//cout<<"List1"<<endl;
	it=ar2[0].begin();
	j=0;
	for(int i=0;i<tmp2;i++)
	{
		bool bo=1;
		cout<<ar1[26][i]+1<<" ";
		while(bo)
		{
			for(;it!=ar2[j].end()&&bo;it++)
			{
				if(*it!=-1)
				{
					cout<<*it+1<<endl;
					*it=-1;
					bo=0;
				}
			}
			if(it==ar2[j].end())
			{
				j++;
				it=ar2[j].begin();
			}
		}
	}
	//cout<<"List2"<<endl;
	for(int i=0;i<min(m1['?']-tmp2,m2['?']-tmp1);i++)
	{
		cout<<ar1[26][tmp2+i]+1<<" "<<ar2[26][tmp1+i]+1<<endl;
	}
}
