#include <iostream>
#include <cmath>

using namespace std;

int list_prime(int , int *);
void concate_prime(int * , int );
int total_prime(int *, int);
int digit(int );

int main(){

	int n , *prime;
	
	cout << "Enter input : " ;
	cin >> n ;

	n = list_prime(n,prime);

	concate_prime(prime,n);

}

int list_prime(int n, int *prime){

	int i = 0 , j = 0, flag = 0, temp;

	while(n){

		flag = 0;
		for( i = 2; i <= n/2 ; i++ ){

			if( (n % i) == 0 ){

				flag = 1;
				break;

			}
		
		}
		if( flag == 0 && n != 1){
			//++j;
			*(prime+j) = n;
			++j;
		}
		--n;

	}

	return j;

}

void concate_prime( int *prime , int n ){

	int i , j , k=0 , temp = 0 ,size = n*n; 
	int cct[size];

//	for( k = 0 ; k < n*n ; k++ )
		for( i = 0 ; i < n ; i++ ) {
			for( j = 0 ; j < n ; j++,k++ ){
			
				temp = digit(prime[j]);
				temp = pow(10,temp);
				cct[k] = prime[i]*temp + prime[j];

		/*	temp = prime[i];
			strcat(prime[i],prime[j]);
			*(concate+k) = (int) prime[i];
			prime[i] = temp;
		*/

			}
		}

	n = total_prime(cct,k);

}

int total_prime(int *prime,int n){

	int i,j,flag=0,count=0;	

	for( i = 0 ; i < n ; i++ ){
		flag = 0;
		for( j = 2 ; j < prime[i]/2 ; j++ ){

			if( prime[i]% j == 0 ){
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			++count;
	}
	//return 1;
	cout << count << endl; 
}

int digit(int n){

	int count=0;

	while(n){

		++count;
		n = n/10;

	}

	return count;
}
