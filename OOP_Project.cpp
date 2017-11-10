/*Descriptive Statistics*/

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<fstream>

#include "loadingbar.h"

#define SIZE 100

using namespace std;

class Mean{	
	public:
	float mean(float array[],int n)
	{
	int i;
	float sum=0;
	for(i=0;i<n;i++)
	sum=sum+array[i];
	return (sum/n);
	}
};


	class Median{
		public:
			float median(float a[],int n)
				{
				float temp;
				int i,j;
				for(i=0;i<n;i++)
				for(j=i+1;j<n;j++)
				{
				if(a[i]>a[j])
				{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
				}
				}
				if(n%2==0)
				return (a[n/2]+a[n/2-1])/2;
				else
				return a[n/2];
				}
		
	};
	
	


class FirstQuartile{
	public:	
	float firstQuartile(float a[],int n)
			{
			float temp;
			int i,j;
			for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
			if(a[i]>a[j])
			{
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
			}
			}
			if(n%2==0)
			return (a[n/4]+a[n/4-1])/2;
			else
			return a[n/4];
			}
};


	class ThirdQuartile{
		public:
			float thirdQuartile(float a[],int n)
				{
				float temp;
				int i,j;
				for(i=0;i<n;i++)
				for(j=i+1;j<n;j++)
				{
				if(a[i]>a[j])
				{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
				}
				}
				if(n%2==0)
				return (a[(3*n)/4]+a[(3*n)/4-1])/2;
				else
				return a[(3*n)/4];
				}
	};

/*Multiple Inheritance*/
class QuartileDeviation : public FirstQuartile,public ThirdQuartile{
	public:
		float quartileDeviation(float a[],int n)
		{
			return (thirdQuartile(a,n)-firstQuartile(a,n))/2;
		}
	
	float coeffOfQD(float a[],int n)
		{
			float numerator, denominator;
			 numerator = (thirdQuartile(a,n)-firstQuartile(a,n)); 
			 denominator = (thirdQuartile(a,n)+firstQuartile(a,n));
			 return (numerator/denominator);
		}
};


	class Mode : public Mean,public Median{
		public:
			float mode(float a[],int n)
			{
			return (3*median(a,n)-2*mean(a,n));
			}
	};


/*Single Inheritance*/
class StandardDeviation : public Mean{
	public:
		float standardDeviation(float a[],int n)
		{
		int i;
		float sd=0;
		for(i=0;i<n;++i)
		{
        sd += pow(a[i] - mean(a,n), 2);
		}
    return sqrt(sd / n);
		}
};


	class MeanDeviation : public Mean{
		public:
			float meanDeviation(float a[],int n)
			{
			int i;
			float md=0;
			for(i=0;i<n;++i)
			{
	        md += (a[i] - mean(a,n));
			}
			if(md<0)
			{
				return (-1*md)/n;
			}
			return (md/n);
		}
	};


class Range{
	private:
		float min;
		float max;
	public:
		Range(float mi,float ma)
		{
			min=mi;
			max=ma;
		}
		
		float range (float a[], int n)
		{
		    int i, r;
		    min = max = a[0];
		    for(i=0;i<n;i++)
		    {           
		        if(a[i]>max)
		            max = a[i];
		        if(a[i] < min)
		            min = a[i];
		    }
		    r = max-min;
		    return r;
		}
		
		float coeffOfRange(float a[], int n)
		{
			return ((max-min)/(max+min));
		}
};

	class Skewness : public FirstQuartile, public ThirdQuartile,public Median{
		public:
			float skewness(float a[], int n)
			{
				float numerator,denominator;
				numerator = thirdQuartile(a,n)+firstQuartile(a,n)-2*median(a,n);
				denominator = thirdQuartile(a,n)-firstQuartile(a,n);
				
				return (numerator/denominator);
			}
	};

class PercentileNinty{
	public:
			float percentileNinty(float a[],int n)
				{
				float temp;
				int i,j;
				for(i=0;i<n;i++)
				for(j=i+1;j<n;j++)
				{
				if(a[i]>a[j])
				{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
				}
				}
				if(n%2==0)
				return (a[9*n/10]+a[9*n/10-1])/2;
				else
				return a[9*n/10];
				}
};

	class PercentileTen{
		public:
			float percentileTen(float a[],int n)
				{
				float temp;
				int i,j;
				for(i=0;i<n;i++)
				for(j=i+1;j<n;j++)
				{
				if(a[i]>a[j])
				{
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
				}
				}
				if(n%2==0)
				return (a[n/10]+a[n/10-1])/2;
				else
				return a[n/10];
				}
	};


class Kurtosis: public ThirdQuartile, public FirstQuartile, public PercentileNinty, public PercentileTen{
	public:
		float kurtosis(float a[],int n)
		{
			float numerator, denominator;
			
			numerator = (thirdQuartile(a,n)-firstQuartile(a,n));
			denominator = 2*((percentileNinty(a,n))-(percentileTen(a,n)));
			
			return (numerator/denominator);
		}		
};


		int main()
		{
		int i,n,choice;
		float array[SIZE],mean,median,mode;
		float skew,kurt;
		LoadingBar l;
		
				l.loadingBar();
				
				
				 
				cout<<"\nEnter No of Elements"<<endl;
				cin>>n;
				
				if(n<1)
				{
					cout<<"Invalid Entry!"<<endl;
				}
				
				else				
				{
					cout<<"Enter elements "<<endl;
				for(i=0;i<n;i++)
				cin>>array[i];
			
				system("cls");
		
		Mean m;
		Median md;
		Mode mo;
		Range r(0,0);
		QuartileDeviation qd;
		MeanDeviation mdd;
		StandardDeviation sd;
		Skewness s;
		Kurtosis k;
		
				cout<<"DESCRIPTIVE STATISTICS (Analysis of Data)"<<endl<<endl<<endl;
				cout<<"*********************************Central Tendency*******************************"<<endl;
				cout<<"\t\t\tMean is: "<<m.mean(array,n)<<endl<<endl;
				cout<<"\t\t\tMedian is: "<<md.median(array,n)<<endl<<endl;
				cout<<"\t\t\tMode is: "<<mo.mode(array,n)<<endl;
				cout<<endl;
				cout<<"*********************************Dispersion*******************************"<<endl;
				cout<<"\t\t\tRange is: "<<r.range(array,n)<<endl;
				cout<<"\t\t\tCoefficient of Range is: "<<r.coeffOfRange(array,n)<<endl<<endl;
				cout<<"\t\t\tQuartile Devition is: "<<qd.quartileDeviation(array,n)<<endl;
				cout<<"\t\t\tCoefficient of Quartile Deviation is: "<<qd.coeffOfQD(array,n)<<endl<<endl;
				cout<<"\t\t\tMean Deviation is: "<<mdd.meanDeviation(array,n)<<endl<<endl;
				cout<<"\t\t\tStandard Deviation is:"<<sd.standardDeviation(array,n)<<endl<<endl;
				cout<<"\t\t\tVariance is "<<pow (sd.standardDeviation(array,n),2)<<endl;
				cout<<endl;
				cout<<"*********************************Skewness*******************************"<<endl;
				skew = s.skewness(array,n);
				if(skew==0)
				{
					cout<<"\t\t\tEntered data is symmetrical (Not Skewed)"<<endl;
				}
				else if(skew>0)
				{
					cout<<"\t\t\tEntered data is positively skewed (Right skewed)"<<endl;
				}
				else if (skew<0)
				{
					cout<<"\t\t\tEntered data is negatively skewed (Left skewed)"<<endl;
				}
				cout<<endl;
				cout<<"*********************************Kurtosis******************************"<<endl;
				kurt = k.kurtosis(array,n);
				if(kurt==0.263)
				{
					cout<<"\t\t\tEntered data is mesokurtic"<<endl;
				}
				else if(kurt>0.263)
				{
					cout<<"\t\t\tEntered data is leptokurtic"<<endl;
				}
				else if(kurt<0.263)
				{
					cout<<"\t\t\tEntered data is platykurtic"<<endl;
				}
			
				
		ofstream file;
		file.open("result.txt");
		file<<"DESCRIPTIVE STATISTICS (Analysis of Data)"<<endl<<endl<<endl;
				file<<"Entered data are:"<<endl;
				for(i=0;i<n;i++)
				{
					file<<array[i];
					cout<<" ";
				}
				file<<"\n*********************************Central Tendency*******************************"<<endl;
				file<<"\t\t\tMean is: "<<m.mean(array,n)<<endl<<endl;
				file<<"\t\t\tMedian is: "<<md.median(array,n)<<endl<<endl;
				file<<"\t\t\tMode is: "<<mo.mode(array,n)<<endl;
				file<<endl;
				file<<"*********************************Dispersion*******************************"<<endl;
				file<<"\t\t\tRange is: "<<r.range(array,n)<<endl;
				file<<"\t\t\tCoefficient of Range is: "<<r.coeffOfRange(array,n)<<endl<<endl;
				file<<"\t\t\tQuartile Devition is: "<<qd.quartileDeviation(array,n)<<endl;
				file<<"\t\t\tCoefficient of Quartile Deviation is: "<<qd.coeffOfQD(array,n)<<endl<<endl;
				file<<"\t\t\tMean Deviation is: "<<mdd.meanDeviation(array,n)<<endl<<endl;
				file<<"\t\t\tStandard Deviation is:"<<sd.standardDeviation(array,n)<<endl<<endl;
				file<<"\t\t\tVariance is "<<pow (sd.standardDeviation(array,n),2)<<endl;
				file<<endl;
				file<<"*********************************Skewness*******************************"<<endl;
				skew = s.skewness(array,n);
				if(skew==0)
				{
					file<<"\t\t\tEntered data is symmetrical (Not Skewed)"<<endl;
				}
				else if(skew>0)
				{
					file<<"\t\t\tEntered data is positively skewed (Right skewed)"<<endl;
				}
				else if (skew<0)
				{
					file<<"\t\t\tEntered data is negatively skewed (Left skewed)"<<endl;
				}
				file<<endl;
				file<<"*********************************Kurtosis******************************"<<endl;
				kurt = k.kurtosis(array,n);
				if(kurt==0.263)
				{
					file<<"\t\t\tEntered data is mesokurtic"<<endl;
				}
				else if(kurt>0.263)
				{
					file<<"\t\t\tEntered data is leptokurtic"<<endl;
				}
				else if(kurt<0.263)
				{
					file<<"\t\t\tEntered data is platykurtic"<<endl;
				}
		file.close();
				}
				
		}
