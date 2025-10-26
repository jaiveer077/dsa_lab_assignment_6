#include<iostream>
using namespace std; int
main(){
int n;
cout << "Enter the no. of
elements:"; cin >> n; int arr[n];
cout << "Enter elements of array:";
for(int i=0;i<n;i++){ cin >> arr[i];
}
int low=0,high=n-1;
int ele;
cout << "Enter element to be searched:"; cin >> ele;
while(low<=high){ int mid=(low+high)/2; if(arr[mid]==ele)
{cout << ele << " found at position " << mid+1;
break;
}
if(arr[mid]<ele) low=mid+1;
if(arr[mid]>ele) high=mid-1;
}
if(low>high) cout << "Element not found";
return 0;
}
OUTPUT:
Enter the no. of elements:4
Enter elements of array:3 4 6 7
Enter element to be searched:6
6 found at position 3
Q.2
#include<iostream> using
namespace std; int main(){ int
arr[]={64,34,25,12,22,11,90};
for(int i=0;i<6;i++){ for(int
j=0;j<6-i;j++){
if(arr[j]>arr[j+1]){ int
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
for(int i=0;i<7;i++){
cout << arr[i] << " ";
} return
0;
}
OUTPUT:
11 12 22 25 34 64 90
Q.3a
#include<bits/stdc++.h>
using namespace std; int
missingNumber (int a[], int
n){ int sum = (n*(n+1))/2;
int sumOfArrayElements = 0;
for(int i = 0 ; i < n-1 ; i++){
sumOfArrayElements += a[i];
}
return sum - sumOfArrayElements;
}
int main(){ int arr[] = {1,2,5,4}; int n =
sizeof(arr)/sizeof(arr[0]); int missingNum =
missingNumber(arr, n+1); cout<<"The Number
missing is: "<<missingNum;
return 0;
}
OUTPUT:
The Number missing is: 3
Q.3b
#include <iostream> using
namespace std;
int findMissing(int arr[], int n)
{ int low = 0, high = n - 2;
while (low <= high) { int
mid = (low + high) / 2; if
(arr[mid] == mid + 1)
low = mid + 1; else
high = mid - 1;
}
return low + 1; // missing number
}
int main() { int arr[] = {1, 2, 3, 5, 6}; int n = 6; cout <<
"Missing number: " << findMissing(arr, n) << endl; return
0;
}
OUTPUT:
Missing number: 4
Q.4
#include <iostream>
#include <cstring> // for strcmp, strcpy
using namespace std;
int main() { // (a) Concatenate char
str1[100], str2[100]; cout << "Enter first
string: "; cin >> str1; cout << "Enter
second string: "; cin >> str2; int i = 0, j
= 0; while (str1[i] != '\0') i++; while
(str2[j] != '\0') str1[i++] = str2[j++];
str1[i] = '\0';
cout << "Concatenated: " << str1 << endl << endl;
// (b) Reverse char str3[100]; cout
<< "Enter a string to reverse: "; cin
>> str3; int len = 0; while
(str3[len] != '\0') len++; for (int k =
0; k < len / 2; k++) { char temp =
str3[k]; str3[k] = str3[len - k - 1];
str3[len - k - 1] = temp;
}
cout << "Reversed: " << str3 << endl << endl;
// (c) Delete vowels char str4[100],
result[100]; cout << "Enter a string to remove
vowels: "; cin >> str4; i = 0; j = 0; while
(str4[i] != '\0') { char c = str4[i]; if
(!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) {
result[j++] = c;
}
i++;
}
result[j] = '\0'; cout << "Without vowels: " <<
result << endl << endl;
// (d) Sort strings (using strcmp & strcpy)
int n;
cout << "Enter number of strings: ";
cin >> n; char arr[10][100]; cout
<< "Enter strings:\n"; for (i = 0; i < n;
i++) cin >> arr[i];
for (i = 0; i < n - 1; i++) { for (j
= 0; j < n - i - 1; j++) { if
(strcmp(arr[j], arr[j+1]) > 0) {
char temp[100];
strcpy(temp, arr[j]);
strcpy(arr[j], arr[j+1]);
strcpy(arr[j+1], temp);
}
}
}
cout << "Sorted strings:\n"; for (i = 0; i
< n; i++) cout << arr[i] << endl; cout <<
endl;
// (e) Convert whole string to
lowercase char str5[100]; cout <<
"Enter a string in uppercase: "; cin >>
str5; i = 0; while (str5[i] != '\0') {
if (str5[i] >= 'A' && str5[i] <= 'Z')
str5[i] = str5[i] + 32; i++;
}
cout << "Lowercase string: " << str5 << endl;
return 0;
}
OUTPUT:
Enter first string: hello
Enter second string: mister
Concatenated: hellomister
Q.5
#include <iostream> using
namespace std;
// (a) Diagonal Matrix void
diagonalMatrix(int n) { int diag[n];
cout << "\nEnter diagonal elements: ";
for (int i = 0; i < n; i++) cin >> diag[i];
cout << "Diagonal Matrix:\n";
for (int i = 0; i < n; i++) { for
(int j = 0; j < n; j++) { if (i == j)
cout << diag[i] << " "; else
cout << "0 ";
}
cout << endl;
}
}
// (b) Tri-diagonal Matrix void
triDiagonalMatrix(int n) { int
tri[3*n - 2]; // 3 diagonals cout
<< "\nEnter elements of
tri-diagonal (main + 2
off-diagonals): "; for (int i = 0; i
< 3*n - 2; i++) cin >> tri[i];
cout << "Tri-Diagonal Matrix:\n";
int k = 0; for (int i = 0; i < n; i++) { for
(int j = 0; j < n; j++) { if (i == j) cout <<
tri[k++] << " "; else if (i == j+1) cout <<
tri[k++] << " "; else if (i+1 == j) cout <<
tri[k++] << " "; else cout << "0 ";
}
cout << endl;
}
}
// (c) Lower Triangular Matrix void
lowerTriangularMatrix(int n) { int size = n*(n+1)/2; //
only lower part int lower[size]; cout << "\nEnter
lower triangular elements row-wise: "; for (int i = 0; i <
size; i++) cin >> lower[i];
cout << "Lower Triangular Matrix:\n";
int k = 0; for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) { if (i >= j)
cout << lower[k++] << " "; else
cout << "0 ";
}
cout << endl;
}
}
// (d) Upper Triangular Matrix void
upperTriangularMatrix(int n) { int size = n*(n+1)/2; //
only upper part int upper[size]; cout << "\nEnter
upper triangular elements row-wise: "; for (int i = 0; i <
size; i++) cin >> upper[i];
cout << "Upper Triangular Matrix:\n";
int k = 0; for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) { if (i <= j)
cout << upper[k++] << " "; else
cout << "0 ";
}
cout << endl;
}
}
// (e) Symmetric Matrix void symmetricMatrix(int n) { int size =
n*(n+1)/2; // lower part only int sym[size]; cout << "\nEnter
lower triangular elements of symmetric matrix: "; for (int i = 0; i <
size; i++) cin >> sym[i];
cout << "Symmetric Matrix:\n";
int k = 0; for (int i =
0; i < n; i++) { for (int j
= 0; j < n; j++) { if (i
>= j) cout << sym[k++] <<
" "; else cout <<
sym[j*(j+1)/2 + i] << " ";
// mirror from lower
}
cout << endl;
}
}
int main() {
int n;
cout << "Enter order of square matrix (n): ";
cin >> n;
diagonalMatrix(n);
triDiagonalMatrix(n);
lowerTriangularMatrix(n);
upperTriangularMatrix(n);
symmetricMatrix(n);
return 0;
}
OUTPUT:
Enter order of square matrix (n): 3
Enter diagonal elements: 4 5 6
Diagonal Matrix:
4 0 0
0 5 0
0 0 6
Q.6
#include <iostream> using
namespace std;
void print(int r[], int c[], int v[], int n) { cout << "Row Col Val\n"; for
(int i = 0; i < n; i++) cout << r[i] << " " << c[i] << " " << v[i] << endl;
}
void transpose(int r[], int c[], int v[], int n)
{ for (int i = 0; i < n; i++) { int t = r[i];
r[i] = c[i]; c[i] = t;
}
}
int add(int r1[], int c1[], int v1[], int n1, int r2[], int c2[], int v2[],
int n2, int r3[], int c3[], int v3[]) { int k = 0; for (int i = 0; i <
n1; i++) { r3[k]=r1[i]; c3[k]=c1[i]; v3[k]=v1[i]; k++; } for (int i = 0; i
< n2; i++) { r3[k]=r2[i]; c3[k]=c2[i]; v3[k]=v2[i]; k++; } return k;
}
int multiply(int r1[], int c1[], int v1[], int n1,
int r2[], int c2[], int v2[], int n2, int
r3[], int c3[], int v3[]) { int k = 0; for
(int i = 0; i < n1; i++) { for (int j = 0; j <
n2; j++) {
if (c1[i] == r2[j]) { r3[k] = r1[i];
c3[k] = c2[j]; v3[k] = v1[i]*v2[j]; k++;
}
}
}
return k;
}
int main() { int n1,n2; cout << "Enter number of
non-zero elements in A: "; cin >> n1; int
r1[20],c1[20],v1[20]; cout << "Enter row col val for
A:\n"; for(int i=0;i<n1;i++) cin>>r1[i]>>c1[i]>>v1[i];
cout << "Enter number of non-zero elements in B:
"; cin >> n2; int r2[20],c2[20],v2[20]; cout <<
"Enter row col val for B:\n"; for(int i=0;i<n2;i++)
cin>>r2[i]>>c2[i]>>v2[i];
cout << "Matrix A:\n"; print(r1,c1,v1,n1);
cout << "Matrix B:\n"; print(r2,c2,v2,n2);
transpose(r1,c1,v1,n1); cout << "\nTranspose
of A:\n"; print(r1,c1,v1,n1);
int r3[40],c3[40],v3[40]; int n3 =
add(r1,c1,v1,n1,r2,c2,v2,n2,r3,c3,v3); cout <<
"\nA + B:\n"; print(r3,c3,v3,n3);
int r4[40],c4[40],v4[40]; int n4 =
multiply(r1,c1,v1,n1,r2,c2,v2,n2,r4,c4,v4); cout <<
"\nA x B:\n"; print(r4,c4,v4,n4);
return 0;
}
OUTPUT:
Enter number of non-zero elements in A: 4
Enter row col val for A:
4 5 6
3 2 4
1 2 3
3 2 1
Enter number of non-zero elements in B: 4
Enter row col val for B:
2 3 1
4 5 2
4 2 3
1 2 4
Matrix A:
Row Col Val
4 5 6
3 2 4
1 2 3
3 2 1
Matrix B:
Row Col Val
2 3 1
4 5 2
4 2 3
1 2 4
Transpose of A:
Row Col Val
5 4 6
2 3 4
2 1 3
2 3 1
A + B:
Row Col Val
5 4 6
2 3 4
2 1 3
2 3 1
2 3 1
4 5 2
4 2 3
1 2 4
A x B:
Row Col Val
5 5 12
5 2 18
2 2 12
Q.7
#include<iostream>
using namespace std; int
main(){
int n;
cout << "Enter no. of elements:";
cin >>n; int arr[n]; cout <<
"Enter array elements:"; for(int
i=0;i<n;i++){ cin >> arr[i];
}
int count=0; for(int
i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
if(arr[i]>arr[j])
count++;
}
}
cout << "The total number of inversions in this array is " << count ; return
0;
}
OUTPUT:
Enter no. of elements:5
Enter array elements: 4 5 2 3 1
The total number of inversions in this array is 8
Q.8
#include<iostream>
using namespace std; int
main(){
int n;
cout << "Enter no. of elements:";
cin >>n; int arr[n]; cout <<
"Enter array elements:"; for(int
i=0;i<n;i++){ cin >> arr[i];
}
int count=0; for(int i=0;i<n;i++){
bool flag=true; for(int j=0;j<i;j++){
if(arr[i]==arr[j]){ flag=false; break;
}
}
if(flag==true) count ++;
}
cout << "The total number of distinct elements in this array is " << count ;
return 0;
}
OUTPUT:
Enter no. of elements:5
Enter array elements:4 4 5 3 3
The total number of distinct elements in this array is 3