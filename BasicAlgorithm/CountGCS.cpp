// Ziyi Tang
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define bound 1000
using namespace std;
// Test Case
const string a = "POIUYIJKJYYOIUYOIUYLK";
const string b = "PIPOITOIUJJOIUYK";

/*
 *	 First Part: Figure out the length of GCS
 */

// Initialize Lookup Table
int length[bound][bound]; 
int count[bound][bound];
int get_length(int i, int j){
	if (length[i][j] != -1){
		return length[i][j];
	}
	else{
		int thelength;
		if (i < 0 || j < 0){
			return 0;
		}
		else if (a[i] == b[j]){
			thelength = 1 + get_length(i-1,j-1);
			length[i][j] = thelength;
			return thelength;
		}
		else{
			int tmp1 = get_length(i-1,j);
			int tmp2 = get_length(i,j-1);
			if (tmp1 > tmp2){
				thelength = tmp1;
			}
			else{
				thelength = tmp2;
			}
			length[i][j] = thelength;
			return thelength;
		}
	}
	

}

/*
 *	 Second Part: Count pairs
 */
int get_count(int i, int j){
	if (count[i][j] != -1){
		return count[i][j];
	}
	else{
		if (i < 0 || j < 0){
			return 0;
		}
		else{
			int tmpcount;
			if (length[i][j] == 0){
				count[i][j] = 1;
				return 1;	// When the max length of GCS is 0, we assume that
							// there is one pair of "nothing match" string, so that
							// the neighboring positions on table can get correct values
							// by this recursive algorithm.
			}
			else if (length[i][j] == length[i-1][j-1]){
				tmpcount = max(get_count(i-1,j), get_count(i,j-1));
				count[i][j] = tmpcount;
			}
			else{
				if (a[i] == b[i]){
					tmpcount	= count[i-1][j-1] 
								+ (length[i-1][j]-length[i-1][j-1])*count[i-1][j] 
								+ (length[i][j-1]-length[i-1][j-1])*count[i][j-1];
					count[i][j] = tmpcount;
				}
				else{
					tmpcount	= (length[i-1][j]-length[i-1][j-1])*count[i-1][j] 
								+ (length[i][j-1]-length[i-1][j-1])*count[i][j-1];
					count[i][j] = tmpcount;
				}
			}
			return tmpcount;

		}
	}
}
int main(){
	memset(length, -1, sizeof(length)); // Set all position to -1
	memset(count, -1, sizeof(count)); 
	int m = a.size();
	int n = b.size();
	int getlength = get_length(m-1,n-1);
	int getcount = get_count(m-1,n-1);

	return 0;
}