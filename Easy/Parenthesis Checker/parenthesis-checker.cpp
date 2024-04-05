//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string expr)
    {
        stack<char> s; 
	    char x; 

    	// Traversing the Expression 
    	for (int i=0; i<expr.length(); i++) 
    	{ 
    		if (expr[i]=='('||expr[i]=='['||expr[i]=='{') 
    		{ 
    		
    			s.push(expr[i]); 
    			continue; 
    		} 
    
    		 
    		if (s.empty()) 
    		return false; 
    
    		switch (expr[i]) 
    		{ 
    		case ')': 
    
    		
    			x = s.top(); 
    			s.pop(); 
    			if (x=='{' || x=='[') 
    				return false; 
    			break; 
    
    		case '}': 
    
    		
    			x = s.top(); 
    			s.pop(); 
    			if (x=='(' || x=='[') 
    				return false; 
    			break; 
    
    		case ']': 
    
    			x = s.top(); 
    			s.pop(); 
    			if (x =='(' || x == '{') 
    				return false; 
    			break; 
		   } 
	    } 
	    return (s.empty()); 

        
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends