//this is a test programme for random number generation
#include <boost/random.hpp> // Convenience header file
#include <iostream>
#include <ctime>			// std::time
#include <boost/Random/detail/const_mod.hpp> // LCG class
#include <map>    //STL container map

using namespace std;

void main()
{
	// Throwing dice.
	// Mersenne Twister.
	boost::random::mt19937 myRng;
	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));
	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1,6);

	//create a map that holds the frequency of each outcome
	map<int, long> statistics; // Structure to hold outcome + frequencies
	int outcome; // Current outcome

	//initialize statistics
	for (int i=1;i<=6;++i)
	{
		statistics[i]=0;
	}

	//Get trial times from user
	long times;
	cout<<"How many trials? "; cin>>times;

	//generating results (for user specified times)
	for (int i=0;i<times;i++)
	{
		outcome = six(myRng);//cast the die
		//cout<<outcome<<endl;//for debug use
		switch (outcome)//for different outcomes
		{
		case 1://add to corresponding counts
			{
				statistics[1]+=1;
				break;
			}
		case 2://add to corresponding counts
			{
				statistics[2]+=1;
				break;
			}
		case 3://add to corresponding counts
			{
				statistics[3]+=1;
				break;
			}
		case 4://add to corresponding counts
			{
				statistics[4]+=1;
				break;
			}
		case 5://add to corresponding counts
			{
				statistics[5]+=1;
				break;
			}
		case 6://add to corresponding counts
			{
				statistics[6]+=1;
				break;
			}
		default:
			{
				break;
			}
		}
	}

	//print outcomes on screen
	for (int i=1;i<=6;++i)
	{
		double percent; double count=statistics[i]; double Times=times;
		percent=count*100/Times;
		cout<<"Trial "<<i<<" has "<<statistics[i]<<" and "<<percent<<"% outcomes."<<endl;
	}
}