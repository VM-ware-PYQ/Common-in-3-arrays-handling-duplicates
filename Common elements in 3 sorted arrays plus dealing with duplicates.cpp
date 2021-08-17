/*
We can deal with duplicates using STL container set

void findCommon(int a[], int b[], int c[], int n1, int n2,
                int n3)
{
    // three sets to maintain frequency of elements
    unordered_set <int> uset,uset2,uset3;
    for(int i=0;i<n1;i++){
        uset.insert(a[i]);
    }
     for(int i=0;i<n2;i++){
        uset2.insert(b[i]);
    }
      // checking if elements of 3rd array are present in first 2 sets
    for(int i=0;i<n3;i++){
        if(uset.find(c[i])!=uset.end() && uset2.find(c[i])!=uset.end()){
            // using a 3rd set to prevent duplicates
            if(uset3.find(c[i])==uset3.end())
                cout<<c[i]<<" ";
            uset3.insert(c[i]);
        }
    }          
}

Expected Time Complexity: O(n1 + n2 + n3)
Expected Auxiliary Space: O(n1 + n2 + n3)

*/

/*
The approach used in arrays already (3 pointers) works well if the arrays does not contain duplicate values however 
it can fail in cases where the array elements are repeated. This can lead to a single common element 
to get printed multiple times.

These duplicate entries can be handled without using any additional data structure by keeping the 
track of the previous element. Since the elements inside the array are arranged in sorted manner there is no possibility 
for the repeated elements to occur at random positions. 

Let’s consider the current element traversed in ar1[] be x, in ar2[] be y and in ar3[] be z and let the variables prev1, prev2, 
prev3 for keeping the track of last encountered element in each array and initialize them with INT_MIN. Hence for every element 
we visit across each array, we check for the following.

If x = prev1, move ahead in ar1[] and repeat the procedure until x != prev1. Similarly, apply the same for the ar2[] and ar3[].
If x, y, and z are same, we can simply print any of them as common element, update prev1, prev2, and prev3 and move ahead in all three arrays.
Else If (x < y), we update prev1 and move ahead in ar1[] as x cannot be a common element.
Else If (y < z), we update prev2 and move ahead in ar2[] as y cannot be a common element.
Else If (x > z and y > z), we update prev3 and we move ahead in ar3[] as z cannot be a common element.


void findCommon(int ar1[], int ar2[], int ar3[], int n1,
                int n2, int n3)
{
     
    // Initialize starting indexes
    // for ar1[], ar2[] and
    // ar3[]
    int i = 0, j = 0, k = 0;
 
    // Declare three variables prev1,
    // prev2, prev3 to track
    // previous element
    int prev1, prev2, prev3;
 
    // Initialize prev1, prev2,
    // prev3 with INT_MIN
    prev1 = prev2 = prev3 = INT_MIN;
 
    // Iterate through three arrays
    // while all arrays have
    // elements
    while (i < n1 && j < n2 && k < n3) {
       
        // If ar1[i] = prev1 and i < n1,
        // keep incrementing i
        while (ar1[i] == prev1 && i < n1)
            i++;
 
        // If ar2[j] = prev2 and j < n2,
        // keep incrementing j
        while (ar2[j] == prev2 && j < n2)
            j++;
 
        // If ar3[k] = prev3 and k < n3,
        // keep incrementing k
        while (ar3[k] == prev3 && k < n3)
            k++;
 
        // If x = y and y = z, print
        // any of them, update
        // prev1 prev2, prev3 and move
        //ahead in each array
        if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) {
            cout << ar1[i] << " ";
            prev1 = ar1[i];
            prev2 = ar2[j];
            prev3 = ar3[k];
            i++;
            j++;
            k++;
        }
 
        // If x < y, update prev1
        // and increment i
        else if (ar1[i] < ar2[j]) {
            prev1 = ar1[i];
            i++;
        }
 
        // If y < z, update prev2
        // and increment j
        else if (ar2[j] < ar3[k]) {
            prev2 = ar2[j];
            j++;
        }
 
        // We reach here when x > y
        // and z < y, i.e., z is
        // smallest update prev3
        // and imcrement k
        else {
            prev3 = ar3[k];
            k++;
        }
    }
}

Time Complexity for the above approach still remains O(n1 + n2 + n3) and space complexity also remains O(1) 
and no extra space and data structure is required to handle the duplicate array entries.
*/
