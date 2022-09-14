# Problem 3: Runtime Analysis

## Part a)
  In each iteration of the loop, the power of $i$ is doubled, so the sequence goes like: $i^1, i^2, i^4, i^8, ..., n$
  
  which is equivalent to $i^{2^0}, i^{2^1}, i^{2^2}, i^{2^3}, ..., n, $ where
  $$ n = i^{2^k} = 2^{2^k} $$

  Solving for k, 
  $$ \log_2{n} = 2^k $$
  $$ \log_{2}\log_{2}n = k $$

  In formal notation,
 
  $$ T(n) = \sum_{i=0}^{\log_{2}\log_{2}n} (O(1) + O(1)) = \Theta(\log_{2}\log_{2}n) $$

  **Answer:** $\Theta(\log_{2}\log_{2}n)$
___
## Part b)
  The outer loop begins with $1...n$.
  
  The first if statement reduces that to the values $\sqrt{n}, 2\sqrt{n}, 3\sqrt{n}, ... (\sqrt{n}*\sqrt{n})$.
  
  The innermost for-loop is then run:
  $$ T(n) = \sum_{i=1}^{\sqrt{n}} \sqrt{n}^3 \sum_{j=0}^{i^3} O(1) $$
  $$ = \sqrt{n}^3 \sum_{i=1}^{\sqrt{n}}  \Theta(i^3) $$ 
  $$ = \sqrt{n}^3 \sqrt{n}^{3 + 1} $$
  $$ = n^{7/2} $$
  
  In simpler notation:
  $$ T(n) = (\sqrt{n})^3 + (2\sqrt{n})^3 + (3\sqrt{n})^3 + ... + (\sqrt{n} * \sqrt{n})^3 $$
  $$ = (\sqrt{n})^3 (1^3 + 2^3 + 3^3 + ... + (\sqrt{n})^3)$$
  $$ = \sqrt{n}^3 \sqrt{n}^{3 + 1} = n^{7/2} $$
  
  **Answer:** $\Theta(n^{7/2})$
___
## Part c)
  The outer loops and the if statement evaluate to:
  $$ \sum_{i=0}^n \sum_{k=0}^n \Theta(1) $$ 
  
  Because the if statement can only be true at most $n$ times, the inner loop evaluates to:
  $$ \sum_{i=0}^n \sum_{m=0}^{\log_{2}n} 2^m O(1) $$
  
  Adding them together, we get:
  $$ T(n) = \sum_{i=0}^n \sum_{k=0}^n \Theta(1) + \sum_{i=0}^n \sum_{m=0}^{\log_{2}n} 2^m O(1) $$ 
  $$ = \sum_{i=0}^n (\Theta(i) + \Theta(\frac{2^{\log_{2}i + 1} - 1}{2 - 1})) $$
  $$ = \sum_{i=0}^n (\Theta(i) + \Theta(2i - 1)) $$
  $$ = \sum_{i=0}^n \Theta(i) $$
  $$ = \Theta(n^2) $$

  **Answer:** $\Theta(n^2)$
___
## Part d)
  The tricky part here is the number of times the contents of the if statement is run (denoted by the second summation below). Because the if statement only occurs at $i = 10 * 1.5^k$ up until $i = n$, we solve for the equation $n = 10 * 1.5^k$, resulting in the $\log_{3/2}n/10$ number of times the if statement is true below.

  The third summation is another simple for-loop within the if statement.

  $$ T(n) = \Theta(2) + \sum_{i=0}^{n-1}\Theta(1) + \sum_{i=0}^{\log_{3/2}n/size} (\Theta(5) + \sum_{j=0}^{size*1.5^i} \Theta(1)) $$
  $$ = \Theta(1) + \Theta(n) + \sum_{i=0}^{\log_{3/2}n/10} \Theta(10*1.5^i) $$
  $$ = \Theta(n) +  10* \Theta(1.5^{\log_{3/2}n/10}) $$
  $$ = \Theta(n) + 10 * \Theta(n / 10) $$
  $$ = \Theta(n) $$

  **Answer:** $\Theta(n)$