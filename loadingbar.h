#include<iostream>

using namespace std;

class LoadingBar{
		public:
			void loadingBar()
			{
				 char a=177;
				 char b[22]={'D','E','S','C','R','I','P','T','I','V','E',' ','S','T','A','T','I','S','T','I','C','S'};
				 cout<<"\t\t\t\t";
				 for (int i=0;i<=22;i++)
				 cout<<a;
				 cout<<"\r";
				 cout<<"\t\t\t\t";
				 for (int i=0;i<=22;i++)
				 {
				  cout<<b[i];
				  for (int j=0;j<=1e7;j++);
				 }
				 
				 cout<<endl<<"Presented By : Shiva Tripathi"<<endl<<"Roll Number : 532"<<endl;
			}
	};
