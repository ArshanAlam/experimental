%
% Arshan Alam
% 2017/05/21
%
% Gradient Descent
%
%
% @param X is a m * n matrix of values for each feature.
% @param y Output of training exaple
% @param alpha is the learning rate (Should be small 0.001, 0.003, 0.01, ..., 1, ...)
% @param q an input vector for which we must predict an output value
function result = predictOnGradientDescent(X, y, alpha, q)
  theta = gradientDescent(X, y, alpha);
  result = theta' * ([1 (q-mean(X))./std(X)])';
end
