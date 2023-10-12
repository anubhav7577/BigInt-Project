#include <bits/stdc++.h> 
using namespace std;

// in this function we will do addition 

void addition(string data1 , string data2 ,vector< unsigned long long int> &sum)
{
      int n1,n2;

// first we will find the length of both string means how many digit in every data

      n1=data1.length();
      n2=data2.length();

// for performing addition in easy form we will reverse the data so that we can perform addition operation easily      
      reverse(data1.begin(),data1.end());
      reverse(data2.begin(),data2.end());
      
// here we will compare the data digit & according to the data digit we will perform the operation
     int i,num,carry=0;
     
// if first data digits larger
	 if(n1>n2)
	 {
	 	 for( i=0; i<n2 ;i++)
	 	 {
	 	 num = ((data1[i]-'0')+(data2[i]-'0')+carry);
		sum.push_back(num%10); 
		// Calculate carry for next step 
		carry = num/10; 
		  }
		  
	  	for (int i=n2; i<n1; i++) 
		{ 
		 num = ((data1[i]-'0')+carry); 
		sum.push_back(num%10 ); 
		carry = num/10; 
		} 

	// Add remaining carry 
    	if (carry) 
		sum.push_back(carry);	
	} 
	
// if second data digits are larger
	else if(n2>n1)
	 {
	 	 for( i=0; i<n1 ;i++)
	 	 {
	 	 num = ((data1[i]-'0')+(data2[i]-'0')+carry);
		sum.push_back(num%10); 
		// Calculate carry for next step 
		carry = num/10; 
		  }
		  
	  	for (int i=n1; i<n2; i++) 
		{ 
		 num = ((data2[i]-'0')+carry); 
		sum.push_back(num%10 ); 
		carry = num/10; 
		} 

	// Add remaining carry 
    	if (carry) 
		sum.push_back(carry);	
	} 
	
// both data digits are same
    else
	 {
	 	 for( i=0; i<n2 ;i++)
	 	 {
	 	 num = ((data1[i]-'0')+(data2[i]-'0')+carry);
		sum.push_back(num%10); 
		// Calculate carry for next step 
		carry = num/10; 
		  }
		  
	// Add remaining carry 
    	if (carry) 
		sum.push_back(carry);	
	} 
	
// after operation we repeat the reverse operation again so that we can get the data as we got
//
//	  reverse(data1.begin(),data1.end());
//      reverse(data2.begin(),data2.end());
	  reverse(sum.begin(),sum.end());
	  
// for checking the data 
//	  for(i=0; i<sum.size();i++)
//	   cout<<sum[i];

}



// Returns true if data1 is smaller than data2.
bool isSmaller(string data1, string data2)
{
    // Calculate lengths of both string
    int n1 = data1.length(), n2 = data2.length();
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
  // if both data digit length are same so we are checking all element so that we can make data1  will be larger  
    for (int i = 0; i < n1; i++)
        if (data1[i] < data2[i])
            return true;
        else if (data1[i] > data2[i])
            return false;
 
    return false;
}

 
// Function for find difference of larger numbers
void subtraction(string data1, string data2, vector< unsigned long long int>&sub)
{
   // for easy subtraction we are making data1 is larger than second data
    if (isSmaller(data1, data2))
        swap(data1, data2);
 
    // Calculate length of both string
    int n1 = data1.length(), n2 = data2.length();
 
    // Reverse both of strings for easy calculation
    reverse(data1.begin(), data1.end());
    reverse(data2.begin(), data2.end());
 
    int num ,carry = 0;
 
    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++) 
	{
        // Do school mathematics, compute difference of
        // current digits
 
        num = ((data1[i] - '0') - (data2[i] - '0') - carry);
 
        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (num < 0)
		 {
            num = num + 10;
            carry = 1;
         }
        else
            carry = 0;
 
        sub.push_back(num);
    }
 
// subtract remaining digits of larger number
    for (int i = n2; i < n1; i++) 
	{
        int num= ((data1[i] - '0') - carry);
 
        // if the sub value is -ve, then make it positive
        if (num< 0) {
            num = num + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        sub.push_back(num);
    }
 
    // reverse resultant string so that data can be seen in proper form
    reverse(sub.begin(), sub.end());
}
 

// printing the data 

void print_data( string data1,string data2)
{
	 
	  cout<<data1<<"\n"<<data2<<endl<<endl<<endl;
}



int main()
{  
	 int t=0;
	cout<<"how many do you want to test it ::  ";
	 cin>>t;
	 
	while(t--)
	{
	 
	 	string data1 ,data2,data3,data4;
		vector< unsigned long long int> sum , sub;   
	 cout<<"\nenter the data for addition \n";
		cout<<"enter the first data :: ";
		cin>>data1;
		cout<<"enter the second data :: ";
		cin>>data2;
		cout<<"entered  data is below\n";
  		print_data(data1, data2);

// performing the addition operation on the given data
    addition(data1,data2,sum);
       cout<<"after addition answer is ::   ";
       for(int i=0; i<sum.size();i++)
	   cout<<sum[i];
	   cout<<"\n\n\n";
// performing the subtraction operation 	
	cout<<"enter the data for subtraction \n";
    	cout<<"enter the first data :: ";
		cin>>data3;
		cout<<"enter the second data :: ";
		cin>>data4;
		cout<<"entered data is below\n";
		print_data(data3, data4);

    subtraction(data3,data4,sub);
       cout<<"after subtracting answer is ::   ";
       for(int i=0; i<sub.size();i++)
	   cout<<sub[i];
	   cout<<"\n";
    }

	return 0;
}


/* 
 for example data1 =  54326789013892014531903492543267890138920145319034925432678901389201 
             data2 = 7890138920145319034925432678907890138920145319034925432678901903492543267890
             
             data1 = 12345678098765431234567809876543034925432678901389
             data2 = 2678907890138920145319034925432678901903492543267890
*/

