//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class complex
{
    int x, y;

    
    public:
    complex(){}
    
    complex(int real, int imag)
    {x=real; y=imag;}
    
    complex operator+(complex c)
    {
        // Add your code here.
        complex ans;
        ans.x = this->x + c.x; // Add real parts
        ans.y = this->y + c.y; // Add imaginary parts
        return ans;
    }
    
    void display()
    {
        cout<<x<<" + "<<y<<"i"<<endl;
       
    }
    
    
};


//{ Driver Code Starts.

int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
        int c11, c12, c21, c22;
        cin>>c11>>c12>>c21>>c22;
     
        
	
	complex c1, c2, c3;
	c1 = complex(c11, c12);
	c2 = complex(c21, c22);
	c3 = c1 + c2;
	
	c3.display();
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends