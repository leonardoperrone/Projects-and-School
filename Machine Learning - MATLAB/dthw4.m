% Leonardo Perrone
% F285Y428

test = load("zip.test.txt");
train = load("zip.train.txt");

X_train = train(:,2:end);
Y_train = train(:,1);
X_test = test(:,2:end);
Y_test = test(:,1);

decTree = fitctree(X_train, Y_train, 'MinLeafSize', 10);

Y_predict = predict(decTree, X_test);

accuracy = sum(Y_test == Y_predict) / numel(Y_test);
accuracyPercentage = 100*accuracy;