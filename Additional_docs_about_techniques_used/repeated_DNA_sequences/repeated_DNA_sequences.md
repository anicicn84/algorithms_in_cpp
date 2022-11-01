# Hash calculation for this problem

We’ll combine the sliding window pattern and rolling hash technique to find the repeated DNA sequence in a string. To understand the rolling hash technique, consider the following example with the hash function:
*H = c<sub>1</sub>a<sup>k-1</sup> + c<sub>2</sub>a<sup>k-2</sup>  + ... + c<sub>i</sub>a<sup>k-i</sup> + ... + c<sub>k-1</sub>a<sup>1</sup> + c<sub>k</sub>a<sup>0</sup>*.

*a* is a constant, *c<sub>1</sub>... c<sub>k</sub>* are input characters and *k* is the substring length. Since we only have 4 possible nucleotides, our *a* would be 4. We’ll also assign numeric values to the nucleotides as shown in the table below:

| A           |  C          |  G          | T           |
|:------------|:-----------:|:-----------:|------------:|
|c<sub>1</sub>|c<sub>2</sub>|c<sub>3</sub>|c<sub>4</sub>|
|1            |2            |3            |4            |

1. Computing the hash of the DAN sequence *ACG*:
    *H(ACG) = H(A) + H(C) + H(G) = 1 $\times$ 4<sup>2</sup> + 2 $\times$ 4<sup>1</sup> + 3 $\times$ 4<sup>0</sup>*.

2. To get the hash of *CGT*, we just need to remove *A* and add *T*, instead of recomputing the hash for all nucleotides.
    *H(CGT) = H(ACG) - H(A) + H(T)*.

However, this is not quite correct – after subtracting *H(A)*, to stay consistent with the hashing formula, we need to fix the place values of the remaining nucleotides, *C* and *G*. Therefore, we’ll multiply *H(ACG)−H(A)* by 4, so that *H(C)* becomes
2 $\times$ 4<sup>2</sup> and *H(G)* becomes 3 $\times$ 4<sup>1</sup>:

*H(CGT) = ((H(ACG) - H(A)) $\times$ 4) + H(T) = (((1 $\times$ 4<sup>2</sup> + 2 $\times$ 4<sup>1</sup> + 3 $\times$ 4<sup>0</sup>) - (1 $\times$ 4<sup>2</sup>)) $\times$ 4) + 4 $\times$ 4<sup>0</sup>*.


Now the rolling hash calculation should be clear.