/*
** The probem: Given 100 50-digit numbers in an input file,
** find the first 10 digits of the sum of the numbers.
*/

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using std::vector;
using std::cout;
using std::endl;
using std::ifstream;


void addVecs(vector<char> * base_p, vector<char> * curr_p, int length){
	int dif_1 = 0;
	int dif_2 = 0;
	
	vector<char>& base = *base_p;		
	vector<char>& curr = *curr_p;
	
	for(int i = length - 1; i >= 0; i--){
		dif_1 = 0;
		dif_2 = 0;
		
		if( (int)(base[i+2] - '0') > 9 ){ //check current base item, increase next if
			dif_1 = 10 - (int)(base[i+2] - '0');
			int tmp = (int)(base[i+1] - '0');			
			tmp++;
			base[i+1] = tmp + '0';
			base[i+2] = dif_1 = '0';
			dif_1 = 0;
		}
				
		dif_1 = 10 - (int)(base[i+2] - '0'); //difference until overflow
		
		if((int)(curr[i] - '0') >= dif_1) { //if the new addition is larger than the overflow difference
			dif_2 = (int)(curr[i] - '0') - dif_1; //new insertion value
			int tmp = (int)(base[i+1] - '0');
			tmp++;
			base[i+1] = tmp + '0';
			base[i+2] = dif_2 + '0';
		}
		else{
			int tmp = (int)(base[i+2] - '0');
			tmp = tmp + (int)(curr[i] - '0');			
			base[i+2] = tmp + '0';			
		}
		
		//check 2nd bucket for base vector
		if((int)(base[1] - '0') > 9){
			dif_1 = 10 - (int)(base[1] - '0');
			int tmp = (int)(base[0] - '0');
			tmp++;
			base[0] = tmp + '0';
			base[1] = dif_1 + '0';
		}
	}
}

int main(int argc, char** argv){
	
	if(argc < 2){
		cout << endl << "Usage: ./prob_13 <input file path\\name>" << endl;
		exit(0);
	}
	
	vector<char> base_vec (52, '0');
	vector<char> input_vec (50, '0');
	
	ifstream fs_in (argv[1], ifstream::in);
	char c = fs_in.get();
	int i = 0;
	while(fs_in.good()){ //while not EOF
		
		if(c!='\n') {
			input_vec[i%50] = c;	
		}
		
		if(i%50 == 49){ //input_vec has been filled for this number			
			addVecs(&base_vec, &input_vec, 50);
		}
		
		if(c!='\n') i++;
		c = fs_in.get();			
	}
	
	fs_in.close();
	
	cout << endl << "Sol: ";
	for(int i = 0; i < 10; i++){
	cout << (int)(base_vec[i] - '0') << " ";
	}
	cout << endl;
	
	return 0;
}
