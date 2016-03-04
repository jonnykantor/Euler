#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;

int main(int argc, char** argv){
	
	if(argc < 2){ cout << endl << "Usage: ./prob_10 <number> - adds all primes less than <number>" << endl; exit(0); }
	
	long long target = atol(argv[1]);
	
	vector<long> primes (target);
	for(long i = 2; i < target; i++){
		primes[i] = i;
	}
	long mult = 0;
	
	for(long i = 2; i < (long)ceil(sqrt(target)); i++){ //index	
		if(primes[i]!=0){ //if the entry has not been reduced to 0	
			mult = i;
			long q = ((i + target - 1)/i);
			for(long j = i; j < q; j++){	
				mult = j * i; //the new multiple
				primes[mult] = 0;
			}
		}
	}
	
	long long total = 0;
	
	//cout << endl;
	for(size_t i = 0; i < primes.size(); i++){
		//cout << primes[i] << " ";
		total = total + primes[i];
	}
	
	
	cout << endl << total << endl;
}