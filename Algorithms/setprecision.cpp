#include <iostream>
#include <iomanip>
#include <ios>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() 
{
	double pi = 3.14159, npi = -3.14159;
	cout<<pi;
	cout<<setprecision(4)<<"\n";
	cout<<pi;
	cout<<setprecision(2)<<"\n";
	cout<<pi;
	cout<<setprecision(1)<<"\n";
	cout<<pi;
	cout<<setprecision(0)<<"\n";
	cout<<pi;
	
	cout<<"\n\n\n";
	
	cout << fixed << setprecision(0) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(1) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(2) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(3) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(4) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(5) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(6) << pi <<" "<<npi<<endl; 
	return 0;
}
