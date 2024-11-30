#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

# Function to join given bound_by and tag
def join_middle(bound_by, tag_name):
  # complete the statement below to return the string as required
  return bound_by[0 :len(bound_by)//2] + tag_name + bound_by[len(bound_by)//2:len(bound_by)]  

#{ 
 # Driver Code Starts.
# Driver Code
def main():
    # testcase input
    testcases = int(input())
    
    # looping through testcases
    while(testcases > 0):
        string = input().split()
        bound_by = string[0]
        tag_name = string[1]
        
        testcases -= 1
        
        print (join_middle(bound_by, tag_name))

        print("~")
if __name__ == '__main__':
    main()
# } Driver Code Ends