X = load("boston_housing.data.txt");

for i = 13
    X(:,i) = (X(:,i) - repmat(mean(X(:,i)),506,1))/std(X(:,i));
end
   
X = [ones(506,1) X];

X_train = X(1:456, 1:14);
Y_train = X(1:456, 15);

X_test = X(457:506,1:14);
Y_test = X(457:506,15);

w = (X_train.'*X_train)\(X_train.'*Y_train);

Y_predict = X_test * w;

err = sum(abs(Y_predict-Y_test))/50;


