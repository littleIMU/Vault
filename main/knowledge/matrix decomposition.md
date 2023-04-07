# backslash
In Matlab, the ‘\’ command invokes an algorithm which depends upon the structure of the matrix A and includes checks (small overhead) on properties of A.

- If A is sparse and banded, employ a banded solver.
- If A is an upper or lower triangular matrix, employ a backward substitution algorithm.
- If A is symmetric and has real positive diagonal elements, attempt a Cholesky factorization. If A is sparse, employ reordering first to minimize fill-in.
- If none of criteria above is fulfilled, do a general triangular factorization using Gaussian elimination with partial pivoting.
- If A is sparse, then employ the UMFPACK library.
- If A is not square, employ algorithms based on QR factorization for undetermined systems.
To reduce overhead it is possible to use the linsolve command in Matlab and select a suitable solver among these options yourself.

```matlab
n = 2000;
a = rand(n,n);
b = rand(n,1);
disp('For a\b');
tic;a\b;toc;
disp('For LU');
tic;LULU;toc;
disp('For Conj Grad');
tic;conjgrad(a,b,1e-8);toc;
disp('For INV(A)*B');
tic;inv(a)*b;toc;
```

Results:
```matlab
For a\b
Elapsed time is 0.575926 seconds.

For LU
Elapsed time is 0.654287 seconds.

For Conj Grad
Elapsed time is 9.875896 seconds.

Inv(A)*B
Elapsed time is 1.648074 seconds.
```
# eigenvalue and decomposition

[eigenvalue.pdf](eigenvalue%20and%20decompo/eigenvalue.pdf)

[Linear Algebra 18d: The Eigenvalue Decomposition and Powers of a Matrix](https://www.youtube.com/watch?v=-1loSrioE4Y)

# Cholesky and QR factorization

[qr and cholesky factorization example in matlab](matrix%20decomposition/chap7.pdf)
