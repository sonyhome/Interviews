// Dan Truong
// Merge in-place two sorted arrays (no array allocations)
// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays
//
// Heuristic:
// use a3 as a pointer to the first or second array.
// scan first array against second array elements, and swap them if the
// second array element is smaller.
// When doing the swap, move the element going to a2 in it's proper order.
// The sort can be done by using a dichotomic search in a2, and then doing
// a memmove of all the smaller elements left one.
// The sort ends when a1 contains all the smallest values since values
// sent to a2 get sorted on insertion.
// The code implementation is not the best since it's influenced by how I
// started solving this (aka by allocating an array to save sorted values).

#include <stdio.h>

#define A3_IS_A2 (p3 >= s1)
const int s1 = 6;
int a1[] = {1, 5, 9, 10, 15, 20};
const int s2 = 4;
int a2[] = {2, 3, 8, 13};

///
printOut()
{
	for (int i = 0; i < s1; i++)
	    printf("%d.", a1[i]);
	printf("    ");
	for (int i = 0; i < s2; i++)
	    printf("%d.", a2[i]);
	printf("\n");
}

/// store t in a2 within index p2 to s2-1, sorted
storeInto(int t,int * a2, int p2, int s2)
{
    // Find the next value > t.
    // This can be a dichotomic search followed by a memmove.
    int i;
    for(i = p2+1; i < s2; i++)
    {
        if (a2[i] >= t)
        {
            // Insert value
            a2[i-1] = t;
            return;
        }
        // Move smaller values down
        a2[i-1] = a2[i];
    }
    // t is the largest value
    a2[s2-1] = t;
}

///
int main() {
    // Start with a1[] as target array
    int* a3 = a1;
    
	//code
	int t = -1;
	int p1 = 0;
	int p2 = 0;
	for (int p3 = 0; p3 < s1+s2; p3++)
	{
	    // Set a2[] as target array
	    if A3_IS_A2
	    {
	        a3 = a2 - s1;
	    }
	    
	    // Backup value replaced
	    t = a3[p3];
	    
        if ((p2 >= s2 || a1[p1] <= a2[p2]) && (p1 < s1))
        {
            // Value from a1 is the smallest,
            // so it's already in a3 because a1==a3 if that's true.
            printf("Xp1=%d p2=%d\t", p1, p2); printOut();
            p1++;
        }
        else if (p2 < s2)
        {
            if (! A3_IS_A2)
            {
                // Value from a2 is smallest, and is copied to a3==a1
                a3[p3] = a2[p2];
                // t must be saved to a2, but requires a sort
                storeInto(t, a2, p2, s2);
                printf("Yp1=%d p2=%d\t", p1, p2); printOut();
                p1++;
            }
            else
            {
                // Value from a2 is smallest, but a3 == a2
                printf("!p1=%d p2=%d\t", p1, p2); printOut();
                p2++;
                return;
            }
        }
	}
    printOut();
	return 0;
}
