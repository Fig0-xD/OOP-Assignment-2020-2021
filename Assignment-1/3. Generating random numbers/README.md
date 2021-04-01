# Generating random numbers

>Pseudo-random numbers are generated using **linear congruential generator**.
[Click here](https://en.wikipedia.org/wiki/Linear_congruential_generator) for more information.

### Problem Statement

Write a code to generate that will implement your random number generator function `myrand()` using the multiplicative congruential generator formula:

`Xi+1=(Xi * a) % m;`

Set **X0** the initial value of the series to be the system time using `time()` function.

Now generate 10000 random numbers in the range [1,50] using `myrand()` and also using library function `rand()`. 
Display the [Chi-square test](https://en.wikipedia.org/wiki/Chi-squared_test) value of both the random series and comment if they are acceptable. 
You may set the suitable values for a, c & m (refer to the above link).
