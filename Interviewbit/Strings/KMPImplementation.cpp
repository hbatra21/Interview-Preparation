#include<iostream>
#include<string>

using namespace std;

int *pre_kmp(string pattern)
{
	int size = pattern.size();
	int *f = new int [size];
	f[0] = 0;
	int j = 0;
	for(int i=1;i<size;i++)
	{
		while(j > 0 && pattern[j] != pattern[i] )
		{
			j = f[j-1];
		}
		if( pattern[j] == pattern[i] )
		{
			j++;
		}
		f[i] = j;
	}
	
	return f;
}

void kmp(string text,string pattern)
{
	int* f=pre_kmp(pattern);
	int matched_pos=0;
	for(int current=0; current< text.length(); current++)
	{
		while (matched_pos > 0 && pattern[matched_pos] != text[current] )
			matched_pos = f[matched_pos-1];
			
		if(pattern[matched_pos] == text[current])
			matched_pos = matched_pos+1;
			
		if( matched_pos == (pattern.length()) )
		{
			cout<<"Pattern occurs with shift "<< current - (pattern.length() -1 );
			matched_pos = f[matched_pos-1];
		}
	}
}
int main()
{
	string text,pattern;
	cin>>text;
	cin>>pattern;
	kmp(text,pattern);
	return 0;
}
