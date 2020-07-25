%
% Arshan Alam
% 2017/05/21
%
% Gradient Descent
%
% The cost function that will be used for Gradient Descent is
% as follow: J(theta) = (1/2m) sum_{i = 1}^{m} (h_theta(x^(i)) - y^(i))^2
%
% Where m is the number of training examples, and
%
% Where h_theta(x^(i)) is the hypothesis function h_theta(X) = (theta)' * X
%
% @param X is a m * n matrix of values for each feature.
% @param y Output of training example (column vector)
% @param alpha is the learning rate (Should be small 0.001, 0.003, 0.01, ..., 1, ...)
function theta = gradientDescent(X, y, alpha)

  % Some constants
  m = length(y);
  n = size(X, 2) + 1;
  THRESHOLD = 0;  % Difference between previous and current cost is nothing

  % Apply feature scaling to speed up gradient Descent
  % Apply mean normalization
  X = (X-mean(X))./std(X);

  % Add a column of ones to X for theta_0
  X = [ones(m, 1)  X];

  % NOTE: we are taking the transpose so that each training example is a column in X
  X = X';

  % Initial value for theta
  theta = zeros(n, 1);
  prevCost = calCost(X, y, theta, m);

  % Apply gradient decent
  while true
    theta = theta - (alpha/m) * (((theta' * X) - y') * X')';
    curCost = calCost(X, y, theta, m);
    if (abs(curCost-prevCost) <= THRESHOLD)
      break;
    else
      prevCost = curCost;
    end
  end
end

%
% Calculate the cost for the given function
%
% J(theta) = (1/2m) sum_{i = 1}^{m} (h_theta(x^(i)) - y^(i))^2
function J = calCost(X, y, theta, m)
  J = (1/(2*m)) * sum(((theta' * X) - y').^2);
end
