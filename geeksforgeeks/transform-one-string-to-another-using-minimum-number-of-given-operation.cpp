for (int i=n-1, j=n-1; i>=0; )
{
    // If there is a mismatch, then keep incrementing
    // result 'res' until B[j] is not found in A[0..i]
    while (i>=0 && A[i] != B[j])
    {
        i--;
        res++;
    }

    // If A[i] and B[j] match
    if (i >= 0)
    {
        i--;
        j--;
    }
}
