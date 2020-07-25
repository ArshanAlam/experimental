Gradient Descent
---

To calculate the *parameters* for a given set of data **X** and it's respective output **y**
execute gradient descent: `gradientDescent(X, y, alpha)` with some learning rate *alpha*.

**NOTE:** The learning rate *alpha* should be small for gradient descent to converge. Try
something along the lines of `alpha = 0.01`.


The parameter **X** is a *(m &times; n)* matrix of *m* training examples and *n* features.

The parameter **y** is the output vector of size *m*.


#### How to predict?
---
To predict an output based on the values of the parameters &theta; we must first normalize the input.

let **q** be some (row) input vector of features.

To normalize **q**, set `q = [1 (q-mean(X))./std(X)]`.

Lastly, we run our prediction: `theta' * q'`

**Or simply:** call the `predictOnGradientDescent(X, y, alpha, q)` function, where the input parameter *q* is **not** normalized
