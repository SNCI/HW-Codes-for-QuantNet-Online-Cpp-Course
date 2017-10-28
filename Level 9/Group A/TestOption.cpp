//	This is the source file for testing BS option pricing models
//	
//	This file contains the main programme and global function body
//
//	For other included files, namespaces and structs, global functions declarations
//
//	See "OptionElements.h" (fucntions that were once global but are now incorporated in class are commented out)
//
//	Comment out different namespaces to carry out test for different batches

//	include necessary file
#include "OptionElements.h"
#include "EUoption.h"

//	main programme
void main()
{
		using namespace Batch1;	//result: call:2,13337, put: 5.84628
	//	using namespace Batch2; //result: call:7.96557, put:7.96557
	//	using namespace Batch3; //result: call:0.204058, put:4.07326
	//	using namespace Batch4; //result: call:92.1757, put:1.2475

	char type1='C'; char type2='P';		//	set type parameters
	EUoption EUcall(K,T,r,sig,type1);
	EUoption EUput(K,T,r,sig,type2);
	cout<<"Call-option price: "<<EUcall.Price(S)<<","<<"Put-option price: "<<EUput.Price(S)<<endl;	//	print the result

	//	put-call parity test, all 4 batches passed
	cout<<"call-parity(put): "<<ParityPrice(S,EUcall)<<", put-parity(call): "<<ParityPrice(S,EUput)<<endl;
	cout<<endl;							//	print a new line

	//	test for struct version of each function
	cout<<"Struct Version Test:"<<endl;
	OptionData OptD;								//	create an object of struct OptionData
	OptD.K=K; OptD.T=T; OptD.r=r; OptD.sig=sig;		//	initialize each member data with data in the batch

	double C1=BSCallPrice(OptD,S);		//	calculate with struct version
	double P1=BSPutPrice(OptD,S);		//	calculate with struct version
	cout<<"Call-option price: "<<C1<<","<<"Put-option price: "<<P1<<endl;				//	print the result
	cout<<endl;							//	print a new line

	cout<<"Put-Call Parity Check, struct version:"<<endl;
	PCParity(OptD,S,C1,type1);		//	test struct version
	PCParity(OptD,S,P1,type2);		//	test struct version
	cout<<endl;						//	print a new line
	
	//	declare the neccessary
	//	containers of conditions
	vector<double> StockP=CutVec(10,1,50);				//	call Cut()
	vector<double> Time=CutVec(0.25,0.25,50);			//	as above
	vector<double> Volatility=CutVec(0.01,0.001,50);	//	as above

	//	containers of results
	vector<double> Output1;
	Output1.reserve(50);		//	reserve places for elements
	vector<double> Output2;
	Output2.reserve(50);		//	reserve places for elements
	
	//	calculate option price for different stock prices (other parameters in batches remain the same as before)
	cout<<"Option price for different stock price:"<<endl;
	for (int i=0;i!=50;i++)
	{
	Output1.push_back(BSCallPrice(OptD,StockP[i]));		//	calculate call price
	Output2.push_back(BSPutPrice(OptD,StockP[i]));		//	calculate put price
	cout<<"Stock Price: "<<StockP[i]<<", Call Price: "<<Output1[i]<<", Put Price:"<<Output2[i]<<endl;	//	print the results
	}
	Output1.clear(); Output2.clear();
	cout<<endl;

	//	calculate option price for different time to maturity (other parameters in batches remain the same as before)
	cout<<"Option price for different time to maturity:"<<endl;
	for (int i=0;i!=50;i++)
	{
	OptD.T=Time[i];
	Output1.push_back(BSCallPrice(OptD,S));		//	calculate call price
	Output2.push_back(BSPutPrice(OptD,S));		//	calculate put price
	cout<<"Time to Maturity: "<<Time[i]<<", Call Price: "<<Output1[i]<<", Put Price:"<<Output2[i]<<endl;	//	print the results
	}
	Output1.clear(); Output2.clear();
	cout<<endl;

	//	calculate option price for different volatility (other parameters in batches remain the same as before)
	cout<<"Option price for different stock price volatility:"<<endl;
	for (int i=0;i!=50;i++)
	{
	OptD.sig=Volatility[i];
	Output1.push_back(BSCallPrice(OptD,S));		//	calculate call price
	Output2.push_back(BSPutPrice(OptD,S));		//	calculate put price
	cout<<"Volatility: "<<Volatility[i]<<", Call Price: "<<Output1[i]<<", Put Price:"<<Output2[i]<<endl;	//	print the results
	}
	Output1.clear(); Output2.clear();
	cout<<endl;
	
	//	test for delta
	K=100; S=105; T=0.5; r=0.1; sig=0.36; double b=0;					//	required data
	vector<double> H=CutVec(0.1,0.05,10);								//	step length used in approximation
	
	EUoption EUcall1(K,T,r,sig,type1);	EUcall1.ModelParameter(b);
	EUoption EUput1(K,T,r,sig,type2);	EUput1.ModelParameter(b);
	
	cout<<"delta call: "<<EUcall1.Delta(S)<<", delta put: "<<EUput1.Delta(S)<<endl;		//	results: call:0.594629, put:-0.356601
	cout<<"gamma: "<<EUcall1.Gamma(S)<<endl;
	cout<<endl;
	
	cout<<"Approximated version:"<<endl;
	for (int i=0;i!=10;i++)
	{
		cout<<"Step length: "<<H[i]<<endl;
		cout<<"delta call: "<<EUcall1.ApprxDelta(S,H[i])<<", delta put: "<<EUput1.ApprxDelta(S,H[i])<<", gamma: "<<EUcall1.ApprxGamma(S,H[i])<<endl;	
	}
	cout<<endl;
	
	//	series delta test
	for (int i=0;i!=50;i++)
	{
	Output1.push_back(EUcall1.Delta(StockP[i]));
	Output2.push_back(EUput1.Delta(StockP[i]));
	cout<<"Stock Price: "<<StockP[i]<<", delta call: "<<Output1[i]<<", delta put: "<<Output2[i]<<endl;
	}
	Output1.clear(); Output2.clear();
	cout<<endl;
	
	//	approximate deltas
	double h=0.5;
	for (int i=0;i!=50;i++)
	{
	Output1.push_back(EUcall1.ApprxDelta(StockP[i],h));
	Output2.push_back(EUput1.ApprxDelta(StockP[i],h));
	cout<<"Stock Price: "<<StockP[i]<<", Approx delta call: "<<Output1[i]<<", Approx delta put: "<<Output2[i]<<endl;
	}
	Output1.clear(); Output2.clear();
	cout<<endl;
}

//	global functions function body
//	call-option struct version
double BSCallPrice(const OptionData& OptD, const double& S)
{
	//	declare parameters
	double C,d1,d2,b;					// price, parameter d1, parameter d2,cost of carry
	normal_distribution<> N(0.0,1.0);	// standard normal distribution

	//	calculate parameters
	b=OptD.r;											// In Black-Scholes model
	d1=(log(S/OptD.K)+(b+(OptD.sig*OptD.sig/2))*OptD.T)/(OptD.sig*sqrt(OptD.T));
	d2=d1-OptD.sig*sqrt(OptD.T);

	// calculate option price
	C=S*exp((b-OptD.r)*OptD.T)*cdf(N,d1)-OptD.K*exp(-OptD.r*OptD.T)*cdf(N,d2);

	return C; 
}

//	put-option struct version
double BSPutPrice(const OptionData& OptD, const double& S)
{
	//	declare parameters
	double P,d1,d2,b;					// price, parameter d1, parameter d2,cost of carry
	normal_distribution<> N(0.0,1.0);	// standard normal distribution

	//	calculate parameters
	b=OptD.r;											// In Black-Scholes model
	d1=(log(S/OptD.K)+(b+(OptD.sig*OptD.sig/2))*OptD.T)/(OptD.sig*sqrt(OptD.T));
	d2=d1-OptD.sig*sqrt(OptD.T);

	// calculate option price
	P=OptD.K*exp(-OptD.r*OptD.T)*cdf(N,-d2)-S*exp((b-OptD.r)*OptD.T)*cdf(N,-d1);

	return P;	//	call plain version 
}

//	put-call parity struct version
double PCParity(const OptionData& OptD, const double& S,const double& price, const char& type)
{
	double parityP;
	if (type==67)	//	if the input is a call-option price
	{
		parityP=price+OptD.K*exp(-OptD.r*OptD.T)-S;
	}
	else			//	if the input is a put-option price
	{
		parityP=price+S-OptD.K*exp(-OptD.r*OptD.T);
	}

	//	print the result
	cout<<"Original option type: "<<type<<endl;						//	benchmark type
	cout<<"Price according to Put-Call Parity: "<<parityP<<endl;	//	result

	return parityP;
}

//	produces a mesh array of doubles separated by a mesh size h
vector<double> CutVec(const double& start, const double& h, const int& size)
{
	vector<double> Proto;				//	declare the vector to be returned
	Proto.reserve(size);				//	reserve places for elements
	for (int i=0;i!=size;i++)			//	initialize elements according to requirement
	{
		Proto.push_back(start+h*i);
	}
	return Proto;
}